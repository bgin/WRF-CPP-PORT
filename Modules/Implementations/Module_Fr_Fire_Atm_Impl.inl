
/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library Module Fire Atm Implementation -  definitions.

@file Module_Fr_Fire_Atm_Impl.inl
@author: Bernard Gingold
@version:  1.0.0  08/05/2016
@description: Module_Fr_Fire_Atm_Impl.h
*/

/********************************************************
         Class  FireTendencyAV implementation
*********************************************************/

template<typename T,
	     const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >  wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                            ITS, ITE, KTS, KTE, JTS, JTE>::FireTendencyAV() :
		 m_aRthFrTen{ boost::extents[IME][KME][JME] },
		 m_aRqvFrTen{ boost::extents[IME][KME][JME] } {

										/* Zero-fill class arrays */
					for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {
						for (WRF_ULONGLONG k{ KMS }; k != KME; ++k) {
#pragma ivdep
#pragma simd
#pragma unroll(4)
						      for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {

									this->m_aRthFrTen[i][k][j] = static_cast<T>(0);
									this->m_aRqvFrTen[i][k][j] = static_cast<T>(0);
												}
											}
										}
		 }

template<typename T,
	     const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >  wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                             ITS, ITE, KTS, KTE, JTS, JTE>::FireTendencyAV(_In_ const FireTendencyAV &rhs) :
		 m_aRthFrTen{ rhs.m_aRthFrTen },
		 m_aRqvFrTen{ rhs.m_aRqvFrTen } {

		 }

template<typename T,
	     const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >    wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                              ITS, ITE, KTS, KTE, JTS, JTE>::FireTendencyAV(_In_ FireTendencyAV &&rhs) :
		 m_aRthFrTen{ std::move(rhs.m_aRthFrTen) },
		 m_aRqvFrTen{ std::move(rhs.m_aRqvFrTen) } {

		 }

template<typename T,
	     const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >  auto   wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                   ITS, ITE, KTS, KTE, JTS, JTE>::operator=(_In_ const FireTendencyAV &rhs)->FireTendencyAV & {
					if (this == &rhs) return (*this);
					   FireTendencyAV temp{ rhs };
					   std::swap(*this, temp);
					return (*this);
		 }

template<typename T,
	     const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >    auto   wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                      ITS, ITE, KTS, KTE, JTS, JTE>::operator=(_In_ FireTendencyAV &&rhs)->FireTendencyAV & {
						if (this == &rhs) return (*this);
							this->m_aRthFrTen.operator=(std::move(rhs.m_aRthFrTen));
							this->m_aRqvFrTen.operator=(std::move(rhs.m_aRqvFrTen));
						return (*this);
		 }

template<typename T,
	     const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >     auto    wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                        ITS, ITE, KTS, KTE, JTS, JTE>::operator()(_In_ const WRF_ULONGLONG I,
		                                                                                  _In_ const WRF_ULONGLONG K,
																						  _In_ const WRF_ULONGLONG J)const->const std::pair<T, T> {

	using namespace wrf_physics::utils_exceptions;
	if ((I > IME) || (K > KME) || (J > JME))
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Indices size mismatch: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
	return (std::make_pair(this->m_aRthFrTen[I][K][J], this->m_aRqvFrTen[I][K][J]));
}

template<typename T,
	     const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >  auto    wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                     ITS, ITE, KTS, KTE, JTS, JTE>::getRthFrTen()const->Matrix3D const & {
			 return (this->m_aRthFrTen);
		 }

template<typename T,
	     const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >  auto     wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                      ITS, ITE, KTS, KTE, JTS, JTE>::getRqvFrTen()const->Matrix3D const & {
			  return (this->m_aRqvFrTen);
											  }

template < typename T,
	     const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
	     const WRF_ULONGLONG JTE > auto      wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
	                                    ITS, ITE, KTS, KTE, JTS, JTE>::nth_elem_rth(_In_ const WRF_ULONGLONG I,
	                                                                               _In_ const WRF_ULONGLONG K,
	                                                                               _In_ const WRF_ULONGLONG J)const->const T{
	using namespace wrf_physics::utils_exceptions;
	if ((I > IME) || (K > KME) || (J > JME))
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Indices size mismatch: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
	return (this->m_aRthFrTen[I][K][J]);
}

template < typename T,
	     const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
	     const WRF_ULONGLONG JTE > auto    wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
	                                  ITS, ITE, KTS, KTE, JTS, JTE>::nth_elem_rqv(_In_ const WRF_ULONGLONG I,
	                                                                              _In_ const WRF_ULONGLONG K,
	                                                                              _In_ const WRF_ULONGLONG J)const-> const T{
	using namespace wrf_physics::utils_exceptions;
	if ((I > IME) || (K > KME) || (J > JME))
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Indices size mismatch: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
	return (this->m_aRqvFrTen[I][K][J]);
}

