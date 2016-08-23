
/***************************************
  Implementation of Array1DPrinter
****************************************/

template<typename data_t,
	     class Container_t> auto  
			   wrf_physics::wrf_physics_utils::
			       Array1DPrinter<data_t, Container_t>::
						print_array1d(_In_ WRF_CPP_CONST Container_t &container,
			                          _In_ WRF_CPP_CONST ArrayMetaData<Container_t> &metadata )->
									                                        std::enable_if<wrf_physics::
																	                       wrf_physics_internal::
																						   traits::Is_Container_std_vector<data_t,Container_t>::value ||
																						   wrf_physics::
																						   wrf_physics_internal::
																						   traits::Is_Container_std_valarray<data_t,Container_t>::value ||
																						   wrf_physics::
																						   wrf_physics_internal::
																						   traits::Is_Container_boost_multi_array1d<data_t, Container_t>::value, void> {
#ifdef DEBUG_VERBOSE
							DebugPrinter::debug_verbose();
							DebugPrinter::at_prolog(__LINE__, WRF_STRING{ " Array1DPrinter::print_array1d -- prolog " });
#endif 
							using namespace wrf_physics::wrf_physics_internal::traits;
							WRF_ULONGLONG nElements{};
							if ((Is_Container_std_vector<data_t, Container_t>::value) || (Is_Container_std_valarray<data_t, Container_t>::value))
								nElements = container.size();
							else if (Is_Container_boost_multi_array1d<data_t,Container_t>::value)
								nElements = container.num_of_elements();

							std::cout << "*** Dumping container metadata ***" << std::endl;
							std::cout << " Container of type: " << metadata.get_container_type() << std::endl;
							std::cout << " Container tag type: " << metadata.get_container_tag_type() << std::endl;
							std::cout << " Container's dexcription: " << metadata.get_description() << std::endl;
							std::cout << " Container's enclosing function virt address: " << std::hex << metadata.get_func_address() << std::endl;
							std::cout << " Container's size: " << metadata.get_container_size() << std::endl;
							std::cout << " Container's extent: " << metadata.get_container_extent() << std::endl;
							std::cout << " Container stored primitive type: " << metadata.get_primitive_type() << std::endl;

							std::cout << "*** Dumping stored content. ***" << std::endl;
							std::cout << " Current date and time: " << std::endl;
							std::cout << __DATE__ << " , " << __TIME__ << std::endl;
							std::cout << "index:           value:  " << std::endl;
							std::cout << "---------------------------" << std::endl;
							for (WRF_ULONGLONG i{ 0 }; i != nElements; ++i) {

								std::cout << std::setw(2) << i << std::setw(20) << std::fixed << std::setprecision(15) <<
									container.operator()[i] << std::endl;
							}
							std::cout << "--------------------------" << std::endl;
							std::cout << "*** Reached end of stored content dump. ***" << std::endl;
#ifdef DEBUG_VERBOSE
							DebugPrinter::debug_verbose();
							DebugPrinter::at_epilog(__LINE__, WRF_STRING{ " Array1DPrinter::print_array1d -- epilog " });
#endif
			   }
			                       