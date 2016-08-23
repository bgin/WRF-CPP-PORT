
/***************************************************
           Implementation of class Psacw
****************************************************/

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > wrf_physics::wrf_models_wsm::wrf_wsm_iface::
		                                             Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                                                         wrf_physics::wrf_physics_internal::tags::
															                             dyn_container_boost_t_tag, ims, ime, jms, jme>::Psacw() :

		 m_psacw{ boost::extents[ime][jme] } {


			 for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
#ifdef LOOP_UNROLL_2X
				 for (WRF_ULONGLONG j{ jms }; j != jme; j += 16) {
					 _mm256_storeu_ps(&this->m_psacw[i][j], _mm256_setzero_ps());
					 _mm256_storeu_ps(&this->m_psacw[i][j+8], _mm256_setzero_ps());
				 }
#else
				 for (WRF_ULONGLONG j{ jms }; j != jme; j += 8) {
					 _mm256_storeu_ps(&this->m_psacw[i][j], _mm256_setzero_ps());
				 }
#endif

			 }

		 }


template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::Psacw(_In_ WRF_CPP_CONST Psacw &other) :

		 m_psacw{ other.m_psacw } {}


template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::Psacw(_In_ Psacw &&other) :

		 m_psacw{ std::move(other.m_psacw) } {}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator=(_In_ WRF_CPP_CONST Psacw& other)->Psacw & {

													if (this == &other) return (*this);
#if VECTORIZE_COPY_OPERATOR == 0x1
													for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
														for(WRF_ULONGLONG j{jms}; j != jme; j += 16) {

															_mm256_storeu_ps(&this->m_psacw[i][j], _mm256_loadu_ps(&other.m_psacw[i][j]));
															_mm256_storeu_ps(&this->m_psacw[i][j + 8], _mm256_loadu_ps(&other.m_psacw[i][j + 8]));
														}
													}
#else
			                                                  this->m_psacw.operator=(other.m_psacw);
