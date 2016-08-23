
/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library exception classes -  implementation.

@file Wrf_phys_except.inl
@author: Bernard Gingold
@version:  1.0.0  28/04/2016
@description: Wrf_phys_except.h
*/

template<typename T> wrf_physics::utils_exceptions::Wrf_invalid_arg_except<T>::Wrf_invalid_arg_except() {}

template<typename T> wrf_physics::utils_exceptions::Wrf_invalid_arg_except<T>::Wrf_invalid_arg_except(
	_In_ const WRF_STRING Msg, 
	_In_ const T InvArg,
	_In_ const WRF_INT LOC,
	_In_ const WRF_WSTRING& FuncAddress) :
	m_sMsg{ Msg },
	m_TInvArg{ InvArg },
	m_iLOC{ LOC },
	m_sFuncAddress{FuncAddress}
{

}

template<typename T> wrf_physics::utils_exceptions::Wrf_invalid_arg_except<T>::Wrf_invalid_arg_except(
	_In_ const Wrf_invalid_arg_except &rhs) :
	m_sMsg{ rhs.m_sMsg },
	m_TInvArg{ rhs.mTInvArg },
	m_iLOC{ rhs.m_iLOC },
	m_sFuncAddress{rhs.m_sFuncAddress}
{

}

template<typename T> wrf_physics::utils_exceptions::Wrf_invalid_arg_except<T>::Wrf_invalid_arg_except(
	_In_ Wrf_invalid_arg_except &&rhs) :
	m_sMsg{ std::move(rhs.m_sMsg) },
	m_TInvArg{ std::move(rhs.TInvArg) },
	m_iLOC{ std::move(rhs.m_iLOC) },
	m_sFuncAddress{ std::move(rhs.m_sFuncAddress) }
{

}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_invalid_arg_except<T>::
getMsg()const->WRF_STRING {

	return (this->m_sMsg);
}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_invalid_arg_except<T>::
getInvArg()const->T {

	return (this->m_TInvArg);
}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_invalid_arg_except<T>::
getLOC()const->WRF_INT {

	return (this->m_iLOC);
}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_invalid_arg_except<T>::
getFuncAddress()const->WRF_WSTRING {

	return (this->m_sFuncAddress);
}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_invalid_arg_except<T>::
description()const->void {

	std::cerr << "*************  Exception Details *****************" << std::endl;
	std::cerr << "Invalid Argument Exception: " << this->m_sMsg.c_str() << std::endl;
	std::cerr << "Faulty argument value: " << this->m_TInvArg << std::endl;
	std::cerr << "At line of code: " << this->m_iLOC << std::endl;
	std::cerr << "At function address: " << std::hex << this->m_sFuncAddress.c_str() << std::endl;
	std::cerr << "At date: " << __DATE__ << " at time: " << __TIME__ << std::endl;
	std::cerr << "*************************************************" << std::endl;
}

/*******************************************************************
    Class Wrf_out_boundary_except implementation
********************************************************************/

template<typename T> wrf_physics::utils_exceptions::Wrf_out_boundary_except<T>::Wrf_out_boundary_except() {}

 template<typename T> template<typename T2> //= typename std::enable_if<std::is_integral<T>::value>::type>
wrf_physics::utils_exceptions::Wrf_out_boundary_except<T>::Wrf_out_boundary_except(
	_In_ const WRF_STRING& Msg, 
	_In_ const T OutBound,
	_In_ const WRF_INT LOC,
	_In_ const WRF_WSTRING& FuncAddress) :
	m_sMsg{ Msg },
	m_tOutBound{ OutBound },
	m_iLOC{ LOC },
	m_sFuncAddress{FuncAddress}
{

}

template<typename T> wrf_physics::utils_exceptions::Wrf_out_boundary_except<T>::
Wrf_out_boundary_except(
	_In_ const Wrf_out_boundary_except &rhs) :
	m_sMsg{ rhs.m_sMsg },
	m_tOutBound{ rhs.m_tOutBound },
	m_iLOC{ rhs.m_iLOC },
	m_sFuncAddress{rhs.m_sFuncAddress}
{

}

