
#ifndef _WRF_TYPE_ALIASES_HPP_
#define _WRF_TYPE_ALIASES_HPP_

#ifndef WRF_TYPE_ALIASES_VERSION_MAJOR
#define WRF_TYPE_ALIASES_VERSION_MAJOR 1
#endif

#ifndef WRF_TYPE_ALIASES_VERSION_MINOR
#define WRF_TYPE_ALIASES_VERSION_MINOR 0
#endif

#ifndef WRF_TYPE_ALIASES_CREATE_DATE 
#define WRF_TYPE_ALIASES_CREATE_DATE 20160729
#endif

/* Set this value to successful build date*/
#ifndef WRF_TYPE_ALIASES_BUILD_DATE
#define WRF_TYPE_ALIASES_BUILD_DATE 0
#endif




#include "WRF_PHYS_LIB_TYPEDEFS.h"

namespace wrf_physics {

	namespace wrf_physics_internal {

		namespace traits {

			/************************************
			         Useful type aliases.
			*************************************/

			

			template<bool B, typename T = void>
			using WRF_ENABLE_IF = typename std::enable_if<B, T>::type;

			template<typename T>
			using WRF_IS_CLASS =  std::is_class<T>;

			template<typename T>
			using WRF_IS_FLOATING_POINT = std::is_floating_point<T>;

			template<typename T>
			using WRF_IS_INTEGRAL = std::is_integral<T>;

			template<typename T>
			using WRF_IS_OBJECT = std::is_object<T>;

			template<typename T>
			using WRF_IS_UNION = std::is_union<T>;

			template<bool B, class T, class F>
			using WRF_Conditional = std::conditional<B, T, F>;


			namespace  global_std_traits_funcs {


				template<typename T>
				       auto Wrf_Is_floating_point()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
					                             WRF_ENABLE_IF<WRF_IS_FLOATING_POINT<T>::
										                            value, constexpr WRF_BOOL> {

					return (WRF_IS_FLOATING_POINT<T>::value);
				}

               template<typename T>
			           auto Wrf_Is_class()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
				                                 WRF_ENABLE_IF<WRF_IS_CLASS<T>::
										                    value, constexpr WRF_BOOL> {

				   return (WRF_IS_CLASS<T>::value);
			   }

               template<typename T>
			           auto Wrf_is_object()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
				                                   WRF_ENABLE_IF<WRF_IS_OBJECT<T>::
										                   value, constexpr WRF_BOOL> {

				   return (WRF_IS_OBJECT<T>::value);
			   }

               template<typename T>
			           auto Wrf_Is_union()WRF_CPP_NOEXCEPT(WRF_CPP_TRUE)->
				                                    WRF_ENABLE_IF<WRF_IS_UNION<T>::
								                            value, constexpr WRF_BOOL> {

				   return (WRF_IS_UNION<T>::value);
			   }



			}// global namespace
		}
	}
}



#endif /*_WRF_TYPE_ALIASES_HPP_*/