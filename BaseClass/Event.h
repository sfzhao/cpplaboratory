#ifndef  _EVENT_H_
#define  _EVENT_H_
 
#include "dll_client.h"
#include "pthread.h"
class TAPS_BASECLASS_API CEvent
{
    public:
        CEvent();
        ~CEvent();
 
        void wait();
        bool wait(int secs );
 
        void set();
        void reset();

    protected:
        pthread_mutex_t m_mutex;
        pthread_cond_t  m_cond;
        bool            m_state;
    protected:
        const CEvent &operator=(const CEvent &event); 

};
#endif //#ENDIF
