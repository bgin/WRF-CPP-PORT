
/***************************************************
              Templates implementation 
***************************************************/
/**********************************************
   Implementation of FireTendencyGenImpl
**********************************************/
template<typename T,
	    const std::size_t IDS,
	    const std::size_t IDE,
	    const std::size_t KDS,
	    const std::size_t KDE,
	    const std::size_t JDS,
	    const std::size_t JDE,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t KMS,
	    const std::size_t KME,
	    const std::size_t JMS,
	    const std::size_t JME,
	    const std::size_t ITS,
	    const std::size_t ITE,
	    const std::size_t KTS,
	    const std::size_t KTE,
	    const std::size_t JTS,
		const std::size_t JTE > wrf_port_cpp::wrf_physics_impl::FireTendencyGenImpl<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
		IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE > ::FireTendencyGenImpl() :
		m_aRthFrTen{ boost::extents[IME][KME][JME] },
		m_aRQvFrTen{ boost::extents[IME][KME][JME] }
{
	/* Zero-fill the arrays*/
	for (std::size_t i{ IMS }; i != IME; ++i) {
		for (std::size_t k{ KMS }; k != KME; ++k) {
#pragma simd
#pragma unroll (4)
			for (std::size_t j{ JMS }; j != JME; ++j) {

				this->m_aRthFrTen[i][k][j] = static_cast<T>(0);
				this->m_aRQvFrTen[i][k][j] = static_cast<T>(0);
			}
		}
	}
}

template<typename T,
	    const std::size_t IDS,
	    const std::size_t IDE,
	    const std::size_t KDS,
	    const std::size_t KDE,
	    const std::size_t JDS,
	    const std::size_t JDE,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t KMS,
	    const std::size_t KME,
	    const std::size_t JMS,
	    const std::size_t JME,
	    const std::size_t ITS,
	    const std::size_t ITE,
	    const std::size_t KTS,
	    const std::size_t KTE,
	    const std::size_t JTS,
		const std::size_t JTE > wrf_port_cpp::wrf_physics_impl::FireTendencyGenImpl<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
		IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE >::FireTendencyGenImpl(_In_ const FireTendencyGenImpl &rhs) :
		m_aRthFrTen{ rhs.m_aRthFrTen },
		m_aRQvFrTen{ rhs.m_aRQvFrTen }
{

}

template<typename T,
	    const std::size_t IDS,
	    const std::size_t IDE,
	    const std::size_t KDS,
	    const std::size_t KDE,
	    const std::size_t JDS,
	    const std::size_t JDE,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t KMS,
	    const std::size_t KME,
	    const std::size_t JMS,
	    const std::size_t JME,
	    const std::size_t ITS,
	    const std::size_t ITE,
	    const std::size_t KTS,
	    const std::size_t KTE,
	    const std::size_t JTS,
		const std::size_t JTE > wrf_port_cpp::wrf_physics_impl::FireTendencyGenImpl<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
		IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE > ::FireTendencyGenImpl(_In_ FireTendencyGenImpl &&rhs) :
		m_aRthFrTen{ std::move(rhs.m_aRthFrTen) },
		m_aRQvFrTen{ std::move(rhs.m_aRQvFrTen) }
{

}

template<typename T,
	    const std::size_t IDS,
	    const std::size_t IDE,
	    const std::size_t KDS,
	    const std::size_t KDE,
	    const std::size_t JDS,
	    const std::size_t JDE,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t KMS,
	    const std::size_t KME,
	    const std::size_t JMS,
	    const std::size_t JME,
	    const std::size_t ITS,
	    const std::size_t ITE,
	    const std::size_t KTS,
	    const std::size_t KTE,
	    const std::size_t JTS,
		const std::size_t JTE > auto wrf_port_cpp::wrf_physics_impl::FireTendencyGenImpl<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
		IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE > ::operator=(_In_ const FireTendencyGenImpl &rhs)->FireTendencyGenImpl & {

	if (this == &rhs) return (*this);
	this->m_aRthFrTen.operator=(rhs.m_aRthFrTen);
	this->m_aRQvFrTen.operator=(rhs.m_aRQvFrTen);
	return (*this);
}


