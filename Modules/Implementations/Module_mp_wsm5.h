#ifndef MODULE_MP_WSM5_H_
#define MODULE_MP_WSM5_H_

#ifndef MODULE_MP_WSM5_VERSION_MAJOR
#define MODULE_MP_WSM5_VERSION_MAJOR 1
#endif

#ifndef MODULE_MP_WSM5_VERSION_MINOR
#define MODULE_MP_WSM5_VERSION_MINOR 0
#endif

#ifndef MODULE_MP_WSM5_CREATE_DATE
#define MODULE_MP_WSM5_CREATE_DATE 20160623
#endif

/* Set this macro to successful build date!!*/
#ifndef MODULE_MP_WSM5_BUILD_DATE
#define MODULE_MP_WSM5_BUILD_DATE 0
#endif


/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library Module WSM5 -  declaration.

@file Module_mp_wsm5.h
@author: Bernard Gingold
@version:  1.0.0  08/05/2016
@description: Module_mp_wsm5.h
*/

//#include "WRF_PHYS_LIB_TYPEDEFS.h"
//#include "Wrf_phys_except.h"
#include "Module_mp_wsm_iface.h"

#if COLLECT_PERF_DATA == 1
#include "Wrf_perf_collectors.h"
#endif

namespace  wrf_physics {

	namespace wrf_models_wsm {

		namespace wrf_wsm5_impl {


			
			
			namespace  {

				/* float single - precision types: */
				constexpr WRF_REAL32 f_dtcldcr{ 120.0F };
				constexpr WRF_REAL32 f_n0r{ 8.0e+6f };
				constexpr WRF_REAL32 f_qcrmin{ 1.0e-9f };
				constexpr WRF_REAL32 f_bvtr{ 0.8f };
				constexpr WRF_REAL32 f_avtr{ 841.9F };
				constexpr WRF_REAL32 f_r0{ 0.8e-5f };
				constexpr WRF_REAL32 f_peaut{ 0.55F };
				constexpr WRF_REAL32 f_xncr{ 3.0e+8F };
				constexpr WRF_REAL32 f_xmyu{ 1.718e-5f };
				constexpr WRF_REAL32 f_avts{ 11.72f };
				constexpr WRF_REAL32 f_bvts{ 0.41f };
				constexpr WRF_REAL32 f_n0smax{ 1.0e+11f };
				constexpr WRF_REAL32 f_lamdarmax{ 8.0e+4f };
				constexpr WRF_REAL32 f_lamdasmax{ 1.0e+5f };
				constexpr WRF_REAL32 f_lamdagmax{ 6.0e+4f };
				constexpr WRF_REAL32 f_dicon{ 11.9f };
				constexpr WRF_REAL32 f_dimax{ 500.0e-6f };
				constexpr WRF_REAL32 f_n0s{ 2.0e+6f };
				constexpr WRF_REAL32 f_alpha{ 0.12f };
				constexpr WRF_REAL32 f_pfrz1{ 100.0f };
				constexpr WRF_REAL32 f_pfrz2{ 0.66f };
				constexpr WRF_REAL32 f_eacrc{ 1.0f };

				/* double single - precision types: */

				constexpr WRF_REAL64 d_dtcldcr{ 120.0 };
				constexpr WRF_REAL64 d_n0r{ 8.0e+6 };
				constexpr WRF_REAL64 d_qcrmin{ 1.0e-9 };
				constexpr WRF_REAL64 d_bvtr{ 0.8 };
				constexpr WRF_REAL64 d_avtr{ 841.9 };
				constexpr WRF_REAL64 d_r0{ 0.8e-5 };
				constexpr WRF_REAL64 d_peaut{ 0.55 };
				constexpr WRF_REAL64 d_xncr{ 3.0e+8 };
				constexpr WRF_REAL64 d_xmyu{ 1.718e-5 };
				constexpr WRF_REAL64 d_avts{ 11.72 };
				constexpr WRF_REAL64 d_bvts{ 0.41 };
				constexpr WRF_REAL64 d_n0smax{ 1.0e+11 };
				constexpr WRF_REAL64 d_lamdarmax{ 8.0e+4 };
				constexpr WRF_REAL64 d_lamdasmax{ 1.0e+5 };
				constexpr WRF_REAL64 d_lamdagmax{ 6.0e+4 };
				constexpr WRF_REAL64 d_dicon{ 11.9 };
				constexpr WRF_REAL64 d_dimax{ 500.0e-6 };
				constexpr WRF_REAL64 d_n0s{ 2.0e+6f };
				constexpr WRF_REAL64 d_alpha{ 0.12 };
				constexpr WRF_REAL64 d_pfrz1{ 100.0 };
				constexpr WRF_REAL64 d_pfrz2{ 0.66 };
				constexpr WRF_REAL64 d_eacrc{ 1.0 };

