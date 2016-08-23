
#ifndef MODULE_MP_WSM_IFACE_H_
#define MODULE_MP_WSM_IFACE_H_


#ifndef MODULE_MP_WSM_IFACE_VERSION_MAJOR 
#define MODULE_MP_WSM_IFACE_VERSION_MAJOR 1
#endif

#ifndef MODULE_MP_WSM_IFACE_VERSION_MINOR
#define MODULE_MP_WSM_IFACE_VERSION_MINOR 0
#endif

#ifndef MODULE_MP_WSM_IFACE_CREATE_DATE
#define MODULE_MP_WSM_IFACE_CREATE_DATE 20160707
#endif

/* Notice: initialize to successful build date*/
#ifndef MODULE_MP_WSM_IFACE_BUILD_DATE
#define MODULE_MP_WSM_IFACE_BUILD_DATE 0
#endif


#include "WRF_PHYS_LIB_TYPEDEFS.h"
#include "Wrf_phys_except.h"
#include "Wrf_phys_tags.h"

/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library Module WSM Interface -  declaration.

@file Module_mp_wsm_iface.h
@author: Bernard Gingold
@version:  1.0.0  07/07/2016
@description: Module_mp_wsm_iface.h
*/

namespace wrf_physics {

	namespace wrf_models_wsm {

		namespace wrf_wsm_iface {

			

			/**********************************************
			        Abstract class ISpecies_base
			**********************************************/
			template<typename data_t,
			         class Container_t> struct ISpecies_base {


						 WRF_CPP_VIRTUAL ~ISpecies_base() = default;

						 /********************************
						      Pure virtual functions
						 *********************************/

						 WRF_CPP_VIRTUAL auto class_typeId()WRF_CPP_CONST->WRF_STRING WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) = 0;

						 /* return class name,raw name and hash tag.*/
						 WRF_CPP_VIRTUAL auto   class_info()WRF_CPP_CONST->std::tuple<WRF_STRING, WRF_ULONGLONG, WRF_STRING> = 0;

						 /* returns class tags description */
						/* return class name,raw name and hash tag.*/
						 WRF_CPP_VIRTUAL auto   class_info()WRF_CPP_CONST->std::tuple<WRF_STRING, WRF_ULONGLONG, WRF_STRING> = 0;

						/* returns class tags description */
						 WRF_CPP_VIRTUAL auto   class_tags()WRF_CPP_CONST->std::pair<WRF_STRING, WRF_STRING> = 0;

						

						/* number of array elements */
						 WRF_CPP_VIRTUAL auto   num_of_elements()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG WRF_CPP_NOEXCEPT(WRF_CPP_FALSE) = 0;

						/* number of array dimensions*/
						 WRF_CPP_VIRTUAL auto   num_of_dimensions()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) = 0;

						/* print object state.*/
						 WRF_CPP_VIRTUAL auto   print_object_state() WRF_CPP_CONST->void WRF_CPP_NOEXCEPT(true) = 0;

						

#ifdef DEBUG_VERBOSE
						 WRF_CPP_VIRTUAL	auto   debug_print(_In_ WRF_CPP_CONST WRF_STRING &,
							                                       _In_ WRF_CPP_CONST WRF_INT,
							                                       _In_ WRF_CPP_CONST WRF_WSTRING &)WRF_CPP_CONST->void = 0;
#endif 

			};


			/******************************************
			 struct Psacw templated on primitive type
			 data_t and on Container type.
			 Primary template.
			*******************************************/

			template<typename data_t,
			         class Container_t,
				     WRF_CPP_CONST WRF_ULONGLONG ims,
				     WRF_CPP_CONST WRF_ULONGLONG ime,
				     WRF_CPP_CONST WRF_ULONGLONG jms,
				     WRF_CPP_CONST WRF_ULONGLONG jme >  struct  Psacw;


