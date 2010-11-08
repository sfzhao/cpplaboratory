#ifndef _FTPTRANSER_H_
#define _FTPTRANSER_H_

#include <stdlib.h>

class CFtpTranser
{
    public:
        CFtpTranser();
        ~CFtpTranser();
    
    public:
        typedef const short URL_LEN;
        typedef const short USRINFO_LEN;

        static URL_LEN urlmax = 512;
        static USRINFO_LEN usrmax = 64; 

    public:
        bool bUpload(char * destfile,char* localfile,char * serverip = NULL, char *userinfo = NULL);
        bool bDownload(char * destfile,char* localfile,char * serverip = NULL, char *userinfo = NULL)
        {
            return true;
        };

    private:
        CFtpTranser(const CFtpTranser&){};
        const CFtpTranser& operator=(const CFtpTranser&){};
 
        bool bCheckData() // check parameter send to bUpload,bDownload
        {
            return true;
        };   

    protected:
        char m_szUrl[urlmax];
        char m_szUsr[usrmax];
};
#endif
