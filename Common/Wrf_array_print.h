
#ifndef WRF_ARRAY_PRINT_H_
#define WRF_ARRAY_PRINT_H_

#ifndef WRF_ARRAY_PRINT_VERSION_MAJOR
#define WRF_ARRAY_PRINT_VERSION_MAJOR 1
#endif

#ifndef WRF_ARRAY_PRINT_VERSION_MINOR
#define WRF_ARRAY_PRINT_VERSION_MINOR 0
#endif

#ifndef WRF_ARRAY_PRINT_CREATE_DATE
#define WRF_ARRAY_PRINT_CREATE_DATE 20160719
#endif

/* Set this value to successful build date*/
#ifndef WRF_ARRAY_PRINT_BUILD_DATE
#define WRF_ARRAY_PRINT_BUILD_DATE 0
#endif

#include "Wrf_type_traits.hpp"
//#include "WRF_PHYS_LIB_TYPEDEFS.h"

#include "Wrf_array_metadata.h"
#ifdef DEBUG_VERBOSE
#include "Wrf_debug_print.h"
#endif


namespace wrf_physics {

	namespace wrf_physics_utils {


		

		/**********************************************
		   Generic array 1D printer. Templated on 
		   primitive type data_t and on ADT type
		   Container_t.
		  
		***********************************************/

		template<typename data_t,
		          class Container_t> struct  Array1DPrinter {


					  /* print array 1d - generic type Container_t
					     must have defined public operator subscript.
						 Arguments:
						 1) array to be printed.
						 2) virtual address of function enclosing array.
						 3) array name.
						 4) array's loc.
						 */

					  static  auto  print_array1d(_In_ WRF_CPP_CONST Container_t &,
					                              _In_ WRF_CPP_CONST ArrayMetaData<Container_t> &)->
												                      std::enable_if<wrf_physics::
					                                                                 wrf_physics_internal::
					                                                                 traits::Is_Container_std_vector<data_t, Container_t>::value ||
					                                                                 wrf_physics::
					                                                                 wrf_physics_internal::
					                                                                 traits::Is_Container_std_valarray<data_t, Container_t>::value ||
					                                                                 wrf_physics::
					                                                                 wrf_physics_internal::
					                                                                 traits::Is_Container_boost_multi_array1d<data_t, Container_t>::value, void>;


		};


				





#include "Wrf_array_print.inl"
	}
}









#endif /* WRF_ARRAY_PRINT_H_*/