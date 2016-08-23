
/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library Module Fire Atm Interfaces -  implementation.

@file Module_Ff_Fire_Atm_iface.inl
@author: Bernard Gingold
@version:  1.0.0  08/05/2016
@description: Module_Fr_Fire_Atm.h
*/

/**************************************************************
                       Implementation
***************************************************************/

template<typename T,
	const WRF_ULONGLONG IMS,
	const WRF_ULONGLONG IME,
	const WRF_ULONGLONG JMS,
	const WRF_ULONGLONG JME > wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T, IMS, IME, JMS, JME>::
	                          TerrainTopography() :  
	        m_aTerrainMap{ boost::extents[IME][JME] } {
		
		for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
			for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {

				this->m_aTerrainMap[i][j] = boost::units::quantity<height, T>
					(static_cast<T>(0) * boost::units::si::meters);
			}
		}
			 
    }

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME > wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME>::
		TerrainTopography(_In_ const boost::multi_array<T, 2> &height_map) :
		m_aTerrainMap{ boost::extents[IME][JME] } {

			for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
				for (WRF_ULONGLONG j{ JMS }; j != JMS; ++j) {

					this->m_aTerrainMap[i][j] = boost::units::quantity<height, T>
						(height_map[i][j] * boost::units::si::meters);
				}
			}
		}

template<typename T,
	     const WRF_ULONGLONG IMS,
		 const WRF_ULONGLONG IME,
		 const WRF_ULONGLONG JMS,
		 const WRF_ULONGLONG JME > wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME>::
		 TerrainTopography(_In_ const TerrainTopography &rhs) :
		 m_aTerrainMap{ rhs.m_aTerrainMap } {

		 }

