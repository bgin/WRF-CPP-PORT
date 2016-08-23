
/*****************************************
     Implementation of ArraySlice1D
******************************************/

template<typename data_t,
class Container_t> wrf_physics::
	wrf_physics_utils::ArraySlice1D<data_t, Container_t>::
	                     ArraySlice1D(_In_ WRF_CPP_CONST WRF_ULONGLONG x0,
	                                  _In_ WRF_CPP_CONST WRF_ULONGLONG x1) : 

				 m_x0{ x0 },
				 m_x1{ x1 },
				 m_container1D((wrf_physics::wrf_physics_utils::CheckCtorArgs<WRF_ULONGLONG>::check_args(x0, x1), (m_x1 - m_x0))) {

	using namespace wrf_physics::wrf_physics_internal::traits;
	static_assert(std::enable_if<Is_Container_std_vector<data_t, Container_t>::value ||
		Is_Container_std_valarray<data_t, Container_t>::value ||
		Is_Container_boost_multi_array1d<data_t, Container_t>::value, void>, "Invalid ADT type!! ");
	for (WRF_ULONGLONG i{ this->m_x0 }; i != this->m_x1; ++i)
		this->m_container1D[i] = static_cast<data_t>(0);
#ifdef DEBUG_VERBOSE
	wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " 4-arg Ctor: "  }.append(class_typeID().c_str()),
		__LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
}

template<typename data_t,
	     class Container_t> wrf_physics::
			 wrf_physics_utils::ArraySlice1D<data_t,Container_t>::
			 ArraySlice1D(_In_ WRF_CPP_CONST ArraySlice1D &other) :

			 m_x0{ other.m_x0 },
			 m_x1{ other.m_x1 },
			 m_container1D{ other.m_container1D } {
#ifdef DEBUG_VERBOSE
	 wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Copy-Ctor: " }.append(class_typeID().c_str()),
				__LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
			 }

template<typename data_t,
	     class Container_t> wrf_physics::
			 wrf_physics_utils::ArraySlice1D<data_t,Container_t>::
			 ArraySlice1D(_In_ ArraySlice1D &&other) :

			 m_x0{ std::move(other.m_x0) },
			 m_x1{ std::move(other.m_x1) },
			 m_container1D{ other.m_container1D } {
#ifdef DEBUG_VERBOSE
		wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Move-Ctor: " }.append(class_typeID().c_str()),
					 __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
			 }

template<typename data_t,
	     class Container_t> auto wrf_physics::
			 wrf_physics_utils::ArraySlice1D<data_t,Container_t>::
			 operator=(_In_ WRF_CPP_CONST ArraySlice1D &other)->ArraySlice1D & {

				 if (this == &other) return (*this);
				 this->m_x0 = other.m_x0;
				 this->m_x1 = other.m_x1;
				 this->m_container1D = other.m_container1D;
#ifdef DEBUG_VERBOSE
		 wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ "Copy-Assign: " }.append(class_typeID().c_str()),
					 __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
				 return (*this);
			 }

template<typename data_t,
	    class Container_t> auto wrf_physics::
			wrf_physics_utils::ArraySlice1D<data_t,Container_t>::
			operator=(_In_ ArraySlice1D &&other)->ArraySlice1D & {

				if (this == &other) return (*this);
				    *this = std::move(other);
#ifdef DEBUG_VERBOSE
		  wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ "Move-Assign: " }.append(class_typeID().c_str()),
						__LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
				return (*this);

			}

template<typename data_t,
	    class Container_t> auto wrf_physics::
			wrf_physics_utils::ArraySlice1D<data_t, Container_t>::
			          get_x0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

			return (this->m_x0);
		}

template<typename data_t,
	    class Container_t> auto wrf_physics::
			wrf_physics_utils::ArraySlice1D<data_t, Container_t>::
			           get_x1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

			return (this->m_x1);
		}

template<typename data_t,
	     class Container_t> auto wrf_physics::
			 wrf_physics_utils::ArraySlice1D<data_t, Container_t>::
			 class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING{

			 return (WRF_STRING{ typeid(*this).name() });
		 }


		/*********************************************
		    Implementation of ArraySlice2D class
		*********************************************/

