
#ifndef WRF_PHYS_ARRAY_SLICE_H_
#define WRF_PHYS_ARRAY_SLICE_H_

#ifndef WRF_PHYS_ARRAY_SLICE_VERSION_MAJOR 
#define WRF_PHYS_ARRAY_SLICE_VERSION_MAJOR 1
#endif

#ifndef WRF_PHYS_ARRAY_SLICE_VERSION_MINOR
#define WRF_PHYS_ARRAY_SLICE_VERSION_MINOR 0
#endif

#ifndef WRF_PHYS_ARRAY_SLICE_CREATE_DATE
#define WRF_PHYS_ARRAY_SLICE_CREATE_DATE 20160714
#endif

/* Initialize this macro to successful build date*/
#ifndef WRF_PHYS_ARRAY_SLICE_BUILD_DATE
#define WRF_PHYS_ARRAY_SLICE_BUILD_DATE 0
#endif

/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library class ContainerSlice -  declaration.

@file Wrf_phys_array_slice.h
@author: Bernard Gingold
@version:  1.0.0 14/07/2016
@description: Wrf_phys_array_slice.h
*/


#include "Wrf_ctor_check_args.h"
#include "Wrf_type_traits.hpp"
#include "Wrf_phys_tags.h"
#include "Wrf_debug_print.h"
#include <utility>

namespace  wrf_physics {

	namespace wrf_physics_utils {

		/**********************************
		   class templated on primitive data_t
		   type and on concrete type Container_t.
		        Generic  array 1D slice
		***********************************/
		template<typename data_t,
		        class Container_t >  struct ArraySlice1D {


					ArraySlice1D(
					             _In_ WRF_CPP_CONST WRF_ULONGLONG,
					             _In_ WRF_CPP_CONST WRF_ULONGLONG);

					ArraySlice1D(_In_ WRF_CPP_CONST ArraySlice1D &);

					ArraySlice1D(_In_ ArraySlice1D &&);
					          

					~ArraySlice1D() = WRF_CPP_DEFAULT;

					
					auto  operator=(_In_ WRF_CPP_CONST ArraySlice1D &)->ArraySlice1D &;

					auto  operator=(_In_ ArraySlice1D &&)->ArraySlice1D &;

					

					/* acessors */

					auto get_x0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

					auto get_x1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

					auto class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING;

					/* start of slice*/
					WRF_ULONGLONG m_x0;

					/* end of slice*/
					WRF_ULONGLONG m_x1;

					/* template argument should
					posses available publicly
					operator[]().
					*/
				    Container_t m_container1D;

		};


				template<typename data_t,
				        class Container_t > class ArraySlice2D {


							/****************************
							  Constructor and Destructor
							*****************************/

							ArraySlice2D(_In_ WRF_CPP_CONST Container_t &,
							             _In_ WRF_CPP_CONST WRF_ULONGLONG,
							             _In_ WRF_CPP_CONST WRF_ULONGLONG,
							             _In_ WRF_CPP_CONST WRF_ULONGLONG,
							             _In_ WRF_CPP_CONST WRF_ULONGLONG);

							ArraySlice2D(_In_ WRF_CPP_CONST ArraySlice2D &);

							ArraySlice2D(_In_ ArraySlice2D &&);

							~ArraySlice2D() = WRF_CPP_DEFAULT;

							auto  operator=(_In_ WRF_CPP_CONST ArraySlice2D &)->ArraySlice2D &;

							auto  operator=(_In_ ArraySlice2D &&)->ArraySlice2D &;


							/***************************
							     accessor methods
							****************************/
							auto  get_x0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

							auto  get_x1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

							auto  get_y0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

							auto  get_y1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

							auto  class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING;

#ifdef DEBUG_VERBOSE
							auto  debug_print()WRF_CPP_CONST->void;
#endif
							

						

							WRF_ULONGLONG m_x0;

							WRF_ULONGLONG m_x1;

							WRF_ULONGLONG m_y0;

							WRF_ULONGLONG m_y1;

							/* Container_t should posses
							publicly accessible operator[]()*/
							Container_t m_container2D;
				};

						/*******************************************
						  class ArraySlice2DSP specialization on
						  2 types.
						  1) std::vector
						  2) std::valarray
						  3) bost::multi_array
						  Primary template.
						********************************************/

						template<typename data_t,
						         class Container_t> 
						                      struct  ArraySlice2DSP;


								/*********************************
								  Specialization on tag of type
								  dyn_container_valarray_t_tag.
								**********************************/