template<typename T> wrf_physics::utils_exceptions::Wrf_out_boundary_except<T>::
Wrf_out_boundary_except(
	_In_ Wrf_out_boundary_except &&rhs) :
	m_sMsg{ std::move(rhs.m_sMsg) },
	m_tOutBound{ std::move(rhs.m_tOutBound) },
	m_iLOC{ std::move(rhs.m_iLOC) },
	m_sFuncAddress{ std::move(rhs.m_sFuncAddress) }
{

}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_out_boundary_except<T>::
getMsg()const->WRF_STRING {
	
	return (this->m_sMsg);
}

template<typename T>  auto wrf_physics::utils_exceptions::Wrf_out_boundary_except<T>::
getOutBound()const->T {

	return (this->m_tOutBound);
}

template<typename T>  auto wrf_physics::utils_exceptions::Wrf_out_boundary_except<T>::
getLOC()const->WRF_INT {

	return (this->m_iLOC);
}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_out_boundary_except<T>::
getFuncAddress()const->WRF_WSTRING {

	return (this->m_sFuncAddress);
}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_out_boundary_except<T>::
description()const->void {

	std::cerr << "************  Exception Details   ***********" << std::endl;
	std::cerr << "Out of Boundary exception: " << this->m_sMsg.c_str() << std::endl;
	std::cerr << "Faulting argument's value: " << this->m_tOutBound << std::endl;
	std::cerr << "At line of code: " << this->m_iLOC << std::endl;
	std::cerr << "At function address: " << std::hex << this->m_sFuncAddress.c_str() << std::endl;
	std::cerr << "At date: " << __DATE__ << " at time: " << __TIME__ << std::endl;
	std::cerr << "*********************************************" << std::endl;
}

/************************************************************************
           Class Wrf_math_divergence_except - implementation
*************************************************************************/

template<typename T>  wrf_physics::utils_exceptions::Wrf_math_divergence_except<T>::
Wrf_math_divergence_except() {}

template<typename T>  wrf_physics::utils_exceptions::Wrf_math_divergence_except<T>::
Wrf_math_divergence_except(_In_ const WRF_STRING &Msg, 
                           _In_ const T DivergVal,
						   _In_ const WRF_INT LOC,
						   _In_ const WRF_WSTRING & FuncAddress) :
  m_sMsg{ Msg },
  m_tDivergVal{ DivergVal },
  m_iLOC{ LOC },
  m_sFuncAddress{FuncAddress}
{

}

template<typename T>  wrf_physics::utils_exceptions::Wrf_math_divergence_except<T>::
Wrf_math_divergence_except(_In_ const Wrf_math_divergence_except &rhs) :
  m_sMsg{ rhs.m_sMsg },
  m_tDivergVal{ rhs.m_tDivergVal },
  m_iLOC{ rhs.m_iLOC },
  m_sFuncAddress{rhs.m_sFuncAddress}
{

}

template<typename T>  wrf_physics::utils_exceptions::Wrf_math_divergence_except<T>::
Wrf_math_divergence_except(_In_ Wrf_math_divergence_except &&rhs) :
  m_sMsg{ std::move(rhs.m_sMsg) },
  m_tDivergVal{ std::move(rhs.m_tDivergVal) },
  m_iLOC{ std::move(rhs.m_iLOC) },
  m_sFuncAddress{ std::move(rhs.m_sFuncAddress) }
{

}

template<typename T>  auto  wrf_physics::utils_exceptions::Wrf_math_divergence_except<T>::
getMsg()const->WRF_STRING {

	return (this->m_sMsg);
}

template<typename T>  auto  wrf_physics::utils_exceptions::Wrf_math_divergence_except<T>::
getDivergVal()const->T {

	return (this->m_tDivergVal);
}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_math_divergence_except<T>::
getLOC()const->int {
	
	return (this->m_iLOC);
}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_math_divergence_except<T>::
getFuncAddress()const->WRF_WSTRING {

	return (this->m_sFuncAddress);
}