				/* WRF_Vec256F32 single-precision vector type*/
				const WRF_Vec256F32 dtcldcr_vf(_mm256_set1_ps(120.0f));
				const WRF_Vec256F32 n0r_vf(_mm256_set1_ps(8.0e+6f));
				const WRF_Vec256F32 qcrmin_vf(_mm256_set1_ps(1.0e-9f));
				const WRF_Vec256F32 bvtr_vf(_mm256_set1_ps(0.8f));
				const WRF_Vec256F32 avtr_vf(_mm256_set1_ps(841.9f));
				const WRF_Vec256F32 r0_vf(_mm256_set1_ps(0.8e-5f));
				const WRF_Vec256F32 peaut_vf(_mm256_set1_ps(0.55f));
				const WRF_Vec256F32 xncr_vf(_mm256_set1_ps(3.0e+8f));
				const WRF_Vec256F32 xmyu_vf(_mm256_set1_ps(1.718e-5f));
				const WRF_Vec256F32 avts_vf(_mm256_set1_ps(11.72f));
				const WRF_Vec256F32 bvts_vf(_mm256_set1_ps(0.41f));
				const WRF_Vec256F32 n0smax_vf(_mm256_set1_ps(1.0e+11f));
				const WRF_Vec256F32 lamdarmax_vf(_mm256_set1_ps(8.0e+4f));
				const WRF_Vec256F32 lamdasmax_vf(_mm256_set1_ps(1.0e+5f));
				const WRF_Vec256F32 lamdagmax_vf(_mm256_set1_ps(6.0e+4f));
				const WRF_Vec256F32 dicon_vf(_mm256_set1_ps(11.9f));
				const WRF_Vec256F32 dimax_vf(_mm256_set1_ps(500.0e-6f));
				const WRF_Vec256F32 n0s_vf(_mm256_set1_ps(2.0e+6f));
				const WRF_Vec256F32 alpha_vf(_mm256_set1_ps(0.12f));
				const WRF_Vec256F32 pfrz1_vf(_mm256_set1_ps(100.0f));
				const WRF_Vec256F32 pfrz2_vf(_mm256_set1_ps(0.66f));
				const WRF_Vec256F32 eacrc_vf(_mm256_set1_ps(1.0f));

				/* WRF_Vec256F64 double-precision vector type*/
				const WRF_Vec256F64 dtcldcr_vd(_mm256_set1_pd(120.0));
				const WRF_Vec256F64 n0r_vd(_mm256_set1_pd(8.0e+6));
				const WRF_Vec256F64 qcrmin_vd(_mm256_set1_pd(1.0e-9));
				const WRF_Vec256F64 bvtr_vd(_mm256_set1_pd(0.8));
				const WRF_Vec256F64 avtr_vd(_mm256_set1_pd(841.9));
				const WRF_Vec256F64 r0_vd(_mm256_set1_pd(0.8e-5));
				const WRF_Vec256F64 peaut_vd(_mm256_set1_pd(0.55));
				const WRF_Vec256F64 xncr_vd(_mm256_set1_pd(3.0e+8));
				const WRF_Vec256F64 xmyu_vd(_mm256_set1_pd(1.718e-5));
				const WRF_Vec256F64 avts_vd(_mm256_set1_pd(11.72));
				const WRF_Vec256F64 bvts_vd(_mm256_set1_pd(0.41));
				const WRF_Vec256F64 n0smax_vd(_mm256_set1_pd(1.0e+11));
				const WRF_Vec256F64 lamdarmax_vd(_mm256_set1_pd(8.0e+4));
				const WRF_Vec256F64 lamdasmax_vd(_mm256_set1_pd(1.0e+5));
				const WRF_Vec256F64 lamdagmax_vd(_mm256_set1_pd(6.0e+4));
				const WRF_Vec256F64 dicon_vd(_mm256_set1_pd(11.9));
				const WRF_Vec256F64 dimax_vd(_mm256_set1_pd(500.0e-6));
				const WRF_Vec256F64 n0s_vd(_mm256_set1_pd(2.0e+6));
				const WRF_Vec256F64 alpha_vf(_mm256_set1_pd(0.12f));
				const WRF_Vec256F64 pfrz1_vd(_mm256_set1_pd(100.0));
				const WRF_Vec256F64 pfrz2_vd(_mm256_set1_pd(0.66));
				const WRF_Vec256F64 eacrc_vd(_mm256_set1_pd(1.0));

