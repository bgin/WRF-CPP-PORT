#ifndef WRF_PHYS_EXCEPT_H_04_27_16 
#define WRF_PHYS_EXCEPT_H_04_27_16 

/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library exception classes -  declaration.

@file Wrf_phys_except.h
@author: Bernard Gingold
@version:  1.0.0  28/04/2016
@description: Wrf_phys_except.h
*/

#ifndef WRF_PHYS_EXCEPT_VERSION_MAJOR
#define WRF_PHYS_EXCEPT_VERSION_MAJOR 1
#endif

#ifndef WRF_PHYS_EXCEPT_VERSION_MINOR
#define WRF_PHYS_EXCEPT_VERSION_MINOR 0
#endif

#ifndef WRF_PHYS_EXCEPT_CREATE_DATE
#define WRF_PHYS_EXCEPT_CREATE_DATE 20160427
#endif

/* Set this macro to successful build date.*/
#ifndef WRF_PHYS_EXCEPT_BUILD_DATE
#define WRF_PHYS_EXCEPT_BUILD_DATE 0
#endif

#include <iostream>
#include <iomanip>
#include "WRF_PHYS_LIB_TYPEDEFS.h"

namespace  wrf_physics{

	namespace utils_exceptions {

		/********************************************
		       Class Wrf_underflow_except
			   Only floating-point types
		*********************************************/

		class Wrf_underflow_except {


		public:

			

			/* Default Ctor */
			Wrf_underflow_except();

			/* Main class Ctor initializes exception object with the user
			   passed message and faulted variable (argument)*/
			Wrf_underflow_except(_In_ const WRF_STRING&, 
				                 _In_ const WRF_REAL64, 
				                 _In_ const WRF_REAL32,
				                 _In_ const int, 
								 _In_ const WRF_WSTRING&);

			/* Copy Ctor */
			Wrf_underflow_except(_In_ const Wrf_underflow_except&);

			/* Move-Ctor*/
			Wrf_underflow_except(_In_ Wrf_underflow_except &&);

			/* Class Dtor = default */
			~Wrf_underflow_except() = default;

			/***************************************************
			             Class member functions
			****************************************************/

			/* function getter returns user m_sMsg variable*/
			const WRF_STRING  getMsg() const;

			/* getter function  retuns 
			   double-precision underflow faulty variable*/
			const WRF_REAL64   getFaultVarf64() const;

			/* getter function returns
			   single-precision underflow faulty variable*/
			const WRF_REAL32   getFaultVarf32() const;

			/* getter function returns
			   line of code where underflow occurred.*/
			const WRF_INT      getLOC()const;

			/* getter function returns
			   WRF_WSTRING with the address of function
			   where underflow occurred.*/
			const WRF_WSTRING  getFuncAddress()const;

			/* this functions displays detailed description
			   about the error(exception). Used in conjuction
			   with catch handler*/
			void  description() const;


		private:


			/* class member variable m_sMsg , denotes 
			   user passed exception description*/
			WRF_STRING  m_sMsg;

			/* class member m_dFaultVarf64, denotes so
			   called faulty variable which caused 
			   floating-point double-precision underflow*/
			WRF_REAL64  m_dFaultVarf64;

			/* class member m_dFaultVarf32, denotes
			   so called faulty variable which caused
			   floating-point single-precision underflow.*/
			WRF_REAL32   m_fFaultVarf32;

			/* Class member m_iLOC, denotes line of code
			   where fault occurred.*/
			WRF_INT  m_iLOC;

			/* Class member m_sFuncAddress, denotes
			   name resolved to address of function
			   where fault occurred.*/
			WRF_WSTRING m_sFuncAddress;
		};

		

		/*************************************************
		            Class Wrf_overflow_except  
					Only floating-point types
		**************************************************/

		class Wrf_overflow_except {



		public:

			/* Default Ctor. */
			Wrf_overflow_except();

			/* Main class Ctor, initializes member variables 
			   with the error desc message and with overflow
			   variables.*/
			Wrf_overflow_except(_In_ const WRF_STRING&, 
				_In_ const WRF_REAL64,
				_In_ const WRF_REAL32,
				_In_ const WRF_INT,
				_In_ const WRF_WSTRING&);

