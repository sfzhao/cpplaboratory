#ifndef _DLL_CLIENT_H_
#define _DLL_CLIENT_H_
 
#ifdef WIN32
  #ifdef SWPF_MOM_CLIENT_EXPORTS
     #define SWPF_MOM_CLIENT_API __declspec(dllexport)
  #else
     #define SWPF_MOM_CLIENT_API __declspec(dllimport)
  #endif


  #ifdef TAPS_BASECLASS_EXPORTS
    #define TAPS_BASECLASS_API __declspec(dllexports)
  #else
    #define TAPS_BASECLASS_API __declspec( dllimports )
  #endif

#else
  #define SWPF_MOM_CLIENT_API
  #define TAPS_BASECLASS_API
 
#endif


#endif
