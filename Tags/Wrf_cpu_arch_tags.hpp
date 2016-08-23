
#ifndef _WRF_CPU_ARCH_TAGS_HPP_
#define _WRF_CPU_ARCH_TAGS_HPP_

#ifndef WRF_CPU_ARCH_TAGS_VERSION_MAJOR
#define WRF_CPU_ARCH_TAGS_VERSION_MAJOR 1
#endif

#ifndef WRF_CPP_ARCH_TAGS_VERSION_MINOR
#define WRF_CPP_ARCH_TAGS_VERSION_MINOR 0
#endif

#ifndef WRF_CPP_ARCH_TAGS_CREATE_DATE
#define WRF_CPP_ARCH_TAGS_CREATE_DATE 20160726
#endif

/* Set this value to date of successful build.*/
#ifndef WRF_CPP_ARCH_TAGS_BUILD_DATE
#define WRF_CPP_ARCH_TAGS_BUILD_DATE 0
#endif

namespace  wrf_physics {

	namespace  wrf_physics_internal {

		namespace tags {



			/********************************
			  CPUID tags types, denotes 
			  different CPU architectures
			*********************************/

			class cpu_arch_t_tag {};

			class cpu_arch_0F_03_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_0F_02_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_2A_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_2D_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_3A_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_3E_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_3C_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_45_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_46_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_25_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_2C_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_1A_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_1E_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_1F_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_2E_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_2F_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_17_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_1D_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_0F_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_0E_t_tag final : public  cpu_arch_t_tag {};

			class cpu_arch_06_0D_t_tag final : public  cpu_arch_t_tag {};

			/* Represnts following versions of CPUs
			  06_2A/2D/3A/3E/3C/45/46
			*/
			class cpu_arch_common_models_1_t_tag final : public cpu_arch_t_tag {};

			/* Represents following versions of CPUs
			  06_25/2C/1A/1E/1F/2E/2F
			*/
			class cpu_arch_common_models_2_t_tag final : public cpu_arch_t_tag {};

			/* Combined models: 06_3C/45/46*/
			class cpu_arch_06_3C_45_46_t_tag final : public cpu_arch_t_tag {};

			/* Combined models: 06_2A/2D/3A/3E */
			class cpu_arch_06_2A_2D_3A_3E_t_tag final : public cpu_arch_t_tag {};

			/* Combined models: 06_25/2C/1A/1E/1F/2E/2F */
			class cpu_arch_06_25_2C_1A_1E_1F_2E_2F_t_tag final : public cpu_arch_t_tag {};

			/***********************************
			  Condensed to 3 architecture types
			*************************************/

			class cpu_arch_sandy_bridge_t_tag final : public cpu_arch_t_tag {};

			class cpu_arch_ivy_bridge_t_tag final : public cpu_arch_t_tag {};

			class cpu_arch_haswell_t_tag final : public cpu_arch_t_tag {};

			/*
			   These tags are not implemented
			   because of lack of appropriate data:
			   1) Latency.
			   2) Reciprocal Throughput.
			   3) Unfused Micro-ops decomposition.
			   4) Fused Micro-ops decomposition.
			*/
			class cpu_arch_broadwell_t_tag final : public cpu_arch_t_tag {};

			class cpu_arch_sky_lake_t_tag final : public cpu_arch_t_tag {};

			class cpu_arch_mic_t_tag    final : public cpu_arch_t_tag {};

			/* Combined tag for 3 architectures
			   Not used.*/
			class cpu_arch_sb_ib_haswell_t_tag final : public cpu_arch_t_tag {};

			/***********************************
			   Primitive type data size tags
			************************************/

			class cpu_arch_data_size_t_tag {};

			class cpu_arch_float32_t_tag final : public cpu_arch_data_size_t_tag {};

			class cpu_arch_float64_t_tag final : public cpu_arch_data_size_t_tag {};

			class cpu_arch_int8_t_tag final : public cpu_arch_data_size_t_tag {};

			class cpu_arch_int16_t_tag final : public cpu_arch_data_size_t_tag {};

			class cpu_arch_int32_t_tag final : public cpu_arch_data_size_t_tag {};

			class cpu_arch_int64_t_tag final : public cpu_arch_data_size_t_tag {};
		}
	}
}
#endif /* _WRF_CPU_ARCH_TAGS_HPP_*/