			/* Copy-Constructor. */
			Wrf_overflow_except(_In_ const Wrf_overflow_except &);

			/* Move-Constructor. */
			Wrf_overflow_except(_In_ Wrf_overflow_except &&);

			/* Class Destructor = default. */
			~Wrf_overflow_except() = default;

			/****************************************
			         Class member functions
			*****************************************/

			/* getter function returns m_sMsg variable*/
			const WRF_STRING  getMsg() const;

			/* getter function retuens m_dFaultVarF64 variable*/
			const WRF_REAL64       getFaultVarf64() const;

			/* getter function returns m_fFaultVarf32 variable*/
			const WRF_REAL32        getFaultVarf32() const;

			/* getter functions returns m_iLOC variable.*/
			const WRF_INT           getLOC() const;

			/* getter function returns m_sFuncAddress variable.*/
			const WRF_WSTRING       getFuncAddress() const;

			/* member function displays detailed exception
			   information.*/
			void  description() const;

		private:

			/* class variable m_sMsg, denotes user passed
			   const std::string which containes error
			   description.*/
			WRF_STRING m_sMsg;

			/* class variable m_dFaultVarf64, denotes so
			   called faulty variable which caused 
			   floating-point double-precision Overflow*/
		    WRF_REAL64 m_dFaultVarf64;

			/* class variable m_dFaultVarf32, denotes so
			called faulty variable which caused
			floating-point single-precision Overflow*/
			WRF_REAL32  m_fFaultVarf32;

			/* class variable m_iLOC, denotes line of 
			   code where fault occurred.*/
			WRF_INT     m_iLOC;

			/* class variable m_sFuncAddress denotes
			   hex address of function where fault
			   occurred*/
			WRF_WSTRING  m_sFuncAddress;
		};

		/**************************************************
		           Class Wrf_invalid_arg_except
				   Templated on type T
		***************************************************/
		template<typename T>  class Wrf_invalid_arg_except {


			/* Default Ctor does nothing */
			Wrf_invalid_arg_except();


			/* Main class Ctor, initializes exception
			   object with the user passed message and
			   the argument which triggered exception*/
			Wrf_invalid_arg_except(_In_ const WRF_STRING, 
				                   _In_ const T,
								   _In_ const WRF_INT,
								   _In_ const WRF_WSTRING& );

			/* Copy Constructor */
			Wrf_invalid_arg_except(_In_ const Wrf_invalid_arg_except &);

			/* Move Constructor */
			Wrf_invalid_arg_except(_In_ Wrf_invalid_arg_except &&);

			/* Class Destructor = default */
			~Wrf_invalid_arg_except() = default;

			/***************************************
			          Class member functions
			****************************************/

			/* This function returns user passed message*/
			auto    getMsg()const->WRF_STRING;

			/* This function returns copy of 
			   invalid argument which caused
			   an exception */
			auto    getInvArg()const->T;

			/* This function returns member
			    variable m_iLOC.
			  */
			auto    getLOC()const->WRF_INT;

			/* This function returns member
			   variable m_sFuncAddress.*/
			auto    getFuncAddress()const->WRF_WSTRING;

			/* This function returns detailed 
			   description of the errorneous
			   condition which caused an excep-
			   tion.*/
			auto    description()const->void;



		private:

			/* class member m_sMsg, denotes user
			   passed string message*/
			WRF_STRING m_sMsg;

			/* class member m_tInvArg, denotes
			   user passed invalid argument which
			   triggered exception.*/
			T  m_TInvArg;

			/* class variable m_iLOC, denotes line of
			code where fault occurred.*/
			WRF_INT     m_iLOC;

			/* class variable m_sFuncAddress denotes
			hex address of function where fault
			occurred*/
			WRF_WSTRING  m_sFuncAddress;
		};

		/*******************************************
		    Class Wrf_out_boundary_except
			Templated on type T. Compile
			time checked if T is::integral
		*******************************************/

