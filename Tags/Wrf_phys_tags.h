#ifndef WRF_PHYS_TAGS_H_
#define WRF_PHYS_TAGS_H_

#ifndef WRF_PHYS_TAGS_VERSION_MAJOR 
#define WRF_PHYS_TAGS_VERSION_MAJOR 1
#endif

#ifndef WRF_PHYS_TAGS_VERSION_MINOR
#define WRF_PHYS_TAGS_VERSION_MINOR 0
#endif

#ifndef WRF_PHYS_TAGS_CREATION_DATE 
#define WRF_PHYS_TAGS_CREATION_DATE 20160706
#endif

/* initialize this macro to successful build date*/
#ifndef WRF_PHYS_TAGS_BUILD_DATE
#define WRF_PHYS_TAGS_BUILD_DATE 0
#endif

namespace wrf_physics {

	namespace wrf_physics_internal {

		namespace tags {

			/*******************************************
			  Tag dispatch mechanism for specialization
			  on primitive data type and on array type
			  ********************************************/


			/**********************************
				  Primitive data types tags
			***********************************/

			class primitive_type_tag {};

			class float32_t_tag final : public primitive_type_tag {};

			class float64_t_tag final : public primitive_type_tag {};


			/**********************************************
			                 Array types tags
							 Dynamic arrays
			***********************************************/

			class dyn_container_type_tag {};

			class dyn_container_boost_t_tag final : public dyn_container_type_tag {};

			class dyn_container_valarray_t_tag final : public dyn_container_type_tag {};

			class dyn_container_vector_t_tag  final : public dyn_container_type_tag {};

			class dyn_container_blaze_t_tag final : public dyn_container_type_tag {};

			class dyn_container_armadillo_t_tag final : public dyn_container_type_tag {};

			class dyn_container_raw_ptr_t_tag final : public dyn_container_type_tag {};

			class dyn_container_smart_ptr_t_tag final : public dyn_container_type_tag {};

			class dyn_container_own_impl_t_tag final : public dyn_container_type_tag {};

			/*****************************************************
			                  Array types tags
							  Static arrays.
			******************************************************/

			class stat_container_type_tag {};

			class stat_container_std_array_t_tag final : public stat_container_type_tag {};

			class stat_container_builtin_array_t_tag final : public stat_container_type_tag {};

			class stat_container_wrf_impl_t_tag final : public stat_container_type_tag {};

		}
	}
}





#endif /*WRF_PHYS_TAGS_H_*/