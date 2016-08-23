
#ifndef _WRF_CPU_ARCH_TRAITS_HPP_
#define _WRF_CPU_ARCH_TRAITS_HPP_

#ifndef WRF_CPP_ARCH_TRAITS_VERSION_MAJOR
#define WRF_CPP_ARCH_TRAITS_VERSION_MAJOR 1
#endif

#ifndef WRF_CPP_ARCH_TRAITS_VERSION_MINOR
#define WRF_CPP_ARCH_TRAITS_VERSION_MINOR 0
#endif

#ifndef WRF_CPP_ARCH_TRAITS_CREATE_DATE
#define WRF_CPP_ARCH_TRAITS_CREATE_DATE 20160726
#endif

/* Set this value to last successful build date*/
#ifndef WRF_CPP_ARCH_TRAITS_BUILD_DATE
#define WRF_CPP_ARCH_TRAITS_BUILD_DATE 0
#endif

#include "WRF_PHYS_LIB_TYPEDEFS.h"
#include "Wrf_cpu_arch_tags.hpp"
#include "Wrf_type_aliases.hpp"

namespace wrf_physics {

	namespace  wrf_physics_internal {

		                namespace traits {


			/*********************************
			 Type traits of CPU architectures
			*********************************/

			/* Primary template*/
			template<class CpuArch_t>
			    struct  Is_cpu_arch_0F_03_t final :
				    public  std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {

			};

				/* partial specialization on tag
				   cpu_arch_0F_03_t_tag*/
            template<>
			    struct  Is_cpu_arch_0F_03_t<wrf_physics::
					           wrf_physics_internal::tags::cpu_arch_0F_03_t_tag> final : 
				public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE> {


				};

             template<class CpuArch_t>
			 struct  Is_cpu_arch_0F_02_t final :
				 public   std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			 };


			 template<>
			      struct Is_cpu_arch_0F_02_t<wrf_physics::
					            wrf_physics_internal::tags::cpu_arch_0F_02_t_tag> final : 
				  public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


				  };

