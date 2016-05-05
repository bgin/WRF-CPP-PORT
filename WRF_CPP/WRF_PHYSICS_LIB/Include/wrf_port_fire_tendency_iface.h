

#ifndef WRF_PORT_FIRE_TENDENCY_IFACE_H_04_05_16
#define WRF_PORT_FIRE_TENDENCY_IFACE_H_04_05_16 0x100

#include "MasterHeaderFile.h"

/****************************************************
   Abstract Interface for WRF Fire Tendency module
*****************************************************/

namespace wrf_port_cpp {

	namespace wrf_physics_iface {


		template<typename T>  class FireTendencyIface {


		public:

			virtual ~FireTendencyIface() {};

			/* Pure abstract functions 
			   overriden by the subclasses*/
			virtual  void  compute_fire_tendency(_In_  std::tuple<boost::multi_array<T, 2>,
				boost::multi_array<T, 2>,
				boost::multi_array<T, 2>,
				boost::multi_array<T, 2>,
				boost::multi_array<T, 2>,
				boost::multi_array<T, 2>,
				boost::multi_array<T, 3>,
				boost::multi_array<T, 3>,
				boost::multi_array<T, 3>> &,
				_In_ const T, _In_ const T, _In_ const T) = 0;
		};
	}
}

#endif /* WRF_PORT_FIRE_TENDENCY_IFACE_H_04_05_16 */