template<typename T>  auto  wrf_physics::utils_exceptions::Wrf_math_divergence_except<T>::
description()const->void {

	std::cerr << "*************** Exception Details ***************" << std::endl;
	std::cerr << "Value Divergence Exception: " << this->m_sMsg.c_str() << std::endl;
	std::cerr << "Faulty value: " << this->m_tDivergVal << std::endl;
	std::cerr << "At line of code: " << this->m_iLOC << std::endl;
	std::cerr << "At function address: " << std::hex << this->m_sFuncAddress.c_str() << std::endl;
	std::cerr << "At date: " << __DATE__ << " at time: " << __TIME__ << std::endl;
	std::cerr << "**************************************************" << std::endl;
}

/***********************************************************************
         Class Wrf_null_pointer_except - implementation.
************************************************************************/
template<typename T>  wrf_physics::utils_exceptions::Wrf_null_pointer_except<T>::
Wrf_null_pointer_except() {}

template<typename T>  wrf_physics::utils_exceptions::Wrf_null_pointer_except<T>::
Wrf_null_pointer_except(_In_ const WRF_STRING &Msg, 
                        _In_ const T NullPtrVal,
						_In_ const WRF_INT LOC,
						_In_ const WRF_WSTRING &FuncAddress) :
  m_sMsg{ Msg },
  m_tNullPtrVal{ NullPtrVal },
  m_iLOC{ LOC },
  m_sFuncAddress{FuncAddress}
{

}

template<typename T>  wrf_physics::utils_exceptions::Wrf_null_pointer_except<T>::
Wrf_null_pointer_except(_In_ const Wrf_null_pointer_except &rhs) :
  m_sMsg{ rhs.m_sMsg },
  m_tNullPtrVal{ rhs.m_tNullPtrVal },
  m_iLOC{ LOC },
  m_sFuncAddress{rhs.m_sFuncAddress}
{

}

template<typename T>  wrf_physics::utils_exceptions::Wrf_null_pointer_except<T>::
Wrf_null_pointer_except(_In_ Wrf_null_pointer_except &&rhs) :
  m_sMsg{ std::move(rhs.m_sMsg) },
  m_tNullPtrVal{ std::move(rhs.m_tNullPtrVal) },
  m_iLOC{ std::move(rhs.m_iLOC) },
  m_sFuncAddress{ std::move(rhs.m_sFuncAddress) }
{

}

template<typename T>  auto   wrf_physics::utils_exceptions::Wrf_null_pointer_except<T>::
getMsg()const->WRF_STRING {

	return (this->m_sMsg);
}

template<typename T>  auto   wrf_physics::utils_exceptions::Wrf_null_pointer_except<T>::
getNullPtrVal()const->T {

	return (this->m_tNullPtrVal);
}

template<typename T> auto    wrf_physics::utils_exceptions::Wrf_null_pointer_except<T>::
getLOC()const->WRF_INT {

	return (this->m_iLOC);
}

template<typename T> auto    wrf_physics::utils_exceptions::Wrf_null_pointer_except<T>::
getFuncAddress()const->WRF_WSTRING {

	return (this->m_sFuncAddress)
}

template<typename T>  auto   wrf_physics::utils_exceptions::Wrf_null_pointer_except<T>::
description()const->void {

	std::cerr << "************** Exception Details ***************" << std::endl;
	std::cerr << "Null Pointer Exception: " << this->m_sMsg.c_str() << std::endl;
	std::cerr << "Faulting pointer value: " << this->m_tNullPtrVal << std::endl;
	std::cerr << "At line of code: " << this->m_iLOC << std::endl;
	std::cerr << "At function address: " << std::hex << this->m_sFuncAddress.c_str() << std::endl;
	std::cerr << "At date: " << __DATE__ << " at time: " << __TIME__ << std::endl;
	std::cerr << "************************************************" << std::endl;
}


template<typename T> wrf_physics::utils_exceptions::Wrf_math_error_except<T>::
Wrf_math_error_except() {}


template<typename T> wrf_physics::utils_exceptions::Wrf_math_error_except<T>::
Wrf_math_error_except(_In_ const WRF_STRING &Msg, 
                      _In_ const T MathErr,
					  _In_ const WRF_INT LOC,
					  _In_ const WRF_WSTRING &FuncAddress) :
  m_sMsg{ Msg },
  m_tMathErr{ MathErr },
  m_iLOC{ LOC },
  m_sFuncAddress{FuncAddress}
{

}

