#ifndef MODULE_FR_FIRE_ATM_IMPL_H_05_15_2016
#define MODULE_FR_FIRE_ATM_IMPL_H_05_15_2016 0x100

/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library Module Fire Atm Implementation -  declaration.

@file Module_Fr_Fire_Atm_Impl.h
@author: Bernard Gingold
@version:  1.0.0  08/05/2016
@description: Module_Fr_Fire_Atm_Impl.h
*/

#include "Module_Fr_Fire_Atm_Iface.h"

namespace  wrf_physics {

	namespace  fire_fr_atm {

		namespace  fire_fr_atm_impl {


			/*********************************************************
			       Generic declaration of FireTendency class
			       This class is templated on type T and containes
			       18 default template arguments - array indices.
			       This  class is meant to be ICC auto-vectorised.
			**********************************************************/

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
					 const WRF_ULONGLONG JTE > class    FireTendencyAV {



					 public:

						 /***********************************
						           Class typedefs
						 ************************************/
						typedef  boost::multi_array<T, 2> Matrix2D;
						typedef  boost::multi_array<T, 3> Matrix3D;



						/******************************************
						        Constructors and Destructor
						*******************************************/

						/* "Main" class Constructor default, initializes
						    object state and zero-fills its arrays.*/
						FireTendencyAV();

						/* Copy Constructor */
						FireTendencyAV(_In_ const FireTendencyAV &);

						/* Move Constructor */
						FireTendencyAV(_In_ FireTendencyAV &&);

						/* Destructor = default*/
						~FireTendencyAV() = default;

						/********************************************
						          Class member operators
						*********************************************/

						/* copy-assignment. */
						auto   operator=(_In_ const FireTendencyAV &)->FireTendencyAV &;

						/* move-assignment. */
						auto    operator=(_In_ FireTendencyAV &&)->FireTendencyAV &;

						/* subscription implemented by operator()
						   returns std::pair<T,T>*/
						auto    operator()(_In_ const WRF_ULONGLONG,
							               _In_ const WRF_ULONGLONG,
							               _In_ const WRF_ULONGLONG)const-> const std::pair<T, T>;

						/*************************************************
						              Class member functions
						**************************************************/

						/* This function returns const reference to
						   member m_aRthFrTen. */
						auto     getRthFrTen()const->Matrix3D const &;

						/* This function returns const reference to
						   member m_aRqvFrTen. */
						auto     getRqvFrTen()const->Matrix3D const &;

						/* This function returns nth element of m_aRthFrTen
						   indexed  by (i,j,k)*/
						auto     nth_elem_rth(_In_ const WRF_ULONGLONG,
							                  _In_ const WRF_ULONGLONG,
							                  _In_ const WRF_ULONGLONG)const->const T;

						/* This function returns nth element of m_aRqvFrTen
						   indexed  by (i,j,k)*/
						auto      nth_elem_rqv(_In_ const WRF_ULONGLONG,
							                   _In_ const WRF_ULONGLONG,
							                   _In_ const WRF_ULONGLONG)const->const T;


						/* This function computes fire tendency.*/
						auto      fire_tendency(_In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME> &,
							                    _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME> &,
												_In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME> &,
												_In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T,IMS,IME,JMS,JME> &,
												_In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<T,IMS,IME,JMS,JME> &,
												_In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T,IMS,IME,JMS,JME> &,
												_In_ const Matrix3D &,
												_In_ const Matrix3D &,
												_In_ const Matrix3D &,
												_In_ const T,
												_In_ const T,
												_In_ const T)->FireTendencyAV &;


					 private:

						 /* Class member variable m_aRthFrTen, denotes
						    theta tendency from fire (in mass units).*/
						 Matrix3D   m_aRthFrTen;

						 /*  Class member variable m_aRqvFrTen, denotes
						     Qv tendency from fire (in mass units). */
						 Matrix3D   m_aRqvFrTen;
					 };

					 /************************************************
					               Global  operators
					 *************************************************/

					 /* overloaded operator<< */
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
						      const WRF_ULONGLONG JTE > auto  operator<<(_In_ std::ostream &,
						                                            _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyAV<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
						 ITS, ITE, KTS, KTE, JTS, JTE>& rhs)->std::ostream &;