template<typename T,
	     const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >   auto    wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                     ITS, ITE, KTS, KTE, JTS, JTE>::fire_tendency(_In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T, IMS, IME, JMS, JME> &grnhfx,
		                                                                                  _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T, IMS, IME, JMS, JME> &grnqfx,
		                                                                                  _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T, IMS, IME, JMS, JME> &canhfx,
		                                                                                  _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T, IMS, IME, JMS, JME> &canqfx,
		                                                                                  _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T, IMS, IME, JMS, JME> &zs,
		                                                                                  _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T, IMS, IME, JMS, JME> &mu,
		                                                                                  _In_ const Matrix3D &z_at_w,
		                                                                                  _In_ const Matrix3D &dz8w,
		                                                                                  _In_ const Matrix3D &rho,
		                                                                                  _In_ const T alfg,
		                                                                                  _In_ const T alfc,
		                                                                                  _In_ const T z1can)->FireTendencyAV & {
                    
					/* Local variables:  */
					WRF_ULONGLONG i_st, i_en, j_st, j_en, k_st, k_en;
				    T rho_i, z_w, fact_g, fact_c, alfg_i, alfc_i;
				    T cp_i(9.95421063109695401154688e-4);
				    T xlv_i(0.0000004);
					alfg_i = static_cast<T>(1.0) / alfg;
				    alfc_i = static_cast<T>(1.0) / alfc;
				    Matrix3D hfx{ boost::extents[ITE][KTE][JTE] };
				    Matrix3D qfx{ boost::extents[ITE][KTE][JTE] };

					/* set loop indices */
					i_st = std::max(ITS, IDS + 1);
					i_en = std::min(ITE, IDE - 1);
					k_st = KTS;
					k_en = std::min(KTE, KDE - 1);
					j_st = std::max(JTS, JDS + 1);
					j_en = std::min(JTE, JDE - 1);

					/* Distribute fluxes */

					for (WRF_ULONGLONG j{ j_st }; j != j_en; ++j) {
						for (WRF_ULONGLONG k{ k_st }; k != k_en; ++k) {
#pragma ivdep
#pragma simd
#pragma unroll(4)
							for (WRF_ULONGLONG i{ i_st }; i != i_en; ++i) {

								/* set z in meters above the ground.*/
								z_w = z_at_w[i][k][j] - zs.getTerrainMap()[i][j].value();

								/* heat flux */
								fact_g = cp_i * std::exp(-alfg * z_w);
								if (z_w < z1can) //<- possible obstacle in vectorisation: presence of branch here!!
									fact_c = cp_i;
								else
									fact_c = cp_i * std::exp(-alfc_i * (z_w - z1can));
								hfx[i][k][j] = fact_g * grnhfx.getHeatDensity()[i][j] + fact_c * canhfx.getHeatDensity()[i][j];

								/* vapour flux */
								fact_g = xlv_i * std::exp(-alfg_i * z_w);
								if (z_w < z1can)
									fact_c = xlv_i;
								else
									fact_c = xlv_i * std::exp(-alfc_i * (zw - z1can));
								qfx[i][k][j] = fact_g * grnqfx.getHeatDensity()[i][j] + fact_c * canqfx.getHeatDensity()[i][j];
							}
						}
					}


					/*******************************************************
					Add flux divergence to tendencies.
					Multiply by dry air mass (mu) to eliminate the need
					to call func. calculate_phy_tend
					********************************************************/

					for (WRF_ULONGLONG j{ j_st }; j != j_en; ++j) {
						for (WRF_ULONGLONG k{ k_st }; k != k_en; ++k) {
#pragma ivdep
#pragma simd
#pragma unroll(4)
							for (WRF_ULONGLONG i{ i_st }; i != i_en; ++i) {

								rho_i = static_cast<T>(1.0) / rho[i][k][j];
								                                                            // possible obstacle in vectorisation 
								                                                            // flow carried dependency here !
								this->m_aRthFrTen[i][k][j] = mu.getAirMass2D()[i][j].value() * rho_i * (hfx[i][k + 1][j] - hfx[i][k][j]) / dz8w[i][k][j];
								this->m_aRqvFrTen[i][k][j] = mu.getAirMass2D()[i][j].value() * rho_i * (qfx[i][k + 1][j] - qfx[i][k][j]) / dz8w[i][k][j];
									                         
							}
						}
					}

					return (*this);

		 }