					 /******************************************************
					   Type float and type boost::multi_array<float,2>
					   specialization.
					   This structure models or rather contains the values
					   of accretion of cloud water by snow to form graupel.
					 *******************************************************/

					 template< WRF_CPP_CONST WRF_ULONGLONG ims,
						       WRF_CPP_CONST WRF_ULONGLONG ime,
							   WRF_CPP_CONST WRF_ULONGLONG jms,
							   WRF_CPP_CONST WRF_ULONGLONG jme >  struct Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
							                                           wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme> final : 
					                                                   public ISpecies_base<wrf_physics::wrf_physics_internal::tags::float32_t_tag, wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag>  {


								   /* data type - float
								      Container type - boost::multi_array*/

								   /**********************************
								        Constructor and destructor
								   ***********************************/

								   Psacw();

								   Psacw(_In_  WRF_CPP_CONST Psacw &);

								   Psacw(_In_ Psacw &&);

								 WRF_CPP_VIRTUAL  ~Psacw() = WRF_CPP_DEFAULT;


								   /*********************************
								        class member operators 
								   **********************************/

								   auto   operator=(_In_ WRF_CPP_CONST Psacw &)->Psacw &;

								   auto   operator=(_In_ Psacw &&)->Psacw &;

								   auto   operator==(_In_ WRF_CPP_CONST Psacw &)->WRF_CPP_CONST WRF_BOOL;

								   auto   operator!=(_In_ WRF_CPP_CONST Psacw &)->WRF_CPP_CONST WRF_BOOL;

								   auto   operator()(_In_ WRF_CPP_CONST WRF_ULONGLONG,
									                 _In_ WRF_CPP_CONST WRF_ULONGLONG)WRF_CPP_CONST->WRF_CPP_CONST WRF_REAL32;

								   auto   operator()(_In_ WRF_CPP_CONST WRF_ULONGLONG,
									                 _In_ WRF_CPP_CONST WRF_ULONGLONG)->WRF_REAL32;

								   auto   operator+=(_In_ WRF_CPP_CONST Psacw &)->Psacw &;

								   auto   operator-=(_In_ WRF_CPP_CONST Psacw &)->Psacw &;


								   /******************************
								         member functions
								   *******************************/

								   /* returns class typeid*/
								WRF_CPP_VIRTUAL   auto   class_typeId()WRF_CPP_CONST->WRF_STRING WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) WRF_CPP_OVERRIDE;

								   /* return class name,raw name and hash tag.*/
								WRF_CPP_VIRTUAL    auto   class_info()WRF_CPP_CONST->std::tuple<WRF_STRING, WRF_ULONGLONG, WRF_STRING> WRF_CPP_OVERRIDE;

								   /* returns class tags description */
								WRF_CPP_VIRTUAL    auto   class_tags()WRF_CPP_CONST->std::pair<WRF_STRING, WRF_STRING> WRF_CPP_OVERRIDE;

								   /* returns class member copied to smart pointer */
								   auto   toCPtr()->WRF_SHPTRF32 WRF_CPP_NOEXCEPT(WRF_CPP_FALSE) ;

								   /* number of array elements */
								WRF_CPP_VIRTUAL    auto   num_of_elements()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG WRF_CPP_NOEXCEPT(WRF_CPP_FALSE) WRF_CPP_OVERRIDE;

								   /* number of array dimensions*/
								WRF_CPP_VIRTUAL    auto   num_of_dimensions()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) WRF_CPP_OVERRIDE;

								   /* print object state.*/
								WRF_CPP_VIRTUAL    auto   print_object_state() WRF_CPP_CONST->void WRF_CPP_NOEXCEPT(true) WRF_CPP_OVERRIDE;

								   /* conversion to mks model*/
							    auto   convert_to_mks(_Inout_ KMSProdRatioF32 &) WRF_CPP_CONST->void WRF_CPP_NOEXCEPT(WRF_CPP_FALSE);