#endif
			
			 return (*this);
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator=(_In_ Psacw&& other)->Psacw & {

			 if (this == &other) return (*this);


			this->m_psacw.operator=(std::move(other.m_psacw));
			 return (*this);
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator==(_In_ WRF_CPP_CONST Psacw& other)->WRF_CPP_CONST WRF_BOOL {

			 using namespace wrf_physics::utils_exceptions;
			 if (this->num_of_elements() != other.num_of_elements())
				 throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Array's size mismatch!!"), other.num_of_elements(), (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

			 return (this->m_psacw.operator==(other.m_psacw));
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator!=(_In_ WRF_CPP_CONST Psacw& other)->WRF_CPP_CONST WRF_BOOL {

			 using namespace wrf_physics::utils_exceptions;
			 if (this->num_of_elements() != other.num_of_elements())
				 throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Array's size mismatch!!"), other.num_of_elements(), (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

			 return (this->m_psacw.operator!=(other.m_psacw));

		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator()(_In_ WRF_CPP_CONST WRF_ULONGLONG index_i,
		                                                                                                     _In_ WRF_CPP_CONST WRF_ULONGLONG index_k)WRF_CPP_CONST->WRF_CPP_CONST WRF_REAL32{

	     using namespace wrf_physics::utils_exceptions;
	     if (index_i > ime || index_k > kme)
		     throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid argument size!!"), index_i, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

	       return (this->m_psacw[index_i][index_k]);
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator()(_In_ WRF_CPP_CONST WRF_ULONGLONG index_i,
		                                                                                                     _In_ WRF_CPP_CONST WRF_ULONGLONG index_k)->WRF_REAL32 {

			 using namespace wrf_physics::utils_exceptions;
			 if (index_i > ime || index_k > kme)
				 throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid argument size!!"), index_i, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

			 return (this->m_psacw[index_i][index_k]);
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                             wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator+=(_In_ WRF_CPP_CONST Psacw &other)->Psacw & {

#ifdef DISABLE_HW_PREFETCH
#pragma noprefetch
#endif
			 for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
				 for (WRF_ULONGLONG j{ jms }; j != jme; j += 8) {
					 _mm_prefetch(reinterpret_cast<const char*>(&other.m_psacw[i][j + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
					 _mm_prefetch(reinterpret_cast<const char*>(&other.m_psacw[i][j + 8]), _MM_HINT_T1);
#endif
					 _mm256_storeu_ps(&this->m_psacw[i][j], _mm256_add_ps(_mm256_loadu_ps(&this->m_psacw[i][j]),
						                                    _mm256_loadu_ps(&other.m_psacw[i][j])));
				 }
			 }
			 return (*this);
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator-=(_In_ WRF_CPP_CONST Psacw &other)->Psacw & {

#ifdef DISABLE_HW_PREFETCH
#pragma noprefetch
#endif
			 for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
				 for (WRF_ULONGLONG j{ jms }; j != jme; j += 8) {
					 _mm_prefetch(reinterpret_cast<const char*>(&other.m_psacw[i][j + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
					 _mm_prefetch(reinterpret_cast<const char*>(&other.m_psacw[i][j + 8]), _MM_HINT_T1);
#endif
					 _mm256_storeu_ps(&this->m_psacw[i][j], _mm256_sub_ps(_mm256_loadu_ps(&this->m_psacw[i][j]),
						                                    _mm256_loadu_ps(&other.m_psacw[i][j])));
				 }
			 }
			 return (*this);
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto  wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                         wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::class_typeId()WRF_CPP_CONST->WRF_STRING{

	return (WRF_STRING(typeid(*this).name()));
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto  wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::class_info()WRF_CPP_CONST->std::tuple<WRF_STRING, WRF_ULONGLONG, WRF_STRING>{

	return (std::make_tuple(typeid(*this).name(), typeid(*this).hash_code(), typeid(*this).raw_name()));
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::class_tags()WRF_CPP_CONST->std::pair<WRF_STRING, WRF_STRING>{

	return (std::make_pair(WRF_STRING{ "float32_t_tag" }, WRF_STRING{ "dyn_container_boost_t_tag" }));
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::toCPtr()->WRF_SHPTRF32 {

			 const WRF_ULONGLONG size{ this->num_of_elements() };
			 WRF_REAL32 * ptr = nullptr;
			 try {

				 ptr = new WRF_REAL32[size];
			 }
			 catch (std::bad_alloc &ba) {
				    // Temporary solution till
				    // Wrf_error will be implemented
				 std::cerr << " Fatal error: Failed to allocate memory: " << ba.what() << std::endl;
				 std::cerr << " Value of ptr=" << std::hex << *ptr << std::endl;
				 std::cerr << " Time stamp: " << __TIME__ << std::endl;
				 std::cerr << " Date:" << __DATE__ << std::endl;
				 std::cerr << " Code point(loc): " << __LINE__ << std::endl;
				 std::cerr << " Call site: " << std::hex << __FUNCTIONW__ << std::endl;
				 std::cerr << " Deallocating resources and exiting!!" << std::endl;
				 delete[]ptr;
				 std::exit(EXIT_FAILURE);
			 }
			 for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
				 for (WRF_ULONGLONG j{ jms }; j != jme; j += 8) {
					 _mm256_storeu_ps(&ptr[i + size * j], _mm256_loadu_ps(&this->m_psacw[i][j]));
				 }
			 }
			 WRF_SHPTRF32 smart_ptr(ptr, [](WRF_REAL32* ptr)->void { delete[]ptr; });
			 
			 return (smart_ptr);
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::num_of_elements()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	     return (static_cast<WRF_ULONGLONG>(this->m_psacw.num_elements()));
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::num_of_dimensions()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	     return (static_cast<WRF_ULONGLONG>(this->m_psacw.num_dimensions());
}

#ifdef DEBUG_VERBOSE

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
	     WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
	                                       wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::print_object_state()WRF_CPP_CONST->void{

	std::cout << "Dump of object of type: " << this->class_typeId().c_str() << std::endl;
	std::cout << " Class name: " << std::get<0>(this->class_info()).c_str() << std::endl;
	std::cout << " Class hash name: " << std::get<1>(this->class_info()) << std::endl;
	std::cout << " Class raw name:  " << std::get<2>(this->class_info()).c_str() << std::endl;
	std::cout << "Time stamp: " << __TIME__ << std::endl;
	std::cout << " Date: " << __DATE__ << std::endl;
	std::cout << "************** Internal context ***************" << std::endl;
	std::cout << " this at address: " << std::hex << this << std::endl;
	std::cout << " member of type: " << typeid(this->m_psacw).name() <<
		         " at address: " << std::hex << &this->m_psacw << std::endl;
	std::cout << " Stored values: " << std::endl;
	std::cout << *this << std::endl;
	std::cout << "************** End  of  context ***************" << std::endl;
	std::cout << " End of dump " << std::endl;
}
#endif

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::convert_to_mks(_In_ KMSProdRatioF32 &prod_ratio)WRF_CPP_CONST->void{

	using namespace wrf_physics::utils_exceptions;
	if (this->num_of_elements() != prod_ratio.num_elements())
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid argument size!!"), prod_ratio.num_elements(), (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

	for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
		for (WRF_ULONGLONG j{ jms }; j != jme; ++j) {

			prod_ratio[i][j] = boost::units::quantity<boost::units::si::mass, WRF_REAL32>(
				this->m_psacw[i][j] * boost::units::si::kilograms);
		}

	}

}

/******************************************************************
              Implementatio  of double specialization
********************************************************************/

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                   wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::Psacw() :

										   m_psacw{ boost::extents[ime][jme] } {

											   for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
#ifdef LOOP_UNROLL_2X 
												   for (WRF_ULONGLONG j{ jms }; j != jme; j += 16) {

													   _mm256_storeu_pd(&this->m_psacw[i][j], _mm256_setzero_pd());
													   _mm256_storeu_pd(&this->m_psacw[i][j + 8], _mm256_setzero_pd());
												   }
#else
												   for (WRF_ULONGLONG j{ jms }; j != jme; j += 8) {
													   _mm256_storeu_pd(&this->m_psacw[i][j], _mm256_setzero_pd());
												   }
#endif
											   }
#ifdef DEBUG_VERBOSE
											   debug_print(WRF_STRING("Psacw::Psacw{}"), __LINE__, WRF_WSTRING(__FUNCTIONW__));
#endif
		 }


template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                   wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::Psacw(_In_ WRF_CPP_CONST Psacw &other) :

		 m_psacw{ other.m_psacw } {

#ifdef DEBUG_VERBOSE
											   debug_print(WRF_STRING("Psacw::Psacw{const Psacw &}"), __LINE__, WRF_WSTRING(__FUNCTIONW__));
#endif
   }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                   wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::Psacw(_In_  Psacw &&other) :

		 m_psacw{ std::move(other.m_psacw) } {
#ifdef DEBUG_VERBOSE
											   debug_print(WRF_STRING("Psacw::Psacw{Psacw &&}"), __LINE__, WRF_WSTRING(__FUNCTIONW__));
#endif
  }


template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator=(_In_ WRF_CPP_CONST Psacw &other)->Psacw & {
                      
													if (this == &other) return (*this);

#if VECTORIZE_COPY_OPERATOR == 0x1
													for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
														for (WRF_ULONGLONG j{ jms }; j != jme; j += 16) {

															_mm256_storeu_pd(&this->m_psacw[i][j], _mm256_loadu_ps(&other.m_psacw[i][j]));
															_mm256_storeu_pd(&this->m_psacw[i][j + 8], _mm256_loadu_pd(&other.m_psacw[i][j + 8]));
														}

													}
#else
													this->m_psacw.operator=(other.m_psacw);
#endif
#ifdef DEBUG_VERBOSE
													debug_print(WRF_STRING("Psacw::operator="), __LINE__ , WRF_WSTRING(__FUNCTIONW__));
#endif
													return (*this);
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator=(_In_ Psacw &&other)->Psacw & {

													if (this == &other) return (*this);

													*this = std::move(other);
#ifdef DEBUG_VERBOSE
													debug_print(WRF_STRING("Psacw::operator=(&&)"), __LINE__, WRF_WSTRING(__FUNCTIONW__));
#endif
													return (*this);
		 }


template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator==(_In_ WRF_CPP_CONST Psacw &other)WRF_CPP_CONST->WRF_BOOL {

	using namespace wrf_physics::utils_exceptions;
	if (this->num_of_elements() != other.num_of_elements())
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Array mismatch size!!"), other.num_of_elements(), (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

	return (this->m_psacw.operator==(other.m_psacw));
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator!=(_In_ WRF_CPP_CONST Psacw &other)WRF_CPP_CONST->WRF_BOOL{
	                                   
	using namespace wrf_physics::utils_exceptions;
	if (this->num_of_elements() != other.num_of_elements())
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Array mismatch size!!"), other.num_of_elements(), (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

	return (this->m_psacw.operator!=(other.m_psacw));
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator()(_In_ WRF_CPP_CONST WRF_ULONGLONG index_i,
		                                                                                                                                            _In_ WRF_CPP_CONST WRF_ULONGLONG index_j)WRF_CPP_CONST->WRF_CPP_CONST WRF_REAL64 {
	using namespace wrf_physics::utils_exceptions;
	if (index_i > ime || index_j > jme)
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid argument size!!"), index_i, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

	return (this->m_psacw[index_i][index_j]);
	   
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator()(_In_ WRF_CPP_CONST WRF_ULONGLONG index_i,
		                                                                                                                                            _In_ WRF_CPP_CONST WRF_ULONGLONG index_j)->WRF_REAL64 {
           
	using namespace wrf_physics::utils_exceptions;
	if (index_i > ime || index_j > jme)
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid argument size!!"), index_i, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

	return (this->m_psacw[index_i][index_j]);
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator+=(_In_ WRF_CPP_CONST Psacw &other)->Psacw & {

#ifdef DISABLE_HW_PREFETCH
#pragma noprefetch
#endif
			 for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
				 for (WRF_ULONGLONG j{ jms }; j != jme; j += 8) {
					 _mm_prefetch(reinterpret_cast<const char*>(&other.m_psacw[i][j + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_DOUBLE > MAX_L1_SIZE_DOUBLE
					 _mm_prefetch(reinterpret_cast<const char*>(&other.m_psacw[i][j + 8]), _MM_HINT_T1);
#endif
					 _mm256_storeu_pd(&this->m_psacw[i][j], _mm256_add_pd(_mm256_loadu_pd(&this->m_psacw[i][j]),
						                                    _mm256_loadu_pd(&other.m_psacw[i][j])));
				 }
			 }
			 return (*this);
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator-=(_In_ WRF_CPP_CONST Psacw &other)->Psacw & {

#ifdef DISABLE_HW_PREFETCH
#pragma noprefetch
#endif
			 for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
				 for (WRF_ULONGLONG j{ jms }; j != jme; j += 8) {
					 _mm_prefetch(reinterpret_cast<const char*>(&other.m_psacw[i][j + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_DOUBLE > MAX_L1_SIZE_DOUBLE
					 _mm_prefetch(reinterpret_cast<const char*>(&other.m_psacw[i][j + 2]), _MM_HINT_T0);
#endif
					 _mm256_storeu_pd(&this->m_psacw[i][j], _mm256_sub_pd(_mm256_loadu_pd(&this->m_psacw[i][j]),
						                                                  _mm256_loadu_pd(&other.m_psacw[i][j])));
				 }
			 }
			 return (*this);
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::class_typeId()WRF_CPP_CONST->WRF_STRING{

	
	return (WRF_STRING(typeid(*this).name()));
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::class_info()WRF_CPP_CONST->std::tuple<WRF_STRING, WRF_ULONGLONG, WRF_STRING>{

	return (std::make_tuple(typeid(*this).name(), typeid(*this).hash_code(), typeid(*this).raw_name()));
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto  wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::class_tags()WRF_CPP_CONST->std::pair<WRF_STRING, WRF_STRING>{

	return (std::make_pair(WRF_STRING{ "float64_t_tag" }, WRF_STRING{ " dyn_container_boost_t_tag" }));
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::toCPtr()->WRF_SHPTRF64 {

			 const auto size = this->num_of_elements();
			 WRF_REAL64* ptrPsacw = nullptr;
			 try{

				 ptrPsacw = new WRF_REAL64[size];
			 }
			 catch (std::bad_alloc &ba) {
				 std::cerr << " Fatal error: Failed to allocate memory: " << ba.what() << std::endl;
				 std::cerr << " Value of ptr=" << std::hex << *ptrPsacw << std::endl;
				 std::cerr << " Time stamp: " << __TIME__ << std::endl;
				 std::cerr << " Date:" << __DATE__ << std::endl;
				 std::cerr << " Code point(loc): " << __LINE__ << std::endl;
				 std::cerr << " Call site: " << std::hex << __FUNCTIONW__ << std::endl;
				 std::cerr << " Deallocating resources and exiting!!" << std::endl;
				 delete[]ptrPsacw;
				 std::exit(EXIT_FAILURE);
			 }
			 for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
				 for (WRF_ULONGLONG j{ jms }; j != jme; j += 8) {
					 _mm256_storeu_pd(&ptrPsacw[i + size * j], _mm256_loadu_pd(&this->m_psacw[i][j]));
				 }
			 }
			 WRF_SHPTRF64 smart_ptr(ptrPsacw, [](WRF_REAL64* ptr)->void{ delete[]ptr; });
			 return (smart_ptr);
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::num_of_elements()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_psacw.num_elements());
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::num_of_dimensions()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_psacw.num_dimensions());
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::print_object_state()WRF_CPP_CONST->void{

	std::cout << "Dump of object of type: " << this->class_typeId().c_str() << std::endl;
	std::cout << " Class name: " << std::get<0>(this->class_info()).c_str() << std::endl;
	std::cout << " Class hash name: " << std::get<1>(this->class_info()) << std::endl;
	std::cout << " Class raw name:  " << std::get<2>(this->class_info()).c_str() << std::endl;
	std::cout << "Time stamp: " << __TIME__ << std::endl;
	std::cout << " Date: " << __DATE__ << std::endl;
	std::cout << "************** Internal context ***************" << std::endl;
	std::cout << " this at address: " << std::hex << this << std::endl;
	std::cout << " member of type: " << typeid(this->m_psacw).name() <<
		" at address: " << std::hex << &this->m_psacw << std::endl;
	std::cout << " Stored values: " << std::endl;
	std::cout << *this << std::endl;
	std::cout << "************** End  of  context ***************" << std::endl;
	std::cout << " End of dump " << std::endl;
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::convert_to_mks(_Inout_ KMSProdRatioF64 &prod_ratio)WRF_CPP_CONST->void{

	using namespace wrf_physics::utils_exceptions;
	if (this->num_of_elements() != prod_ratio.num_elements())
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid argument size!!"), prod_ratio.num_elements(), (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

	for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
		for (WRF_ULONGLONG j{ jms }; j != jme; ++j) {
			prod_ratio[i][j] = boost::units::quantity<boost::units::si::mass, WRF_REAL64>(
				this->m_psacw[i][j] * boost::units::si::kilogram);
		}
	}
}


#ifdef DEBUG_VERBOSE
template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::debug_print(_In_ WRF_CPP_CONST WRF_STRING &msg,
		                                                                                                                                             _In_ WRF_CPP_CONST WRF_INT line,
		                                                                                                                                             _In_ WRF_CPP_CONST WRF_WSTRING &func_address)WRF_CPP_CONST->void {
	std::cerr << "********* debug_print was called ************" << std::endl;
	std::cerr << "Current timestamp: " << __TIME__ << std::endl;
	std::cerr << "Current date: " << __DATE__ << std::endl;
	std::cerr << "Executing in: " << msg.c_str() << std::endl;
	std::cerr << " At line of code: " << line << std::endl;
	std::cerr << " At virtual address: " << std::hex << func_address.c_str() << std::endl;
}

#endif

/**************************************************************
           Implementation of class Pigen
***************************************************************/

/**************************************************************
                Float specialization
**************************************************************/

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > wrf_physics::wrf_models_wsm::wrf_wsm_iface::Pigen<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                   wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::Pigen() :

										   m_pigen{ boost::extents[ime][jme] } {

											   for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
#ifdef LOOP_UNROLL_2X
												   for (WRF_ULONGLONG j{ jms }; j != jme; j += 16) {

													   _mm256_storeu_ps(&this->m_pigen[i][j], _mm256_setzero_ps());
													   _mm256_storeu_ps(&this->m_pigen[i][j + 8], _mm256_setzero_ps());
												   }
#else
												   for (WRF_ULONGLONG j{ jms }; j != jme; j += 8) {
													   _mm256_storeu_ps(&this->m_pigen[i][j], _mm256_setzero_ps());
												   }
#endif
											   }
#ifdef DEBUG_VERBOSE
											   debug_print(WRF_STRING{ "Pigen::Pigen{}" }, __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > wrf_physics::wrf_models_wsm::wrf_wsm_iface::Pigen<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                   wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::Pigen(_In_ WRF_CPP_CONST Pigen &other) :

										   m_pigen{ other.m_pigen } {
#ifdef DEBUG_VERBOSE
											   debug_print(WRF_STRING{ "Pigen::Pigen{Pigen &}" }, __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
	 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > wrf_physics::wrf_models_wsm::wrf_wsm_iface::Pigen<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                   wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::Pigen(_In_  Pigen &&other) :

										   m_pigen{ std::move(other.m_pigen) } {
#ifdef DEBUG_VERBOSE
											   debug_print(WRF_STRING{ "Pigen::Pigen{Pigen &&}" }, __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Pigen<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator=(_In_ WRF_CPP_CONST Pigen &other)->Pigen & {

													if (this == &other) return (*this);

#if VECTORIZE_COPY_OPERATOR == 0x1

													for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
														for (WRF_ULONGLONG j{ jms }; j != jme; j += 16) {
															_mm256_storeu_ps(&this->m_pigen[i][j], _mm256_loadu_ps(&other.m_pigen[i][j]));
															_mm256_storeu_ps(&this->m_pigen[i][j + 8], _mm256_loadu_ps(&other.m_pigen[i][j + 8]));
														}
													}
#else
													this->m_pigen.operator=(other.m_pigen);
#endif
#ifdef DEBUG_VERBOSE
													debug_print(WRF_STRING{ "Pigen::operator=(Pigen &)" }, __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
													return (*this);
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto 
		   wrf_physics::wrf_models_wsm::wrf_wsm_iface::
		               Pigen<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                           wrf_physics::wrf_physics_internal::tags::
												          dyn_container_boost_t_tag, ims, ime, jms, jme>::operator=(_In_ Pigen &&other)->Pigen & {
                                           
													if (this == &other) return (*this);

													this->m_pigen.operator=(std::move(other.m_pigen));
#ifdef DEBUG_VERBOSE
													debug_print(WRF_STRING{ "Pigen::operator=(Pigen &&)" }, __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
													return (*this);
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Pigen<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator==(_In_ WRF_CPP_CONST Pigen &other)WRF_CPP_CONST->WRF_CPP_CONST WRF_BOOL{

#if WRF_DEBUG_SEVERE == 1
	_ASSERTE(this->num_of_elements() == other.num_of_elements());
#elif WRF_DEBUG_SEVERE == 2
	_ASSERT(this->num_of_elements() == other.num_of_elements());
#else
	using namespace wrf_physics::utils_exceptions;
	if (this->num_of_elements() != other.num_of_elements())
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid array's size!!"), other.num_of_elements(), (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
#endif

	return (this->m_pigen.operator==(other.m_pigen));
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Pigen<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator!=(_In_ WRF_CPP_CONST Pigen &other)WRF_CPP_CONST->WRF_CPP_CONST WRF_BOOL{
#if WRF_DEBUG_SEVERE == 0x1
	_ASSERTE(this->num_of_elements() == other.num_of_elements());
#elif WRF_DEBUG_SEVERE == 0x2
	_ASSERT(this->num_of_elements() == other.num_of_elements());
#else
	using namespace wrf_physics::utils_exceptions;
	if (this->num_of_elements() != other.num_of_elements())
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid array's size!!"), other.num_of_elements(), (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
#endif

	return (this->m_pigen.operator!=(other.m_pigen));
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Pigen<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator()(_In_ WRF_CPP_CONST WRF_ULONGLONG idx_i,
		                                                                                                                                            _In_ WRF_CPP_CONST WRF_ULONGLONG idx_j)WRF_CPP_CONST->WRF_CPP_CONST WRF_REAL32{
#if WRF_DEBUG_SEVERE == 0x1
	_ASSERTE(idx_i <= ime && idx_j <= jme);
#elif WRF_DEBUG_SEVERE == 0x2
	_ASSERT(idx_i <= ime && idx_j <= jme);
#else
	using namespace wrf_physics::utils_exceptions;
	if (idx_i > ime || idx_j > jme)
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid arg's size!!"), idx_i, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
#endif

	return (this->m_pigen[idx_i][idx_j]);
}

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto wrf_physics::wrf_models_wsm::wrf_wsm_iface::Pigen<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                        wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme>::operator()(_In_ WRF_CPP_CONST WRF_ULONGLONG idx_i,
		                                                                                                                                            _In_ WRF_CPP_CONST WRF_ULONGLONG idx_j)->WRF_REAL32 {
#if WRF_DEBUG_SEVERE == 0x1
	_ASSERTE(idx_i <= ime && idx_j <= jme);
#elif WRF_DEBUG_SEVERE == 0x2
	_ASSERT(idx_i <= ime && idx_j <= jme);
#else
   using namespace wrf_physics::utils_exceptions;
   if (idx_i > ime || idx_j > jme)
	   throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid arg's size!!"), idx_i, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
#endif
   return (this->m_pigen[idx_i][idx_j]);

}

	
template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto  operator<<(_In_ std::ostream &os, _In_ WRF_CPP_CONST wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
		                                                    wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme> &rhs)->std::ostream & {
			 
			 std::cout << "Object of type " << typeid(rhs).name() << " state dump!!" << std::endl;
			 std::cout << std::setw(2) << "this->m_psacw: " << std::endl;
			 for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
				 for (WRF_ULONGLONG j{ jms }; j != jme; ++j) {
					 os << std::fixed << std::setprecision(9) <<
						 rhs.operator()(i, j) << std::endl;
				 }
				 os << "-----------------------" << std::endl;
			 }
			 std::cout << " End of state dump " << std::endl;
			 return (os);
		 }

template<WRF_CPP_CONST WRF_ULONGLONG ims,
	     WRF_CPP_CONST WRF_ULONGLONG ime,
	     WRF_CPP_CONST WRF_ULONGLONG jms,
		 WRF_CPP_CONST WRF_ULONGLONG jme > auto operator<<(_In_ std::ostream &os, _In_ WRF_CPP_CONST wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
		 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme> &rhs)->std::ostream & {

			 std::cout << "Object of type " << typeid(rhs).name() << " state dump!!" << std::endl;
			 std::cout << std::setw(2) << "this->m_psacw: " << std::endl;
			 for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
				 for (WRF_ULONGLONG j{ jms }; j != jme; ++j) {
					 os << std::fixed << std::setprecision(9) <<
						 rhs.operator()(i, j) << std::endl;
				 }
				 os << "-----------------------" << std::endl;
			 }
			 std::cout << " End of state dump " << std::endl;
			 return (os);
		 }