template<typename data_t,
	    class Container_t> wrf_physics::
			wrf_physics_utils::ArraySlice2D<data_t,Container_t>::
			ArraySlice2D(_In_ WRF_CPP_CONST Container_t & container,
			_In_ WRF_CPP_CONST WRF_ULONGLONG x0,
			_In_ WRF_CPP_CONST WRF_ULONGLONG x1,
			_In_ WRF_CPP_CONST WRF_ULONGLONG y0,
			_In_ WRF_CPP_CONST WRF_ULONGLONG y1) :

			m_container2D{ container },
			m_x0{ x0 },
			m_x1{ x1 },
			m_y0{ y0 },
			m_y1{ y1 } {

				using namespace wrf_physics::wrf_physics_utils;
				CheckCtorArgs<WRF_ULONGLONG>::check_args(x0, x1, y0, y1);

				for (WRF_ULONGLONG i{ this->m_x0 }; i != this->m_x1; ++i) {
					for (WRF_ULONGLONG j{ this->m_y0 }; j != this->m_y1; ++j) {
						this->m_container2D[i][j] = static_cast<data_t>(0);
					}
				}
#ifdef  DEBUG_VERBOSE
				wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ "4-arg Ctor: " }.append(class_typeID().c_str()),
					__LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
			}

template<typename data_t,
	    class Container_t> wrf_physics::
			wrf_physics_utils::ArraySlice2D<data_t,Container_t>::
			           ArraySlice2D(_In_ WRF_CPP_CONST ArraySlice2D &other) :

			m_container2D{ other.m_container2D },
			m_x0{ other.m_x0 },
			m_x1{ other.m_x1 },
			m_y0{ other.m_y0 },
			m_y1{ other.m_y1 } {

#ifdef DEBUG_VERBOSE
				 wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ "Copy-Ctor: " }.append(class_typeID().c_str()),
					 __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif

		 }

template<typename data_t,
	    class Container_t> wrf_physics::
			wrf_physics_utils::ArraySlice2D<data_t, Container_t>::
			        ArraySlice2D(_In_ ArraySlice2D &&other) {
						*this = std::move(other); 
#ifdef DEBUG_VERBOSE
				  wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Move-Ctor: " }.append(class_typeID().c_str()),
							__LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
			}

template<typename data_t,
	    class Container_t> auto wrf_physics::
			wrf_physics_utils::ArraySlice2D<data_t, Container_t>::
			             operator=(_In_ WRF_CPP_CONST ArraySlice2D &other)->ArraySlice2D & {

				if (this == &other) return (*this);
				this->m_x0 = other.m_x0;
				this->m_x1 = other.m_x1;
				this->m_y0 = other.m_y0;
				this->m_y1 = other.m_y1;
				this->m_container2D = other.m_container2D;
#ifdef DEBUG_VERBOSE
				wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Op-Copy-Assign: " }.append(class_typeID().c_str()),
					__LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
				return (*this);
			}

template<typename data_t,
	    class Container_t> auto wrf_physics::
			wrf_physics_utils::ArraySlice2D<data_t, Container_t>::
			             operator=(_In_ ArraySlice2D &&other)->ArraySlice2D & {

				if (this == &other) return (*this);
				    *this = std::move(other);
#ifdef DEBUG_VERBOSE
					wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Op-Move-Assign: " }.append(class_typeID().c_str()),
						__LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
				return (*this);
			}

template<typename data_t,
	    class Container_t> auto wrf_physics::
			wrf_physics_utils::ArraySlice2D<data_t, Container_t>::
			            get_x0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

			return (this->m_x0);
		}

template<typename data_t,
	     class Container_t> auto wrf_physics::
			 wrf_physics_utils::ArraySlice2D<data_t, Container_t>::
			            get_x1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

			 return (this->m_x1);
		 }

template<typename data_t,
	     class Container_t> auto wrf_physics::
			 wrf_physics_utils::ArraySlice2D<data_t, Container_t>::
			             get_y0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

			 return (this->m_y0);
		 }

template<typename data_t,
	     class Container_t> auto wrf_physics::
			 wrf_physics_utils::ArraySlice2D<data_t, Container_t>::
			             get_y1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

			 return (this->m_y1);
		 }

