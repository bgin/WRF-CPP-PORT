
#ifndef __WRF_INTRINSICS_AVX_TYPES_HPP__
#define __WRF_INTRINSICS_AVX_TYPES_HPP__

#ifndef WRF_INTRINSICS_AVX_TYPES_VERSION_MAJOR
#define WRF_INTRINSICS_AVX_TYPES_VERSION_MAJOR 1
#endif

#ifndef WRF_INTRINSICS_AVX_TYPES_VERSION_MINOR
#define WRF_INTRINSICS_AVX_TYPES_VERSION_MINOR 0
#endif

#ifndef WRF_INTRINSICS_AVX_TYPES_CREATE_DATE
#define WRF_INTRINSICS_AVX_TYPES_CREATE_DATE 20160802
#endif

/* Set this value to successful build date*/
#ifndef WRF_INTRINSICS_AVX_TYPES_BUILD_DATE
#define WRF_INTRINSICS_AVX_TYPES_BUILD_DATE 20160818
#endif


#include "Wrf_cpu_arch_tags.hpp"
#include "Wrf_intrinsics_config.hpp"
#include "WRF_PHYS_LIB_TYPEDEFS.h"
#include "Wrf_type_aliases.hpp"
#include <map>

namespace wrf_physics {

	namespace wrf_physics_internal {

		namespace avx_intrinsic_traits {

			/*************************************
			   Convenience namespace aliases
			**************************************/
			namespace ic = wrf_physics::wrf_physics_utils::intrinsics_config;

			namespace ttags = wrf_physics::wrf_physics_internal::tags;

			namespace ttraits = wrf_physics::wrf_physics_internal::traits;

			/**********************************
			**********************************/
			

			template<class Config,
				           class CpuType_t, 
						          class  DataSize_t> struct AVX_MM256_ADD;


								  template<class Config>
								         struct AVX_MM256_ADD<Config, wrf_physics::
									                wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
									                                    wrf_physics::wrf_physics_internal::tags::
															                                   cpu_arch_float32_t_tag> {

											 typedef typename Config::CpuCycles LATENCY;

											 typedef typename Config::ReciprocalThroughput THROUGHPUT;

											 static constexpr LATENCY m_latency = Config::ThreePipelineCycles;

											 static constexpr THROUGHPUT m_throughput = Config::OnePipelineCycle;

											 static auto get_latency()
												         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
														           constexpr LATENCY { return (m_latency); }

											 static auto get_throughput()
												         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
														            constexpr THROUGHPUT { return (m_throughput); }

											 static auto get_intrinsic_type()->
												                 std::map<WRF_CPP_CONST WRF_STRING,
												                                        std::pair<WRF_CPP_CONST WRF_STRING,
																						          WRF_CPP_CONST WRF_STRING>> {

												 using namespace wrf_physics::wrf_physics_internal::tags;
												 std::map < WRF_CPP_CONST WRF_STRING,
													 std::pair < WRF_CPP_CONST WRF_STRING,
													 WRF_CPP_CONST WRF_STRING >> ret_map{ { typeid(AVX_MM256_ADD).name(),
													 { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, WRF_STRING{ typeid(cpu_arch_float32_t_tag) } } } };

												 return (ret_map);
											 }

											 static auto get_intrinsic_perf()->
												 std::map < std::pair<WRF_CPP_CONST WRF_STRING,
												                      WRF_CPP_CONST WRF_STRING>,
												                 std::pair < LATENCY, THROUGHPUT >> {

												 using namespace wrf_physics::wrf_physics_internal::tags;
												 return std::map < std::pair<WRF_CPP_CONST WRF_STRING,
													                         WRF_CPP_CONST WRF_STRING>,
																			 std::pair < LATENCY, THROUGHPUT >> {{ { typeid(cpu_arch_sandy_bridge_t_tag).name(),
																			 "_mm256_add_ps" }, { get_latency(), get_throughput() } }};
											 }

								  };

