#ifndef _WRF_PHYS_LIB_TYPEDEFS_H_
#define _WRF_PHYS_LIB_TYPEDEFS_H_ 

#ifndef WRF_PHYS_LIB_TYPEDEFS_VERSION_MAJOR
#define WRF_PHYS_LIB_TYPEDEFS_VERSION_MAJOR 1
#endif

#ifndef WRF_PHYS_LIB_TYPEDEFS_VERSION_MINOR
#define WRF_PHYS_LIB_TYPEDEFS_VERSION_MINOR 0
#endif

#ifndef WRF_PHYS_LIB_TYPEDEFS_CREATE_DATE
#define WRF_PHYS_LIB_TYPEDEFS_CREATE_DATE 20160314
#endif

/* Set this value to successful build date*/
#ifndef WRF_PHYS_LIB_TYPEDEFS_BUILD_DATE
#define WRF_PHYS_LIB_TYPEDEFS_BUILD_DATE 0
#endif

#include "MARCH.h"

#ifdef WRF_USE_ALIGNED_ALLOCATOR
#include "Wrf_memory.hpp"
#endif

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
typedef   std::vector<WRF_REAL32>   WRF_StdVectorF32;

/*
     std::vector<double>    data type.
*/
typedef   std::vector<WRF_REAL64>  WRF_StdVectorF64;

/*
     std::vector<WRF_INT> data type.
*/
typedef   std::vector<WRF_INT>  WRF_StdVectorInt32;

/*
     std::vector<WRF_LONGLONG> data type.
*/
typedef   std::vector<WRF_LONGLONG> WRF_StdVectorInt64;

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


  /*  boost::multi_array<double,3>   data type.
	3D Matrix KxNxM.*/

typedef   boost::multi_array<double, 3>      WRF_Mat3DF64;

#ifdef WRF_USE_ALIGNED_ALLOCATOR


/***********************************************
  Typedefs boost::multi_array data types
  aligned on 16,32 bytes boundaries.
************************************************/

/***************************************
              Aligned allocators
****************************************/
typedef wrf_physics::wrf_physics_internal::memory::
       aligned_allocator<WRF_REAL32, WRF_ALIGN_ON_16_BYTES> WRF_ALLOCATOR_16B;

typedef wrf_physics::wrf_physics_internal::memory::
       aligned_allocator<WRF_REAL64, WRF_ALIGN_ON_32_BYTES> WRF_ALLOCATOR_32B;
/*
   boost::multi_array<float,1> data type aligned.
   Row matrix 1xN.
*/
typedef  boost::multi_array < WRF_REAL32, 1, WRF_ALLOCATOR_16B> WRF_Mat1DF32A;
	    

/*
   boost::multi_array<float,2> data type aligned on 16 bytes.

   2D Matrix NxM.
*/
typedef boost::multi_array < WRF_REAL32, 2, WRF_ALLOCATOR_16B> WRF_Mat2DF32A;
	 
/*
   boost::multi_array<float,3>  data type.
   3D Matrix KxNxM.
*/
typedef boost::multi_array< WRF_REAL32, 3, WRF_ALLOCATOR_16B> WRF_Mat3DF32A;

/*
   boost::multi_array<double,1> data type.
   Row matrix 1xN.
*/
typedef boost::multi_array< WRF_REAL64, 1, WRF_ALLOCATOR_32B> WRF_Mat1DF64A;

/*
   boost::multi_array<double,2>  data type.
   2D Matrix NxM.
*/
typedef boost::multi_array< WRF_REAL64, 2, WRF_ALLOCATOR_32B> WRF_Mat2DF64A;

/*  boost::multi_array<double,3>   data type.
    3D Matrix KxNxM.*/
typedef boost::multi_array< WRF_REAL64, 3, WRF_ALLOCATOR_32B> WRF_Mat3DF64A;

#endif /* WRF_USE_ALIGNED_ALLOCATOR */

/***************************************************
  Mass to mass per second (nominal) growth ratio.
  Units of KMS: kg*kg^-1*s^-1
****************************************************/

/* boost::multi_array<quantity<mass,float>,2> 
   data type*/
typedef   boost::multi_array<boost::units::quantity
	      <boost::units::si::mass, WRF_REAL32>, 2> KMSProdRatioF32;


/* boost::multi_array<quantity<mass,float>,2> 
   data type*/
typedef   boost::multi_array<boost::units::quantity
	      <boost::units::si::mass, WRF_REAL32>, 2>  KMSProdRatioF64;

/* **********************************************
  Smart pointers holding raw arrays only
*************************************************/

/*
       std::unique_ptr<WRF_REAL32,void(*)(REAL32*)>
 */
typedef std::unique_ptr<WRF_REAL32, void(*)(WRF_REAL32*)> WRF_UPTRF32;

/*
        std::unique_ptr<WRF_REAL64,void(*)(REAL64*)>
*/
typedef std::unique_ptr<WRF_REAL64, void(*)(WRF_REAL64*)> WRF_UPTRF64;

/*
         std::shared_ptr<WRF_REAL32>
*/
typedef std::shared_ptr<WRF_REAL32> WRF_SHPTRF32;

/*
         std::shared_ptr<WRF_REAL64>
*/
typedef std::shared_ptr<WRF_REAL64> WRF_SHPTRF64;

/********************************************************
   boost::multi_array<T,N> wrapped in templated 
   on type T struct.
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

/*
       Matrix 4D JxKxNxM templated on parameter T.
*/
template<typename T> struct Boost_Matrix4D_Type {

	 boost::multi_array<T, 4>     WRF_Mat4D;
};

/*              
       std::string typedef
*/
typedef std::string   WRF_STRING;

/*
       std::wstring typedef
*/
typedef  std::wstring  WRF_WSTRING;

/*
     noexcept
*/

#ifndef WRF_CPP_NOEXCEPT
#define WRF_CPP_NOEXCEPT noexcept
#endif

/*
    virtual
*/

#ifndef WRF_CPP_VIRTUAL
#define WRF_CPP_VIRTUAL virtual
#endif

/*
   default
*/
#ifndef WRF_CPP_DEFAULT
#define WRF_CPP_DEFAULT default
#endif

/*
   const
*/
#ifndef WRF_CPP_CONST
#define WRF_CPP_CONST const
#endif

/*
   true
*/
#ifndef WRF_CPP_TRUE
#define WRF_CPP_TRUE true
#endif

/*
   false
*/
#ifndef WRF_CPP_FALSE
#define WRF_CPP_FALSE false
#endif

/*
   override
*/
#ifndef WRF_CPP_OVERRIDE
#define WRF_CPP_OVERRIDE override
#endif

/*
   inline
*/
#ifndef WRF_INLINE
#define WRF_INLINE inline
#endif

/*
   __forceinline
*/
#ifndef WRF_STRONG_INLINE
#define WRF_STRONG_INLINE __forceinline
#endif

/*
FORTRAN-like defines
*/

#define DO_1(i,N)  for(WRF_ULONGLONG i{0}; i != N; ++i)



#endif /*_WRF_PHYS_LIB_TYPEDEFS_H_03_14_16*/