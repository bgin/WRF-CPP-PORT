
template<typename T,
	    const std::size_t IMS,
		const std::size_t IME,
		const std::size_t JMS,
		const std::size_t JME,
		class Terrain >  wrf_port_cpp::wrf_physics_impl::TerrainGrad3x3<T,IMS,IME,JMS,JME,Terrain>::
			             TerrainGrad3x3(_In_ const Terrain &terrain_map,
			                            _In_ const T dx,
			                            _In_ const T dy) :
			m_TerrainMap{ terrain_map },
			m_aGradient3x3{ boost::extents[IME][JME] },
			m_dx{ dx },
			m_dy{ dy }
		{
			for (std::size_t i{ IMS }; i != IME; ++i) {
				for (std::size_t j{ JMS }; j != JME; ++j) {

					this->m_aGradient3x3[i][j] = terrain_map.getTerrain2DMap()[i][j].value();
				}
			}
		}

template<typename T,
	     const std::size_t IMS,
		 const std::size_t IME,
		 const std::size_t JMS,
		 const std::size_t JME,
		 class Terrain   >    wrf_port_cpp::wrf_physics_impl::TerrainGrad3x3<T,IMS,IME,JMS,JME,Terrain>::
			                  TerrainGrad3x3(_In_ const TerrainGrad3x3 &rhs) :
			 m_TerrainMap{ rhs.m_TerrainMap },
			 m_aGradient3x3{ rhs.m_aGradient3x3 },
			 m_dx{ rhs.m_dx },
			 m_dy{ rhs.m_dy }
		 {

		 }

template<typename T,
	    const std::size_t IMS,
		const std::size_t IME,
		const std::size_t JMS,
		const std::size_t JME,
		class Terrain     >   wrf_port_cpp::wrf_physics_impl::TerrainGrad3x3<T,IMS,IME,JMS,JME,Terrain>::
			                  TerrainGrad3x3(_In_ TerrainGrad3x3 &&rhs) :
			m_TerrainMap{ std::move(rhs.m_TerrainMap) },
			m_aGradient3x3{ std::move(rhs.m_aGradient3x3) },
			m_dx{ std::move(rhs.m_dx) },
			m_dy{ std::move(rhs.m_dy) }
		{

		}

template<typename T,
	    const std::size_t IMS,
		const std::size_t IME,
		const std::size_t JMS,
		const std::size_t JME,
		class  Terrain  >  auto  wrf_port_cpp::wrf_physics_impl::TerrainGrad3x3<T,IMS,IME,JMS,JME,Terrain>::
			operator=(_In_ const TerrainGrad3x3 &rhs)->TerrainGrad3x3 & {
			if (this == &rhs) return (*this);
			TerrainGrad3x3 temp{ rhs };
			std::swap(*this, temp);
			return (*this);
		}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME,
        class  Terrain  >   auto   wrf_port_cpp::wrf_physics_impl::TerrainGrad3x3<T,IMS,IME,JMS,JME,Terrain>::
			operator=(_In_ TerrainGrad3x3 &&rhs)->TerrainGrad3x3 & {
			if (this == &rhs) return (*this);
			TerrainGrad3x3 temp{ rhs };
			std::swap(*this, temp);
			return (*this);
		}

template<typename T,
	    const std::size_t IMS,
		const std::size_t IME,
		const std::size_t JMS,
		const std::size_t JME,
        class  Terrain  >    auto  wrf_port_cpp::wrf_physics_impl::TerrainGrad3x3<T,IMS,IME,JMS,JME,Terrain>::
			operator()(_In_ const std::size_t I,
			_In_ const std::size_t J)const->const T{

			if ((I > IME) || (J > JME))
			    throw std::invalid_argument(std::string("Invalid argument in TerrainGrad3x3::operator()\n"));
			return (this->m_aGradient3x3[I][J]);
		}