template<typename data_t,
	     class Container_t> auto wrf_physics::
			  wrf_physics_utils::ArraySlice2D<data_t, Container_t>::
			            class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING{

			 return (WRF_STRING{ typeid(*this).name() });
		 }

		 /******************************************************
		  Implementation of class ArraySlice2DSP.
		  Specialization on dyn_container_valarray_t_tag type
		 ******************************************************/

template<typename data_t>
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
			 wrf_physics::wrf_physics_internal::tags::
			         dyn_container_valarray_t_tag>::ArraySlice2DSP(_In_ WRF_CPP_CONST WRF_ULONGLONG x0,
					                                               _In_ WRF_CPP_CONST WRF_ULONGLONG x1,
					                                               _In_ WRF_CPP_CONST WRF_ULONGLONG y0,
					                                               _In_ WRF_CPP_CONST WRF_ULONGLONG y1) : 

								 m_x0{ x0 },
								 m_x1{ x1 },
							     m_y0{ y0 },
								 m_y1{y1},
								 m_slice2D((wrf_physics::wrf_physics_utils::CheckCtorArgs<WRF_ULONGLONG>::
								            check_args(x0, x1, y0, y1), (m_x1 - m_x0)*(m_y1 - m_y0))) {

			 for (WRF_ULONGLONG i{ this->m_x0 }; i != this->m_x1; ++i) {
				 for (WRF_ULONGLONG j{ this->m_y0 }; j != this->m_y1; ++j) {
					 this->m_slice2D[i + this->m_slice2D.size() * j] = static_cast<data_t>(0);
				 }
			 }
#ifdef DEBUG_VERBOSE
			 wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ "4-arg Ctor: " }.append(class_typeID().c_str()),
				 __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
		 }

template<typename data_t>
        wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
			wrf_physics::wrf_physics_internal::tags::
			   dyn_container_valarray_t_tag>::ArraySlice2DSP(_In_ WRF_CPP_CONST ArraySlice2DSP &other) :

			m_x0{ other.m_x0 },
			m_x1{ other.m_x1 },
			m_y0{ other.m_y0 },
			m_y1{ other.m_y1 },
			m_slice2D{ other.m_slice2D } {

#ifdef DEBUG_VERBOSE
			 wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Copy-Ctor: " }.append(class_typeID().c_str()),
					   __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
		 }

template<typename data_t>
        wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
			wrf_physics::wrf_physics_internal::tags::
			   dyn_container_valarray_t_tag>::ArraySlice2DSP(_In_ ArraySlice2DSP &&other) :

			m_x0{ std::move(other.m_x0) },
			m_x1{ std::move(other.m_x1) },
			m_y0{ std::move(other.m_y0) },
			m_y1{ std::move(other.m_y1) },
			m_slice2D{ std::move(other.m_slice2D) } {

#ifdef DEBUG_VERBOSE
			 wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Move-Ctor: " }.append(class_typeID().c_str()),
					   __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
		 }

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		    wrf_physics::wrf_physics_internal::tags::
			   dyn_container_valarray_t_tag>::operator=(_In_ WRF_CPP_CONST ArraySlice2DSP &other)->ArraySlice2DSP & {

				   if (this == &other) return (*this);

				   this->m_x0 = other.m_x0;
				   this->m_x1 = other.m_x1;
				   this->m_y0 = other.m_y0;
				   this->m_y1 = other.m_y1;
				   this->m_slice2D.operator=(other.m_slice2D);
#ifdef DEBUG_VERBOSE
			 wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Op-Copy-Assign: " }.append(class_typeID().c_str()),
					   __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
				   return (*this);
			}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		    wrf_physics::wrf_physics_internal::tags::
		       dyn_container_valarray_t_tag>::operator=(_In_ ArraySlice2DSP &&other)->ArraySlice2DSP & {

				   if (this == &other) return (*this);
				   *this = std::move(other);
#ifdef DEBUG_VERBOSE
			 wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Op-Move-Assign: " }.append(class_typeID().c_str()),
					   __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
				   return (*this);
		 }

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		    wrf_physics::wrf_physics_internal::tags::
		       dyn_container_valarray_t_tag>::get_x0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_x0);
}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		    wrf_physics::wrf_physics_internal::tags::
		       dyn_container_valarray_t_tag>::get_x1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_x1);
}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		    wrf_physics::wrf_physics_internal::tags::
		       dyn_container_valarray_t_tag>::get_y0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_y0);
}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		    wrf_physics::wrf_physics_internal::tags::
		       dyn_container_valarray_t_tag>::get_y1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_y1);
}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
             wrf_physics::wrf_physics_internal::tags::
			 dyn_container_valarray_t_tag>::class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING{

	return (WRF_STRING{ typeid(*this).name() });
}

