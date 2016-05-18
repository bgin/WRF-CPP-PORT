

template<typename T,
	    const std::size_t IMS,
		const std::size_t IME,
		const std::size_t JMS,
		const std::size_t JME > wrf_port_cpp::wrf_physics_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		HeatFluxDensity(_In_ const boost::multi_array<quantity<length, T>, 2> &plane2D,
		_In_ const boost::multi_array<quantity<power, T>, 2> &heat_flux) :
		m_aHeatFlux2D{ boost::extents[IME][JME] } {

	for (std::size_t i{ IMS }; i != IME; ++i) {
		for (std::size_t j{ JMS }; j != JME; ++j) {

			this->m_aHeatFlux2D[i][j] = heat_flux[i][j].value() / plane2D[i][j].value();
		}
	}
}

template<typename T,
	    const std::size_t IMS,
		const std::size_t IME,
		const std::size_t JMS,
		const std::size_t JME > wrf_port_cpp::wrf_physics_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		HeatFluxDensity(_In_ const HeatFluxDensity &rhs) :
		m_aHeatFlux2D{ rhs.m_aHeatFlux2D } {

}

template<typename T,
	    const std::size_t IMS,
		const std::size_t IME,
		const std::size_t JMS,
		const std::size_t JME > wrf_port_cpp::wrf_physics_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		HeatFluxDensity(_In_ HeatFluxDensity &&rhs) :
		m_aHeatFlux2D{ std::move(rhs.m_aHeatFlux2D) } {

}

template<typename T,
	const std::size_t IMS,
	const std::size_t IME,
	const std::size_t JMS, 
	const std::size_t JME > auto wrf_port_cpp::wrf_physics_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
	operator=(_In_ const HeatFluxDensity &rhs)->HeatFluxDensity & {

	if (this == &rhs) (*this);
	HeatFluxDensity temp{ rhs };
	std::swap(*this, temp);
	return (*this);
}

template<typename T,
	    const std::size_t IMS,
		const std::size_t IME,
		const std::size_t JMS,
		const std::size_t JME > auto wrf_port_cpp::wrf_physics_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		operator=(_In_ HeatFluxDensity &&rhs)->HeatFluxDensity & {

	if (this == &rhs) return (*this);
	this->m_aHeatFlux2D.operator=(std::move(rhs.m_aHeatFlux2D));
	return (*this);
}

template<typename T,
	    const std::size_t IMS,
		const std::size_t IME,
		const std::size_t JMS,
		const std::size_t JME > auto wrf_port_cpp::wrf_physics_iface::HeatFluxDensity<T,IMS,IME,JMS,JME>::
		operator()(_In_ const std::size_t I,
		          _In_ const std::size_t J)const->const T{

	if (I > IME || J > JME)
	throw std::invalid_argument(std::string("Invalid input: index!! \n"));

	return (this->m_aHeatFlux2D[I][J]);
}