				/* Translation unit namespace static variable type float*/
				static WRF_REAL32 rsloperbmax, qc0, qck1, bvtr1, bvtr2, bvtr3, bvtr4,
					g1pbr, g3pbr, g4pbr, g5pbro2, pvtr, eacrr, pacrr,pidnc,
					precr1, precr2, xmnax, roqimax, bvts1, bvts2, bvts3,
					bvts4, g1pbs, g4pbs, g3pbs, g5pbso2, pvts,pvtr, pacrs, precs1,
					precs2, pidn0r, pidn0s, xlv1, pacrc, rslopermax, rslopesmax,
					rslopegmax, rslopesbmax, rsloper2max, rslopes2max,
					rslopes2gmax, rsloper3max, rslopes3max, rslopes3gmax;

				/* Translation unit namespace static variables type double*/
				static WRF_REAL64 d_rsloperbmax, d_qc0, d_qck1, d_bvtr1, d_bvtr2, d_bvtr3, d_bvtr4,
					d_g1pbr, d_g3pbr, d_g4pbr, d_g5pbro2, d_pvtr, d_eacrr, d_pacrr,d_pidnc,
					d_precr1, d_precr2, d_xmnax, d_roqimax, d_bvts1, d_bvts2, d_bvts3,
					d_bvts4, d_g1pbs,d_g4pbs, d_g3pbs, d_g5pbso2, d_pvts, d_pvtr, d_pacrs, d_precs1,
					d_precs2, d_pidn0r,d_pidn0s, d_xlv1, d_pacrc, d_rslopermax, d_rslopesmax,
					d_rslopegmax, d_rslopesbmax, d_rsloper2max, d_rslopes2max,
					d_rslopes2gmax, d_rsloper3max, d_rslopes3max, d_rslopes3gmax;





			}

			/***********************************************************
			     Helper structure WSM5Consts templated on type T
				 Primary template
			************************************************************/
			template<typename T>   struct WSM5_CONSTS;

			/* Float specialization  - WSM5_CONSTS<float> */

			template<>   struct WSM5_CONSTS<float> {

				 const WRF_Vec256F32 ZERO = _mm256_setzero_ps();

				 const WRF_Vec256F32 ONE = _mm256_set1_ps(1.0F);

				 const WRF_Vec256Int NEG_MASK = _mm256_set1_epi64x(0x800000000000000);

				 const WRF_Vec256Int ABS_MASK = _mm256_set1_epi64x(0x7FFFFFFFFFFFFFF);

				 const WRF_Vec256F32 v_0_99c = _mm256_set1_ps(0.99F);

				 const WRF_Vec256F32 THOUSAND = _mm256_set1_ps(1.0E+3F);

				 const WRF_Vec256F32 MILLION = _mm256_set1_ps(1.0E+6F);

				 const WRF_Vec256F32 v_5_38_e7c = _mm256_set1_ps(5.38E+7F);

				 const WRF_Vec256F32 v_1_496_e6c = _mm256_set1_ps(1.496E-6F);

				 const WRF_Vec256F32 v_8_794_e5c = _mm256_set1_ps(8.794E-5F);

				 const WRF_Vec256F32 v_1_81c = _mm256_set1_ps(1.81F);

				 const WRF_Vec256F32 v_0_33c = _mm256_set1_ps(0.3333333F);

				 const WRF_Vec256F32 v_120_0c = _mm256_set1_ps(120.0F);

				 const WRF_Vec256F32 v_1_414e3c = _mm256_set1_ps(1.414E+3F);

				 const WRF_Vec256F32 v_1_0_e25c = _mm256_set1_ps(1.0E-25F);

				 const WRF_Vec256F32 v_1_49_e4c = _mm256_set1_ps(1.49E+4F);

				 const WRF_Vec256F32 v_1_31c = _mm256_set1_ps(1.31F);

				 const WRF_Vec256F32 HALF_PI = _mm256_set1_ps(1.570796326794896F);

				 const float f_1over100{ 0.01F };

			};