template<typename T,
	     const WRF_ULONGLONG IMS,
		 const WRF_ULONGLONG IME,
		 const WRF_ULONGLONG JMS,
		 const WRF_ULONGLONG JME > wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME>::
		 TerrainTopography(_In_ TerrainTopography &&rhs) :
		 m_aTerrainMap{ std::move(rhs.m_aTerrainMap) } {

		 }

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME > auto  wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME>::
		operator=(_In_ const TerrainTopography &rhs)->TerrainTopography & {

			if (this == &rhs) return (*this);
			this->m_aTerrainMap.operator=(rhs.m_aTerrainMap);
			return (*this);
		}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME > auto  wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME>::
		operator=(_In_ TerrainTopography &&rhs)->TerrainTopography & {

			if (this == &rhs) return (*this);
			this->m_aTerrainMap.operator=(std::move(rhs.m_aTerrainMap));
			return (*this);
		}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME > auto  wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME>::
		operator()(_In_ const WRF_ULONGLONG I,
		          _In_ const WRF_ULONGLONG J)const->const T {

	             using namespace wrf_physics::utils_exceptions;
				 if (I > IME || J > JME)
					 throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

				 return (this->m_aTerrainMap[I][J].value());
			     
		}

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME > auto  wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME>::
		 operator==(_In_ const TerrainTopography &rhs)const->const bool {

			 using namespace wrf_physics::utils_exceptions;
			 if (this->m_aTerrainMap.num_elements() != rhs.m_aTerrainMap.num_elements())
				 throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: size of array!!"), rhs.m_aTerrainMap.num_elements(),
				 (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

			 return (this->m_aTerrainMap.operator==(rhs.m_aTerrainMap));
		 }

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME > auto  wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME>::
		operator!=(_In_ const TerrainTopography &rhs)const->const bool {
			using namespace wrf_physics::utils_exceptions;
			if (this->m_aTerrainMap.num_elements() != rhs.m_aTerrainMap.num_elements())
				throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: size of array!!"), rhs.m_aTerrainMap.num_elements(),
				(__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

			return (this->m_aTerrainMap.operator!=(rhs.m_aTerrainMap));
		}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME > auto  wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME>::
		operator+=(_In_ const boost::multi_array<T, 2> &height_map)->TerrainTopography & {

			using namespace wrf_physics::utils_exceptions;
			if (this->m_aTerrainMap.num_elements() != height_map.num_elements())
				throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: size of array!!"), height_map.num_elements(),
				(__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

			for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
				for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {

					this->m_aTerrainMap[i][j].value() += height_map[i][j];
				}
			}
			return (*this);
		}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME > auto  wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME>::
		                                getTerrainMap()const->boost::multi_array<boost::units::quantity<height, T>, 2> const & {

			return (this->m_aTerrainMap);
		}

template<typename T,
	    const WRF_ULONGLONG IMS,
		const WRF_ULONGLONG IME,
		const WRF_ULONGLONG JMS,
		const WRF_ULONGLONG JME > auto  wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME>::
		                               increase_height(_In_ const WRF_ULONGLONG I,
		                                               _In_ const WRF_ULONGLONG J,
		                                               _In_ const T value)->TerrainTopography & {

			using namespace wrf_physics::utils_exceptions;
			if (I > IME || J > JME)
				throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

			this->m_aTerrainMap[I][J].value() += value;
			return (*this);
		}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME > auto wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME>::
		                               increase_height(_In_ const WRF_ULONGLONG I0,
		                                               _In_ const WRF_ULONGLONG I1,
		                                               _In_ const WRF_ULONGLONG J0,
		                                               _In_ const WRF_ULONGLONG J1,
		                                               _In_ const boost::multi_array<T, 2> &height_map)->TerrainTopography & {

			using namespace wrf_physics::utils_exceptions;
			if (I1 > IME || J1 > JME)
				throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

			for (WRF_ULONGLONG i{ I0 }; i != I1; ++i) {
				for (WRF_ULONGLONG j{ J0 }; j != J1; ++j) {

					this->m_aTerrainMap[i][j].value() += height_map[i][j];
				}
			}
			return (*this);
		}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
		const WRF_ULONGLONG JME > auto   operator<<(_In_ std::ostream &os,
		                         _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T, IMS, IME, JMS, JME> &rhs)->std::ostream & {

			std::cout << typeid(rhs).name() << " object state dump: " << std::endl;
			for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
				for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {
					os << std::fixed << std::setprecision(15) <<
						rhs.operator()(i, j) << std::endl;
				}
				os << "------------------" << std::endl;
			}
			return (os);
			
		}


/***********************************************************************************************
                     Implementation of class TerrainGrad3P3x3
************************************************************************************************/

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain  >     wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                  TerrainGrad3P3x3(_In_ const Terrain & terrain,
			                                   _In_ const T dx,
			                                   _In_ const T dy) :
			 m_TerrainMap{ terrain },
			 m_aFx{ boost::extents[IME][JME] },
			 m_aFy{ boost::extents[IME][JME] },
			 m_Dx{ dx },
			 m_Dy{ dy }
		 {


		 }

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain  >   wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T,IMS,IME,JMS,JME,Terrain>::
			               TerrainGrad3P3x3(_In_ const TerrainGrad3P3x3 &rhs) :
			m_TerrainMap{ rhs.m_TerrainMap },
			m_aFx{ rhs.m_aFx },
			m_aFy{ rhs.m_aFy },
			m_Dx{  rhs.m_Dx },
			m_Dy{  rhs.m_Dy }
		{


		}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain >   wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T,IMS,IME,JMS,JME,Terrain>::
			              TerrainGrad3P3x3(_In_ TerrainGrad3P3x3 &&rhs) :
			m_TerrainMap{ std::move(rhs.m_TerrainMap) },
			m_aFx{ std::move(rhs.m_aFx) },
			m_aFy{ std::move(rhs.m_aFy) },
			m_Dx{ std::move(rhs.m_Dx) },
			m_Dy{ std::move(rhs.m_Dy) }
		{


		}

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain  >  auto    wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                       operator=(_In_ const TerrainGrad3P3x3 &rhs)->TerrainGrad3P3x3 & {

									   if (this == &rhs) return (*this);
									   TerrainGrad3P3x3 temp{ rhs };
									   std::swap(*this, temp);
									   return (*this);
			 }

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain  >   auto     wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                        operator=(_In_ TerrainGrad3P3x3 &&rhs)->TerrainGrad3P3x3 & {

										if (this == &rhs) return (*this);
										TerrainGrad3P3x3 temp{ rhs };
										std::swap(*this, temp);
										return (*this);
			}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain >    auto      wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                         operator()(_In_ const WRF_ULONGLONG I,
			                                    _In_ const WRF_ULONGLONG J)const->std::pair<const T, const T> {
										 using namespace wrf_physics::utils_exceptions;
										 if ((I > IME) || (J > JME))
											 throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
										 return (std::make_pair(this->m_aFx[I][J], this->m_aFy[I][J]));


			}
						
template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain >     auto      wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                          compute_grad3x3()->TerrainGrad3P3x3 & {
                                       
										  T inv_dx(1.0 / this->m_Dx);
										  T inv_dy(1.0 / this->m_Dy);
										  for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
											  for (WRF_ULONGLONG j{ JMS + 1 }; j != JME - 1; ++j) {

												  this->m_aFx[i][j] = inv_dx * (this->m_TerrainMap.getTerrainMap()[i][j + 1].value() -
													                           this->m_TerrainMap.getTerrainMap()[i][j].value());
												  this->m_aFy[i][j] = inv_dy * (this->m_TerrainMap.getTerrainMap()[j - 1][i].value() -
													                           this->m_TerrainMap.getTerrainMap()[j][i]);
											  }
										  }
										  return (*this);
			}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain >      auto       wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T, IMS, IME, JMS, JME, Terrain>::
			                            getFx()const->Matrix2D const & {

				return (this->m_aFx);
			}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain >       auto      wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                            getFy()const->Matrix2D const & {

				return (this->m_aFy);
			}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain >       auto      wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                            getDx()const->T {
				return(this->m_Dx);
			}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain >        auto     wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                            getDy()const->T {
				return(this->m_Dy);
			}