/******************************************************
  Implementation of ArraySlice2DSP specialized on
  dyn_container_vector_t_tag type.
*******************************************************/

template<typename data_t>
        wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
			wrf_physics::wrf_physics_internal::tags::
			   dyn_container_vector_t_tag>::ArraySlice2DSP(_In_ WRF_CPP_CONST WRF_ULONGLONG x0,
			                                               _In_ WRF_CPP_CONST WRF_ULONGLONG x1,
														   _In_ WRF_CPP_CONST WRF_ULONGLONG y0,
														   _In_ WRF_CPP_CONST WRF_ULONGLONG y1) : 

							m_x0{ x0 },
							m_x1{ x1 },
						    m_y0{ y0 },
							m_y1{ y1 },
						    m_slice2D((wrf_physics::wrf_physics_utils::CheckCtorArgs<WRF_ULONGLONG>::check_args(x0,x1,y0,y1),
							(m_x1 - m_x0)*(m_y1 - m_y0))) {

			for (WRF_ULONGLONG i{ this->m_x0 }; i != this->m_x1; ++i) {
				for (WRF_ULONGLONG j{ this->m_y0 }; j != this->m_y1; ++j) {
					this->m_slice2D[i + this->m_slice2D.size() * j] = static_cast<data_t>(0);
				}
			}
#ifdef DEBUG_VERBOSE
			wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ "4-arg Ctor: " }.append(class_typeID().c_str()),
				__LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
		}

template<typename data_t>
        wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
			wrf_physics::wrf_physics_internal::tags::
			   dyn_container_vector_t_tag>::ArraySlice2DSP(_In_ WRF_CPP_CONST ArraySlice2DSP &other) :

			m_x0{ other.m_x0 },
			m_x1{ other.m_x1 },
			m_y0{ other.m_y0 },
			m_y1{ other.m_y1 },
			m_slice2D{ other.m_slice2D } {
#ifdef DEBUG_VERBOSE
			 wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Copy-Ctor: " }.append(class_typeID().c_str()),
					   __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
		  }

template<typename data_t>
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
			 wrf_physics::wrf_physics_internal::tags::
			     dyn_container_vector_t_tag>::ArraySlice2DSP(_In_ ArraySlice2DSP &&other) :

			 m_x0{ std::move(other.m_x0) },
			 m_x1{ std::move(other.m_x1) },
			 m_y0{ std::move(other.m_y0) },
			 m_y1{ std::move(other.m_y1) } {
#ifdef DEBUG_VERBOSE
				wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Move-Ctor: " }.append(class_typeID().c_str()),
					 __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
			}

template<typename data_t> auto 
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		    wrf_physics::wrf_physics_internal::tags::
			   dyn_container_vector_t_tag>::operator=(_In_ WRF_CPP_CONST ArraySlice2DSP &other)->ArraySlice2DSP & {

				   if (this == &rhs) return (*this);
				   this->m_x0 = other.m_x0;
				   this->m_x1 = other.m_x1;
				   this->m_y0 = other.m_y0;
				   this->m_y1 = other.m_y1;
				   this->m_slice2D.operator=(other.m_slice2D);
#ifdef DEBUG_VERBOSE
				   wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Op-Copy-Assign: " }.append(class_typeID().c_str()),
					   __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
				   return (*this);
			}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		    wrf_physics::wrf_physics_internal::tags::
			   dyn_container_vector_t_tag>::operator=(_In_ ArraySlice2DSP &&other)->ArraySlice2DSP & {

				   if (this == &rhs) return (*this);
				   *this = std::move(other);
#ifdef DEBUG_VERBOSE
				   wrf_physics::wrf_physics_utils::DebugPrinter::debug_print(WRF_STRING{ " Op-Move-Assign: " }.append(class_typeID().c_str()),
					   __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
				   return (*this);
			}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		    wrf_physics::wrf_physics_internal::tags::
		       dyn_container_vector_t_tag>::get_x0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_x0);
}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		    wrf_physics::wrf_physics_internal::tags::
			   dyn_container_vector_t_tag>::get_x1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_x1);
}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		    wrf_physics::wrf_physics_internal::tags::
		       dyn_container_vector_t_tag>::get_y0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_y0);
}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		    wrf_physics::wrf_physics_internal::tags::
		       dyn_container_vector_t_tag>::get_y1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_y1);
}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
             wrf_physics::wrf_physics_internal::tags::
			     dyn_container_vector_t_tag>::class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING{

	return (WRF_STRING{ typeid(*this).name() });
}