template<typename T,
        const std::size_t IMS,
        const std::size_t IME,
        const std::size_t JMS,
        const std::size_t JME,
		class  Terrain  >    auto wrf_port_cpp::wrf_physics_impl::TerrainGrad3x3<T,IMS,IME,JMS,JME,Terrain>::
			compute_grad3x3()->TerrainGrad3x3 & {

			boost::multi_array<T, 2> temp{ boost::extents[IME][JME] };
			T inv_dx(1.0 / this->m_dx);
			T inv_dy(1.0 / this->m_dy);
			for (std::size_t i{ IMS  }; i != IME - 1; ++i) {
				for (std::size_t j{ JMS + 1 }; j != JME - 1; ++j) {

					temp[i][j] = inv_dx * (this->m_aGradient3x3[i][j + 1] - this->m_aGradient3x3[i][j]) + 
						         inv_dy * (this->m_aGradient3x3[j-1][i] - this->m_aGradient3x3[j][i]);
					//std::cout << std::fixed << std::setprecision(15) << temp[i][j] << std::endl;
				}
			}
			this->m_aGradient3x3.operator=(temp);
			return (*this);
		}


template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME,
        class  Terrain >  wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			              TerrainGrad8P3x3(_In_ const Terrain &terrain_map,
			                               _In_ const T dx,
			                               _In_ const T dy) :
		    m_TerrainMap{terrain_map},
			m_aFx{  boost::extents[IME][JME] },
			m_aFy{  boost::extents[IME][JME] },
			m_aFxx{ boost::extents[IME][JME] },
			m_aFyy{ boost::extents[IME][JME] },
			m_aFxy{ boost::extents[IME][JME] },
			m_dx{ dx },
			m_dy{ dy },
			m_bisComputed{false}
		{
#if 1
			std::cerr << "Inside TerrainGrad8P3x3 -- Ctor" << std::endl;
#endif
		}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME,
        class  Terrain  >  wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			               TerrainGrad8P3x3(_In_ const TerrainGrad8P3x3 &rhs) :
			m_TerrainMap{rhs.m_TerrainMap},
			m_aFx{ rhs.m_aFx },
			m_aFy{ rhs.m_aFy },
			m_aFxx{ rhs.m_aFxx },
			m_aFyy{ rhs.m_aFyy },
			m_aFxy{ rhs.m_aFxy },
			m_dx{ rhs.m_dx },
			m_dy{ rhs.m_dy },
			m_bisComputed{rhs.m_bisComputed}
		{

		}