#ifdef DEBUG_VERBOSE
								WRF_CPP_VIRTUAL    auto   debug_print(_In_ WRF_CPP_CONST WRF_STRING &,
									                                  _In_ WRF_CPP_CONST WRF_INT,
									                                  _In_ WRF_CPP_CONST WRF_WSTRING &)WRF_CPP_CONST->void WRF_CPP_OVERRIDE;
#endif

								   /* Member variable ,
								      acceration graupel container,
									  values are in kgkg^-1s^-1*/
								   WRF_Mat2DF32 m_psacw;

							   };


					 /**********************************************************
					    Type double and type boost::multi_array<double,2>
					    specialization.
					    This structure models or rather contains the values
					    of accretion of cloud water by snow to form graupel.
					 ***********************************************************/
					 template<WRF_CPP_CONST WRF_ULONGLONG ims,
						      WRF_CPP_CONST WRF_ULONGLONG ime,
						      WRF_CPP_CONST WRF_ULONGLONG jms,
							  WRF_CPP_CONST WRF_ULONGLONG jme >   struct  Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
							                                                    wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme> final : public
																				ISpecies_base<wrf_physics::wrf_physics_internal::tags::float64_t_tag, wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag> {


								  /* data type - double
								  Container type - boost::multi_array*/

								  /**********************************
								  Constructor and destructor
								  ***********************************/

								  Psacw();

								  Psacw(_In_ WRF_CPP_CONST Psacw &);

								  Psacw(_In_ Psacw&&);

								WRF_CPP_VIRTUAL  ~Psacw() = WRF_CPP_DEFAULT;


								  /************************************
								         Class member operators
								  **************************************/

								  auto   operator=(_In_ WRF_CPP_CONST Psacw &)->Psacw &;

								  auto   operator=(_In_  Psacw &&)->Psacw &;

								  auto   operator==(_In_ WRF_CPP_CONST Psacw &)WRF_CPP_CONST->WRF_BOOL WRF_CPP_NOEXCEPT(WRF_CPP_FALSE);

								  auto   operator!=(_In_ WRF_CPP_CONST Psacw &)WRF_CPP_CONST->WRF_BOOL WRF_CPP_NOEXCEPT(WRF_CPP_FALSE);

								  auto   operator()(_In_ WRF_CPP_CONST WRF_ULONGLONG,
									                _In_ WRF_CPP_CONST WRF_ULONGLONG)WRF_CPP_CONST->WRF_CPP_CONST WRF_REAL64;

								  auto   operator()(_In_ WRF_CPP_CONST WRF_ULONGLONG,
									                _In_ WRF_CPP_CONST WRF_ULONGLONG)->WRF_REAL64;

								  auto   operator+=(_In_ WRF_CPP_CONST Psacw &)->Psacw &;

								  auto   operator-=(_In_ WRF_CPP_CONST Psacw &)->Psacw &;


								  /********************************
								    Class member functions
								  ********************************/
								  /* returns class typeid*/
								  WRF_CPP_VIRTUAL  auto   class_typeId()WRF_CPP_CONST->WRF_STRING WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) WRF_CPP_OVERRIDE;

								  /* returns class typeid, raw name and hashed name*/
								  WRF_CPP_VIRTUAL  auto   class_info()WRF_CPP_CONST->std::tuple<WRF_STRING, WRF_ULONGLONG, WRF_STRING>  WRF_CPP_OVERRIDE;

								  /* returns class tags description*/
								  WRF_CPP_VIRTUAL auto   class_tags()->WRF_CPP_CONST std::pair<WRF_STRING, WRF_STRING> WRF_CPP_OVERRIDE;

								  /* returns class member copied to smart pointer */
								  auto   toCPtr()->WRF_SHPTRF64 WRF_CPP_NOEXCEPT(WRF_CPP_FALSE);

								  /* number of array elements */
								  WRF_CPP_VIRTUAL auto   num_of_elements()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG WRF_CPP_NOEXCEPT(WRF_CPP_FALSE) WRF_CPP_OVERRIDE;

								  /* number of array dimensions*/
								  WRF_CPP_VIRTUAL auto   num_of_dimensions()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) WRF_CPP_OVERRIDE;

								  /* print object state.*/
								  WRF_CPP_VIRTUAL auto   print_object_state() WRF_CPP_CONST->void WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) WRF_CPP_OVERRIDE;

								  /* conversion to mks model*/
								  auto   convert_to_mks(_In_ KMSProdRatioF64 &) WRF_CPP_CONST->void WRF_CPP_NOEXCEPT(WRF_CPP_FALSE);