		template<typename T> class 
			             Wrf_out_boundary_except {
			
			 


		public:

			/* Default Constructor, does nothing (
			   creates empty exception object)*/
			Wrf_out_boundary_except();

			/* Main class Constructor initializes
			   exception object with the user passed
			   description of the error*/
			template<typename T2  = typename std::enable_if<std::is_integral<T>::value>::type>
			Wrf_out_boundary_except(_In_ const WRF_STRING&, 
				                    _In_ const T,
									_In_ const WRF_INT,
									_In_ const WRF_WSTRING&);

			/* Copy Constructor */
			Wrf_out_boundary_except(_In_ const Wrf_out_boundary_except &);

			/* Move Constructor */
			Wrf_out_boundary_except(_In_ Wrf_out_boundary_except &&);

			/* Destructor = default */
			~Wrf_out_boundary_except() = default;

			/*****************************************************
			                   Class member functions
			******************************************************/

			/* This function returns user passed
			   exception description*/
			auto  getMsg()const->WRF_STRING;

			/* This function returns user passed
			   variable which caused an exception*/
			auto  getOutBound()const->T;

			/* This function returns class
			   variable m_iLOC.*/
			auto  getLOC()const->WRF_INT;

			/* This function returns class
			   variable m_sFuncAddress.*/
			auto  getFuncAddress()const->WRF_WSTRING;

			/* This function provides detailed
			   description of the error*/
			auto  description()const->void;


		private:

			/* class member m_sMsg, denotes user
			passed string message*/
			WRF_STRING m_sMsg;

			/* class member m_tOutBound, denotes
			   user passed argument which is out of
			   the array boundary.*/
			T m_tOutBound;

			/* class variable m_iLOC, denotes line of
			code where fault occurred.*/
			WRF_INT     m_iLOC;

			/* class variable m_sFuncAddress denotes
			hex address of function where fault
			occurred*/
			WRF_WSTRING  m_sFuncAddress;

			};

		/*************************************************
		    Class Wrf_math_divergence_except
			Templated on type T. Thrown when
			specific value convergence is not
			reached.
		**************************************************/

		template<typename T> class Wrf_math_divergence_except {





		public:


			/* Class default Constructor, does
			   nothing, creates empty exception
			   object.*/
			Wrf_math_divergence_except();

			/* Class main Constructor, creates
			   exception object with user passed
			   message and copy of non-converged
			   value.*/
			Wrf_math_divergence_except(_In_ const WRF_STRING &, 
				                       _In_ const T,
									   _In_ const WRF_INT,
									   _In_ const WRF_WSTRING &);

			/* Copy-Constructor */
			Wrf_math_divergence_except(_In_ const Wrf_math_divergence_except &);

			/* Move-Constructor */
			Wrf_math_divergence_except(_In_ Wrf_math_divergence_except &&);

			/* Class default Destructor */
			~Wrf_math_divergence_except() = default;

			/**********************************************
			          Class member functions
			**********************************************/

			/* This function returns copy of user passed
			   message.*/
			auto    getMsg()const->WRF_STRING;

			/* This function returns copy of user
			   passed value which did not converge*/
			auto    getDivergVal()const->T;

			/* This function returns class
			    variable m_iLOC. */
			auto    getLOC()const->WRF_INT;

			/* This function returns class
			   variable m_sFuncAddress.*/
			auto    getFuncAddress()const->WRF_WSTRING;

			/* This function displays detailed
			   info about the thrown exception.*/
			auto    description()const->void;



		private:

			/* class variable m_sMsg, denotes
			   user passed message */
			WRF_STRING m_sMsg;

			/* class variable m_tDivergVal, denotes
			   copy of user passed value which 
			   did not converge.*/
			T m_tDivergVal;

			/* class variable m_iLOC, denotes line of
			code where fault occurred.*/
			WRF_INT     m_iLOC;

			/* class variable m_sFuncAddress denotes
			hex address of function where fault
			occurred*/
			WRF_WSTRING  m_sFuncAddress;
		};

		/***********************************************
		          Class Wrf_null_pointer_except
		************************************************/

