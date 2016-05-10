#ifndef WRF_PORT_FIRE_ATM_TERRAIN_GRADIENT_H_05_09_16
#define WRF_PORT_FIRE_ATM_TERRAIN_GRADIENT_H_05_09_16


#include "MasterHeaderFile.h"
#include "wrf_port_fire_atm_terrain.h"

namespace wrf_port_cpp {

	namespace wrf_physics_impl {


		/********************************************
		  Terrain gradient class templated on type
		  T and on default template argument Terrain.
		  3-Points implementation.
		*********************************************/

		template<typename T, 
         const std::size_t IMS,
		 const std::size_t IME,
		 const std::size_t JMS,
		 const std::size_t JME,
		 class Terrain = wrf_port_cpp::wrf_physics_iface::Terrain2D<T,IMS,IME,JMS,JME>> class TerrainGrad3x3 {

			 /*********************************************
			           Constructors and Destructor
			 *********************************************/
		 public:

			 /****************************************
			  Main class Constructor initializes
			  class members.
			 ****************************************/
			 TerrainGrad3x3(_In_ const Terrain &,
				            _In_ const T,
							_In_ const T);

			 /* Copy Constructor */
			 TerrainGrad3x3(_In_ const TerrainGrad3x3 &);

			 /* Move Constructor */
			 TerrainGrad3x3(_In_ TerrainGrad3x3 &&);

			 /* Destructor = default*/
			 ~TerrainGrad3x3() = default;

			 /*****************************************
			           Class member operators
			 ******************************************/

			 /* copy assignment */
			 auto   operator=(_In_ const TerrainGrad3x3 &)->TerrainGrad3x3 &;

			 /* move assignment */
			 auto   operator=(_In_ TerrainGrad3x3 &&)->TerrainGrad3x3 &;

			 /* subscription - operator()*/
			 auto   operator()(_In_ const std::size_t, _In_ const std::size_t)const->const T;

			 /*******************************************
			            Class member functions
			 ********************************************/


			 /* This function computes terrain gradient
			    of kernel 3x3*/
			 auto   compute_grad3x3()->TerrainGrad3x3 &;



		 private:

			 /* Class variable m_TerrainMap, denotes template default
			    argument of type Terrain2D*/
			 Terrain m_TerrainMap;

			 /* Class variable m_aGradient3x3, denotes array 2D
			    which contains computed 3x3 gradient*/
			 boost::multi_array<T, 2> m_aGradient3x3;

			 /* Class variable m_dx, denotes grid spacing
			    in x direction.*/
			 T  m_dx;

			 /* Class variable m_dy, denotes grid spacing
			    in y direction.*/
			 T  m_dy;
		};

		 template<typename T,
			     const std::size_t IMS,
				 const std::size_t IME,
				 const std::size_t JMS,
				 const std::size_t JME,
		 class Terrain > auto operator<<(_In_ std::ostream &os, _In_ wrf_port_cpp::wrf_physics_impl::TerrainGrad3x3<T, IMS, IME, JMS, JME, Terrain> &rhs)->std::ostream & {

			 std::cout << typeid(rhs).name() << " object state dump." << std::endl;
			 for (std::size_t i{ IMS }; i != IME; ++i) {
				 for (std::size_t j{ JMS }; j != JME; ++j) {

					 os << std::fixed << std::setprecision(15) << i <<
						"," << j  <<  ", val " << rhs.operator()(i, j) << std::endl;
				 }
				 os << "---------------" << std::endl;
			 }
			 return (os);
		 }

		 /**************************************
		 Terrain gradient class templated on type
		 T and on default template argument Terrain.
		  9-Points implementation.
		 ***************************************/

		 template<typename T,
			     const std::size_t IMS,
				 const std::size_t IME,
				 const std::size_t JMS,
				 const std::size_t JME,
		         class Terrain = wrf_port_cpp::wrf_physics_iface::Terrain2D < T, IMS, IME, JMS, JME >> class TerrainGrad8P3x3 {

					 /****************************************
					         Constructors and Destructor
					 *****************************************/
				 public:

					 /* Class main Constructor */
					 TerrainGrad8P3x3(_In_ const Terrain &,
						              _In_ const T,
						              _In_ const T);

					 /* Copy Constructor */
					 TerrainGrad8P3x3(_In_ const TerrainGrad8P3x3 &);

