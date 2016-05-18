

template<typename T,
	     const std::size_t NSTEPS> wrf_port_cpp::wrf_physics_iface::WindVelocity<T,NSTEPS>::
		                            WindVelocity() :
		 m_Velocity{ boost::extents[2][NSTEPS] } {

	for (std::size_t i{ 0 }; i != 2; ++i) {
#pragma ivdep
#pragma simd
#pragma unroll(4)
		for (std::size_t j{ 0 }; j != NSTEPS; ++j) {

			this->m_Velocity[i][j] = boost::units::quantity<boost::units::si::velocity,T>(static_cast<T>(0)
				                               * boost::units::si::meters_per_second);
				
		}
	}
	   
}
