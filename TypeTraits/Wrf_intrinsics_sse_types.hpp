


#if CPU_HAS_SSE_ONLY == 0x1

#ifndef __WRF_INTRINSICS_SSE_TYPES_HPP__
#define __WRF_INTRINSICS_SSE_TYPES_HPP__

#ifndef WRF_INTRINSICS_SSE_TYPES_VERSION_MAJOR
#define WRF_INTRINSICS_SSE_TYPES_VERSION_MAJOR 1
#endif

#ifndef WRF_INTRINSICS_SSE_TYPES_VERSION_MINOR
#define WRF_INTRINSICS_SSE_TYPES_VERSION_MINOR 0
#endif

#ifndef WRF_INTRINSICS_SSE_TYPES_CREATE_DATE
#define WRF_INTRINSICS_SSE_TYPES_CREATE_DATE 20160730
#endif

/* Set this value to successful build date*/
#ifndef WRF_INTRINSICS_SSE_TYPES_BUILD_DATE
#define WRF_INTRINSICS_SSE_TYPES_BUILD_DATE 0
#endif

#include "Wrf_cpu_arch_tags.hpp"
#include "Wrf_intrinsics_config.hpp"
#include "Wrf_intrinsics_tags.hpp"
#include "Wrf_type_aliases.hpp"
#include "WRF_PHYS_LIB_TYPEDEFS.h"


namespace  wrf_physics {

	namespace wrf_physics_internal {

		namespace sse_intrinsic_traits{
		
		/********************************************
		   Intrinsic SSE Arithmetic type
		  Compile time structure describes number
		  of CPU cycles consumed by the execution
		  units, and describes reciprocal throughput
		  (latency) in CPU cycles.
		  Primarily template.
		  Template arguments:
		  1) Config template structure
		  2) CpuArch_t - tag dispatch
		  3) Arithmetic subtype - tag dispatch.
		*********************************************/

		template<class Config, 
		               class CpuType_t, 
					         class Operation_t > struct SSE_Arithmetic;


							 /*******************************
							      Partial specializations on
								  tag dipatch CpuType_t and
								  Operation_t.
							 *********************************/

							 template<class Config>
							         struct SSE_Arithmetic<Config, wrf_physics::
										             wrf_physics_internal::tags::cpu_arch_06_0F_t_tag,
								                                 wrf_physics::wrf_physics_internal::tags::
														                                  sse_mm_add_ps_t_tag> {

										 /*********************
										       Members
										 **********************/
										 typedef typename Config::CpuCycles CYCLES;

										 typedef typename Config::ReciprocalThroughput LATENCY;

										 static constexpr CYCLES  m_cycles = static_cast<typename Config::CpuCycles>(3);

										 static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

										 static auto get_cycles()
											   WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->constexpr CYCLES
										                                          { return (m_cycles); }
										 
										 static auto get_latency()
											    WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->constexpr LATENCY 
										                                          { return (m_latency); }

										 static auto get_intrinsic_type()->
											             std::pair<WRF_CPP_CONST WRF_STRING,
											                                WRF_CPP_CONST WRF_STRING> {

											 using namespace wrf_physics::wrf_physics_internal::tags;
											 return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
												                    WRF_STRING{ typeid(cpu_arch_06_0F_t_tag).name() }));
										 }
							 };