		template<typename T>  class
			       Wrf_null_pointer_except {



		public:

			/* Class Constructor default */
			Wrf_null_pointer_except();

			/* Main Class Constructor initializes exception
			   object with the user passed message and
			   with the value of failed/invalid pointer*/
			Wrf_null_pointer_except(_In_ const WRF_STRING &, 
				                    _In_ const T,
									_In_ const WRF_INT,
									_In_ const WRF_WSTRING &);

			/* Copy Constructor */
			Wrf_null_pointer_except(_In_ const Wrf_null_pointer_except &);

			/* Move Constructor */
			Wrf_null_pointer_except(_In_  Wrf_null_pointer_except &&);

			/* Destructor default */
			~Wrf_null_pointer_except() = default;


			/************************************************
			             Class member functions
			*************************************************/

			/* This function returns copy of user
			   passed message */
			auto  getMsg()const->WRF_STRING;

			/* This function returns copy of
			   user passed failed/invalid
			   pointer. */
			auto  getNullPtrVal()const->T;

			/* This function returns class
			variable m_iLOC. */
			auto    getLOC()const->WRF_INT;

			/* This function returns class
			variable m_sFuncAddress.*/
			auto    getFuncAddress()const->WRF_WSTRING;

			/* This function displays detailed
			   ecxeption description.*/
			auto  description()const->void;


		private:

			/* class member m_sMsg denotes
			   user passed message which
			   describes the error  */
			WRF_STRING m_sMsg;

			/* class member m_tNullPtrVal,which
			   denotes copy of null/invalid pointer value*/
			   
			T  m_tNullPtrVal;

			/* class variable m_iLOC, denotes line of
			code where fault occurred.*/
			WRF_INT     m_iLOC;

			/* class variable m_sFuncAddress denotes
			hex address of function where fault
			occurred*/
			WRF_WSTRING  m_sFuncAddress;

		};

		/*************************************************
		      Class Wrf_math_error_except
			  Templated on parameter T.
			  Describes generic math error:
			  Invalid result or result which
			  differs from the expected.
		**************************************************/

		template<typename T>  class
			           Wrf_math_error_except {


		public:

			/* Class Constructor default,
			 *  creates an empty exception object.*/
			Wrf_math_error_except();

			/* Main class Constructor initializes
			 *  exception object from user passed
			 * error message and user passed faulty
			 * variables.*/
			Wrf_math_error_except(_In_ const WRF_STRING &, 
				                  _In_ const T,
								  _In_ const WRF_INT,
								  _In_ const WRF_WSTRING &);

			/* Copy Constructor */
			Wrf_math_error_except(_In_ const Wrf_math_error_except &);

			/* Move Constructor */
			Wrf_math_error_except(_In_ Wrf_math_error_except &&);

			/* Class Destructor default.*/
			~Wrf_math_error_except() = default;

			/***************************************************
			                Class member functions
			****************************************************/

			/* This functions returns copy of user
			   error description message.*/
			auto   getMsg()const->WRF_STRING;

			/* This function returns copy of user
			    passed fault variable.*/
			auto   getMathErr()const->T;

			/* This function returns class
			variable m_iLOC. */
			auto    getLOC()const->WRF_INT;

			/* This function returns class
			variable m_sFuncAddress.*/
			auto    getFuncAddress()const->WRF_WSTRING;

			/* This function displays detailed
			   exception description.*/
			auto   description()const->void;




		private:

			/* class variable m_sMsg, which contains copy
			   of user passed error message*/

			WRF_STRING m_sMsg;

			/* class variable m_tMathErr, which contains
			   copy of user passed errorneous variable*/
			T m_tMathErr;

			/* class variable m_iLOC, denotes line of
			code where fault occurred.*/
			WRF_INT     m_iLOC;

			/* class variable m_sFuncAddress denotes
			hex address of function where fault
			occurred*/
			WRF_WSTRING  m_sFuncAddress;

		};