#if defined DEBUG_VERBOSE

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain  >       auto     wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                            debug_print(_In_ const WRF_STRING &Msg,
			                                        _In_ const WRF_INT Line,
			                                        _In_ const WRF_WSTRING & FuncAddress)const->void {

											std::cerr << "*********debug_print was called**********" << std::endl;
											std::cerr << __DATE__ << " " << __TIME__ << std::endl;
											std::cerr << "Executing in: " << Msg.c_str() << std::endl;
											std::cerr << "At line #: " << Line << std::endl;
											std::cerr << "At virtual address: " << std::hex << FuncAddress.c_str() << std::endl;
			}
#endif

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain  >       auto      operator<<(_In_ std::ostream &os, 
	                                        _In_ wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad3P3x3<T, IMS, IME, JMS, JME, Terrain> &rhs)->std::ostream & {
	              
			std::cout << typeid(rhs).name() << " Object state dump: " << std::endl;
			std::cout << "----------------------------------------------" << std::endl;
			std::cout << "       Fx:                           Fy:      " << std::endl;
			std::cout << "----------------------------------------------" << std::endl;

			for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
				for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {

					os << std::fixed << std::setprecision(15) << rhs.getFx()[i][j] <<
						std::setw(20) << rhs.getFy()[i][j] << std::endl;
				}
				os << "------------------------------------------" << std::endl;
			}
			std::cout << "-------------- End of object dump -------------" << std::endl;
			return (os);
}

		/*********************************************************************************
		                    Implementation of class TerrainGrad8P3x3
		**********************************************************************************/
		