template<typename T> wrf_physics::utils_exceptions::Wrf_math_error_except<T>::
Wrf_math_error_except(_In_ const Wrf_math_error_except &rhs) :
  m_sMsg{ rhs.m_sMsg },
  m_tMathErr{ rhs.m_tMathErr },
  m_iLOC{ rhs.m_iLOC },
  m_sFuncAddress{rhs.m_sFuncAddress}
{

}

template<typename T> wrf_physics::utils_exceptions::Wrf_math_error_except<T>::
Wrf_math_error_except(_In_ Wrf_math_error_except &&rhs) :
  m_sMsg{ std::move(rhs.m_sMsg) },
  m_tMathErr{ std::move(rhs.m_tMathErr) },
  m_iLOC{ std::move(rhs.m_iLOC) },
  m_sFuncAddress{ std::move(rhs.m_sFuncAddress) }
{

}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_math_error_except<T>::
getMsg()const->WRF_STRING {

	return (this->m_sMsg);
}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_math_error_except<T>::
getMathErr()const->T {

	return (this->m_tMathErr);
}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_math_error_except<T>::
getLOC()const->WRF_INT {

	return (this->m_iLOC);
}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_math_error_except<T>::
getFuncAddress()const->WRF_WSTRING {

	return (this->m_sFuncAddress);
}

template<typename T>  auto wrf_physics::utils_exceptions::Wrf_math_error_except<T>::
description()const->void {

	std::cerr << "************** Exception Details ****************" << std::endl;
	std::cerr << "Math Error Exception: " << this->m_sMsg.c_str() << std::endl;
	std::cerr << "Fault variable: " << this->m_tMathErr << std::endl;
	std::cerr << "At line of code: " << this->m_iLOC << std::endl;
	std::cerr << "At function address: " << std::hex << this->m_sFuncAddress.c_str() << std::endl;
	std::cerr << "At date: " << __DATE__ << " at time: " << __TIME__ << std::endl;
	std::cerr << "**************************************************" << std::endl;
}


template<typename T > wrf_physics::utils_exceptions::Wrf_unaligned16_except<T>::
Wrf_unaligned16_except() {}

template<typename T > wrf_physics::utils_exceptions::Wrf_unaligned16_except<T>::
Wrf_unaligned16_except(_In_ const WRF_STRING & Msg,
                       _In_ const T UnalignVal,
                       _In_ const WRF_INT LOC,
                       _In_ const WRF_WSTRING & FuncAddress) :
    m_sMsg{ Msg },
    m_pUnalignVal{ UnalignVal },
    m_iLOC{ LOC },
    m_sFuncAddress{ FuncAddress }
{

}

template<typename T > wrf_physics::utils_exceptions::Wrf_unaligned16_except<T>::
Wrf_unaligned16_except(_In_ const Wrf_unaligned16_except &rhs) :
   m_sMsg{ rhs.m_sMsg },
   m_pUnalignVal{ rhs.m_pUnalignVal },
   m_iLOC{ rhs.m_iLOC },
   m_sFuncAddress{ rhs.m_sFuncAddress }
{

}

template<typename T > wrf_physics::utils_exceptions::Wrf_unaligned16_except<T>::
Wrf_unaligned16_except(_In_ Wrf_unaligned16_except &&rhs) :
   m_sMsg{ std::move(rhs.m_sMsg) },
   m_pUnalignVal{ std::move(rhs.m_pUnalignVal) },
   m_iLOC{ std::move(rhs.m_iLOC) },
   m_sFuncAddress{ std::move(rhs.m_sFuncAddress) }
{

}

template<typename T> auto wrf_physics::utils_exceptions::Wrf_unaligned16_except<T>::
getMsg()const->WRF_STRING {

	return (this->m_sMsg);
}

template<typename T > auto wrf_physics::utils_exceptions::Wrf_unaligned16_except<T>::
getUnalignVal()const->T {

	return (this->m_pUnalignVal);
}