		/******************************************************
		  Class Wrf_unaligned16_except class.
		  Unaligned memory access exception. Alignment is 
		  on 16-bytes boundaries.
		  Template argument should be of type pointer: T*
		*******************************************************/
		template< typename T = void*> class Wrf_unaligned16_except {

        

		public:

			/* Default Ctor construct partly uninitialized
			   object.This object should not accessed.*/
			Wrf_unaligned16_except();

			/* Main Class Constructor initializes object 
			   to user passed values.*/
			Wrf_unaligned16_except(_In_ const WRF_STRING &,
				                   _In_ const T,
				                   _In_ const WRF_INT,
				                   _In_ const WRF_WSTRING &);

			/* Copy Constructor.*/
			Wrf_unaligned16_except(_In_ const Wrf_unaligned16_except &);

			/* Move Constructor. */
			Wrf_unaligned16_except(_In_ Wrf_unaligned16_except &&);

			/* Destructor = default. */
			~Wrf_unaligned16_except() = default;

			/*********************************************
			            Class member functions
			**********************************************/

			/* This functions returns member variable 
			   m_sMsg.*/
			auto    getMsg()const->WRF_STRING;

			/* This function returns member variable
			   m_pUnalignVal*/
			auto    getUnalignVal()const->T;

			/* This function returns member variable
			   m_iLOC.*/
			auto    getLOC()const->WRF_INT;

			/* This function returns member variable
			   m_sFuncAddress.*/
			auto    getFuncAddress()const->WRF_WSTRING;


			/* This function displays detailed description
			   about the exception.*/
			auto     description()const->void;

		private:

			/* class variable m_sMsg, which contains copy
			of user passed error message*/

			WRF_STRING m_sMsg;

			/* Class variable m_pUnalignVal, denotes copy of user passed
			   pointer variable which is unaligned on 16-bytes boundary*/
			T m_pUnalignVal;

			/* Class variable m_iLOC denotes line of code where the
			   exception condition occurred.*/
			WRF_INT m_iLOC;

			/* Class variable m_sFuncAddress , denotes string encoded
			   hex value of function address where an exception occurred.*/
			WRF_WSTRING m_sFuncAddress;
			   
		};

		/*********************************************************
		  Class Wrf_unaligned32_except class.
		  Unaligned memory access exception. Alignment is 
		  on 32-bytes boundaries.
		  Template argument should be of type pointer: T = void*
		*********************************************************/
		template<typename T = void*> class Wrf_unaligned32_except {


		public:

			/****************************************
			       Constructors and Destructor
			****************************************/
			
			/* Default Constructor - default object
			   initilization. description function
			   should not be called on this object.*/
			Wrf_unaligned32_except();

			/* Main class Constructor - initializes
			   exception object with the user passed
			   data/variables.*/
			Wrf_unaligned32_except(_In_ const WRF_STRING &,
				                   _In_ const T,
				                   _In_ const WRF_INT,
				                   _In_ const WRF_WSTRING &);

			/* Copy Constructor.*/
			Wrf_unaligned32_except(_In_ const Wrf_unaligned32_except &);

			/* Move Constructor */
			Wrf_unaligned32_except(_In_ Wrf_unaligned32_except &&);

			/* Destructor = default. */
			~Wrf_unaligned32_except() = default;

			/****************************************
			         Class member functions.
			*****************************************/

			/* This function returns member variable m_sMsg.*/
			auto  getMsg()const->WRF_STRING ;

			/* This function returns member variable
			   m_pUnalignVal.*/
			auto  getUnalignVal()const->T;

			/* This function returns member variable
			   m_iLOC.*/
			auto  getLOC()const->WRF_INT;

			/* This function returns member variable
			   m_sFuncAddress.*/
			auto  getFuncAddress()const->WRF_WSTRING;

			/* This function provides detailed 
			   description of the exception.*/
			auto  description()const->void;



		private:

			/* class variable m_sMsg, which contains copy
			of user passed error message*/

			WRF_STRING m_sMsg;

			/* Class variable m_pUnalignVal, denotes copy of user passed
			pointer variable which is unaligned on 32-bytes boundary*/
			T m_pUnalignVal;

			/* Class variable m_iLOC denotes line of code where the
			exception condition occurred.*/
			WRF_INT m_iLOC;

			/* Class variable m_sFuncAddress , denotes string encoded
			hex value of function address where an exception occurred.*/
			WRF_WSTRING m_sFuncAddress;
		};


		

		
		
#include "Wrf_phys_except.inl"
	}
}
#endif /*WRF_PHYS_EXCEPT_H_04_27_16*/