template<typename T,
	const std::size_t IDS,
	const std::size_t IDE,
	const std::size_t KDS,
	const std::size_t KDE,
	const std::size_t JDS,
	const std::size_t JDE,
	const std::size_t IMS,
	const std::size_t IME,
	const std::size_t KMS,
	const std::size_t KME,
	const std::size_t JMS,
	const std::size_t JME,
	const std::size_t ITS,
	const std::size_t ITE,
	const std::size_t KTS,
	const std::size_t KTE,
	const std::size_t JTS,
	const std::size_t JTE > auto wrf_port_cpp::wrf_physics_impl::FireTendencyGenImpl<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
	IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE > ::operator=(_In_  FireTendencyGenImpl &&rhs)->FireTendencyGenImpl & {

	if (this == &rhs) return (*this);
	this->m_aRthFrTen.operator=(std::move(rhs.m_aRthFrTen));
	this->m_aRQvFrTen.operator=(std::move(rhs.m_aRQvFrTen));
	return (*this);
}

template<typename T,
	    const std::size_t IDS,
	    const std::size_t IDE,
	    const std::size_t KDS,
	    const std::size_t KDE,
	    const std::size_t JDS,
	    const std::size_t JDE,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t KMS,
	    const std::size_t KME,
	    const std::size_t JMS,
	    const std::size_t JME,
	    const std::size_t ITS,
	    const std::size_t ITE,
	    const std::size_t KTS,
	    const std::size_t KTE,
	    const std::size_t JTS,
		const std::size_t JTE > auto wrf_port_cpp::wrf_physics_impl::FireTendencyGenImpl<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
		IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE>::operator()(_In_ const std::size_t I,
		_In_ const std::size_t K,
		_In_ const std::size_t J)const->std::pair < T, T > {

	if ((I > IME) || (K > KME) || (J > JME))
		throw std::invalid_argument("Invalid input in: FireTendencyGenImpl::operator()()\n");

	return (std::make_pair(this->m_aRthFrTen[I][K][J], this->m_aRQvFrTen[I][K][J]));
}

template<typename T,
	    const std::size_t IDS,
	    const std::size_t IDE,
	    const std::size_t KDS,
	    const std::size_t KDE,
	    const std::size_t JDS,
	    const std::size_t JDE,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t KMS,
	    const std::size_t KME,
	    const std::size_t JMS,
	    const std::size_t JME,
	    const std::size_t ITS,
	    const std::size_t ITE,
	    const std::size_t KTS,
	    const std::size_t KTE,
	    const std::size_t JTS,
		const std::size_t JTE > auto operator<<(_In_ std::ostream &os, _In_ const wrf_port_cpp::wrf_physics_impl::FireTendencyGenImpl<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
		IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE> &rhs)->std::ostream & {

	std::cout << "Object state dump: " << std::endl;
	std::cout << "member m_aRthFrTen:                       member m_aRqvFrTen:";
	for (std::size_t i{ IMS }; i != IME; ++i) {
		for (std::size_t k{ KMS }; k != KME; ++k) {
			for (std::size_t j{ JMS }; j != JME; ++j) {
				os << std::setw(4) << std::fixed << std::setprecision(16) << rhs.operator()(i, j, k).first << " , "
					<< std::setw(16) << rhs.operator()(i, j, k).second << std::endl;

			}
			os << std::endl;
		}
		os << std::endl;
	}
	std::cout << "Reached end of object state dump." << std::endl;
	return os;
}
	 

