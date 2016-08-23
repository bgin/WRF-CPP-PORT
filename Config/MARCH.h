#ifndef __WRF_MARCH_H__
#define __WRF_MARCH_H__ 

#ifndef WRF_MARCH_VERSION_MAJOR
#define WRF_MARCH_VERSION_MAJOR 1
#endif

#ifndef WRF_MARCH_VERSION_MINOR
#define WRF_MARCH_VERSION_MINOR 0
#endif

#ifndef WRF_MARCH_CREATE_DATE
#define WRF_MARCH_CREATE_DATE 20160403
#endif

/* Set this value to successful build date*/
#ifndef WRF_MARCH_BUILD_DATE
#define WRF_MARCH_BUILD_DATE 0
#endif


/* *********************************************
        Machine Architecture Config
 **********************************************/
#include "ALL_INCLUDES.h"

#if defined CONFIG_MARCH && !defined SIMD_INSTR_SET
// Force inclusion of Intel Intrinsics: SSE, SSE2, SSE3, SSSE3, SSE4.1, SSE4.2, AVX Header Files.
#if defined (__INTEL_COMPILER) && defined (__AVX__)
#define SIMD_INSTR_SET 7
#include <immintrin.h>
#elif defined  (__SSE4_2__)
#define SIMD_INSTR_SET 6
#include <nmmintrin.h>
#elif defined (__SSE4_1__)
#define SIMD_INSTR_SET 5
#include <smmintrin.h>
#elif defined (__SSSE3__)
#define SIMD_INSTR_SET 4
#include <tmmintrin.h>
#elif defined (__SSE3__)
#define SIMD_INSTR_SET 3
#include <pmmintrin.h>
#elif defined (__SSE2__)
#define SIMD_INSTR_SET 2
#include <emmintrin.h>
#elif defined (__SSE__)
#define SIMD_INSTR_SET 1
#if defined CPU_HAS_SSE_ONLY
#define CPU_HASE_SSE_ONLY 0x1
#endif
#include <xmmintrin.h>

/* Force inclusion of Intel Intrinsics: SSE, SSE2, SSE3, SSSE3, SSE4.1, SSE4.2, AVX Header Files
   Microsoft Compiler header files */
#elif defined (_MSC_VER) && defined (__AVX__)
#define SIMD_INSTR_SET 7
#include <immintrin.h>
#elif defined (__SSE4_2__)
#define SIMD_INSTR_SET 6
#include <nmmintrin.h>
#elif defined (__SSE4_1__)
#define SIMD_INSTR_SET 5
#include <smmintrin.h>
#elif defined (__SSSE3__)
#define SIMD_INSTR_SET 4
#include <tmmintrin.h>
#elif defined (__SSE3__)
#define SIMD_INSTR_SET 3
#include <pmmintrin.h>
#elif defined (__SSE2__)
#define SIMD_INSTR_SET 2
#include <emmintrin.h>
#elif defined (__SSE__)
#define SIMD_INSTR_SET 1
#include <xmmintrin.h>
#endif

#endif

/* MS Compiler Intrinsics support */

#endif /*__WRF_MARCH_H__*/