			/* Double specialization -  WSM5_CONST<double> */

			template<>   struct WSM5_CONSTS<double> {

				const WRF_Vec256F64 ZERO = _mm256_setzero_pd();

				const WRF_Vec256F64 ONE = _mm256_set1_pd(1.0);

				const WRF_Vec256F32 v_0_99c = _mm256_set1_ps(0.99);
			};

			/*************************************************************
			  Primary template for WSM-5-3-5 Implementation.
			  Specializations are templated on template type T , on
			  class type ArrayType and on 18 default arguments of type
			  WRF_ULONGLONG.
			**************************************************************/
				template<typename T, 
				         class ArrayType,
					     const WRF_ULONGLONG its,
					     const WRF_ULONGLONG ite,
					     const WRF_ULONGLONG kts,
					     const WRF_ULONGLONG kte,
					     const WRF_ULONGLONG ims,
					     const WRF_ULONGLONG ime,
					     const WRF_ULONGLONG jms,
					     const WRF_ULONGLONG jme >    class   WSM535;




						 /* Partial specialization on type float and type
						    boost::multi_array<WRF_REAL32,1>*/
				template<const WRF_ULONGLONG its,
						 const WRF_ULONGLONG ite,
					     const WRF_ULONGLONG kts,
						 const WRF_ULONGLONG kte,
						 const WRF_ULONGLONG ims,
						 const WRF_ULONGLONG ime,
						 const WRF_ULONGLONG jms,
						 const WRF_ULONGLONG jme >   class  WSM535<WRF_REAL32, 
						 boost::multi_array<WRF_REAL32, 1>, its, ite, kts, kte, ims, ime, jms, jme> {



							 /*******************************************************
							                 Constructor and Destructors
							 ********************************************************/

						 public:

							 /* Main class Ctor*/
							 WSM535(_In_ const WRF_Mat2DF32 &,
							        _In_ const WRF_Mat3DF32 &,
							        _In_ const WRF_Mat3DF32 &,
							        _In_ const WRF_Mat2DF32 &,
							        _In_ const WRF_Mat1DF32 &,
							        _In_ const WRF_Mat1DF32 &,
#if FORTRAN_OPTIONAL == 1
							        _In_ const WRF_Mat2DF32 &,
							        _In_ const WRF_Mat2DF32 &,
#endif
							        _In_ const WRF_Mat1DF32 &);

									
							 /* Destructor = default.*/
							 ~WSM535() = default;





							 /*Purpose: main computation routine.*/
							 auto      wsm52D(        _In_ const WRF_Mat2DF32 &, 
							                          _In_ const WRF_Mat2DF32 &,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
							                          _In_ const WRF_REAL32,
													  _In_ const WRF_REAL32, 
#if COLLECT_PERF_DATA == 1
													   _Inout_ wrf_physics::wrf_service::wrf_wsm_perf_collectors::WSM5_PerfCollector<WRF_ULONGLONG,10> &
#endif
													  )->void;
							                                              

							 /* Purpose: slope computation routine*/
							 auto  slope_wsm5()->void;

							 /* Purpose: slope of rain computation routine.*/
							 auto  slope_rain()->void;

							 /* Purpose: slope of snow computation routine.*/
							 auto  slope_snow()->void;

							 
							 /*  init function initializes static anon
							     namespace variables.*/
							 auto   wsm5init(_In_ const WRF_REAL32,
								             _In_ const WRF_REAL32,
								             _In_ const WRF_REAL32,
								             _In_ const WRF_REAL32,
								             _In_ const WRF_REAL32,
								             _In_ const bool)->void;
							
							
							 /****************************************
							         Class getters  member functions
							 *****************************************/

							 auto  get_t()const->WRF_Mat2DF32 const &;

							 auto  get_qci()const->WRF_Mat3DF32 const &;

							 auto  get_qrs()const->WRF_Mat3DF32 const &;



						 private:

							 /* Class member, array m_t*/
							 WRF_Mat2DF32  m_t;

							 /* Class member, array m_qci*/
							 WRF_Mat3DF32 m_qci;

							 /* Class member, array m_qrs*/
							 WRF_Mat3DF32 m_qrs;

							 /* Class member, array m_q*/
							 WRF_Mat2DF32 m_q;

							 /* Class member, array m_rain*/
							 WRF_Mat1DF32 m_rain;

							 /* Class member, array m_rainncv*/
							 WRF_Mat1DF32 m_rainncv;

							 /* Class member, array m_sr*/
							 WRF_Mat1DF32 m_sr;

							 /* Class member, array m_rslope*/
							 WRF_Mat3DF32 m_rslope;

							 /* Class member, array m_rslopeb*/
							 WRF_Mat3DF32 m_rslopeb;

							 /* Class member, array m_rslope2*/
							 WRF_Mat3DF32 m_rslope2;

							 /* Class member, array m_rslope3*/
							 WRF_Mat3DF32 m_rslope3;

							 /* Class member, array m_vt*/
							 WRF_Mat3DF32 m_vt;

							 /* Class member, array m_den*/
							 WRF_Mat2DF32 m_den;

							 /* Class member, array m_denfac*/
							 WRF_Mat2DF32 m_denfac;

#if FORTRAN_OPTIONAL == 1
							 /* Class member, array m_snow*/
							 WRF_Mat2DF32 m_snow;

							 /* Class member, array m_snowncv*/
							 WRF_Mat2DF32 m_snowncv;
#endif

							 static const WRF_ULONGLONG nChunks;
							 
							 

						 };
						