								template<typename data_t> 
								          struct ArraySlice2DSP<data_t,
									              wrf_physics::wrf_physics_internal::tags::
												                           dyn_container_valarray_t_tag> {

											  /*******************************
											          local   typedefs
											  ********************************/
											  typedef std::valarray<data_t> ValarraySlice2D;


											  /********************************
											    Constructors and Destructor
											  ********************************/

											  ArraySlice2DSP(_In_ WRF_CPP_CONST WRF_ULONGLONG,
												             _In_ WRF_CPP_CONST WRF_ULONGLONG,
												             _In_ WRF_CPP_CONST WRF_ULONGLONG,
												             _In_ WRF_CPP_CONST WRF_ULONGLONG);

											  ArraySlice2DSP(_In_ WRF_CPP_CONST ArraySlice2DSP &);

											  ArraySlice2DSP(_In_ ArraySlice2DSP &&);

											  ~ArraySlice2DSP() = WRF_CPP_DEFAULT;

											  /************************************
											          Class member operators
											  *************************************/

											  auto operator=(_In_ WRF_CPP_CONST ArraySlice2DSP &)->ArraySlice2DSP &;

											  auto operator=(_In_  ArraySlice2DSP &&)->ArraySlice2DSP &;

											  /*********************************
											        class member accessors
											  **********************************/

											  auto  get_x0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

											  auto  get_x1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

											  auto  get_y0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

											  auto  get_y1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

											  auto  class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING;

#ifdef  DEBUG_VERBOSE
											  auto  debug_print()WRF_CPP_CONST->void;
#endif

											  /**************************
											         class members
											  ****************************/

											  WRF_ULONGLONG m_x0;

											  WRF_ULONGLONG m_x1;

											  WRF_ULONGLONG m_y0;

											  WRF_ULONGLONG m_y1;

											  ValarraySlice2D m_slice2D;


											 
								};

							    /************************************
								 Specialization on tag of type
								 dyn_container_vector_t_tag
								************************************/
                                template<typename data_t>
								     struct  ArraySlice2DSP<data_t,
									          wrf_physics::wrf_physics_internal::tags::
									                             dyn_container_vector_t_tag> {


										 /***************************
										        local  typedefs
										 ****************************/
										 typedef std::vector<data_t> VecSlice2D;


										 /*****************************************
										        Constructors and Destructor
										 ******************************************/
										 ArraySlice2DSP(_In_ WRF_CPP_CONST WRF_ULONGLONG,
											            _In_ WRF_CPP_CONST WRF_ULONGLONG,
											            _In_ WRF_CPP_CONST WRF_ULONGLONG,
											            _In_ WRF_CPP_CONST WRF_ULONGLONG);

										 ArraySlice2DSP(_In_ WRF_CPP_CONST ArraySlice2DSP &);

										 ArraySlice2DSP(_In_ ArraySlice2DSP &&);

										 ~ArraySlice2DSP() = WRF_CPP_DEFAULT;

										 /***********************************
										         class member operators
										 ************************************/

										 auto operator=(_In_ WRF_CPP_CONST ArraySlice2DSP &)->ArraySlice2DSP &;

										 auto operator=(_In_  ArraySlice2DSP &&)->ArraySlice2DSP &;


										 /******************************
										        member accessors
										 *******************************/

										 auto  get_x0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

										 auto  get_x1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

										 auto  get_y0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

										 auto  get_y1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

										 auto  class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING;

#ifdef DEBUG_VERBOSE
										 auto  debug_print()WRF_CPP_CONST->void;
#endif

										 /*********************
										       class members
										 *************************/

										 WRF_ULONGLONG m_x0;

										 WRF_ULONGLONG m_x1;

										 WRF_ULONGLONG m_y0;

										 WRF_ULONGLONG m_y1;

										 VecSlice2D m_slice2D;


								};

									 /**************************************
									  Specialization on tag of  type
									  dyn_container_boost_t_tag
									 ****************************************/

