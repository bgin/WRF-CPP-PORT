#ifndef _ALL_INCLUDES_H_03_04_16
#define _ALL_INCLUDES_H_03_04_16   0x100

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
#include <boost\multi_array.hpp>


#if !defined CONFIG_MARCH
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
#ifndef VECTORISE
#define VECTORISE 0x1
#endif
#endif /*_ALL_INCLUDES_H_03_04_16*/