template<typename T,
	    const std::size_t IDS,
	    const std::size_t IDE,
	    const std::size_t KDS,
	    const std::size_t KDE,
	    const std::size_t JDS,
	    const std::size_t JDE,
	    const std::size_t IMS,
	    const std::size_t IME,
	    const std::size_t KMS,
	    const std::size_t KME,
	    const std::size_t JMS,
	    const std::size_t JME,
	    const std::size_t ITS,
	    const std::size_t ITE,
	    const std::size_t KTS,
	    const std::size_t KTE,
	    const std::size_t JTS,
		const std::size_t JTE > auto wrf_port_cpp::wrf_physics_impl::FireTendencyGenImpl<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
		IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE>::compute_fire_tendency(_In_  std::tuple < boost::multi_array<T, 2>,/* grnhfx*/
		                                                                                                boost::multi_array<T, 2>,/* grnqfx*/
		                                                                                                boost::multi_array<T, 2>,/* canhfx*/
		                                                                                                boost::multi_array<T, 2>,/* canqfx*/
		                                                                                                boost::multi_array<T, 2>,/* zs */
		                                                                                                boost::multi_array<T, 2>,/* mu*/
		                                                                                                boost::multi_array<T, 3>,/* z_at_w */
		                                                                                                boost::multi_array<T, 3>,/* dz8w */
		                                                                                                boost::multi_array<T, 3>  /* rho */  >&  Arrays,
		                                                                                                _In_ const T alfg, const T alfc, const T z1can)->void {

	T cp_i{ 9.9542106310969540115468843320725e-4 }; T xlv_i{ 0.0000004 };
	T rho_i, z_w, fact_g, fact_c, alfg_i, alfc_i;
	boost::multi_array<T, 3> hfx{ boost::extents[IME][KME][JME] };
	boost::multi_array<T, 3> qfx{ boost::extents[IME][KME][JME] };
	alfg_i = 1.0 / alfg;
	alfc_i = 1.0 / alfc;
#pragma simd
#pragma unroll(4)
	for (std::size_t i{ IMS }; i != IME; ++i) {
		for (std::size_t k{ KMS }; k != KME; ++k) {

			for (std::size_t j{ JMS }; j != JME; ++j) {

				/* set z (meters above ground)*/                        //[i][k]
				z_w = std::get<6>(Arrays)[i][k][j] - std::get<4>(Arrays)[i][j];

				/* heat flux */
				fact_g = cp_i * std::exp(-alfg_i * z_w);
				if (z_w < z1can)
					fact_c = cp_i;
				else
					fact_c = cp_i * std::exp(-alfc_i * (z_w - z1can)); //[i][k]                //[i][k]
				hfx[i][k][j] = fact_g * std::get<0>(Arrays)[i][j] + fact_c * std::get<2>(Arrays)[i][j];

				/* vapour flux */
				fact_g = xlv_i * std::exp(-alfg_i * z_w);
				if (z_w < z1can)
					fact_c - xlv_i;
				else
					fact_c = xlv_i * std::exp(-alfc_i * (z_w - z1can)); //[i][k]                      //[i][k]
				qfx[i][k][j] = fact_g * std::get<1>(Arrays)[i][j] + fact_c * std::get<3>(Arrays)[i][j];
			}
		}
	}
	std::cout << "end of first 3D loop" << std::endl;
	/* add flux divergence to tendencies

	Multiply by dry air mass (mu) to eliminate the need
	to call sr. calculate_phy_tend(in dyn_em/module_em)*/
#pragma simd
	for (std::size_t i{ IMS }; i != IME; ++i) {
		for (std::size_t k{ KMS }; k != KME-1; ++k) {

			for (std::size_t j{ JMS }; j != JME; ++j) {
				rho_i = static_cast<T>(1.0) / std::get<8>(Arrays)[i][k][j];

				this->m_aRthFrTen[i][k][j] = -std::get<5>(Arrays)[i][k] * rho_i * (hfx[i][k + 1][j] - hfx[i][k][j]) / std::get<7>(Arrays)[i][k][j];
				this->m_aRQvFrTen[i][k][j] = -std::get<5>(Arrays)[i][k] * rho_i * (qfx[i][k + 1][j] - qfx[i][k][j]) / std::get<7>(Arrays)[i][k][j];
			}
		}
	}
	std::cout << "end of secon 3D loop" << std::endl;

}


