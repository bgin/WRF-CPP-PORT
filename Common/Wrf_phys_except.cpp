
#include "Wrf_phys_except.h"

/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library exception classes -  implementation.

@file Wrf_phys_except.cpp
@author: Bernard Gingold
@version:  1.0.0  28/04/2016
@description: Wrf_phys_except.h
*/

/**************************************************
      Class Wrf_underflow_except implementation
***************************************************/

/* No-arg default ctor*/
wrf_physics::utils_exceptions::Wrf_underflow_except::Wrf_underflow_except() {}

/***********************************************************
               Main class Ctor
		User will pass either float or double
		faulty argument the other member will
		be set to 0
		@param: const std::string& -- Reference
		        to string containing user passed
				message.
        @param: const double faulty variable of type double
		        which caused underflow.
        @param: const float  faulty variable of type float
		        which caused underflow.
        @retunrns: nothing.

***********************************************************/
wrf_physics::utils_exceptions::Wrf_underflow_except::Wrf_underflow_except(_In_ const WRF_STRING& Msg, _In_ const WRF_REAL64 uflowf64, 
	_In_ const WRF_REAL32 uflowf32, _In_ const WRF_INT LOC, _In_ const WRF_WSTRING& FuncAddress) :
m_sMsg{ Msg },
m_dFaultVarf64{ uflowf64 },
m_fFaultVarf32{ uflowf32 },
m_iLOC{ LOC },
m_sFuncAddress{FuncAddress}
{

}

/***************************************************
             Copy-Constructor.
		 @param: const Wrf_underflow_except & - ref.
****************************************************/
wrf_physics::utils_exceptions::Wrf_underflow_except::Wrf_underflow_except(_In_ const Wrf_underflow_except& rhs) :
m_sMsg{ rhs.m_sMsg },
m_dFaultVarf64{ rhs.m_dFaultVarf64 },
m_fFaultVarf32{ rhs.m_fFaultVarf32 },
m_iLOC{ rhs.m_iLOC },
m_sFuncAddress{rhs.m_sFuncAddress}
{

}

/**************************************************
            Move-Constructor.
		@param: Wrf_underflow_except && - rval ref.
***************************************************/
wrf_physics::utils_exceptions::Wrf_underflow_except::Wrf_underflow_except(_In_ Wrf_underflow_except&& rhs) :
m_sMsg{ std::move(rhs.m_sMsg) },
m_dFaultVarf64{ std::move(rhs.m_dFaultVarf64) },
m_fFaultVarf32{ std::move(rhs.m_fFaultVarf32) },
m_iLOC{ std::move(rhs.m_iLOC) },
m_sFuncAddress{ std::move(rhs.m_sFuncAddress) }
{

}

/***************************************************
    getter function: getMsg
	@param: void
	@returns: const std::string - member variable
	          m_sMsg
***************************************************/
const WRF_STRING  wrf_physics::utils_exceptions::Wrf_underflow_except::getMsg() const {

	return (this->m_sMsg);
}

/***************************************************
    getter function: getFaultVarf64
	@param: void
	@returns: faulty variable of type double
****************************************************/
const WRF_REAL64      wrf_physics::utils_exceptions::Wrf_underflow_except::getFaultVarf64() const {

	return (this->m_dFaultVarf64);
}

/*****************************************************
    getter function: getFaultVarf32
	@param: void
	@returns: faulty variable of type float.
*****************************************************/
const   WRF_REAL32        wrf_physics::utils_exceptions::Wrf_underflow_except::getFaultVarf32() const {

	return (this->m_fFaultVarf32);
}

const   WRF_INT           wrf_physics::utils_exceptions::Wrf_underflow_except::getLOC() const {

	return (this->m_iLOC);
}

const  WRF_WSTRING        wrf_physics::utils_exceptions::Wrf_underflow_except::getFuncAddress() const {

	return (this->m_sFuncAddress);
}

/*****************************************************
     member function: description
	 @param: void
	 @returns: void
	 Displays detailed error description to the
	 user/caller.
******************************************************/
void    wrf_physics::utils_exceptions::Wrf_underflow_except::description() const {

	std::cerr << "***************** Underflow Exception *****************" << std::endl;
	std::cerr << "Underflow Exception details: " << this->m_sMsg.c_str() << std::endl;
	std::cerr << "1st faulty variable: " << std::setprecision(16) << this->m_dFaultVarf64 << std::endl;
	std::cerr << "2nd faulty variable: " << std::setprecision(7)  << this->m_fFaultVarf32 << std::endl;
	std::cerr << "At line of code: " << this->m_iLOC << std::endl;
	std::cerr << "At function address: " << std::hex << this->m_sFuncAddress.c_str() << std::endl;
	std::cerr << "At date: " << __DATE__ << " at time: " << __TIME__ << std::endl;
	std::cerr << "****************** Underflow Exception *****************" << std::endl;
}


