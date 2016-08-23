
#ifndef __WRF_INTRINSICS_AVX_TYPECHECK_HPP__
#define __WRF_INTRINSICS_AVX_TYPECHECK_HPP__

#ifndef WRF_INTRINSICS_AVX_TYPECHECK_VERSION_MAJOR
#define WRF_INTRINSICS_AVX_TYPECHECK_VERSION_MAJOR 1
#endif

#ifndef WRF_INTRINSICS_AVX_TYPECHECK_VERSION_MINOR
#define WRF_INTRINSICS_AVX_TYPECHECK_VERSION_MINOR 0
#endif

#ifndef WRF_INTRINSICS_AVX_TYPECHECK_CREATE_DATE
#define WRF_INTRINSICS_AVX_TYPECHECK_CREATE_DATE 20160822
#endif

/* Set this value to successful build date.*/
#ifndef WRF_INTRINSICS_AVX_TYPECHECK_BUILD_DATE
#define WRF_INTRINSICS_AVX_TYPECHECK_BUILD_DATE 0
#endif

#ifndef WRF_INTRINSICS_AVX_TYPES
#include "Wrf_intrinsics_avx_types.hpp"
#endif

namespace wrf_physics{

	namespace wrf_physics_internal {

		                  namespace traits {

			/*
			   Namespace alias for conveniance.
			*/
			namespace at = wrf_physics::wrf_physics_internal::avx_intrinsic_traits;

			namespace tr = wrf_physics::wrf_physics_internal::traits;
			
			/*****************************************
			  AVX Intrinsics compile type checks.
			*****************************************/

			/*
			 * Type check of AVX_MM256_ADD Intrinsic.
			 * Primary template.
			 */
			template<class IntrinsicType_t,
			                      class Config,
				                   class CpuType_t,
						             class DataSize_t>
			                           struct Is_avx_mm256_add final :
				                           public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {

			};
            
			  /*
			   *   Partial specialization on type AVX_MM256_ADD.
			   */
		 template<class Config,
			           class CpuType_t,
			                class DataSize_t> 
		                              struct Is_avx_mm256_add<at::AVX_MM256_ADD<Config,
								               CpuType_t,DataSize_t>,Config,CpuType_t,DataSize_t> final : 
					                                    public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


					 };

						/*
						 * Type check of AVX_MM256_SUB Intrinsic.
						 * Primary template.
						 */
             template<class IntrinsicType_t,
				                  class Config,
								      class CpuType_t,
									     class DataSize_t>
			                               struct Is_avx_mm256_sub final :
				                              public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			 };
                         