template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain    >        wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                       TerrainGrad8P3x3(_In_ const Terrain &terrain,
			                                        _In_ const T Dx,
			                                        _In_ const T Dy) :

			 m_TerrainMap{ terrain },
			 m_aFx{ boost::extents[IME][JME] },
			 m_aFy{ boost::extents[IME][JME] },
			 m_aFxx{ boost::extents[IME][JME] },
			 m_aFyy{ boost::extents[IME][JME] },
			 m_aFxy{ boost::extents[IME][JME] },
			 m_Dx{ Dx },
			 m_Dy{ Dy }
			 
		 {

		 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain   >          wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                        TerrainGrad8P3x3(_In_ const TerrainGrad8P3x3 &rhs) :
			 m_TerrainMap{ rhs.m_TerrainMap },
			 m_aFx{ rhs.m_aFx },
			 m_aFy{ rhs.m_aFy },
			 m_aFxx{ rhs.m_aFxx },
			 m_aFyy{ rhs.m_aFyy },
			 m_aFxy{ rhs.m_aFxy },
			 m_Dx{ rhs.m_Dx },
			 m_Dy{ rhs.m_Dy }
			
		 {

		 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain   >          wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                        TerrainGrad8P3x3(_In_ TerrainGrad8P3x3 &&rhs) :
			 m_TerrainMap{ std::move(rhs.m_TerrainMap) },
			 m_aFx{ std::move(rhs.m_aFx) },
			 m_aFy{ std::move(rhs.m_aFy) },
			 m_aFxx{ std::move(rhs.m_aFxx) },
			 m_aFyy{ std::move(rhs.m_aFyy) },
			 m_aFxy{ std::move(rhs.m_aFxy) },
			 m_Dx{ std::move(rhs.m_Dx) },
			 m_Dy{ std::move(rhs.m_Dy) }
			 
		 {

		 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain   >      auto     wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                             operator=(_In_ const TerrainGrad8P3x3 &rhs)->TerrainGrad8P3x3 & {

											 if (this == &rhs) return (*this);
											 TerrainGrad8P3x3 temp{ rhs };
											 std::swap(*this, temp);
											 return (*this);
			 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain   >      auto      wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                              operator=(_In_ TerrainGrad8P3x3 &&rhs)->TerrainGrad8P3x3 & {

											  if (this == &rhs) return (*this);
											  *this = std::move(rhs);
											  return (*this);
			 }

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain   >      auto        wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                               getFx()const->Matrix2D const & {
				return (this->m_aFx);
			}

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain   >     auto        wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                               getFy()const->Matrix2D const & {
				 return (this->m_aFy);
			 }

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME,
        class Terrain    >     auto        wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                               getFxx()const->Matrix2D const & {
				return (this->m_aFxx);
			}

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain   >     auto        wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                               getFyy()const->Matrix2D const & {
			    return (this->m_aFyy);
			 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain    >     auto       wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                               getFxy()const->Matrix2D const & {
				 return (this->m_aFxy);
			 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain     >     auto       wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                                getAllPartials()const->std::tuple<const Matrix2D &,
			                                                                  const Matrix2D &,
			                                                                  const Matrix2D &,
			                                                                  const Matrix2D &,
			                                                                  const Matrix2D &> {
			       return (std::make_tuple(this->m_aFx, this->m_aFy, this->m_aFxx, this->m_aFyy, this->m_aFxy);
			 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain     >    auto         wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                                 getTypeID()const->std::string {
				   return (std::string(typeid(*this).name());
			 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain     >    auto          wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                                  compute_grad8P3x3()->TerrainGrad8P3x3 & {
                               
				    T two_dx(this->m_Dx + this->m_Dx);
					T two_dy(this->m_Dy + this->m_Dy);
					T dxdx(this->m_Dx * this->m_Dx);
					T dydy(this->m_Dy * this->m_Dy);
					T four_dxdy(4.0 * this->m_Dx * this->m_Dy);

					for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
						for (WRF_ULONGLONG j{ JMS + 1 }; j != JME - 1; ++j) {

							this->m_aFx[i][j] = (this->m_TerrainMap.getTerrainMap()[i][j - 1].value() -
								                this->m_TerrainMap.getTerrainMap()[i][j + 1].value()) / two_dx;

							this->m_aFy[i][j] = (this->m_TerrainMap.getTerrainMap()[j - 1][i].value() -
								                this->m_TerrainMap.getTerrainMap()[j + 1][i].value()) / two_dy;

							this->m_aFxx[i][j] = (this->m_TerrainMap.getTerrainMap()[i][j - 1].value() -
								                 (2.0 * this->m_TerrainMap.getTerrainMap()[i][j].value() +
								                 this->m_TerrainMap.getTerrainMap()[i][j + 1].value())) / dxdx;

							this->m_aFyy[i][j] = (this->m_TerrainMap.getTerrainMap()[j - 1][i].value() -
								                 (2.0 * this->m_TerrainMap.getTerrainMap()[j][i].value() +
								                 this->m_TerrainMap.getTerrainMap()[j + 1][i].value())) / dydy;
						}
					}

					for (WRF_ULONGLONG i{ IMS + 1 }; i != IME - 1; ++i) {
						for (WRF_ULONGLONG j{ JMS + 1 }; j != JME - 1; ++j) {
							this->m_aFxy[i][j] = (this->m_TerrainMap.getTerrainMap()[i][j + 1].value() +
								                  this->m_TerrainMap.getTerrainMap()[j + 1][i - 1].value() -
								                  this->m_TerrainMap.getTerrainMap()[j - 1][i - 1].value() -
								                  this->m_TerrainMap.getTerrainMap()[i][j + 1].value()) / four_dxdy;
						}
					}

					return (*this);
			 }

#if defined DEBUG_VERBOSE

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain   >         auto     wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                                debug_print(_In_ const WRF_STRING &Msg,
											            _In_ const WRF_INT Line,
														_In_ const WRF_WSTRING & FuncAddress)const->void {

												std::cerr << "*********debug_print was called**********" << std::endl;
												std::cerr << __DATE__ << " " << __TIME__ << std::endl;
												std::cerr << "Executing in: " << Msg.c_str() << std::endl;
												std::cerr << "At line #: " << Line << std::endl;
												std::cerr << "At virtual address: " << std::hex << FuncAddress.c_str() << std::endl;
												
			 }
#endif


template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
         class Terrain    >        auto    operator<<(_In_ std::ostream &os, 
			                                          _In_ wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T, IMS, IME, JMS, JME, Terrain> &rhs)->std::ostream & {

			 std::cout << typeid(rhs).name() << " Object state dump: " << std::endl;
			 std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
			 std::cout << "    Fx:                  Fy:                  Fxx:                     Fyy:                    Fxy:"     << std::endl;
			 std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;

			 for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
				 for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {

					 os << std::fixed << std::setprecision(15) << rhs.getFx()[i][j] << std::setw(20) << rhs.getFy()[i][j] <<
						 std::setw(20) << rhs.getFxx()[i][j] << std::setw(20) << rhs.getFyy()[i][j] << std::setw(20) <<
						 rhs.getFxy()[i][j] << std::endl;
				 }
				 os <<  "-------------------------------------------------------------------------------------------------------" << std::endl;
			 }
			 std::cout << "--------------------------- End of object dump. ------------------------------------------------------" << std::endl;
			 return (os);
          }              
	     

			
		 /******************************************************************
		          Implementation of class HeatFluxDensity
		 *******************************************************************/

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME  >   wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		                              HeatFluxDensity(_In_ const Plane& plane) :
		              m_aPlane{ plane },
		              m_aHeatFlux{ boost::extents[IME][JME] },
					  m_aHeatDensity{ boost::extents[IME][JME] } {

										  for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
											  for (WRF_ULONGLONG j{ JMS }; j != JMS; ++j) {

												  this->m_aHeatFlux[i][j] = boost::units::quantity<boost::units::si::power, T>(
													                        static_cast<T>(0) * boost::units::si::watt);
												  this->m_aHeatDensity[i][j] = this->m_aHeatFlux[i][j].value();
											  }
										  }
		 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME  >   wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		                              HeatFluxDensity(_In_ const Plane& plane,
		                                              _In_ const HeatFlux& flux) :
		           m_aPlane{ plane },
		           m_aHeatFlux{ flux },
				   m_aHeatDensity{ boost::extents[IME][JME] } {

										  for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
											  for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {

												  this->m_aHeatDensity[i][j] = this->m_aHeatFlux[i][j].value() /
													                           this->m_aPlane[i][j].value();
											  }
										  }
		 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME  >     wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		                                HeatFluxDensity(_In_ const HeatFluxDensity &rhs) :
		            m_aPlane{ rhs.m_aPlane },
		            m_aHeatFlux{ rhs.m_aHeatFlux },
		            m_aHeatDensity{ rhs.m_aHeatDensity } {

		 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME  >      wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		                                 HeatFluxDensity(_In_ HeatFluxDensity &&rhs) :
		            m_aPlane{ std::move(rhs.m_aPlane) },
		            m_aHeatFlux{ std::move(rhs.m_aHeatFlux) },
		            m_aHeatDensity{ std::move(rhs.m_aHeatDensity) } {

		 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME  >    auto   wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		                                      operator=(_In_ const HeatFluxDensity &rhs)->HeatFluxDensity & {

					if (this == &rhs) return (*this);
					    HeatFluxDensity temp{ rhs };
						std::swap(*this, temp);
						return (*this);

		 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME >      auto    wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		                                        operator=(_In_ HeatFluxDensity &&rhs)->HeatFluxDensity & {
					if (this == &rhs) return (*this);
					*this = std::move(rhs);
					return (*this);
		 }

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME >        auto    wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		                                         operator()(_In_ const WRF_ULONGLONG I,
		                                                    _In_ const WRF_ULONGLONG J)const->T {

			using namespace wrf_physics::utils_exceptions;
			if (I > IME || J > JME)
				throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
			return (this->m_aHeatDensity[I][J]);
		}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME >       auto     wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		                                         getPlane()const->Plane & {
			return (this->m_aPlane);
		}

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME >      auto      wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		                                          getHeatFlux()const->HeatFlux & {
			 return (this->m_aHeatFlux);
		 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME >       auto     wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		                                          getHeatDensity()const->Matrix2D & {
			 return (this->m_aHeatDensity);
		 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
		 const WRF_ULONGLONG JME >       auto     operator<<(_In_ std::ostream &os,
		                                                     _In_ wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T, IMS, IME, JMS, JME>& rhs)->std::ostream & {
			 std::cout << typeid(rhs).name() << " Object state dump: " << std::endl;
			 std::cout << "--------------------------------------------------------------------" << std::endl;
			 std::cout << " Plane[X,m^1,Y,m^1]:          Heat Flux[W]:        Heat Density[W/m^2]:   " << std::endl;
			 std::cout << "--------------------------------------------------------------------" << std::endl;

			 for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
				 for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {

					 os << std::fixed << std::setprecision(15) << rhs.getPlane()[i][j].value() << std::setw(20) << rhs.getHeatFlux()[i][j].value() <<
						 std::setw(20) << rhs.getHeatDensity()[i][j] << std::endl;
				 }
				 os << "---------------------------------------------------------------------" << std::endl;
			 }
			 std::cout << "-------------------- End of state dump -------------------------------" << std::endl;
			 return (os);
		 }


                                  /*******************************************************************************
								                       Implementation of class DryAirMass
                                  ********************************************************************************/

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME >  wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T,IMS,IME,JMS,JME>::
		                            DryAirMass(_In_ const PressureVals & pressure_vals) :
				m_aAirMass2D{ boost::extents[IME][JME] } {

				       for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
#pragma simd
#pragma unroll(4)
							for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {

								this->m_aAirMass2D[i][j] = boost::units::quantity<boost::units::si::pressure, T>{
													        pressure_vals[i][j] * boost::units::si::pascals};
												
											}
										}
		 }

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME >   wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T,IMS,IME,JMS,JME>::
		                            DryAirMass(_In_ const DryAirMass &rhs) :
		       m_aAirMass2D{ rhs.m_aAirMass2D }{

		}

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME >  wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T,IMS,IME,JMS,JME>::
		                            DryAirMass(_In_ DryAirMass &&rhs) :
		       m_aAirMass2D{ std::move(rhs.m_aAirMass2D) } {

		 }

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME >  auto   wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T,IMS,IME,JMS,JME>::
		                                   operator=(_In_ const DryAirMass &rhs)->DryAirMass & {
					if (this == &rhs) return (*this);
						DryAirMass temp{ rhs };
						std::swap(*this, temp);
					return (*this);
		 }

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME >   auto    wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T,IMS,IME,JMS,JME>::
		                                    operator=(_In_ DryAirMass &&rhs)->DryAirMass & {
					if (this == &rhs) return (*this);
					     this->m_aAirMass2D.operator=(std::move(rhs.m_aAirMass2D));
					return (*this);

											}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME >   auto   wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T, IMS, IME, JMS, JME>::
	                                   operator()(_In_ const WRF_ULONGLONG I,
	                                              _In_ const WRF_ULONGLONG J)const-> const T{
	using namespace wrf_physics::utils_exceptions;
	if (I > IME || J > JME)
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
	return (this->m_aAirMass2D[I][J].value());
}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME >    auto   wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T,IMS,IME,JMS,JME>::
		                                    operator==(_In_ const DryAirMass &rhs)const-> const bool {

			using namespace wrf_physics::utils_exceptions;
			if (this->m_aAirMass2D.num_elements() != rhs.m_aAirMass2D.num_elements())
				throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Arrays size mismatch: array!!"), rhs.m_aAirMass2D.num_elements(), (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
			return (this->m_aAirMass2D.operator==(rhs.m_aAirMass2D));
		}

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
		 const WRF_ULONGLONG JME >   auto   wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T, IMS, IME, JMS, JME>::
		                                    operator!=(_In_ const DryAirMass &rhs)const-> const bool {
			using namespace wrf_physics::utils_exceptions;
			if (this->m_aAirMass2D.num_elements() != rhs.m_aAirMass2D.num_elements())
				throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Arrays size mismatch: array!!"), rhs.m_aAirMass2D.num_elements(), (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
			return(this->m_aAirMass2D.operator!=(rhs.m_aAirMass2D));
		 }

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME >    auto    wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T,IMS,IME,JMS,JME>::
		                                     operator>(_In_ const DryAirMass &rhs)const-> const bool {
			using namespace wrf_physics::utils_exceptions;
		    if (this->m_aAirMass2D.num_elements() != rhs.m_aAirMass2D.num_elements())
				throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Arrays size mismatch: array!!"), rhs.m_aAirMass2D.num_elements(), (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
			return(this->m_aAirMass2D.operator>(rhs.m_aAirMass2D));
		}

template<typename T,
	    const WRF_ULONGLONG IMS,
	    const WRF_ULONGLONG IME,
	    const WRF_ULONGLONG JMS,
	    const WRF_ULONGLONG JME >    auto     wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T,IMS,IME,JMS,JME>::
		                                      operator<(_In_ const DryAirMass &rhs)const-> const bool {
	        using namespace wrf_physics::utils_exceptions;
			if (this->m_aAirMass2D.num_elements() != rhs.m_aAirMass2D.num_elements())
				throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Arrays size mismatch: array!!"), rhs.m_aAirMass2D.num_elements(), (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
			return(this->m_aAirMass2D.operator<(rhs.m_aAirMass2D));
		}

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME >   auto      wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T,IMS,IME,JMS,JME>::
		                                       getAirMass2D()const->AirMass const & {
			return (this->m_aAirMass2D);
		 }

#if defined DEBUG_VERBOSE

template<typename T,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME >    auto     wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T,IMS,IME,JMS,JME>::
		                                       debug_print(_In_ const WRF_STRING &Msg,
		                                                   _In_ const WRF_INT Line,
		                                                   _In_ const WRF_WSTRING &FuncAddress)const->void {

					std::cerr << "*********debug_print was called**********" << std::endl;
				    std::cerr << __DATE__ << " " << __TIME__ << std::endl;
				    std::cerr << "Executing in: " << Msg.c_str() << std::endl;
					std::cerr << "At line #: " << Line << std::endl;
					std::cerr << "At virtual address: " << std::hex << FuncAddress.c_str() << std::endl;
		 }
#endif

template<typename T,
	const WRF_ULONGLONG IMS,
	const WRF_ULONGLONG IME,
	const WRF_ULONGLONG JMS,
	const WRF_ULONGLONG JME >    auto   operator<<(_In_ std::ostream &os,
	                                               _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T, IMS, IME, JMS, JME>& rhs)->std::ostream {

		std::cout << typeid(rhs).name() << " Object state dump: " << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << "      AirDensity[Pa]:      " << std::endl;
		std::cout << "---------------------------" << std::endl;
		for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
			for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {

				os << std::fixed << std::setprecision(15) << std::setw(8) <<
					rhs.operator()(i, j) << std::endl;
			}
			os << "-------------------------" << std::endl;
		}
		std::cout << "------- End of state dump ---------" << std::endl;
		return (os);
	}
		

	    
	    
	     