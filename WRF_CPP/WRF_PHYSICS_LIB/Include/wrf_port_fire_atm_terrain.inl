
/********************************************************
                  Class implementation 
********************************************************/


template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
		const std::size_t JME> wrf_port_cpp::wrf_physics_iface::Terrain2D<T, IMS, IME, JMS, JME>::Terrain2D() :
		m_aTerrain2DMap{ boost::extents[IME][JME] }
{
	for (std::size_t i{ IMS }; i != IME; ++i) {
		for (std::size_t j{ JMS }; j != JME; ++j) {
			
			this->m_aTerrain2DMap[i][j] = quantity<length, T>(static_cast<T>(0) * meters);
			
		}
	}
}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
		const std::size_t JME > wrf_port_cpp::wrf_physics_iface::Terrain2D<T, IMS, IME, JMS, JME>::
		Terrain2D(_In_ const boost::multi_array<T, 2> &height_map) :
		m_aTerrain2DMap{ boost::extents[IME][JME] }
{
	//static_assert(height_map.num_elements() == (IME * JME), "Size mismatch in Terrain2D::Terrain2D\n");
#if 1
	std::cerr << "Before loop 2D in Terrain2D CTor" << std::endl;
#endif
	for (std::size_t i{ IMS }; i != IME; ++i) {
		for (std::size_t j{ JMS }; j != JME; ++j) {

			this->m_aTerrain2DMap[i][j] = quantity<length, T>(height_map[i][j] * meters);
		}
	}
}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME > wrf_port_cpp::wrf_physics_iface::Terrain2D<T,IMS,IME,JMS,JME>::
		Terrain2D(_In_ const Terrain2D &rhs) :
		m_aTerrain2DMap{ rhs.m_aTerrain2DMap }
{

}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME > wrf_port_cpp::wrf_physics_iface::Terrain2D<T,IMS,IME,JMS,JME>::
		Terrain2D(_In_ Terrain2D &&rhs) :
		m_aTerrain2DMap{ std::move(rhs.m_aTerrain2DMap) }
{

}
	     

template<typename T,
	   const std::size_t IMS,
	   const std::size_t IME,
	   const std::size_t JMS,
	   const std::size_t JME > auto wrf_port_cpp::wrf_physics_iface::Terrain2D<T,IMS,IME,JMS,JME>::
	   operator=(_In_ const Terrain2D &rhs)->Terrain2D & {

	if (this == &rhs) return (*this);
	Terrain2D temp{ rhs };
	std::swap(*this, temp);
	//this->m_aTerrain2DMap.operator=(rhs.m_aTerrain2DMap);
	return (*this);
}
	     

template<typename T,
	     const std::size_t IMS,
		 const std::size_t IME,
		 const std::size_t JMS,
		 const std::size_t JME > auto wrf_port_cpp::wrf_physics_iface::Terrain2D<T,IMS,IME,JMS,JME>::
		 operator=(_In_ Terrain2D &&rhs)->Terrain2D & {

	if (this == &rhs) return (*this);
	this->m_aTerrain2DMap.operator=(std::move(rhs.m_aTerrain2DMap));
	return (*this);
}

template<typename T,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t JMS,
	    const std::size_t JME > auto wrf_port_cpp::wrf_physics_iface::Terrain2D<T,IMS,IME,JMS,JME>::
		operator()(_In_ const std::size_t I, _In_ const std::size_t J)const-> const T{

	if ((I > IME) || (J > JME))
	throw std::invalid_argument("Argument size mismatch in: Terrain2D::operator()\n");
	return (this->m_aTerrain2DMap[I][J].value());
}

template<typename T,
        const std::size_t IMS,
        const std::size_t IME,
        const std::size_t JMS,
        const std::size_t JME > auto wrf_port_cpp::wrf_physics_iface::Terrain2D<T,IMS,IME,JMS,JME>::
		getTerrain2DMap()const->boost::multi_array<quantity<length, T>,2> const & {

	return (this->m_aTerrain2DMap);
}
        

template<typename T,
         const std::size_t IMS,
         const std::size_t IME,
         const std::size_t JMS,
         const std::size_t JME > auto  wrf_port_cpp::wrf_physics_iface::Terrain2D<T,IMS,IME,JMS,JME>::
		 incr_height(_In_ const std::size_t I, _In_ const std::size_t J, _In_ const T mag)->void {
	if (I > IME || J > JME)
		throw std::invalid_argument("Invalid argument in Terrain2D::incr_height \n");
	this->m_aTerrain2DMap[I][J] += mag;
}
        