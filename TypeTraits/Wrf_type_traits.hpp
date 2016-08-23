
#ifndef WRF_TYPE_TRAITS_HPP_
#define WRF_TYPE_TRAITS_HPP_



#ifndef WRF_TYPE_TRAITS_VERSION_MAJOR
#define WRF_TYPE_TRAITS_VERSION_MAJOR 1
#endif

#ifndef WRF_TYPE_TRAITS_VERSION_MINOR
#define WRF_TYPE_TRAITS_VERSION_MINOR 0
#endif

#ifndef WRF_TYPE_TRAITS_CREATE_DATE
#define WRF_TYPE_TRAITS_CREATE_DATE 20160716
#endif

/* Set this define to successful build date.*/
#ifndef WRF_TYPE_TRAITS_BUILD_DATE
#define WRF_TYPE_TRAITS_BUILD_DATE 0
#endif

#include "ALL_INCLUDES.h"
#include <type_traits>
#include <vector>
#include <valarray>

namespace wrf_physics {

	namespace wrf_physics_internal {

		namespace traits {


			/*************************************
			     Class ArraySlice1D traits
			**************************************/
			template<typename T,
			        class Container_t> 
			struct Is_Container_std_vector : 
			    public std::integral_constant<bool,false> {

			};

            template<typename T>  
			struct Is_Container_std_vector<T,std::vector<T>> : 
			                 public std::integral_constant<bool, true>{

		    };

            
            template<typename T,
				    class Container_t>
			struct Is_Container_std_valarray :
				public std::integral_constant<bool, false> {

			};

			template<typename T>
			       struct Is_Container_std_valarray<T,std::valarray<T>> : 
			public std::integral_constant<bool, true>{


			};

			template<typename T,
				    class Container_t>
			struct Is_Container_boost_multi_array1d :
				public std::integral_constant<bool, false> {

			};

			template<typename T>
			     struct Is_Container_boost_multi_array1d<T,boost::multi_array<T,1>> : 
				 public std::integral_constant<bool, true>{

			};





			
		}
	}
}

#endif /*WRF_TYPE_TRAITS_HPP_*/