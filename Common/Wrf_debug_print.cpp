
#include "Wrf_debug_print.h"

auto wrf_physics::
        wrf_physics_utils::
		          DebugPrinter::debug_print(_In_ WRF_CPP_CONST WRF_STRING Msg,
		                                    _In_ WRF_CPP_CONST WRF_INT Loc,
		                                    _In_ WRF_CPP_CONST WRF_WSTRING faddress)->void {

					  std::cerr << "******** debug print begin *********" << std::endl;
					  std::cerr << "Called inside: " << Msg.c_str() << std::endl;
					  std::cerr << " At line of code: " << Loc << std::endl;
					  std::cerr << "At function virt address: " << faddress.c_str() << std::endl;
					  std::cerr << "******** debug print end  **********" << std::endl;
		}


					              