						  /*
						   *   Partial specialization on type AVX_MM256_ADD.
						   */
            template<class Config,
				            class CpuType_t,
								   class DataSize_t> 
			                                    struct Is_avx_mm256_sub<at::AVX_MM256_SUB<Config,
									                   CpuType_t,DataSize_t>,Config,CpuType_t,DataSize_t> final : 
								                               public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


				     };

           
			template<class IntrinsicType_t,
				                  class Config,
									   class CpuType_t,
										     class DataSize_t>
			                                   struct Is_avx_mm256_div final :
			                                     	public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			};
		    		         
           
           template<class Config,
			              class CpuType_t,
							     class DataSize_t> 
		                                      struct Is_avx_mm256_div<at::AVX_MM256_DIV<Config,
									                        CpuType_t,DataSize_t>,Config,CpuType_t,DataSize_t> final : 
								                                         public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


						 };

            template<class IntrinsicType_t,
				                    class Config,
										  class CpuType_t,
											     class DataSize_t>
			                                           struct Is_avx_mm256_mul final :
			                            	              public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			};

            template<class Config,
				           class CpuType_t,
							     class DataSize_t> 
			                                  struct Is_avx_mm256_mul<at::AVX_MM256_MUL<Config,
									                          CpuType_t,DataSize_t>,Config,CpuType_t,DataSize_t> final : 
								                                        public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{
            


						 };

             template<class IntrinsicType_t,
				                     class Config,
										   class CpuType_t,
											      class DataSize_t>
			                                            struct Is_avx_mm256_cvtp final :
				                                               public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {

			 };

             template<class Config,
				            class CpuType_t,
								   class DataSize_t>
			                             struct Is_avx_mm256_cvtp < at::AVX_MM256_CVTP < Config,
			                                          typename std::enable_if<std::is_class<Config>::
											                        value>::type,CpuType_t,DataSize_t>,
				                                                            Config,CpuType_t,DataSize_t> final : 
			                                                                  public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{


			 };
			                
             template<class IntrinsicType_t,
				                  class Config,
									    class CpuType_t,
											   class DataSize_t>
			                                     struct Is_avx_mm256_cmp final :
				                                    public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			 };

             template<class Config,
				            class CpuType_t,
								   class DataSize_t>
									     struct Is_avx_mm256_cmp<at::AVX_MM256_CMP<Config,
											 typename tr::WRF_ENABLE_IF<tr::WRF_IS_CLASS<Config>::
											                           value>::type,CpuType_t, DataSize_t>,
																	            Config,CpuType_t, DataSize_t> final : 
									                            	                public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{
 

			 };

             template<class IntrinsicType_t,
				                    class Config,
										  class CpuType_t,
											    class DataSize_t>
			                                          struct Is_avx_mm256_rcp final :
				                                               public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {


			 };

             template<class Config,
				            class CpuType_t,
								     class DataSize_t>
										    struct Is_avx_mm256_rcp<at::AVX_MM256_RCP<Config,
												typename tr::WRF_ENABLE_IF<tr::WRF_IS_CLASS<Config>
												                  ::value>::type,CpuType_t, DataSize_t>,
																           Config,CpuType_t, DataSize_t> final : 
											                                    public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{};


			
											                    
			template<class IntrinsicType_t,
				                 class Config,
									   class CpuType_t,
										      class DataSize_t>
			                                        struct Is_avx_mm256_rsqrt final :
				                                           public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {};


			
            
            template<class Config,
			                  class CpuType_t,
								   class DataSize_t>
									     struct Is_avx_mm256_rsqrt<at::AVX_MM256_RSQRT<Config,
											 typename tr::WRF_ENABLE_IF<tr::WRF_IS_CLASS<Config>
											               ::value>::type, CpuType_t, DataSize_t>,
														           Config, CpuType_t, DataSize_t> final : 
										                                public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{};



		   

          template<class IntrinsicType_t,
			                  class Config,
								    class CpuType_t,
										   class DataSize_t>
		                                        struct Is_avx_mm256_sqrt final :
			                                           public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {};


		  

          template<class Config,
			                 class CpuType_t,
								       class DataSize_t>
										   struct Is_avx_mm256_sqrt<at::AVX_MM256_SQRT<Config,
											    typename tr::WRF_ENABLE_IF<tr::WRF_IS_CLASS<Config>
											                     ::value>::type, CpuType_t, DataSize_t>,
											                           Config, CpuType_t, DataSize_t> final : 
										                                  public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{};



		  

          template<class IntrinsicType_t,
			                      class Config,
									  class CpuType_t,
										    class DataSize_t>
		                                          struct Is_avx_mm256_fmadd final :
			                                             public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {};


		  

          template<class Config,
			             class CpuType_t,
							    class DataSize_t>
									  struct Is_avx_mm256_fmadd<at::AVX_MM256_FMADD<Config,
										        typename   tr::WRF_ENABLE_IF<tr::WRF_IS_CLASS<Config>
											               ::value>::type, CpuType_t, DataSize_t>,
											                     Config, CpuType_t, DataSize_t> final : 
									                                  public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{};



		 

          template<class IntrinsicType_t,
			                   class Config,
			                        class CpuType_t,
								          class DataSize_t>
		                                            struct Is_avx_mm256_fmsub final :
			                                               public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {};


		  

          template<class Config,
			              class CpuType_t,
							      class DataSize_t>
									  struct Is_avx_mm256_fmsub<at::AVX_MM256_FMSUB<Config,
										       typename tr::WRF_ENABLE_IF<tr::WRF_IS_CLASS<Config>
											                   ::value>::type, CpuType_t, DataSize_t>,
											                          Config, CpuType_t, DataSize_t> final : 
									                                        public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{};



		  

          template<class IntrinsicType_t,
			                      class Config,
									    class CpuType_t,
											   class DataSize_t>
		                                            struct Is_avx_mm256_fnmadd final :
			                                               public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {};


		  
          template<class Config,
			              class CpuType_t,
							            class DataSize_t>
											struct Is_avx_mm256_fnmadd<at::AVX_MM256_FNMADD<Config,
											    	typename tr::WRF_ENABLE_IF<tr::WRF_IS_CLASS<Config>
												                   ::value>::type, CpuType_t, DataSize_t>,
												                         Config, CpuType_t, DataSize_t> final : 
											                                    public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{};



          template<class IntrinsicType_t,
			                      class Config,
									    class CpuType_t,
											  class DataSize_t>
		                                           struct Is_avx_mm256_fnmsub final :
			                                              public std::integral_constant<WRF_BOOL, WRF_CPP_FALSE> {};



          template<class Config,
			               class CpuType_t,
							          class DataSize_t>
										  struct Is_avx_mm256_fnmsub<at::AVX_MM256_FNMSUB<Config,
											  typename tr::WRF_ENABLE_IF<tr::WRF_IS_CLASS<Config>
											  ::value>::type, CpuType_t, DataSize_t>,
											    Config, CpuType_t, DataSize_t> final : 
										  public std::integral_constant<WRF_BOOL, WRF_CPP_TRUE>{};









		}
	}
}

#endif /*__WRF_INTRINSICS_AVX_TYPECHECK_HPP__*/