
/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library Module WSM5 -  declaration.

@file Module_mp_wsm5.inl
@author: Bernard Gingold
@version:  1.0.0  08/05/2016
@description: Module_mp_wsm5.h
*/

/**************************************************************
                Class implementation
***************************************************************/

template<const WRF_ULONGLONG its,
	const WRF_ULONGLONG ite,
	const WRF_ULONGLONG kts,
	const WRF_ULONGLONG kte,
	const WRF_ULONGLONG ims,
	const WRF_ULONGLONG ime,
	const WRF_ULONGLONG jms,
	const WRF_ULONGLONG jme > const WRF_ULONGLONG wrf_physics::wrf_models_wsm::wrf_wsm5_impl::
	                          WSM535<WRF_REAL32, boost::multi_array<WRF_REAL32, 1>, its, ite, kts, kte, ims, ime, jms, jme>
	                                                                                                      ::nChunks = 2Ui64;

template<const WRF_ULONGLONG its,
	     const WRF_ULONGLONG ite,
	     const WRF_ULONGLONG kts,
	     const WRF_ULONGLONG kte,
	     const WRF_ULONGLONG ims,
	     const WRF_ULONGLONG ime,
	     const WRF_ULONGLONG jms,
		 const WRF_ULONGLONG jme >  wrf_physics::wrf_models_wsm::
		                                wrf_wsm5_impl::WSM535<WRF_REAL32, 
		                                      boost::multi_array<WRF_REAL32, 1>, its, ite, kts, kte, ims, ime, jms, jme>
		                                                                          ::WSM535(_In_ const WRF_Mat2DF32 &t,
		                                                                           _In_ const WRF_Mat3DF32 &qci,
		                                                                           _In_ const WRF_Mat3DF32 &qrs,
		                                                                           _In_ const WRF_Mat2DF32 &q,
		                                                                           _In_ const WRF_Mat1DF32 &rain,
		                                                                           _In_ const WRF_Mat1DF32 &rainncv,
#if FORTRAN_OPTIONAL == 1
		                                                                           _In_ const WRF_Mat2DF32 &snow,
		                                                                           _In_ const WRF_Mat2DF32 &snowncv,
#endif
		                                                                           _In_ const WRF_Mat1DF32 &sr          ) :

		 m_t{ boost::extents[ite][ike] },
		 m_qci{ boost::extents[2][ite][ike] },
		 m_qrs{ boost::extents[2][ite][ike] },
		 m_q{ boost::extents[ime][jme] },
		 m_rain{ bost::extents[ime] },
		 m_rainncv{ boost::extents[ime] },
#if FORTRAN_OPTIONAL == 1
		 m_snow{boost::extents[ime][jme]},
		 m_snowncv{ boost::extents[ime][jme] },
#endif
		 m_sr{ boost::extents[ime]  },
		 m_rslope{ boost::extents[2][ite][kte] },
		 m_rslopeb{ boost::extents[2][ite][kte] },
		 m_rslope2{ boost::extents[2][ite][kte] },
		 m_rslope3{ boost::extents[2][ite][kte] },
		 m_vt{ boost::extents[2][ite][kte] },
		 m_den{ boost::extents[ite][kte] },
		 m_denfac{ boost::extents[ite][kte] } {


										/* Copy arguments arrays 3D and initialize
										   member arrays 3D. Assume Mod(kte,8) == 0
										   Unaligned load/store is used. */
										//constexpr WRF_ULONGLONG nChunks{ 2Ui64 };

										for (WRF_ULONGLONG j{ 0 }; j != nChunks; ++j) {
											for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
#ifdef LOOP_UNROLL_2X
												for (WRF_ULONGLONG k{ kts }; k != kte - 16; k += 16) {
													_mm256_storeu_ps(&m_qci[j][i][k], _mm256_loadu_ps(&qci[j][i][k]));
													_mm256_storeu_ps(&m_qci[j][i][k + 8], _mm256_loadu_ps(&qci[j][i][k + 8]));
													_mm256_storeu_ps(&m_qrs[j][i][k], _mm256_loadu_ps(&qrs[j][i][k]));
													_mm256_storeu_ps(&m_qrs[j][i][k + 8], _mm256_loadu_ps(&qrs[j][i][k + 8]));
													_mm256_storeu_ps(&m_rslope[j][i][k], _mm256_setzero_ps());
													_mm256_storeu_ps(&m_rslope[j][i][k + 8], _mm256_setzero_ps());
													_mm256_storeu_ps(&m_rslopeb[j][i][k], _mm256_setzero_ps());
													_mm256_storeu_ps(&m_rslopeb[j][i][k + 8], _mm256_setzero_ps());
													_mm256_storeu_ps(&m_rslope2[j][i][k], _mm256_setzero_ps());
													_mm256_storeu_ps(&m_rslope2[j][i][k + 8], _mm256_setzero_ps());
													_mm256_storeu_ps(&m_rslope3[j][i][k], _mm256_setzero_ps());
													_mm256_storeu_ps(&m_rslope3[j][i][k + 8], _mm256_setzero_ps());
												}
#else
												for(WRF_ULONGLONG k{kts}; k != kte - 8; k += 8) {
													_mm256_storeu_ps(&m_qci[j][i][k], _mm256_loadu_ps(&qci[j][i][k]));
													_mm256_storeu_ps(&m_qrs[j][i][k], _mm256_loadu_ps(&qrs[j][i][k]));
													_mm256_storeu_ps(&m_rslope[j][i][k], _mm256_setzero_ps());
													_mm256_storeu_ps(&m_rslopeb[j][i][k], _mm256_setzero_ps());
													_mm256_storeu_ps(&m_rslope2[j][i][k], _mm256_setzero_ps());
													_mm256_storeu_ps(&m_rslope3[j][i][k], _mm256_setzero_ps());

												}
#endif													

											}

										}

										/* Copy argument arrays 2D and initialize
										 member arrays 2D. Assume Mod(kte,8) == 0.
										 Arrays load/store operations are
										 unaligned on 32-byte boundary by default.*/
										for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
#ifdef LOOP_UNROLL_2X
											for (WRF_ULONGLONG k{ kts }; k != kte - 16; k += 16) {
												_mm256_storeu_ps(&m_t[i][k], _mm256_loadu_ps(&t[i][k]));
												_mm256_storeu_ps(&m_t[i][k + 8], _mm256_loadu_ps(&t[i][k + 8]));
												_mm256_storeu_ps(&m_den[i][k], _mm256_setzero_ps());
												_mm256_storeu_ps(&m_den[i][k + 8], _mm256_setzero_ps());
												_mm256_storeu_ps(&m_denfac[i][k], _mm256_setzero_ps());
												_mm256_storeu_ps(&m_denfac[i][k + 8], _mm256_setzero_ps());
											}
#else
											for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
												_mm256_storeu_ps(&m_t[i][k], _mm256_loadu_ps(&t[i][k]));
												_mm256_storeu_ps(&m_den[i][k], _mm256_setzero_ps());
												_mm256_storeu_ps(&m_denfac[i][k], _mm256_setzero_ps());
											}
#endif												

										}

										/* Initialize member arrays 1D.
										 Assume Mod(kte,8) == 0.
										 Arrays load/store operations are
										 unaligned on 32-byte boundary by default.*/
#ifdef LOOP_UNROLL_2X
										for (WRF_ULONGLONG i{ ims }; i != ime - 16; i += 16) {
											_mm256_storeu_ps(&m_rain[i], _mm256_loadu_ps(&rain[i]));
											_mm256_storeu_ps(&m_rain[i + 8], _mm256_loadu_ps(&rain[i + 8]));
											_mm256_storeu_ps(&m_rainncv[i], _mm256_loadu_ps(&rainncv[i]));
											_mm256_storeu_ps(&m_rainncv[i + 8], _mm256_loadu_ps(&rainncv[i + 8]));
											_mm256_storeu_ps(&m_sr[i], _mm256_loadu_ps(&sr[i]));
											_mm256_storeu_ps(&m_sr[i + 8], _mm256_loadu_ps(&sr[i + 8]));
										}
#else
										for(WRF_ULONGLONG i{ims}; i != ime - 8; i += 8) {
											_mm256_storeu_ps(&m_rain[i], _mm256_loadu_ps(&rain[i]));
											_mm256_storeu_ps(&m_rainncv[i], _mm256_loadu_ps(&rainncv[i]));
											_mm256_storeu_ps(&m_sr[i], _mm256_loadu_ps(&sr[i]));
										}