             template<class CpuArch_t>
			 struct Is_cpu_arch_06_2A_t final :
				 public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			 };

			 template<>
			        struct Is_cpu_arch_06_2A_t<wrf_physics::
						          wrf_physics_internal::tags::cpu_arch_06_2A_t_tag> final : 
					public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


					};

             template<class CpuArch_t>
			 struct Is_cpu_arch_06_2D_t final :
				 public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {

			 };

			 template<>
			        struct Is_cpu_arch_06_2D_t<wrf_physics::
						          wrf_physics_internal::tags::cpu_arch_06_2D_t_tag> final : 
					public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


					};

              template<class CpuArch_t>
			  struct Is_cpu_arch_06_3A_t final :
				  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			  };

			  template<>
			         struct Is_cpu_arch_06_3A_t<wrf_physics::
						 wrf_physics_internal::tags::cpu_arch_06_3A_t_tag> final : 
					 public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


					 };

              template<class CpuArch_t>
			  struct Is_cpu_arch_06_3C_t final :
				  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			  };

			  template<>
			         struct Is_cpu_arch_06_3C_t<wrf_physics::
						 wrf_physics_internal::tags::cpu_arch_06_3C_t_tag> final : 
					 public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


					 };

              template<class CpuArch_t>
			  struct Is_cpu_arch_06_3E_t final :
				  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			  };

			  template<>
			          struct Is_cpu_arch_06_3E_t<wrf_physics::
						  wrf_physics_internal::tags::cpu_arch_06_3E_t_tag> final : 
					  public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


					  };

              template<class CpuArch_t>
			  struct Is_cpu_arch_06_45_t final :
				  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			  };

			  template<>
			         struct Is_cpu_arch_06_45_t<wrf_physics::
						 wrf_physics_internal::tags::cpu_arch_06_45_t_tag> final : 
					 public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


					 };

              template<class CpuArch_t>
			  struct Is_cpu_arch_06_46_t final :
				  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			  };

			  template<>
			         struct Is_cpu_arch_06_46_t<wrf_physics::
						  wrf_physics_internal::tags::cpu_arch_06_46_t_tag> final : 
					                  public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


					 };

               template<class CpuArch_t>
			   struct Is_cpu_arch_06_25_t final :
				   public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			   };

			   template<>
			          struct Is_cpu_arch_06_25_t<wrf_physics::
						  wrf_physics_internal::tags::cpu_arch_06_25_t_tag> final : 
					  public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


					  };

                template<class CpuArch_t>
				struct Is_cpu_arch_06_2C_t final :
					public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


				};

				template<>
				       struct Is_cpu_arch_06_2C_t<wrf_physics::
						   wrf_physics_internal::tags::cpu_arch_06_2C_t_tag> final :
					   public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


					   };

                 template<class CpuArch_t>
				 struct Is_cpu_arch_06_1A_t final :
					 public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


				 };

				 template<>
				        struct Is_cpu_arch_06_1A_t<wrf_physics::
							wrf_physics_internal::tags::cpu_arch_06_1A_t_tag> final : 
						public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


						};

                  template<class CpuArch_t>
				  struct Is_cpu_arch_06_1E_t final :
					  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


				  };

				  template<>
				         struct Is_cpu_arch_06_1E_t<wrf_physics::
							 wrf_physics_internal::tags::cpu_arch_06_1E_t_tag> final : 
						 public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


						 };

                  template<class CpuArch_t>
				  struct Is_cpu_arch_06_1F_t final :
					  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


				  };

				  template<>
				         struct Is_cpu_arch_06_1F_t<wrf_physics::
							 wrf_physics_internal::tags::cpu_arch_06_1F_t_tag> final : 
						 public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


						 };

                  template<class CpuArch_t>
				  struct Is_cpu_arch_06_2E_t final :
					  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


				  };

				  template<>
				         struct Is_cpu_arch_06_2E_t<wrf_physics::
							 wrf_physics_internal::tags::cpu_arch_06_2E_t_tag> final : 
						 public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


						 };

                  template<class CpuArch_t>
				  struct Is_cpu_arch_06_2F_t final :
					  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


				  };

				  template<>
				          struct Is_cpu_arch_06_2F_t<wrf_physics::
							  wrf_physics_internal::tags::cpu_arch_06_2F_t_tag> final : 
						  public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


						  };

                  template<class CpuArch_t>
				  struct Is_cpu_arch_06_17_t final :
					  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


				  };

				  template<>
				         struct Is_cpu_arch_06_17_t<wrf_physics::
							 wrf_physics_internal::tags::cpu_arch_06_17_t_tag> final : 
						 public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


						 };

                  template<class CpuArch_t>
				  struct Is_cpu_arch_06_1D_t final :
					  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


				  };

				  template<>
				          struct Is_cpu_arch_06_1D_t<wrf_physics::
							  wrf_physics_internal::tags::cpu_arch_06_1D_t_tag> final : 
						  public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


						  };

                  template<class CpuArch_t>
				  struct Is_cpu_arch_06_0F_t final :
					  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


				  };

				  template<>
				         struct Is_cpu_arch_06_0F_t<wrf_physics::
							 wrf_physics_internal::tags::cpu_arch_06_0F_t_tag> final : 
						 public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


						 };

                  template<class CpuArch_t>
				  struct Is_cpu_arch_sandy_bridge_t final :
					  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


				  };

				  template<>
				         struct Is_cpu_arch_sandy_bridge_t<wrf_physics::
						   wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag> final : 
						 public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


						 };

                  template<class CpuArch_t>
				  struct Is_cpu_arch_ivy_bridge_t final :
					  public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


				  };

				  template<>
				         struct Is_cpu_arch_ivy_bridge_t<wrf_physics::
							   wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag> final : 
						 public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


						 };

                   template<class CpuArch_t>
				   struct Is_cpu_arch_haswell_t final :
					   public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


				   };

				   template<>
				          struct Is_cpu_arch_haswell_t<wrf_physics::
							  wrf_physics_internal::tags::cpu_arch_haswell_t_tag> final :
						  public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


						  };

						 namespace global_cpu_arch_funcs {

							 /********************************************
							  Convenience global functions
							  for testing specific partial specialization.
							 **********************************************/

							 template<class CpuArch_t>
							        constexpr WRF_BOOL Is_cpu_arch_0F_03_() 
								                 WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) {

								         return (Is_cpu_arch_0F_03_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							        constexpr WRF_BOOL Is_cpu_arch_0F_02_()
								                 WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) {

									     return (Is_cpu_arch_0F_02_t<CpuArch_t>::value);
								 }

                             template<class CpuArch_t>
							        constexpr WRF_BOOL Is_cpu_arch_06_2A_()
								                 WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) {

									     return (Is_cpu_arch_06_2A_t<CpuArch_t>::value);
								 }

                             template<class CpuArch_t>
							        constexpr WRF_BOOL Is_cpu_arch_06_2D_()
								                 WRF_CPP_NOEXCEPT(WRF_CPP_TRUE) {

									     return (Is_cpu_arch_06_2D_t<CpuArch_t>::value);
								 }

                             template<class CpuArch_t>
							          auto Is_cpu_arch_06_3A_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                            std::enable_if<std::is_class<CpuArch_t>::
								                                           value, constexpr WRF_BOOL>::type {

										return (Is_cpu_arch_06_3A_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							         auto Is_cpu_arch_06_3C_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                          std::enable_if<std::is_class<CpuArch_t>::
														                        value, constexpr WRF_BOOL>::type {

										 return (Is_cpu_arch_06_3C_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							         auto Is_cpu_arch_06_3E_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                          std::enable_if<std::is_class<CpuArch_t>::
														                        value, constexpr WRF_BOOL>::type {
										  
										 return (Is_cpu_arch_06_3E_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							          auto Is_cpu_arch_06_45_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                           std::enable_if<std::is_class<CpuArch_t>::
														                         value, constexpr WRF_BOOL>::type {

										  return (Is_cpu_arch_06_45_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							          auto Is_cpu_arch_06_46_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                            std::enable_if<std::is_class<CpuArch_t>::
															                      value, constexpr WRF_BOOL>::type {

								 return (Is_cpu_arch_06_46_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							          auto Is_cpu_arch_06_25_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                            std::enable_if<std::is_class<CpuArch_t>::
															                      value, constexpr WRF_BOOL>::type {

										  return (Is_cpu_arch_06_25_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							          auto Is_cpu_arch_06_2C_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                            std::enable_if<std::is_class<CpuArch_t>::
															                      value, constexpr WRF_BOOL>::type {

								 return (Is_cpu_arch_06_2C_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							         auto Is_cpu_arch_06_1A_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                           WRF_ENABLE_IF<std::is_class<CpuArch_t>::
														                      value, constexpr WRF_BOOL> {

										 return (Is_cpu_arch_06_1A_t<CpuArch_t>::value);
							 }

                              
                             template<class CpuArch_t>
							         auto Is_cpu_arch_06_1E_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                          WRF_ENABLE_IF<WRF_IS_CLASS<CpuArch_t>::
														                     value, constexpr WRF_BOOL> {

										 return (Is_cpu_arch_06_1E_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							         auto Is_cpu_arch_06_1F_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                          WRF_ENABLE_IF<WRF_IS_CLASS<CpuArch_t>::
														                    value, constexpr WRF_BOOL> {

										 return (Is_cpu_arch_06_1F_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							          auto Is_cpu_arch_06_2E_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                           WRF_ENABLE_IF<WRF_IS_CLASS<CpuArch_t>::
														                     value, constexpr WRF_BOOL> {

										  return (Is_cpu_arch_06_2E_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							          auto Is_cpu_arch_06_2F_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                           WRF_ENABLE_IF<WRF_IS_CLASS<CpuArch_t>::
														                     value, constexpr WRF_BOOL> {

										  return (Is_cpu_arch_06_2F_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							         auto Is_cpu_arch_06_17_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                           WRF_ENABLE_IF<WRF_IS_CLASS<CpuArch_t>::
														                    value, constexpr WRF_BOOL> {

										 return (Is_cpu_arch_06_17_t<CpuArch_t>::value);
							 }

                             template<class CpuArch_t>
							          auto Is_cpu_arch_06_1D_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                            WRF_ENABLE_IF<WRF_IS_CLASS<CpuArch_t>::
															                value, constexpr WRF_BOOL> {

										  return (Is_cpu_arch_06_1D_t<CpuArch_t>::value);
							 }


							template<class CpuArch_t>
							         auto Is_cpu_arch_06_0F_()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								                           WRF_ENABLE_IF<WRF_IS_CLASS<CpuArch_t>::
														                   value, constexpr WRF_BOOL> {

										 return (Is_cpu_arch_06_0F_t<CpuArch_t>::value);
							}



						 } // global_funcs

		}
	}
}




#endif /*_WRF_CPU_ARCH_TRAITS_HPP_*/