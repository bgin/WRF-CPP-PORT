
#ifndef WRF_DEBUG_PRINT_H_
#define WRF_DEBUG_PRINT_H_

#ifndef WRF_DEBUG_PRINT_VERSION_MAJOR
#define WRF_DEBUG_PRINT_VERSION_MAJOR 1
#endif

#ifndef WRF_DEBUG_PRINT_VERSION_MINOR
#define WRF_DEBUG_PRINT_VERSION_MINOR 0
#endif

#ifndef WRF_DEBUG_PRINT_CREATE_DATE
#define WRF_DEBUG_PRINT_CREATE_DATE 20160717
#endif

/* Set this value to successful build date.*/
#ifndef WRF_DEBUG_PRINT_BUILD_DATE
#define WRF_DEBUG_PRINT_BUILD_DATE 0
#endif

#include "WRF_PHYS_LIB_TYPEDEFS.h"




namespace  wrf_physics {

	namespace wrf_physics_utils {


		/*****************************************
		          class DebugPrint
		*****************************************/

		class DebugPrinter {

		public:



			/* debug print called from Ctors,Dtor and
			   copy assignment operators.*/

			static auto  debug_print(_In_ WRF_CPP_CONST WRF_STRING,
			                         _In_ WRF_CPP_CONST WRF_INT,
			                         _In_ WRF_CPP_CONST WRF_WSTRING)->void;

			/* debug print called from Ctors,Dtor and
			copy assignment operators. Version more 
			verbose.*/
			static auto  debug_print_verbose(_In_ WRF_CPP_CONST WRF_STRING,
				                             _In_ WRF_CPP_CONST WRF_INT,
				                             _In_ WRF_CPP_CONST WRF_WSTRING,
				                             _In_ WRF_CPP_CONST WRF_STRING)->void;

			/* displays message: "at function prolog" */
			static auto  at_prolog(_In_ WRF_CPP_CONST WRF_INT,
				                   _In_ WRF_CPP_CONST WRF_STRING &)->void;

			/* displays message: "at function epilog" */
			static auto  at_epilog(_In_ WRF_CPP_CONST WRF_INT,
				                   _In_ WRF_CPP_CONST WRF_STRING &)->void;


			static auto debug_verbose()->void;

		};

		    

	}
}




#endif /*WRF_DEBUG_PRINT_H_*/