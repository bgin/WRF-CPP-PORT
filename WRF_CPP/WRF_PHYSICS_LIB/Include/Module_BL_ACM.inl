
template<typename T, WRF_INT KL, WRF_INT NSP>  wrf_physics::bl_acm::TRIDIAGONAL<T, KL, NSP>::TRIDIAGONAL() :
m_X{ boost::extents[KL][NSP] },
//m_XX{ boost::extents[KL] }
{}


template<typename T, WRF_INT KL, WRF_INT NSP>  wrf_physics::bl_acm::TRIDIAGONAL<T, KL, NSP>::TRIDIAGONAL(_In_ const TRIDIAGONAL &rhs) :
m_X{ rhs.m_X }
{}


template<typename T, WRF_INT KL, WRF_INT NSP>  wrf_physics::bl_acm::TRIDIAGONAL<T, KL, NSP>::TRIDIAGONAL(_In_ TRIDIAGONAL &&rhs) :
m_X{ std::move(rhs.m_X) }
{}

template<typename T, WRF_INT KL, WRF_INT NSP>  auto wrf_physics::bl_acm::TRIDIAGONAL<T, KL, NSP>::operator=(_In_ const TRIDIAGONAL &rhs)->TRIDIAGONAL & {

	if (this == &rhs) return (*this);
	this->m_X.operator=(rhs.m_X);
	
	return (*this);
}

template<typename T, WRF_INT KL, WRF_INT NSP> auto wrf_physics::bl_acm::TRIDIAGONAL<T, KL, NSP>::operator=(_In_ TRIDIAGONAL &&rhs)->TRIDIAGONAL & {

	if (this == &rhs) return (*this);
	this->m_X.operator=(std::move(rhs.m_X));
	return (*this);
}

template<typename T, WRF_INT KL, WRF_INT NSP> auto wrf_physics::bl_acm::TRIDIAGONAL<T, KL, NSP>::operator()(_In_ const WRF_INT N, _In_ const WRF_INT M)->T {
	static_assert(N <= KL && M <= NSP, "Index out of bounds in TRIDIAGONAL<T,KL,NSP>::operator()");
	return (this->m_X[N][M]);
}

template<typename T, WRF_INT KL, WRF_INT NSP> auto wrf_physics::bl_acm::TRIDIAGONAL<T, KL, NSP>::operator()(_In_ const WRF_INT N, _In_ const WRF_INT M)const->const T{
	static_assert(N <= KL && M <= NSP, "Index out of bounds in TRIDIAGONAL<T,KL,NSP>::operator()");
	return (this->m_X[N][M]);
}

template<typename T,  WRF_INT KL, WRF_INT NSP> auto        operator<<(_In_ std::ostream &os, _In_ wrf_physics::bl_acm::TRIDIAGONAL<T, KL, NSP> &rhs)->std::ostream & {

	for (int i{ 0 }; i != KL; ++i){
		for (int j{ 0 }; j != NSP; ++j){
			os << std::showpoint << std::fixed << std::setprecision(16) <<
				<< "[" << rhs.operator()(i, j) << "]" << std::endl;
		}
		os << std::endl;
	}
	return os;
}

template<typename T, WRF_INT KL, WRF_INT NSP> auto  wrf_physics::bl_acm::TRIDIAGONAL<T, KL, NSP>::solve(_In_ const boost::multi_array<T, 1> &L, _In_ const boost::multi_array<T, 1> &D,
	_In_ const boost::multi_array<T, 1> &U, _In_ const boost::multi_array<T, 2> &B)->TRIDIAGONAL & {
	
	if ((L.num_elements() != KL) || (D.num_elements() != KL) || (U.num_elements() != KL) ||
		(B.num_elements() != (KL * NSP)))
		throw std::runtime_error("Invalid index in TRIDIAGONAL<T,KL,NSP>::solve");

	// Local variables
	boost::multi_array<T, 1> GAM(boost::extents[KL]);
	T BET;

	// Decomposition and forward substitution
	BET = 1.0 / D[0];
	for (WRF_INT i{ 0 }; i != NSP; ++i)
		this->m_X[i][0] = BET * B[i][0];

	for (WRF_INT i{ 1 }; i != KL; ++i) {
		GAM[i] = BET * U[i - 1];
		BET = 1.0 / (D[i] - L[i] * GAM[k]);
		   for (WRF_INT j{ 0 }; j != NSP; ++j)
			    this->m_X[j][i] = BET * (B[j][j] - L[i] * this->m_X[j][i - 1]);
	}

	// Back-substitution
	for (WRF_INT i = KL; i >= 0; --i)
	    for (WRF_INT j{ 0 }; j != NSP; ++j)
		     this->m_X[j][i] = this->m_X[j][i] - GAM[i + 1] * this->m_X[j][i + 1];

	return (*this);
}