/********************************************************
 Implementation of ArraySlice2DSP specialized on tag of
 type dyn_container_boost_t_tag
********************************************************/

template<typename data_t> 
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
			     wrf_physics::wrf_physics_internal::tags::
				          dyn_container_boost_t_tag>::ArraySlice2DSP(_In_ WRF_CPP_CONST WRF_ULONGLONG x0,
				                                                     _In_ WRF_CPP_CONST WRF_ULONGLONG x1,
				                                                     _In_ WRF_CPP_CONST WRF_ULONGLONG y0,
				                                                     _In_ WRF_CPP_CONST WRF_ULONGLONG y1) :

				 m_x0{ x0 },
				 m_x1{ x1 },
				 m_y0{ y0 },
				 m_y1{ y1 },
				 m_slice2D{ boost::extents[(wrf_physics::wrf_physics_utils::
				 CheckCtorArgs<WRF_ULONGLONG>::check_args(x0, x1), (m_x1 - m_x0))][(wrf_physics::wrf_physics_utils::
				 CheckCtorArgs<WRF_ULONGLONG>::check_args(y0, y1), (m_y1 - m_y0))] } {

								 for (WRF_ULONGLONG i{ m_x0 }; i != m_x1; ++i) {
									 for (WRF_ULONGLONG j{ m_y0 }; j != m_y1; ++j) {

										 this->m_slice2D[i][j] = static_cast<data_t>(0);
									 }
								 }
#ifdef DEBUG_VERBOSE
								 DebugPrinter::debug_print(WRF_STRING{ " 4-arg Ctor: " }.append(class_typeID().c_str()),
									 __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif

		}

template<typename data_t>
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
			   wrf_physics::wrf_physics_internal::tags::
				         dyn_container_boost_t_tag>::ArraySlice2DSP(_In_ WRF_CPP_CONST ArraySlice2DSP &other) :

				  m_x0{ other.m_x0 },
				  m_x1{ other.m_x1 },
				  m_y0{ other.m_y0 },
				  m_y1{ other.m_y1 },
				  m_slice2D{ other.m_slice2D } {

#ifdef DEBUG_VERBOSE
							 DebugPrinter::debug_print(WRF_STRING{ " Copy-Ctor: " }.append(class_typeID().c_str()),
								 __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
		 }

template<typename data_t>
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
			 wrf_physics::wrf_physics_internal::tags::
			     dyn_container_boost_t_tag>::ArraySlice2DSP(_In_ ArraySlice2DSP &&other) :

			     m_x0{ std::forward<WRF_ULONGLONG>(other.m_x0) },
			     m_x1{ std::forward<WRF_ULONGLONG>(other.m_x1) },
			     m_y0{ std::forward<WRF_ULONGLONG>(other.m_y0) },
			     m_y1{ std::forward<WRF_ULONGLONG>(other.m_y1) },
				 m_slice2D{ std::forward<MultiArraySlice2D>(other.m_slice2D) } {

#ifdef DEBUG_VERBOSE
					 DebugPrinter::debug_print(WRF_STRING{ " Move-Ctor: " }.append(class_typeID().c_str()),
						 __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
			}

template<typename data_t>
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
			   wrf_physics::wrf_physics_internal::tags::
			         dyn_container_boost_t_tag>::~ArraySlice2DSP() {

#ifdef DEBUG_VERBOSE
				 DebugPrinter::debug_print(WRF_STRING{ " Dtor: " }.append(class_typeID().c_str()),
					 __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
			 }

template<typename data_t> auto 
	     wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		        wrf_physics::wrf_physics_internal::tags::
				       dyn_container_boost_t_tag>::operator=(_In_ WRF_CPP_CONST ArraySlice2DSP &other)->ArraySlice2DSP & {
						   if (this == &other) return (*this);
						   ArraySlice2DSP<data_t, wrf_physics::wrf_physics_internal::tags::
							   dyn_container_boost_t_tag> temp{ other };
						   std::swap(*this, temp);
#ifdef DEBUG_VERBOSE
						   DebugPrinter::debug_print(WRF_STRING{ " Op-Copy-Assign: " }.append(class_typeID().c_str()),
							   __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
						   return (*this);

			}

template<typename data_t> auto
          wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		      wrf_physics::wrf_physics_internal::tags::
			       dyn_container_boost_t_tag>::operator=(_In_ ArraySlice2DSP &&other)->ArraySlice2DSP & {
					   if (this == &other) return (*this);
					   *this = std::forward<ArraySlice2DSP>(other);
#ifdef DEBUG_VERBOSE
					   DebugPrinter::debug_print(WRF_STRING{ " Op-Move-Assign: " }.append(class_typeID().c_str()),
						   __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
					   return (*this);
			  }

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		     wrf_physics::wrf_physics_internal::tags::
			      dyn_container_boost_t_tag>::get_x0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_x0);
}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		     wrf_physics::wrf_physics_internal::tags::
			      dyn_container_boost_t_tag>::get_x1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_x1);
}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		     wrf_physics::wrf_physics_internal::tags::
			     dyn_container_boost_t_tag>::get_y0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_y0);
}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		     wrf_physics::wrf_physics_internal::tags::
			      dyn_container_boost_t_tag>::get_y1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_y1);
}

