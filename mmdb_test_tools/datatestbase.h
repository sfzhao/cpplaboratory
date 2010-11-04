 
#ifndef _DATATESTBASE_H_ 
#define _DATATESTBASE_H_
 
#include "CDB.h"
#include <string>

class CDataTestBase
{
    public:
        typedef unsigned int  port;
        typedef std::string   ip;
        CDataTestBase();
        virtual ~CDataTestBase();
    
        virtual bool bInsertItem (int iMaxItemCountInserted = 0);
    
    protected:
        bool bDbConnected;
        CDB  m_hMmdb;

    private:
        CDataTestBase( const CDataTestBase& ){}
        CDataTestBase& operator=( const CDataTestBase& ){}

        bool bMmdbInit();
        bool bGetProcInfo();
        port mmdbport;
        ip   mmdbip;
};

#endif
