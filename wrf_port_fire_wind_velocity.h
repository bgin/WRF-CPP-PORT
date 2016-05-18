#ifndef WRF_PORT_FIRE_WIND_VELOCITY_H_05_17_2016
#define WRF_PORT_FIRE_WIND_VELOCITY_H_15_17_2016  100

#include "MasterHeaderFile.h"


namespace   wrf_port_cpp {

	namespace   wrf_physics_iface {

		/***************************************
		    Wind Velocity class templated on
			type T and on default template
			argument of type const std::size_t
		***************************************/
		template<typename T,
			const std::size_t NSTEPS > struct WindVelocity {

			/***********************************
					   class typedefs
					   ************************************/
			typedef	boost::multi_array<boost::units::quantity<boost::units::si::velocity, T>, 2> Wind;

			/* Constructor and Destructor */

			WindVelocity();

			~WindVelocity() = default;




			/* Class member m_VX, denotes wind velocity in m/s.*/
			Wind  m_Velocity;

		};


		


#include "wrf_port_fire_wind_velocity.inl"
	}
}
#endif /*WRF_PORT_FIRE_WIND_VELOCITY_H_15_17_2016 */