#endif
										/* Copy argument arrays 2D and initialize
										member arrays 2D. Assume Mod(kte,8) == 0.
										Arrays load/store operations are
										unaligned on 32-byte boundary by default.*/

										for (WRF_ULONGLONG i{ ims }; i != ime; ++i) {
											for (WRF_ULONGLONG j{ jms }; j != jme - 16; j += 16) {
												_mm256_storeu_ps(&m_q[i][j], _mm256_loadu_ps(&q[i][j]));
												_mm256_storeu_ps(&m_q[i][j + 8], _mm256_loadu_ps(&q[i][j + 8]));
#if FORTRAN_OPTIONAL == 1
												_mm256_storeu_ps(&m_snow[i][j], _mm256_loadu_ps(&snow[i][j]));
												_mm256_storeu_ps(&m_snow[i][j + 8], _mm256_loadu_ps(&snow[i][j + 8]));
												_mm256_storeu_ps(&m_snowncv[i][j], _mm256_loadu_ps(&snowncv[i][j]));
												_mm256_storeu_ps(&m_snowncv[i][j + 8], _mm256_loadu_ps(&snowncv[i][j + 8]));
#endif
											}
										}





		 }

		 /**************************************************************
		           Implementation of wsm5init function
		 ***************************************************************/
		 template<const WRF_ULONGLONG its,
			      const WRF_ULONGLONG ite,
			      const WRF_ULONGLONG kts,
			      const WRF_ULONGLONG kte,
			      const WRF_ULONGLONG ims,
			      const WRF_ULONGLONG ime,
			      const WRF_ULONGLONG jms,
				  const WRF_ULONGLONG jme >  auto  wrf_physics::wrf_models_wsm::
				  wrf_wsm5_impl::WSM535<WRF_REAL32, 
				  boost::multi_array<WRF_REAL32, 1>, its, ite, kts, kte, ims, ime, jms, jme>
				                                          ::wsm5init(_In_ const WRF_REAL32 den0,
				                                                     _In_ const WRF_REAL32 denr,
				                                                     _In_ const WRF_REAL32 dens,
				                                                     _In_ const WRF_REAL32 cl,
				                                                     _In_ const WRF_REAL32 cpv,
				                                                     _In_ const bool allowed_to_read)->void {

                             
													   WRF_REAL64 pi;
													   pi = 4.0 * std::atan(1.0);
													   xlv1 = cl - cpv;
													   qc0 = 1.333333333F * pi * denr * f_r0 * f_r0 * f_r0 * f_xncr / den0;
													   qck1 = 1.0192F * f_peaut / std::powf(f_xncr*denr, 0.3333333333F) / f_xmyu *
														      std::powf(den0, 1.333333333333F);
													   pidnc = pi * denr * 0.1666666666666F;
													   bvtr1 = 1.0F + f_bvtr;
													   bvtr2 = 2.5F + 0.5F + f_bvtr;
													   bvtr3 = 3.0F + f_bvtr;
													   bvtr4 = 4.0F + f_bvtr;
													   g1pbr = rgamma(bvtr1);
													   g3pbr = rgamma(bvtr3);
													   g4pbr = rgamma(bvtr4);
													   g5pbro2 = rgamma(bvtr2);
													   pvtr = f_avtr * g4pbr * 0.1666666666666F;
													   eacrr = 1.0F;
													   pacrr = pi * f_n0r * f_avtr * g3pbr * 0.25F * eacrr;
													   precr1 = 2.0F * pi * f_n0r * 0.78F;
													   precr2 = 2.0F * pi * f_n0r * 0.31F * std::powf(f_avtr, 0.5F) * g5pbro2;
													   xmnax = (f_dimax / f_dicon) * (f_dimax / f_dicon);
													   roqimax = 2.08e+22f * std::powf(f_dimax, 8.0F);

													   bvts1 = 1.0F + f_bvts;
													   bvts2 = 2.5F + 0.5F * f_bvts;
													   bvts3 = 3.0F + f_bvts;
													   bvts4 = 4.0 + f_bvts;
													   g1pbs = rgamma(bvts1);
													   g3pbs = rgamma(bvts3);
													   g4pbs = rgamma(bvts4);
													   g5pbso2 = rgamma(bvts2);
													   pvts = f_avts * g4pbs * 0.166666666666F;
													   pacrs = pi * f_n0s * f_avts * g3pbs * 0.25F;
													   precs1 = 4.0F * f_n0s * 0.65F;
													   precs2 = 4.0F * f_n0s * 0.44F * std::powf(f_avts, 0.5F) * g5pbso2;
													   pidn0r = pi * denr * f_n0r;
													   pidn0s = pi * dens * f_n0s;
													   pacrc = pi * f_n0s * f_avts * g3pbs * 0.25F * eacrr;

													   rslopermax = 1.0F / f_lamdarmax;
													   rslopesmax = 1.0F / f_lamdasmax;
													   rsloperbmax = rslopermax * f_bvtr;
													   rslopesbmax = rslopesmax * f_bvts;
													   rsloper2max = rslopermax * rslopermax;
													   rslopes2max = rslopesmax * rslopesmax;
													   rsloper3max = rsloper2max * rslopermax;
													   rslopes3max = rslopes2max * rslopesmax;

													   /* Setting variables for RADAR reflectivity
													      TO DO - Later.*/

													   // call radar_init here
												   }

		 /****************************************************
		   Implementation of wsm52D member function.
		 *****************************************************/
		 template<const WRF_ULONGLONG its,
			      const WRF_ULONGLONG ite,
			      const WRF_ULONGLONG kts,
			      const WRF_ULONGLONG kte,
			      const WRF_ULONGLONG ims,
			      const WRF_ULONGLONG ime,
			      const WRF_ULONGLONG jms,
				  const WRF_ULONGLONG jme  > auto  wrf_physics::wrf_models_wsm::
				  wrf_wsm5_impl::WSM535<WRF_REAL32, 
				  boost::multi_array<WRF_REAL32, 1>, its, ite, kts, kte, ims, ime, jms, jme>
				                                                                                       

				                                                                             ::wsm52D(_In_ const WRF_Mat2DF32 &p,
																							          _In_ const WRF_Mat2DF32 &delz,
																							          _In_ const WRF_REAL32 delt,
																							          _In_ const WRF_REAL32 g,
																							          _In_ const WRF_REAL32 cpd,
																							          _In_ const WRF_REAL32 cpv,
																							          _In_ const WRF_REAL32 t0c,
																							          _In_ const WRF_REAL32 den0,
																							          _In_ const WRF_REAL32 rd,
																							          _In_ const WRF_REAL32 rv,
																							          _In_ const WRF_REAL32 ep1,
																							          _In_ const WRF_REAL32 ep2,
																							          _In_ const WRF_REAL32 qmin,
																							          _In_ const WRF_REAL32 XLS,
																							          _In_ const WRF_REAL32 XLV0,
																							          _In_ const WRF_REAL32 XLF0,
																							          _In_ const WRF_REAL32 cliq,
																							          _In_ const WRF_REAL32 cice,
																							          _In_ const WRF_REAL32 psat,
																							          _In_ const WRF_REAL32 denr,
#if COLLECT_PERF_DATA == 1
                                                                                                      _Inout_ wrf_physics::wrf_service::wrf_wsm_perf_collectors::
																									          WSM5_PerfCollector<WRF_ULONGLONG,10> &collectors
#endif
																									  )->void {


							    /*******************************************
												Local variables
								*********************************************/

								
							    using namespace  wrf_physics::wrf_physics_internal::tags;
								 /* Heap allocated automatic arrays.*/

								WRF_Mat3DF32 rh{ boost::extents[nChunks][ite][kte] };
								WRF_Mat3DF32 qs{ boost::extents[nChunks][ite][kte] };
								WRF_Mat3DF32 rslope{ boost::extents[nChunks][ite][kte] };
								WRF_Mat3DF32 rslope2{ boost::extents[nChunks][ite][kte] };
								WRF_Mat3DF32 rslope3{ boost::extents[nChunks][ite][kte] };
								WRF_Mat3DF32 rslopeb{ boost::extents[nChunks][ite][kte] };
								WRF_Mat3DF32 qrs_temp{ boost::extents[nChunks][ite][kte] };
								WRF_Mat3DF32 falk{ boost::extents[nChunks][ite][kte] };
								WRF_Mat3DF32 fall{ boost::extents[nChunks][ite][kte] };
								WRF_Mat3DF32 work1{ boost::extents[nChunks][ite][kte] };

								WRF_Mat2DF32 falkc{ boost::extents[ite][kte] };
								WRF_Mat2DF32 fallc{ boost::extents[ite][kte] };
								WRF_Mat2DF32 xl{ boost::extents[ite][kte] };
								WRF_Mat2DF32 cpm{ boost::extents[ite][kte] };
								WRF_Mat2DF32 denfac{ boost::extents[ite][kte] };
								WRF_Mat2DF32 xni{ boost::extents[ite][kte] };
								WRF_Mat2DF32 denqrs1{ boost::extents[ite][kte] };
								WRF_Mat2DF32 denqrs2{ boost::extents[ite][kte] };
								WRF_Mat2DF32 denqci{ boost::extents[ite][kte] };
								WRF_Mat2DF32 n0sfac{ boost::extents[ite][kte] };
								WRF_Mat2DF32 work2{ boost::extents[ite][kte] };
								WRF_Mat2DF32 workr{ boost::extents[ite][kte] };
								WRF_Mat2DF32 works{ boost::extents[ite][kte] };
								WRF_Mat2DF32 work1c{ boost::extents[ite][kte] };
								WRF_Mat2DF32 work2c{ boost::extents[ite][kte] };
								WRF_Mat2DF32 den_tmp{ boost::extents[ite][kte] };
								WRF_Mat2DF32 delz_tmp{ boost::extents[ite][kte] };

								WRF_Mat1DF32 delqrs1{ boost::extents[ite] };
								WRF_Mat1DF32 delqrs2{ boost::extents[ite] };
								WRF_Mat1DF32 delqi{ boost::extents[ite] };

								WRF_Mat2DF32 pigen{ boost::extents[ite][kte] };
								WRF_Mat2DF32 pidep{ boost::extents[ite][kte] };
								WRF_Mat2DF32 psdep{ boost::extents[ite][kte] };
								WRF_Mat2DF32 praut{ boost::extents[ite][kte] };
								WRF_Mat2DF32 psaut{ boost::extents[ite][kte] };
								WRF_Mat2DF32 prevp{ boost::extents[ite][kte] };
								WRF_Mat2DF32 psevp{ boost::extents[ite][kte] };
								WRF_Mat2DF32 pracw{ boost::extents[ite][kte] };
								WRF_Mat2DF32 psacw{ boost::extents[ite][kte] };
								WRF_Mat2DF32 psaci{ boost::extents[ite][kte] };
								WRF_Mat2DF32 pcond{ boost::extents[ite][kte] };
								WRF_Mat2DF32 psmlt{ boost::extents[ite][kte] };

								WRF_Mat1DF32 mstep{ boost::extents[ite] };
								WRF_Mat1DF32 numdt{ boost::extents[ite] };
								WRF_Mat1DF32 tstepsnow{ boost::extents[ite] };
								WRF_Mat1DF32 rmstep{ boost::extents[ite] };
								WRF_Mat1DF32 flgcld{ boost::extents[ite][kte] }; // flags holder
								wrf_physics::wrf_models_wsm::wrf_wsm_iface::Psacw<float32_t_tag, dyn_container_boost_t_tag, ims, ime, jms, jme> test{};
								
								
								/* Vector float variables */
								WRF_Vec256F32 qdt, holdrr, holdrs, supcol, supcolt, pvt,
									coeres, supsat, dtcld, xmi, eacrs, sadtd,
									vt2i, vt2s, acrfac, qimax, diameter, xni0,
									roqi0, fallsum, fallsum_qsi, xlwork2,
									factor, source, value, xlf, pfrzdtc, supice,
									holdc, holdci, temp;

								/* Scalar integral variables*/
								WRF_INT mstepmax, iprt, latd, lond, loop, loops, ifsat, n;
								WRF_ULONGLONG idim, kdim;

								/* Scalar float variables.*/
								float f_dtcld;

								/*Temporary helper variables, default expanded scalars*/
#ifdef EXPAND_SCALARS_TO_VECTOR
								WRF_Vec256F32 dldti, xb, xai, tr, xbi, xa, hvap,
									          cvap, hsub, dldt, ttp, logtr;
#else
								/* Scalar float variables*/
								float f_dtcld, dldti, xb, xai, tr, xbi, xa, hvap,
									cvap, hsub, dldt, ttp, logtr;
#endif
								

								/* Executable code begin: */

								/* Compute lambda functors */
								
								
								auto  CPMCAL = [](WRF_Vec256F32 x)->WRF_Vec256F32 {

									WRF_Vec256F32 t0(_mm256_mul_ps(_mm256_set1_ps(cpd), _mm256_sub_ps(WSM5_CONSTS<float>::ONE,
										_mm256_max_ps(x, _mm256_set1_ps(qmin)))));
									WRF_Vec256F32 t1(_mm256_mul_ps(_mm256_max_ps(x, _mm256_set1_ps(qmin)), _mm256_set1_ps(cpv)));
									 
									WRF_Vec256F32 ret_val(_mm256_add_ps(t0, t1));
									return (ret_val);
									
								};

								auto  XLCAL = [](WRF_Vec256F32 x)->WRF_Vec256F32 {

									WRF_Vec256F32 ret_val(_mm256_mul_ps(_mm256_sub_ps(_mm256_set1_ps(XLV0),
										_mm256_set1_ps(xlv1)), _mm256_sub_ps(x, _mm256_set1_ps(t0c))));
									return (ret_val);
								};

								idim = ite - its;
								kdim = kte - kts;

								/* paddint 0 for negative values generated by dynamics.*/

								for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
									for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {

										_mm256_storeu_ps(&this->m_qci[1][i][k], _mm256_max_ps(_mm256_loadu_ps(&this->m_qci[1][i][k]),
											                                    WSM5_CONSTS<float>::ZERO));
										_mm256_storeu_ps(&this->m_qrs[1][i][k], _mm256_max_ps(_mm256_loadu_ps(&this->m_qrs[1][i][k]),
											                                    WSM5_CONSTS<float>::ZERO));
										_mm256_storeu_ps(&this->m_qci[2][i][k], _mm256_max_ps(_mm256_loadu_ps(&this->m_qci[2][i][k]),
											                                    WSM5_CONSTS<float>::ZERO));
										_mm256_storeu_ps(&this->m_qrs[2][i][k], _mm256_max_ps(_mm256_loadu_ps(&this->m_qrs[2][i][k]),
											                                    WSM5_CONSTS<float>::ZERO));
									}
								}

								/*
								   Latent heat for phase changes and heat capacity.
								   Neglect the changes during microphysics process
								   calculation.
								   Ref:: Emanuel(1994).

								   */
