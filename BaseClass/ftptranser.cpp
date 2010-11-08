#include "ftptranser.h"
#include <curl/curl.h>

CFtpTranser::CFtpTranser()
{

}
 
CFtpTranser::~CFtpTranser()
{

}
 
bool CFtpTranser::bUpload( char *destfile,char* localfile,char *serverip,char *userinfo )
{
    if (! bCheckData() )
    {
        return false;
    }
 

   CURL * curl;
   CURLcode res;
 
   char errorBufp[CURL_ERROR_SIZE];
   FILE * sendFile ,*debugFile;
   char ftpurl[256 + 1];
   char usrpasswd[64 + 1];
 

   if (NULL == ( sendFile = fopen(argv[6],"r")))
   {
       fclose(debugFile);
       return -1;
   }
/*   fseek(sendFile,0,SEEK_END);
   int sendSize = ftell(sendFile);
   if (sendSize < 0)
   {
       fclose(debugFile);
       fclose(sendFile);
       return -1;
   }
   fseek(sendFile,0L,SEEK_SET);
 */
 
   struct stat file_info;
   curl_off_t fsize;
   struct curl_slit *headerlist = NULL;
   if (!stat("/root/vimrc",&file_info))
   {
       return -1;
   }
   int sendSize = (curl_off_t)file_info.st_size;
   
   if (0 != (res = curl_global_init(CURL_GLOBAL_ALL)))
   {
       fclose(debugFile);
       fclose(sendFile);
       return -1;
   }
  if( ( curl = curl_easy_init() ) == NULL ) 
  {
    
       fclose(debugFile);
       fclose(sendFile);
       curl_global_cleanup();
       return -1;
  }
   if ( '/' != argv[4][strlen(argv[4]) - 1 ])
   {
       sprintf(ftpurl,"ftp://%s/%s/%s",argv[1],argv[4],argv[5]);
   }
   else
   {
       sprintf(ftpurl,"ftp://%s/%s%s",argv[1],argv[4],argv[5]);
   }
   curl_easy_setopt(curl,CURLOPT_URL,ftpurl);

   sprintf(usrpasswd,"%s:%s",argv[2],argv[3]);
   curl_easy_setopt(curl,CURLOPT_USERPWD,usrpasswd);
 
   curl_easy_setopt(curl,CURLOPT_VERBOSE ,1 );
   curl_easy_setopt(curl,CURLOPT_DEBUGDATA ,debugFile );
   curl_easy_setopt(curl,CURLOPT_READDATA ,sendFile );
   curl_easy_setopt(curl,CURLOPT_UPLOAD ,1 );
   curl_easy_setopt(curl,CURLOPT_INFILESIZE ,sendSize );
   curl_easy_setopt(curl,CURLOPT_FTP_CREATE_MISSING_DIRS , 1 );
//   curl_easy_setopt(curl,CURLOPT_DEBUGFUNCTION ,debugFun );
 
   res = curl_easy_perform(curl);
   if (0 != res)
   {
       fclose(sendFile);
       fclose(debugFile);
       curl_easy_cleanup(curl);
       curl_global_cleanup( );
       return -1;
   }
   
   fclose(sendFile);
   fclose(debugFile);
   curl_easy_cleanup(curl);
   curl_global_cleanup( );
   return 0;
    return true;
}
 