template<typename T,
	     const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE > auto    operator<<(_In_ std::ostream &os,
		                                              _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		 ITS, ITE, KTS, KTE, JTS, JTE>& rhs)->std::ostream & {

			 std::cout << typeid(rhs).name() << " Object state dump!!: " << std::endl;
			 std::cout << "-----------------------------------------" << std::endl;
			 std::cout << " Theta Tendency:         Qv Tendency:    " << std::endl;
			 std::cout << "-----------------------------------------" << std::endl;
			 for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {
				 for (WRF_ULONGLONG k{ KMS }; k != KME; ++k) {
					 for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {

						 os << std::fixed << std::setprecision(15) << rhs.operator()(i, k, j).first <<
							 std::setw(20) << rhs.operator()(i, k, j).second << std::endl;
					 }
					 os << "-------------------------------" << std::endl;
				 }
				 os << "--------------------------------" << std::endl;
			 }
			 std::cout << "---------- End of state dump!! ---------" << std::endl;
			 return (os);

		 }

		 
/**************************************************************
         Implementation of class FireTendencyMV
***************************************************************/
  
template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >  wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                            ITS, ITE, KTS, KTE, JTS, JTE>::FireTendencyMV() :

		       m_dRthFrTen{ boost::extents[JME][KME][IME] },
			   m_dRqvFrTen{ boost::extents[JME][KME][IME] } {

										/* Assume unaligned access
										Should not be penalty for that.*/

										for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {
											for (WRF_ULONGLONG k{ KMS }; k != KME; ++k) {
												for (WRF_ULONGLONG i{ IMS }; i != IME; i += 4) {
													_mm256_storeu_pd(&this->m_dRthFrTen[i][k][j], _mm256_setzero_pd());
													_mm256_storeu_pd(&this->m_dRqvFrTen[i][k][j], _mm256_setzero_pd());
												}
											}
										}
		 }


template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >  wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                            ITS, ITE, KTS, KTE, JTS, JTE>::FireTendencyMV(_In_ const FireTendencyMV &rhs) :

		       m_dRthFrTen{ rhs.m_dRthFrTen },
		       m_dRqvFrTen{ rhs.m_dRqvFrTen } {


		 }