#ifdef DISABLE_HW_PREFETCH
#pragma noprefetch
#endif
								for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
									for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
										_mm_prefetch(reinterpret_cast<const char*>(&this->m_q[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
										_mm_prefetch(reinterpret_cast<const char*>(&this->m_q[i][k+8]), _MM_HINT_T1);
#endif
										_mm256_storeu_ps(&cpm[i][k], CPMCAL(_mm256_loadu_ps(&this->m_q[i][k])));
										_mm_prefetch(reinterpret_cast<const char*>(&this->m_t[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
										_mm_prefetch(reinterpret_cast<const char*>(&this->m_t[i][k + 8]), _MM_HINT_T1);
#endif
										_mm256_storeu_ps(&xl[i][k], XLCAL(_mm256_loadu_ps(&this->m_t[i][k])));
									}
								}

								for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
#ifdef LOOP_UNROLL_2X
									for (WRF_ULONGLONG k{ kts }; k != kte - 16; k += 16) {

										_mm256_storeu_ps(&delz_tmp[i][k], _mm256_loadu_ps(&delz[i][k]));
										_mm256_storeu_ps(&delz_tmp[i][k + 8], _mm256_loadu_ps(&delz[i][k + 8]));
										_mm256_storeu_ps(&den_tmp[i][k], _mm256_loadu_ps(&this->m_den[i][k]));
										_mm256_storeu_ps(&den_tmp[i][k + 8], _mm256_loadu_ps(&this->m_den[i][k + 8]));
									}
#else
									for(WRF_ULONGLONG k{kts}; k != kte; k += 8) {
										_mm256_storeu_ps(&delz_tmp[i][k], _mm256_loadu_ps(&delz[i][k]));
										_mm256_storeu_ps(&den_tmp[i][k], _mm256_loadu_ps(&this->m_den[i][k]));
									}
#endif
								}

								/* Initialize the surface rain, snow.*/

								for (WRF_ULONGLONG i{ its }; i != ite - 8; i += 8) {

									_mm256_storeu_ps(&this->m_rainncv[i], _mm256_setzero_ps());
#if FORTRAN_OPTIONAL == 1
									_mm256_storeu_ps(&this->m_snowncv[lat][i], _mm256_setzero_ps());
#endif
									_mm256_storeu_ps(&this->m_sr[i], _mm256_setzero_ps());
									/* New local array to catch step snow.*/
									_mm256_storeu_ps(&tstepsnow[i], _mm256_setzero_ps());
								}

								/* Compute the minor time-steps */
								
								loops = std::max(std::roundf(delt / f_dtcldcr), 1.F);
								f_dtcld = delt / loops;
								if (delt <= f_dtcldcr) dtcld = delt;

								/* Begining huge outer loop iterative process.*/

								for (loop = 1, loop != loops; ++loop) {

									/* Initialize large scale variables.*/

#ifdef LOOP_UNROLL_2X
									for (WRF_ULONGLONG i{ its }; i != ite - 16; i += 16) {

										_mm256_storeu_ps(&mstep[i], WSM5_CONSTS<float>::ONE);
										_mm256_storeu_ps(&mstep[i + 8], WSM5_CONSTS<float>::ONE);
										_mm256_storeu_ps(&flgcld[i], WSM5_CONSTS<float>::ONE);
										_mm256_storeu_ps(&flgcld[i+8], WSM5_CONSTS<float>::ONE);

									}
#else
									for (WRF_ULONGLONG i{ its }; i != ite - 8; i += 8) {

										_mm256_storeu_ps(&mstep[i], WSM5_CONSTS<float>::ONE);
										_mm256_storeu_ps(&flgcld[i], WSM5_CONSTS<float>::ONE);
									}
#endif
#ifdef DISABLE_HW_PREFETCH
#pragma noprefetch
#endif
									for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
										for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k+8]), _MM_HINT_T1);
#endif
											_mm256_storeu_ps(&this->m_denfac[i][k], _mm256_sqrt_ps(_mm256_mul_ps(_mm256_set1_ps(den0),
												                                    _mm256_rcp_ps(_mm256_loadu_ps(&this->m_den[i][k])))));
										}
									}


									hsub = _mm256_set1_ps(XLS);
									hvap = _mm256_set1_ps(XLV0);
									cvap = _mm256_set1_ps(cpv);
									ttp = _mm256_add_ps(_mm256_set1_ps(t0c), _mm256_set1_ps(WSM5_CONSTS<float>::f_1over100));
									dldt = _mm256_sub_ps(cvap, _mm256_set1_ps(cliq));
									xa = _mm256_div_ps(_mm256_xor_ps(dldt,NEG_MASK), _mm256_set1_ps(rv));
									xb = _mm256_div_ps(_mm256_add_ps(xa,hvap), _mm256_mul_ps(_mm256_set1_ps(rv), ttp));
									dldti = _mm256_sub_ps(cvap, _mm256_set1_ps(cice));
									xai = _mm256_div_ps(_mm256_xor_ps(dldti,NEG_MASK), _mm256_set1_ps(rv));
									xbi = _mm256_div_ps(_mm256_add_ps(xai,hsub), _mm256_mul_ps(_mm256_set1_ps(rv),ttp));

#ifdef DISABLE_HW_PREFETCH
#pragma noprefetch
#endif
#if COLLECT_PERF_DATA == 1
									
									collectors.m_collector_pair1.first.operator[](loop) = __rdtsc();
									collectors.m_record.m_loop_loc = __LINE__;
									collectors.m_record.m_collector_name = "collector_pair1";
#endif
									for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
										for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_t[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_t[i][k+8]), _MM_HINT_T1);
#endif
											WRF_Vec256F32 v_tr(_mm256_mul_ps(ttp, _mm256_rcp_ps(
												                            _mm256_loadu_ps(&this->m_t[i][k]))));
											logtr = _mm256_log_ps(tr);
											WRF_Vec256F32 qs_term1(_mm256_add_ps(_mm256_mul_ps(logtr, xa), _mm256_mul_ps(
												                        xb, _mm256_sub_ps(WSM5_CONSTS<float>::ONE, tr))));
											_mm256_storeu_ps(&qs[1][i][k], _mm256_mul_ps(_mm256_set1_ps(psat),
												                           _mm256_exp_ps(qs_term1)));
											_mm_prefetch(reinterpret_cast<const char*>(&p[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
											_mm_prefetch(reinterpret_cast<const char*>(&p[i][k+8]), _MM_HINT_T1);
#endif
											_mm256_storeu_ps(&qs[1][i][k], _mm256_min_ps(_mm256_loadu_ps(&qs[1][i][k]),
												_mm256_mul_ps(WSM5_CONSTS<float>::v_0_99c, _mm256_loadu_ps(&p[i][k]))));
											_mm256_storeu_ps(&qs[1][i][k], _mm256_div_ps(_mm256_mul_ps(_mm256_set1_ps(ep2),
												_mm256_loadu_ps(&qs[1][i][k])), _mm256_sub_ps(_mm256_loadu_ps(&p[i][k]),
												_mm256_loadu_ps(&qs[1][i][k]))));
											_mm256_storeu_ps(&qs[1][i][k], _mm256_max_ps(_mm256_loadu_ps(&qs[1][i][k]),
												                           _mm256_set1_ps(qmin)));
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_q[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_q[i][k+8]), _MM_HINT_T1);
#endif
											_mm256_storeu_ps(&rh[1][i][k], _mm256_max_ps(_mm256_div_ps(_mm256_loadu_ps(
												&this->m_q[i][k]), _mm256_loadu_ps(&qs[1][i][k])), _mm256_set1_ps(qmin)));

											/* Branchless conditional*/
											WRF_Vec256F32 mask1(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_t[i][k]), ttp, _CMP_LT_OQ));
											WRF_Vec256F32 qs_term2(_mm256_add_ps(_mm256_mul_ps(logtr, xai), _mm256_mul_ps(
												xbi, _mm256_sub_ps(WSM5_CONSTS<float>::ONE, tr))));
											_mm256_storeu_ps(&qs[2][i][k], _mm256_blendv_ps(qs_term2, qs_term1, mask1));
											_mm256_storeu_ps(&qs[2][i][k], _mm256_min_ps(_mm256_loadu_ps(&qs[2][i][k]),
												_mm256_mul_ps(WSM5_CONSTS<float>::v_0_99c, _mm256_loadu_ps(&p[i][k]))));
											_mm256_storeu_ps(&qs[2][i][k], _mm256_div_ps(_mm256_mul_ps(_mm256_set1_ps(ep2),
												_mm256_loadu_ps(&qs[2][i][k])), _mm256_sub_ps(_mm256_loadu_ps(&p[i][k]),
												_mm256_loadu_ps(&qs[2][i][k]))));
											_mm256_storeu_ps(&qs[2][i][k], _mm256_max_ps(_mm256_loadu_ps(&qs[2][i][k]),
												_mm256_set1_ps(qmin)));
											_mm256_storeu_ps(&rh[2][i][k], _mm256_max_ps(_mm256_div_ps(_mm256_loadu_ps(
												&this->m_q[i][k]), _mm256_loadu_ps(&qs[2][i][k])), _mm256_set1_ps(qmin)));

										}
									}
#if COLLECT_PERF_DATA == 1
									collectors.m_collector_pair1.second.operator[](loop) = collectors.m_func_ptr.operator->();
