#ifndef _MARCH_H_03_04_16
#define _MARCH_H_03_04_16  0x100


#include "ALL_INCLUDES.h"
/* *********************************************
        Machine Architecture Config
 **********************************************/


#if defined CONFIG_MARCH 
// Force inclusion of Intel Intrinsics: SSE, SSE2, SSE3, SSSE3, SSE4.1, SSE4.2, AVX Header Files.
#if defined (__INTEL_COMPILER) && defined (__AVX__)
#include <immintrin.h>
#elif defined (__SSE4_2__)
#include <nmmintrin.h>
#elif defined (__SSE4_1__)
#include <smmintrin.h>
#elif defined (__SSSE3__)
#include <tmmintrin.h>
#elif defined (__SSE3__)
#include <pmmintrin.h>
#elif defined (__SSE2__)
#include <emmintrin.h>
#elif defined (__SSE__)
#include <xmmintrin.h>
#elif defined (_MSC_VER)
#include <intrin.h>
#endif
#else
// Default to SSE SIMD support.
#include <xmmintrin.h>
#endif
#endif /*_MARCH_H_03_04_16*/