template<const std::size_t IDS,
	     const std::size_t IDE,
	     const std::size_t KDS,
	     const std::size_t KDE,
	     const std::size_t JDS,
	     const std::size_t JDE,
	     const std::size_t IMS,
	     const std::size_t IME,
	     const std::size_t KMS,
	     const std::size_t KME,
	     const std::size_t JMS,
	     const std::size_t JME,
	     const std::size_t ITS,
	     const std::size_t ITE,
	     const std::size_t KTS,
	     const std::size_t KTE,
	     const std::size_t JTS,
		 const std::size_t JTE > wrf_port_cpp::wrf_physics_impl::FireTendencySPImpl<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
		 IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE > ::FireTendencySPImpl() :
		 m_aRthFrTen{ boost::extents[IME][KME][JME] },
		 m_aRQvFrTen{ boost::extents[IME][KME][JME] }
{
	/* Assume ualigned access*/
	for (std::size_t i{ IMS }; i != IME; ++i) {
		for (std::size_t k{ KMS }; k != KME; ++k) {
			for (std::size_t j{ JMS }; j != JME; j += 4) {
				_mm256_storeu_pd(&this->m_aRthFrTen[i][k][j], _mm256_setzero_pd());
				_mm256_storeu_pd(&this->m_aRQvFrTen[i][k][j], _mm256_setzero_pd());
			}
		}
	}
}
	     
	    
template<const std::size_t IDS,
	     const std::size_t IDE,
	     const std::size_t KDS,
	     const std::size_t KDE,
	     const std::size_t JDS,
	     const std::size_t JDE,
	     const std::size_t IMS,
	     const std::size_t IME,
	     const std::size_t KMS,
	     const std::size_t KME,
	     const std::size_t JMS,
	     const std::size_t JME,
	     const std::size_t ITS,
	     const std::size_t ITE,
	     const std::size_t KTS,
	     const std::size_t KTE,
	     const std::size_t JTS,
		 const std::size_t JTE > wrf_port_cpp::wrf_physics_impl::FireTendencySPImpl<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
		 IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE > ::FireTendencySPImpl(_In_ const FireTendencySPImpl &rhs) :
		 m_aRthFrTen{ rhs.m_aRthFrTen},
		 m_aRQvFrTen{ rhs.m_aRQvFrTen }
{

}

template<const std::size_t IDS,
	const std::size_t IDE,
	const std::size_t KDS,
	const std::size_t KDE,
	const std::size_t JDS,
	const std::size_t JDE,
	const std::size_t IMS,
	const std::size_t IME,
	const std::size_t KMS,
	const std::size_t KME,
	const std::size_t JMS,
	const std::size_t JME,
	const std::size_t ITS,
	const std::size_t ITE,
	const std::size_t KTS,
	const std::size_t KTE,
	const std::size_t JTS,
	const std::size_t JTE > wrf_port_cpp::wrf_physics_impl::FireTendencySPImpl<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
	IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE > ::FireTendencySPImpl(_In_  FireTendencySPImpl &&rhs) :
	m_aRthFrTen{ std::move(rhs.m_aRthFrTen) },
	m_aRQvFrTen{ std::move(rhs.m_aRQvFrTen) }
{

}