template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >   wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                             ITS, ITE, KTS, KTE, JTS, JTE>::FireTendencyMV(_In_ FireTendencyMV &&rhs) :

		       m_dRthFrTen{ std::move(rhs.m_dRthFrTen) },
		       m_dRqvFrTen{ std::move(rhs.m_dRqvFrTen) } {

		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >  auto  wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                  ITS, ITE, KTS, KTE, JTS, JTE>::operator=(_In_ const FireTendencyMV &rhs)->FireTendencyMV & {

				if (this == &rhs) return (*this);
					 FireTendencyMV temp{ rhs };
					 std::swap(*this, temp);
				return (*this);
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >  auto   wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                   ITS, ITE, KTS, KTE, JTS, JTE>::operator=(_In_ FireTendencyMV &&rhs)->FireTendencyMV & {

				if (this == &rhs) return (*this);
					*this = std::move(rhs);
			    return (*this);
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >  auto   wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		 ITS, ITE, KTS, KTE, JTS, JTE>::operator()(_In_ const WRF_ULONGLONG J,
		                                           _In_ const WRF_ULONGLONG K,
												   _In_ const WRF_ULONGLONG I)const-> const std::pair<T, T> {

	         using namespace wrf_physics::utils_exceptions;
			 if ((J > JME) || (K > KME) || (I > IME))
				 throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
			 return (std::make_pair(this->m_dRthFrTen[I][K][J], this->m_dRqvFrTen[I][K][J]));
}

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >   auto   wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                    ITS, ITE, KTS, KTE, JTS, JTE>::getRthFrTen()const->WRF_Mat3DF64 const & { 
			  return (this->m_dRthFrTen); 
		}

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >   auto    wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		 ITS, ITE, KTS, KTE, JTS, JTE>::getRqvFrTen()const->WRF_Mat3DF64 const & {

			 return (this->m_dRqvFrTen);
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >   auto  wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                    ITS, ITE, KTS, KTE, JTS, JTE>::nth_elem_rth(_In_ const WRF_ULONGLONG J,
		                                                                                _In_ const WRF_ULONGLONG K,
		                                                                                _In_ const WRF_ULONGLONG I)const-> const double {
					using namespace wrf_physics::utils_exceptions;
					if ((J > JME) || (K > KME) || (I > IME))
						throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), J, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
					return (this->m_dRthFrTen[J][K][I]);
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >    auto  wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                     ITS, ITE, KTS, KTE, JTS, JTE>::nth_elem_rqv(_In_ const WRF_ULONGLONG J,
		                                                                                 _In_ const WRF_ULONGLONG K,
		                                                                                 _In_ const WRF_ULONGLONG I)const-> const double {
					using namespace wrf_physics::utils_exceptions;
					if ((J > JME) || (K > KME) || (I > IME))
					    throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), J, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
					return (this->m_dRqvFrTen[J][K][I]);
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >    auto  wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                     ITS, ITE, KTS, KTE, JTS, JTE>::fire_tendency(_In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<double, IMS, IME, JMS, JME> &grnhfx,
		                                                                                  _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<double, IMS, IME, JMS, JME> &grnqfx,
		                                                                                  _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<double, IMS, IME, JMS, JME> &canhfx,
		                                                                                  _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<double, IMS, IME, JMS, JME> &canqfx,
		                                                                                  _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<double, IMS, IME, JMS, JME> &zs,
		                                                                                  _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<double, IMS, IME, JMS, JME> &mu,
		                                                                                  _In_ const WRF_Mat3DF64 &z_at_w,
		                                                                                  _In_ const WRF_Mat3DF64 &dz8w,
		                                                                                  _In_ const WRF_Mat3DF64 &rho,
		                                                                                  _In_ const double alfg,
		                                                                                  _In_ const double alfc,
		                                                                                  _In_ const double z1can)->FireTendencyMV & {
                  


					 /* Local variables:  */
			 WRF_ULONGLONG i_st, i_en, j_st, j_en, k_st, k_en;
			 const __m256d cp_i(_mm256_set1_pd(9.9542106310969540115468E-4));
			 const __m256d xlv_i(_mm256_set1_pd(0.0000004));
			 __m256d v_alfg(_mm256_set1_pd(-alfg));
			 __m256d v_alfc(_mm256_set1_pd(-alfc));
			 __m256d v_z1can(_mm256_set1_pd(z1can));
			 __m256d rho_i(_mm256_setzero_pd());
			 __m256d fact_g(_mm256_setzero_pd());
			 __m256d fact_c(_mm256_setzero_pd());
			 __m256d z_w(_mm256_setzero_pd());
			 __m256d alfg_i(_mm256_castps_pd(_mm256_rcp_ps(_mm256_castpd_ps(v_alfg))));
			 __m256d alfc_i(_mm256_castps_pd(_mm256_rcp_ps(_mm256_castpd_ps(v_alfc))));
			 WRF_Mat3DF64 hfx{ boost::extents[IME][KME][JME] };
			 WRF_Mat3DF64 qfx{ boost::extents[IME][KME][JME] };

			 /* Indices must be set either -/+ 1 above or below modulo(n) == 0*/
			 i_st = std::max(ITS, IDS + 1);
			 i_en = std::min(ITE, IDE - 1);
			 k_st = KTS;
			 k_en = std::min(KTE, KDE - 1);
			 j_st = std::max(JTS, JDS + 1);
			 j_en = std::min(JTE, JDE - 1);

			 /* Distribute Fluxes */

			 for (WRF_ULONGLONG j{ j_st }; j != j_en; ++j) {
				 for (WRF_ULONGLONG k{ k_st }; k != k_en; ++k) {
					 for (WRF_ULONGLONG i{ i_st }; i != i_en; i += 4) {

						 /* Prefetch arrays to L1D */
						 _mm_prefetch(reinterpret_cast<const char*>(&zs.getTerrainMap()[i][j].value()),_MM_HINT_T0);
						 _mm_prefetch(reinterpret_cast<const char*>(&z_at_w[i][j]),_MM_HINT_T0);

						 /* Set z (meters above the ground) */
						 z_w = _mm256_sub_pd(_mm256_loadu_pd(&z_at_w[i][k][j]), _mm256_loadu_pd(&zs.getTerrainMap()[i][j].value()));

						 /* pre-computed constants */
						 const __m256d expalfg_zw(_mm256_exp_pd(_mm256_mul_pd(v_alfg, z_w)));
						 const __m256d expalfczw_z1can(_mm256_exp_pd(_mm256_mul_pd(v_alfc, _mm256_sub_pd(z_w, v_z1can))));

						 /* Heat flux */
						 fact_g = _mm256_mul_pd(cp_i, expalfg_zw);
						 const __m256d mask(_mm256_cmp_pd(z_w, v_z1can, _CMP_LT_OS));
						 /* Eliminate conditional branch */
						 fact_c = _mm256_blendv_pd(cp_i, _mm256_mul_pd(cp_i, expalfczw_z1can), mask);
						 /* Prefetch to L1D */
						 _mm_prefetch(reinterpret_cast<const char*>(&grnhfx.getHeatDensity()[i][j]),_MM_HINT_T0);
						 _mm_prefetch(reinterpret_cast<const char*>(&canhfx[i][j]),_MM_HINT_T0);
						 _mm256_storeu_pd(&hfx[i][k][j], _mm256_add_pd(_mm256_mul_pd(fact_g, _mm256_loadu_pd(&
							 grnhfx.getHeatDensity()[i][j])), _mm256_mul_pd(fact_c, _mm256_loadu_pd(&canhfx.getHeatDensity()[i][j]))));

						 /* Vapour flux */
						 fact_g = _mm256_mul_pd(xlv_i, expalfg_zw);
						 const __m256d mask2(_mm256_cmp_pd(z_w, v_z1can, _CMP_LT_OS));
						 fact_c = _mm256_blendv_pd(xlv_i, _mm256_mul_pd(xlv_i, expalfczw_z1can), mask2);
						 /* Prefetch to L1D */
						 _mm_prefetch(reinterpret_cast<const char*>(&grnqfx.getHeatDensity()[i][j]),_MM_HINT_T0);
						 _mm_prefetch(reinterpret_cast<const char*>(&canqfx.getHeatDensity()[i][j]),_MM_HINT_T0);
						 _mm256_storeu_pd(&qfx[i][k][j], _mm256_add_pd(_mm256_mul_pd(fact_g, _mm256_loadu_pd(&
							 grnqfx.getHeatDensity[i][j])), _mm256_mul_pd(fact_c, _mm256_loadu_pd(&canqfx.getHeatDensity()[i][j]))));

					 }
				 }
			 }

			 /* Add flux divergence to tendencies.
			 Multiply by dry air mass(mu) in order
			 to eliminate call to func. calculate_phy_tend*/
			 for (WRF_ULONGLONG j{ j_st }; j != j_en; ++j) {
				 for (WRF_ULONGLONG k{ k_st }; k != k_en - 1; ++k) {
					 for (WRF_ULONGLONG i{ i_st }; i != i_en - 4; i += 4) {

						 /* Prefetch to L1D */
						 _mm_prefetch(reinterpret_cast<const char*>(&rho[i + 4][k][j]),_MM_HINT_T0);
						 rho_i = _mm256_castps_pd(_mm256_rcp_ps(_mm256_castpd_ps(_mm256_loadu_pd(&rho[i][k][j]))));

						 /* Compute temporaries */
						 _mm_prefetch(reinterpret_cast<const char*>(&mu.getAirMass2D()[i + 4][j].value()), _MM_HINT_T0);
						 const __m256d t0(_mm256_mul_pd(_mm256_loadu_pd(&mu.getAirMass2D()[i][j].value()), rho_i));
						// _mm_prefetch(reinterpret_cast<const char*>(&hfx[i + 4][k + 1][j]), _MM_HINT_T0);

						 const __m256d t1(_mm256_sub_pd(_mm256_loadu_pd(&hfx[i][k + 1][j]), _mm256_loadu_pd(&hfx[i][k][j])));
						 const __m256d t2(_mm256_sub_pd(_mm256_loadu_pd(&qfx[i][k + 1][j]), _mm256_loadu_pd(&qfx[i][k][j])));

						 _mm_prefetch(reinterpret_cast<const char*>(&dz8w[i + 4][k][j]), _MM_HINT_T0);
						 _mm256_storeu_pd(&this->m_dRthFrTen[i][k][j], _mm256_div_pd(_mm256_mul_pd(t0, t1),
							 _mm256_loadu_pd(&dz8w[i][k][j])));
						 _mm256_storeu_pd(&this->m_dRqvFrTen[i][k][j], _mm256_div_pd(_mm256_mul_pd(t0, t2),
							 _mm256_loadu_pd(&dz8w[i][k][j])));

					 }
				 }
			 }
			 
			 return (*this);
		 }

template<const WRF_ULONGLONG IDS,
		 const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
		 const WRF_ULONGLONG KDE,
		 const WRF_ULONGLONG JDS,
		 const WRF_ULONGLONG JDE,
		 const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
		 const WRF_ULONGLONG KME,
		 const WRF_ULONGLONG JMS,
		 const WRF_ULONGLONG JME,
		 const WRF_ULONGLONG ITS,
		 const WRF_ULONGLONG ITE,
		 const WRF_ULONGLONG KTS,
		 const WRF_ULONGLONG KTE,
		 const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE > auto   operator<<(_In_ std::ostream &os,
		                                             const _In_ wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV < double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                             ITS, ITE, KTS, KTE, JTS, JTE> &rhs)->std::ostream & {

			 std::cout << typeid(rhs).name() << " Object state dump:" << std::endl;
			 std::cout << "----------------------------------------" << std::endl;
			 std::cout << "  Theta tendency:       Qv  tendency:   " << std::endl;
			 std::cout << "----------------------------------------" << std::endl;
			 
			 for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {
				 for (WRF_ULONGLONG k{ KMS }; k != KME; ++k) {
					 for (WRF_ULONGLONG i{ IMS }; i != IME; ++i) {

						 os << std::fixed << std::setprecision(15) << rhs.operator(i, k, j).first <<
							 std::setw(20) << rhs.operator(i, k, j).second << std::endl;
					 }
					 os << "-------------------------------" << std::endl;
				 }
				 os << "--------------------------------" << std::endl;
			 }
			 std::cout << "-------- End of object dump ----------" << std::endl;
			 return (os);
		 }

/*****************************************************
  Implementation of class FireTendencyMV type float.
******************************************************/

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >   wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<float, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                             ITS, ITE, KTS, KTE, JTS, JTE>::FireTendencyMV() :

		       m_fRthFrTen{ boost::extents[IME][KME][JME] },
			   m_fRqvFrTen{ boost::extents[IME][KME][JME] } {

						/* Assume unaligned access
						 Should not be penalty for that.*/
						for (WRF_ULONGLONG j{ JMS }; j != JME; ++j) {
							for (WRF_ULONGLONG k{ KMS }; k != KME; ++k) {
								 for (WRF_ULONGLONG i{ IMS }; i != IME; i += 8) {

									 _mm256_storeu_ps(&this->m_fRthFrTen[i][k][j], _mm256_setzero_ps());
									 _mm256_storeu_ps(&this->m_fRqvFrTen[i][k][j], _mm256_setzero_ps());
								}
							}
						}

		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >  wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<float, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                             ITS, ITE, KTS, KTE, JTS, JTE>::FireTendencyMV(_In_ const FireTendencyMV &rhs) :

		      m_fRthFrTen{ rhs.m_fRthFrTen },
		      m_fRqvFrTen{ rhs.m_fRqvFrTen } { 

		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >   wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<float, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                              ITS, ITE, KTS, KTE, JTS, JTE>::FireTendencyMV(_In_ FireTendencyMV &&rhs) :

		       m_fRthFrTen{ std::move(rhs.m_fRthFrTen) },
		       m_fRqvFrTen{ std::move(rhs.m_fRqvFrTen) } {

		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >  auto    wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<float, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                     ITS, ITE, KTS, KTE, JTS, JTE>::operator=(_In_ const FireTendencyMV &rhs)->FireTendencyMV & {
					if (this == &rhs) return (*this);
						FireTendencyMV temp{ rhs };
						std::swap(*this, temp);
					return (*this);
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >   auto   wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<float, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                     ITS, ITE, KTS, KTE, JTS, JTE>::operator=(_In_ FireTendencyMV &&rhs)->FireTendencyMV & {
					if (this == &rhs) return (*this);
						*this = std::move(rhs);
					return (*this);
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >   auto    wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<float, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                     ITS, ITE, KTS, KTE, JTS, JTE>::operator()(_In_ const WRF_ULONGLONG I,
											                                           _In_ const WRF_ULONGLONG K,
																					   _In_ const WRF_ULONGLONG J)const->const std::pair<float, float> {

	using namespace wrf_physics::utils_exceptions;
	if ((J > JME) || (K > KME) || (I > IME))
		throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
	return(std::make_pair(this->m_fRthFrTen[I][K][J], this->m_fRqvFrTen[I][K][J]));
}
		 
template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >  auto    wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<float, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                    ITS, ITE, KTS, KTE, JTS, JTE>::getRthFrTen()const->WRF_Mat3DF32 const & {
			   return (this->m_fRthFrTen);
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >  auto    wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<float, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                    ITS, ITE, KTS, KTE, JTS, JTE>::getRqvFrTen()const->WRF_Mat3DF32 const & {
			    return (this->m_fRqvFrTen);
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >   auto    wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<float, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                     ITS, ITE, KTS, KTE, JTS, JTE>::nth_elem_rth(_In_ const WRF_ULONGLONG I,
		                                                                                 _In_ const WRF_ULONGLONG K,
		                                                                                 _In_ const WRF_ULONGLONG J)const->const float {
					 using namespace wrf_physics::utils_exceptions;
					 if ((J > JME) || (K > KME) || (I > IME))
						throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
					 return (this->m_fRthFrTen[I][K][J]);
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE  >   auto   wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<float, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                     ITS, ITE, KTS, KTE, JTS, JTE>::nth_elem_rqv(_In_ const WRF_ULONGLONG I,
		                                                                                 _In_ const WRF_ULONGLONG K,
		                                                                                 _In_ const WRF_ULONGLONG J)const->const float {
				using namespace wrf_physics::utils_exceptions;
				if ((J > JME) || (K > KME) || (I > IME))
				   throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), I, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
				return (this->m_fRqvFrTen[I][K][J]);
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG KDS,
	     const WRF_ULONGLONG KDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG KMS,
	     const WRF_ULONGLONG KME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME,
	     const WRF_ULONGLONG ITS,
	     const WRF_ULONGLONG ITE,
	     const WRF_ULONGLONG KTS,
	     const WRF_ULONGLONG KTE,
	     const WRF_ULONGLONG JTS,
		 const WRF_ULONGLONG JTE >  auto  wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<float, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
		                                   ITS, ITE, KTS, KTE, JTS, JTE>::fire_tendency(_In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<float, IMS, IME, JMS, JME> &grnhfx,
		                                                                                _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<float, IMS, IME, JMS, JME> &grnqfx,
		                                                                                _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<float, IMS, IME, JMS, JME> &canhfx,
		                                                                                _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<float, IMS, IME, JMS, JME> &canqfx,
		                                                                                _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<float, IMS, IME, JMS, JME> &zs,
		                                                                                _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<float, IMS, IME, JMS, JME> &mu,
		                                                                                _In_ const WRF_Mat3DF32 &z_at_w,
		                                                                                _In_ const WRF_Mat3DF32 &dz8w,
		                                                                                _In_ const WRF_Mat3DF32 &rho,
		                                                                                _In_ const float alfg,
		                                                                                _In_ const float alfc,
		                                                                                _In_ const float z1can)->FireTendencyMV & {
               
						/* Local variables:  */
					 WRF_ULONGLONG i_st, i_en, j_st, j_en, k_st, k_en;
					 const  __m256 cp_i(_mm256_set1_ps(9.9542106310969540115468E-4));
					 const  __m256 xlv_i(_mm256_set1_ps(0.0000004));
					 __m256  v_alfg(_mm256_set1_ps(-alfg));
					 __m256  v_alfc(_mm256_set1_ps(-alfc));
					 __m256  v_z1can(_mm256_set1_ps(z1can));
					 __m256  rho_i(_mm256_setzero_ps());
					 __m256  fact_g(_mm256_setzero_ps());
					 __m256  fact_c(_mm256_setzero_ps());
					 __m256  z_w(_mm256_setzero_ps());
					 __m256  alfg_i(_mm256_rcp_ps(v_alfg));
					 __m256  alfc_i(_mm256_rcp_ps(v_alfc));
					 WRF_Mat3DF32  hfx{ boost::extents[IME][KME][JME] };
					 WRF_Mat3DF32  qfx{ boost::extents[IME][KME][JME] };

					 /* Indices must be set either -/+ 1 above or below modulo(n) == 0*/
					 i_st = std::max(ITS, IDS + 1);
					 i_en = std::min(ITE, IDE - 1);
					 k_st = KTS;
					 k_en = std::min(KTE, KDE - 1);
					 j_st = std::max(JTS, JDS + 1);
					 j_en = std::min(JTE, JDE - 1);

					 for (WRF_ULONGLONG j{ j_st }; j != j_en; ++j) {
						 for (WRF_ULONGLONG k{ k_st }; k != k_en; ++k) {
							 for (WRF_ULONGLONG i{ i_st }; i != i_en; i += 8) {

								 /* Prefetch to L1D */
								 _mm_prefetch(reinterpret_cast<const char*>(&z_at_w[i][k][j]), _MM_HINT_T0);
								 _mm_prefetch(reinterpret_cast<const char*>(&zs.getTerrainMap()[i][j]), _MM_HINT_T0);

								 /* Set z_w in meters above the ground */
								 z_w = _mm256_sub_ps(_mm256_loadu_ps(&z_at_w[i][k][j]), _mm256_loadu_ps(&zs.getTerrainMap()[i][j]));

								 /* Heat flux. */
								 /* pre-computed constants */
								 const __m256 expalfg_zw(_mm256_exp_ps(_mm256_mul_ps(v_alfg, z_w)));
								 const __m256 expalfczw_z1can(_mm256_exp_ps(_mm256_mul_ps(v_alfc, _mm256_sub_ps(z_w, v_z1can))));

								 /* Heat flux */
								 fact_g = _mm256_mul_ps(cp_i, expalfg_zw);
								 const __m256 mask(_mm256_cmp_ps(z_w, v_z1can, _CMP_LT_OS));
								 /* Eliminate conditional branch */
								 fact_c = _mm256_blendv_ps(cp_i, _mm256_mul_ps(cp_i, expalfczw_z1can), mask);
								 /* Prefetch to L1D */
								 _mm_prefetch(reinterpret_cast<const char*>(&grnhfx.getHeatDensity()[i][j]), _MM_HINT_T0);
								 _mm_prefetch(reinterpret_cast<const char*>(&canhfx[i][j]), _MM_HINT_T0);
								 _mm256_storeu_ps(&hfx[i][k][j], _mm256_add_ps(_mm256_mul_ps(fact_g, _mm256_loadu_ps(&
									 grnhfx.getHeatDensity()[i][j])), _mm256_mul_ps(fact_c, _mm256_loadu_ps(&canhfx.getHeatDensity()[i][j]))));

								 /* Vapour flux */
								 fact_g = _mm256_mul_ps(xlv_i, expalfg_zw);
								 const __m256d mask2(_mm256_cmp_ps(z_w, v_z1can, _CMP_LT_OS));
								 fact_c = _mm256_blendv_ps(xlv_i, _mm256_mul_ps(xlv_i, expalfczw_z1can), mask2);
								 /* Prefetch to L1D */
								 _mm_prefetch(reinterpret_cast<const char*>(&grnqfx.getHeatDensity()[i][j]), _MM_HINT_T0);
								 _mm_prefetch(reinterpret_cast<const char*>(&canqfx.getHeatDensity()[i][j]), _MM_HINT_T0);
								 _mm256_storeu_ps(&qfx[i][k][j], _mm256_add_ps(_mm256_mul_ps(fact_g, _mm256_loadu_ps(&
									 grnqfx.getHeatDensity[i][j])), _mm256_mul_ps(fact_c, _mm256_loadu_ps(&canqfx.getHeatDensity()[i][j]))));


								 /* Vapour flux */
								 fact_g = _mm256_mul_ps(xlv_i, expalfg_zw);
								 const __m256 mask2(_mm256_cmp_ps(z_w, v_z1can, _CMP_LT_OS));
								 fact_c = _mm256_blendv_ps(xlv_i, _mm256_mul_ps(xlv_i, expalfczw_z1can), mask2);
								 /* Prefetch to L1D */
								 _mm_prefetch(reinterpret_cast<const char*>(&grnqfx.getHeatDensity()[i][j]), _MM_HINT_T0);
								 _mm_prefetch(reinterpret_cast<const char*>(&canqfx.getHeatDensity()[i][j]), _MM_HINT_T0);
								 _mm256_storeu_ps(&qfx[i][k][j], _mm256_add_ps(_mm256_mul_ps(fact_g, _mm256_loadu_ps(&
									 grnqfx.getHeatDensity[i][j])), _mm256_mul_ps(fact_c, _mm256_loadu_ps(&canqfx.getHeatDensity()[i][j]))));
							 }
						 }
					 }

					 /* Add flux divergence to tendencies.
					 Multiply by dry air mass(mu) in order
					 to eliminate call to func. calculate_phy_tend*/
					 for (WRF_ULONGLONG j{ j_st }; j != j_en; ++j) {
						 for (WRF_ULONGLONG k{ k_st }; k != k_en - 1; ++k) {
							 for (WRF_ULONGLONG i{ i_st }; i != i_en - 8; i += 8) {
								 /* Prefetch to L1D */
								 _mm_prefetch(reinterpret_cast<const char*>(&rho[i + 4][k][j]), _MM_HINT_T0);
								 rho_i = _mm256_rcp_ps(_mm256_loadu_pd(&rho[i][k][j]));

								 /* Compute temporaries */
								 _mm_prefetch(reinterpret_cast<const char*>(&mu.getAirMass2D()[i + 4][j].value()), _MM_HINT_T0);
								 const __m256 t0(_mm256_mul_ps(_mm256_loadu_ps(&mu.getAirMass2D()[i][j].value()), rho_i));
								 // _mm_prefetch(reinterpret_cast<const char*>(&hfx[i + 4][k + 1][j]), _MM_HINT_T0);

								 const __m256 t1(_mm256_sub_ps(_mm256_loadu_ps(&hfx[i][k + 1][j]), _mm256_loadu_ps(&hfx[i][k][j])));
								 const __m256 t2(_mm256_sub_ps(_mm256_loadu_ps(&qfx[i][k + 1][j]), _mm256_loadu_ps(&qfx[i][k][j])));

								 _mm_prefetch(reinterpret_cast<const char*>(&dz8w[i + 4][k][j]), _MM_HINT_T0);
								 _mm256_storeu_ps(&this->m_dRthFrTen[i][k][j], _mm256_div_ps(_mm256_mul_ps(t0, t1),
									 _mm256_loadu_ps(&dz8w[i][k][j])));
								 _mm256_storeu_ps(&this->m_dRqvFrTen[i][k][j], _mm256_div_ps(_mm256_mul_ps(t0, t2),
									 _mm256_loadu_ps(&dz8w[i][k][j])));
							 }
						 }
					 }

					 return (*this);
		 }
	    

	    