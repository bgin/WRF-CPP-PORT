#ifndef WRF_PORT_FIRE_ATM_TERRAIN_H_05_06_16
#define WRF_PORT_FIRE_ATM_TERRAIN_H_05_06_16 0x100

#include "MasterHeaderFile.h"

namespace  wrf_port_cpp {

	namespace wrf_physics_iface {

		using namespace boost::units;
		using namespace boost::units::si;

		/******************************************
		   Terrain topography as 2D map of height,
		   based Dimensional analysis units of height
		   in meter above sea level. Templated on type
		   T.
		*******************************************/
		template<typename T,
			    const std::size_t IMS,
				const std::size_t IME,
				const std::size_t JMS,
				const std::size_t JME > class Terrain2D {


			/****************************************
			        Constructors and Destructor
			*****************************************/

			public:

			/* Reference sea level or almost flat terrain with
			   height map variation below/up to 1.0 meter.*/
			Terrain2D();

			/* Terrain2D modulated with user passed
			   height map above reference 1.0 meter.*/
			Terrain2D(_In_ const boost::multi_array<T, 2> &);

			/* Copy Constructor.*/
			Terrain2D(_In_ const Terrain2D &);

			/* Move Constructor. */
			Terrain2D(_In_ Terrain2D &&);

			/* Destructor = default*/
			~Terrain2D() = default;

			/***************************************
			            Member operators
			***************************************/

			/* copy assignment */
			auto   operator=(_In_ const Terrain2D &)->Terrain2D &;

			/* move assignment */
			auto   operator=(_In_ Terrain2D &&)->Terrain2D &;

			/* subscription immutable access.*/
			auto   operator()(_In_ const std::size_t, 
				              _In_ const std::size_t)const-> const T;

			/****************************************
			         Class member functions 
			*****************************************/

			/* return const reference to class member
			   variable.
			   Warning!! reference must not outlive its
			   object.*/
			auto   getTerrain2DMap()const->boost::multi_array<quantity<length, T>, 2> const &;

			auto   incr_height(_In_ const std::size_t,
				               _In_ const std::size_t,
				               _In_ const T)->void;
			private:

				/* Class variable m_aTerrain2DMap, denotes 
				   terrain 2D height map.*/
			boost::multi_array<quantity<length, T>, 2> m_aTerrain2DMap;
			
		};
			                
		template < typename T,
			const std::size_t IMS,
			const std::size_t IME,
			const std::size_t JMS,
			const std::size_t JME > auto operator<<(_In_ std::ostream &os, _In_ const Terrain2D<T, IMS, IME, JMS, JME> &rhs)->std::ostream & {

			std::cout << typeid(rhs).name() << " object state dump" << std::endl;
 			for (std::size_t i{ IMS }; i != IME; ++i) {
				for (std::size_t j{ JMS }; j != JME; ++j) {
					os << std::fixed << std::setprecision(15) << 
						rhs.operator()(i, j) << std::endl;
				}
				os << "----------------" << std::endl;
			}

			return (os);
		}
			    

#include "wrf_port_fire_atm_terrain.inl"
	}
}

#endif  /*WRF_PORT_FIRE_ATM_TERRAIN_H_05_06_16*/