#endif
									/* Initialize varaibles for microphysical physics*/

									for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
										for (WRF_ULONGLONG k{ kts }; k != kte - 16; k += 16) {

											_mm256_storeu_ps(&prevp[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&prevp[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&psdep[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&psdep[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(praut[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&praut[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&psaut[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&psaut[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&pracw[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&pracw[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&psacw[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&psacw[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&pigen[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&pigen[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&pidep[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&pidep[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&pcond[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&pcond[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&psmlt[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&psmlt[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&psevp[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&psevp[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&falk[1][i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&falk[1][i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&falk[2][i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&falk[2][i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&fall[1][i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&fall[1][i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&fall[2][i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&fall[2][i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&fallc[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&fallc[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&falkc[i][k], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&falkc[i][k + 8], WSM5_CONSTS<float>::ZERO);
											_mm256_storeu_ps(&xni[i][k], WSM5_CONSTS<float>::THOUSAND);
											_mm256_storeu_ps(&xni[i][k + 8], WSM5_CONSTS<float>::THOUSAND);
										}
									}

									/*******************************************
										Ni:   ice crystal number concentration
										*******************************************/
#ifdef DISABLE_HW_PREFETCH
#pragma noprefetch
#endif
									for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
										for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k + 2]), _MM_HINT_T0);
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_qci[2][i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k + 8]), _MM_HINT_T1);
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_qci[2][i][k + 8]), _MM_HINT_T1);
#endif
											temp = _mm256_mul_ps(_mm256_loadu_ps(&this->m_den[i][k]), _mm256_max_ps(_mm256_loadu_ps(
												                                       &this->m_qci[2][i][k]), _mm256_set1_ps(qmin)));
											temp = _mm256_sqrt_ps(_mm256_sqrt_ps(_mm256_pow_ps(temp, _mm256_set1_ps(3.0F))));
											_mm256_storeu_ps(&xni[i][k], _mm256_min_ps(_mm256_max_ps(_mm256_mul_ps(
												WSM5_CONSTS<float>::v_5_38_e7c, temp), WSM5_CONSTS<float>::THOUSAND),
												WSM5_CONSTS<float>::MILLION));

												
										}
									}

									/****************************************************
									Compute the fallout term:
									first, vertical terminal velocity for minor loops
									*****************************************************/

									for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
										for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
											_mm256_storeu_ps(&qrs_temp[1][i][k], _mm256_loadu_ps(&this->m_qrs[0][i][k]));
											_mm256_storeu_ps(&qrs_temp[2][i][k], _mm256_loadu_ps(&this->m_qrs[1][i][k]));
										}
									}

									// TO DO - Correct slope_wsm5 function
									slope_wsm5();

									/* Small loop no measurement here*/
#ifdef DISABLE_HW_PREFETCH
#pragma noprefetch
#endif
									for (WRF_ULONGLONG i{ ite }; i >= its; --i) {
										for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[0][i][k + 2]), _MM_HINT_T0);
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[1][i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[0][i][k + 8]), _MM_HINT_T1);
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[1][i][k + 8]), _MM_HINT_T1);
#endif
											WRF_Vec256F32 mask1(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_qrs[0][i][k]),
												                             WSM5_CONSTS<float>::ZERO, _CMP_LE_OQ));
											WRF_Vec256F32 mask2(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_qrs[1][i][k]),
												                             WSM5_CONSTS<float>::ZERO, _CMP_LE_OQ));
											_mm256_storeu_ps(&workr[i][k], _mm256_blendv_ps(WSM5_CONSTS<float>::ZERO, _mm256_loadu_ps(
												                           &work1[0][i][k]), mask1));
											_mm256_storeu_ps(&works[i][k], _mm256_blendv_ps(WSM5_CONSTS<float>::ZERO, _mm256_loadu_ps(
												                           &work1[1][i][k]), mask2));
										}
									}

									// TO DO Implement the function below
									// call nislfv_rain_plm 2x

#ifdef DISABLE_HW_PREFETCH
#pragma noprefetch
#endif
									for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
										for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
											_mm_prefetch(reinterpret_cast<const char*>(&denqrs1[i][k + 2]), _MM_HINT_T0);
											_mm_prefetch(reinterpret_cast<const char*>(&denqrs2[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
											_mm_prefetch(reinterpret_cast<const char*>(&denqrs1[i][k + 8]), _MM_HINT_T1);
											_mm_prefetch(reinterpret_cast<const char*>(&denqrs2[i][k + 8]), _MM_HINT_T1);
#endif
											_mm256_storeu_ps(&this->m_qrs[0][i][k], _mm256_max_ps(_mm256_mul_ps(_mm256_loadu_ps(&
												denqrs1[i][k]), _mm256_rcp_ps(_mm256_loadu_ps(&this->m_den[i][k]))), WSM5_CONSTS<float>::ZERO));
											_mm256_storeu_ps(&this->m_qrs[1][i][k], _mm256_max_ps(_mm256_mul_ps(_mm256_loadu_ps(&
												denqrs2[i][k]), _mm256_rcp_ps(_mm256_loadu_ps(&this->m_den[i][k]))), WSM5_CONSTS<float>::ZERO));
											_mm_prefetch(reinterpret_cast<const char*>(&workr[i][k + 2]), _MM_HINT_T0);
											_mm_prefetch(reinterpret_cast<const char*>(&delz[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
											_mm_prefetch(reinterpret_cast<const char*>(&workr[i][k + 8]), _MM_HINT_T1);
											_mm_prefetch(reinterpret_cast<const char*>(&delz[i][k + 8]), _MM_HINT_T1);
#endif
											_mm256_storeu_ps(&fall[0][i][k], _mm256_mul_ps(_mm256_loadu_ps(&denqrs1[i][k]),
												_mm256_mul_ps(_mm256_loadu_ps(&workr[i][k]), _mm256_rcp_ps(_mm256_loadu_ps(&delz[i][k])))));
											_mm256_storeu_ps(&fall[1][i][k], _mm256_mul_ps(_mm256_loadu_ps(&denqrs2[i][k]),
												_mm256_mul_ps(_mm256_loadu_ps(&works[i][k]), _mm256_rcp_ps(_mm256_loadu_ps(&delz[i][k])))))

										}
									}

									// Handy loop invariant 1.0 / dtcld
									WRF_Vec256F32 inv_dtcld(_mm256_rcp_ps(dtcld));
#ifdef DISABLE_HW_PREFETCH
#pragma noprefetch
#endif
									for (WRF_ULONGLONG i{ its }; i != ite - 8; i += 8) {
										_mm_prefetch(reinterpret_cast<const char*>(&delqrs1[i + 2]), _MM_HINT_T0);
										_mm_prefetch(reinterpret_cast<const char*>(&delqrs2[i + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
										_mm_prefetch(reinterpret_cast<const char*>(&delqrs1[i + 8]), _MM_HINT_T1);
										_mm_prefetch(reinterpret_cast<const char*>(&delqrs2[i + 8]), _MM_HINT_T1);
#endif
										_mm256_storeu_ps(&fall[0][0][i], _mm256_mul_ps(_mm256_loadu_ps(&delqrs1[i]),
											_mm256_mul_ps(_mm256_rcp_ps(_mm256_loadu_ps(&delz[i][k])), inv_dtcld)));
										_mm256_storeu_ps(&fall[1][0][i], _mm256_mul_ps(_mm256_loadu_ps(&delqrs2[i]),
											_mm256_mul_ps(_mm256_rcp_ps(_mm256_loadu_ps(&delz[i][k])), inv_dtcld)));

									}

									for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
#ifdef LOOP_UNROLL_2X
										for (WRF_ULONGLONG k{ kts }; k != kte - 16; k += 16) {
											_mm256_storeu_ps(&qrs_temp[0][i][k], _mm256_loadu_ps(&this->m_qrs[0][i][k]));
											_mm256_storeu_ps(&qrs_temp[0][i][k + 8], _mm256_loadu_ps(&this->m_qrs[0][i][k]));
											_mm256_storeu_ps(&qrs_temp[1][i][k], _mm256_loadu_ps(&this->m_qrs[1][i][k]));
											_mm256_storeu_ps(&qrs_temp[1][i][k + 8], _mm256_loadu_ps(&this->m_qrs[1][i][k + 8]));
										}
#else
										for(WRF_ULONGLONG k{kts}; k != kte; k += 8) {
											_mm256_storeu_ps(&qrs_temp[0][i][k], _mm256_loadu_ps(&this->m_qrs[0][i][k]));
											_mm256_storeu_ps(&qrs_temp[1][i][k], _mm256_loadu_ps(&this->m_qrs[1][i][k]));
										}
#endif
									}



									slope_wsm5();

									/* Big computtional loop*/

#ifdef DISABLE_HW_PREFETCH
#pragma noprefetch
#endif
									for (WRF_ULONGLONG i{ ite }; i >= its; --i) {
										for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_t[i][k + 2]), _MM_HINT_T0);
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[1][i][k]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_t[i][k+8]), _MM_HINT_T1);
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[1][i][k+8]), _MM_HINT_T1);
#endif
											supcol = _mm256_sub_ps(_mm256_set1_ps(t0c), _mm256_loadu_ps(&this->m_t[i][k]));
											_mm256_storeu_ps(&n0sfac[i][k], _mm256_max_ps(_mm256_min_ps(_mm256_exp_ps(
												_mm256_mul_ps(alpha_vf, supcol)), _mm256_div_ps(n0smax_vf, n0s_vf)), WSM5_CONSTS<float>::ONE));

											WRF_Vec256F32 mask1(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_t[i][k]), _mm256_set1_ps(
												t0c), _CMP_GT_OQ));
											WRF_Vec256F32 mask2(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_qrs[1][i][k]), WSM5_CONSTS<float>::ZERO,
												_CMP_GT_OQ));
											if (!(_mm256_testz_ps(mask1, WSM5_CONSTS<float>::ONE)) && !(_mm256_testz_ps(mask2,
												WSM5_CONSTS<float>::ONE))) {

												xlf = _mm256_set1_ps(XLF0);
												/***************************************************
												 psmelt: melting of snow
												 (T > T0: S > R)
												 ****************************************************/
												_mm_prefetch(reinterpret_cast<const char*>(&this->m_t[i][k + 2]), _MM_HINT_T0);
												_mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k + 2]), _MM_HINT_T0);
												_mm_prefetch(reinterpret_cast<const char*>(&p[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
												_mm_prefetch(reinterpret_cast<const char*>(&this->m_t[i][k + 8]), _MM_HINT_T1);
												_mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k + 8]), _MM_HINT_T1);
												_mm_prefetch(reinterpret_cast<const char*>(&p[i][k + 8]), _MM_HINT_T1);
#endif
												WRF_Vec256F32 log_term1(_mm256_mul_ps(WSM5_CONSTS<float>::v_1_496_e6c, _mm256_mul_ps(
													_mm256_loadu_ps(&this->m_t[i][k]), _mm256_sqrt_ps(_mm256_loadu_ps(&this->m_t[i][k])))));
												WRF_Vec256F32 log_term2(_mm256_mul_ps(_mm256_add_ps(_mm256_loadu_ps(&this->m_t[i][k]),
													WSM5_CONSTS<float>::v_120_0c), _mm256_rcp_ps(_mm256_loadu_ps(&this->m_den[i][k]))));
												WRF_Vec256F32 log_arg1(_mm256_div_ps(log_term1, log_term2));
												WRF_Vec256F32 log_term3(_mm256_mul_ps(WSM5_CONSTS<float>::v_8_794_e5c, _mm256_mul_ps(
													_mm256_exp_ps(_mm256_log_ps(_mm256_mul_ps(_mm256_loadu_ps(&this->m_t[i][k]),
													WSM5_CONSTS<float>::v_1_81c))), _mm256_rcp_ps(_mm256_loadu_ps(&p[i][k])))));
												WRF_Vec256F32 log_arg2(_mm256_div_ps(loag_arg1, log_term3));
												WRF_Vec256F32 exp_arg_nom(_mm256_exp_ps(_mm256_mul_ps(_mm256_log_ps(log_arg2),
													WSM5_CONSTS<float>::v_0_33c)));
												WRF_Vec256F32 sqrt_term1(_mm256_mul_ps(WSM5_CONSTS<float>::v_1_496_e6c, _mm256_mul_ps(
													_mm256_loadu_ps(&this->m_t[i][k]), _mm256_sqrt_ps(_mm256_loadu_ps(&this->m_t[i][k])))));
												WRF_Vec256F32 sqrt_term2(_mm256_mul_ps(_mm256_add_ps(_mm256_loadu_ps(&this->m_t[i][k]),
													WSM5_CONSTS<float>::v_120_0c), _mm256_rcp_ps(_mm256_loadu_ps(&this->m_den[i][k]))));
												WRF_Vec256F32 sqrt_arg(_mm256_sqrt_ps(_mm256_div_ps(sqrt_term1, sqrt_term2)));
												WRF_Vec256F32 denom_term(_mm256_sqrt_ps(_mm256_sqrt_ps(_mm256_mul_ps(_mm256_set1_ps(den0),
													_mm256_rcp_ps(_mm256_loadu_ps(&this->m_den[i][k]))))));
												_mm256_storeu_ps(&work2[i][k], _mm256_mul_ps(_mm256_div_ps(exp_arg_nom, sqrt_arg), denom_term));

												_mm_prefetch(reinterpret_cast<const char*>(&this->m_rslope2[1][i][k + 2]), _MM_HINT_T0);
												_mm_prefetch(reinterpret_cast<const char*>(&this->m_rslope[1][i][k + 2]), _MM_HINT_T0);
												_mm_prefetch(reinterpret_cast<const char*>(&this->m_rslopeb[1][i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
												_mm_prefetch(reinterpret_cast<const char*>(&this->m_rslope2[1][i][k + 8]), _MM_HINT_T1);
												_mm_prefetch(reinterpret_cast<const char*>(&this->m_rslope[1][i][k + 8]), _MM_HINT_T1);
												_mm_prefetch(reinterpret_cast<const char*>(&this->m_rslopeb[1][i][k + 8]), _MM_HINT_T1);
#endif
												coeres = _mm256_mul_ps(_mm256_loadu_ps(&this->m_rslope2[1][i][k]), _mm256_mul_ps(
													_mm256_sqrt_ps(_mm256_loadu_ps(&this->m_rslope[1][i][k])), _mm256_loadu_ps(&this->m_rslopeb[1][i][k])));


												WRF_Vec256F32 psmlt_term1(_mm256_mul_ps(WSM5_CONSTS<float>::v_1_496_e6c, _mm256_mul_ps(
													_mm256_loadu_ps(&this->m_t[i][k]), _mm256_sqrt_ps(_mm256_loadu_ps(&this->m_t[i][k])))));
												WRF_Vec256F32 psmlt_term2(_mm256_mul_ps(_mm256_add_ps(_mm256_loadu_ps(&this->m_t[i][k]),
													WSM5_CONSTS<float>::v_120_0c), _mm256_rcp_ps(_mm256_loadu_ps(&this->m_den[i][k]))));
												WRF_Vec256F32 psmlt_term3(_mm256_mul_ps(WSM5_CONSTS<float>::v_1_414e3c, _mm256_mul_ps(
													_mm256_div_ps(psmlt_term1, psmlt_term2), _mm256_loadu_ps(&this->m_den[i][k]))));
												WRF_Vec256F32 psmlt_term4(_mm256_mul_ps(xlf, _mm256_mul_ps(_mm256_sub_ps(_mm256_set1_ps(t0c),
													_mm256_loadu_ps(&this->m_t[i][k]))), WSM5_CONSTS<float>::HALF_PI));
												WRF_Vec256F32 psmlt_term5(_mm256_mul_ps(_mm256_fmadd_ps(_mm256_set1_ps(precs1),
													_mm256_loadu_ps(&this->m_rslope2[1][i][k]), _mm256_set1_ps(precs2)), _mm256_mul_ps(
													_mm256_loadu_ps(work2[i][k]), coeres)));
												WRF_Vec256F32 psmlt6(_mm256_mul_ps(psmlt_term4, _mm256_mul_ps(psmlt_term5, _mm256_rcp_ps(
													_mm256_loadu_ps(&this->m_den[i][k])))));
												_mm256_storeu_ps(&psmlt[i][k], _mm256_div_ps(psmlt_term3, psmlt_term6));

												_mm_prefetch(reinterpret_cast<const char*>(&mstep[k + 2]), _MM_HINT_T0);
												_mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[1][i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
												_mm_prefetch(reinterpret_cast<const char*>(&mstep[k + 8]), _MM_HINT_T1);
												_mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[1][i][k + 8]), _MM_HINT_T1);
#endif
												WRF_Vec256F32 max_term1(_mm256_mul_ps(_mm256_loadu_ps(&psmlt[i][k]),
													_mm256_mul_ps(dtcld, _mm256_rcp_ps(_mm256_loadu_ps(&mstep[k])))));
												WRF_Vec256F32 neg_qrs(_mm256_xor_ps(_mm256_loadu_ps(&this->m_qrs[1][i][k]),
													WSM5_CONSTS<float>::NEG_MASK));
												WRF_Vec256F32 max_term2(_mm256_mul_ps(neg_qrs, _mm256_rcp_ps(_mm256_loadu_ps(&mstep[k]))));

												_mm256_storeu_ps(&psmlt[i][k], _mm256_min_ps(_mm256_max_ps(max_term1, max_term2),
													WSM5_CONSTS<float>::ZERO));
												_mm256_storeu_ps(&this->m_qrs[1][i][k], _mm256_add_ps(_mm256_loadu_ps(&this->m_qrs[1][i][k]),
													_mm256_loadu_ps(&psmlt[i][k])));
												_mm256_storeu_ps(&this->m_qrs[0][i][k], _mm256_sub_ps(_mm256_loadu_ps(&this->m_qrs[0][i][k]),
													_mm256_loadu_ps(&psmlt[i][k])));

#if AGRESSIVE_MAN_OPTIMIZATION == 1
												// Can be potentially unsafe from mathematical point of view,
												// or from increased precision error (decreased precision)
												// because of call to _mm256_rcp_ps function.
												_mm256_storeu_ps(&this->m_t[i][k], _mm256_add_ps(_mm256_loadu_ps(&this->m_t[i][k]),
													_mm256_mul_ps(xlf, _mm256_mul_ps(_mm256_rcp_ps(_mm256_loadu_ps(&cpm[i][k])),
													_mm256_loadu_ps(&psmlt[i][k])))));
#else
												_mm256_storeu_ps(&this->m_t[i][k], _mm256_div_ps(_mm256_add_ps(_mm256_loadu_ps(this->m_t[i][k]),
													xlf), _mm256_mul_ps(_mm256_loadu_ps(&cpm[i][k]), _mm256_loadu_ps(&psmlt[i][k]))));
#endif

											}
										}

									}

									/******************************************************
									  Vice [ms^-1] : fallout of ice crystal [HDC 5a]
									  *******************************************************/

									for (WRF_ULONGLONG i{ ite }; i >= its; --i) {
										for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_qci[1][i][k+2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_qci[1][i][k+2]), _MM_HINT_T1);
#endif
											WRF_Vec256F32 mask1(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_qci[1][i][k]), WSM5_CONSTS<float>::ZERO,
												_CMP_LE_OQ));
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k+2]), _MM_HINT_T0);
											_mm_prefetch(reinterpret_cast<const char*>(&xni[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k+8]), _MM_HINT_T1);
											_mm_prefetch(reinterpret_cast<const char*>(&xni[i][k + 8]), _MM_HINT_T1);
