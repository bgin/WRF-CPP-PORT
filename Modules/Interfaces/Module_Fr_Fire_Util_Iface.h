#ifndef MODULE_FR_FIRE_UTIL_IFACE_H_05_25_2016
#define MODULE_FR_FIRE_UTIL_IFACE_H_05_25_2016 

#ifndef MODULE_FR_FIRE_UTIL_IFACE_VERSION_MAJOR 
#define  MODULE_FR_FIRE_UTIL_IFACE_VERSION_MAJOR 1
#endif

#ifndef MODULE_FR_FIRE_UTIL_IFACE_VERSION_MINOR 
#define MODULE_FR_FIRE_UTIL_IFACE_VERSION_MINOR 0
#endif

#ifndef MODULE_FR_FIRE_UTIL_IFACE_CREATE_DATE
#define MODULE_FR_FIRE_UTIL_IFACE_CREATE_DATE 20160525
#endif

/* Set this macro to successful build date*/
#ifndef MODULE_FR_FIRE_UTIL_IFACE_BUILD_DATE
#define MODULE_FR_FIRE_UTIL_IFACE_BUILD_DATE 0
#endif

/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library Module Fire Util Interface -  declaration.

@file Module_Fr_Fire_Util_iface.h
@author: Bernard Gingold
@version:  1.0.0  08/05/2016
@description: Module_Fr_Fire_Util_Iface.h
*/


#include "WRF_PHYS_LIB_TYPEDEFS.h"

namespace   wrf_physics {

	namespace fire_fr_util {

		namespace  fire_fr_util_iface {


			/***************************************
			          struct GlobalConsts
			***************************************/

			template<typename T>   struct GlobalFlags {

				  static   int  fire_print_msg{ 1 };

				  static   int  fire_print_file{ 1 };

				  static   int  fuel_left_method{ 1 };

				  static   int  fuel_left_irl{ 2 };

				  static   int  fuel_left_jrl{ 2 };

				  static   int  boundary_guard{ 1 };

				  static   int  fire_grows_only{ 1 };

				  static   int  fire_upwinding{ 3 };

				  static   int  fire_upwind_split{ 0 };

				  static   int  fire_test_steps{ 0 };

				  static   int  fire_topo_from_atm{ 1 };

				  static   int  fire_advection{ 0 };

				  static   int  REAL_SUM{ 10 };

				  static   int  REAL_MAX{ 20 };

				  static   int  RNRM_SUM{ 30 };

				  static   int  RNRM_MAX{ 40 };



				  static   T   fire_constant_time{ -1.0 };

				  static   T   fire_constant_grnhfx{ -1.0 };

				  static   T   fire_constant_grnqfx{ -1.0 };

				  static   T   fire_atm_feedback{ 1.0 };

				  static   T   fire_back_weight{ 0.5 };

				  static   T   fire_viscosity{ 0.4 };

				  static   T   fire_lfn_ext_up{ 1.0 };
			
			};
		}
	}
}

#endif /*MODULE_FR_FIRE_UTIL_IFACE_H_05_25_2016*/