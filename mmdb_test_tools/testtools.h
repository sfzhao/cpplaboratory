/* ***************************************************
 * Author     : sfzhao
 * Create Time: 10/11/03 15:07:11
 * File Name  : testtools.h
 *
 * Description: 
 * **************************************************/
#ifndef _TESTTOOLS_H_ 
#define _TESTTOOLS_H_
#include "datatestbase.h" 
#include "FTDORDItem.h"
//#include "FTDORD.h"
//#include "Profile.h"
//#include "CDB.h"
//#include "DBErr.h"

class CTestTools:CDataTestBase
{
    public:
        CTestTools();
        virtual ~CTestTools();
 
    public:
       // test effective of insert action ; 
        virtual bool bInsertItem(int iMaxItemCountInserted = 0);
 
    private:
        //CFTDORD m_hFtdord;
        //CDB     m_hMmdb;
};
 

 

 
#endif