					 /**********************************************
					   Class FireTendencyMV - manually vectorised
					   Primary template declaration. Templated
					   on type T and on 18 default arguments of
					   type WRF_ULONGLONG.
					 ***********************************************/

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
							  const WRF_ULONGLONG JTE > class   FireTendencyMV {};

					 /****************************************************
					  Class FireTendencyMV - manually vectorised.
					  Specialization on type double. Non specialized -
					  18 default template arguments of type WRF_ULONGLONG.
					  Manual vectorisation based on AVX ISA.
					 *****************************************************/

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
							  const WRF_ULONGLONG JTE >     class   FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
							  ITS, ITE, KTS, KTE, JTS, JTE> {



							  public:


								  /****************************************
								             Class typedefs
								  *****************************************/
								//  typedef boost::multi_array<double, 3>  Matrix3DF64;

                                    
								  /*******************************************
								           Constructors and Destructor
								  ********************************************/


								  /* Default constructor, instantiates and
								     zero-initilizes class members.*/
								  FireTendencyMV();

								  /* Copy Constructor */
								  FireTendencyMV(_In_ const FireTendencyMV &);

								  /* Move Constructor */
								  FireTendencyMV(_In_ FireTendencyMV &&);

								  /* Destructor = default */
								  ~FireTendencyMV() = default;

								  /******************************************
								               Class member operators
								  *******************************************/

								  /* copy-assignment */
								  auto    operator=(_In_ const FireTendencyMV &)->FireTendencyMV &;

								  /* move-assignment */
								  auto    operator=(_In_ FireTendencyMV &&)->FireTendencyMV &;

								  /* subscription implemented by operator()*/
								  auto    operator()(_In_ const WRF_ULONGLONG,
									                 _In_ const WRF_ULONGLONG,
									                 _In_ const WRF_ULONGLONG)const->const std::pair<T, T>;



								  /********************************************
								            Class member functions
								  *********************************************/

								  /* This function returns a const refrence to
								     member variable m_dRthFrTen.  */
								  auto     getRthFrTen()const->WRF_Mat3DF64 const &;

								  /* This function returns a const reference to
								     member variable m_dRqvFrTen. */
								  auto     getRqvFrTen()const->WRF_Mat3DF64 const &;

								  /* This function returns nth element of m_aRthFrTen
								  indexed  by (i,j,k)*/
								  auto     nth_elem_rth(_In_ const WRF_ULONGLONG,
									                    _In_ const WRF_ULONGLONG,
									                    _In_ const WRF_ULONGLONG)const->const double;

								  /* This function returns nth element of m_aRqvFrTen
								  indexed  by (i,j,k)*/
								  auto      nth_elem_rqv(_In_ const WRF_ULONGLONG,
									  _In_ const WRF_ULONGLONG,
									  _In_ const WRF_ULONGLONG)const->const double;

								  /* This function computes fire tendency.*/
								  auto     fire_tendency(_In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<double, IMS, IME, JMS, JME> &,
									                     _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<double, IMS, IME, JMS, JME> &,
									                     _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<double, IMS, IME, JMS, JME> &,
									                     _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<double, IMS, IME, JMS, JME> &,
									                     _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<double, IMS, IME, JMS, JME> &,
									                     _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<double, IMS, IME, JMS, JME> &,
									                     _In_ const WRF_Mat3DF64 &,
									                     _In_ const WRF_Mat3DF64 &,
									                     _In_ const WRF_Mat3DF64 &,
									                     _In_ const double,
									                     _In_ const double,
									                     _In_ const double)->FireTendencyMV &;

							  private:

								  /* Class member m_dRthFrTen, denotes fire Theta
								     tendency in units of mass.
									 Notice: Could have used boost::quantity<
									 si::mass,double> as an Matrix3DF64 element
									 , but I did not test manual vectorisation
									 with this type of object. Possible AoS situation.*/
								 WRF_Mat3DF64  m_dRthFrTen;

								  /* Class member m_dRqvFrTen, denotes fire Qv
								     tendency in unit of mass.*/
								 WRF_Mat3DF64  m_dRqvFrTen;

							  };