#endif
											xmi = _mm256_mul_ps(_mm256_loadu_ps(&this->m_den[i][k]), _mm256_mul_ps(_mm256_loadu_ps(
												               &this->m_qci[1][i][k]), _mm256_rcp_ps(_mm256_loadu_ps(&xni[i][k]))));
											diameter = _mm256_max_ps(_mm256_min_ps(_mm256_mul_ps(dicon_vf, _mm256_sqrt_ps(xmi)),
												dimax_vf), WSM5_CONSTS<float>::v_1_0_e25c);

											_mm256_storeu_ps(&work1c[i][k], _mm256_blendv_ps(WSM5_CONSTS<float>::ZERO, _mm256_mul_ps(
												WSM5_CONSTS<float>::v_1_49_e4c, _mm256_exp_ps(_mm256_mul_ps(_mm256_log_ps(diameter),
												WSM5_CONSTS<float>::v_1_31c))), mask1));

										}
									}

									/*********************************************************************
										  Forward  semi-lagrangian scheme, piecewise constant, linear
										  **********************************************************************/

									for (WRF_ULONGLONG i{ ite }; i >= its; --i) {
										for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k + 2]), _MM_HINT_T0);
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_qci[1][i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k + 8]), _MM_HINT_T1);
											_mm_prefetch(reinterpret_cast<const char*>(&this->m_qci[1][i][k + 8]), _MM_HINT_T1);
#endif
											_mm256_storeu_ps(&denqci[i][k], _mm256_mul_ps(_mm256_loadu_ps(&this->m_den[i][k]),
												_mm256_loadu_ps(&this->m_qci[1][i][k])));
										}
									}

									// call here
									// nislfv_rain_plm

									for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
										for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
											_mm256_storeu_ps(&this->m_qci[1][i][k], _mm256_max_ps(_mm256_mul_ps(_mm256_loadu_ps(
												&denqci[i][k]), _mm256_rcp_ps(_mm256_loadu_ps(&this->m_den[i][k])))));
										}
									}

									for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
										
#if AGRESSIVE_MAN_OPTIMIZATION == 1
										_mm256_storeu_ps(&fallc[0][k], _mm256_mul_ps(_mm256_loadu_ps(&delqi[k]), _mm256_mul_ps(
											_mm256_rcp_ps(_mm256_loadu_ps(&delz[0][k])),_mm256_rcp_ps(dtcld))));
#else
										_mm256_storeu_ps(&fallc[0][k], _mm256_div_ps(_mm256_loadu_ps(&delqi[k]), _mm256_div_ps(
											_mm256_loadu_ps(&delz[0][k]), dtcld)));
#endif
									}

									/***************************************************************
									 Rain unit is (mm/sec; kg-2s-1: /1000*delt --> m --> mm for wrf
									 ****************************************************************/

									for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
										_mm_prefetch(reinterpret_cast<const char*>(&fall[0][0][k + 2]), _MM_HINT_T0);
										_mm_prefetch(reinterpret_cast<const char*>(&fall[1][0][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
										_mm_prefetch(reinterpret_cast<const char*>(&fall[0][0][k + 8]), _MM_HINT_T1);
										_mm_prefetch(reinterpret_cast<const char*>(&fall[1][0][k + 8]), _MM_HINT_T1);
#endif
										fallsum = _mm256_add_ps(_mm256_loadu_ps(&fall[0][0][k]), _mm256_add_ps(
											_mm256_loadu_ps(&fall[1][0][k]), _mm256_loadu_ps(&fallc[0][k])));
										fallsum_qsi = _mm256_add_ps(_mm256_loadu_ps(&fall[1][0][k]), 
											                           _mm256_loadu_ps(&fallc[0][k]));
										WRF_Vec256F32 mask1(_mm256_cmp_ps(fallsum, WSM5_CONSTS<float>::ZERO, _CMP_GT_OQ));
										if (!(_mm256_testz_ps(mask1, WSM5_CONSTS<float>::ONE))) {

											WRF_Vec256F32 rainnv_term1(_mm256_mul_ps(fallsum, _mm256_loadu_ps(&delz[0][k])));
											WRF_Vec256F32 rainnv_term2(_mm256_mul_ps(_mm256_set1_ps(denr), _mm256_mul_ps(dtcld,
												WSM5_CONSTS<float>::THOUSAND)));
											_mm256_storeu_ps(&this->m_rainncv[k], _mm256_add_ps(_mm256_div_ps(rainnv_term1, rainnv_term2),
												_mm256_loadu_ps(&this->m_rainncv[k])));
											_mm256_storeu_ps(&this->m_rain[k], _mm256_add_ps(_mm256_div_ps(rainnv_term1, rainnv_term2),
												_mm256_loadu_ps(&this->m_rain[k])));
										}

										WRF_Vec256F32 mask2(_mm256_cmp_ps(fallsum_qsi, WSM5_CONSTS<float>::ZERO, _CMP_GT_OQ));



									}


								} // Big outer loop
								

				  }

		 /****************************************************
		   Implementation of slope_wsm5 member function.
		 *****************************************************/
		 template<const WRF_ULONGLONG its,
			      const WRF_ULONGLONG ite,
			      const WRF_ULONGLONG kts,
			      const WRF_ULONGLONG kte,
			      const WRF_ULONGLONG ims,
			      const WRF_ULONGLONG ime,
			      const WRF_ULONGLONG jms,
				  const WRF_ULONGLONG jme >  auto  wrf_physics::wrf_models_wsm::
				  wrf_wsm5_impl::WSM535<WRF_REAL32, 
				  boost::multi_array<WRF_REAL32, 1>, its, ite, kts, kte, ims, ime, jms, jme>
				                                                                             ::slope_wsm5()->void {
                         
								/* Lambda functors */
							 auto  lamdar = [](_In_ WRF_Vec256F32 x,
											   _In_ WRF_Vec256F32 y)->WRF_Vec256F32 {

								 WRF_Vec256F32 ret_val(_mm256_sqrt_ps(_mm256_sqrt_ps(_mm256_div_ps(
									 _mm256_set1_ps(pidn0r), _mm256_mul_ps(x, y)))));
								 return (ret_val);
							 };
							 auto  lamdas = [](_In_ WRF_Vec256F32 x,
								               _In_ WRF_Vec256F32 y,
								               _In_ WRF_Vec256F32 z)->WRF_Vec256F32 {

								 WRF_Vec256F32 ret_val(_mm256_sqrt_ps(_mm256_sqrt_ps(_mm256_div_ps(
									 _mm256_mul_ps(_mm256_set1_ps(pidn0s), z), _mm256_mul_ps(x, y)))));
								 return (ret_val);
							 };

							 /* Local variables */
							 const WRF_Vec256F32 t0c(_mm256_set1_ps(273.15F));
							 const WRF_Vec256F32 ONE(_mm256_set1_ps(1.0F));
							 const WRF_Vec256F32 ZERO(_mm256_setzero_ps());
							 WRF_Vec256F32 supcol;
							 WRF_Mat2DF32 n0sfac{ boost::extents[ite][kte] };

							 /* Executable code: */

							 for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
								 for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_t[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_t[i][k + 8]), _MM_HINT_T1);