template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		     wrf_physics::wrf_physics_internal::tags::
			       dyn_container_boost_t_tag>::class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING{

	return (WRF_STRING{ typeid(*this).name() });
}

template<typename data_t> auto 
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		     wrf_physics::wrf_physics_internal::tags::
			 dyn_container_boost_t_tag>::class_info()WRF_CPP_CONST->std::tuple<WRF_STRING, WRF_ULONGLONG, WRF_STRING>{

	return (std::make_tuple(WRF_STRING{ typeid(*this).name() },
	         typeid(*this).hash_code(), WRF_STRING{ typeid(*this).raw_name() }));
	
}

#ifdef DEBUG_VERBOSE
template<typename data_t> auto
         wrf_physics::wrf_physics_utils::ArraySlice2DSP<data_t,
		     wrf_physics::wrf_physics_internal::tags::
			     dyn_container_boost_t_tag>::print_object_state()WRF_CPP_CONST->void{

	std::cout << "****** Object state dump ******* "  std::endl;
	std::cout << " Class type: " << this->class_typeID() << std::endl;
	std::cout << " Class type raw name: " << std::get<2>(this->class_info()) << std::endl;
	std::cout << " Class hash code: " << std::get<1>(this->class_info()) << std::endl;
	std::cout << " Current date: " << " |  " << " Current time: " << std::endl;
	std::cout <<    __DATE__                        __TIME__      << std::endl;
	std::cout << " Number of class members: " << 5 << std::endl;
	std::cout << " Total number of allocated memory: " << (4 * sizeof(WRF_ULONGLONG)+sizeof(this->m_slice2D)) / 1024Ui64 << " KiB. " << std::endl;
	std::cout << " this pointer at virtual address: " << std::hex << this << std::endl;
	std::cout << " this->m_x0   at vritual address: " << std::hex << &this->m_x0 << std::endl;
	std::cout << " this->m_x1   at virtual address: " << std::hex << &this->m_x1 << std::endl;
	std::cout << " this->m_y0   at virtual address: " << std::hex << &this->m_y0 << std::endl;
	std::cout << " this->m_y1   at virtual address: " << std::hex << &this->m_y1 << std::endl;
	std::cout << " this->m_slice2D at virtual address: " << std::hex << &this->m_slice2D << std::endl;
	std::cout << " ****** End of object state dump ******* " << std::endl;

}
		 
#endif

/*****************************************************
 Implementation of class ArraySlice3DSP 
 Specilization on dispatch tag of type 
 dyn_container_vector_t_tag.
******************************************************/

                                                  
			

			
