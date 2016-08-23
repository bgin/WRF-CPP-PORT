
#ifndef _WRF_INTRINSICS_CONFIG_HPP_
#define _WRF_INTRINSICS_CONFIG_HPP_

#ifndef WRF_INTRINSICS_CONFIG_VERSION_MAJOR
#define WRF_INTRINSICS_CONFIG_VERSION_MAJOR 1
#endif

#ifndef WRF_INTRINSICS_CONFIG_VERSION_MINOR 
#define WRF_INTRINSICS_CONFIG_VERSION_MINOR 0
#endif

#ifndef WRF_INTRINSICS_CONFIG_CREATE_DATE
#define WRF_INTRINSICS_CONFIG_CREATE_DATE 20160729
#endif

/* Set this value to successful build date.*/
#ifndef WRF_INTRINSICS_CONFIG_BUILD_DATE
#define WRF_INTRINSICS_CONFIG_BUILD_DATE 0
#endif

#ifndef WRF_PHYS_LIB_TYPEDEFS
#include "WRF_PHYS_LIB_TYPEDEFS.h"
#endif

#include <map>

namespace wrf_physics {

	namespace wrf_physics_utils {

		namespace intrinsics_config {

			/*****************************************
				 Config object for Intrinsics types
				 ******************************************/
			
			/*******************************
			   Namespace visible typedefs
			********************************/

			typedef std::map < WRF_CPP_CONST WRF_STRING,
				               std::pair < WRF_CPP_CONST WRF_STRING, 
							               WRF_CPP_CONST WRF_STRING >> TypeMap;


			typedef std::map < WRF_CPP_CONST WRF_STRING,
				               std::pair < WRF_CPP_CONST WRF_STRING,
				                            WRF_INT >> UopUnfusedMap;

			typedef std::map<WRF_CPP_CONST WRF_STRING,
				                  WRF_INT> UopFusedMap;

			
			typedef std::unique_ptr<UopFusedMap> UptrFusedMap;

			typedef std::unique_ptr<UopUnfusedMap> UptrUnfusedMap;

			

			/*********************************************
			  Helper structures declarations/definitions
			***********************************************/

			template<typename T>
			       struct IntrinsicsConfig {



				T CpuCycles;

				T ReciprocalThroughput;

				T RelativeError;

				/**********************************************
				    CPU Latency and Throughput Pipeline Cycles.
				***********************************************/
				static constexpr T Lat5PipeCycles = static_cast<T>(5);

				static constexpr T Lat6PipeCycles = static_cast<T>(6);

				static constexpr T Lat2PipeCycles = static_cast<T>(2);

				static constexpr T Lat4PipeCycles = static_cast<T>(4);

				static constexpr T Lat7PipeCycles = static_cast<T>(7);

				static constexpr T Thr1PipeCycle = static_cast<T>(1);

				static constexpr T Lat3PipeCycles = static_cast<T>(3);

				static constexpr T Thr3PipeCycles = static_cast<T>(3);

				static constexpr T Thr0_5PipeCycle = static_cast<T>(0.5);

				static constexpr T Lat35PipeCycles = static_cast<T>(35);

				static constexpr T Lat43PipeCycles = static_cast<T>(43);

				static constexpr T Thr25PipeCycles = static_cast<T>(25);

				static constexpr T Thr28PipeCycles = static_cast<T>(28);

				static constexpr T Thr44PipeCycles = static_cast<T>(44);

				static constexpr T Lat29PipeCycles = static_cast<T>(29);

				static constexpr T Lat21PipeCycles = static_cast<T>(21);

				static constexpr T Thr28PipeCycles = static_cast<T>(28);

				static constexpr T Thr24PipeCycles = static_cast<T>(24);

				static constexpr T Thr14PipeCycles = static_cast<T>(14);

				static constexpr T Thr13PipeCycles = static_cast<T>(13);

				/* Used to describe zero - throughput instruction.*/
				static constexpr T Thr0PipeCycle   = static_cast<T>(0);

				static constexpr T RCPRelError     = static_cast<T>(0.0003662109375L);

				static constexpr T RSQRTRelError = static_cast<T>(0.0003662109375L);

				//static constexpr T RelErrorUnk = static_cast<T>(std::numeric_limits<T>::quiet_Nan());

				static constexpr WRF_BOOL LoadSource{ WRF_CPP_FALSE };

				static auto is_memory_load()->WRF_INT { return ((LoadSource) ? 1 : 0); }

			};


				   /************************************
				    Helper static functions for Micro-ops
					decomposition map descriptors.
				   ************************************/

				   struct PortDecompHelper {

