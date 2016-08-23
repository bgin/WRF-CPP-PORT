#ifndef _ALL_INCLUDES_H_03_04_16
#define _ALL_INCLUDES_H_03_04_16   100

/*
    *************  Frequently Used Header Files  *****************
*/

#include <math.h>
#include <iostream>
#include <iomanip>
#include <memory>
#include <functional>
#include <array>
#include <valarray>
#include <vector>
#include <stdexcept>
#include <type_traits>

#include <boost\multi_array.hpp>
#include <boost\units\quantity.hpp>
#include <boost\units\systems\si.hpp>


#ifndef CONFIG_MARCH
#define CONFIG_MARCH 0x1
#endif

#if !defined USE_OPENMP
#define USE_OPENMP 0x1
#endif

#if defined (__INTEL_COMPILER) 
#include <immintrin.h>
#else
#include <intrin.h>
#endif

#if defined (USE_OPENMP) && defined (__INTEL_COMPILER)
#include <omp.h>
#elif defined (USE_OPENMP) && !defined (__INTEL_COMPILER)
#include <omp.h>
#endif

/**********************************************
 OpenMP version support:
 1) OPENMP_VERSION 0x2 = OpenMP 2.0 - 2.5
 2) OPENMP_VERSION 0x3 = OpenMP 3.0 - 3.5
 3) OPENMP_VERSION 0x4 = OpenMP 4.0 - 4.5
*************************************************/
#if defined USE_OPENMP
#if !defined OPENMP_VERSION
#define OPENMP_VERSION 0x4
#endif
#endif

#if defined _DEBUG
#if !defined DEBUG_VERBOSE
#define DEBUG_VERBOSE 0x1
#endif
#endif

/* Important!!
   Vectorisation defines.
   This defines will enable/disable the conditional
   compilation of large part of the code.*/


/* Manual vectorisation if possible. Undef it 
   in order to use ICC auto-vectorizer (enable it in
   compiler settings) */
#ifndef USE_MANUAL_VECTORISATION
#define USE_MANUAL_VECTORISATION 0x1

/* Loop unrolling macros */
#if !defined LOOP_UNROLL_2X
#define LOOP_UNROLL_2X 0x2
#endif

#if !defined LOOP_UNROLL_4X
#define LOOP_UNROLL_4X 0x4
#endif

#if !defined LOOP_UNROLL_8X
#define LOOP_UNROLL_8X 0x8
#endif

#if defined _WIN64 
#if !defined LOOP_UNROLL_16X
#define LOOP_UNROLL_16 0xF
#endif
#endif

#endif

/* ICC auto - vectorization undef 
   manual vectorisation in order 
   to use auto-vectoriser*/
#ifndef USE_AUTO_VECTORISATION
#define USE_AUTO_VECTORISATION 0x1
#endif

/* Agressive manual optimization
   Possibly unsafe.*/
#ifndef AGRESSIVE_MAN_OPTMIZATION
#define AGRESSIVE_MAN_OPTIMIZATION 0x1
#endif

/* Used inside operator copy assignment*/
#ifndef VECTORIZE_COPY_OPERATOR
#define VECTORIZE_COPY_OPERATOR 0x1
#endif


/* Debug severe default level 0x1 calls
   _ASSERTE macro.
   Level 0x2 calls ASSERT macro.*/
#if defined _DEBUG
#undef _DEBUG
#define WRF_DEBUG_SEVERE 0x1

#endif

/* Set this to 1 if your CPU has SSE ISA only*/
#ifndef CPU_HAS_SSE_ONLY
#define CPU_HAS_SSE_ONLY 0x0
#endif



/* Undef these macros in order to rely on superior
   ICC optmization, otherwise loops will be
   manually vectorised and unrolled.*/
/* ICC optimization levels */
/* Optimization level: disabled */
#if !defined ICC_NO_OPTIMIZATION
#define ICC_NO_OPTIMIZATION 0x1
#endif

/* Optimization level: low*/
#if !defined ICC_LOW_OPTIMIZATION_LEVEL
#define ICC_LOW_OPTIMIZATION_LEVEL 0x2
#endif

/* Optimization level: medium*/
#if !defined ICC_MEDIUM_OPTIMIZATION_LEVEL
#define ICC_MEDIUM_OPTIMIZATION_LEVEL 0x3
#endif

/* Optimization level: high*/
#if !defined ICC_HIGH_OPTIMIZATION_LEVEL && defined (__AVX__)
#define ICC_HIGH_OPTMIZATION_LEVEL 0x4
#endif

/* Emulate Fortran Optional statement*/
#ifndef FORTRAN_OPTIONAL
#define FORTRAN_OPTIONAL 0x0
#endif

/* Conditional compilation of software prefetch for L2 Cache
   Set these values to the exact  size in units of float(4 bytes)
   and units of double(8 bytes).*/
#ifndef PREFETCH_TO_L2
#define PREFETCH_TO_L2 0x1
#define DATA_SIZE_TO_BE_CACHED_FLOAT 0
#define DATA_SIZE_TO_BE_CACHED_DOUBLE 0
#endif

#ifndef MAX_L1_SIZE_FLOAT
#define MAX_L1_SIZE_FLOAT 8000
#endif

#ifndef MAX_L1_SIZE_DOUBLE
#define MAX_L1_SIZE_DOUBLE 4000
#endif

#ifdef PREFETCH_TO_L2
#define DISABLE_HW_PREFETCH 0x1
#endif

#ifndef EXPAND_SCALARS_TO_VECTOR
#define EXPAND_SCALARS_TO_VECTOR 0x1
#endif

#ifndef COLLECT_PERF_DATA
#define COLLECT_PERF_DATA 0x1
#endif

/***************************
  Memory alignment defines
***************************/
#ifndef WRF_USE_ALIGNED_ALLOCATOR
#define WRF_USE_ALIGNED_ALLOCATOR 0x1
#endif

#ifdef WRF_USE_ALIGNED_ALLOCATOR
#define WRF_ALIGN_ON_16_BYTES 16
#define WRF_ALIGN_ON_32_BYTES 32
#endif


#endif /*_ALL_INCLUDES_H_03_04_16*/