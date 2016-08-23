
/********************************************
    Implementation of class ArrayMetaData
*********************************************/

template<class Container_t> 
         wrf_physics::wrf_physics_utils::
                         ArrayMetaData<Container_t>::
					                   ArrayMetaData(_In_ WRF_CPP_CONST WRF_STRING &cont_type,
					                                 _In_ WRF_CPP_CONST WRF_STRING &cont_tag_type,
					                                 _In_ WRF_CPP_CONST WRF_STRING &description,
					                                 _In_ WRF_CPP_CONST WRF_WSTRING &faddress,
					                                 _In_ WRF_CPP_CONST WRF_ULONGLONG cont_size,
					                                 _In_ WRF_CPP_CONST WRF_ULONGLONG cont_extent,
					                                 _In_ WRF_CPP_CONST WRF_STRING &primitive_type) :

					   m_container_type{ cont_type },
					   m_container_tag_type{ cont_tag_type },
					   m_description{ description },
					   m_func_address{ faddress },
					   m_container_size{ cont_size },
					   m_container_extent{ cont_extent },
					   m_primitive_type{ primitive_type } {

#ifdef DEBUG_VERBOSE
										 DebugPrinter::debug_print(WRF_STRING{ " 7-arg Ctor: " }.append(class_typeID()).c_str(),
											 __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
		}

template<class Container_t>
         wrf_physics::wrf_physics_utils::
			             ArrayMetaData<Container_t>::
						               ArrayMetaData(_In_ WRF_CPP_CONST ArrayMetaData &other) :

			 m_container_type{ other.m_container_type },
			 m_container_tag_type{ other.m_container_tag_type },
			 m_description{ other.m_description },
			 m_func_address{ other.m_func_address },
			 m_container_size{ other.m_container_size },
			 m_container_extent{ other.m_container_extent },
			 m_primitive_type{ other.m_primitive_type } {


#ifdef DEBUG_VERBOSE
										   DebugPrinter::debug_print(WRF_STRING{ " Copy-Ctor: " }.append(class_typeID()).c_str(),
											   __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
	    }

template<class Container_t>
         wrf_physics::wrf_physics_utils::
			             ArrayMetaData<Container_t>::
						               ArrayMetaData(_In_ ArrayMetaData &&other) :

				 m_container_type{ std::move(other.m_container_type) },
				 m_container_tag_type{ std::move(other.m_container_tag_type) },
				 m_description{ std::move(other.m_description) },
				 m_func_address{ std::move(other.m_func_address) },
				 m_container_size{ std::move(other.m_container_size) },
				 m_container_extent{ std::move(other.m_container_extent) },
				 m_primitive_type{ std::move(other.m_primitive_type) } {


#ifdef DEBUG_VERBOSE
										   DebugPrinter::debug_print(WRF_STRING{ " Move-Ctor: " }.append(class_typeID()).c_str(),
											   __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
		 }

template<class Container_t> auto 
          wrf_physics::wrf_physics_utils::
			              ArrayMetaData<Container_t>::
						                    operator=(_In_ WRF_CPP_CONST ArrayMetaData &other)->ArrayMetaData & {

											if (this == &other) return (*this);
											ArrayMetaData<Container_t> temp{ other };
											std::swap(*this, temp);
#ifdef DEBUG_VERBOSE
											DebugPrinter::debug_print(WRF_STRING{ "Op-Copy-Assign: " }.append(class_typeID()).c_str(),
												__LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
											return (*this);
		}

template<class Container_t> auto
         wrf_physics::wrf_physics_utils::
		                 ArrayMetaData<Container_t>::
						                   operator=(_In_ ArrayMetaData &&other)->ArrayMetaData & {

											   if (this == &other) return (*this);
											   *this = std::move(other);
#ifdef DEBUG_VERBOSE
											   DebugPrinter::debug_print(WRF_STRING{ "Op-Move-Assign: " }.append(class_typeID()).c_str(),
												   __LINE__, WRF_WSTRING{ __FUNCTIONW__ });
#endif
											   return (*this);
	   }

template<class Container_t> auto
         wrf_physics::wrf_physics_utils::
		                ArrayMetaData<Container_t>::
						              get_container_type()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING{

	return (this->m_container_type);
}

template<class Container_t> auto
         wrf_physics::wrf_physics_utils::
		                 ArrayMetaData<Container_t>::
		                               get_container_tag_type()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING{

	return (this->m_container_tag_type);
}

template<class Container_t> auto 
         wrf_physics::wrf_physics_utils::
		                 ArrayMetaData<Container_t>::
						               get_description()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING{

	return (this->m_description);
}

template<class Container_t> auto 
         wrf_physics::wrf_physics_utils::
		                  ArrayMetaData<Container_t>::
						                 get_func_address()WRF_CPP_CONST->WRF_CPP_CONST WRF_WSTRING{

	return (this->m_func_address);
}

template<class Container_t> auto
         wrf_physics::wrf_physics_utils::
		                 ArrayMetaData<Container_t>::
						                get_container_size()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_container_size);
}

template<class Container_t> auto
         wrf_physics::wrf_physics_utils::
		                 ArrayMetaData<Container_t>::
						               get_container_extent()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG{

	return (this->m_container_extent);
}

template<class Container_t> auto
         wrf_physics::wrf_physics_utils::
		                 ArrayMetaData<Container_t>::
						                get_primitive_type()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING{

	return (this->m_primitive_type);
}

template<class Container_t> auto
         wrf_physics::wrf_physics_utils::
		                 ArrayMetaData<Container_t>::
						               get_class_members()WRF_CPP_CONST->std::tuple<WRF_CPP_CONST WRF_STRING,
						                                                            WRF_CPP_CONST WRF_STRING,
						                                                            WRF_CPP_CONST WRF_STRING,
						                                                            WRF_CPP_CONST WRF_WSTRING,
						                                                            WRF_CPP_CONST WRF_ULONGLONG,
						                                                            WRF_CPP_CONST WRF_ULONGLONG,
						                                                            WRF_CPP_CONST WRF_STRING >  {

	return (std::make_tuple(this->m_container_type, this->m_container_tag_type,
	                        this->m_description, this->m_func_address,
	                        this->m_container_size, this->m_container_extent,
	                        this->m_primitive_type));
}

template<class Container_t> auto 
         wrf_physics::wrf_physics_utils::
		                 ArrayMetaData<Container_t>::
						               class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING{

	return (WRF_STRING{ typeid(*this).name() });
}

template<class Container_t> auto
         wrf_physics::wrf_physics_utils::
		                 ArrayMetaData<Container_t>::
						               class_info()WRF_CPP_CONST->std::tuple<WRF_STRING, WRF_ULONGLONG, WRF_STRING>{

	return (std::make_tuple(WRF_STRING{ typeid(*this).name() }, 
	                       typeid(*this).hash_code(), 
						   WRF_STRING{ typeid(*this).raw_name() }));
}

template<class Container_t> auto
         wrf_physics::wrf_physics_utils::
                        ArrayMetaData<Container_t>::
						              class_member_names()->std::array<WRF_STRING, 7Ui64> {

	constexpr WRF_ULONGLONG size = 7Ui64;
	std::array<WRF_STRING, size> member_names = { WRF_STRING{ "m_container_type" },
		                                          WRF_STRING{ "m_container_tag_type" },
		                                          WRF_STRING{ "m_description" },
		                                          WRF_STRING{ "m_func_address" },
		                                          WRF_STRING{ "m_container_size" },
		                                          WRF_STRING{ "m_container_extent" },
		                                          WRF_STRING{ "m_primitive_type" } };

	return (member_names);
}

template<class Container_t> auto
               operator<<(_In_ std::ostream &os,
                          _In_ WRF_CPP_CONST wrf_physics::wrf_physics_utils::
						                      ArrayMetaData<Container_t> &rhs)->std::ostream & {

				   DateTime date_time{};
				
				   std::cout << "***Dumping state of object of type: ***" << rhs.class_typeID().c_str() << std::endl;
				   std::cout << "Current date: " << date_time.getDateTime().first << std::endl;
				   std::cout << "Current time: " << date_time.getDateTime().second << std::endl;
				   std::cout << "Class members values: " << std::endl;
				   os << ArrayMetaData<Container_t>::class_member_names()[0] << rhs.get_container_type() << std::endl;
				   os << ArrayMetaData<Container_t>::class_member_names()[1] << rhs.get_container_tag_type() << std::endl;
				   os << ArrayMetaData<Container_t>::class_member_names()[2] << rhs.get_description() << std::endl;
				   os << ArrayMetaData<Container_t>::class_member_names()[3] << std::hex << rhs.get_func_address() << std::endl;
				   os << ArrayMetaData<Container_t>::class_member_names()[4] << rhs.get_container_size() << std::endl;
				   os << ArrayMetaData<Container_t>::class_member_names()[5] << rhs.get_container_extent() << std::endl;
				   os << ArrayMetaData<Container_t>::class_member_names()[6] << rhs.get_primitive_type() << std::endl;
				   std::cout << "*** End of object state dump ***" << std::endl;
				   return (os);
}
                                  


																 