template<typename T,
	     const std::size_t IMS,
	     const std::size_t IME,
	     const std::size_t JMS,
	     const std::size_t JME,
         class  Terrain  >  wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			                TerrainGrad8P3x3(_In_  TerrainGrad8P3x3 &&rhs) :
			 m_TerrainMap{ std::move(rhs.m_TerrainMap) },
			 m_aFx{ std::move(rhs.m_aFx) },
			 m_aFy{ std::move(rhs.m_aFy) },
			 m_aFxx{ std::move(rhs.m_aFxx) },
			 m_aFyy{ std::move(rhs.m_aFyy) },
			 m_aFxy{ std::move(rhs.m_aFxy) },
			 m_dx{ std::move(rhs.m_dx) },
			 m_dy{ std::move(rhs.m_dx) },
			 m_bisComputed{ std::move(rhs.m_bisComputed) }
		 {

		 }

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME,
        class  Terrain  >   auto  wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			operator=(_In_ const TerrainGrad8P3x3 &rhs)->TerrainGrad8P3x3 & {

			if (this == &rhs) return (*this);
			TerrainGrad8P3x3 temp{ rhs };
			std::swap(*this, temp);
			return  (*this);
		}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME,
        class  Terrain  >  auto  wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			operator=(_In_ TerrainGrad8P3x3 &&rhs)->TerrainGrad8P3x3 & {

			if (this == &rhs) return (*this);
			TerrainGrad8P3x3 temp{ rhs };
			std::swap(*this, temp);
			return (*this);
		}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME,
        class  Terrain >  auto  wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			getFx()const-> boost::multi_array<T, 2> const & {

			return (this->m_aFx);
		}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME,
        class  Terrain >   auto  wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3<T, IMS, IME, JMS, JME, Terrain>::
	        getFy()const-> boost::multi_array<T, 2> const & {

	        return (this->m_aFy);
}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME,
        class  Terrain >    auto  wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3<T, IMS, IME, JMS, JME, Terrain>::
			   getFxx()const->boost::multi_array<T, 2> const & {

			return (this->m_aFxx);
		}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME,
        class  Terrain >     auto  wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3<T, IMS, IME, JMS,JME, Terrain>::
		       getFyy()const->boost::multi_array<T, 2> const & {

		   return (this->m_aFyy);
	   }

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME,
        class  Terrain >       auto  wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3< T, IMS, IME, JMS, JME, Terrain>::
		       getFxy()const->boost::multi_array<T, 2> const & {

		return (this->m_aFxy);
	}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME,
        class  Terrain >       auto wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			compute_grad8P3x3()->TerrainGrad8P3x3 & {

			T two_dx(this->m_dx + this->m_dx);
			T two_dy(this->m_dy + this->m_dy);
			T dxdx(this->m_dx   *  this->m_dx);
			T dydy(this->m_dy   * this->m_dy);
			T four_dxdy(4.0 * this->m_dx * this->m_dy);
#if 0
			std::cerr << "Inside: compute_grad8P3x3 , before the 1st loop" << std::endl;
#endif
			for (std::size_t i{ IMS }; i != IME; ++i) {
				for (std::size_t j{ JMS + 1 }; j != JME - 1; ++j) {

					this->m_aFx[i][j] = (m_TerrainMap.getTerrain2DMap()[i][j - 1].value() -
						m_TerrainMap.getTerrain2DMap()[i][j + 1].value()) / two_dx;

					this->m_aFy[i][j] = (m_TerrainMap.getTerrain2DMap()[j - 1][i].value() -
						m_TerrainMap.getTerrain2DMap()[j + 1][i].value()) / two_dy;

					this->m_aFxx[i][j] = (m_TerrainMap.getTerrain2DMap()[i][j - 1].value() -
						(2.0 * m_TerrainMap.getTerrain2DMap()[i][j].value() + m_TerrainMap.getTerrain2DMap()[i][j + 1].value())) / dxdx;

					this->m_aFyy[i][j] = (m_TerrainMap.getTerrain2DMap()[j - 1][i].value() -
						(2.0 * m_TerrainMap.getTerrain2DMap()[j][i].value() + m_TerrainMap.getTerrain2DMap()[j + 1][i].value())) / dydy;

				}
			}
#if 0
			std::cerr << "Inside: compute_grad8P3x3 , after the 1nd loop" << std::endl;
			std::cerr << "Inside: compute_grad8P3x3 , before the 2nd loop" << std::endl;
#endif
			for (std::size_t i{ IMS + 1 }; i != IME - 1; ++i) {
				for (std::size_t j{ JMS + 1 }; j != JME - 1; ++j) {

					this->m_aFxy[i][j] = (m_TerrainMap.getTerrain2DMap()[i][j + 1].value() +
						m_TerrainMap.getTerrain2DMap()[j + 1][i - 1].value() - m_TerrainMap.getTerrain2DMap()[j - 1][i - 1].value() -
						m_TerrainMap.getTerrain2DMap()[i][j + 1].value()) / four_dxdy;

				}
			}
#if 0
			   
				std::cerr << "Inside: compute_grad8P3x3 ,after the 2nd loop" << std::endl;
#endif
			this->m_bisComputed = true;

			return (*this);
		}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME,
        class  Terrain  >    auto wrf_port_cpp::wrf_physics_impl::TerrainGrad8P3x3<T,IMS,IME,JMS,JME,Terrain>::
			getAllGradients()const->std::tuple < const boost::multi_array<T, 2> &,
			const boost::multi_array<T, 2> &,
			const boost::multi_array<T, 2> &,
			const boost::multi_array<T, 2> &,
			const boost::multi_array<T, 2> & > {

			if (this->m_bisComputed)
				return (std::make_tuple(this->m_aFx, this->m_aFy, this->m_aFxx, this->m_aFyy, this->m_aFxy));
			else
				throw std::runtime_error(std::string("Unknown Error during computation of Gradient\n"));

		}

		
			
			
			
			
		

	    