                            template<class Config>
							       struct SSE_Arithmetic<Config, wrf_physics::
								              wrf_physics_internal::tags::cpu_arch_06_0E_t_tag,
								                          wrf_physics::wrf_physics_internal::tags::
														                             sse_mm_add_ps_t_tag> {

									   /*************************
									         Local typedefs
									   **************************/

									   typedef typename Config::CpuCycles CYCLES;

									   typedef typename Config::ReciprocalThroughput LATENCY;

									   static constexpr CYCLES m_cycles  = static_cast<typename Config::CpuCycles>(4);

									   static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(2);

									   static auto get_cycles()
										           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												              constexpr CYCLES { return (m_latency); }

									   static auto get_latency()
										           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												              constexpr LATENCY { return (m_latency); }

									   static auto get_intrinsic_type()->
										               std::pair<WRF_CPP_CONST WRF_STRING,
										                                       WRF_CPP_CONST WRF_STRING> {

										   using namespace wrf_physics::wrf_physics_internal::tags;
										   return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
											                      WRF_STRING{ typeid(cpu_arch_06_0E_t_tag).name() }));
									   }
										   
							};

                            template<class Config>
							       struct SSE_Arithmetic<Config, wrf_physics::
								              wrf_physics_internal::tags::cpu_arch_06_0D_t_tag,
								                             wrf_physics::wrf_physics_internal::tags::
												                                        sse_mm_add_ps_t_tag> {

									   /**************************
									            Local typedefs
									   ***************************/

									   typedef typename Config::CpuCycles CYCLES;

									   typedef typename Config::ReciprocalThroughput LATENCY;

									   static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(4);

									   static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(2);

									   static auto get_cycles()
										           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												             constexpr CYCLES { return (m_cycles); }

									   static auto get_latency()
										           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												             constexpr LATENCY { return (m_latency); }

									   static auto get_intrinsic_type()->
										               std::pair<WRF_CPP_CONST WRF_STRING,
										                                 WRF_CPP_CONST WRF_STRING> {

										   using namespace wrf_physics::wrf_physics_internal::tags;
										   return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
											                      WRF_STRING{ typeid(cpu_arch_06_0D_t_tag).name() }));
									   }
							};

                            template<class Config>
							       struct SSE_Arithmetic<Config, wrf_physics::
								                  wrf_physics_internal::tags::cpu_arch_06_17_t_tag,
								                              wrf_physics::wrf_physics_internal::tags::
															                           sse_mm_add_ps_t_tag> {

									   /*************************
									            Members
									   **************************/
									   typedef typename Config::CpuCycles CYCLES;

									   typedef typename Config::ReciprocalThroughput LATENCY;

									   static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

									   static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

									   static auto get_cycles()
										      WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->constexpr CYCLES 
									                                             { return (m_cycles); }

									   static auto get_latency()
										      WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->constexpr LATENCY 
									                                             { return (m_latency); }

									   static auto get_intrinsic_type()->
										               std::pair<WRF_CPP_CONST WRF_STRING,
										                                 WRF_CPP_CONST WRF_STRING> {

										   using namespace wrf_physics::wrf_physics_internal::tags;
										   return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
											                      WRF_STRING{ typeid(cpu_arch_06_17_t_tag).name() }));
									   }
									   
							};

                            template<class Config>
							       struct SSE_Arithmetic<Config, wrf_physics::
								                  wrf_physics_internal::tags::cpu_arch_06_1A_t_tag,
								                              wrf_physics::wrf_physics_internal::tags::
															                          sse_mm_add_ps_t_tag> {

									   /******************
									         Members
									   *******************/
									   typedef typename Config::CpuCycles CYCLES;

									   typedef typename Config::ReciprocalThroughput LATENCY;

									   static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

									   static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

									   static auto get_cycles()
										      WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->constexpr CYCLES 
									                                             { return (m_cycles); }

									   static auto get_latency()
										      WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->constexpr LATENCY 
									                                             { return (m_latency); }

									   static auto get_intrinsic_type()->
										               std::pair<WRF_CPP_CONST WRF_STRING,
										                                 WRF_CPP_CONST WRF_STRING> {

										   using namespace wrf_physics::wrf_physics_internal::tags;
										   return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
											                      WRF_STRING{ typeid(cpu_arch_06_1A_t_tag).name() }));
									   }
							};

                           template<class Config>
						          struct SSE_Arithmetic<Config, wrf_physics::
							                     wrf_physics_internal::tags::cpu_arch_06_1D_t_tag,
							                                  wrf_physics::wrf_physics_internal::tags::
															                               sse_mm_add_ps_t_tag> {

									  /****************************
									              Members
									  ******************************/
									  typedef typename Config::CpuCycles CYCLES;

									  typedef typename Config::ReciprocalThroughput LATENCY;

									  static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

									  static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

									  static auto get_cycles()
										     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											          constexpr CYCLES { return (m_cycles); }

									  static auto get_latency()
										     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											          constexpr LATENCY { return (m_latency); }

									  static auto get_intrinsic_type()->
										              std::pair<WRF_CPP_CONST WRF_STRING,
										                                      WRF_CPP_CONST WRF_STRING> {

										  using namespace wrf_physics::wrf_physics_internal::tags;
										  return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
											                     WRF_STRING{ typeid(cpu_arch_06_1D_t_tag).name() }));
									  }
						   };

                           template<class Config>
						          struct SSE_Arithmetic<Config, wrf_physics::
							                    wrf_physics_internal::tags::cpu_arch_06_1E_t_tag,
							                               wrf_physics::wrf_physics_internal::tags::
							                                                         sse_mm_add_ps_t_tag> {

									  /**********************
									           Members
									  ************************/
									  typedef typename Config::CpuCycles CYCLES;

									  typedef typename Config::ReciprocalThroughput LATENCY;

									  static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

									  static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

									  static auto get_cycles()
										     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											          constexpr CYCLES { return (m_cycles); }

									  static auto get_latency()
										     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											           constexpr LATENCY { return (m_latency); }

									  static auto get_intrinsic_type()->
										               std::pair<WRF_CPP_CONST WRF_STRING,
										                                       WRF_CPP_CONST WRF_STRING> {

										  using namespace wrf_physics::wrf_physics_internal::tags;
										  return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
											                     WRF_STRING{ typeid(cpu_arch_06_1E_t_tag).name() }));
									  }
						   };

                           template<class Config>
						          struct SSE_Arithmetic<Config, wrf_physics::
							                     wrf_physics_internal::tags::cpu_arch_06_1F_t_tag,
							                                wrf_physics::wrf_physics_internal::tags::
							                                                         sse_mm_add_ps_t_tag> {

									  /*************************
									              Members
									  ***************************/
									  typedef typename Config::CpuCycles CYCLES;

									  typedef typename Config::ReciprocalThroughput LATENCY;

									  static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

									  static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

									  static auto get_cycles()
										     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											          constexpr CYCLES { return (m_cycles); }

									  static auto get_latency()
										     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											           constexpr LATENCY { return (m_latency); }

									  static auto get_intrinsic_type()->
										              std::pair<WRF_CPP_CONST WRF_STRING,
										                                WRF_CPP_CONST WRF_STRING> {

										  using namespace wrf_physics::wrf_physics_internal::tags;
										  return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
											                     WRF_STRING{ typeid(cpu_arch_06_1F_t_tag).name() }));
									  }
						   };

                           template<class Config>
						          struct SSE_Arithmetic<Config, wrf_physics::
							                     wrf_physics_internal::tags::cpu_arch_06_25_t_tag,
							                                wrf_physics::wrf_physics_internal::tags::
							                                                          sse_mm_add_ps_t_tag> {

									  /***************************
									             Members
									  ****************************/
									  typedef typename Config::CpuCycles CYCLES;

									  typedef typename Config::ReciprocalThroughput LATENCY;

									  static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

									  static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

									  static auto get_cycles()
										     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											            constexpr CYCLES { return (m_cycles); }

									  static auto get_latency()
										     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											            constexpr LATENCY { return (m_latency); }

									  static auto get_intrinsic_type()->
										              std::pair<WRF_CPP_CONST WRF_STRING,
										                                WRF_CPP_CONST WRF_STRING> {

										  using namespace wrf_physics::wrf_physics_internal::tags;
										  return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
											                     WRF_STRING{ typeid(cpu_arch_06_25_t_tag).name() }));
									  }
						   };

                          template<class Config>
						         struct SSE_Arithmetic<Config, wrf_physics::
							                    wrf_physics_internal::tags::cpu_arch_06_2A_t_tag,
							                                wrf_physics::wrf_physics_internal::tags::
													                                 sse_mm_add_ps_t_tag> {

									 /***********************
									         Members
									 ************************/
									 typedef typename Config::CpuCycles CYCLES;

									 typedef typename Config::ReciprocalThroughput LATENCY;

									 static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

									 static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

									 static auto get_cycles()
										    WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											        constexpr CYCLES { return (m_cycles); }

									 static auto get_latency()
										    WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											        constexpr LATENCY { return (m_latency); }

									 static auto get_intrinsic_type()->
										             std::pair<WRF_CPP_CONST WRF_STRING,
										                               WRF_CPP_CONST WRF_STRING> {

										 using namespace wrf_physics::wrf_physics_internal::tags;
										 return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
											                    WRF_STRING{ typeid(cpu_arch_06_2A_t_tag).name() }));
									 }
						  };

                         template<class Config>
						        struct SSE_Arithmetic<Config, wrf_physics::
							                  wrf_physics_internal::tags::cpu_arch_06_2C_t_tag,
							                              wrf_physics::wrf_physics_internal::tags::
														                              sse_mm_add_ps_t_tag> {

									/*********************
									        Members
									**********************/
									typedef typename Config::CpuCycles CYCLES;

									typedef typename Config::ReciprocalThroughput LATENCY;

									static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

									static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

									static auto get_cycles()
										   WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										           constexpr CYCLES { return (m_cycles); }

									static auto get_latency()
										   WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										           constexpr LATENCY { return (m_latency); }

									static auto get_intrinsic_type()->
										            std::pair<WRF_CPP_CONST WRF_STRING,
										                            WRF_CPP_CONST WRF_STRING> {

										using namespace wrf_physics::wrf_physics_internal::tags;
										return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
											                   WRF_STRING{ typeid(cpu_arch_06_2C_t_tag).name() }));
									}
						 };

                        template<class Config>
						       struct SSE_Arithmetic<Config, wrf_physics::
							              wrf_physics_internal::tags::cpu_arch_06_2D_t_tag,
							                          wrf_physics::wrf_physics_internal::tags::
							                                                      sse_mm_add_ps_t_tag> {

								   /***************************
								          local typedefs
								   **************************/
								   typedef typename Config::CpuCycles CYCLES;

								   typedef typename Config::ReciprocalThroughput LATENCY;

								   static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

								   static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

								   static auto get_cycles()
									      WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										          constexpr CYCLES { return (m_cycles); }

								   static auto get_latency()
									      WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										          constexpr LATENCY { return (m_latency); }

								   static auto get_intrinsic_type()->
									               std::pair<WRF_CPP_CONST WRF_STRING,
									                                 WRF_CPP_CONST WRF_STRING> {

									   using namespace wrf_physics::wrf_physics_internal::tags;
									   return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
										                      WRF_STRING{ typeid(cpu_arch_06_2D_t_tag).name() }));
								   }

						};

                        template<class Config>
						       struct SSE_Arithmetic<Config, wrf_physics::
							             wrf_physics_internal::tags::cpu_arch_06_2E_t_tag,
							                         wrf_physics::wrf_physics_internal::tags::
							                                                   sse_mm_add_ps_t_tag> {

								   /***********************
								        local typedefs
								   ***********************/
								   
								   typedef typename Config::CpuCycles CYCLES;

								   typedef typename Config::ReciprocalThroughput LATENCY;

								  

								   static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

								   static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

								   static auto get_cycles()
									      WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										           constexpr CYCLES { return (m_cycles); }

								   static auto get_latency()
									      WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										           constexpr LATENCY { return (m_latency); }

								   static auto get_intrinsic_type()->
									              std::pair<WRF_CPP_CONST WRF_STRING,
									                              WRF_CPP_CONST WRF_STRING> {

									   using namespace wrf_physics::wrf_physics_internal::tags;
									   return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
										                      WRF_STRING{ typeid(cpu_arch_06_2E_t_tag).name() }));
								   }
						};
								    
                       template<class Config>
					          struct SSE_Arithmetic<Config, wrf_physics::
						                wrf_physics_internal::tags::cpu_arch_06_2F_t_tag,
						                          wrf_physics::wrf_physics_internal::tags::
												                           sse_mm_add_ps_t_tag> {

								  /*************************
								          local typedefs
								  **************************/

								  

								  typedef typename Config::CpuCycles CYCLES;

								  typedef typename Config::ReciprocalThroughput LATENCY;

								  static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

								  static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

								  static auto get_cycles()
									     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										           constexpr CYCLES { return (m_cycles); }

								  static auto get_latency()
									     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									               constexpr LATENCY { return (m_latency); }

								  static auto get_intrinsic_type()->
									              std::pair<WRF_CPP_CONST WRF_STRING,
									                               WRF_CPP_CONST WRF_STRING> {

									  using namespace wrf_physics::wrf_physics_internal::tags;
									  return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
										                     WRF_STRING{ typeid(cpu_arch_06_2F_t_tag).name() }));
								  }

					   };

                       template<class Config>
					          struct SSE_Arithmetic<Config, wrf_physics::
						                 wrf_physics_internal::tags::cpu_arch_06_3A_t_tag,
						                              wrf_physics::wrf_physics_internal::tags::
													                             sse_mm_add_ps_t_tag> {

								  /************************
								        local typedefs
								  *************************/

								  typedef typename Config::CpuCycles CYCLES;

								  typedef typename Config::ReciprocalThroughput LATENCY;

								  static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

								  static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

								  static auto get_cycles()
									     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										         constexpr CYCLES { return (m_cycles); }

								  static auto get_latency()
									     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										         constexpr LATENCY { return (m_latency); }

								  static auto get_intrinsic_type()->
									              std::pair<WRF_CPP_CONST WRF_STRING,
									                                  WRF_CPP_CONST WRF_STRING> {

									  using namespace wrf_physics::wrf_physics_internal::tags;
									  return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
										                     WRF_STRING{ typeid(cpu_arch_06_3A_t_tag).name() }));
								  }
					   };

                       template<class Config>
					          struct SSE_Arithmetic<Config, wrf_physics::
						                 wrf_physics_internal::tags::cpu_arch_06_3C_t_tag,
						                              wrf_physics::wrf_physics_internal::tags::
						                                                        sse_mm_add_ps_t_tag> {

								  /**************************
								        Local typedefs
								  ***************************/

								  typedef typename  Config::CpuCycles CYCLES;

								  typedef typename  Config::ReciprocalThroughput LATENCY;

								  static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

								  static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

								  static auto get_cycles()
									     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										         constexpr CYCLES { return (m_cycles); }

								  static auto get_latency()
									     WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										         constexpr LATENCY { return (m_latency); }

								  static auto get_intrinsic_type()->
									              std::pair<WRF_CPP_CONST WRF_STRING,
									                                WRF_CPP_CONST WRF_STRING> {

									  using namespace wrf_physics::wrf_physics_internal::tags;
									  return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
										                     WRF_STRING{ typeid(cpu_arch_06_3C_t_tag).name() }));
								  }
					   };

                      template<class Config>
					         struct SSE_Arithmetic<Config, wrf_physics::
						                wrf_physics_internal::tags::cpu_arch_06_3E_t_tag,
						                            wrf_physics::wrf_physics_internal::tags::
						                                                      sse_mm_add_ps_t_tag> {

								 /*****************************
								         local typedefs
								 ******************************/

								 typedef typename Config::CpuCycles CYCLES;

								 typedef typename Config::ReciprocalThroughput LATENCY;

								 static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

								 static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

								 static auto get_cycles()
									    WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										         constexpr CYCLES { return (m_cycles); }

								 static auto get_latency()
									    WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										         constexpr LATENCY { return (m_latency); }

								 static auto get_intrinsic_type()->
									              std::pair<WRF_CPP_CONST WRF_STRING,
									                                 WRF_CPP_CONST WRF_STRING> {

									 using namespace wrf_physics::wrf_physics_internal::tags;
									 return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
										                    WRF_STRING{ typeid(cpu_arch_06_3E_t_tag).name() }));
								 }

					  };

                      template<class Config>
					         struct SSE_Arithmetic<Config, wrf_physics::
						                wrf_physics_internal::tags::cpu_arch_06_45_t_tag,
						                            wrf_physics::wrf_physics_internal::tags::
													                          sse_mm_add_ps_t_tag> {

								 /*************************
								       Local typedefs
								 ***************************/

								 typedef typename Config::CpuCycles CYCLES;

								 typedef typename Config::ReciprocalThroughput LATENCY;

								 static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

								 static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

								 static auto get_cycles()
									    WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										          constexpr CYCLES { return (m_cycles); }

								 static auto get_latency()
									    WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										          constexpr LATENCY { return (m_latency); }

								 static auto get_intrinsic_type()->
									               std::pair<WRF_CPP_CONST WRF_STRING,
									                                 WRF_CPP_CONST WRF_STRING > {

									 using namespace wrf_physics::wrf_physics_internal::tags;
									 return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
										                    WRF_STRING{ typeid(cpu_arch_06_45_t_tag).name() }));
								 }
					  };

                      template<class Config>
					         struct SSE_Arithmetic<Config, wrf_physics::
						                wrf_physics_internal::tags::cpu_arch_06_46_t_tag,
						                            wrf_physics::wrf_physics_internal::tags::
													                           sse_mm_add_ps_t_tag> {

								 /**************************
								        Local typedefs
								 ***************************/

								 typedef typename Config::CpuCycles CYCLES;

								 typedef typename Config::ReciprocalThroughput LATENCY;

								 static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

								 static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

								 static auto get_cycles()
									    WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										          constexpr CYCLES { return (m_cycles); }

								 static auto get_latency()
									    WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										          constexpr LATENCY { return (m_latency); }

								 static auto get_intrinsic_type()->
									             std::pair<WRF_CPP_CONST WRF_STRING,
									                            WRF_CPP_CONST WRF_STRING> {

									 using namespace wrf_physics::wrf_physics_internal::tags;
									 return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
										                    WRF_STRING{ typeid(cpu_arch_06_46_t_tag).name() }));
								 }
					  };

                     template<class Config>
					        struct SSE_Arithmetic<Config, wrf_physics::
						               wrf_physics_internal::tags::cpu_arch_0F_02_t_tag,
						                           wrf_physics::wrf_physics_internal::tags::
												                            sse_mm_add_ps_t_tag> {

								/******************************
								        Local typedefs
								******************************/

								typedef typename Config::CpuCycles CYCLES;

								typedef typename Config::ReciprocalThroughput LATENCY;

								static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(4);

								static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(2);

								static auto get_cycles()
									   WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									              constexpr CYCLES { return (m_cycles); }

								static auto get_latency()
									   WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									              constexpr LATENCY { return (m_latency); }

								static auto get_intrinsic_type()->
									              std::pair<WRF_CPP_CONST WRF_STRING,
									                                  WRF_CPP_CONST WRF_STRING> {

									using namespace wrf_physics::wrf_physics_internal::tags;
									return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
										                   WRF_STRING{ typeid(cpu_arch_0F_02_t_tag).name() }));
								}
					 };

                    template<class Config>
					       struct SSE_Arithmetic<Config, wrf_physics::
						              wrf_physics_internal::tags::cpu_arch_0F_03_t_tag,
						                          wrf_physics::wrf_physics_internal::tags::
												                            sse_mm_add_ps_t_tag> {

							   /***************************
							          Local typedefs
							   *****************************/

							   typedef typename Config::CpuCycles CYCLES;

							   typedef typename Config::ReciprocalThroughput LATENCY;

							   static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(5);

							   static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(2);

							   static auto get_cycles()
								      WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									             constexpr CYCLES { return (m_cycles); }

							   static auto get_latency()
								      WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									             constexpr LATENCY { return (m_latency); }

							   static auto get_intrinsic_type()->
								               std::pair<WRF_CPP_CONST WRF_STRING,
											                   WRF_CPP_CONST WRF_STRING>{

								   using namespace wrf_physics::wrf_physics_internal::tags;
								   return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
									                      WRF_STRING{ typeid(cpu_arch_0F_03_t_tag).name() }));
							   }
					};


						   /***************************************
						    Partial specialization on tag dispatch
							type sse_mm_sub_ps_t_tag
						   ****************************************/

						   template<class Config>
						         struct SSE_Arithmetic<Config, wrf_physics::
							               wrf_physics_internal::tags::cpu_arch_0F_03_t_tag,
							                            wrf_physics::wrf_physics_internal::tags::
													                            sse_mm_sub_ps_t_tag> {

									 /********************************
									          Local typedefs
									 *********************************/

									 typedef typename Config::CpuCycles CYCLES;

									 typedef typename Config::ReciprocalThroughput LATENCY;

									 static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(5);

									 static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(2);

									 static auto get_cycles()
										         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												            constexpr CYCLES { return (m_cycles); }

									 static auto get_latency()
										         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												            constexpr LATENCY { return (m_latency); }

									 static auto get_intrinsic_type()->
										             std::pair<WRF_CPP_CONST WRF_STRING,
										                               WRF_CPP_CONST WRF_STRING> {

										 using namespace wrf_physics::wrf_physics_internal::tags;
										 return (std::make_pair(WRF_STRING{ typeid(sse_mm_sub_ps_t_tag).name() },
											                    WRF_STRING{ typeid(cpu_arch_0F_03_t_tag).name() }));
									 }
						   };

                           template<class Config>
						         struct SSE_Arithmetic<Config, wrf_physics::
							                wrf_physics_internal::tags::cpu_arch_0F_02_t_tag,
							                            wrf_physics::wrf_physics_internal::tags::
														                             sse_mm_sub_ps_t_tag> {

									 /*************************
									       Local typedefs
									 *************************/

									 typedef typename Config::CpuCycles CYCLES;

									 typedef typename Config::ReciprocalThroughput LATENCY;

									 static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(4);

									 static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(2);

									 static auto get_cycles()
										         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												            constexpr CYCLES { return (m_cycles); }

									 static auto get_latency()
										         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												            constexpr LATENCY { return (m_latency); }

									 static auto get_intrinsic_type()->std::pair<WRF_CPP_CONST WRF_STRING,
										 WRF_CPP_CONST WRF_STRING> {

										 using namespace wrf_physics::wrf_physics_internal::tags;
										 return (std::make_pair(WRF_STRING{ typeid(sse_mm_sub_ps_t_tag).name() },
											                    WRF_STRING{ typeid(cpu_arch_0F_02_t_tag).name() }));
									 }
						   };

                          template<class Config>
						         struct SSE_Arithmetic<Config, wrf_physics::
							                   wrf_physics_internal::tags::cpu_arch_common_models_1_t_tag,
							                                           wrf_physics::wrf_physics_internal::tags::
														                                        sse_mm_sub_ps_t_tag> {

									 /************************
									      Local typedefs
									 *************************/

									 typedef typename Config::CpuCycles CYCLES;

									 typedef typename Config::ReciprocalThroughput LATENCY;

									 static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

									 static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

									 static auto get_cycles()
										         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												            constexpr CYCLES { return (m_cycles); }

									 static auto get_latency()
										         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												            constexpr LATENCY { return (m_latency); }

									 static auto get_intrinsic_type()->std::pair<WRF_CPP_CONST WRF_STRING,
										 WRF_CPP_CONST WRF_STRING> {

										 using namespace wrf_physics::wrf_physics_internal::tags;
										 return (std::make_pair(WRF_STRING{ typeid(sse_mm_sub_ps_t_tag).name() },
											                    WRF_STRING{ typeid(cpu_arch_common_models_1_t_tag).name() }));
									 }
						  };
						         

                         template<class Config>
						        struct SSE_Arithmetic<Config, wrf_physics::
							               wrf_physics_internal::tags::cpu_arch_common_models_2_t_tag,
							                                       wrf_physics::wrf_physics_internal::tags::
													                                         sse_mm_sub_ps_t_tag> {

									/***************************
									      Local typedefs
									****************************/

									typedef typename Config::CpuCycles CYCLES;

									typedef typename Config::ReciprocalThroughput LATENCY;

									static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

									static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

									static auto get_cycles()
										        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												           constexpr CYCLES { return (m_cycles); }

									static auto get_latency()
										        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												           constexpr LATENCY { return (m_latency); }

									static auto get_intrinsic_type()->std::pair<WRF_CPP_CONST WRF_STRING,
										WRF_CPP_CONST WRF_STRING> {

										using namespace wrf_physics::wrf_physics_internal::tags;
										return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
											                   WRF_STRING{ typeid(cpu_arch_common_models_2_t_tag).name() }));
									}
						 };

                        template<class Config>
						       struct SSE_Arithmetic<Config, wrf_physics::
							              wrf_physics_internal::tags::cpu_arch_06_17_t_tag,
							                           wrf_physics::wrf_physics_internal::tags::
													                              sse_mm_sub_ps_t_tag> {

								   /********************************
								            Local typedefs
								   *********************************/

								   typedef typename Config::CpuCycles CYCLES;

								   typedef typename Config::ReciprocalThroughput LATENCY;

								   static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

								   static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

								   static auto get_cycles()
									           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											              constexpr  CYCLES { return (m_cycles); }

								   static auto get_latency()
									           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											              constexpr LATENCY { return (m_latency) }

								   static auto get_intrinsic_type()->
									                std::pair<WRF_CPP_CONST WRF_STRING,
									                                  WRF_CPP_CONST WRF_STRING> {

									   using namespace wrf_physics::wrf_physics_internal::tags;
									   return (std::make_pair(WRF_STRING{ typeid(sse_mm_sub_ps_t_tag).name() },
										                      WRF_STRING{ typeid(cpu_arch_06_17_t_tag).name() }));
								   }
									       
						};

                       template<class Config>
					          struct SSE_Arithmetic<Config, wrf_physics::
						                 wrf_physics_internal::tags::cpu_arch_06_1D_t_tag,
						                             wrf_physics::wrf_physics_internal::tags::
													                            sse_mm_sub_ps_t_tag> {

								  typedef typename Config::CpuCycles CYCLES;

								  typedef typename Config::ReciprocalThroughput LATENCY;

								  static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

								  static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

								  static auto get_cycles()
									          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											            constexpr CYCLES { return (m_cycles); }

								  static auto get_latency()
									          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											            constexpr LATENCY { return (m_latency); }

								  static auto get_intrinsic_type()->std::pair<WRF_CPP_CONST WRF_STRING,
									  WRF_CPP_CONST WRF_STRING> {

									  using namespace wrf_physics::wrf_physics_internal::tags;
									  return (std::make_pair(WRF_STRING{ typeid(sse_mm_sub_ps_t_tag).name() },
										                     WRF_STRING{ typeid(cpu_arch_06_1D_t_tag).name() }));
								  }
					   };

                      template<class Config>
					        struct SSE_Arithmetic<Config, wrf_physics::
						               wrf_physics_internal::tags::cpu_arch_06_0F_t_tag,
						                            wrf_physics::wrf_physics_internal::tags::
										                                    sse_mm_sub_ps_t_tag> {

								typedef typename Config::CpuCycles CYCLES;

								typedef typename Config::ReciprocalThroughput LATENCY;

								static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(3);

								static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(1);

								static auto get_cycles()
									        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											           constexpr CYCLES { return (m_cycles); }

								static auto get_latency()
									        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											           constexpr LATENCY { return (m_latency); }

								static auto get_intrinsic_type()->std::pair<WRF_CPP_CONST WRF_STRING,
									WRF_CPP_CONST WRF_STRING> {

									using namespace wrf_physics::wrf_physics_internal::tags;
									return (std::make_pair(WRF_STRING{ typeid(sse_mm_add_ps_t_tag).name() },
										                   WRF_STRING{ typeid(cpu_arch_06_0F_t_tag).name() }));
								}
					  };

							/*************************************
							 sse_mm_mul_ps_t_tag specialization
							*************************************/

                      template<class Config>
					         struct SSE_Arithmetic<Config, wrf_physics::
						                wrf_physics_internal::tags::cpu_arch_0F_03_t_tag,
						                             wrf_physics::wrf_physics_internal::tags::
											                                  sse_mm_mul_ps_t_tag> {

						              typedef typename Config::CpuCycles CYCLES;

									  typedef typename Config::ReciprocalThroughput LATENCY;

									  static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(7);

									  static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(2);

									  static auto get_cycles()
										          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												             constexpr CYCLES { return (m_cycles); }

									  static auto get_latency()
										          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												             constexpr LATENCY { return (m_latency); }

									  static auto get_intrinsic_type()->
										              std::pair<WRF_CPP_CONST WRF_STRING,
										                                  WRF_CPP_CONST WRF_STRING> {

										  using namespace wrf_physics::wrf_physics_internal::tags;
										  return (std::make_pair(WRF_STRING{ typeid(sse_mm_mul_ps_t_tag).name() },
											                     WRF_STRING{ typeid(cpu_arch_0F_03_t_tag).name() }));
									  }
					  };

                     template<class Config>
					       struct SSE_Arithmetic<Config, wrf_physics::
						              wrf_physics_internal::tags::cpu_arch_0F_02_t_tag,
						                          wrf_physics::wrf_physics_internal::tags::
												                            sse_mm_mul_ps_t_tag> {


							   typedef typename Config::CpuCycles CYCLES;

							   typedef typename Config::ReciprocalThroughput LATENCY;

							   static constexpr CYCLES m_cycles = static_cast<typename Config::CpuCycles>(6);

							   static constexpr LATENCY m_latency = static_cast<typename Config::ReciprocalThroughput>(2);

							   static auto get_cycles()
								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										             constexpr CYCLES { return (m_cycles); }

							   static auto get_latency()
								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										             constexpr LATENCY { return (m_latency); }

							   static auto get_intrinsic_type()->
								               std::pair<WRF_CPP_CONST WRF_STRING,
								                                 WRF_CPP_CONST WRF_STRING> {

								   using namespace wrf_physics::wrf_physics_internal::tags;
								   return (std::make_pair(WRF_STRING{ typeid(sse_mm_mul_ps_t_tag).name() },
									                      WRF_STRING{ typeid(cpu_arch_0F_02_t_tag).name() }))
							   }
					 };

                    template<class Config>
					       struct SSE_Arithmetic<Config, wrf_physics::
						             wrf_physics_internal::tags::cpu_arch_06_3C_45_46_t_tag,
						                                    wrf_physics::wrf_physics_internal::tags::
						                                                               sse_mm_mul_ps_t_tag> {

							   typedef typename Config::CpuCycles CYCLES;

							   typedef typename Config::ReciprocalThroughput LATENCY;

							   static constexpr CYCLES m_cycles = Config::FivePipelineCycles;

							   static constexpr LATENCY m_latency = Config::HalfPipelineCycle;

							   static auto get_cycles()
								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										             constexpr CYCLES { return (m_cycles); }

							   static auto get_latency()
								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										             constexpr LATENCY { return (m_latency); }

							   static auto get_intrinsic_type()->std::pair<WRF_CPP_CONST WRF_STRING,
								   WRF_CPP_CONST WRF_STRING> {

								   using namespace wrf_physics::wrf_physics_internal::tags;
								   return (std::make_pair(WRF_STRING{ typeid(sse_mm_mul_ps_t_tag).name() },
									                      WRF_STRING{ typeid(cpu_arch_06_3C_45_46_t_tag).name() }));
							   }
					};

                    template<class Config>
					       struct SSE_Arithmetic<Config, wrf_physics::
						             wrf_physics_internal::tags::cpu_arch_06_2A_2D_3A_3E_t_tag,
						                                    wrf_physics::wrf_physics_internal::tags::
										                                              sse_mm_mul_ps_t_tag> {

							   typedef typename Config::CpuCycles CYCLES;

							   typedef typename Config::ReciprocalThroughput LATENCY;

							   static constexpr CYCLES m_cycles = Config::FivePipelineCycles;

							   static constexpr LATENCY m_latency = Config::OnePipelineCycle;

							   static auto get_cycles()
								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										             constexpr CYCLES { return (m_cycles); }

							   static auto get_latency()
								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										             constexpr LATENCY { return (m_latency); }

							   static auto get_intrinsic_type()->
								           std::pair<WRF_CPP_CONST WRF_STRING,
								                        WRF_CPP_CONST WRF_STRING> {

								   using namespace wrf_physics::wrf_physics_internal::tags;
								   return (std::make_pair(WRF_STRING{ typeid(sse_mm_mul_ps_t_tag).name() },
									                      WRF_STRING{ typeid(cpu_arch_06_2A_2D_3A_3E_t_tag) }));
							   }
								         
					};

                    template<class Config>
					       struct SSE_Arithmetic<Config, wrf_physics::
						         wrf_physics_internal::tags::cpu_arch_06_25_2C_1A_1E_1F_2E_2F_t_tag,
						                                        wrf_physics::wrf_physics_internal::tags::
												                                       sse_mm_mul_ps_t_tag> {

							   typedef typename Config::CpuCycles CYCLES;

							   typedef typename Config::ReciprocalThroughput LATENCY;

							   static constexpr CYCLES m_cycles = Config::FourPipelineCycles;

							   static constexpr LATENCY m_latency = Config::OnePipelineCycle;

							   static auto get_cycles()
								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										              constexpr CYCLES { return (m_cycles); }

							   static auto get_latency()
								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										              constexpr LATENCY { return (m_latency); }

							   static auto get_intrinsic_type()->
								           std::pair<WRF_CPP_CONST WRF_STRING,
								                            WRF_CPP_CONST WRF_STRING> {

								   using namespace wrf_physics::wrf_physics_internal::tags;
								   return (std::make_pair(WRF_STRING{ typeid(sse_mm_mul_ps_t_tag).name() },
									   WRF_STRING{ typeid(cpu_arch_06_25_2C_1A_1E_1F_2E_2F_t_tag).name() }));
							   }
					};

                    template<class Config>
					       struct SSE_Arithmetic<Config, wrf_physics::
						              wrf_physics_internal::tags::cpu_arch_06_17_t_tag,
						                          wrf_physics::wrf_physics_internal::tags::
										                                 sse_mm_mul_ps_t_tag> {

							   typedef typename Config::CpuCycles CYCLES;

							   typedef typename Config::ReciprocalThroughput LATENCY;

							   static constexpr CYCLES m_cycles = Config::FourPipelineCycles;

							   static constexpr LATENCY m_latency = Config::OnePipelineCycles;

							   static auto get_cycles()
								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										             constexpr CYCLES { return (m_cycles); }

							   static auto get_latency()
								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										             constexpr LATENCY { return (m_latency); }

							   static auto get_intrinsic_type()->std::pair<WRF_CPP_CONST WRF_STRING,
								   WRF_CPP_CONST WRF_STRING> {

								   using namespace wrf_physics::wrf_physics_internal::tags;
								   return (std::make_pair(WRF_STRING{ typeid(sse_mm_mul_ps_t_tag).name() },
									                      WRF_STRING{ typeid(cpu_arch_06_17_t_tag).name() }));
							   }
					};

                   template<class Config>
				         struct SSE_Arithmetic<Config, wrf_physics::
					               wrf_physics_internal::tags::cpu_arch_06_1D_t_tag,
					                           wrf_physics::wrf_physics_internal::tags::
											                           sse_mm_mul_ps_t_tag> {

							 typedef typename Config::CpuCycles CYCLES;

							 typedef typename Config::ReciprocalThroughput LATENCY;

							 static constexpr CYCLES m_cycles = Config::FourPipelineCycles;

							 static constexpr LATENCY m_latency = Config::OnePipelineCycle;

							 static auto get_cycles()
								         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										            constexpr CYCLES { return (m_cycles); }

							 static auto get_latency()
								         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										            constexpr LATENCY { return (m_latency); }

							 static auto get_intrinsic_type()->std::pair<WRF_CPP_CONST WRF_STRING,
								 WRF_CPP_CONST WRF_STRING> {

								 using namespace wrf_physics::wrf_physics_internal::tags;
								 return (std::make_pair(WRF_STRING{ typeid(sse_mm_mul_ps_t_tag).name() },
									                    WRF_STRING{ typeid(cpu_arch_06_1D_t_tag).name() }));
							 }
				   };

                  template<class Config>
				         struct SSE_Arithmetic<Config, wrf_physics::
					                wrf_physics_internal::tags::cpu_arch_06_0F_t_tag,
					                           wrf_physics::wrf_physics_internal::tags::
										                               sse_mm_mul_ps_t_tag> {

							 typedef typename Config::CpuCycles CYCLES;

							 typedef typename Config::ReciprocalThroughput LATENCY;

							 static constexpr CYCLES m_cycles = Config::FourPipelineCycles;

							 static constexpr LATENCY m_latency = Config::OnePipelineCycle;

							 static auto get_cycles()
								         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										           constexpr CYCLES { return (m_cycles); }

							 static auto get_latency()
								         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										          constexpr LATENCY { return (m_latency); }

							 static auto get_intrinsic_type()->std::pair<WRF_CPP_CONST WRF_STRING,
								 WRF_CPP_CONST WRF_STRING> {

								 using namespace wrf_physics::wrf_physics_internal::tags;
								 return (std::make_pair(WRF_STRING{ typeid(sse_mm_mul_ps_t_tag).name() },
									                    WRF_STRING{ typeid(cpu_arch_06_0F_t_tag).name() }));
							 }

				  };

                 template<class Config>
				       struct SSE_Arithmetic<Config, wrf_physics::
					              wrf_physics_internal::tags::cpu_arch_06_0E_t_tag,
					                           wrf_physics::wrf_physics_internal::tags::
											                             sse_mm_mul_ps_t_tag> {

						   typedef typename Config::CpuCycles CYCLES;

						   typedef typename Config::ReciprocalThroughput LATENCY;

						   static constexpr CYCLES m_cycles = Config::FivePipelineCycles;

						   static constexpr LATENCY m_latency = Config::TwoPipelineCycles;

						   static auto get_cycles()
							           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									               constexpr CYCLES { return (m_cycles); }

						   static auto get_latency()
							           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									               constexpr LATENCY { return (m_latency); }

						   static auto get_intrinsic_type()->std::pair<WRF_CPP_CONST WRF_STRING,
							   WRF_CPP_CONST WRF_STRING > {

							   using namespace wrf_physics::wrf_physics_internal::tags;
							   return (std::make_pair(WRF_STRING{ typeid(sse_mm_mul_ps_t_tag).name() },
								                    WRF_STRING{ typeid(cpu_arch_06_0E_t_tag).name() }));
						   }
				 };

                 
				        

                 


						   namespace glob_intrin_helper_funcs {



							   using namespace wrf_physics::wrf_physics_internal::traits;

							   template<class IntrinsicType_t> auto  
								       display_intrinsic_data(_In_ WRF_CPP_CONST IntrinsicType_t &type)
											                                       WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																				               WRF_ENABLE_IF<WRF_IS_CLASS<IntrinsicType_t>::value,void>{
                                        
													 std::cout << "Intrinsic type of: " << typeid(type).name() << std::endl;
													 std::cout << "Number of pipeline cycles: " << IntrinsicType_t::get_cycles() << std::endl;
													 std::cout << "Number of latency cycles: " << IntrinsicType_t::get_latency() << std::endl;
													 std::cout << "CPU model tag type: " << IntrinsicType_t::get_intrinsic_type().first << std::endl;
													 std::cout << "Intrinsic tag type: " << IntrinsicType_t::get_intrinsic_type().second << std::endl;


							   }
							           
						   }
				         




		 }
							   
	}
}
#endif

#endif /*__WRF_INTRINSICS_TYPES_HPP__*/