template<const std::size_t IDS,
	const std::size_t IDE,
	const std::size_t KDS,
	const std::size_t KDE,
	const std::size_t JDS,
	const std::size_t JDE,
	const std::size_t IMS,
	const std::size_t IME,
	const std::size_t KMS,
	const std::size_t KME,
	const std::size_t JMS,
	const std::size_t JME,
	const std::size_t ITS,
	const std::size_t ITE,
	const std::size_t KTS,
	const std::size_t KTE,
	const std::size_t JTS,
	const std::size_t JTE > auto wrf_port_cpp::wrf_physics_impl::FireTendencySPImpl<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
	IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE > ::operator=(_In_ const FireTendencySPImpl &rhs)->FireTendencySPImpl & {

	if (this == &rhs) return (*this);
	this->m_aRthFrTen.operator=(rhs.m_aRthFrTen);
	this->m_aRQvFrTen.operator=(rhs.m_aRQvFrTen);
	return (*this);
}


template<const std::size_t IDS,
	const std::size_t IDE,
	const std::size_t KDS,
	const std::size_t KDE,
	const std::size_t JDS,
	const std::size_t JDE,
	const std::size_t IMS,
	const std::size_t IME,
	const std::size_t KMS,
	const std::size_t KME,
	const std::size_t JMS,
	const std::size_t JME,
	const std::size_t ITS,
	const std::size_t ITE,
	const std::size_t KTS,
	const std::size_t KTE,
	const std::size_t JTS,
	const std::size_t JTE > auto wrf_port_cpp::wrf_physics_impl::FireTendencySPImpl<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
	IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE > ::operator=(_In_  FireTendencySPImpl &&rhs)->FireTendencySPImpl & {

	if (this == &rhs) return (*this);
	this->m_aRthFrTen.operator=(std::move(rhs.m_aRthFrTen));
	this->m_aRQvFrTen.operator=(std::move(rhs.m_aRQvFrTen));
	return (*this);
}

template<const std::size_t IDS,
	const std::size_t IDE,
	const std::size_t KDS,
	const std::size_t KDE,
	const std::size_t JDS,
	const std::size_t JDE,
	const std::size_t IMS,
	const std::size_t IME,
	const std::size_t KMS,
	const std::size_t KME,
	const std::size_t JMS,
	const std::size_t JME,
	const std::size_t ITS,
	const std::size_t ITE,
	const std::size_t KTS,
	const std::size_t KTE,
	const std::size_t JTS,
	const std::size_t JTE > auto wrf_port_cpp::wrf_physics_impl::FireTendencySPImpl<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
	IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE>::operator()(_In_ const std::size_t I,
	const std::size_t K,
	const std::size_t J)const->std::pair < double, double > {

	if ((I > IME) || (K > KME) || (J > JME))
		throw std::invalid_argument("Invalid input in: FireTendencyGenImpl::operator()()\n");

	return (std::make_pair(this->m_aRthFrTen[I][K][J], this->m_aRQvFrTen[I][K][J]));
}

template<const std::size_t IDS,
	const std::size_t IDE,
	const std::size_t KDS,
	const std::size_t KDE,
	const std::size_t JDS,
	const std::size_t JDE,
	const std::size_t IMS,
	const std::size_t IME,
	const std::size_t KMS,
	const std::size_t KME,
	const std::size_t JMS,
	const std::size_t JME,
	const std::size_t ITS,
	const std::size_t ITE,
	const std::size_t KTS,
	const std::size_t KTE,
	const std::size_t JTS,
	const std::size_t JTE> auto  operator<<(_In_ std::ostream& os, _In_ const wrf_port_cpp::wrf_physics_impl::FireTendencySPImpl<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
	IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE> &rhs)->std::ostream & {

	std::cout << "Object state dump: " << std::endl;
	std::cout << "member m_aRthFrTen:                       member m_aRqvFrTen:";
	for (std::size_t i{ IMS }; i != IME; ++i) {
		for (std::size_t k{ KMS }; k != KME; ++k) {
			for (std::size_t j{ JMS }; j != JME; ++j) {
				os << std::setw(4) << std::fixed << std::setprecision(16) << rhs.operator()(i, j, k).first << " , "
					<< std::setw(16) << rhs.operator()(i, j, k).second << std::endl;

			}
			os << std::endl;
		}
		os << std::endl;
	}
	std::cout << "Reached end of object state dump." << std::endl;
	return os;
}

