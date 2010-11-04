/* ***************************************************
 * Author     : sfzhao
 * Create Time: 10/11/03 14:57:07
 * File Name  : testtools.cpp
 *
 * Description: test mmdb efficiency
 * **************************************************/

#include "testtools.h" 
#include "CDATransaction.h"
#include "CStatement.h"
#include "time.h"
#include <sys/timeb.h>

CTestTools::CTestTools()
{
   /* ErrEnum errNum ;

    bool bResult = false;
    bResult = m_hMmdb.bConnectDB( "10.204.9.7",7501,"","",&errNum );
    if (bResult)
    {
        printf("connected mmdb 10.204.9.7 7501 success!\n");
    }
    else
    {
        printf("connected mmdb 10.204.9.7 7501 false!\n");
    }
  */
}
 
CTestTools::~CTestTools()
{

}
 
bool CTestTools::bInsertItem(int iMaxItemCountInserted)
{
    if (!bDbConnected)
        return bDbConnected;
    
    CFTDORDItem ftdorditem;
    CDATransaction tran(&m_hMmdb);
    
    /////////////////////////////////////////////////
    /// clear table at the first.
    {
        tran.bBeginTransacion();
        CStatement cStmt(&tran);

        cStmt + " delete from ftdord ";
 
        if (! cStmt.bExecute() )
        {
          printf("clear table  error !");
        }

        tran.bCommit();
    }
    /////////////////////////////////////////////////
    
    bool bOperateRes = false;
    memset(&ftdorditem , 0 , sizeof(ftdorditem));
    sprintf(ftdorditem.szOrddt,"%s","20101103");
    sprintf(ftdorditem.szCompany,"%s","SYSTEX");
    ftdorditem.cLegno = 'c' ;

    ////////////////////////////////////////////////
    /// show the start time
    clock_t clkStart,clkEnd;
    clkStart = clock();
 
    struct timeb tbStart;
    ftime(&tbStart);

    time_t tmtStart;
    tmtStart = tbStart.time;
    struct tm* ptmStart ;
    ptmStart = localtime(&tmtStart);

    printf("start time: %02d:%02d:%02d.%03d\n",ptmStart->tm_hour,
                ptmStart->tm_min,ptmStart->tm_sec,tbStart.millitm);
    ///////////////////////////////////////////////////
    
    for (int i = 0 ; i < iMaxItemCountInserted ; i ++)
    {
        tran.bBeginTransacion();
        sprintf(ftdorditem.szOrdno,"%05d",i);

        CStatement cStmt(&tran);

        cStmt + "INSERT INTO FTDORD( ORDDT,COMPANY,ORDNO,LEGNO) values ("
              + "'" + ftdorditem.szOrddt + "'," 
              + "'" + ftdorditem.szCompany + "',"
              + "'" + ftdorditem.szOrdno + "',"
              + "'" + ftdorditem.cLegno + "'"
              + ")";
 
        if (! cStmt.bExecute() )
        {
          printf("insert error !line [%d]",i);
        }
        //#bOperateRes = bStatementExecute(&cStmt);
        tran.bCommit();
    }
 
    ////////////////////////////////////////////////////
    /// show the end time
    struct timeb tbEnd;
    ftime(&tbEnd);
 
    time_t tmtEnd;
    tmtEnd = tbEnd.time;
    struct tm* ptmEnd ;
    ptmEnd = localtime(&tmtEnd);
    
    printf("end   time: %02d:%02d:%02d.%03d\n",ptmEnd->tm_hour,
                ptmEnd->tm_min,ptmEnd->tm_sec,tbEnd.millitm);
    //////////////////////////////////////////////////

    ////////////////////////////////////////////////
    /// show the duration calculated by function clock.
    clkEnd = clock();
 
    double duration = (double)(clkEnd - clkStart) / CLOCKS_PER_SEC;
    printf("clock() duration  %f seconds\n",duration);
    ////////////////////////////////////////////////
 
    return true;
}
 

