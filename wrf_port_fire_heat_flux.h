#ifndef WRF_PORT_FIRE_HEAT_FLUX_05_06_16
#define WRF_PORT_FIRE_HEAT_FLUX_05_06_16 0x100

#include "MasterHeaderFile.h"


namespace wrf_port_cpp {

	namespace wrf_physics_iface {


		using namespace boost::units;
		using namespace boost::units::si;

		/****************************************
		        Heat Flux in Watt/m^2 , templated
				on parameter T
		****************************************/

		template<typename T,
			    const std::size_t IMS,
				const std::size_t IME,
				const std::size_t JMS,
				const std::size_t JME > class HeatFluxDensity {

				public:

					

					/*******************************************
					         Constructors and Destructor
					********************************************/
                
					

					/* Variable heat flux density Constructor */
					HeatFluxDensity(_In_ const boost::multi_array<quantity<length, T>, 2> &,
						            _In_ const boost::multi_array<quantity<power,T>,2> &);

					/* Copy Constructor */
					HeatFluxDensity(_In_ const HeatFluxDensity &);

					/* Move Constructor */
					HeatFluxDensity(_In_ HeatFluxDensity &&);

					/* Destructor = default */
					~HeatFluxDensity() = default;

					/********************************************
					            Class member operators
					**********************************************/

					/* copy assignment */
					auto    operator=(_In_ const HeatFluxDensity &)->HeatFluxDensity &;

					/* move assignment */
					auto    operator=(_In_ HeatFluxDensity &&)->HeatFluxDensity &;

					auto    operator()(_In_ const std::size_t, _In_ const std::size_t)const-> const T;


					/**********************************************
					             Member functions
					***********************************************/

					auto    getHeatFlux2D()const->boost::multi_array<quantity<energy, T>, 2> const &;


				private:

					/* Class member variable m_aHeatFlux,
					   denotes heat flux from fire.*/
					boost::multi_array<T, 2> m_aHeatFlux2D;

		};

		template<typename T,
			     const std::size_t IMS,
				 const std::size_t IME,
				 const std::size_t JMS,
				 const std::size_t JME > auto operator<<(_In_ std::ostream &os, _In_ const HeatFluxDensity &)->std::ostream & {


		}

#include "wrf_port_fire_heat_flux.inl"
	}
}

#endif /* WRF_PORT_FIRE_HEAT_FLUX_05_06_16*/