                                template<class Config>
								      struct AVX_MM256_ADD<Config, wrf_physics::
									            wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
									                             wrf_physics::wrf_physics_internal::tags::
																                         cpu_arch_float32_t_tag> {

										  typedef typename Config::CpuCycles LATENCY;

										  typedef typename Config::ReciprocalThroughput THROUGHPUT;

										  static constexpr LATENCY m_latency = Config::ThreePipelineCycles;

										  static constexpr THROUGHPUT m_throughput = Config::OnePipelineCycle;

										  static auto get_latency()
											          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
													             constexpr LATENCY { return (m_latency); }

										  static auto get_throughput()
											          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
													             constexpr THROUGHPUT { return (m_throughput); }

										  static auto get_intrinsic_type()->
											               std::map < WRF_CPP_CONST WRF_STRING,
											                          std::pair < WRF_CPP_CONST WRF_STRING,
											                                       WRF_CPP_CONST WRF_STRING >> {

											  using namespace wrf_physics::wrf_physics_internal::tags;
											  return std::map < WRF_CPP_CONST WRF_STRING, std::pair < WRF_CPP_CONST WRF_STRING,
												  WRF_CPP_CONST WRF_STRING >> {{ typeid(AVX_MM256_ADD).name(),
												  { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } };
										  }

										  static auto get_intrinsic_perf()->
											          std::map < std::pair<WRF_CPP_CONST WRF_STRING,
											                              WRF_CPP_CONST WRF_STRING>,
											                                       std::pair < LATENCY, THROUGHPUT >> {

											  using namespace wrf_physics::wrf_physics_internal::tags;
											  return std::map < std::pair<WRF_CPP_CONST WRF_STRING, WRF_CPP_CONST WRF_STRING>,
												  std::pair < LATENCY, THROUGHPUT >> {{ { typeid(cpu_arch_ivy_bridge_t_tag).name(), "_mm256_add_ps" },
												  { get_latency(), get_throughput() } } };
										  }


											  
										  
								};

                              template<class Config>
							         struct AVX_MM256_ADD<Config, wrf_physics::
								                wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
								                                wrf_physics::wrf_physics_internal::tags::
																                      cpu_arch_float32_t_tag> {

										 typedef typename Config::CpuCycles LATENCY;

										 typedef typename Config::ReciprocalThroughput THROUGHPUT;

										 static constexpr LATENCY m_latency = Config::ThreePipelineCycles;

										 static constexpr THROUGHPUT m_throughput = Config::OnePipelineCycle;

										 static auto get_latency()
											         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
													           constexpr LATENCY { return (m_latency); }

										 static auto get_throughput()
											         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
													           constexpr THROUGHPUT { return (m_latency); }

										 static auto get_intrinsic_type()->
											         std::map < WRF_CPP_CONST WRF_STRING,
											                   std::pair < WRF_CPP_CONST WRF_STRING,WRF_CPP_CONST WRF_STRING >> {

											 using namespace wrf_physics::wrf_physics_internal::tags;
											 return std::map < WRF_CPP_CONST WRF_STRING,
												 std::pair < WRF_CPP_CONST WRF_STRING,WRF_CPP_CONST WRF_STRING >> {{ typeid(AVX_MM256_ADD).name(),
												 { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } }};
										 }

										 static auto get_intrinsic_perf()->
											 std::map < std::pair<WRF_CPP_CONST WRF_STRING,
											 WRF_CPP_CONST WRF_STRING>,
											 std::pair < LATENCY, THROUGHPUT >> {

											 using namespace wrf_physics::wrf_physics_internal::tags;
											 return (std::map < std::pair<WRF_CPP_CONST WRF_STRING, WRF_CPP_CONST WRF_STRING>,
												 std::pair < LATENCY, THROUGHPUT >> {{ { typeid(cpu_arch_haswell_t_tag).name(), " _mm256_add_ps" },
												 { get_latency(), get_throughput() } }});
										 }

										 
							  };

                          template<class Config>
						        struct AVX_MM256_ADD<Config, wrf_physics::
							              wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
							                                  wrf_physics::wrf_physics_internal::tags::
													                                cpu_arch_float64_t_tag> {

									typedef typename Config::CpuCycles LATENCY;

									typedef typename Config::ReciprocalThroughput THROUGHPUT;

									static constexpr LATENCY m_latency = Config::ThreePipelineCycles;

									static constexpr THROUGHPUT m_throughput = Config::OnePipelineCycle;

									static auto get_latency()
										        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												        constexpr LATENCY { return (m_latency); }

									static auto get_throughput()
										        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												        constexpr THROUGHPUT { return (m_throughput); }

									static auto get_intrinsic_type()->
										       std::map < WRF_CPP_CONST WRF_STRING,
										                  std::pair < WRF_CPP_CONST WRF_STRING,
										                              WRF_CPP_CONST WRF_STRING >> {

										using namespace wrf_physics::wrf_physics_internal::tags;
										return (std::map<WRF_CPP_CONST WRF_STRING,
											std::pair < WRF_CPP_CONST WRF_STRING, WRF_CPP_CONST WRF_STRING >> {{ typeid(AVX_MM256_ADD).name(), {
											WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } }});
									}

									static auto get_intrinsic_perf()->
										        std::map < std::pair<WRF_CPP_CONST WRF_STRING,
										                             WRF_CPP_CONST WRF_STRING>,
										                     std::pair < LATENCY, THROUGHPUT >> {

										using namespace wrf_physics::wrf_physics_internal::tags;
										return (std::map<std::pair<WRF_CPP_CONST WRF_STRING,
											                       WRF_CPP_CONST WRF_STRING>,
																   std::pair < LATENCY, THROUGHPUT >> {{ {typeid(cpu_arch_sandy_bridge_t_tag).name(),
										                            " _mm256_add_pd"}, {get_latency(), get_throughput()} }});
									}
												         
						  };

						template<class Config>
						      struct AVX_MM256_ADD<Config, wrf_physics::
							            wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
							                             wrf_physics::wrf_physics_internal::tags::
							                                                   cpu_arch_float64_t_tag> {

								  typedef typename Config::CpuCycles LATENCY;

								  typedef typename Config::ReciprocalThroughput THROUGHPUT;

								  typedef std::map<WRF_CPP_CONST WRF_STRING, 
									             std::pair<WRF_CPP_CONST WRF_STRING, 
										                    WRF_CPP_CONST WRF_STRING>> TypeMap;

								  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING, 
									                           WRF_CPP_CONST WRF_STRING>,
									                   std::pair < LATENCY, THROUGHPUT >> PerfMap;

								  static constexpr LATENCY m_latency = Config::ThreePipelineCycles;

								  static constexpr THROUGHPUT m_throughput = Config::OnePipelineCycle;

								  static auto get_latency()
									          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											            constexpr LATENCY { return (m_latency); }

								  static auto get_throughput()
									          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											            constexpr THROUGHPUT { return (m_throughput); }

								  static auto get_intrinsic_type()->TypeMap {

									  using namespace wrf_physics::wrf_physics_internal::tags;
									  return (TypeMap{ { typeid(AVX_MM256_ADD).name(), { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
										  WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
								  }

								  static auto get_intrinsic_perf()->PerfMap {

									  using namespace wrf_physics::wrf_physics_internal::tags;
									  return (PerfMap{ { {typeid(cpu_arch_ivy_bridge_t_tag).name(), "_mm256_add_pd"}, 
									                                          {get_latency(), get_throughput()} } });
								  }
						};

                      template<class Config>
					  struct AVX_MM256_ADD<Config, wrf_physics::
						         wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
						                         wrf_physics::wrf_physics_internal::tags::
												                       cpu_arch_float64_t_tag> {

						  typedef typename Config::CpuCycles LATENCY;

						  typedef typename Config::ReciprocalThroughput THROUGHPUT;

						  typedef std::map < WRF_CPP_CONST WRF_STRING,
							                 std::map < WRF_CPP_CONST WRF_STRING, 
											          WRF_CPP_CONST WRF_STRING >> TypeMap;

						  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
							                 WRF_CPP_CONST WRF_STRING>,
							                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

						  static constexpr LATENCY m_latency = Config::ThreePipelineCycles;

						  static constexpr THROUGHPUT m_throughput = Config::OnePipelineCycle;

						  static auto get_latency()
							          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									             constexpr LATENCY { return (m_latency) };

						  static auto get_throughput()
							          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									             constexpr THROUGHPUT { return (m_throughput); }

						  static auto get_intrinsic_type()->TypeMap {

							  using namespace wrf_physics::wrf_physics_internal::tags;
							  return (TypeMap{ { typeid(AVX_MM256_ADD).name(), { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
								  WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
						  }

						  static auto get_intrinsic_perf()->PerfMap {

							  using namespace wrf_physics::wrf_physics_internal::tags;
							  return (PerfMap{ { { typeid(cpu_arch_haswell_t_tag).name(), " _mm256_add_pd" },
							  { get_latency(), get_throughput() } } });
						  }

					  };


					  template<class Config,
						              class CpuType_t,
									        class  DataSize_t> struct AVX_MM256_SUB;


					template<class Config>
					      struct AVX_MM256_SUB<Config, wrf_physics::
						             wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
						                                   wrf_physics::wrf_physics_internal::tags::
													                              cpu_arch_float32_t_tag> {

							  typedef typename Config::CpuCycles LATENCY;

							  typedef typename Config::ReciprocalThroughput THROUGHPUT;

							

							  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
								                           WRF_CPP_CONST WRF_STRING>,
								                           std::pair < LATENCY, THROUGHPUT >> PerfMap;

							  static constexpr LATENCY m_latency = Config::ThreePipelineCycles;

							  static constexpr THROUGHPUT m_throughput = Config::OnePipelineCycle;

							  static auto get_latency()
								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										              constexpr LATENCY { return (m_latency); }

							  static auto get_throughput()
								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										              constexpr THROUGHPUT { return (m_throughput); }

							  static auto get_intrinsic_type()->wrf_physics::
								             wrf_physics_utils::intrinsics_config::TypeMap {

								  using namespace wrf_physics::wrf_physics_internal::tags;
								  using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
								  return (TypeMap{ { typeid(AVX_MM256_SUB).name(), {
									  WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
									  WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
							  }

							  static auto get_intrinsic_perf()->PerfMap {

								  using namespace wrf_physics::wrf_physics_internal::tags;
								  return (PerfMap{ { { typeid(cpu_arch_sandy_bridge_t_tag).name(),
									  "_mm256_sub_ps" }, { get_latency(), get_throughput() } } });
							  }
					};

                  template<class Config>
				       struct AVX_MM256_SUB<Config, wrf_physics::
					              wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
					                               wrf_physics::wrf_physics_internal::tags::
					                                                   cpu_arch_float32_t_tag> {

						   typedef typename Config::CpuCycles LATENCY;

						   typedef typename Config::ReciprocalThroughput THROUGHPUT;

						   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
							                            WRF_CPP_CONST WRF_STRING>,
							                            std::pair < LATENCY, THROUGHPUT >> PerfMap;

						   static constexpr LATENCY m_latency = Config::ThreePipelineCycles;

						   static constexpr THROUGHPUT m_throughput = Config::OnePipelineCycle;

						   static auto get_latency()
							           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									             constexpr LATENCY { return (m_latency); }

						   static auto get_throughput()
							           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									             constexpr THROUGHPUT { return (m_throughput); }

						   static auto get_intrinsic_type()->wrf_physics::
							            wrf_physics_utils::intrinsics_config::TypeMap {

							   using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
							   using namespace wrf_physics::wrf_physics_internal::tags;
							   return (TypeMap{ { typeid(AVX_MM256_SUB).name(), {
								             WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
								             WRF_STRING{ typeid(cpu_arch_float32_t_tag) } } } });
						   }

						   static auto get_intrinsic_perf()->PerfMap {

							   using namespace wrf_physics::wrf_physics_internal::tags;
							   return (PerfMap{ { {typeid(cpu_arch_ivy_bridge_t_tag).name(), " _mm256_sub_ps"}, 
							                               {get_latency(), get_throughput()} } });
						   }
							    
				  };

               template<class Config>
			         struct AVX_MM256_SUB<Config, wrf_physics::
				           wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
				                        wrf_physics::wrf_physics_internal::tags::
										                      cpu_arch_float32_t_tag> {

						 typedef typename Config::CpuCycles LATENCY;

						 typedef typename Config::ReciprocalThroughput THROUGHPUT;

						 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
							                          WRF_CPP_CONST WRF_STRING>,
							                   std::pair < LATENCY, THROUGHPUT >> PerfMap;

						 static constexpr LATENCY m_latency = Config::ThreePipelineCycles;

						 static constexpr THROUGHPUT m_throughput = Config::OnePipelineCycle;

						 static auto get_latency()
							         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									            constexpr LATENCY { return (m_latency); }

						 static auto get_throughput()
							         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									            constexpr THROUGHPUT { return (m_throughput); }

						 static auto get_intrinsic_type()->wrf_physics::
							         wrf_physics_utils::intrinsics_config::TypeMap{

							 using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
							 using namespace wrf_physics::wrf_physics_internal::tags;
							 return (TypeMap{ { typeid(AVX_MM256_SUB).name(), 
							    { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
								 WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
						 }

						 static auto get_intrinsic_perf()->PerfMap{

							 using namespace wrf_physics::wrf_physics_internal::tags;
							 return (PerfMap{ { { typeid(cpu_arch_haswell_t_tag).name(), " _mm256_sub_ps" },
							                                       { get_latency(), get_throughput() } } });
						 }
			   };

             template<class Config>
			       struct AVX_MM256_SUB < Config, wrf_physics::
				              wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
				                                 wrf_physics::wrf_physics_internal::tags::
												                       cpu_arch_float64_t_tag> {

					   typedef typename Config::CpuCycles LATENCY;

					   typedef typename Config::ReciprocalThroughput THROUGHPUT;

					   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
						                            WRF_CPP_CONST WRF_STRING>,
						                       std::pair < LATENCY, THROUGHPUT >> PerfMap;

					   static constexpr LATENCY m_latency = Config::ThreePipelineCycles;

					   static constexpr THROUGHPUT m_throughput = Config::OnePipelineCycle;

					   static auto get_latency()
						           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								           constexpr LATENCY { return (m_latency); }

					   static auto get_throughput()
						           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								           constexpr THROUGHPUT { return (m_throughput); }

					   static auto get_intrinsic_type()->wrf_physics::
						       wrf_physics_utils::intrinsics_config::TypeMap {

						   using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
						   using namespace wrf_physics::wrf_physics_internal::tags;
						   return (TypeMap{ { typeid(AVX_MM256_SUB).name(),
						   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
						     WRF_STRING{ typeid(cpu_arch_06_0D_t_tag).name() } } } });
					   }

					   static auto get_intrinsic_perf()->PerfMap {

						   using namespace wrf_physics::wrf_physics_internal::tags;
						   return (PerfMap{ { { typeid(cpu_arch_sandy_bridge_t_tag).name(), " _mm256_sub_pd" }, 
						                     {get_latency(), get_throughput()} } });
					   }

			 };

            template<class Config>
			       struct AVX_MM256_SUB<Config, wrf_physics::
				              wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
				                               wrf_physics::wrf_physics_internal::tags::
											                        cpu_arch_float64_t_tag> {

					   typedef typename Config::CpuCycles LATENCY;

					   typedef typename Config::ReciprocalThroughput THROUGHPUT;

					   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
						                            WRF_CPP_CONST WRF_STRING>,
						                       std::pair < LATENCY, THROUGHPUT >> PerfMap;

					   static constexpr LATENCY m_latency = Config::ThreePipelineCycles;

					   static constexpr THROUGHPUT m_throughput = Config::OnePipelineCycle;

					   static auto get_latency()
						           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								             constexpr LATENCY { return (m_latency); }

					   static auto get_throughput()
						           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								             constexpr THROUGHPUT { return (m_throughput); }

					   static auto get_intrinsic_type()->wrf_physics::
						          wrf_physics_utils::intrinsics_config::TypeMap {

						   using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
						   using namespace wrf_physics::wrf_physics_internal::tags;
						   return (TypeMap{ { typeid(AVX_MM256_SUB).name(), 
						      { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
							   WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
					   }

					   static auto get_intrinsic_perf()->PerfMap{

						   using namespace wrf_physics::wrf_physics_internal::tags;
						   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_sub_pd" },
						                                                           { get_latency(), get_throughput() } } });
					   }
			};

          template<class Config>
		        struct AVX_MM256_SUB<Config, wrf_physics::
			                    wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
			                                  wrf_physics::wrf_physics_internal::tags::
											                        cpu_arch_float64_t_tag> {


					typedef typename Config::CpuCycles LATENCY;

					typedef typename Config::ReciprocalThroughput THROUGHPUT;

					typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
						                         WRF_CPP_CONST WRF_STRING>,
						                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

					static constexpr LATENCY m_latency = Config::ThreePipelineCycles;

					static constexpr THROUGHPUT m_throughput = Config::OnePipelineCycle;

					static auto get_latency()
						        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								          constexpr LATENCY { return (m_latency); }

					static auto get_throughput()
						        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								          constexpr THROUGHPUT { return (m_throughput); }

					static auto get_intrinsic_type()->wrf_physics::
						        wrf_physics_utils::intrinsics_config::TypeMap {

						using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
						using namespace wrf_physics::wrf_physics_internal::tags;
						return (TypeMap{ { typeid(AVX_MM256_SUB).name(),
						                 { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
						                   WRF_STRING{ typeid(cpu_arch_06_0D_t_tag).name() } } } });
					}

					static auto get_intrinsic_perf()->PerfMap {

						using namespace wrf_physics::wrf_physics_internal::tags;
						return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_sub_pd" },
						                                                    { get_latency(), get_throughput() } } });
					}
		  };

        
				 template<class Config,
					            class  CpuType_t,
								       class   DataSize_t>  struct AVX_MM256_DIV;


                 template<class Config>
				        struct AVX_MM256_DIV<Config, wrf_physics::
					                wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
					                                    wrf_physics::wrf_physics_internal::tags::
														                     cpu_arch_float32_t_tag> {

							typedef typename Config::CpuCycles LATENCY;

							typedef typename Config::ReciprocalThroughput THROUGHPUT;

							typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
								                         WRF_CPP_CONST WRF_STRING>,
								                   std::pair < LATENCY, THROUGHPUT >> PerfMap;

							static constexpr LATENCY m_latency = Config::Lat29PipeCycles;

							static constexpr THROUGHPUT m_throughput = Config::Thr28PipeCycles;

							static auto get_latency()
								        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										        constexpr LATENCY { return (m_latency); }

							static auto get_throughput()
								        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
										        constexpr THROUGHPUT { return (m_throughput); }

							static auto get_intrinsic_type()->wrf_physics::
								        wrf_physics_utils::intrinsics_config::TypeMap{

								using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
								using namespace wrf_physics::wrf_physics_internal::tags;
								return (TypeMap{ { typeid(AVX_MM256_DIV).name(),
								{ WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
								  WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
							}

							static auto get_intrinsic_perf()->PerfMap {

								using namespace wrf_physics::wrf_physics_internal::tags;
								return (PerfMap{ { { WRF_STRING{typeid(cpu_arch_sandy_bridge_t_tag).name()}, " _mm256_div_ps" }, 
								                                                        {get_latency(), get_throughput() } } });
							}
				 };

                template<class Config>
				      struct AVX_MM256_DIV<Config, wrf_physics::
					             wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
					                               wrf_physics::wrf_physics_internal::tags::
					                                                    cpu_arch_float32_t_tag> {

						  typedef typename Config::CpuCycles LATENCY;

						  typedef typename Config::ReciprocalThroughput THROUGHPUT;

						  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
							                           WRF_CPP_CONST WRF_STRING>,
							                  std::pair < LATENCY, THROUGHPUT >> PerfMap;

						  static constexpr LATENCY m_latency = Config::Lat21PipeCycles;

						  static constexpr THROUGHPUT m_throughput = Config::Thr14PipeCycles;

						  static auto get_latency()
							          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									             constexpr LATENCY { return (m_latency); }

						  static auto get_throughput()
							         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									             constexpr THROUGHPUT { return (m_throughput); }

						  static auto get_intrinsic_type()->wrf_physics::
							          wrf_physics_utils::intrinsics_config::TypeMap {

							  using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
							  using namespace wrf_physics::wrf_physics_internal::tags;
							  return (TypeMap{ { typeid(AVX_MM256_DIV).name(),
							  { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
							    WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
						  }
				};

               template<class Config>
			         struct AVX_MM256_DIV<Config, wrf_physics::
				              wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
				                           wrf_physics::wrf_physics_internal::tags::
										                         cpu_arch_float32_t_tag> {

						 typedef typename Config::CpuCycles LATENCY;

						 typedef typename Config::ReciprocalThroughput THROUGHPUT;

						 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
							                          WRF_CPP_CONST WRF_STRING>,
							                   std::pair < LATENCY, THROUGHPUT >> PerfMap;

						 static constexpr LATENCY m_latency = Config::Lat21PipeCycles;

						 static constexpr THROUGHPUT m_throughput = Config::Thr13PipeCycles;

						 static auto get_latency()
							         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									           constexpr LATENCY { return (m_latency); }

						 static auto get_throughput()
							         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									           constexpr THROUGHPUT { return (m_throughput); }

						 static auto get_intrinsic_type()->wrf_physics::
							         wrf_physics_utils::intrinsics_config::TypeMap {

							 using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
							 using namespace wrf_physics::wrf_physics_internal::tags;
							 return (TypeMap{ { typeid(AVX_MM256_DIV).name(),
							 { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
							   WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
						 }

						 static auto get_intrinsic_perf()->PerfMap {

							 using namespace wrf_physics::wrf_physics_internal::tags;
							 return (PerfMap{ { { WRF_STRING{typeid(cpu_arch_haswell_t_tag).name()}, " _mm256_div_ps" }, 
							                                                      {get_latency(), get_throughput()} } });
						 }


			   };

              template<class Config>
			         struct AVX_MM256_DIV<Config, wrf_physics::
				                wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
				                                  wrf_physics::wrf_physics_internal::tags::
												                        cpu_arch_float64_t_tag>{

						 typedef typename Config::CpuCycles LATENCY;

						 typedef typename Config::ReciprocalThroughput THROUGHPUT;

						 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
							                          WRF_CPP_CONST WRF_STRING>,
							                    std::pair < LATENCY, THROUGHPUT >> PerfMap;

						 static constexpr LATENCY m_latency = Config::Lat43PipeCycles;

						 static constexpr THROUGHPUT m_throughput = Config::Thr44PipeCycles;

						 static auto get_latency()
							         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									         constexpr LATENCY { return (m_latency); }

						 static auto get_throughput()
							         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									         constexpr THROUGHPUT { return (m_throughput); }

						 static auto get_intrinsic_type()->wrf_physics::
							          wrf_physics_utils::intrinsics_config::TypeMap {

							 using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
							 using namespace wrf_physics::wrf_physics_internal::tags;
							 return (TypeMap{ { typeid(AVX_MM256_DIV).name(),
							 { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
							   WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
						 }

						 static auto get_intrinsic_perf()->PerfMap {

							 using namespace wrf_physics::wrf_physics_internal::tags;
							 return (PerfMap{ { { WRF_STRING{typeid(cpu_arch_sandy_bridge_t_tag).name()}, " _mm256_div_pd" }, 
							                                                          {get_latency(), get_throughput()} } });
						 }

						 

			  };

             template<class Config>
			       struct AVX_MM256_DIV<Config, wrf_physics::
				             wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
				                               wrf_physics::wrf_physics_internal::tags::
											                         cpu_arch_float64_t_tag>{

					   typedef typename Config::CpuCycles LATENCY;

					   typedef typename Config::ReciprocalThroughput THROUGHPUT;

					   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
						                            WRF_CPP_CONST WRF_STRING>,
						                       std::pair < LATENCY, THROUGHPUT >> PerfMap;

					   static constexpr LATENCY m_latency = Config::Lat35PipeCycles;

					   static constexpr THROUGHPUT m_throughput = Config::Thr28PipeCycles;

					   static auto get_latency()
						           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								             constexpr LATENCY { return (m_latency); }

					   static auto get_throughput()
						           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								             constexpr THROUGHPUT { return (m_throughput); }

					   static auto get_intrinsic_type()->wrf_physics::
						    wrf_physics_utils::intrinsics_config::TypeMap {

						   using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
						   using namespace wrf_physics::wrf_physics_internal::tags;
						   return (TypeMap{ { typeid(AVX_MM256_DIV).name(),
						   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
						     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
					   }

					   static auto get_intrinsic_perf()->PerfMap {

						   using namespace wrf_physics::wrf_physics_internal::tags;
						   return (PerfMap{ { { WRF_STRING{typeid(cpu_arch_ivy_bridge_t_tag).name()}, " _mm256_div_pd" }, 
						                                                         { get_latency(), get_throughput() } } });
					   }

			 };

           template<class Config>
		         struct AVX_MM256_DIV<Config, wrf_physics::
			                 wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
			                                wrf_physics::wrf_physics_internal::tags::
											                      cpu_arch_float64_t_tag> {

					 typedef typename Config::CpuCycles LATENCY;

					 typedef typename Config::ReciprocalThroughput THROUGHPUT;

					 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
						                          WRF_CPP_CONST WRF_STRING>,
						                  std::pair < LATENCY, THROUGHPUT >> PerfMap;

					 static constexpr LATENCY m_latency = Config::Lat35PipeCycles;

					 static constexpr THROUGHPUT m_throughput = Config::Thr25PipeCycles;

					 static auto get_latency()
						         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								            constexpr LATENCY { return (m_latency); }

					 static auto get_throughput()
						         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								            constexpr THROUGHPUT { return (m_throughput); }

					 static auto get_intrinsic_type()->wrf_physics::
						         wrf_physics_utils::intrinsics_config::TypeMap {

						 using namespace wrf_physics::wrf_physics_internal::tags;
						 using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
						 return (TypeMap{ { typeid(AVX_MM256_DIV).name(),
						 { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
						   WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
					 }

					 static auto get_intrinsic_perf()->PerfMap {

						 using namespace wrf_physics::wrf_physics_internal::tags;
						 return (PerfMap{ { { WRF_STRING{typeid(cpu_arch_haswell_t_tag).name()}, " _mm256_div_pd" }, 
						                                                     {get_latency(), get_throughput()} } });
					 }

		   };

				 template<class Config,
					                 class CpuType_t,
									       class DataSize_t> struct AVX_MM256_MUL;

               
        
          template<class Config>
		         struct AVX_MM256_MUL<Config, wrf_physics::
			                 wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
			                                      wrf_physics::wrf_physics_internal::tags::
												                        cpu_arch_float32_t_tag> {

					 
					 
					 typedef typename Config::CpuCycles LATENCY;

					 typedef typename Config::ReciprocalThroughput THROUGHPUT;

					 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
						                          WRF_CPP_CONST WRF_STRING>,
						                     std::pair < LATENCY, THROUGHPUT >> PerfMap;

					 static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

					 static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

					 static auto get_latency()
						         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								            constexpr LATENCY { return (m_latency); }

					 static auto get_throughput()
						         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								            constexpr THROUGHPUT { return (m_throughput); }

					 static auto get_intrinsic_type()->wrf_physics::
						         wrf_physics_utils::intrinsics_config::TypeMap {

						 using namespace wrf_physics::wrf_physics_utils::intrinsics_config;
						 using namespace wrf_physics::wrf_physics_internal::tags;
						 return (TypeMap{ { typeid(AVX_MM256_MUL).name(),
						 { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
						   WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
					 }

					 static auto get_intrinsic_perf()->PerfMap {

						 using namespace wrf_physics::wrf_physics_internal::tags;
						 return (PerfMap{ { { WRF_STRING{typeid(cpu_arch_sandy_bridge_t_tag).name()}, " _mm256_mul_ps" }, 
						                                                           {get_latency(), get_throughput()} } });
					 }
		  };
				
         template<class Config>
		       struct AVX_MM256_MUL<Config, wrf_physics::
			             wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
			                               wrf_physics::wrf_physics_internal::tags::
										                       cpu_arch_float32_t_tag> {

				   
				   typedef typename Config::CpuCycles LATENCY;

				   typedef typename Config::ReciprocalThroughput THROUGHPUT;

				   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
					                            WRF_CPP_CONST WRF_STRING>,
					                            std::pair < LATENCY, THROUGHPUT >> PerfMap;

				   static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

				   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

				   static auto get_latency()
					           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
							              constexpr LATENCY { return (m_latency); }

				   static auto get_throughput()
					           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
							              constexpr THROUGHPUT { return (m_throughput); }

				   static auto get_intrinsic_type()->ic::TypeMap {

					   using namespace wrf_physics::wrf_physics_internal::tags;
					   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MUL).name() },
					   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
					   WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
				   }

				   static auto get_intrinsic_perf()->PerfMap {

					   using namespace wrf_physics::wrf_physics_internal::tags;
					   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_mul_ps" },
					                                                          { get_latency(), get_throughput() } } });
				   }

		 };

         template<class Config>
		       struct AVX_MM256_MUL<Config, wrf_physics::
			          wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
			                         wrf_physics::wrf_physics_internal::tags::
									                      cpu_arch_float32_t_tag> {

				   typedef typename Config::CpuCycles LATENCY;

				   typedef typename Config::ReciprocalThroughput THROUGHPUT;

				   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
					                            WRF_CPP_CONST WRF_STRING>,
					                            std::pair < LATENCY, THROUGHPUT >> PerfMap;

				   static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

				   static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

				   static auto get_latency()
					           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
							              constexpr LATENCY { return (m_latency); }

				   static auto get_throughput()
					           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
							              constexpr THROUGHPUT { return (m_throughput); }

				   static auto get_intrinsic_type()->ic::TypeMap {

					   using namespace ttags;
					   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MUL).name() },
					   { WRF_STRING{ typeid(cpu_arch_06_0D_t_tag).name() },
					     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
				   }

				   static auto get_intrinsic_perf()->PerfMap{

					   using namespace ttags;
					   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_mul_ps" },
					                                                       { get_latency(), get_throughput() } } });
				   }
		 };

         template<class Config>
		        struct AVX_MM256_MUL<Config, wrf_physics::
			                wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
			                                     wrf_physics::wrf_physics_internal::tags::
											                            cpu_arch_float64_t_tag> {

					typedef typename Config::CpuCycles LATENCY;

					typedef typename Config::ReciprocalThroughput THROUGHPUT;

					typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
						                         WRF_CPP_CONST WRF_STRING>,
						                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

					static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

					static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

					static auto get_latency()
						        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								          constexpr LATENCY { return (m_latency); }

					static auto get_throughput()
						        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
								          constexpr THROUGHPUT { return (m_throughput); }

					static auto get_intrinsic_type()->ic::TypeMap {

						using namespace ttags;
						return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MUL).name() },
						{ WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
						  WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
					}

					static auto get_intrinsic_perf()->PerfMap {

						using namespace ttags;
						return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_mul_pd" },
						                                                          { get_latency(), get_throughput() } } });
					}
		 };

				template<class Config>
				      struct AVX_MM256_MUL<Config, wrf_physics::
					                wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
					                                 wrf_physics::wrf_physics_internal::tags::
													                        cpu_arch_float64_t_tag> {

						  typedef typename Config::CpuCycles LATENCY;

						  typedef typename Config::ReciprocalThroughput THROUGHPUT;

						  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
							                           WRF_CPP_CONST WRF_STRING>,
							                    std::pair < LATENCY, THROUGHPUT >> PerfMap;

						  static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

						  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

						  static auto get_latency()
							           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									             constexpr LATENCY { return (m_latency); }

						  static auto get_throughput()
							           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
									             constexpr THROUGHPUT { return (m_throughput); }

						  static auto get_intrinsic_type()->ic::TypeMap {

							  using namespace ttags;
							  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MUL).name() },
							  { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
							  WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
						  }
						         
						  static auto get_intrinsic_perf()->PerfMap {

							  using namespace ttags;
							  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_mul_pd" },
							                                                          { get_latency(), get_throughput() } } });
						  }
						  

				};

					  template<class Config>
					         struct AVX_MM256_MUL<Config, wrf_physics::
						                wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
						                               wrf_physics::wrf_physics_internal::tags::
													                           cpu_arch_int64_t_tag> {

								 typedef typename Config::CpuCycles LATENCY;

								 typedef typename Config::ReciprocalThroughput THROUGHPUT;

								 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
									                          WRF_CPP_CONST WRF_STRING>,
									                   std::pair < LATENCY, THROUGHPUT >> PerfMap;

								 static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

								 static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

								 static auto get_latency()
									         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											           constexpr LATENCY { return (m_latency); }

								 static auto get_throughput()
									         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
											           constexpr THROUGHPUT { return (m_throughput); }

								 static auto get_intrinsic_type()->ic::TypeMap {

									 using namespace ttags;
									 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MUL).name() },
									 { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
									   WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
								 }

								 static auto get_intrinsic_perf()->PerfMap {

									 using namespace ttags;
									 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_mul_pd" },
									                                                     { get_latency(), get_throughput() } } });
								 }
					  };


							 /************************************************
							           Convert type of Intrinsics
									   Primary template
							 **************************************************/

							 template<class Config, 
								              typename,
											         class CpuType_t,
													        class  DataSize_t> struct AVX_MM256_CVTP;
                                     
															/******************************************
															    CPU and data size  partial template 
																specializations.
															******************************************/

                            template<class Config>
							      struct AVX_MM256_CVTP<Config, 
									     typename std::enable_if<std::is_class<Config>::value>::type,
								             wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
								                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {

									  typedef typename Config::CpuCycles LATENCY;

									  typedef typename Config::ReciprocalThroughput THROUGHPUT;

									  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
										                           WRF_CPP_CONST WRF_STRING>,
										                           std::pair < LATENCY, THROUGHPUT >> PerfMap;

									  static constexpr LATENCY m_latency = Config::Lat2PipeCycles;

									  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

									  static auto get_latency()
										          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												            constexpr LATENCY { return (m_latency); }

									  static auto get_throughput()
										           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												            constexpr THROUGHPUT { return (m_throughput); }

									  static auto get_intrinsic_type()->ic::TypeMap {

										  using namespace ttags;
										  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CVTP).name() },
										  { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
										    WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
									  }

									  static auto get_intrinsic_perf()->PerfMap{

										  using namespace ttags;
										  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_cvtps_pd" },
										                                                             { get_latency(), get_throughput() } } });
									  }
							};


                          template<class Config>
						           struct AVX_MM256_CVTP<Config,
							           typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
							                          wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
							                                 wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {

									 typedef typename Config::CpuCycles LATENCY;

									 typedef typename Config::ReciprocalThroughput THROUGHPUT;

									 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
										                          WRF_CPP_CONST WRF_STRING>,
										                         std::pair < LATENCY, THROUGHPUT >> PerfMap;

									 static constexpr LATENCY m_latency = Config::Lat2PipeCycles;

									 static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

									 static auto get_latency()
										         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												           constexpr LATENCY { return (m_latency); }

									 static auto get_throughput()
										         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
												           constexpr THROUGHPUT { return (m_throughput); }

									 static auto get_intrinsic_type()->ic::TypeMap {

										 using namespace ttags;
										 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CVTP).name() },
										 { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
										 WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
									 }

									 static auto get_intrinsic_perf()->PerfMap{

										 using namespace ttags;
										 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_cvtps_pd" },
										 { get_latency(), get_throughput() } } });
									 }
						  };

								   template<class Config>
								         struct AVX_MM256_CVTP<Config,
									           typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
									                           wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
									                                wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {

											 typedef typename Config::CpuCycles LATENCY;

											 typedef typename Config::ReciprocalThroughput THROUGHPUT;

											 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
												                          WRF_CPP_CONST WRF_STRING>,
												                          std::pair < LATENCY, THROUGHPUT >> PerfMap;

											 static constexpr LATENCY m_latency = Config::Lat2PipeCycles;

											 static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

											 static auto get_latency()
												         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
														            constexpr LATENCY { return (m_latency); }

											 static auto get_throughput()
												         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
														            constexpr THROUGHPUT { return (m_throughput); }

											 static auto get_intrinsic_type()->ic::TypeMap {

												 using namespace ttags;
												 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CVTP).name() },
												 { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
												   WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
											 }

											 static auto get_intrinsic_perf()->PerfMap {

												 using namespace ttags;
												 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_cvtps_pd" },
												                                                      { get_latency(), get_throughput() } } });
											 }
								   };

						 template<class Config>
							   struct AVX_MM256_CVTP<Config,
								 typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
											    wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
											                wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {

												   typedef typename Config::CpuCycles LATENCY;

												   typedef typename Config::ReciprocalThroughput THROUGHPUT;

												   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
													                            WRF_CPP_CONST WRF_STRING>,
													                    std::pair < LATENCY, THROUGHPUT >> PerfMap;

												   static constexpr LATENCY m_latency = Config::Lat4PipeCycles;

												   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

												   static auto get_latency()
													           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
															             constexpr LATENCY { return (m_latency); }

												   static auto get_throughput()
													           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
															             constexpr THROUGHPUT { return (m_throughput); }

												   static auto get_intrinsic_type()->ic::TypeMap {

													   using namespace ttags;
													   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CVTP).name() },
													   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
													   WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
												   }

												   static auto get_intrinsic_perf()->PerfMap {

													   using namespace ttags;
													   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_cvtpd_ps" },
													                                                              { get_latency(), get_throughput() } } });
												   }
										 };

											   template<class Config>
											         struct AVX_MM256_CVTP<Config,
												           typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
												                           wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
												                                     wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag>{

														 typedef typename Config::CpuCycles LATENCY;

														 typedef typename Config::ReciprocalThroughput THROUGHPUT;

														 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
															                          WRF_CPP_CONST WRF_STRING>,
															                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

														 static constexpr LATENCY m_latency = Config::Lat4PipeCycles;

														 static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

														 static auto get_latency()
															          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																	          constexpr LATENCY { return (m_latency); }

														 static auto get_throughput()
															         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																	          constexpr THROUGHPUT { return (m_throughput); }

														 static auto get_intrinsic_type()->ic::TypeMap {

															 using namespace ttags;
															 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CVTP).name() },
															 { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
															   WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
														 }

														 static auto get_intrinsic_perf()->PerfMap {

															 using namespace ttags;
															 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_cvtpd_ps" },
															                                                          { get_latency(), get_throughput() } } });
														 }
											   };
													 
