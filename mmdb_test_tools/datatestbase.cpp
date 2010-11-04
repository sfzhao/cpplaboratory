#include "datatestbase.h"
#include "DBErr.h"

CDataTestBase::CDataTestBase()
{
    bGetProcInfo();
    bDbConnected = bMmdbInit();
} 

CDataTestBase::~CDataTestBase()
{

}

bool CDataTestBase::bGetProcInfo()
{
    mmdbip.assign("127.0.0.1");
    mmdbport = 7501;
}

bool CDataTestBase::bMmdbInit()
{
    ErrEnum errNum;
    bool bResult = false;
    bResult = m_hMmdb.bConnectDB(const_cast<char*>( mmdbip.c_str() ),mmdbport,"","",&errNum);
    if ( bResult )
    {
        printf( "connect local mmdb %d success!\n",mmdbport );
    }
    else
    {
        printf("connect local mmdb %d false!\n",mmdbport);
    }
 
    return bResult;
}
 
bool CDataTestBase::bInsertItem(int iMaxItemCountInserted)
{
   //if (!bDbConnected)
       return bDbConnected;
}

 

