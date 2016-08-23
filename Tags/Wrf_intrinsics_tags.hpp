
#ifndef _WRF_INTRINSICS_TAGS_HPP_
#define _WRF_INTRINSICS_TAGS_HPP_

#ifndef WRF_INTRINSICS_TAGS_VERSION_MAJOR
#define WRF_INTRINSICS_TAGS_VERSION_MAJOR 1
#endif

#ifndef WRF_INTRINSICS_TAGS_VERSION_MINOR
#define WRF_INTRINSICS_TAGS_VERSION_MINOR 0
#endif

#ifndef WRF_INTRINSICS_TAGS_CREATE_DATE
#define WRF_INTRINSICS_TAGS_CREATE_DATE 20162607
#endif

/* Set this value to successful build date*/
#ifndef WRF_INTRINSICS_TAGS_BUILD_DATE
#define WRF_INTRINSICS_TAGS_BUILD_DATE 0
#endif

namespace  wrf_physics {

	namespace wrf_physics_internal {

		namespace tags {

			/**************************************
			Tag dispatch mechanism for Intel
			Intrinsics code performance metrics
			***************************************/



			/*****************************************
			       SSE Intrinsics type tags
				   Notice:
				   Only handful of intrinsics tags
				   are represented.
			******************************************/

			class sse_intrinsics_t_tag {};

			/*********************************
			        main categories types
			***********************************/

			class sse_intrinsics_arithmetic_t_tag : public sse_intrinsics_t_tag {};

			class sse_intrinsics_bitmanip_t_tag   : public sse_intrinsics_t_tag {};

			class sse_intrinsics_cast_t_tag       : public sse_intrinsics_t_tag {};

			class sse_intrinsics_compare_t_tag    : public sse_intrinsics_t_tag {};

			class sse_intrinsics_convert_t_tag    : public sse_intrinsics_t_tag {};

			class sse_intrinsics_elem_math_t_tag  : public  sse_intrinsics_t_tag {};

			class sse_intrinsics_gen_support_t_tag : public sse_intrinsics_t_tag {};

			class sse_intrinsics_load_t_tag        : public sse_intrinsics_t_tag {};

			class sse_intrinsics_logical_t_tag     : public sse_intrinsics_t_tag {};

			class sse_intrinsics_set_t_tag         : public  sse_intrinsics_t_tag {};

			class sse_intrinsics_spec_math_t_tag   : public sse_intrinsics_t_tag {};

			class sse_intrinsics_store_t_tag       : public sse_intrinsics_t_tag {};

			class sse_intrinsics_trigo_t_tag       : public sse_intrinsics_t_tag {};


			                 /***********************************
			                           arithmetic types
			                 ***********************************/
			class sse_mm_add_ps_t_tag final        : public sse_intrinsics_arithmetic_t_tag {};

			class sse_mm_div_ps_t_tag final        : public sse_intrinsics_arithmetic_t_tag {};

			class sse_mm_mul_ps_t_tag    final        : public sse_intrinsics_arithmetic_t_tag {};

			class sse_mm_sub_ps_t_tag    final        : public sse_intrinsics_arithmetic_t_tag {};

			               /*************************************
			                           comparison types
			               *************************************/
			class sse_mm_cmpeq_ps_t_tag final      : public sse_intrinsics_compare_t_tag {};

			class sse_mm_cmpge_ps_t_tag final      : public sse_intrinsics_compare_t_tag {};

			class sse_mm_cmpgt_ps_t_tag final      : public sse_intrinsics_compare_t_tag {};

			class sse_mm_cmple_ps_t_tag final      : public sse_intrinsics_compare_t_tag {};

			class sse_mm_cmpneq_ps_t_tag final     : public sse_intrinsics_compare_t_tag {};

			class sse_mm_cmpnge_ps_t_tag final     : public sse_intrinsics_compare_t_tag {};

			class sse_mm_cmpngt_ps_t_tag final     : public sse_intrinsics_compare_t_tag {};

			class sse_mm_cmpnle_ps_t_tag final     : public sse_intrinsics_compare_t_tag {};

			class sse_mm_cmpnlt_ps_t_tag final     : public sse_intrinsics_compare_t_tag {};

			             /************************************
			                         convert types
			             *************************************/
			class sse_mm_cvt_si2ss_t_tag final     : public sse_intrinsics_convert_t_tag {};

			class sse_mm_cvt_ss2si_t_tag final     : public sse_intrinsics_convert_t_tag {};

			
			/********************************************
			             AVX dispatch tag types
						 Notice: 
						 More extensive intrinsic tags
						 representation.
			*********************************************/
			/*
			Notice: As for now these tags ar unused!!
			*/

			/******************************
			         Primary tag.
			*******************************/
			class avx_intrinsics_t_tag {};

			/******************************
			          Derived type tags
			*******************************/

			class avx_intrinsics_arithm_t_tag : public avx_intrinsics_t_tag {};

			class avx_intrinsics_bitmanip_t_tag : public avx_intrinsics_t_tag {};

			class avx_intrinsics_cast_t_tag : public avx_intrinsics_t_tag {};

			class avx_intrinsics_convert_t_tag : public avx_intrinsics_t_tag {};

			class avx_intrinsics_elem_math_t_tag : public avx_intrinsics_t_tag {};

			class avx_intrinsics_load_t_tag : public avx_intrinsics_t_tag {};

			class avx_intrinsics_logic_t_tag : public avx_intrinsics_t_tag {};

			class avx_intrinsics_set_t_tag : public avx_intrinsics_t_tag {};

			class avx_intrinsics_shift_t_tag : public avx_intrinsics_t_tag {};

			class avx_intrinsics_spec_math_t_tag : public avx_intrinsics_t_tag {};

			class avx_intrinsics_store_t_tag : public avx_intrinsics_t_tag {};

			class avx_intrinsics_trigo_t_tag : public avx_intrinsics_t_tag {};


			/******************************
			  Concrete Intrinsics tags
			*******************************/

			class avx_mm256_add_pd_t_tag final : public avx_intrinsics_arithm_t_tag {};

			class avx_mm256_add_ps_t_tag final : public avx_intrinsics_arithm_t_tag {};

			class avx_mm256_sub_pd_t_tag final : public avx_intrinsics_arithm_t_tag {};

			class avx_mm256_sub_pd_t_tag final : public avx_intrinsics_arithm_t_tag {};
		}
	}
}
#endif /*_WRF_INTRINSICS_TAGS_HPP_*/