#ifdef DEBUG_VERBOSE
								  WRF_CPP_VIRTUAL auto   debug_print(_In_ WRF_CPP_CONST WRF_STRING &,
									                                 _In_ WRF_CPP_CONST WRF_INT,
													                 _In_ WRF_CPP_CONST WRF_WSTRING &)WRF_CPP_CONST->void WRF_CPP_OVERRIDE;
#endif

								  /***************************
								          Class members
								  ****************************/

								  /* Member variable ,
								  acceration graupel container,
								  values are in kgkg^-1s^-1*/

								  WRF_Mat2DF64 m_psacw;
							  };



					  
					 /*****************************************
					   struct Pigen templated on primitive type
					   data_t and on container type container_t
					   Primiary template.
					 ******************************************/
					 template<typename data_t,
					          class Container_t,
						      WRF_CPP_CONST WRF_ULONGLONG ims,
						      WRF_CPP_CONST WRF_ULONGLONG ime,
						      WRF_CPP_CONST WRF_ULONGLONG jms,
						      WRF_CPP_CONST WRF_ULONGLONG jme >  struct Pigen;


							  /*******************************************************
							     float and boost::multi_array<float,2> spcecialization
							  ********************************************************/
							  template< WRF_CPP_CONST WRF_ULONGLONG ims,
								        WRF_CPP_CONST WRF_ULONGLONG ime,
								        WRF_CPP_CONST WRF_ULONGLONG jms,
										WRF_CPP_CONST WRF_ULONGLONG jme >   struct Pigen<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
										                                                  wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme> final : public
							                                                                                                          ISpecies_base<wrf_physics::wrf_physics_internal::tags::float32_t_tag, 
																			                                                                 wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag> {
							                                                                          

											/********************************************
											          Constructor and Desructors
											*********************************************/

											/* Ctor member instantiation and null
											   initialization only (zero-fill)*/

											Pigen();

											/* Copy Ctor*/
											Pigen(_In_ WRF_CPP_CONST Pigen &);

											/* Move Ctor*/
											Pigen(_In_ Pigen &&);

											/* Default Dtor */
											WRF_CPP_VIRTUAL ~Pigen() = default;

											/**************************************
											         Class member operators
											***************************************/

											auto  operator=( _In_ WRF_CPP_CONST Pigen &)->Pigen &;

											auto  operator=( _In_ Pigen &&)->Pigen &;

											auto  operator==(_In_ WRF_CPP_CONST Pigen &)WRF_CPP_CONST->WRF_CPP_CONST WRF_BOOL WRF_CPP_NOEXCEPT(WRF_CPP_FALSE);

											auto  operator!=(_In_ WRF_CPP_CONST Pigen &)WRF_CPP_CONST->WRF_CPP_CONST WRF_BOOL WRF_CPP_NOEXCEPT(WRF_CPP_FALSE);

											auto   operator()(_In_ WRF_CPP_CONST WRF_ULONGLONG,
												              _In_ WRF_CPP_CONST WRF_ULONGLONG)WRF_CPP_CONST->WRF_CPP_CONST WRF_REAL32;

											auto   operator()(_In_ WRF_CPP_CONST WRF_ULONGLONG,
												              _In_ WRF_CPP_CONST WRF_ULONGLONG)->WRF_REAL32;

											auto   operator+=(_In_ WRF_CPP_CONST Pigen &)->Pigen<decltype(Pigen{}+Pigen{}), wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme> &;

											auto   operator-=(_In_ WRF_CPP_CONST Pigen &)->Pigen<decltype(Pigen{}-Pigen{}), wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme> &;


											/******************************************
											         Class member functions
											*******************************************/

											/* returns class typeid*/
											
										WRF_CPP_VIRTUAL	auto  class_typeId()WRF_CPP_CONST->WRF_STRING 
											                           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) WRF_CPP_OVERRIDE;

											/* returns class typeid, raw name and hashed name*/
										WRF_CPP_VIRTUAL	auto   class_info()WRF_CPP_CONST->
											                   std::tuple<WRF_STRING, WRF_ULONGLONG, WRF_STRING> WRF_CPP_OVERRIDE;

											/* returns class tags description*/
										WRF_CPP_VIRTUAL	auto   class_tags()->WRF_CPP_CONST 
											                   std::pair<WRF_STRING, WRF_STRING> WRF_CPP_OVERRIDE;

											/* returns class member copied to smart pointer */
										            	auto   toCPtr()->WRF_SHPTRF32 WRF_CPP_NOEXCEPT(WRF_CPP_FALSE);

											/* number of array elements */
										WRF_CPP_VIRTUAL	auto   num_of_elements()WRF_CPP_CONST->WRF_CPP_CONST 
											                   WRF_ULONGLONG WRF_CPP_NOEXCEPT(WRF_CPP_FALSE) WRF_CPP_OVERRIDE;

											/* number of array dimensions*/
										WRF_CPP_VIRTUAL	auto   num_of_dimensions()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) WRF_CPP_OVERRIDE;

											/* print object state.*/
										WRF_CPP_VIRTUAL	auto   print_object_state() WRF_CPP_CONST->void WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) WRF_CPP_OVERRIDE;

											/* conversion to mks model*/
											auto   convert_to_mks(_In_ KMSProdRatioF64 &) WRF_CPP_CONST->void WRF_CPP_NOEXCEPT(WRF_CPP_FALSE);
