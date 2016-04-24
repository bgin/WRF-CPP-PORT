#ifndef _WRF_PHYS_LIB_TYPEDEFS_H_03_14_16 
#define _WRF_PHYS_LIB_TYPEDEFS_H_03_14_16   0x100

#include "MARCH.h"
/*************************************************
        Library type definitions 
**************************************************/

/*************************************************
         Primitive data types 
*************************************************/

// IEEE-754 32-bit single-precision type
typedef   float WRF_REAL32;

// IEEE-754 64-bit double-precision type.
typedef   double WRF_REAL64;

/*
 Notice:
       Windows CRT will not support extended double-precision 
	   80-bit long double data type.
*/
#if defined (__linux__) && defined (__LONG_DOUBLE_SIZE__)
// IEEE-754 80-bit extended double-precision type.
typedef   long double WRF_REAL80;
#endif

/************************************************
      Integer types
*************************************************/

/*
    Logical(bool) data type
*/
typedef  bool WRF_BOOL;

/*
     unsigned char data type.
*/
typedef unsigned char WRF_UCHAR;

/*
    "signed" char data type
*/
typedef  char WRF_CHAR;

/*
     unsigned short data type
*/
typedef  unsigned short WRF_USHORT;

/*
     "signed" short data type
*/
typedef  short WRF_SHORT;

/*
      unsigned int data type.
*/
typedef  unsigned int WRF_UINT;

/*
      "signed" int data type
*/
typedef  int WRF_INT;

/*
     unsigned long long data type
*/
typedef  unsigned long long WRF_ULONGLONG;

/*
     "signed" long long
*/
typedef  long long   WRF_LONGLONG;

/*
      ptrdiff_t
*/
typedef ptrdiff_t WRF_PTRDIFF;

/***************************************************
                    SIMD Vector data types
***************************************************/

/*
     __m128 data type
*/
typedef  __m128  WRF_Vec128F32;

/*
     __m128i data type
*/
typedef  __m128i WRF_Vec128Int;

/*
     __m128d data type
*/
typedef  __m128d WRF_Vec128F64;

/*
     __m256 data type
*/
typedef  __m256  WRF_Vec256F32;

/*
     __m256i data type
*/
typedef  __m256i WRF_Vec256Int;

/*
     __m256d data type.
*/
typedef  __m256d WRF_Vec256F64;

/*
    clock_t data type.
	Used as a seed to random number generator.
*/
typedef clock_t WRF_RNGSEED;

/*************************************
     STL container data types.
**************************************/

/*
     std::valarray<float> data type.
*/
typedef  std::valarray<float>  WRF_StdVArrayF32;

/*
     std::valarray<double> data type.
*/
typedef  std::valarray<double> WRF_StdArrayF64;

/*
     std::vector<float> data type.
*/
typedef   std::vector<float>   WRF_StdVectorF32;

/*
     std::vector<double>    data type.
*/
typedef   std::vector<double>  WRF_StdVectorF64;

/***********************************************
    boost::multi_array  array data types
************************************************/

/*
    boost::multi_array<float,1> data type.
	Row matrix 1xN.
*/
typedef   boost::multi_array<float, 1>  WRF_Mat1DF32;

/*
    boost::multi_array<float,2> data type.
	2D Matrix NxM.
*/
typedef   boost::multi_array<float, 2>   WRF_Mat2DF32;

/*
    boost::multi_array<float,3>  data type.
	3D Matrix KxNxM.
*/
typedef   boost::multi_array<float, 3>    WRF_Mat3DF32;

/*
    boost::multi_array<double,1> data type.
	Row matrix 1xN.
*/
typedef   boost::multi_array<double, 1>    WRF_Mat1DF64;

/*
    boost::multi_array<double,2>  data type.
	2D Matrix NxM.
*/
typedef   boost::multi_array<double, 2>     WRF_Mat2DF64;

/*
    boost::multi_array<double,3>   data type.
	3D Matrix KxNxM.
*/
typedef   boost::multi_array<double, 3>      WRF_Mat3DF64;



/********************************************************
   boost::multi_array<T,N> wrapped in templated struct
********************************************************/


/*
       Matrix 1D 1xN templated on parameter T.
*/
template<typename T> struct Boost_Matrix1D_Type {

	typedef boost::multi_array<T, 1>  WRF_Mat1D;
};

/*
       Matrix 2D NxM templated on parameter T.
*/
template<typename T> struct Boost_Matrix2D_Type {

	typedef boost::multi_array<T, 2>   WRF_Mat2D;
};

/*
       Matrix 3D KxNxM templated on parameter T.
*/
template<typename T> struct Boost_Matrix3D_Type {

	typedef boost::multi_array<T, 3>    WRF_Mat3D;
};


#endif /*_WRF_PHYS_LIB_TYPEDEFS_H_03_14_16*/