													 template<class Config>
													       struct AVX_MM256_CVTP < Config,
														              typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
														                               wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
														                                     wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {

															   typedef typename Config::CpuCycles LATENCY;

															   typedef typename Config::ReciprocalThroughput THROUGHPUT;

															   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																                            WRF_CPP_CONST WRF_STRING>,
																                     std::pair < LATENCY, THROUGHPUT >> PerfMap;

															   static constexpr LATENCY m_latency = Config::Lat4PipeCycles;

															   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

															   static auto get_latency()
																           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																		             constexpr LATENCY { return (m_latency); }

															   static auto get_throughput()
																           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																		             constexpr THROUGHPUT { return (m_throughput); }
																      
															   static auto get_intrinsic_type()->ic::TypeMap {

																   using namespace ttags;
																   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CVTP).name() },
																   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																     WRF_STRING{ typeid(cpu_arch_float64_t_tag) } } } });
															   }

															   static auto get_intrinsic_perf()->PerfMap {

																   using namespace ttags;
																   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_cvtpd_ps" },
																                                                        { get_latency(), get_throughput() } } });
															   }
													 };

														   /*****************************************
														       Vector comparison type of intrisic.
															   Primary template.
														   ******************************************/

														   template<class Config,
															                    typename,
																				        class CpuType_t,
																						       class DataSize_t> struct AVX_MM256_CMP;
														  
														 /******************************
													          Partial specialization.
														*******************************/

                                                        template<class Config>
														     struct AVX_MM256_CMP<Config,
															           typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
															                       wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
															                                 wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																 typedef typename Config::CpuCycles LATENCY;

																 typedef typename Config::ReciprocalThroughput THROUGHPUT;

																 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																	                          WRF_CPP_CONST WRF_STRING>,
																	                     std::pair < LATENCY, THROUGHPUT >> PerfMap;

																 static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

																 static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

																 static auto get_latency()
																	         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																			         constexpr LATENCY { return (m_latency); }

																 static auto get_throughput()
																	        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																			         constexpr THROUGHPUT { return (m_throughput); }

																 static auto get_intrinsic_type()->ic::TypeMap {

																	 using namespace ttags;
																	 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CMP).name() },
																	 { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
																	   WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																 }

																 static auto get_intrinsic_perf()->PerfMap {

																	 using namespace ttags;
																	 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_cmp_ps" },
																	                                                          { get_latency(), get_throughput() } } });
																 }
														};

															 template<class Config>
															       struct AVX_MM256_CMP<Config,
																              typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																                          wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
																                                wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																	   typedef typename Config::CpuCycles LATENCY;

																	   typedef typename Config::ReciprocalThroughput THROUGHPUT;

																	   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																		                            WRF_CPP_CONST WRF_STRING>,
																		                        std::pair < LATENCY, THROUGHPUT >> PerfMap;

																	   static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

																	   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

																	   static auto get_latency()
																		           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																				             constexpr LATENCY { return (m_latency); }

																	   static auto get_throughput()
																		           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																				             constexpr THROUGHPUT { return (m_throughput); }

																	   static auto get_intrinsic_type()->ic::TypeMap {

																		   using namespace ttags;
																		   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CMP).name() },
																		   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
																		     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																	   }

																	   static auto get_intrinsic_perf()->PerfMap {

																		   using namespace ttags;
																		   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_cmp_ps" },
																		                                                      { get_latency(), get_throughput() } } });
																	   }
															 };


																   template<class Config>
																         struct AVX_MM256_CMP<Config,
																	              typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																	                             wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																	                                wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																			 typedef typename Config::CpuCycles LATENCY;

																			 typedef typename Config::ReciprocalThroughput THROUGHPUT;

																			 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																				                          WRF_CPP_CONST WRF_STRING>,
																				                  std::pair < LATENCY, THROUGHPUT >> PerfMap;

																			 static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

																			 static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

																			 static auto get_latency()
																				         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																						          constexpr LATENCY { return (m_latency); }

																			 static auto get_throughput()
																				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																						          constexpr THROUGHPUT { return (m_throughput); }

																			 static auto get_intrinsic_type()->ic::TypeMap {

																				 using namespace ttags;
																				 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CMP).name() },
																				 { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																				   WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																			 }

																			 static auto get_intrinsic_perf()->PerfMap {

																				 using namespace ttags;
																				 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_cmp_ps" },
																				                                                     { get_latency(), get_throughput() } } });
																			 }
																   };

																		 template<class Config>
																		         struct AVX_MM256_CMP<Config,
																			          typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																			                      wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
																			                               wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


																					 typedef typename Config::CpuCycles LATENCY;

																					 typedef typename Config::ReciprocalThroughput THROUGHPUT;

																					 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																						                          WRF_CPP_CONST WRF_STRING>,
																						                      std::pair < LATENCY, THROUGHPUT >> PerfMap;

																					 static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

																					 static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

																					 static auto get_latency()
																						         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																								           constexpr LATENCY { return (m_latency); }

																					 static auto get_throughput()
																						         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																								           constexpr THROUGHPUT { return (m_throughput); }

																					 static auto get_intrinsic_type()->ic::TypeMap {

																						 using namespace ttags;
																						 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CMP).name() },
																						 { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
																						   WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
																					 }

																					 static auto get_intrinsic_perf()->PerfMap {

																						 using namespace ttags;
																						 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, "_mm256_cmp_pd" },
																						                                                     { get_latency(), get_throughput() } } });
																					 }
																		 };

																				 template<class Config>
																				        struct  AVX_MM256_CMP<Config,
																							     typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																								               wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
																									                 wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


																							       typedef typename Config::CpuCycles LATENCY;

																								   typedef typename Config::ReciprocalThroughput THROUGHPUT;

																								   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																									                            WRF_CPP_CONST WRF_STRING>,
																									                     std::pair < LATENCY, THROUGHPUT >> PerfMap;

																								   static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

																								   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

																								   static auto get_latency()
																									          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																											         constexpr LATENCY { return (m_latency); }

																								   static auto get_throughput()
																									           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																											         constexpr THROUGHPUT { return (m_throughput); }

																								   static auto get_intrinsic_type()->ic::TypeMap {

																									   using namespace ttags;
																									   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CMP).name() },
																									   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
																									   WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
																								   }

																								   static auto get_intrinsic_perf()->PerfMap {

																									   using namespace ttags;
																									   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_cmp_pd" },
																									                                                        { get_latency(), get_throughput() } } });
																								   }


																						 };
                                                          
																						template<class Config>
																						       struct AVX_MM256_CMP<Config,
																							        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																							                         wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																							                                 wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


																								   typedef typename Config::CpuCycles LATENCY;

																								   typedef typename Config::ReciprocalThroughput THROUGHPUT;

																								   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																									                            WRF_CPP_CONST WRF_STRING>,
																									                     std::pair < LATENCY, THROUGHPUT >> PerfMap;

																								   static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

																								   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

																								   static auto get_latency()
																									            WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																												      constexpr LATENCY { return (m_latency); }

																								   static auto get_throughput()
																									            WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																												     constexpr THROUGHPUT { return (m_throughput) }

																								   static auto get_intrinsic_type()->ic::TypeMap {

																									   using namespace ttags;
																									   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CMP).name() },
																									   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																									   WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
																								   }

																								   static auto get_intrinsic_perf()->PerfMap {

																									   using namespace ttags;
																									   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_cmp_pd" },
																									                                                        { get_latency(), get_throughput() } } });
																								   }

																						};


																							   /*****************************************************
																							       Vector Reciprocal 1.0/v[:]  type of intrinsic.
																								   Primary template.
																							   ******************************************************/

																							   template<class Config,
																								                 typename,
																												         class CpuType_t,
																														          class DataSize_t> struct AVX_MM256_RCP;

																								  /**********************************************
																								          Only float32_t specializations.
																								  ************************************************/

                                                                                                template<class Config>
																								      struct AVX_MM256_RCP<Config,
																									          typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																									                      wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
																									                                wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																										  typedef typename Config::CpuCycles LATENCY;

																										  typedef typename Config::ReciprocalThroughput THROUGHPUT;

																										  typedef typename Config::RelativeError REL_ERROR;

																										  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																											                           WRF_CPP_CONST WRF_STRING>,
																											                std::pair<std::pair<LATENCY,THROUGHPUT>,REL_ERROR>> PerfMap;

																										  static constexpr LATENCY m_latency = Config::Lat7PipeCycles;

																										  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

																										  static constexpr REL_ERROR m_relerror = Config::RCPRelError;

																										  static auto get_latency()
																											          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													            constexpr LATENCY { return (m_latency); }

																										  static auto get_throughput()
																											          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													            constexpr THROUGHPUT { return (m_throughput); }

																										  static auto get_relerror()
																											          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													            constexpr REL_ERROR { return (m_relerror); }

																										  static auto get_intrinsic_type()->ic::TypeMap {

																											  using namespace ttags;
																											  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_RCP).name() },
																											  { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
																											    WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																										  }

																										  static auto get_intrinsic_perf()->PerfMap {

																											  using namespace ttags;
																											  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_rcp_ps" },
																											  { { get_latency(), get_throughput() }, get_relerror() } } });
																										  }
																								};

																						 template<class Config>
																							   struct AVX_MM256_RCP<Config,
																								    typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																										           wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
																										                  wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																								   typedef typename Config::CpuCycles LATENCY;

																								   typedef typename Config::ReciprocalThroughput THROUGHPUT;

																								   typedef typename Config::RelativeError REL_ERROR;

																								   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																									                            WRF_CPP_CONST WRF_STRING>,
																									            std::pair < std::pair<LATENCY, THROUGHPUT>, REL_ERROR >> PerfMap;

																								   static constexpr LATENCY m_latency = Config::Lat7PipeCycles;

																								   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

																								   static constexpr REL_ERROR m_relerror = Config::RCPRelError;

																								   static auto get_latency()
																									           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																											             constexpr LATENCY { return (m_latency); }

																								   static auto get_throughput()
																									           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																											             constexpr THROUGHPUT { return (m_throughput); }

																								   static auto get_relerror()
																									           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																											   constexpr REL_ERROR {
																												   return (m_relerror);
																											   }

																								   static auto get_intrinsic_type()->ic::TypeMap {

																									   using namespace ttags;
																									   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_RCP).name() },
																									   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
																									   WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																								   }

																								   static auto get_intrinsic_perf()->PerfMap {

																									   using namespace ttags;
																									   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_rcp_ps" },
																									                                     { { get_latency(), get_throughput() }, get_relerror() } } });
																								   }
																							 };

																							   template<class Config>
																							         struct AVX_MM256_RCP<Config,
																								          typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																								                          wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																								                            wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																										 typedef typename  Config::CpuCycles LATENCY;

																										 typedef typename  Config::ReciprocalThroughput THROUGHPUT;

																										 typedef typename  Config::RelativeError REL_ERROR;

																										 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																											                          WRF_CPP_CONST WRF_STRING>,
																											           std::pair < std::pair<LATENCY, THROUGHPUT>, REL_ERROR >> PerfMap;

																										 static constexpr LATENCY m_latency = Config::Lat7PipeCycles;

																										 static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

																										 static constexpr REL_ERROR m_relerror = Config::RCPRelError;

																										 static auto get_latency()
																											        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													         constexpr LATENCY { return (m_latency); }

																										 static auto get_throughput()
																											        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													         constexpr THROUGHPUT { return (m_throughput); }

																										 static auto get_relerror()
																											        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													         constexpr REL_ERROR { return (m_relerror); }

																										 static auto get_intrinsic_type()->ic::TypeMap {

																											 using namespace ttags;
																											 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_RCP).name() },
																											 { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																											   WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																										 }

																										 static auto get_intrinsic_perf()->PerfMap{

																											 using namespace ttags;
																											 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_rcp_ps" },
																											                                  { { get_latency(), get_throughput() }, get_relerror() } } });
																										 }
																							   };


																									 /************************************************************
																									   Vector SQRT Reciprocal 1.0/SQRT(v[:])intrinsic type traits
																									   Primary template
																									 *************************************************************/

                                                                                               template<class Config,
																								              typename,
																											          class CpuType_t,
																													        class DataSize_t> struct AVX_MM256_RSQRT;


																									/***************************************************
																									     float32_t dispatch tag specialization only
																									****************************************************/

                                                                                               template<class Config>
																							        struct AVX_MM256_RSQRT<Config,
																								         typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																								                     wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
																								                              wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																										typedef typename Config::CpuCycles LATENCY;

																										typedef typename Config::ReciprocalThroughput THROUGHPUT;

																										typedef typename Config::RelativeError REL_ERROR;

																										typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																											                         WRF_CPP_CONST WRF_STRING>,
																											            std::pair < std::pair<LATENCY, THROUGHPUT>, REL_ERROR >> PerfMap;


																										static constexpr LATENCY m_latency = Config::Lat7PipeCycles;

																										static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

																										static constexpr REL_ERROR m_relerror = Config::RSQRTRelError;

																										static auto get_latency()
																											       WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																												              constexpr LATENCY { return (m_latency); }

																										static auto get_throughput()
																											       WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																												              constexpr THROUGHPUT { return (m_throughput); }

																										static auto get_relerror()
																											       WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																												              constexpr REL_ERROR { return (m_relerror); }

																										static auto get_intrinsic_type()->ic::TypeMap {

																											using namespace ttags;
																											return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_RSQRT).name() },
																											{ WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
																											  WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																										}

																										static auto get_intrinsic_perf()->PerfMap {

																											using namespace ttags;
																											return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_rsqrt_ps" },
																											{ { get_latency(), get_throughput() }, get_relerror() } } });
																										}
																							   };

                                                                                               
                                                                                               template<class Config>
																							        struct AVX_MM256_RSQRT<Config,
																								         typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																								                     wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
																								                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {

																										typedef typename Config::CpuCycles LATENCY;

																										typedef typename Config::ReciprocalThroughput THROUGHPUT;

																										typedef typename Config::RelativError REL_ERROR;

																										typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																										  	                         WRF_CPP_CONST WRF_STRING>,
																											           std::pair < std::pair<LATENCY, THROUGHPUT>, REL_ERROR >> PerfMap;


																										static  constexpr LATENCY m_latency = Config::Lat7PipeCycles;

																										static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

																										static constexpr REL_ERROR m_relerror = Config::RSQRTRelError;

																										static auto get_latency()
																											        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													          constexpr LATENCY { return (m_latency); }

																										static auto get_throughput()
																											        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													          constexpr THROUGHPUT { return (m_throughput) }

																										static auto get_relerror()
																											        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													          constexpr REL_ERROR  { return (m_relerror); }

																										static auto get_intrinsic_type()->ic::TypeMap {

																											using namespace ttags;
																											return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_RSQRT).name() },
																											{ WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
																											  WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																										}


																										static auto get_intrinsic_perf()->PerfMap {

																											using namespace ttags;
																											return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_rsqrt_ps" },
																											                                  { { get_latency(), get_throughput() }, get_relerror() } } });
																										}

																							   };

                                                                                               template<class Config>
																							         struct AVX_MM256_RSQRT<Config,
																								          typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																								                           wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																								                                 wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																										 typedef typename Config::CpuCycles LATENCY;

																										 typedef typename Config::ReciprocalThroughput THROUGHPUT;

																										 typedef typename Config::RelativeError REL_ERROR;

																										 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																											                          WRF_CPP_CONST WRF_STRING>,
																											           std::pair < std::pair<LATENCY, THROUGHPUT>, REL_ERROR >> PerfMap;


																										 static constexpr LATENCY m_latency = Config::Lat7PipeCycles;

																										 static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

																										 static constexpr REL_ERROR m_relerror = Config::RSQRTRelError;

																										 static auto get_latency()
																											         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													          constexpr LATENCY { return (m_latency); }

																										 static auto get_throughput()
																											         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													         constexpr THROUGHPUT { return (m_throughput); }

																										 static auto get_relerror()
																											         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													         constexpr REL_ERROR { return (m_relerror); }

																										 static auto get_intrinsic_type()->ic::TypeMap {

																											 using namespace ttags;
																											 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_RSQRT).name() },
																											 { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																											   WRF_STRING{ typeid(cpu_arch_float32_t_tag) } } } });
																										 }

																										 static auto get_intrinsic_perf()->PerfMap {

																											 using namespace ttags;
																											 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_rsqrt_ps" },
																											                                  { { get_latency(), get_throughput() }, get_relerror() } } });
																										 }
																							   };

																									 /********************************************************
																									   Vector SQRT, SQRT(v[:]) type of intrinsic type traits.
																									   Primary template.
																									 ********************************************************/

                                                                                                template<class Config,
																									            typename,
																												        class CpuType_t,
																														       class DataSize_t> struct AVX_MM256_SQRT;

																										 /***********************************************
																										  float32_t dispatch tag partial specialization.
																										 ************************************************/

                                                                                               template<class Config>
																							         struct AVX_MM256_SQRT<Config,
																								           typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																								                      wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
																								                              wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																										 typedef typename Config::CpuCycles LATENCY;

																										 typedef typename Config::ReciprocalThroughput THROUGHPUT;

																										 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																											                          WRF_CPP_CONST WRF_STRING>,
																											                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

																										 static constexpr LATENCY m_latency = Config::Lat29PipeCycles;

																										 static constexpr THROUGHPUT m_throughput = Config::Thr28PipeCycles;

																										 static auto get_latency()
																											         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													           constexpr LATENCY { return (m_latency); }

																										 static auto get_throughput()
																											         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													           constexpr THROUGHPUT { return (m_throughput); }

																										 static auto get_intrinsic_type()->ic::TypeMap {

																											 using namespace ttags;
																											 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_SQRT).name() },
																											 { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
																											   WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																										 }

																										 static auto get_intrinsic_perf()->PerfMap {

																											 using namespace ttags;
																											 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_sqrt_ps" },
																											                                                          { get_latency(), get_throughput() } } });
																										 }

																							   };


                                                                                               template<class Config>
																							        struct AVX_MM256_SQRT<Config,
																								           typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																								                        wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
																								                               wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {

																										typedef typename Config::CpuCycles LATENCY;

																										typedef typename Config::ReciprocalThroughput THROUGHPUT;

																										typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																											                         WRF_CPP_CONST WRF_STRING>,
																											             std::pair < LATENCY, THROUGHPUT >> PerfMap;

																										static constexpr LATENCY m_latency = Config::Lat21PipeCycles;

																										static constexpr THROUGHPUT m_throughput = Config::Thr14PipeCycles;

																										static auto get_latency()
																											        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													        constexpr LATENCY { return (m_latency); }

																										static auto get_throughput()
																											        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													         constexpr THROUGHPUT { return (m_throughput); }

																										static auto get_intrinsic_type()->ic::TypeMap {

																											using namespace ttags;
																											return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_SQRT).name() },
																											{ WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
																											  WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																										}

																										static auto get_intrinsic_perf()->PerfMap {

																											using namespace ttags;
																											return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_sqrt_ps" },
																											                                                        { get_latency(), get_throughput() } } });
																										}
																							   };

                                                                                              template<class Config>
																							        struct AVX_MM256_SQRT<Config,
																								         typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																								                          wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																								                              wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																										typedef typename Config::CpuCycles LATENCY;

																										typedef typename Config::ReciprocalThroughput THROUGHPUT;

																										typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																											                         WRF_CPP_CONST WRF_STRING>,
																											            std::pair < LATENCY, THROUGHPUT >> PerfMap;

																										static constexpr LATENCY m_latency = Config::Lat21PipeCycles;

																										static constexpr THROUGHPUT m_throughput = Config::Thr14PipeCycles;

																										static auto get_latency()
																											        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													         constexpr LATENCY { return (m_latency); }

																										static auto get_throughput()
																											        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																													         constexpr THROUGHPUT { return (m_throughput); }

																									WRF_STRONG_INLINE	static auto get_intrinsic_type()->ic::TypeMap {

																											using namespace ttags;
																											return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_SQRT).name() },
																											{ WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																											WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																										}

																									WRF_STRONG_INLINE	static auto get_intrinsic_perf()->PerfMap {

																											using namespace ttags;
																											return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_sqrt_ps" },
																											                                                    { get_latency(), get_throughput() } } });
																										}
																							  };


                                                                                            template<class Config>
																							     struct AVX_MM256_SQRT<Config,
																								        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																								                  wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
																								                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {

																									 
																									 typedef typename Config::CpuCycles LATENCY;

																									 typedef typename Config::ReciprocalThroughput THROUGHPUT;

																									 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																										                          WRF_CPP_CONST WRF_STRING>,
																										                std::pair < LATENCY, THROUGHPUT >> PerfMap;

																									 
																									 static constexpr LATENCY m_latency = Config::Lat43PipeCycles;

																									 static constexpr THROUGHPUT m_throughput = Config::Thr44PipeCycles;

																									 static auto get_latency()
																										         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																												          constexpr LATENCY { return (m_latency); }

																									 static auto get_throughput()
																										         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																												          constexpr THROUGHPUT { return (m_throughput); }

																									 WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

																										 using namespace ttags;
																										 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_SQRT).name() },
																										 { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
																										   WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
																									 }

																									 WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

																										 using namespace ttags;
																										 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_sqrt_pd" },
																										                                                          { get_latency(), get_throughput() } } });
																									 }
																							};

																							template<class Config>
																							      struct AVX_MM256_SQRT<Config,
																								        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																								                       wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
																								                             wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


																									  typedef typename Config::CpuCycles LATENCY;

																									  typedef typename Config::ReciprocalThroughput THROUGHPUT;

																									  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																										                           WRF_CPP_CONST WRF_STRING>,
																										                     std::pair < LATENCY, THROUGHPUT >> PerfMap;

																									  static constexpr LATENCY m_latency = Config::Lat35PipeCycles;

																									  static constexpr THROUGHPUT m_throughput = Config::Thr28PipeCycles;

																									  static auto get_latency()
																										         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																												           constexpr LATENCY { return (m_latency); }

																									  static auto get_throughput()
																										          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																												           constexpr THROUGHPUT { return (m_throughput); }

																									  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

																										  using namespace ttags;
																										  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_SQRT).name() },
																										  { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
																										    WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
																									  }

																									  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

																										  using namespace ttags;
																										  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_sqrt_pd" },
																										  { get_latency(), get_throughput() } } });
																									  }

																							};

  
																						template<class Config>
																						      struct AVX_MM256_SQRT<Config,
																							        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																							                       wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																							                               wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


																								  typedef typename Config::CpuCycles LATENCY;

																								  typedef typename Config::ReciprocalThroughput THROUGHPUT;

																								  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																									                           WRF_CPP_CONST WRF_STRING>,
																									                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

																								  static constexpr LATENCY m_latency = Config::Lat35PipeCycles;

																								  static constexpr THROUGHPUT m_throughput = Config::Thr28PipeCycles;

																								  static auto get_latency()
																									          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																											          constexpr LATENCY { return (m_latency); }

																								  static auto get_throughput()
																									          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																											          constexpr THROUGHPUT { return (m_throughput); }

																								  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

																									  using namespace ttags;
																									  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_SQRT).name() },
																									  { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																									    WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
																								  }

																								  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

																									  using namespace ttags;
																									  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_sqrt_pd" },
																									  { get_latency(), get_throughput() } } });
																								  }
																						};

                                                                                      
																							  /***************************************************
																							            FMADD  intrinsic type traits.
																										Primary template.
																							  *****************************************************/

                                                                                      template<class Config,
																						                typename,
																										       class CpuType_t,
																											         class DataSize_t> struct  AVX_MM256_FMADD;


																							 /****************************************
																							     cpu_arch_haswell_t_tag specialization.
																							 *******************************************/

                                                                                     template<class Config>
																					       struct AVX_MM256_FMADD<Config,
																						   typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																						                  wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																						                      wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																							   typedef typename Config::CpuCycles LATENCY;

																							   typedef typename Config::ReciprocalThroughput THROUGHPUT;

																							   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																								                            WRF_CPP_CONST WRF_STRING>,
																								                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

																							   static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

																							   static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

																							   static auto get_latency()
																								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										             constexpr LATENCY { return (m_latency); }

																							   static auto get_throughput()
																								          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										             constexpr THROUGHPUT { return (m_throughput); }

																							   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

																								   using namespace ttags;
																								   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FMADD).name() },
																								   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																								   WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																							   }

																							   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

																								   using namespace ttags;
																								   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_fmadd_ps" },
																								   { get_latency(), get_throughput() } } });
																							   }
																					 };
																								        
																					         
                                                                                     template<class Config>
																					       struct AVX_MM256_FMADD<Config,
																						       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																						                      wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																						                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


																							   typedef typename Config::CpuCycles LATENCY;

																							   typedef typename Config::ReciprocalThroughput THROUGHPUT;

																							   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																								                            WRF_CPP_CONST WRF_STRING>,
																								                  std::pair < LATENCY, THROUGHPUT >> PerfMap;

																							   static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

																							   static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

																							   static auto get_latency()
																								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										              constexpr LATENCY { return (m_latency); }

																							   static auto get_throughput()
																								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										              constexpr THROUGHPUT { return (m_throughput); }

																							   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

																								   using namespace ttags;
																								   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FMADD).name() },
																								   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																								    WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
																							   }

																							   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

																								   using namespace ttags;
																								   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_fmadd_pd" },
																								            { get_latency(), get_throughput() } } });
																							   }
																					 };

																						   /****************************************
																						     FMSUB intrinsic type traits.
																							 Primary template.
																						   *****************************************/

                                                                                    template<class Config,
																						                 typename,
																										        class CpuType_t,
																												       class DataSize_t> struct AVX_MM256_FMSUB;

																							 /***************************************
																							  cpu_arch_haswell_t_tag tag dispatch
																							  specialization.
																							 ****************************************/

                                                                                     
                                                                                    template<class Config>
																					       struct AVX_MM256_FMSUB<Config,
																						           typename ttraits::WRF_ENABLE_IF<traits::WRF_IS_CLASS<Config>::value>::type,
																						                         wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																						                             wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																							   typedef typename Config::CpuCycles LATENCY;

																							   typedef typename Config::ReciprocalThroughput THROUGHPUT;

																							   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																								                            WRF_CPP_CONST WRF_STRING>,
																								                 std::pair < LATENCY, THROUGHPUT >> PerfMap;


																							   static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

																							   static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

																							   static auto  get_latency()
																								            WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																											         constexpr LATENCY { return (m_latency); }

																							   static auto get_throughput()
																								           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										            constexpr THROUGHPUT { return (m_throughput); }

																							   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

																								   using namespace ttags;
																								   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FMSUB).name() },
																								   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																								   WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																							   }

																							   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

																								   using namespace ttags;
																								   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_fmsub_ps" },
																								          { get_latency(), get_throughput() } } });
																							   }
																					};

                                                                                   template<class Config>
																				         struct AVX_MM256_FMSUB<Config,
																					             typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																					                            wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																					                                 wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


																							 typedef typename Config::CpuCycles LATENCY;

																							 typedef typename Config::ReciprocalThroughput THROUGHPUT;

																							 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																								                          WRF_CPP_CONST WRF_STRING>,
																								                std::pair < LATENCY, THROUGHPUT >> PerfMap;

																							 static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

																							 static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

																							 static auto get_latency()
																								         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										           constexpr LATENCY { return (m_latency); }

																							 static auto get_throughput()
																								         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										           constexpr THROUGHPUT { return (m_throughput); }

																							 WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

																								 using namespace ttags;
																								 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FMSUB).name() },
																								 { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																								 WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
																							 }

																							 WRF_STRONG_INLINE static auto get_intrinsic_pef()->PerfMap {

																								 using namespace ttags;
																								 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_fmsub_pd" },
																								                                                 { get_latency(), get_throughput() } } });
																							 }
																				   };

                                                                                 
																						 /**************************************************
																						           FNMADD intrisic type traits.
																								   Primary template.
																						 ***************************************************/

                                                                                   template<class Config,
																					                   typename,
																									           class CpuType_t,
																											           class DataSize_t> struct AVX_MM256_FNMADD;


																						/*****************************************
																						   cpu_arch_haswell_t_tag dispatch tag
																						   specialization.
																						*****************************************/

                                                                                   template<class Config>
																				          struct AVX_MM256_FNMADD<Config,
																					             typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																					                            wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																					                                    wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																							  typedef typename Config::CpuCycles LATENCY;

																							  typedef typename Config::ReciprocalThroughput THROUGHPUT;

																							  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																								                           WRF_CPP_CONST WRF_STRING>,
																								                  std::pair < LATENCY, THROUGHPUT >> PerfMap;

																							  static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

																							  static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

																							  static auto get_latency()
																								          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										            constexpr LATENCY { return (m_latency); }

																							  static auto get_throughput()
																								          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										            constexpr THROUGHPUT { return (m_throughput); }

																							  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

																								  using namespace ttags;
																								  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FNMADD).name() },
																								  { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																								    WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																							  }

																							  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

																								  using namespace ttags;
																								  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_fnmadd_ps" },
																								                             { get_latency(), get_throughput() } } });
																							  }
																				   };

                                                                                 template<class Config>
																				        struct AVX_MM256_FNMADD<Config,
																					            typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																					                             wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																					                                wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


																							typedef typename Config::CpuCycles LATENCY;

																							typedef typename Config::ReciprocalThroughput THROUGHPUT;

																							typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																								                         WRF_CPP_CONST WRF_STRING>,
																								                 std::pair < LATENCY, THROUGHPUT >> PerfMap;


																							static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

																							static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

																							static auto get_latency()
																								        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										         constexpr LATENCY { return (m_latency); }

																							static auto get_throughput()
																								        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										            constexpr THROUGHPUT { return (m_throughput); }

																							WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

																								using namespace ttags;
																								return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FNMADD).name() },
																								{ WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																								  WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
																							}

																							WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

																								using namespace ttags;
																								return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_fnmadd_pd" },
																								   { get_latency(), get_throughput() } } });
																							}
																				 };


																						/*****************************************
																						  FNMSUB Intrinsic type traits.
																						  Primary template.
																						*****************************************/

                                                                                   template<class Config,
																					                    typename,
																										         class CpuType_t,
																												         class DataSize_t> struct AVX_MM256_FNMSUB;

																							/************************************
																							 cpu_arch_haswell_t_tag tag dispatch
																							 specialization.
																							************************************/

                                                                                  template<class Config>
																				         struct AVX_MM256_FNMSUB<Config,
																					           typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																					                          wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																					                             wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


																							 typedef typename Config::CpuCycles LATENCY;

																							 typedef typename Config::ReciprocalThroughput THROUGHPUT;

																							 typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																								                          WRF_CPP_CONST WRF_STRING>,
																								               std::pair < LATENCY, THROUGHPUT >> PerfMap;

																							 static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

																							 static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

																							 static auto get_latency()
																								          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										           constexpr LATENCY { return (m_latency); }

																							 static auto get_throughput()
																								         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										           constexpr THROUGHPUT { return (m_throughput); }

																							 WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

																								 using namespace ttags;
																								 return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FNMSUB).name() },
																								 { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																								   WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
																							 }

																							 WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

																								 using namespace ttags;
																								 return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_fnmsub_ps" },
																								                                                        { get_latency(), get_throughput() } } });
																							 }
																				  };

                                                                                  template<class Config>
																				        struct AVX_MM256_FNMSUB<Config,
																					        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
																					                          wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
																					                                wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


																							typedef typename Config::CpuCycles LATENCY;

																							typedef typename Config::ReciprocalThroughput THROUGHPUT;

																							typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
																								                         WRF_CPP_CONST WRF_STRING>,
																								                std::pair < LATENCY, THROUGHPUT >> PerfMap;


																							static constexpr LATENCY m_latency = Config::Lat5PipeCycles;

																							static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

																							static auto get_latency()
																								        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										        constexpr LATENCY { return (m_latency); }

																							static auto get_throughput()
																								        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
																										        constexpr THROUGHPUT { return (m_throughput); }

																							WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

																								using namespace ttags;
																								return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FNMSUB).name() },
																								{ WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
																								  WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
																							}

																							WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

																								using namespace ttags;
																								return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_fnmsub_pd" },
																								                                                         { get_latency(), get_throughput() } } });
																							}
																				  };