#ifdef DEBUG_VERBOSE
										WRF_CPP_VIRTUAL	auto   debug_print(_In_ WRF_CPP_CONST WRF_STRING &,
												                           _In_ WRF_CPP_CONST WRF_INT,
												                           _In_ WRF_CPP_CONST WRF_WSTRING &)WRF_CPP_CONST->void WRF_CPP_VIRTUAL;
#endif







											/***************************
											        Member variables
											******************************/

											WRF_Mat2DF32 m_pigen;

										};


						 /************************************************************
											  Global namespace operators
						*************************************************************/
						 template< WRF_CPP_CONST WRF_ULONGLONG ims,
							       WRF_CPP_CONST WRF_ULONGLONG ime,
							       WRF_CPP_CONST WRF_ULONGLONG jms,
							       WRF_CPP_CONST WRF_ULONGLONG jme >
							                                         auto  operator<<(_In_ std::ostream &, _In_ WRF_CPP_CONST Psacw<wrf_physics::wrf_physics_internal::tags::float32_t_tag,
							                                                           wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme> &)->std::ostream &;


						 template< WRF_CPP_CONST WRF_ULONGLONG ims,
							       WRF_CPP_CONST WRF_ULONGLONG ime,
							       WRF_CPP_CONST WRF_ULONGLONG jms,
							       WRF_CPP_CONST WRF_ULONGLONG jme >
							                                        auto  operator<<(_In_ std::ostream &, _In_ WRF_CPP_CONST Psacw<wrf_physics::wrf_physics_internal::tags::float64_t_tag,
							                                                          wrf_physics::wrf_physics_internal::tags::dyn_container_boost_t_tag, ims, ime, jms, jme> &)->std::ostream &;
							


					




#include "Module_mp_wsm_iface.inl"
		}
	}
}

#endif /* MODULE_MP_WSM_IFACE_H_*/