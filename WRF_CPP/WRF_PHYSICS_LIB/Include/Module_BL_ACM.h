#ifndef _MODULE_BL_ACM_H_02_04_16
#define _MODULE_BL_ACM_H_02_04_16  0x100

#include "WRF_PHYS_LIB_TYPEDEFS.h"
#include <boost\multi_array.hpp>
#include <boost\units\base_unit.hpp>



	template<typename T>  struct LOCAL_CONSTANTS {

		constexpr  T RIC{ 0.25 };
		constexpr  T CRANKP{ 0.5 };
	};

	using MAT1D = boost::multi_array<float, 1>;

namespace  wrf_physics {

	namespace  bl_acm {

		/**********************************************************************

				!FUNCTION:
				!Solves tridiagonal system by Thomas algorithm.
				!The associated tri - diagonal system is stored in 3 arrays
				!D : diagonal
				!L : sub - diagonal
				!U : super - diagonal
				!B : right hand side function
				!X : return solution from tridiagonal solver

				![D(1) U(1) 0    0    0 ...       0]
				![L(2) D(2) U(2) 0    0 ...       .]
				![0    L(3) D(3) U(3) 0 ...       .]
				![.       .     .     .           .] X(i) = B(i)
				![.             .     .     .     0]
				![.                   .     .     .]
				![0                           L(n) D(n)]

				************************************************************************/

		

		template<typename T, WRF_INT KL, WRF_INT NSP> class TRIDIAGONAL {


		public:


			/**************************************************
			         Class Constructors and Destructor
			***************************************************/
			/*
			       Default Ctor initializes class member arrays
			*/
			TRIDIAGONAL();

			/*
			@brief      Copy-Ctor.
			*/
			TRIDIAGONAL(_In_ const TRIDIAGONAL &);

			/*
			@brief     Move-Ctor.
			*/
			TRIDIAGONAL(_In_ TRIDIAGONAL &&);

			/*
			@brief   Class Dtor explicitly default
			*/
			~TRIDIAGONAL() = default;

			/**************************************
			    Class member and friend operators
			***************************************/
            

			/*
			 @brief        *this = rhs, denotes copy operation.
			*/
			auto     operator=(_In_ const TRIDIAGONAL &)->TRIDIAGONAL &;

			/*
			           *this = rhs, denotes move operation.
			*/
			auto     operator=(_In_ TRIDIAGONAL &&)->TRIDIAGONAL &;

			/*
			@brief     "subscripting" operator()() returns element
			           from m_X solution array. Data is mutable.
			*/
			auto     operator()(_In_ const WRF_INT, _In_ const WRF_INT)->T;

			/*
			@brief     "subscripting" operator()() returns element
			            from m_X solution array. Data is immutable.
			*/
			auto     operator()(_In_ const WRF_INT, _In_ const WRF_INT)const ->const T;

			/*
			@brief      overloaded operator<<
			*/
			auto   friend   operator<<(_In_ std::ostream &, _In_ const TRIDIAGONAL &)->std::ostream &;


			/*************************************************
			                Member Functions
			**************************************************/

			auto       solve(_In_ const boost::multi_array<T, 1> &, _In_ const boost::multi_array<T, 1> &,
				_In_ const boost::multi_array<T, 1> &, _In_ const boost::multi_array<T, 2> &)->TRIDIAGONAL &;


		private:

			/*
			     class member m_X which upon
				 algorithm completion will contain a solution.
			*/
			boost::multi_array<T, 2> m_X;

			Boost_Matrix1D_Type<T>::WRF_Mat1D m_XX;
		};

		
		/***************************************************************
		!
		!-- Bordered band diagonal matrix solver for ACM2

		!-- ACM2 Matrix is in this form:
		!   B1 E1
		!   A2 B2 E2
		!   A3 C3 B3 E3
		!   A4    C4 B4 E4
		!   A5       C5 B5 E5
		!   A6          C6 B6

		!--Upper Matrix is
		!  U11 U12
		!      U22 U23
		!          U33 U34
		!              U44 U45
		!                  U55 U56
		!                      U66

		!--Lower Matrix is:
		!  1
		! L21  1
		! L31 L32  1
		! L41 L42 L43  1
		! L51 L52 L53 L54  1
		! L61 L62 L63 L64 L65 1
		!---------------------------------------------------------
		***********************************************************/

		template<typename T, WRF_INT KL, WRF_INT NSP>  class MATRIX {



		public:

			/************************************************
			         Class Constructors and Destructor
			*************************************************/

			/*
			         Default Ctor initializes class member m_X.
			*/
			MATRIX();

			/*
			         Copy-Ctor.
			*/
			MATRIX(_In_  const MATRIX &);

			/*
			         Move-Ctor.
			*/
			MATRIX(_In_ MATRIX &&);

			/*
			         Default Dtor
			*/
			~MATRIX() = default;


		private:

			

			/*
			@brief    class member m_X.
			*/
			boost::multi_array<T, 2> m_X;
		};


#include "Module_BL_ACM.inl"

	}
}
#endif /*_MODULE_BL_ACM_H_02_04_16*/