							  /* global overloaded operator<< */
							  template < const WRF_ULONGLONG IDS,
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
								         const WRF_ULONGLONG JTE > auto   operator<<(_In_ std::ostream &,
								                                             const _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_impl::FireTendencyMV<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
								                                                                                                                                      ITS, ITE, KTS, KTE, JTS, JTE> &)->std::ostream &;

							  /**********************************************
							   Class FireTendencyMV - manually vectorised
							   partialy specialized on type float and not 
							   specialized on 18 const WRF_ULONGLONG.
							   Manual vectorisation based on AVX ISA.
							  ***********************************************/

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
									   const WRF_ULONGLONG JTE >     class      FireTendencyMV<float, IDS, IDE, KDS, KDE, JDS, JDE, IMS, IME, KMS, KME, JMS, JME,
									   ITS, ITE, KTS, KTE, JTS, JTE> {


									   public:

										   /*******************************************
										   Constructors and Destructor
										   ********************************************/


										   /* Default constructor, instantiates and
										   zero-initilizes class members.*/
										   FireTendencyMV();

										   /* Copy Constructor */
										   FireTendencyMV(_In_ const FireTendencyMV &);

										   /* Move Constructor */
										   FireTendencyMV(_In_ FireTendencyMV &&);

										   /* Destructor = default */
										   ~FireTendencyMV() = default;

										   /********************************************
										             Class member operators
										   *********************************************/

										   /* copy assignment */
										   auto   operator=(_In_ const FireTendencyMV &)->FireTendencyMV &;

										   /* move assignment */
										   auto   operator=(_In_ FireTendencyMV &&)->FireTendencyMV &;

										   /* subscription implemented by operator() */
										   auto   operator()(_In_ const WRF_ULONGLONG,
											                 _In_ const WRF_ULONGLONG,
											                 _In_ const WRF_ULONGLONG)const-> const std::pair<float, float>;

										   /******************************************
										           Class member functions
										   *******************************************/

										   /* This function returns a const reference to
										      class member m_fRthFrTen*/
										   auto    getRthFrTen()const->WRF_Mat3DF32 const &;

										   /* This function returns a const reference to
										      class member m_fRqvFrTen.*/
										   auto    getRqvFrTen()const->WRF_Mat3DF32 const &;

										   /* This function returns a const float at 
										      subscript (i,k,j)*/
										   auto    nth_elem_rth(_In_ const WRF_ULONGLONG,
											                    _In_ const WRF_ULONGLONG,
											                    _In_ const WRF_ULONGLONG)const->const float;

										   /* This function returns a const float at
										   subscript (i,k,j)*/
										   auto    nth_elem_rqv(_In_ const WRF_ULONGLONG,
											                    _In_ const WRF_ULONGLONG,
											                    _In_ const WRF_ULONGLONG)const->const float;

										   /* This function computes fire tendency.*/
										   auto    fire_tendency(_In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<float, IMS, IME, JMS, JME> &,
											                     _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<float, IMS, IME, JMS, JME> &,
											                     _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<float, IMS, IME, JMS, JME> &,
											                     _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<float, IMS, IME, JMS, JME> &,
											                     _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainTopography<float, IMS, IME, JMS, JME> &,
											                     _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<float, IMS, IME, JMS, JME> &,
											                     _In_ const WRF_Mat3DF32 &,
											                     _In_ const WRF_Mat3DF32 &,
											                     _In_ const WRF_Mat3DF32 &,
											                     _In_ const float,
											                     _In_ const float,
											                     _In_ const float)->FireTendencyMV &;
									   private:

										   /* Class member m_dRthFrTen, denotes fire Theta
										   tendency in units of mass.
										   Notice: Could have used boost::quantity<
										   si::mass,double> as an Matrix3DF64 element
										   , but I did not test manual vectorisation
										   with this type of object. Possible AoS situation.*/
										   WRF_Mat3DF32  m_fRthFrTen;

										   /* Class member m_fRqvFrTen, denotes fire QV tendency
										      in units of mass.*/
										   WRF_Mat3DF32  m_fRqvFrTen;

							 };
																				  


#include "Module_Fr_Fire_Atm_Impl.inl"
		}
	}
}

#endif /*MODULE_FR_FIRE_ATM_IMPL_H_05_15_2016*/