template<const std::size_t IDS,
	const std::size_t IDE,
	const std::size_t KDS,
	const std::size_t KDE,
	const std::size_t JDS,
	const std::size_t JDE,
	const std::size_t IMS,
	const std::size_t IME,
	const std::size_t KMS,
	const std::size_t KME,
	const std::size_t JMS,
	const std::size_t JME,
	const std::size_t ITS,
	const std::size_t ITE,
	const std::size_t KTS,
	const std::size_t KTE,
	const std::size_t JTS,
	const std::size_t JTE > auto wrf_port_cpp::wrf_physics_impl::FireTendencySPImpl<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
	IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE>::compute_fire_tendency(_In_ std::tuple < boost::multi_array<double, 2>,
	boost::multi_array<double, 2>,
	boost::multi_array<double, 2>,
	boost::multi_array<double, 2>,
	boost::multi_array<double, 2>,
	boost::multi_array<double, 2>,
	boost::multi_array<double, 3>,
	boost::multi_array<double, 3>,
	boost::multi_array<double, 3> > & Arrays,
	_In_ const double alfag, _In_ const double alfac, _In_ const double z1can)->void {

	const __m256d cp_i(_mm256_set1_pd(9.9542106310969540115468843320725e-4));
	const __m256d xlv_i(_mm256_set1_pd(0.0000004));
	__m256d v_alfag(_mm256_set1_pd(-alfag));
	__m256d v_alfac(_mm256_set1_pd(-alfac));
	__m256d v_z1can(_mm256_set1_pd(z1can));
	__m256d rho_i(_mm256_setzero_pd());
	__m256d fact_g(_mm256_setzero_pd());
	__m256d z_w(_mm256_setzero_pd());
	__m256d fact_c(_mm256_setzero_pd());
	__m256d alfag_i(_mm256_castps_pd(_mm256_rcp_ps(_mm256_castpd_ps(v_alfag))));
	__m256d alfac_i(_mm256_castps_pd(_mm256_rcp_ps(_mm256_castpd_ps(v_alfac))));
	boost::multi_array<double, 3> hfx{ boost::extents[IME][KME][JME] };
	boost::multi_array<double, 3>  qfx{ boost::extents[IME][KME][JME] };
	boost::multi_array<double, 3>   rho_inv{ boost::extents[IME][KME][JME] };

	for (std::size_t i{ IMS }; i != IME; ++i) {
		for (std::size_t k{ KMS }; k != KME; ++k){
			for (std::size_t j{ JMS }; j != JME; j += 4) {

				/* set z (meters above ground)*/
				z_w = _mm256_sub_pd(_mm256_loadu_pd(&std::get<6>(Arrays)[i][k][j]), 
					_mm256_loadu_pd(&std::get<4>(Arrays)[i][j]));

				/* temporaries */
				const __m256d expalfag_zw(_mm256_exp_pd(_mm256_mul_pd(v_alfag, z_w)));
				const __m256d expalfac_zw_z1can(_mm256_exp_pd(_mm256_mul_pd(v_alfac, _mm256_sub_pd(z_w, v_z1can))));

				/* heat flux */
				fact_g = _mm256_mul_pd(cp_i, expalfag_zw);
			  const	__m256d mask(_mm256_cmp_pd(z_w, v_z1can, _CMP_LT_OS));
				/* Eliminate conditional branch */
				fact_c = _mm256_blendv_pd(cp_i, _mm256_mul_pd(cp_i,expalfac_zw_z1can),mask);
				_mm256_storeu_pd(&hfx[i][k][j], _mm256_add_pd(_mm256_mul_pd(fact_g, _mm256_loadu_pd(&std::get<0>(Arrays)[i][j])), 
					_mm256_mul_pd(fact_c, _mm256_loadu_pd(&std::get<2>(Arrays)[i][j]))));

				/* vapour flux */
				fact_g = _mm256_mul_pd(xlv_i, expalfag_zw);
				const __m256d mask2(_mm256_cmp_pd(z_w, v_z1can, _CMP_LT_OS));
				fact_c = _mm256_blendv_pd(xlv_i, _mm256_mul_pd(xlv_i, expalfac_zw_z1can), mask2);
				_mm256_storeu_pd(&qfx[i][k][j], _mm256_add_pd(_mm256_mul_pd(fact_g, _mm256_loadu_pd(&std::get<1>(Arrays)[i][j])), 
					_mm256_mul_pd(fact_c, _mm256_loadu_pd(&std::get<3>(Arrays)[i][j]))));
			}
		}
	}
	std::cout << "end of first 3D loop" << std::endl;
	/* Creates rho inverses values */
	for (std::size_t i{ IMS }; i != IME; ++i) {
		for (std::size_t k{ KMS }; k != KME; ++k) {
			for (std::size_t j{ JMS }; j != JME-4; j += 4) {
				_mm_prefetch(reinterpret_cast<const char*>(&std::get<8>(Arrays)[i][k][j+4]), _MM_HINT_T0);
				_mm256_storeu_pd(&rho_inv[i][k][j], _mm256_castps_pd(_mm256_rcp_ps(_mm256_castpd_ps
					(_mm256_loadu_pd(&std::get<8>(Arrays)[i][k][j])))));
				/* Precompute 1.0/dzw8(i,k,j) */
				_mm256_storeu_pd(&std::get<7>(Arrays)[i][k][j], _mm256_castps_pd(_mm256_rcp_ps(_mm256_castpd_ps(
					_mm256_loadu_pd(&std::get<8>(Arrays)[i][k][j])))));
			}
		}
	}
	std::cout << "end of second 3D loop" << std::endl;
	/* add flux divergence to tendencies

	Multiply by dry air mass (mu) to eliminate the need
	to call sr. calculate_phy_tend(in dyn_em/module_em)*/
	for (std::size_t i{ IMS }; i != IME; ++i) {
		for (std::size_t k{ KMS }; k != KME - 4; k += 4) {
			   for (std::size_t j{ JMS }; j != JME-4; j += 4) {
                    
				   _mm_prefetch(reinterpret_cast<const char*>(&std::get<5>(Arrays)[i][k+4]), _MM_HINT_T0);
				   _mm_prefetch(reinterpret_cast<const char*>(&std::get<7>(Arrays)[i][k][j + 4]), _MM_HINT_T0);

				   const __m256d temp1(_mm256_mul_pd(_mm256_loadu_pd(&std::get<5>(Arrays)[i][k]), _mm256_loadu_pd(&rho_inv[i][k][j])));
				   const __m256d temp2(_mm256_sub_pd(_mm256_loadu_pd(&hfx[i][k + 4][j]), _mm256_loadu_pd(&hfx[i][k][j])));
				   const __m256d temp3(_mm256_sub_pd(_mm256_loadu_pd(&qfx[i][k + 4][j]), _mm256_loadu_pd(&qfx[i][k][j])));

				   _mm256_storeu_pd(&this->m_aRthFrTen[i][k][j], _mm256_mul_pd(_mm256_mul_pd(temp1, temp2), 
					   _mm256_loadu_pd(&std::get<7>(Arrays)[i][k][j])));

				   _mm256_storeu_pd(&this->m_aRQvFrTen[i][k][j], _mm256_mul_pd(_mm256_mul_pd(temp1,temp3),  
					   _mm256_loadu_pd(&std::get<7>(Arrays)[i][k][j])));
			}
		}
	}
	std::cout << "end of third 3D loop" << std::endl;
}
	     