#endif
									 supcol = _mm256_sub_ps(t0c, _mm256_loadu_ps(&this->m_t[i][k]));
									 _mm256_storeu_ps(&n0sfac[i][k], _mm256_max_ps(_mm256_min_ps(_mm256_exp_ps(
										  _mm256_mul_ps(alpha_vf, supcol)), _mm256_div_ps(n0smax_vf, n0s_vf)), ONE));

									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[1][i][k+2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[1][i][k+8]), _MM_HINT_T1);
#endif
									 WRF_Vec256F32 mask1(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_qrs[1][i][k]),
										                  qcrmin_vf, _CMP_LE_OS));

									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k+2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k+8]), _MM_HINT_T1);
#endif
									 WRF_Vec256F32 lamdar_inv(_mm256_rcp_ps(lamdar(_mm256_loadu_ps(&this->m_qrs[1][i][k]),
										                                           _mm256_loadu_ps(&this->m_den[i][k]))));
									 _mm256_storeu_ps(&this->m_rslope[1][i][k], _mm256_blendv_ps(_mm256_set1_ps(rslopermax),
										                                            lamdar_inv, mask1));
									 _mm256_storeu_ps(&this->m_rslopeb[1][i][k], _mm256_blendv_ps(_mm256_set1_ps(rsloperbmax),
										 _mm256_exp_ps(_mm256_mul_ps(_mm256_log_ps(_mm256_loadu_ps(&this->m_rslope[1][i][k])), bvtr_vf))));
									 _mm256_storeu_ps(&this->m_rslope2[1][i][k], _mm256_blendv_ps(_mm256_set1_ps(rsloper2max),
										 _mm256_mul_ps(_mm256_loadu_ps(&this->m_rslope[1][i][k]), _mm256_loadu_ps(&this->m_rslope[1][i][k]))));
									 _mm256_storeu_ps(&this->m_rslope3[1][i][k], _mm256_belndv_ps(_mm256_set1_ps(rsloper3max),
										 _mm256_mul_ps(_mm256_loadu_ps(&this->m_rslope2[1][i][k]), _mm256_loadu_ps(&this->m_rslope[1][i][k]))));

									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[2][i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[2][i][k + 8]), _MM_HINT_T1);
#endif
									 WRF_Vec256F32 mask2(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_qrs[2][i][k]), 
										                 qcrmin_vf, _CMP_LE_OS));
									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k + 2]), _MM_HINT_T0);
									 _mm_prefetch(reinterpret_cast<const char*>(&n0sfac[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k + 8]), _MM_HINT_T1);
									 _mm_prefetch(reinterpret_cast<const char*>(&n0sfac[i][k + 8]), _MM_HINT_T1);
#endif
									 WRF_Vec256F32 lamdas_inv(_mm256_rcp_ps(lamdas(_mm256_loadu_ps(&this->m_qrs[2][i][k]),
										 _mm256_loadu_ps(&this->m_den[i][k]), _mm256_loadu_ps(&n0sfac[i][k]))));
									 _mm256_storeu_ps(&this->m_rslope[2][i][k], _mm256_blendv_ps(_mm256_set1_ps(rslopesmax),
										                                        lamdas_inv, mask2));
									 _mm256_storeu_ps(&this->m_rslopeb[2][i][k], _mm256_blendv_ps(_mm256_set1_ps(rslopesbmax),
										 _mm256_exp_ps(_mm256_mul_ps(_mm256_log_ps(_mm256_loadu_ps(&this->m_rslope[2][i][k])), bvts_vf))));
									 _mm256_storeu_ps(&this->m_rslope2[2][i][k], _mm256_blendv_ps(_mm256_set1_ps(rslopes2max),
										 _mm256_mul_ps(_mm256_loadu_ps(&this->m_rslope[2][i][k]), _mm256_loadu_ps(&this->m_rslope[2][i][k]))));
									 _mm256_storeu_ps(&this->m_rslope3[2][i][k], _mm256_blendv_ps(_mm256_set1_ps(rslopes3max),
										 _mm256_mul_ps(_mm256_loadu_ps(&this->m_rslope2[2][i][k]), _mm256_loadu_ps(&this->m_rslope[2][i][k]))));

									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[1][i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[1][i][k + 8]), _MM_HINT_T1);
#endif
									 WRF_Vec256F32 mask3(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_qrs[1][i][k]), ZERO, _CMP_LE_OS));
									 WRF_Vec256F32 mask4(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_qrs[2][i][k]), ZERO, _CMP_LE_OS));
									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_denfac[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > MAX_L1_SIZE_FLOAT
									 _mm_prefetch(reinterpret_cast<const char*>(&this->m_denfac[i][k + 8]), _MM_HINT_T1);
#endif
									 _mm256_storeu_ps(&this->m_vt[1][i][k], _mm256_blendv_ps(ZERO, _mm256_mul_ps(_mm256_set1_ps(pvtr),
										 _mm256_mul_ps(_mm256_loadu_ps(&this->m_rslopeb[1][i][k]), _mm256_loadu_ps(&this->m_denfac[i][k])))));
									 _mm256_storeu_ps(&this->m_vt[2][i][k], _mm256_blendv_ps(ZERO, _mm256_mul_ps(_mm256_set1_ps(pvts),
										 _mm256_mul_ps(_mm256_loadu_ps(&this->m_rslopeb[2][i][k]), _mm256_loadu_ps(&this->m_denfac[i][k])))));


								 }
							 }
				  }
		 /****************************************************
		   Implementation of slope_rain member function.
		 *****************************************************/
		 template<const WRF_ULONGLONG its,
			      const WRF_ULONGLONG ite,
			      const WRF_ULONGLONG kts,
			      const WRF_ULONGLONG kte,
			      const WRF_ULONGLONG ims,
			      const WRF_ULONGLONG ime,
			      const WRF_ULONGLONG jms,
				  const WRF_ULONGLONG jme >  auto  wrf_physics::wrf_models_wsm::
				  wrf_wsm5_impl::WSM535<WRF_REAL32, 
				  boost::multi_array<WRF_REAL32, 1>, its, ite, kts, kte, ims, ime, jms, jme>
				                                                                             ::slope_rain()->void {
                           
							/* Lambda functor*/
						 auto lamdar = [](_In_ WRF_Vec256F32 x,
							              _In_ WRF_Vec256F32 y)->WRF_Vec256F32 {
										            
							 WRF_Vec256F32 ret_val(_mm256_sqrt_ps(_mm256_sqrt_ps(_mm256_div_ps(_mm256_set1_ps(pidn0r),
								                   _mm256_mul_ps(x, y)))));
							 return (ret_val);
							            
						 };

						 /* Local variables*/
						 WRF_Vec256F32 supcol;
						 const WRF_Vec256F32 t0c(_mm256_set1_ps(273.15F));
						 const WRF_Vec256F32 ONE(_mm256_set1_ps(1.0F));
						 const WRF_Vec256F32 ZERO(_mm256_setzero_ps());
						
						 WRF_Mat2DF32 n0sfac{ boost::extents[ite][kte] };

						 /* Executable code*/

						 for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
							 for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
								 _mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
								 _mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[i][k+8]),_MM_HINT_T1);
#endif
								 WRF_Vec256F32 mask1(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_qrs[i][k]), qcrmin_vf, _CMP_LE_OS));
								 _mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
								 _mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k+8]),_MM_HINT_T1);