						 /****************************************************
						         Free-standing namespace scope functions
						 *****************************************************/

						 /*Purpose: compute rgamma function value*/
						 auto   rgamma(_In_ const WRF_REAL32)->const WRF_REAL32;

						


						 /*Purpose: compute effective radii of cloud water, ice, snow
						            for single-moment microphysics.*/
						 template<const WRF_ULONGLONG kts,
							      const WRF_ULONGLONG kte >     auto   effectRad_wsm5(_In_ const WRF_REAL32,
							                                                          _In_ const WRF_REAL32 ,
							                                                          _In_ const WRF_Mat1DF32 &,
							                                                          _In_ const WRF_Mat1DF32 &,
							                                                          _In_ const WRF_Mat1DF32 &,
							                                                          _In_ const WRF_Mat1DF32 &,
							                                                          _In_ const WRF_Mat1DF32 &,
							                                                          _Inout_ WRF_Mat1DF32 &,
							                                                          _Inout_ WRF_Mat1DF32 &,
							                                                          _Inout_ WRF_Mat1DF32 &)->void;


						 /*Purpose: compute radar reflectivity at 10cm
						            wavelength.*/
						 template<const WRF_ULONGLONG kts,
							      const WRF_ULONGLONG kte >     auto  refl10cm_wsm5(_In_ const WRF_Mat1DF32 &,
							                                                        _In_ const WRF_Mat1DF32 &,
							                                                        _In_ const WRF_Mat1DF32 &,
							                                                        _In_ const WRF_Mat1DF32 &,
							                                                        _In_ const WRF_Mat1DF32 &,
							                                                        _Inout_    WRF_Mat1DF32 &)->void;
						
			


#include "Module_mp_wsm5.inl"
		}
	}
}
#endif /*MODULE_MP_WSM5_H_22_06_2016*/