/*************************************
	AND Intrinsic type traits.
   Primary template.
**************************************/
                                                                                  
 template<class Config,
			    typename ,
					 class CpuType_t,
								  class DataSize_t> struct AVX_MM256_AND;
 
                                                                                  
/**************************
  Partial specializations.
***************************/

  template<class Config>
       struct AVX_MM256_AND<Config,
	         typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                   wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                             wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                      std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_AND).name() },
			   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_and_ps" },
			                                                            { get_latency(), get_throughput() } } });
		   }
  };

 template<class Config>
       struct AVX_MM256_AND<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                             wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			   WRF_CPP_CONST WRF_STRING>,
			   std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static constexpr get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_AND).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_and_ps" },
			                                                          { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
       struct AVX_MM256_AND<Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                         wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                  std::pair < LATENCY, THROUGHPUT >> PerfMap;


		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					          constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					          constexpr THROUGHPUT { return (m_throughput); }

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_AND).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_and_ps" },
			                                                       { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
       struct AVX_MM256_AND<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                              wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			               std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		    Notification:
		    It is unknown if ICC will inline
			chain of objects creation.
			Here we have 
			1) Inlining call to TypeMap Ctor.
			2) Inlining call to String Ctor.
			3) Inlining call to std::pair Ctor.
			4) Inlining call to String objects Ctors.
			Please bear in mind that std::pair Ctor
			should have a support of initializer list object,
			as in case of String Ctor.
		   *********************************************/
		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_AND).name() },
			   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_and_pd" },
			                                                         { get_latency(), get_throughput() } } });
		   }

 };

 template<class Config>
       struct AVX_MM256_AND<Config,
	          typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                        wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                               wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                std::pair < LATENCY, THROUGHPUT >> PerfMap;


		   static constexpr  LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/
		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_AND).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_and_pd" },
			                                                          { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
       struct AVX_MM256_AND<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                        wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                    std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace  ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_AND).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_and_pd" },
			                                                    { get_latency(), get_throughput() } } });
		   }
 };

	   /***************************************
	    _mm256_or_ps/pd Intrinsic type traits.
		Primary template.
	   ***************************************/

 template<class Config,
	                typename,
					       class CpuType_t,
						               class DataSize_t> struct AVX_MM256_OR;

	/************************************
	   Specializations on CpuType_t and
	   on DataSize_t dispatch tags.
	*************************************/

  template<class Config>
        struct AVX_MM256_OR<Config,
	          typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                               wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


			typedef typename Config::CpuCycles LATENCY;

			typedef typename Config::ReciprocalThroughput THROUGHPUT;

			typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
				                        WRF_CPP_CONST WRF_STRING>,
				                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

			static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

			static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

			static auto get_latency()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						           constexpr LATENCY { return (m_latency); }

			static auto get_throughput()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						           constexpr THROUGHPUT { return (m_throughput); }
			/********************************************
			Notification:
			It is unknown if ICC will inline
			chain of objects creation.
			Here we have
			1) Inlining call to TypeMap Ctor.
			2) Inlining call to String Ctor.
			3) Inlining call to std::pair Ctor.
			4) Inlining call to String objects Ctors.
			Please bear in mind that std::pair Ctor
			should have a support of initializer list object,
			as in case of String Ctor.
			*********************************************/
			WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

				using namespace ttags;
				return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_OR).name() },
				{ WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
				  WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
			    }

			WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

				using namespace ttags;
				return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() } },
				                                       { get_latency(), get_throughput() } } });
			 }
  };

 template<class Config>
       struct AVX_MM256_OR<Config,
	         typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                       wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                             wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                     std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/
		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_OR).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_or_ps" },
			                                                         { get_latency(), get_throughput() } } });
		   }

 };

 template<class Config>
       struct AVX_MM256_OR<Config,
	         typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                               wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename  Config::CpuCycles LATENCY;

		   typedef typename  Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                    std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/
		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_OR).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_or_ps" },
			                                                       { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
       struct AVX_MM256_OR<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                  wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycle LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                     std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					       constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/
		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_OR).name() },
			   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace  ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_or_pd" },
			                                                          { get_latency(), get_throughput() } } });
		   }

 };

 template<class Config>
       struct AVX_MM256_OR<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_OR).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag) }, " _mm256_or_pd" },
			                                                { get_latency(), get_throughput() } } });
		   }

 };

 template<class Config>
       struct AVX_MM256_OR < Config,
	         typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                           wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                                wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef  typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_OR).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_or_pd" },
			                                                     { get_latency(), get_throughput() } } });
		   }
 };

	   /***************************************
	   Intrinsic _mm256_xor_ps/pd type traits.
	   Primary template.
	   ****************************************/

 template<class Config,
		             typename,
						    class CpuType_t,
								         class DataSize_t> struct AVX_MM256_XOR;


		/***************************************
		 Partial specializations on CpuType_t
		 and DataSize_t dispatch tags.
		****************************************/

 template<class Config>
       struct AVX_MM256_XOR<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                  wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/
		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_XOR).name() },
			   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_xor_ps" },
			                                                             { get_latency(), get_throughput() } } });
		   }

		   
 };

 template<class Config>
        struct AVX_MM256_XOR<Config,
	          typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                        wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                               wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


			typedef typename Config::CpuCycles LATENCY;

			typedef typename Config::ReciprocalThroughput THROUGHPUT;

			typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
				                         WRF_CPP_CONST WRF_STRING>,
				                   std::pair < LATENCY, THROUGHPUT >> PerfMap;

			static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

			static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

			static auto get_latency()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						          constexpr LATENCY { return (m_latency); }

			static auto get_throughput()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						          constexpr THROUGHPUT { return (m_throughput); }

			/********************************************
			Notification:
			It is unknown if ICC will inline
			chain of objects creation.
			Here we have
			1) Inlining call to TypeMap Ctor.
			2) Inlining call to String Ctor.
			3) Inlining call to std::pair Ctor.
			4) Inlining call to String objects Ctors.
			Please bear in mind that std::pair Ctor
			should have a support of initializer list object,
			as in case of String Ctor.
			*********************************************/

			WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

				using namespace ttags;
				return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_XOR).name() },
				{ WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
				  WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

				using namespace ttags;
				return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_xor_ps" },
				                                                       { get_latency(), get_throughput() } } });
			}
 };

 template<class Config>
        struct AVX_MM256_XOR<Config,
			typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
			                wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
				                wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag > {


			typedef typename Config::CpuCycles LATENCY;

			typedef typename Config::ReciprocalThroughput THROUGHPUT;

			typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
				                        WRF_CPP_CONST WRF_STRING>,
				              std::pair < LATENCY, THROUGHPUT >> PerfMap;

			static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

			static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

			static auto get_latency()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						          constexpr LATENCY { return (m_latency); }

			static auto get_throughput()
				       WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

			/********************************************
			Notification:
			It is unknown if ICC will inline
			chain of objects creation.
			Here we have
			1) Inlining call to TypeMap Ctor.
			2) Inlining call to String Ctor.
			3) Inlining call to std::pair Ctor.
			4) Inlining call to String objects Ctors.
			Please bear in mind that std::pair Ctor
			should have a support of initializer list object,
			as in case of String Ctor.
			*********************************************/

			WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

				using namespace ttags;
				return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_XOR).name() },
				{ WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
				  WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

				using namespace ttags;
				return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_xor_ps" },
				                                                    { get_latency(), get_throughput() } } });
			}
		};

 template<class Config>
        struct AVX_MM256_XOR<Config,
	         typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                             wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


			typedef typename Config::CpuCycles LATENCY;

			typedef typename Config::ReciprocalThroughput THROUGHPUT;

			typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
				                         WRF_CPP_CONST WRF_STRING>,
				                   std::pair < LATENCY, THROUGHPUT >> PerfMap;

			static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

			static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

			static auto get_latency()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						          constexpr LATENCY { return (m_latency); }

			static auto get_throughput()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						          constexpr THROUGHPUT { return (m_throughput); }

			/********************************************
			Notification:
			It is unknown if ICC will inline
			chain of objects creation.
			Here we have
			1) Inlining call to TypeMap Ctor.
			2) Inlining call to String Ctor.
			3) Inlining call to std::pair Ctor.
			4) Inlining call to String objects Ctors.
			Please bear in mind that std::pair Ctor
			should have a support of initializer list object,
			as in case of String Ctor.
			*********************************************/

			WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

				using namespace ttags;
				return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_XOR).name() },
				{ WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
				  WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

				using namespace ttags;
				return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_xor_pd" },
				{ get_latency(), get_throughput } } });
			} 
 };

 template<class Config>
       struct AVX_MM256_XOR<Config,
	         typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                       wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                             wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                std::pair < LATENCY, THROUGHPUT >> PerfMap;


		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }


		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_XOR).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_xor_pd" },
			                                                           { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
       struct AVX_MM256_XOR<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                        wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CP_TRUE)->
					              constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_XOR).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		       }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_xor_pd" },
			                                                       { get_latency(), get_throughput() } } });
		   }


 };


	   /***********************************************
	     Intrinsic _mm256_broadcast_ps/pd type traits.
		 Primary template.
	   ************************************************/

 template<class Config,
		              typename,
							  class CpuType_t,
									        class DataSize_t> 
                                                           struct AVX_MM256_BROADCAST;

	  /****************************************
	   Partial specializations on CpuType_t and
	   on DataSize_t tag dispatch types.
	  *****************************************/

 template<class Config>
       struct AVX_MM256_BROADCAST<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                    std::pair < LATENCY, THROUGHPUT >> PerfMap;


		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr0PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace  ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_BROADCAST).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_broadcast_ps" },
			                                                                { get_latency(), get_throughput() } } });
		   }

 };

 template<class Config>
       struct AVX_MM256_BROADCAST<Config,
	         typename  ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                              wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                   std::pair < LATENCY, THROUGHPUT >> PerfMap;


		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr0PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_BROADCAST).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_broadcast_ps" },
			                                                            { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
       struct AVX_MM256_BROADCAST<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                    wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                  std::pair < LATENCY, THROUGHPUT >> PerfMap;


		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr0PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_BROADCAST).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_broadcast_pd" },
			   { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
       struct AVX_MM256_BROADCAST<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                       wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                   std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr0PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_BROADCAST).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			   WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_broadcast_pd" },
			                                                            { get_latency(), get_throughput() } } });
		   }

 };


	   /****************************************
	    Intrinsic _mm256_load_ps/pd type traits.
	    Primary template.
	   *****************************************/

 template<class Config,
	                 typename,
					         class CpuType_t,
								           class DataSize_t>
                                                        struct AVX_MM256_LOAD;


           
		/****************************************
		 Partial specializations on CpuType_t and
		 on DataSize_t tag dispatch types.
		*****************************************/

 template<class Config>
       struct AVX_MM256_LOAD < Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                   wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                              wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_LOAD).name() },
			   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_load_ps" },
			                                                             { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
       struct AVX_MM256_LOAD<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                  std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return  (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_LOAD).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_load_ps" },
			                                                          { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
      struct AVX_MM256_LOAD<Config,
	     typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                        wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {

	      
		  typedef typename Config::CpuCycles LATENCY;

		  typedef typename Config::ReciprocalThroughput THROUGHPUT;

		  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                std::pair < LATENCY, THROUGHPUT >> PerfMap;

		  static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		  static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

		  static auto get_latency()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr LATENCY { return (m_latency); }

		  static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr THROUGHPUT { return (m_throughput); }

		  /********************************************
		  Notification:
		  It is unknown if ICC will inline
		  chain of objects creation.
		  Here we have
		  1) Inlining call to TypeMap Ctor.
		  2) Inlining call to String Ctor.
		  3) Inlining call to std::pair Ctor.
		  4) Inlining call to String objects Ctors.
		  Please bear in mind that std::pair Ctor
		  should have a support of initializer list object,
		  as in case of String Ctor.
		  *********************************************/

		  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			  using namespace ttags;
			  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_LOAD).name() },
			  { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			  using namespace ttags;
			  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_load_ps" },
			                                                      { get_latency(), get_throughput() } } });
		  }
 };

 template<class Config>
       struct AVX_MM256_LOAD<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                   wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                  std::pair < LATENCY, THROUGHPUT >> PerfMap;


		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr THROUGHPUT { return (m_throughput); }


		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_LOAD).name() },
			   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_load_pd" },
			                                                             { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
       struct AVX_MM256_LOAD<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                            wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                  std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					               constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_LOAD).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_tintrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_load_pd" },
			                                                            { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
       struct AVX_MM256_LOAD<Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                    std::pair < LATENCY, THROUGHPUT >> PerfMap;


		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_LOAD).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_load_pd" },
			                                                        { get_latency(), get_throughput() } } });
		   }
 };


	   /******************************************
	    Intrinsic _mm256_store_ps/pd type triats.
		Primary template.
	   *******************************************/

 template<class Config,
	                  typename,
					          class CpuType_t,
								             class DataSize_t>
                                                            struct AVX_MM256_STORE;

       
		/****************************************
		 Partial specializations on CpuType_t and
	  	 on DataSize_t tag dispatch types.
		*****************************************/

 template<class Config>
       struct AVX_MM256_STORE<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                   wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_STORE).name() },
			   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_store_ps" },
			                                                              { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
        struct AVX_MM256_STORE<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                    wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


			typedef typename Config::CpuCycles LATENCY;

			typedef typename Config::ReciprocalThroughput THROUGHPUT;

			typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
				                         WRF_CPP_CONST WRF_STRING>,
				                std::pair < LATENCY, THROUGHPUT >> PerfMap;

			static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

			static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

			static auto get_latency()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						            constexpr LATENCY { return (m_latency); }

			static auto get_throughput()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						            constexpr THROUGHPUT { return (m_throughput); }

			/********************************************
			Notification:
			It is unknown if ICC will inline
			chain of objects creation.
			Here we have
			1) Inlining call to TypeMap Ctor.
			2) Inlining call to String Ctor.
			3) Inlining call to std::pair Ctor.
			4) Inlining call to String objects Ctors.
			Please bear in mind that std::pair Ctor
			should have a support of initializer list object,
			as in case of String Ctor.
			*********************************************/

			WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

				using namespace ttags;
				return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_STORE).name() },
				{ WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
				WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

				using namespace ttags;
				return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_store_ps" },
				                                                        { get_latency(), get_throughput() } } });
			}
 };

 template<class Config>
       struct AVX_MM256_STORE<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                    wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_STORE).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_store_ps" },
			                                                         { get_latency(), get_throughput() } } });
		   }

 };

 template<class Config> 
       struct AVX_MM256_STORE<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                 wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                         wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					               constexpr LATENCY  { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)-> 
					              constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_STORE).name() },
			   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag) } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_store_pd" },
			   { get_latency(), get_throughput() } } });
		   }
 };

 template<class Config>
      struct AVX_MM256_STORE<Config,
	     typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                 wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                       wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		  typedef typename Config::CpuCycles LATENCY;

		  typedef typename Config::ReciprocalThroughput THROUGHPUT;

		  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                  std::pair < LATENCY, THROUGHPUT >> PerfMap;

		  static auto get_latency()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		  static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		  /********************************************
		  Notification:
		  It is unknown if ICC will inline
		  chain of objects creation.
		  Here we have
		  1) Inlining call to TypeMap Ctor.
		  2) Inlining call to String Ctor.
		  3) Inlining call to std::pair Ctor.
		  4) Inlining call to String objects Ctors.
		  Please bear in mind that std::pair Ctor
		  should have a support of initializer list object,
		  as in case of String Ctor.
		  *********************************************/

		  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			  using namespace ttags;
			  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_STORE).name() },
			  { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			  using namespace ttags;
			  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_store_pd" },
			                                                          { get_latency(), get_throughput() } } });
		  }
 };

 template<class Config>
       struct AVX_MM256_STORE<Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                    wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                        wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                      std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr0_5PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_STORE).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_store_pd" },
			                                                         { get_latency(), get_throughput() } } });
		   }
 };

 

	   /********************************************
	    Intrinsic _mm256_setzero_ps/pd type traits.
		Primary template.
	   *********************************************/

 template<class Config,
	                 typename,
					        class CpuType_t,
								           class DataSize_t>
                                                       struct AVX_MM256_SETZERO;


	  /******************************************
	   Partial specializations on CpuType_t and
	  	 on DataSize_t tag dispatch types.
	  ******************************************/

 template<class Config>
        struct AVX_MM256_SETZERO<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                        wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


			typedef typename Config::CpuCycle LATENCY;

			typedef typename Config::ReciprocalThroughput THROUGHPUT;

			typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
				                         WRF_CPP_CONST WRF_STRING>,
				                std::pair < LATENCY, THROUGHPUT >> PerfMap;

			static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

			static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

			static constexpr WRF_INT m_fused_uops{ 1 };

			static const WRF_INT m_unfused_uops{ 2 + Config::is_memory_load() };

			static auto get_latency()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						           constexpr LATENCY { return (m_latency); }

			static auto get_throughput()
				       WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					               constexpr THROUGHPUT { return (m_throughput); }

			static auto get_fused_uops()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						           constexpr WRF_INT { return (m_fused_uops); }

			static auto get_unfused_uops()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						           const WRF_INT{ return (m_unfused_uops); }

			/********************************************
			Notification:
			It is unknown if ICC will inline
			chain of objects creation.
			Here we have
			1) Inlining call to TypeMap Ctor.
			2) Inlining call to String Ctor.
			3) Inlining call to std::pair Ctor.
			4) Inlining call to String objects Ctors.
			Please bear in mind that std::pair Ctor
			should have a support of initializer list object,
			as in case of String Ctor.
			*********************************************/

			WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

				using namespace ttags;
				return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_SETZERO).name() },
				{ WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
				  WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

				using namespace ttags;
				return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_setzero_ps" },
				                                                             { get_latency(), get_throughput() } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

				return (ic::UopFusedMap{ { "_mm256_setzero_ps on Sandy_Bridge -> fused micro-ops: ", 
					                                                          get_fused_uops() } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

				ic::UopUnfusedMap *pUUfusedMap = new ic::UopUnfusedMap();
				(*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
				(*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
				(*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 0);
				(*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 1);
				(*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
				(*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

				return (std::make_unique<ic::UopUnfusedMap>(*pUUfusedMap));
			}
 };

 template<class Config>
       struct AVX_MM256_SETZERO<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			   WRF_CPP_CONST WRF_STRING>,
			   std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 1 };

		   static const WRF_INT m_unfused_uops{ 2 + Config::is_memory_load() };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr WRF_INT { return (m_fused_uops); }

		   static auto get_unfused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             const WRF_INT{ return (m_unfused_uops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_SETZERO).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_setzero_ps" },
			                                                              { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_setzero_ps on Ivy_Bridge -> fused micro-ops: ", 
				                                                            get_fused_uops() } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			   ic::UopUnfusedMap *pUUfusedMap = new ic::UopUnfusedMap();
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 0);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 1);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*pUUfusedMap));
		   }
 };

 template<class Config>
       struct AVX_MM256_SETZERO<Config,
	     typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                   wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                  std::pair < LATENCY, THROUGHPUT >> PerfMap;


		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 1 };

		   static const WRF_INT m_unfused_uops{ 1 + Config::is_memory_load() };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->constexpr WRF_INT { return (m_fused_uops); }

		   static auto get_unfused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->const WRF_INT{ return (m_unfused_uops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_SETZERO).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_setzero_ps" },
			                                                           { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_setzero_ps on Haswell -> fused micro-ops: ", 
				                                                       get_fused_uops() } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			   ic::UopUnfusedMap *pUUfusedMap = new ic::UopUnfusedMap();
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 0);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 1);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port6: " }, 0);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port7: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*pUUfusedMap));
		   }
 };

 template<class Config>
      struct AVX_MM256_SETZERO<Config,
	     typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	              wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		  typedef typename Config::CpuCycles LATENCY;

		  typedef typename Config::ReciprocalThroughput THROUGHPUT;

		 typedef  std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			               std::pair < LATENCY, THROUGHPUT >> PerfMap;

		  static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		  static constexpr WRF_INT m_fused_uops{ 1 };

		  static const WRF_INT m_unfused_uops{ 2 + Config::is_memory_load() };

		  static auto get_latency()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr LATENCY { return (m_latency); }

		  static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr THROUGHPUT { return (m_throughput); }

		  static auto get_fused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->constexpr WRF_INT { return (m_fused_uops); }

		  static auto get_unfused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->const WRF_INT{ return (m_unfused_uops); }

		  /********************************************
		  Notification:
		  It is unknown if ICC will inline
		  chain of objects creation.
		  Here we have
		  1) Inlining call to TypeMap Ctor.
		  2) Inlining call to String Ctor.
		  3) Inlining call to std::pair Ctor.
		  4) Inlining call to String objects Ctors.
		  Please bear in mind that std::pair Ctor
		  should have a support of initializer list object,
		  as in case of String Ctor.
		  *********************************************/

		  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			  using namespace ttags;
			  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_SETZERO).name() },
			  { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		      }

		  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			  using namespace ttags;
			  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_setzero_pd" },
			                                                              { get_latency(), get_throughput() } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			  return (ic::UopFusedMap{ { "_mm256_setzero_pd on Sandy_Bridge -> fused micro-ops: ",
				                                                              get_fused_uops() } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			  ic::UopUnfusedMap *pUUfusedMap = new ic::UopUnfusedMap();
			  (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_pd_descr()] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			  (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_pd_descr()] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			  (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_pd_descr()] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 0);
			  (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_pd_descr()] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 1);
			  (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_pd_descr()] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			  (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_pd_descr()] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			  return (std::make_unique<ic::UopUnfusedMap>(*pUUfusedMap));
		  }
 };

 template<class Config>
       struct AVX_MM256_SETZERO<Config,
	     typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {



		   typedef typename  Config::CpuCycles LATENCY;

		   typedef typename  Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 1 };

		   static const WRF_INT m_unfused_uops{ 2 + Config::is_memory_load() };


		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr WRF_INT { return (m_fused_uops); }

		   static auto get_unfused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            const WRF_INT { return (m_unfused_uops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_SETZERO).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_setzero_pd" },
			                                                              { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_setzero_pd on Ivy_Bridge -> fused micro-ops: ",
				                                                             get_fused_uops() } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			   ic::UopUnfusedMap *pUUfusedMap = new ic::UopUnfusedMap();
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 0);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 1);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_zero_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*pUUfusedMap));
		   }
 };


 template<class Config>
       struct AVX_MM256_SETZERO<Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                         wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                   std::pair < LATENCY, THROUGHPUT >> PerfMap;


		   static constexpr LATENCY m_latency = Config::Lat1PipeCycle;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					               constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					               constexpr THROUGHPUT { return (m_throughput); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto  get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_SETZERO)name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_setzero_pd" },
			   { get_latency(), get_throughput() } } });
		   }
 };


     
	   /******************************************
	    Intrinsic _mm256_floor_ps/pd type traits.
		Primary template.
	   *******************************************/

 template<class Config,
	                 typename,
					         class CpuType_t,
								           class DataSize_t>
                                                          struct AVX_MM256_FLOOR;



		 /******************************************
		  Partial specializations on CpuType_t and
		  on DataSize_t tag dispatch types.
		 ******************************************/

 template<class Config>
      struct AVX_MM256_FLOOR<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		  typedef typename Config::CpuCycles LATENCY;

		  typedef typename Config::ReciprocalThroughput THROUGHPUT;

		  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			              std::pair < LATENCY, THROUGHPUT >> PerfMap;

		  static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		  static constexpr WRF_INT m_fused_uops{ 1 };

		  static auto get_latency()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr LATENCY { return (m_latency); }

		  static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr THROUGHPUT { return (m_throughput); }

		  static auto get_fused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr WRF_INT { return (m_fused_uops); }

		  /********************************************
		  Notification:
		  It is unknown if ICC will inline
		  chain of objects creation.
		  Here we have
		  1) Inlining call to TypeMap Ctor.
		  2) Inlining call to String Ctor.
		  3) Inlining call to std::pair Ctor.
		  4) Inlining call to String objects Ctors.
		  Please bear in mind that std::pair Ctor
		  should have a support of initializer list object,
		  as in case of String Ctor.
		  *********************************************/

		  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			  using namespace ttags;
			  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FLOOR).name() },
			  { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			  using namespace ttags;
			  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_floor_ps" },
			                                                             { get_latency(), get_throughput() } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			  return (ic::UopFusedMap{ { "_mm256_floor_ps on Sandy_Bridge -> fused micro-ops: ", get_fused_uops() } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			  ic::UopUnfusedMap *puufused_map = new ic::UopUnfusedMap();
			  (*puufused_map)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			  (*puufused_map)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			  (*puufused_map)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			  (*puufused_map)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			  return (std::make_pair<ic::UopUnfusedMap>(*puufused_map));
		  }
 };

 template<class Config>
       struct AVX_MM256_FLOOR<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                   wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                       wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                  std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 1 };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr WRF_INT { return (m_fused_uops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FLOOR).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_floor_ps" },
			                                                            { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_floor_ps on Ivy_Bridge -> fused micro-ops: ", 
				                                                         get_fused_uops() } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			   ic::UopUnfusedMap *puufused_map = new ic::UopUnfusedMap(); //pUUnfusedMap;
			   (*puufused_map)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			   (*puufused_map)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			   (*puufused_map)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			   (*puufused_map)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		   }
 };

 template<class Config>
       struct AVX_MM256_FLOOR<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                         wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                     std::pair < LATENCY, THROUGHPUT >> PerfMap;


		   static constexpr LATENCY m_latency = Config::Lat6PipeCycles;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 2 };

		   static const WRF_INT m_unfused_uops{ 2 + Config::is_memory_load() };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr WRF_INT { return (m_fused_uops); }

		   static auto get_unfused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            const WRF_INT{ return (m_unfused_uops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FLOOR).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_floor_ps" },
			                                                         { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_floor_ps on Haswell -> fused micro-ops: ", get_fused_uops() } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			   ic::UopUnfusedMap *pUUnfusedMap = new ic::UopUnfusedMap();
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 2);
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port23: " }, Config::is_memory_load());
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port6: " }, 0);
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port7: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*pUUnfusedMap));
		   }
 };

 template<class Config>
       struct AVX_MM256_FLOOR<Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                  wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 1 };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					          constexpr WRF_INT { return (m_fused_uops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FLOOR).name() },
			   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_floor_pd" },
			                                                              { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_floor_pd on Sandy_Bridge -> fused micro-ops: ", get_fused_uops() } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			   ic::UopUnfusedMap *pUUnfusedMap = new ic::UopUnfusedMap();
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			   (*pUUnfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*pUUnfusedMap));
		   }

 };

 template<class Config>
       struct AVX_MM256_FLOOR<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                   wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                        wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 1 };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }


		   static auto get_fused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr WRF_INT { return (m_fused_uops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FLOOR).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_floor_pd" },
			                                                            { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_floor_pd on Ivy_Bridge -> fused micro-ops: ", get_fused_uops() } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			   ic::UopUnfusedMap *pUUfusedMap = new ic::UopUnfusedMap();
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			   (*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*pUUfusedMap));
		   }
 };

 template<class Config>
        struct AVX_MM256_FLOOR<Config,
	         typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                        wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


			typedef typename Config::CpuCycles LATENCY;

			typedef typename Config::ReciprocalThroughput THROUGHPUT;

			typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
				                         WRF_CPP_CONST WRF_STRING>,
				                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

			static constexpr LATENCY m_latency = Config::Lat6PipeCycles;

			static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

			static constexpr WRF_INT m_fused_uops{ 2 };

			static const WRF_INT m_unfused_uops{ 2 + Config::is_memory_load() };

			static auto get_latency()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
				                  constexpr LATENCY { return (m_latency); }

			static auto get_throughput()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						          constexpr THROUGHPUT { return (m_throughput); }

			static auto get_fused_uops()
				       WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr WRF_INT { return (m_fused_uops); }

			static auto get_unfused_uops()
				       WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             const WRF_INT{ return (m_unfused_uops); }

			/********************************************
			Notification:
			It is unknown if ICC will inline
			chain of objects creation.
			Here we have
			1) Inlining call to TypeMap Ctor.
			2) Inlining call to String Ctor.
			3) Inlining call to std::pair Ctor.
			4) Inlining call to String objects Ctors.
			Please bear in mind that std::pair Ctor
			should have a support of initializer list object,
			as in case of String Ctor.
			*********************************************/

			WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

				using namespace ttags;
				return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_FLOOR).name() },
				{ WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
				  WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

				using namespace ttags;
				return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_floor_pd" },
				{ get_latency(), get_throughput() } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

				return (ic::UopFusedMap{ { "_mm256_floor_pd on Haswell -> fused micro-ops: ", get_fused_uops() } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

				ic::UopUnfusedMap *pUUfusedMap = new ic::UopUnfusedMap();
				(*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
				(*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 2);
				(*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
				(*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);
				(*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
				(*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port6: " }, 0);
				(*pUUfusedMap)[ic::PortDecompHelper::uops_floor_pd_descr()] = 
					           ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port7: " }, 0);

				return (std::make_unique<ic::UopUnfusedMap>(*pUUfusedMap));
			}
 };



		/*****************************************
		 Intrinsic _mm256_ceil_ps/pd type triats.
		 Primary template.
		******************************************/

 template<class Config,
	                 typename,
					         class CpuType_t,
								            class Data_Size_t>
                                                           struct AVX_MM256_CEIL;

		 /******************************************
		   Partial specializations on CpuType_t and
		   on DataSize_t tag dispatch types.
	     ******************************************/

 template<class Config>
       struct AVX_MM256_CEIL<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                  wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 1 };

		   static const WRF_INT m_unfused_uops{ 2 + Config::is_memory_load() };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr WRF_INT {
                                                       return (m_fused_uops); }

		   static auto get_unfused_uops()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->const WRF_INT{ return (m_unfused_uops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CEIL).name() },
			   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_ceil_ps" },
			                                                             { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_ceil_ps on Sandy_Bridge -> fused micro-ops: ", get_fused_uops() } });
		   }

		   /********************************************
		    Execution Ports micro-ops distribution map.
		   ***********************************************/
		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {
			   /*****************************
			    This dynamic memory allocation
				should not throw in theory a
				bad_alloc exception.
			   ******************************/
			   ic::UopUnfusedMap *puufused_map = new ic::UopUnfusedMap();
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		   }
 };

 template<class Config>
       struct AVX_MM256_CEIL<Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                    wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                    std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 1 };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr WRF_INT { return (m_fused_uops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CEIL).name() },
			   { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_ceil_ps" },
			                                                          { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_ceil_ps on Ivy_Bridge -> fused micro_ops: ", get_fused_uops() } });
		   }

		   /********************************************
		   Execution Ports micro-ops distribution map.
		   ***********************************************/
		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {
			   /*****************************
			   This dynamic memory allocation
			   should not throw in theory a
			   bad_alloc exception.
			   ******************************/
			   ic::UopUnfusedMap *puufused_map = new ic::UopUnfusedMap();
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		   }
 };

 template<class Config>
       struct AVX_MM256_CEIL<Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                    wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                       wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                   std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat6PipeCycles;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 2 };

		   static const WRF_INT m_unfused_uops{ 2 + Config::is_memory_load() };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					          constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					          constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					                     constexpr LATENCY {
                           return (m_fused_uops); }

		   static auto get_unfused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             const WRF_INT{ return (m_unfused_uops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CEIL).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_ceil_ps" },
			                                                        { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_ceil_ps on Haswell -> fused micro-ops: ", get_fused_uops() } });
		   }

		   /********************************************
		   Execution Ports micro-ops distribution map.
		   Only approximation in case of Haswell CPU.
		   ***********************************************/
		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {
			   /*****************************
			   This dynamic memory allocation
			   should not throw in theory a
			   bad_alloc exception.
			   ******************************/
			   ic::UopUnfusedMap *puufused_map = new ic::UopUnfusedMap();
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 2);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port6: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port7: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		   }
 };

 template<class Config>
       struct AVX_MM256_CEIL<Config,
	      typename traits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                        wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                  std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_ops{ 1 };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr WRF_INT { return (m_fused_ops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CEIL).name() },
			   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_06_0D_t_tag).name() }, " _mm256_ceil_pd" },
			                                                      { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_ceil_pd on Sandy_Bridge -> fused micro-ops: ", get_fused_uops() } });
		   }

		   /********************************************
		   Execution Ports micro-ops distribution map.
		  
		   ***********************************************/
		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {
			   /*****************************
			   This dynamic memory allocation
			   should not throw in theory a
			   bad_alloc exception.
			   ******************************/
			   ic::UopUnfusedMap *puufused_map = new ic::UopUnfusedMap();
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		   }
 };

 template<class Config>
      struct AVX_MM256_CEIL<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                    wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		  typedef typename Config::CpuCycles LATENCY;

		  typedef typename Config::ReciprocalThroughput THROUGHPUT;

		  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

		  static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		  static constexpr WRF_INT m_fused_uops{ 1 };

		  static auto get_latency()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					          constexpr LATENCY { return (m_latency); }

		  static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					          constexpr THROUGHPUT { return (m_throughput); }

		  static auto get_fused_uops()
			         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					          constexpr WRF_INT { return (m_fused_uops); }

		  /********************************************
		  Notification:
		  It is unknown if ICC will inline
		  chain of objects creation.
		  Here we have
		  1) Inlining call to TypeMap Ctor.
		  2) Inlining call to String Ctor.
		  3) Inlining call to std::pair Ctor.
		  4) Inlining call to String objects Ctors.
		  Please bear in mind that std::pair Ctor
		  should have a support of initializer list object,
		  as in case of String Ctor.
		  *********************************************/

		  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			  using namespace ttags;
			  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CEIL).name() },
			  { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			  using namespace ttags;
			  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm25_ceil_pd" },
			                                                            { get_latency(), throughput() } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			  return (ic::UopFusedMap{ { "_mm256_ceil_pd on Ivy_Bridge -> fused micro-ops: ", get_fused_uops() } });
		  }

		  /********************************************
		  Execution Ports micro-ops distribution map.

		  ***********************************************/
		  WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {
			  /*****************************
			  This dynamic memory allocation
			  should not throw in theory a
			  bad_alloc exception.
			  ******************************/
			  ic::UopUnfusedMap *puufused_map = new ic::UopUnfusedMap();
			  (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			  (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			  (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			  (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			  return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		  }

 };

 template<class Config>
       struct AVX_MM256_CEIL<Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                        wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			   WRF_CPP_CONST WRF_STRING>,
			   std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat6PipeCycles;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 2 };

		   static const WRF_INT m_unfused_uops{ 2 + Config::is_memory_load() };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					                    constexpr WRF_INT {
                                          return (m_fused_uops); }

		   static auto get_unfused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					          const WRF_INT{ return (m_unfused_uops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_CEIL).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_ceil_pd" },
			                                                        { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_ceil_pd on Haswell -> fused micro-ops: ", get_fused_uops() } });
		   }

		   /*
		     Execution Ports micro-ops distribution map.
			 Approximation on Haswell CPU.
		   */
		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {
			   /*
			    This dynamic memory allocation
			    should not throw in theory a
			    bad_alloc exception.
			   */
			   ic::UopUnfusedMap *puufused_map = new ic::UopUnfusedMap();
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 2);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port6: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_ceil_pd_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port7: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		   }
 };


	   /****************************************
	    Intrinsic _mm256_max_ps/pd type traits.
		Primary template.
	   ****************************************/

 template<class Config,
	                 typename,
					         class CpuType_t,
								           class DataSize_t>
                                                           struct AVX_MM256_MAX;

       
        

	 /******************************************
	   Partial specializations on CpuType_t and
	   on DataSize_t tag dispatch types.
	 ******************************************/

 template<class Config>
      struct AVX_MM256_MAX<Config,
	     typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                 wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                         wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		  typedef typename Config::CpuCycles LATENCY;

		  typedef typename Config::RecioricalThroughput THROUGHPUT;

		  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                 std::pair < LATENCY, THROUGHPUT >> PerfMap;

		  static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		  static constexpr WRF_INT m_fused_uops{ 1 };

		  static auto get_latency()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					          constexpr LATENCY { return (m_latency); }

		  static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					          constexpr THROUGHPUT { return (m_throughput); }

		  static auto get_fused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					          constexpr WRF_INT { return (m_fused_uops); }

		  /********************************************
		  Notification:
		  It is unknown if ICC will inline
		  chain of objects creation.
		  Here we have
		  1) Inlining call to TypeMap Ctor.
		  2) Inlining call to String Ctor.
		  3) Inlining call to std::pair Ctor.
		  4) Inlining call to String objects Ctors.
		  Please bear in mind that std::pair Ctor
		  should have a support of initializer list object,
		  as in case of String Ctor.
		  *********************************************/

		  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			  using namespace ttags;
			  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MAX).name() },
			  { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			  using namespace ttags;
			  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_max_ps" },
			                                                          { get_latency(), get_throughput() } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			  return (ic::UopFusedMap{ { " _mm256_max_ps on Sandy_Bridge -> fused micro-ops: ", get_fused_uops() } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			  /*************************************
			   Small dynamic allocation
			   should not throw bad_alloc exception.
			  **************************************/
			  ic::UopUnfusedMap* puufused_map = new ic::UopUnfusedMap();
			  (*puufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ " Ports015: " }, 1);
			  (*puufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ " Port0: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ " Port1: " }, 1)
		      (*puufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = 
			                  ic::PortDecompHelper::set_port_value(WRF_STRING{ " Port5: " }, 0)
			  (*puufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = 
			                  ic::PortDecompHelper::set_port_value(WRF_STRING{ " Ports23: " }, Config::is_memory_load());
			  (*puufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ " Port4: " }, 0);

			  return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		  }
 };

 template<class Config>
      struct AVX_MM256_MAX<Config,
	     typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                  wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                         wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		  typedef typename Config::CpuCycles LATENCY;

		  typedef typename Config::ReciprocalThroughput THROUGHPUT;

		  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                   std::pair < LATENCY, THROUGHPUT >> PerfMap;

		  static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		  static constexpr WRF_INT m_fused_uops{ 1 };

		  static auto get_latency()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr LATENCY { return (m_latency); }

		  static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr THROUGHPUT { return (m_throughput); }

		  static auto get_fused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					              constexpr WRF_INT { return (m_fused_uops); }

		  /********************************************
		  Notification:
		  It is unknown if ICC will inline
		  chain of objects creation.
		  Here we have
		  1) Inlining call to TypeMap Ctor.
		  2) Inlining call to String Ctor.
		  3) Inlining call to std::pair Ctor.
		  4) Inlining call to String objects Ctors.
		  Please bear in mind that std::pair Ctor
		  should have a support of initializer list object,
		  as in case of String Ctor.
		  *********************************************/

		  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			  using namespace ttags;
			  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MAX).name() },
			  { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			  using namespace ttags;
			  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_max_ps" },
			                                                         { get_latency(), get_throughput() } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			  return (ic::UopFusedMap{ { " _mm256_max_ps on Ivy_Bridge -> fused micro-ops: ", get_fused_uops() } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			  ic::UopUnfusedMap* puufused_map = new ic::UopUnfusedMap();
			  (*puufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ " Ports015: " }, 1);
			  (*puufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ " Port0: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ " Port1: " }, 1);
			  (*puufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ " Port5: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ " Ports23: " }, (Config::LoadSource) ? 1 : 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ " Port4: " }, 0);
			  return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		  }
		
 };

 template<class Config>
      struct AVX_MM256_MAX<Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		  typedef typename Config::CpuCycles LATENCY;

		  typedef typename Config::ReciprocalThroughput THROUGHPUT;

		  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                     std::pair < LATENCY, THROUGHPUT >> PerfMap;

		  static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		  static constexpr WRF_INT m_fused_uops{ 1 };

		  static const WRF_INT m_unfused_uops{ (Config::LoadSource) ? 1 : 0 };

		  static auto get_latency()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr LATENCY { return (m_latency); }

		  static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					           constexpr THROUGHPUT { return (m_throughput); }

		  static auto get_fused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					                       constexpr WRF_INT {
                                                      return (m_fused_uops); }

		  static auto get_unfused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             const WRF_INT{ return (m_unfused_uops); }

		  /********************************************
		  Notification:
		  It is unknown if ICC will inline
		  chain of objects creation.
		  Here we have
		  1) Inlining call to TypeMap Ctor.
		  2) Inlining call to String Ctor.
		  3) Inlining call to std::pair Ctor.
		  4) Inlining call to String objects Ctors.
		  Please bear in mind that std::pair Ctor
		  should have a support of initializer list object,
		  as in case of String Ctor.
		  *********************************************/

		  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			  using namespace ttags;
			  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MAX).name() },
			  { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			  using namespace ttags;
			  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_max_ps" },
			                                                         { get_latency(), get_throughput() } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			  return (ic::UopFusedMap{ { " _mm256_max_ps on Haswell -> fused micro-ops: " , get_fused_uops() } })
		  }

		  /*******************************************
		   Execution Port micro-ops distrubution map.
		  ********************************************/
		  WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			  ic::UopUnfusedMap* uufused_map = new ic::UopUnfusedMap();
			  (*uufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			  (*uufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			  (*uufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, (Config::LoadSource) ? 1 : 0);
			  (*uufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);
			  (*uufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			  (*uufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port6: " }, 0);
			  (*uufused_map)[ic::PortDecompHelper::uops_max_ps_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port7: " }, 0);
			  return (std::make_unique<ic::UopUnfusedMap>(*uufused_map));
		  }
 };

 template<class Config>
       struct AVX_MM256_MAX < Config,
	     typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	              wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                       wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                     std::pair < LATENCY, THROUGHPUT >> PerfMap;

		   static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 1 };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr WRF_INT { return (m_fused_uops); }

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MAX).name() },
			   { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_max_pd" },
			                                                            { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { "_mm256_max_pd on Sandy_Bridge -> fused micro_ops: ", get_fused_uops() } });
		   }

		   /*******************************************
		    Execution Ports micro-ops distribution map.
		   ********************************************/
		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			   /*********************************
			    Dynamic allocation should
				not throw bad_alloc exception.
			   *********************************/
			   ic::UopUnfusedMap* puufused_map = new ic::UopUnfusedMap();
			   (*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ " Ports015: " }, 1);
			   (*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ " Port0: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ " Port1: " }, 1);
			   (*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ " Port5: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ " Ports23: " }, (Config::LoadSource) ? 1 : 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = ic::PortDecompHelper::set_port_value(WRF_STRING{ " Port4: " }, 0);
			   return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		   }
 };

 template<class Config>
        struct AVX_MM256_MAX<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                            wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


			typedef typename Config::CpuCycles LATENCY;

			typedef typename Config::ReciprocalThroughput THROUGHPUT;

			typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
				                         WRF_CPP_CONST WRF_STRING>,
				                  std::pair < LATENCY, THROUGHPUT >> PerfMap;

			static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

			static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

			static constexpr WRF_INT m_fused_uops{ 1 };

			static auto get_latency()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						           constexpr LATENCY { return (m_latency); }

			static auto get_throughput()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						           constexpr THROUGHPUT { return (m_throughput); }

			static auto get_fused_uops()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						           constexpr WRF_INT { return (m_fused_uops); }

			/********************************************
			Notification:
			It is unknown if ICC will inline
			chain of objects creation.
			Here we have
			1) Inlining call to TypeMap Ctor.
			2) Inlining call to String Ctor.
			3) Inlining call to std::pair Ctor.
			4) Inlining call to String objects Ctors.
			Please bear in mind that std::pair Ctor
			should have a support of initializer list object,
			as in case of String Ctor.
			*********************************************/

			WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

				using namespace ttags;
				return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MAX).name() },
				{ WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
				  WRF_STRING{ typeid(cpu_arch_int64_t_tag).name() } } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

				using namespace ttags;
				return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_max_pd" },
				                                                       { get_latency(), get_throughput() } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

				return (ic::UopFusedMap{ { " _mm256_max_pd on Ivy_Bridge -> fused micro-ops: ", get_fused_uops() } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

				ic::UopUnfusedMap* puufused_map = new ic::UopUnfusedMap();
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                       ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                       ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                       ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                       ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                       ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, (Config::LoadSource) ? 1 : 0);
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                       ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

				return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
			}
 };

 template<class Config>
        struct AVX_MM256_MAX<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                       wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                          wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


			typedef typename Config::CpuCycles LATENCY;

			typedef typename Config::ReciprocalThroughput THROUGHPUT;

			typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
				                         WRF_CPP_CONST WRF_STRING>,
				               std::pair < LATENCY, THROUGHPUT >> PerfMap;

			static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

			static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

			static constexpr WRF_INT m_fused_uops{ 1 };

			static const WRF_INT m_unfused_uops{ (Config::LoadSource) ? 1 : 0 };

			static auto get_latency()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						            constexpr LATENCY { return (m_latency); }

			static auto get_throughput()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						            constexpr THROUGHPUT { return (m_throughput); }

			static auto get_fused_uops()
				       WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					                       constexpr WRF_INT {
                                                return (m_fused_uops); }

			static auto get_unfused_uops()
				       WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					                   const WRF_INT{ return (m_unfused_uops); }

			/********************************************
			Notification:
			It is unknown if ICC will inline
			chain of objects creation.
			Here we have
			1) Inlining call to TypeMap Ctor.
			2) Inlining call to String Ctor.
			3) Inlining call to std::pair Ctor.
			4) Inlining call to String objects Ctors.
			Please bear in mind that std::pair Ctor
			should have a support of initializer list object,
			as in case of String Ctor.
			*********************************************/

			WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

				using namespace ttags;
				return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MAX).name() },
				{ WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
				  WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

				using namespace ttags;
				return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_max_pd" },
				                                                    { get_latency(), get_throughput() } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

				return (ic::UopFusedMap{ { "_mm256_max_pd on Haswell -> fused micro-ops: " }, get_fused_uops() });
			}

			/********************************************
			 Execution Port micro-ops distribution map.
			**********************************************/
			WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

				ic::UopUnfusedMap* puufused_map = new ic::UopUnfusedMap();
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                                 ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                                 ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                                 ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                                 ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                                 ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                                 ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port6: " }, 0);
				(*puufused_map)[ic::PortDecompHelper::uops_max_pd_descr()] = 
					                                 ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port7: " }, 0);

				return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
			}
 };


		/*********************************************
		 Intrinsic _mm256_min_ps/pd type traits.
		 Primary template.
		**********************************************/

 template<class Config,
	                  typename,
					          class CpuType_t,
								             class DataSize_t>
                                                             struct AVX_MM256_MIN;

        
		 /******************************************
		   Partial specializations on CpuType_t and
		   on DataSize_t tag dispatch types.
		 ******************************************/

 template<class Config>
        struct AVX_MM256_MIN<Config,
	        typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                    wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                           wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {



			typedef typename Config::CpuCycles  LATENCY;

			typedef typename Config::ReciprocalThroughput THROUGHPUT;

			typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
				                         WRF_CPP_CONST WRF_STRING>,
				                     std::pair < LATENCY, THROUGHPUT >> PerfMap;


			static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

			static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

			static constexpr WRF_INT m_fused_uops{ 1 };

			static auto get_latency()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						          constexpr LATENCY { return (m_latency); }

			static auto get_throughput()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						          constexpr THROUGHPUT { return (m_throughput); }

			static auto get_fused_uops()
				        WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
						          constexpr WRF_INT { return (m_fused_uops); }

			/********************************************
			Notification:
			It is unknown if ICC will inline
			chain of objects creation.
			Here we have
			1) Inlining call to TypeMap Ctor.
			2) Inlining call to String Ctor.
			3) Inlining call to std::pair Ctor.
			4) Inlining call to String objects Ctors.
			Please bear in mind that std::pair Ctor
			should have a support of initializer list object,
			as in case of String Ctor.
			*********************************************/

			WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

				using namespace ttags;
				return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MIN).name() },
				{ WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
				  WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

				using namespace ttags;
				return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_min_ps" },
				                                                         { get_latency(), get_throughput() } } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

				return (ic::UopFusedMap{ { WRF_STRING{ "_mm256_min_ps on: Sandy_Bridge -> fused micro-ops: " }, get_fused_uops() } });
			}

			WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

				ic::UopUnfusedMap* puufused_map = new ic::UopUnfusedMap();
				(*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr] = 
					            ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
				(*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr] = 
					            ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
				(*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr] =
					            ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
				(*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr] = 
					            ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
				(*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr] = 
					            ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
				(*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr] = 
					            ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

				return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));

			}
 };

 template<class Config>
      struct AVX_MM256_MIN<Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                 wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {



		  typedef typename Config::CpuCycles LATENCY;

		  typedef typename Config::ReciprocalThroughput THROUGHPUT;

		  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                    std::pair < LATENCY, THROUGHPUT >> PerfMap;

		  static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		  static constexpr WRF_INT m_fused_uops{ 1 };

		  static auto get_latency()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		  static auto get_throughput()
			         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		  static auto get_fused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr WRF_INT { return (m_fused_uops); }

		  /********************************************
		  Notification:
		  It is unknown if ICC will inline
		  chain of objects creation.
		  Here we have
		  1) Inlining call to TypeMap Ctor.
		  2) Inlining call to String Ctor.
		  3) Inlining call to std::pair Ctor.
		  4) Inlining call to String objects Ctors.
		  Please bear in mind that std::pair Ctor
		  should have a support of initializer list object,
		  as in case of String Ctor.
		  *********************************************/

		  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			  using namespace ttags;
			  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MIN).name() },
			  { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			  using namespace ttags;
			  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_min_ps" },
			                                                         { get_latency(), get_throughput() } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			  return (ic::UopFusedMap{ { " _mm256_min_ps on: Ivy_Bridge -> fused micro-ops:  ", get_fused_uops() } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			  ic::UopUnfusedMap* pufused_map = new ic::UopUnfusedMap();
			  (*pufused_map)[ic::PortDecompHelper::uops_min_ps_descr] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			  (*pufused_map)[ic::PortDecompHelper::uops_min_ps_descr] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			  (*pufused_map)[ic::PortDecompHelper::uops_min_ps_descr] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			  (*pufused_map)[ic::PortDecompHelper::uops_min_ps_descr] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			  (*pufused_map)[ic::PortDecompHelper::uops_min_ps_descr] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			  (*pufused_map)[ic::PortDecompHelper::uops_min_ps_descr] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			  return (std::make_unique<ic::UopUnfusedMap>(*pufused_map));
		  }
 };

 template<class Config>
       struct AVX_MM256_MIN<Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                        wrf_physics::wrf_physics_internal::tags::cpu_arch_float32_t_tag> {


		   typedef typename Config::CpuCycles LATENCY;

		   typedef typename Config::ReciprocalThroughput THROUGHPUT;

		   typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                            WRF_CPP_CONST WRF_STRING>,
			                  std::pair < LATENCY, THROUGHPUT >> PerfMap;


		   static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		   static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		   static constexpr WRF_INT m_fused_uops{ 1 };

		   /* If memory load uops = 2, otherwise uops = 1*/
		   static const WRF_INT m_unfused_uops{ (Config::LoadSource) ? 2 : 1 };

		   static auto get_latency()
			           WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY { return (m_latency); }

		   static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		   static auto get_fused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr WRF_INT { return (m_fused_uops); }
			                                                          
				 
		   static auto get_unfused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					       const WRF_INT{ return (m_unfused_uops); }
						
					  

		  

		   /********************************************
		   Notification:
		   It is unknown if ICC will inline
		   chain of objects creation.
		   Here we have
		   1) Inlining call to TypeMap Ctor.
		   2) Inlining call to String Ctor.
		   3) Inlining call to std::pair Ctor.
		   4) Inlining call to String objects Ctors.
		   Please bear in mind that std::pair Ctor
		   should have a support of initializer list object,
		   as in case of String Ctor.
		   *********************************************/

		   WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			   using namespace ttags;
			   return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MIN).name() },
			   { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			     WRF_STRING{ typeid(cpu_arch_float32_t_tag).name() } } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			   using namespace ttags;
			   return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_min_ps" },
			                                                       { get_latency(), get_throughput() } } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			   return (ic::UopFusedMap{ { " _mm256_min_ps on Haswell -> fused micro-ops: ", get_fused_uops() } });
		   }

		   WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			   ic::UopUnfusedMap* puufused_map = ic::UopUnfusedMap();
			   (*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			   (*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			   (*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port6: " }, 0);
			   (*puufused_map)[ic::PortDecompHelper::uops_min_ps_descr()] = 
				               ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port7: " }, 0);

			   return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		   }
 };

 template<class Config>
      struct AVX_MM256_MIN < Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	               wrf_physics::wrf_physics_internal::tags::cpu_arch_sandy_bridge_t_tag,
	                      wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		  typedef typename Config::CpuCycles LATENCY;

		  typedef typename Config::ReciprocalThroughput THROUGHPUT;

		  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                 std::pair < LATENCY, THROUGHPUT >> PerfMap;


		  static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		  static constexpr WRF_INT m_fused_uops{ 1 };

		  static auto get_latency()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr LATENCY  { return (m_latency); }

		  static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr THROUGHPUT { return (m_throughput); }

		  static auto get_fused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					             constexpr WRF_INT { return (m_fused_uops); }

		  /********************************************
		  Notification:
		  It is unknown if ICC will inline
		  chain of objects creation.
		  Here we have
		  1) Inlining call to TypeMap Ctor.
		  2) Inlining call to String Ctor.
		  3) Inlining call to std::pair Ctor.
		  4) Inlining call to String objects Ctors.
		  Please bear in mind that std::pair Ctor
		  should have a support of initializer list object,
		  as in case of String Ctor.
		  *********************************************/

		  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			  using namespace ttags;
			  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MIN).name() },
			  { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			  using namespace ttags;
			  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_sandy_bridge_t_tag).name() }, " _mm256_min_pd" },
			                                                          { get_latency(), get_throughput() } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			  return (ic::UopFusedMap{ { WRF_STRING{ " _mm256_min_pd on Sandy_Bridge -> fused micro-ops: " }, get_fused_uops() } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			  ic::UopUnfusedMap* uufused_map = new ic::UopUnfusedMap();
			  (*uufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1)
			  (*uufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
			                 ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			  (*uufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			  (*uufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			  (*uufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			  (*uufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				             ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			  return (std::make_unique<ic::UopUnfusedMap>(*uufused_map));
		  }
 };

 template<class Config>
      struct AVX_MM256_MIN<Config,
	      typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                  wrf_physics::wrf_physics_internal::tags::cpu_arch_ivy_bridge_t_tag,
	                       wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {


		  typedef typename Config::CpuCycles LATENCY;

		  typedef typename Config::ReciprocalThroughput THROUGHPUT;

		  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                std::pair < LATENCY, THROUGHPUT >> PerfMap;


		  static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		  static constexpr WRF_INT m_fused_uops{ 1 };

		  static auto get_latency()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					               constexpr LATENCY { return (m_latency); }

		  static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					               constexpr THROUGHPUT { return (m_throughput); }

		  static auto get_fused_uops()
			         WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					               constexpr WRF_INT { return (m_fused_uops); }

		  /********************************************
		  Notification:
		  It is unknown if ICC will inline
		  chain of objects creation.
		  Here we have
		  1) Inlining call to TypeMap Ctor.
		  2) Inlining call to String Ctor.
		  3) Inlining call to std::pair Ctor.
		  4) Inlining call to String objects Ctors.
		  Please bear in mind that std::pair Ctor
		  should have a support of initializer list object,
		  as in case of String Ctor.
		  *********************************************/

		  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			  using namespace ttags;
			  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MIN).name() },
			  { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			  using namespace ttags;
			  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_ivy_bridge_t_tag).name() }, " _mm256_min_pd" },
			                                                          { get_latency(), get_throughput() } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			  return (ic::UopFusedMap{ { " _mm256_min_pd on Ivy_Bridge -> fused micro-ops: ", get_fused_uops() } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			  ic::UopUnfusedMap* puufused_map = new ic::UopUnfusedMap();
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports015: " }, 1);
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Ports23: " }, Config::is_memory_load());
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);

			  return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		  }
 };

 template<class Config>
      struct AVX_MM256_MIN<Config,
	       typename ttraits::WRF_ENABLE_IF<ttraits::WRF_IS_CLASS<Config>::value>::type,
	                     wrf_physics::wrf_physics_internal::tags::cpu_arch_haswell_t_tag,
	                       wrf_physics::wrf_physics_internal::tags::cpu_arch_float64_t_tag> {



		  typedef typename Config::CpuCycles LATENCY;

		  typedef typename Config::ReciprocalThroughput THROUGHPUT;

		  typedef std::map < std::pair<WRF_CPP_CONST WRF_STRING,
			                           WRF_CPP_CONST WRF_STRING>,
			                   std::pair < LATENCY, THROUGHPUT >> PerfMap;


		  static constexpr LATENCY m_latency = Config::Lat3PipeCycles;

		  static constexpr THROUGHPUT m_throughput = Config::Thr1PipeCycle;

		  static constexpr WRF_INT m_fused_uops{ 1 };

		  static const    WRF_INT m_unfused_uops{ Config::is_memory_load() };

		  static auto get_latency()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr LATENCY { return (m_latency); }

		  static auto get_throughput()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					            constexpr THROUGHPUT { return (m_throughput); }

		  static auto get_fused_uops()
			  WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
			                     constexpr WRF_INT {
				                        return (m_fused_uops);
			  }
			  
		  static auto get_unfused_uops()
			          WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
			                   const WRF_INT{ return (m_unfused_uops); }

		  /********************************************
		  Notification:
		  It is unknown if ICC will inline
		  chain of objects creation.
		  Here we have
		  1) Inlining call to TypeMap Ctor.
		  2) Inlining call to String Ctor.
		  3) Inlining call to std::pair Ctor.
		  4) Inlining call to String objects Ctors.
		  Please bear in mind that std::pair Ctor
		  should have a support of initializer list object,
		  as in case of String Ctor.
		  *********************************************/
		 
		  WRF_STRONG_INLINE static auto get_intrinsic_type()->ic::TypeMap {

			  using namespace ttags;
			  return (ic::TypeMap{ { WRF_STRING{ typeid(AVX_MM256_MIN).name() },
			  { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() },
			    WRF_STRING{ typeid(cpu_arch_float64_t_tag).name() } } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_perf()->PerfMap {

			  using namespace ttags;
			  return (PerfMap{ { { WRF_STRING{ typeid(cpu_arch_haswell_t_tag).name() }, " _mm256_min_pd" },
			                                                     { get_latency(), get_throughput() } } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_fused_uops()->ic::UopFusedMap {

			  return (ic::UopFusedMap{ { "_mm256_min_pd on Haswell -> fused micro-ops: ", get_fused_uops() } });
		  }

		  WRF_STRONG_INLINE static auto get_intrinsic_unfused_uops()->ic::UptrUnfusedMap {

			  ic::UopUnfusedMap* puufused_map = new ic::UopUnfusedMap();
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port0: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port1: " }, 1);
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port23: " }, Config::is_memory_load());
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port4: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port5: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port6: " }, 0);
			  (*puufused_map)[ic::PortDecompHelper::uops_min_pd_descr()] = 
				              ic::PortDecompHelper::set_port_value(WRF_STRING{ "Port7: " }, 0);

			  return (std::make_unique<ic::UopUnfusedMap>(*puufused_map));
		  }

};
 



		}
	}
}
#endif /*__WRF_INTRINSICS_AVX_TYPES_HPP__*/