					 /* Move Constructor  */
					 TerrainGrad8P3x3(_In_ TerrainGrad8P3x3 &&);

					 /* Class Destructor = default*/
					 ~TerrainGrad8P3x3() = default;

					 /*******************************************
					    Class member  operators
					 *******************************************/

					 /* operator copy assignment */
					 auto  operator=(_In_ const TerrainGrad8P3x3 &)->TerrainGrad8P3x3 &;

					 /* operator move assignment */
					 auto  operator=(_In_ TerrainGrad8P3x3 &&)->TerrainGrad8P3x3 &;

					 /********************************************
					            Class member functions
					 *********************************************/

					 /* Returns const reference to m_aFx.*/
					 auto   getFx()const->boost::multi_array<T, 2> const &;

					 /* Returns const reference to m_aFy.*/
					 auto   getFy()const->boost::multi_array<T, 2> const &;

					 /* Returns const reference to m_aFxx.*/
					 auto   getFxx()const->boost::multi_array<T, 2> const &;

					 /* Returns const reference to m_aFyy.*/
					 auto   getFyy()const->boost::multi_array<T, 2> const &;

					 /* Returns const reference to m_aFxy.*/
					 auto   getFxy()const->boost::multi_array<T, 2>  const &;

					 /* Computes 8-Point gradient on 3x3 matrix(plane).*/
					 auto   compute_grad8P3x3()->TerrainGrad8P3x3 &;

					 /* Returns all partials packed into std::tuple*/
					 auto   getAllGradients()const->std::tuple < const boost::multi_array<T, 2> &,
						                                         const boost::multi_array<T, 2> &,
						                                         const boost::multi_array<T, 2> &,
						                                         const boost::multi_array<T, 2> &,
						                                         const boost::multi_array<T, 2> & > ;


				 private:

					 /* Class variable m_TerrainMap, denotes template default
					 argument of type Terrain2D*/
					 Terrain m_TerrainMap;

					 /*Class variable m_aFx, denotes Fx partial
					   derivative.*/
					 boost::multi_array<T, 2> m_aFx;

					 /* Class variable m_aFy, denotes Fy partial
					   derivative.*/
					 boost::multi_array<T, 2>  m_aFy;

					 /* Class variable m_aFxx, denotes Fxx partial
					   derivative.*/
					 boost::multi_array<T, 2> m_aFxx;

					 /* Class variable m_aFyy, denotes Fyy partial
					   derivative. */
					 boost::multi_array<T, 2>  m_aFyy;

					 /* Class variable m_aFxy, denotes Fxy partial
					   derivative.*/
					 boost::multi_array<T, 2>  m_aFxy;

					 /* Class variable m_dx, denotes dx spacing*/
					 T  m_dx;

					 /* Class variable m_dy, denotes dy spacing.*/
					 T  m_dy;

					 /* Class variable m_isComputed , denotes
					    the successful end of gradients computation.*/
					 bool m_bisComputed;

		 };

      template<typename T,
		      const std::size_t IMS,
		      const std::size_t IME,
		      const std::size_t JMS,
		      const std::size_t JME,
	          class Terrain >      auto  operator<<(_In_ std::ostream& os, _In_ wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3<T, IMS, IME, JMS, JME, Terrain> &rhs)->std::ostream & {

				  std::cout << typeid(rhs).name() << " object state dump." << std::endl;
				  std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
				  std::cout << "       Fx:                  Fy:                  Fxx:               Fyy:                    Fxy:     " << std::endl;
				  std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
				  for (std::size_t i{ IMS }; i != IME; ++i) {
					  for (std::size_t j{ JMS }; j != JME; ++j) {

						  os << std::fixed << std::setprecision(15)  << rhs.getFx()[i][j] << std::setw(20) << rhs.getFy()[i][j] <<
							  std::setw(20) << rhs.getFxx()[i][j] << std::setw(20) << rhs.getFyy()[i][j] << std::setw(20) << rhs.getFxy()[i][j] << std::endl;
					  }
					  os << "-------------------------------------------------------------------------------------------------------" << std::endl;
				  }

				  return (os);
	  }
		      
		

#include "wrf_port_fire_atm_terrain_gradient.inl"

	}
}
#endif /* WRF_PORT_FIRE_ATM_TERRAIN_GRADIENT_H_05_09_16*/