/*********************************************************************
      Class Wrf_overflow_except implementation
**********************************************************************/

/* No-arg default Ctor */
wrf_physics::utils_exceptions::Wrf_overflow_except::Wrf_overflow_except() {}

/***********************************************************
         Main class Ctor
     User will pass either float or double
     faulty argument the other member will
     be set to 0
     @param: const std::string& -- Reference
            to string containing user passed
            message.
     @param: const double faulty variable of type double
             which caused overflow.
     @param: const float  faulty variable of type float
             which caused overflow.
     @retunrns: nothing.

***********************************************************/
wrf_physics::utils_exceptions::Wrf_overflow_except::Wrf_overflow_except(_In_ const WRF_STRING& Msg, 
	_In_ const WRF_REAL64 oflowf64, 
	_In_ const WRF_REAL32 oflowf32,
	_In_ const WRF_INT LOC,
	_In_ const WRF_WSTRING& FuncAddress) :
m_sMsg{ Msg },
m_dFaultVarf64{ oflowf64 },
m_fFaultVarf32{ oflowf32 },
m_iLOC{ LOC },
m_sFuncAddress{FuncAddress}
{

}

/***************************************************
               Copy-Constructor.
          @param: const Wrf_overflow_except & - ref.
****************************************************/
wrf_physics::utils_exceptions::Wrf_overflow_except::Wrf_overflow_except(_In_ const Wrf_overflow_except &rhs) :
m_sMsg{ rhs.m_sMsg },
m_dFaultVarf64{ rhs.m_dFaultVarf64 },
m_fFaultVarf32{ rhs.m_fFaultVarf32 },
m_iLOC{ rhs.m_iLOC },
m_sFuncAddress{rhs.m_sFuncAddress}
{

}


/***************************************************
            Move-Constructor.
          @param: const Wrf_overflow_except && - rval 
		  ref.
****************************************************/
wrf_physics::utils_exceptions::Wrf_overflow_except::Wrf_overflow_except(_In_ Wrf_overflow_except &&rhs) :
m_sMsg{ std::move(rhs.m_sMsg) },
m_dFaultVarf64{ std::move(rhs.m_dFaultVarf64) },
m_fFaultVarf32{ std::move(rhs.m_fFaultVarf32) },
m_iLOC{ rhs.m_iLOC },
m_sFuncAddress{rhs.m_sFuncAddress}
{

}

/*****************************************************
    getter function: getMsg
******************************************************/
const WRF_STRING wrf_physics::utils_exceptions::Wrf_overflow_except::getMsg() const {

	return (this->m_sMsg);
}

/******************************************************
     getter function: getFaultVarf64
*******************************************************/
const WRF_REAL64 wrf_physics::utils_exceptions::Wrf_overflow_except::getFaultVarf64() const {

	return (this->m_dFaultVarf64);
}

/*******************************************************
      getter function: getFaultVarf32
********************************************************/
const WRF_REAL32 wrf_physics::utils_exceptions::Wrf_overflow_except::getFaultVarf32() const {

	return (this->m_fFaultVarf32);
}

const  WRF_INT   wrf_physics::utils_exceptions::Wrf_overflow_except::getLOC() const {

	return (this->m_iLOC);
}

const  WRF_WSTRING  wrf_physics::utils_exceptions::Wrf_overflow_except::getFuncAddress() const {

	return (this->m_sFuncAddress);
}

/*****************************************************
         member function: description
         @param: void
         @returns: void
         Displays detailed error description to the
         user/caller.
******************************************************/
void  wrf_physics::utils_exceptions::Wrf_overflow_except::description() const {

	std::cerr << "****************** Overflow Exception ***************" << std::endl;
	std::cerr << "Overflow Exception details: " << this->m_sMsg.c_str() << std::endl;
	std::cerr << "1st faulty variable: " << std::setprecision(16) << this->m_dFaultVarf64 << std::endl;
	std::cerr << "2nd faulty variable: " << std::setprecision(7) << this->m_fFaultVarf32 << std::endl;
	std::cerr << "At line of code: " << this->m_iLOC << std::endl;
	std::cerr << "At function address: " << std::hex << this->m_sFuncAddress.c_str() << std::endl;
	std::cerr << "At date: " << __DATE__ << " at time: " << __TIME__ << std::endl;
	std::cerr << "*********************************************************" << std::endl;
}