					   static auto set_port_value(_In_ WRF_STRING &val1,
					                                    _In_ WRF_INT val2)->
													          std::pair<WRF_STRING, WRF_INT>{
						   return (std::make_pair(val1, val2));
					   }
					                               

					   static auto uops_min_pd_descr()->
					                WRF_STRING { return (WRF_STRING{"Micro-ops of _mm256_min_pd per Port unfused decomposition:" }); }

					   static auto uops_min_ps_descr()->
						            WRF_STRING { return (WRF_STRING{"Micro-ops of _mm256_min_ps per Port unfused decomposition:" }); }

					   static auto uops_max_pd_descr()->
						            WRF_STRING { return (WRF_STRING{"Micro-ops  of _mm256_max_pd per Port unfused decomposition: "}); }

					   static auto uops_max_ps_descr()->
						            WRF_STRING { return (WRF_STRING{"Micro-ops of _mm256_max_ps per Port unfused decomposition: " }); }

					   static auto uops_ceil_ps_descr()->
						            WRF_STRING { return (WRF_STRING{"Micro-ops of _mm26_ceil_ps per Port unfused decomposition: " }); }

					   static auto uops_ceil_pd_descr()->
						            WRF_STRING { return (WRF_STRING{"Micro-ops of _mm256_ceil_pd per Port unfused decomposition: " }); }

					   static auto uops_floor_ps_descr()->
						            WRF_STRING { return (WRF_STRING{"Micro-ops of _mm256_floor_ps per Port unfused decomposition: " }); }

					   static auto uops_floor_pd_descr()->
						            WRF_STRING { return (WRF_STRING{"Micro-ops of _mm256_floor_pd per Port unfused decomposition: " }); }

					   static auto uops_zero_ps_descr()->
						            WRF_STRING { return (WRF_STRING{"Micro-ops of _mm256_setzero_ps per Port unfused decomposition: " }); }

					   static auto uops_zero_pd_descr()->
						            WRF_STRING { return (WRF_STRING{"Micro-ops of _mm256_setzero_pd per Port unfused decomposition: " }); }



				   };



			struct RegisterType {


				enum class  Types {

					XMM = 0,

					YMM = 1,

					ZMM = 2
				};
			};


			template<class Type = RegisterType>
			         struct  Register_XMM final :
				              public RegisterType {


				enum class reg_type{ XMM = Type::Types::XMM };

				static constexpr WRF_UINT m_BitWidth = 1 << 7;

				static constexpr WRF_UINT m_NumScalarsSP = 1 << 2;

				static constexpr WRF_UINT m_NumScalarsDP = 1 << 1;

				static auto getBitWidth()->
					       constexpr WRF_UINT {
					return (m_BitWidth);
				}

				static auto getNumScalarsSP()->
					       constexpr WRF_UINT {
					return (m_NumScalarsSP);
				}

				static auto getNumScalarsDP()->
					         constexpr WRF_UINT {
					return (m_NumScalarsDP);
				}



			};

			template<class Type = RegisterType>
			          struct Register_YMM final :
				                public RegisterType {


				enum class reg_type{ YMM = Type::Types::YMM };

				static constexpr WRF_UINT m_BitWidth = 1 << 8;

				static constexpr WRF_UINT m_NumScalar32bit = 1 << 3;

				static constexpr WRF_UINT m_NumScalar64bit = 1 << 2;

				static auto getBitWidth()->
					constexpr WRF_UINT {
					return (m_BitWidth);
				}

				static auto getNumScalar32bit()->
					constexpr WRF_UINT {
					return (m_NumScalar32bit);
				}

				static auto getNumScalar64bit()->
					constexpr WRF_UINT {
					return (m_NumScalar64bit);
				}
			};

			template<class Type = RegisterType>
			           struct Register_ZMM final :
				                public RegisterType {

				enum class reg_type{ ZMM = Type::Types::ZMM };

				static constexpr WRF_UINT m_BitWidth = 1 << 9;

				static constexpr WRF_UINT m_NumScalar32bit = 1 << 4;

				static constexpr WRF_UINT m_NumScalar64bit = 1 << 3;

				static auto getBitWidth()->
					constexpr WRF_UINT {
					return (m_BitWidth);
				}

				static auto getNumScalar32bit()->
					constexpr WRF_UINT {
					return (m_NumScalar32bit);
				}

				static auto getNumScalar64bit()->
					constexpr WRF_UINT {
					return (m_NumScalar64bit);
				}
			};





			


		}

	}
}


#endif /*_WRF_INTRINSICS_CONFIG_HPP_*/