#endif
								 WRF_Vec256F32 lamdar_inv(_mm256_rcp_ps(lamdar(_mm256_loadu_ps(&this->m_qrs[i][k]),
									                      _mm256_loadu_ps(&this->m_den[i][k]))));
								 _mm256_storeu_ps(&this->m_rslope[i][k], _mm256_blendv_ps(_mm256_set1_ps(rslopermax),
									                                     lamdar_inv, mask1));
								 _mm256_storeu_ps(&this->m_rslopeb[i][k], _mm256_blendv_ps(_mm256_set1_ps(rsloperbmax),
									           _mm256_pow_ps(_mm256_loadu_ps(&this->m_rslope[i][k]), bvtr_vf, mask1)));
								 _mm256_storeu_ps(&this->m_rslope2[i][k], _mm256_blendv_ps(_mm256_set1_ps(rsloper2max),
									 _mm256_mul_ps(_mm256_loadu_ps(&this->m_rslope[i][k]), _mm256_loadu_ps(&this->m_rslope[i][k])), mask1));
								 _mm256_storeu_ps(&this->m_rslope3[i][k], _mm256_blendv_ps(_mm256_set1_ps(rsloper3max),
									 _mm256_mul_ps(_mm256_loadu_ps(&this->m_rslope2[i][k]), _mm256_loadu_ps(&this->m_rslope[i][k])), mask1));
								 _mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[i][k + 2]), _MM_HINT_T0);
								 _mm_prefetch(reinterpret_cast<const char*>(&this->m_denfac[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
								 _mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[i][k + 8]), _MM_HINT_T1);
								 _mm_prefetch(reinterpret_cast<const char*>(&this->m_denfac[i][k + 8]), _MM_HINT_T1);
#endif
								 WRF_Vec256F32 mask2(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_qrs[i][k]), ZERO, _CMP_LE_OS));
								 _mm256_storeu_ps(&this->m_vt[i][k], _mm256_blendv_ps(ZERO, _mm256_mul_ps(_mm256_set1_ps(pvtr),
									 _mm256_mul_ps(_mm256_loadu_ps(&this->m_rslopeb[i][k]), _mm256_loadu_ps(&this->m_denfac[i][k]))),mask2));

							 }
						 }
						 

				  }

		 /****************************************************
		     Implementation of slope_snow member function.
		 ****************************************************/
		 template<const WRF_ULONGLONG its,
			      const WRF_ULONGLONG ite,
			      const WRF_ULONGLONG kts,
			      const WRF_ULONGLONG kte,
			      const WRF_ULONGLONG ims,
			      const WRF_ULONGLONG ime,
			      const WRF_ULONGLONG jms,
				  const WRF_ULONGLONG jme > auto  wrf_physics::wrf_models_wsm::
				  wrf_wsm5_impl::WSM535<WRF_REAL32, 
				  boost::multi_array<WRF_REAL32, 1>, its, ite, kts, kte, ims, ime, jms, jme>
				                                                                            ::slope_snow()->void {
                          

																			
						auto lamdas = [](_In_ WRF_Vec256F32 x, 
							             _In_ WRF_Vec256F32 y, 
										 _In_ WRF_Vec256F32 z)->WRF_Vec256F32 {

							           WRF_Vec256F32 ret_val = _mm256_sqrt_ps(_mm256_sqrt_ps(_mm256_div_ps(_mm256_mul_ps(_mm256_set1_ps(pidn0s),
								                              z), _mm256_mul_ps(x, y))));
							          return (ret_val);

						};

						/* Local variables*/
						const WRF_Vec256F32 t0c(_mm256_set1_ps(273.15F));
						WRF_Vec256F32 supcol;
						WRF_Mat2DF32 n0sfac{ boost::extents[ite][kte] };
						const WRF_Vec256F32 ONE(_mm256_set1_ps(1.0F));
						const WRF_Vec256F32 ZERO(_mm256_setzero_ps());

						/* Executable code */
						for (WRF_ULONGLONG i{ its }; i != ite; ++i) {
							for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
								_mm_prefetch(reinterpret_cast<const char*>(&this->m_t[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
								_mm_prefetch(reinterpret_cast<const char*>(&this->m_t[i][k + 8]), _MM_HINT_T1);
#endif
								supcol = _mm256_sub_ps(t0c, _mm256_loadu_ps(&this->m_t[i][k]));
								/*******************************************
								 n0s: Intercept parameter for snow.
								********************************************/
								_mm256_storeu_ps(&n0sfac[i][k], _mm256_max_ps(_mm256_min_ps(_mm256_exp_ps(_mm256_mul_ps(
									                           alpha_vf, supcol)), _mm256_div_ps(n0smax_vf, n0s_vf), ONE)));
								WRF_Vec256F32 mask1(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_qrs[i][k]), qcrmin_vf, _CMP_LE_OS));
								_mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
								_mm_prefetch(reinterpret_cast<const char*>(&this->m_den[i][k + 8]), _MM_HINT_T1);
#endif
								WRF_Vec256F32 rslope_term1(_mm256_rcp_ps(lamdas(_mm256_loadu_ps(&this->m_qrs[i][k]), _mm256_loadu_ps(
									                                          &this->m_den[i][k]), _mm256_loadu_ps(&n0sfac[i][k]))));
								_mm256_storeu_ps(&this->m_rslope[i][k], _mm256_blendv_ps(_mm256_set1_ps(rslopesmax), rslope_term1, mask1));
								_mm256_storeu_ps(&this->m_rslopeb[i][k], _mm256_blendv_ps(_mm256_set1_ps(rslopesbmax), _mm256_mul_ps(
									                                                _mm256_loadu_ps(&this->m_rslope[i][k]), bvts_vf),mask1));
								_mm256_storeu_ps(&this->m_rslope2[i][k], _mm256_blendv_ps(_mm256_set1_ps(rslopes2max), _mm256_mul_ps(
									                 _mm256_loadu_ps(&this->m_rslope[i][k]), _mm256_loadu_ps(&this->m_rslope[i][k])),mask1));
								_mm256_storeu_ps(&this->m_rslope3[i][k], _mm256_blendv_ps(_mm256_set1_ps(rslopes3max), _mm256_mul_ps(
									                 _mm256_loadu_ps(&this->m_rslope2[i][k]), _mm256_loadu_ps(&this->m_rslope[i][k])),mask1));
								_mm_prefetch(reinterpret_cast<const char*>(&this->m_denfac[i][k+2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
								_mm_prefetch(reinterpret_cast<const char*>(&this->m_denfac[i][k+8]), _MM_HINT_T1);
#endif
								
								_mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[i][k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
								_mm_prefetch(reinterpret_cast<const char*>(&this->m_qrs[i][k + 8]), _MM_HINT_T1);
#endif
								WRF_Vec256F32 mask2(_mm256_cmp_ps(_mm256_loadu_ps(&this->m_qrs[i][k]), ZERO, _CMP_LT_OS));
								_mm256_storeu_ps(&this->m_vt[i][k], _mm256_blendv_ps(ZERO, _mm256_mul_ps(_mm256_set1_ps(pvts), _mm256_mul_ps(
									               _mm256_loadu_ps(&this->m_rslopeb[i][k]), _mm256_loadu_ps(&this->m_denfac[i][k]))), mask2));
									                            
							}
						}




				  }

		 /****************************************************
		            Implementation of rgamma function.
		 *****************************************************/
		 auto  wrf_physics::wrf_models_wsm::wrf_wsm5_impl::rgamma(_In_ const WRF_REAL32 x)->const WRF_REAL32{

			 constexpr WRF_REAL32 euler{ 0.57721566490F };
			 constexpr WRF_ULONGLONG nIters{ 10000Ui64 };
			 WRF_REAL32 y;
			 WRF_REAL32 rgmma_val{};

			 if (x == 1.F)
				 return (rgmma_val = 1.0F);
			 else {
				 rgmma_val = x * std::exp(euler*x);
				 for (WRF_ULONGLONG i{ 1 }; i != nIters; ++i) {
					 y = static_cast<float>(i);
					 rgmma_val = rgmma_val * (1.0F + x / y) * std::exp(-x / y);
				 }
				 return (rgmma_val = 1.0F / rgmma_val);
			 }
		 }

		

		 /**********************************************************
		      Implementation of effectRad_wsm5 function.
		 ***********************************************************/
		template<const WRF_ULONGLONG kts,
			     const WRF_ULONGLONG kte>   auto   effectRad_wsm5(_In_ const WRF_REAL32  qmin,
			                                                      _In_ const WRF_REAL32  t0c,
			                                                      _In_ const WRF_Mat1DF32 &t,
			                                                      _In_ const WRF_Mat1DF32 &qc,
			                                                      _In_ const WRF_Mat1DF32 &qi,
			                                                      _In_ const WRF_Mat1DF32 &qs,
			                                                      _In_ const WRF_Mat1DF32 &rho,
			                                                      _Inout_  WRF_Mat1DF32   &re_qc,
			                                                      _Inout_  WRF_Mat1DF32   &re_qi,
			                                                      _Inout_  WRF_Mat1DF32   &re_qs)->void {


					 /* Local variables.*/
					 WRF_INT inu_c;
					 WRF_Mat1DF32 ni{  boost::extents[kte] };
					 WRF_Mat1DF32 rqc{ boost::extents[kte] };
					 WRF_Mat1DF32 rqi{ boost::extents[kte] };
					 WRF_Mat1DF32 rni{ boost::extents[kte] };
					 WRF_Mat1DF32 rqs{ boost::extents[kte] };

					 WRF_Vec256F32 temp(_mm256_setzero_ps());
					 WRF_Vec256F32 lamdac(_mm256_setzero_ps());
					 WRF_Vec256F32 supcol(_mm256_setzero_ps());
					 WRF_Vec256F32 n0sfac(_mm256_setzero_ps());
					 WRF_Vec256F32 lamdas(_mm256_setzero_ps());
					 WRF_Vec256F32 diai(_mm256_setzero_ps());
					 const WRF_Vec256F32 thousand( _mm256_set1_ps(1.0e+3f));
					 const WRF_Vec256F32 milion(_mm256_set1_ps(1.0e+6f));
					 const WRF_Vec256F32 val_53milion(_mm256_set1_ps(5.38e+7F));
					 const WRF_Vec256F32 ZERO(_mm256_setzero_ps());
					 const WRF_Vec256F32 ONE(_mm256_set1_ps(1.0F));
					 
					 bool has_qc = false, has_qi = false, has_qs = false;
					 WRF_Vec256F32 v_has_qc(_mm256_setzero_ps());
					 WRF_Vec256F32 v_has_qi(_mm256_setzero_ps());
					 WRF_Vec256F32 v_has_qs(_mm256_setzero_ps());
					 constexpr WRF_REAL32 R1{ 1.0E-12F };
					 constexpr WRF_REAL32 R2{ 1.0E-6F };
					 constexpr WRF_REAL32 bm_r{ 3.0F };
					 constexpr WRF_REAL32 obmr{ 1.0F / bm_r };
					 constexpr WRF_REAL32 nc0{ 3.0E+8F };
					 const WRF_Vec256F32 pidnc_mul_nc0(_mm256_mul_ps(_mm256_set1_ps(pidnc), _mm256_set1_ps(nc0)));
					 /********* Executable ***********/
					 
					 

#pragma noprefetch
					 for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {

						 _mm_prefetch(reinterpret_cast<const char*>(&qc[k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
						 _mm_prefetch(reinterpret_cast<const char*>(&qc[k + 8]), _MM_HINT_T1);
#endif
						 _mm_prefetch(reinterpret_cast<const char*>(&rho[k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
						 _mm_prefetch(reinterpret_cast<const char*>(&rho[k + 8]), _MM_HINT_T1);
#endif
						 /* For cloud */
						 _mm256_storeu_ps(&rqc[k], _mm256_max_ps(_mm256_set1_ps(R1), _mm256_mul_ps(_mm256_loadu_ps(&qc[k]), 
							                       _mm256_mul_ps(&rho[k]))));
						  WRF_Vec256F32 mask1(_mm256_cmp_ps(_mm256_loadu_ps(&rqc[k]), _mm256_set1_ps(R1), _CMP_GT_OS));
						 //if (mask1.m256_f32) has_qc = true;
						  v_has_qc = _mm256_blendv_ps(ONE, ZERO, mask1);

						 _mm_prefetch(reinterpret_cast<const char*>(&qi[k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
						 _mm_prefetch(reinterpret_cast<const char*>(&qi[k + 8]), _MM_HINT_T1);
#endif
						 _mm256_storeu_ps(&rqi[k], _mm256_max_ps(_mm256_set1_ps(R1), _mm256_mul_ps(_mm256_loadu_ps(&qi[k]), 
							                       _mm256_loadu_ps(&rho[i]))));
						 temp = _mm256_mul_ps(_mm256_loadu_ps(&rho[k]), _mm256_max_ps(_mm256_loadu_ps(&qi[k]), _mm256_set1_ps(qmin)));
						 temp = _mm256_sqrt_ps(_mm256_sqrt_ps(_mm256_pow_ps(temp, _mm256_set1_ps(3.0F))));
						 _mm256_storeu_ps(&ni[k], _mm256_min_ps(_mm256_max_ps(_mm256_mul_ps(val_53milion, temp), thousand), milion));
						 _mm_prefetch(reinterpret_cast<const char*>(&ni[k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
						 _mm_prefetch(reinterpret_cast<const char*>(&ni[k + 8]), _MM_HINT_T1);
#endif
						 _mm256_storeu_ps(&rni[k], _mm256_max_ps(_mm256_set1_ps(R2), _mm256_mul_ps(_mm256_loadu_ps(&ni[k]), 
							                       _mm256_loadu_ps(&rho[k]))));
						 WRF_Vec256F32 mask2(_mm256_cmp_ps(_mm256_loadu_ps(&rqi[k]), _mm256_set1_ps(R1), _CMP_GT_OS));
						 WRF_Vec256F32 mask3(_mm256_cmp_ps(_mm256_loadu_ps(&rni[k]), _mm256_set1_ps(R2), _CMP_GT_OS));
						 v_has_qi = _mm256_blendv_ps(ONE, ZERO, mask2);
						 v_has_qi = _mm256_blendv_ps(ONE, ZERO, mask3);
						 /* For snow*/
						 _mm_prefetch(reinterpret_cast<const char*>(&qs[k + 2]), _MM_HINT_T0);
						 _mm_prefetch(reinterpret_cast<const char*>(&rho[k+2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
						 _mm_prefetch(reinterpret_cast<const char*>(&qs[k+8]), _MM_HINT_T1);
						 _mm_prefetch(reinterpret_cast<const char*>(rho[k + 8]), _MM_HINT_T1);
#endif
						 _mm256_storeu_ps(&rqs[k], _mm256_max_ps(R1, _mm256_mul_ps(_mm256_mul_ps(_mm256_loadu_ps(&qs[k]), 
							                       _mm256_loadu_ps(&rho[k])))));
						 WRF_V256F32 mask4(_mm256_cmp_ps(_mm256_loadu_ps(&rqs[k]), _mm256_set1_ps(R1), _CMP_GT_OS));
						 v_has_qs = _mm256_blendv_ps(ONE, ZERO, mask4);

					 }
#pragma noprefetch
					 if (v_has_qc.m256_f32) {
						 for (WRF_ULONGLONG k{ kts }; k != kte; k += 8) {
							 WRF_Vec256F32 mask1(_mm256_cmp_ps(_mm256_loadu_ps(&rqc[k]), _mm256_set1_ps(R1), _CMP_LE_OS));
							 if (!(_mm256_testz_ps(mask1,ONE)))
								 continue;
							 _mm_prefetch(reinterpret_cast<const char*>(&rqc[k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
							 _mm_prefetch(reinterpret_cast<const char*>(&rqc[k+8]), _MM_HINT_T1);
#endif
							 lamdac = _mm256_pow_ps(_mm256_div_ps(pidnc_mul_nc0, _mm256_loadu_ps(&rqc[k])), _mm256_set1_ps(obmr));
							 WRF_Vec256F32 lamdac_inv(_mm256_rcp_ps(lamdac));
							 _mm256_storeu_ps(&re_qc[k], _mm256_max_ps(_mm256_set1_ps(2.51E-6F), _mm256_min_ps(_mm256_mul_ps(_mm256_set1_ps(1.5F), lamdac_inv),
								                         _mm256_set1_ps(50.0E-6F))));

							
						 }
					 }
#pragma noprefetch
					 if (v_has_qi.m256_f32) {
						 for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
							 WRF_Vec256F32 mask1(_mm256_cmp_ps(_mm256_loadu_ps(&rqi[k]), _mm256_set1_ps(R1), _CMP_LE_OQ));
							 WRF_Vec256F32 mask2(_mm256_cmp_ps(_mm256_loadu_ps(&rni[k]), _mm256_set1_ps(R2), _CMP_LE_OQ));
							 if (!(_mm256_testz_ps(mask1, ONE)) || !(_mm256_testz_ps(mask2, ONE)))
								 continue;
							 _mm_prefetch(reinterpret_cast<const char*>(&rqi[k + 2]), _MM_HINT_T0);
							 _mm_prefetch(reinterpret_cast<const char*>(&ni[k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
							 _mm_prefetch(reinterpret_cast<const char*>(&rqi[k+8]),_MM_HINT_T1);
							 _mm_prefetch(reinterpret_cast<const char*>(&ni[k + 8]), _MM_HINT_T1);
#endif
							 diai = _mm256_mul_ps(_mm256_set1_ps(11.9F), _mm256_sqrt_ps(_mm256_div_ps(_mm256_loadu_ps(&rqi[k]),
								    _mm256_loadu_ps(&ni[k]))));
							 _mm256_storeu_ps(&re_qi[k], _mm256_max_ps(_mm256_set1_ps(10.01E-6F), _mm256_min_ps(_mm256_mul_ps(_mm256_set1_ps(0.12225F),
								                         diai), _mm256_set1_ps(125.0E-6F))));
						 }
					 }
#pragma noprefetch
					 if (v_has_qs.m256_f32) {
						 for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
							 WRF_Vec256F32 mask1(_mm256_cmp_ps(_mm256_loadu_ps(&rqs[k]), _mm256_set1_ps(R1), _CMP_LE_OS));
							 if (!(_mm256_testz_ps(mask1, ONE)))
								 continue;
							 _mm_prefetch(reinterpret_cast<const char*>(&t[k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
							 _mm_prefetch(reinterpret_cast<const char*>(&t[k+8]), _MM_HINT_T1);
#endif
							 supcol = _mm256_sub_ps(_mm256_set1_ps(t0c), _mm256_loadu_ps(&t[k]));
							 n0sfac = _mm256_max_ps(_mm256_min_ps(_mm256_exp_ps(_mm256_mul_ps(alpha_vf, supcol)),
								      _mm256_div_ps(n0smax_vf, n0s_vf)), ONE);
							 _mm_prefetch(reinterpret_cast<const char*>(&rqs[k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
							 _mm_prefetch(reinterpret_cast<const char*>(&rqs[k+8]), _MM_HINT_T1);
#endif
							 lamdas = _mm256_sqrt_ps(_mm256_sqrt_ps(_mm256_div_ps(_mm256_mul_ps(_mm256_set1_ps(pidn0s),
								      n0sfac), _mm256_loadu_ps(&rqs[k]))));
							 WRF_Vec256F32 lamdas_inv(_mm256_rcp_ps(lamdas));
							 _mm256_storeu_ps(&re_qs[k], _mm256_max_ps(_mm256_set1_ps(25.0E-6F), _mm256_min_ps(_mm256_mul_ps(
								                         _mm256_set1_ps(0.5F), lamdas_inv)), _mm256_set1_ps(999.0E-9F)));
						 }
					 }

		}

		/**********************************************************************
		              Implementation of refl10cm_wsm5 function
		***********************************************************************/
		template<const WRF_ULONGLONG kts,
			     const WRF_ULONGLONG kte >  auto   refl10cm_wsm5(_In_ const WRF_Mat1DF32 &qv1d,
			                                                     _In_ const WRF_Mat1DF32 &qr1d,
			                                                     _In_ const WRF_Mat1DF32 &qs1d,
			                                                     _In_ const WRF_Mat1DF32 &t1d,
			                                                     _In_ const WRF_Mat1DF32 &p1d,
																 _Inout_    WRF_Mat1DF32 &dBZ)->void {

					 /* Local variables: */
					 WRF_Mat1DF32 temp{ boost::extents[kte] };
					 WRF_Mat1DF32 pres{ boost::extents[kte] };
					 WRF_Mat1DF32 qv{ boost::extents[kte] };
					 WRF_Mat1DF32 rho{ boost::extents[kte] };
					 WRF_Mat1DF32 rr{ boost::extents[kte] };
					 WRF_Mat1DF32 rs{ boost::extents[kte] };

					 WRF_Vec256F32 temp_C;
					 WRF_Mat1DF32 ilamr{ boost::extents[kte] };
					 WRF_Mat1DF32 ilams{ boost::extents[kte] };
					 WRF_Mat1DF32 N0_r{ boost::extents[kte] };
					 WRF_Mat1DF32 N0_s{ boost::extents[kte] };
					 WRF_Vec256F32 lamr, lams;
					 WRF_Mat1DF32 L_qr{ boost::extents[kte] }; // Acts as a logical array
					 WRF_Mat1DF32 L_qs{ boost::extents[kte] }; // Acts as a logical array
					 WRF_Mat1DF32 ze_rain{ boost::extents[kte] };
					 WRF_Mat1DF32 ze_snow{ boost::extents[kte] };
					 WRF_Vec256F32 fmelt_s;

					 WRF_INT i, k, k_0, kbot, n;
					 const WRF_Vec256F32 R(_mm256_set1_ps(287.F));

					 /* Exxecutable code: */

					 for (WRF_ULONGLONG k{ kts }; k != kte; k += 16) {
						 _mm256_storeu_ps(&dBZ[k], _mm256_set1_ps(-35.0F));
						 _mm256_storeu_ps(&dBZ[k + 8], _mm256_set1_ps(-35.0F));
					 }

					 /* Puts rows of data into local arrays.*/
#pragma noprefetch
					 for (WRF_ULONGLONG k{ kts }; k != kte - 8; k += 8) {
						 _mm256_storeu_ps(&temp[k], _mm256_loadu_ps(&t1d[k]));
						 _mm_prefetch(reinterpret_cast<const char*>(&temp[k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
						 _mm_prefetch(reinterpret_cast<const char*>(&temp[k+8]), _MM_HINT_T1);
#endif
						 temp_C = _mm256_min_ps(_mm256_set1_ps(-0.001F), _mm256_sub_ps(_mm256_loadu_ps(&temp[k]),
							      _mm256_set1_ps(-273.15F)));
						 _mm_prefetch(reinterpret_cast<const char*>(&qv1d[k + 2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
						 _mm_prefetch(reinterpret_cast<const char*>(&qv1d[k+8]), _MM_HINT_T1);
#endif
						 _mm256_storeu_ps(&qv[k], _mm256_max_ps(_mm256_set1_ps(1.0E-10F), _mm256_loadu_ps(&qv1d)));
						 _mm256_storeu_ps(&pres[k], _mm256_loadu_ps(&p1d[k]));
						 WRF_Vec256F32 rho_term1(_mm256_mul_ps(_mm256_set1_ps(0.622F), _mm256_loadu_ps(&pres[k])));
						 _mm_prefetch(reinterpret_cast<const char*>(&temp[k + 2]), _MM_HINT_T0);
						 _mm_prefetch(reinterpret_cast<const char*>(&qv[k+2]), _MM_HINT_T0);
#if DATA_SIZE_TO_BE_CACHED_FLOAT > 8000
						 _mm_prefetch(reinterpret_cast<const char*>(&temp[k + 8]), _MM_HINT_T1);
						 _mm_prefetch(reinterpret_cast<const char*>(&qv[k + 8]), _MM_HINT_T1);
#endif
						 WRF_Vec256F32 rho_term2(_mm256_mul_ps(_mm256_mul_ps(R, _mm256_loadu_ps(&temp[k])), _mm256_add_ps(
							           _mm256_loadu_ps(&qv[k]), _mm256_set1_ps(0.622F))));
						 _mm256_storeu_ps(&rho[k], _mm256_div_ps(rho_term1, rho_term2));

						 WRF_Vec256F32 mask1(_mm256_cmp_ps(_mm256_loadu_ps(&qr1d[k]), _mm256_set1_ps(1.0E-9F), _CMP_LT_OS));
						 // TODO Implement RADAR module.
					 }

			}

			

											 