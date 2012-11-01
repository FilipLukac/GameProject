#ifndef __GLOBAL__
#define __GLOBAL__

#include <climits>

#if UCHAR_MAX == 0xFF
    typedef unsigned char uint8;
    typedef char int8;
#else
    #error No 8-bit type found!
#endif

#if USHRT_MAX == 0xFFFF
    typedef unsigned short uint16;
    typedef short int16;
#elif UINT_MAX == 0xFFFF
    typedef unsigned int uint16;
    typedef int int16;
#elif ULONG_MAX == 0xFFFF
    typedef unsigned long uint16;
    typedef long int16;
#else
    #error No 16-bit type found!
#endif

#if UINT_MAX == 0xFFFFFFFF
    typedef unsigned int uint32;
    typedef int int32;
#elif USHRT_MAX == 0xFFFFFFFF
    typedef unsigned short uint32;
    typedef short int32;
#elif ULONG_MAX == 0xFFFFFFFF
    typedef unsigned long uint32;
    typedef long int32;
#else
    #error No 32-bit type found!
#endif

#if ULONG_MAX == 0xFFFFFFFFFFFFFFFF
    typedef unsigned long uint64;
    typedef long int64;
#elif ULLONG_MAX == 0xFFFFFFFFFFFFFFFF
    typedef unsigned long long uint64;
    typedef long long int64;
#else
    #error No 64-bit type found!
#endif

#endif