									 template<typename data_t>
									           struct  ArraySlice2DSP<data_t,
												   wrf_physics::wrf_physics_internal::tags::
												                            dyn_container_boost_t_tag> {


												   /***************************
												          Local typedefs
												   ****************************/
												   typedef boost::multi_array<data_t, 2> MultiArraySlice2D;

												   /******************************
												     Constructors and Destructor
												   *******************************/

												   ArraySlice2DSP(_In_ WRF_CPP_CONST WRF_ULONGLONG,
													              _In_ WRF_CPP_CONST WRF_ULONGLONG,
													              _In_ WRF_CPP_CONST WRF_ULONGLONG,
													              _In_ WRF_CPP_CONST WRF_ULONGLONG);

												   ArraySlice2DSP(_In_ WRF_CPP_CONST ArraySlice2DSP &);

												   ArraySlice2DSP(_In_ ArraySlice2DSP &&);

												   ~ArraySlice2DSP();

												   /**************************************
												              Member operators
												   ****************************************/

												   auto  operator=(_In_ WRF_CPP_CONST ArraySlice2DSP &)->ArraySlice2DSP &;

												   auto  operator=(_In_  ArraySlice2DSP &&)->ArraySlice2DSP &;

												   /***************************************
												          Member functions - accessors
												   ****************************************/

												   auto  get_x0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

												   auto  get_x1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

												   auto  get_y0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

												   auto  get_y1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

												   /******************************************
												      Member functions - class helpers
												   *******************************************/

												   auto  class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING;

												   auto  class_info()WRF_CPP_CONST->std::tuple<WRF_STRING, WRF_ULONGLONG, WRF_STRING>;

#ifdef DEBUG_VERBOSE
												   auto  print_object_state()WRF_CPP_CONST->void;
#endif

												   /**************************
												         Class members
												   ****************************/

												   WRF_ULONGLONG m_x0;

												   WRF_ULONGLONG m_x1;

												   WRF_ULONGLONG m_y0;

												   WRF_ULONGLONG m_y1;

												   MultiArraySlice2D  m_slice2D;
									 };

                                     
											   /*******************************************
											   class ArraySlice3DSP specialization on
											   3 types(tags).
											   1) std::vector
											   2) std::valarray
											   3) bost::multi_array
											       Primary template.
											   ********************************************/
											   template<typename data_t,
											            class Container_t> struct  ArraySlice3DSP;


														/*******************************************
														   Specialization templated on dispatch tag
														   of type dyn_container_vector_t_tag.
														********************************************/

														template<typename data_t>
														         struct   ArraySlice3DSP<data_t,
															                 wrf_physics::wrf_physics_internal::tags::
															                                       dyn_container_vector_t_tag> {

																	 /***********************************
																	             local typedef
																	 ************************************/
																	 typedef std::vector<data_t> VecSlice3D;



																	 /*****************************************
																	         Constructors and Destructor
																	 ******************************************/

																	 ArraySlice3DSP(_In_ WRF_CPP_CONST WRF_ULONGLONG,
																		            _In_ WRF_CPP_CONST WRF_ULONGLONG,
																		            _In_ WRF_CPP_CONST WRF_ULONGLONG,
																		            _In_ WRF_CPP_CONST WRF_ULONGLONG,
																		            _In_ WRF_CPP_CONST WRF_ULONGLONG,
																		            _In_ WRF_CPP_CONST WRF_ULONGLONG);

																	 ArraySlice3DSP(_In_ WRF_CPP_CONST ArraySlice3DSP &);

																	 ArraySlice3DSP(_In_ ArraySlice3DSP &&);

																	 ~ArraySlice3DSP();

																	 /****************************************
																	                Member operators
																	 *****************************************/

																	 auto  operator=(_In_ WRF_CPP_CONST ArraySlice3DSP &)->ArraySlice3DSP &;

																	 auto  operator=(_In_ ArraySlice3DSP &&)->ArraySlice3DSP &;


																	 /****************************************
																	         Class functions - accessors
																	 *****************************************/

																	 auto  get_x0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

																	 auto  get_x1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

																	 auto  get_y0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

																	 auto  get_y1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

																	 auto  get_z0()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

																	 auto  get_z1()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;


																	 /*********************************************
																	            Class functions - helpers
																	 **********************************************/

																	 auto  class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING;

																	 auto  class_info()WRF_CPP_CONST->std::tuple<WRF_STRING, WRF_ULONGLONG, WRF_STRING>;

#ifdef DEBUG_VERBOSE
																	 print_object_state()WRF_CPP_CONST->void;
#endif
																	 /*****************************
																	           Class members
																	 ******************************/

																	 WRF_ULONGLONG m_x0;

																	 WRF_ULONGLONG m_x1;

																	 WRF_ULONGLONG m_y0;

																	 WRF_ULONGLONG m_y1;

																	 WRF_ULONGLONG m_z0;

																	 WRF_ULONGLONG m_z1;

																	 VecSlice3D  m_slice3D;


														};


						/********************************
						  Global namespace operators <<
						*********************************/



#include "Wrf_phys_array_slice.inl"
	}
}

#endif /*WRF_PHYS_ARRAY_SLICE_H_*/