template<typename T > auto wrf_physics::utils_exceptions::Wrf_unaligned16_except<T>::
getLOC()const->WRF_INT {

	return (this->m_iLOC);
}

template<typename T > auto wrf_physics::utils_exceptions::Wrf_unaligned16_except<T>::
getFuncAddress()const->WRF_WSTRING {

	return (this->m_sFuncAddress);
}

template<typename T > auto wrf_physics::utils_exceptions::Wrf_unaligned16_except<T>::
description()const->void {

	std::cerr << "************** Exception Details ****************" << std::endl;
	std::cerr << "Unaligned 16-bytes Access Exception: " << this->m_sMsg << std::endl;
	std::cerr << "Faulty variable: " << std::hex << this->m_pUnalignVal << std::endl;
	std::cerr << "At line of code: " << this->m_iLOC << std::endl;
	std::cerr << "At function address: " << std::hex << this->m_sFuncAddress.c_str() << std::endl;
	std::cerr << "At date: " << __DATE__ << "at time: " << __TIME__ << std::endl;
	std::cerr << "*************************************************" << std::endl;
}

template<typename T > wrf_physics::utils_exceptions::Wrf_unaligned32_except<T>::
Wrf_unaligned32_except() {}

template<typename T > wrf_physics::utils_exceptions::Wrf_unaligned32_except<T>::
Wrf_unaligned32_except(_In_ const WRF_STRING &Msg,
                       _In_ const T UnalignVal,
                       _In_ const WRF_INT LOC,
                       _In_ const WRF_WSTRING &FuncAddress) :
       m_sMsg{ Msg },
       m_pUnalignVal{ UnalignVal },
       m_iLOC{ LOC },
       m_sFuncAddress{ FuncAddress }
{

}

template<typename T > wrf_physics::utils_exceptions::Wrf_unaligned32_except<T>::
Wrf_unaligned32_except(_In_ const Wrf_unaligned32_except &rhs) :
    m_sMsg{ rhs.m_sMsg },
    m_pUnalignVal{ rhs.m_pUnalignVal },
    m_iLOC{ rhs.m_iLOC },
    m_sFuncAddress{ rhs.m_sFuncAddress }
{

}

template<typename T > wrf_physics::utils_exceptions::Wrf_unaligned32_except<T>::
Wrf_unaligned32_except(_In_ Wrf_unaligned32_except &&rhs) :
    m_sMsg{ std::move(rhs.m_sMsg) },
    m_pUnalignVal{ std::move(rhs.m_pUnalignVal) },
    m_iLOC{ std::move(rhs.m_iLOC) },
    m_sFuncAddress{ std::move(rhs.m_sFuncAddress) }
{

}

template<typename T > auto wrf_physics::utils_exceptions::Wrf_unaligned32_except<T>::
getMsg()const->WRF_STRING {

	return (this->m_sMsg);
}

template<typename T > auto wrf_physics::utils_exceptions::Wrf_unaligned32_except<T>::
getUnalignVal()const->T {

	return (this->m_pUnalignVal);
}

template<typename T > auto wrf_physics::utils_exceptions::Wrf_unaligned32_except<T>::
getLOC()const->WRF_INT {

	return (this->m_iLOC);
}

template<typename T > auto wrf_physics::utils_exceptions::Wrf_unaligned32_except<T>::
getFuncAddress()const->WRF_WSTRING {

	return (this->m_sFuncAddress);
}

template<typename T > auto wrf_physics::utils_exceptions::Wrf_unaligned32_except<T>::
description()const->void {

	std::cerr << "************** Exception Details ****************" << std::endl;
	std::cerr << "Unaligned 32-bytes Access Exception: " << this->m_sMsg << std::endl;
	std::cerr << "Faulty variable: " << this->m_pUnalignVal << std::endl;
	std::cerr << "At line of code: " << this->m_iLOC << std::endl;
	std::cerr << "At function address: " << std::hex << this->m_sFuncAddress.c_str() << std::endl;
	std::cerr << "At date: " << __DATE__ << "at time: " << __TIME__ << std::endl;
	std::cerr << "*************************************************" << std::endl;
}
