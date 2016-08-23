#ifndef MODULE_FR_FIRE_ATM_IFACE_H_05_08_16 
#define MODULE_FR_FIRE_ATM_IFACE_H_05_08_16  100

/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library Module Fire Atm Interfaces -  declaration.

@file Module_Ff_Fire_Atm_iface.h
@author: Bernard Gingold
@version:  1.0.0  08/05/2016
@description: Module_Fr_Fire_Atm.h
*/

#include "WRF_PHYS_LIB_TYPEDEFS.h"
#include "Wrf_phys_except.h"


namespace  wrf_physics {

	namespace fire_fr_atm {

		namespace fire_fr_atm_iface {

			

			/******************************************
			  Terrain topography as 2D height map.
			  Based on boost::units::quantity<length>
			  in meters above sea level.
			*******************************************/

			template<typename T,
				     const WRF_ULONGLONG IMS,
					 const WRF_ULONGLONG IME,
					 const WRF_ULONGLONG JMS,
					 const WRF_ULONGLONG JME >  class TerrainTopography {

					 public:

						 /* Class typedefs  */
						 typedef boost::units::si::length height;

						 /*********************************************
						         Constructors and Destructor
						 **********************************************/

						 /* Default Ctor, denotes reference sea level
						    or small height perturbation <= 1.0 meter.*/
						 TerrainTopography();

						 /* Terrain Map modulated with user passed 
						    height map 2D above reference 1.0 meter*/
						 TerrainTopography(_In_ const boost::multi_array<T, 2> &);

						 /* Copy Constructor */
						 TerrainTopography(_In_ const TerrainTopography &);

						 /* Move Constructor */
						 TerrainTopography(_In_ TerrainTopography &&);

						 /* Destructor = default */
						 ~TerrainTopography() = default;

						 /********************************************
						            Class member  operators
						 *********************************************/

						 /* copy assignment */
						 auto   operator=(_In_ const  TerrainTopography &)->TerrainTopography &;

						 /* move assignment */
						 auto   operator=(_In_ TerrainTopography &&)->TerrainTopography &;

						 /* subscription implemented by operator()*/
						 auto   operator()(_In_ const WRF_ULONGLONG,
							               _In_ const WRF_ULONGLONG)const->const T;

						 /* operator add-assign , increments heigth , by passing
						    user height map 2D.*/
						 auto   operator+=(_In_ const boost::multi_array<T, 2> &)->TerrainTopography &;

						 /* operator == equality */
						 auto   operator==(_In_ const TerrainTopography &)const->const bool;

						 /* operator != inequality */
						 auto   operator!=(_In_ const TerrainTopography &)const->const bool;

						 /*******************************************************
						              Class member functions
						 ********************************************************/

						 /* This function returns const reference to member
						    variable m_aTerrainMap, must not outlive its object.*/
						 auto    getTerrainMap()const->boost::multi_array<boost::units::quantity<height, T>, 2> const &;

						 /* This function increaments Map's height 
						    at specific location*/
						 auto    increase_height(_In_ const WRF_ULONGLONG,
							                _In_ const WRF_ULONGLONG,
							                _In_ const T)->TerrainTopography &;

						 /* This function increaments Map's height
						    at specific plane location.*/
						 auto    increase_height(_In_ const WRF_ULONGLONG,
							                _In_ const WRF_ULONGLONG,
							                _In_ const WRF_ULONGLONG,
							                _In_ const WRF_ULONGLONG,
							                _In_ const boost::multi_array<T, 2> &)->TerrainTopography &;


					 private:

						 /* Class member variable m_aTerrainMap,
						    denotes 2D height map.*/
						 boost::multi_array<boost::units::quantity<height, T>, 2> m_aTerrainMap;
					 };

			/* global overloaded operator << */
			template<typename T,
				    const WRF_ULONGLONG IMS,
				    const WRF_ULONGLONG IME,
				    const WRF_ULONGLONG JMS,
				    const WRF_ULONGLONG JME > auto operator<<(_In_ std::ostream &os,
				                                          _In_ const TerrainTopography<T, IMS, IME, JMS, JME> &)->std::ostream &;




			/**********************************************************************
			  Terrain gradient class templated on the type T and on default template
			  argument Terrain initialized to type TerrainTopography. 
			  This is 3-Point gradient 3x3 implementation.
			***********************************************************************/

			template<typename T,
				    const WRF_ULONGLONG IMS,
					const WRF_ULONGLONG IME,
					const WRF_ULONGLONG JMS,
					const WRF_ULONGLONG JME,
			        class Terrain = TerrainTopography<T, IMS, IME, JMS, JME> > class TerrainGrad3P3x3 {


					public:

						/*******************************************
						              Class typedefs
						********************************************/
						typedef  boost::multi_array<T, 2> Matrix2D;


						/*********************************************
						         Constructors and Destructors
						**********************************************/


						/* Main class Constructor, initializes the
						   of object.*/
						TerrainGrad3P3x3(_In_ const Terrain &,
							             _In_ const T,
							             _In_ const T);


						/* Copy Constructor */
						TerrainGrad3P3x3(_In_ const TerrainGrad3P3x3 &);

						/* Move Constructor */
						TerrainGrad3P3x3(_In_ TerrainGrad3P3x3 &&);

						/* Class Destructor default.*/
						~TerrainGrad3P3x3() = default;

						/***********************************************
						             Class member operators.
						************************************************/

						/* copy assignment */
						auto    operator=(_In_ const TerrainGrad3P3x3 &)->TerrainGrad3P3x3 &;

						/* move assignment */
						auto    operator=(_In_ TerrainGrad3P3x3 &&)->TerrainGrad3P3x3 &;

						/* subscription realized by the operator()
						   returns immutable T,T at index (i,j)*/
						auto     operator()(_In_ const WRF_ULONGLONG,
							                _In_ const WRF_ULONGLONG)const->std::pair<const T, const T>;

						/*************************************************
						            Class member functions.
						**************************************************/

						/* This function computes Terrain gradient
						   3x3 3-point kernel.*/
						auto      compute_grad3x3()->TerrainGrad3P3x3 &;


						/* This functions returns a reference to 
						   immutable class member m_aFx.*/
						auto      getFx()const->Matrix2D const &;

						/* This functions returns a reference to
						   immutable class member m_aFy.*/
						auto      getFy()const->Matrix2D const &;

						/* This function returns copy of class member
						   m_Dx.  */
						auto      getDx()const->T;

						/* This function returns a copy of class
						   member m_Dy. */
						auto      getDy()const->T;



					private:

						/* Class variable m_TerrainMap denotes template
						   default argument of type TerrainTopography.*/
						Terrain  m_TerrainMap;

						/* Class variable m_aFx denotes 1st derivative
						   in x direction.*/
						Matrix2D  m_aFx;

						/* Class variable m_aFy denotes 1st derivative
						   in y direction.*/
						Matrix2D  m_aFy;

						/* Class variable m_dx denotes grid spacing
						   in x direction.*/
						T m_Dx;

						/* Class variable m_dy denotes grid spacing
						   in y direction.*/
						T m_Dy;

#if defined DEBUG_VERBOSE

						/* This is helper function which print actual closure(function)
						from which it was called.*/
						auto  debug_print(_In_ const WRF_STRING &,
							_In_ const WRF_INT,
							_In_ const WRF_WSTRING &)const->void;
#endif
			};

					
            template<typename T,
				    const WRF_ULONGLONG IMS,
				    const WRF_ULONGLONG IME,
				    const WRF_ULONGLONG JMS,
				    const WRF_ULONGLONG JME,
			        class Terrain  >     auto   operator<<(_In_ std::ostream &, 
						                                   _In_ const TerrainGrad3P3x3<T, IMS, IME, JMS, JME, Terrain> &)->std::ostream &;


					/*******************************************************************************
					   Terrain Gradient class templated on type T and on default template argument
					   Terrain initialized to type TerrainTopography.
					   9-Points kernel 3x3 implementation.
					********************************************************************************/
				      
					template<typename T,
						    const WRF_ULONGLONG IMS,
							const WRF_ULONGLONG IME,
							const WRF_ULONGLONG JMS,
							const WRF_ULONGLONG JME,
					        class Terrain = TerrainTopography<T, IMS, IME, JMS, JME>> class TerrainGrad8P3x3 {


								/***************************************************
								                 Class typedefs
								****************************************************/
								typedef boost::multi_array<T, 2> Matrix2D;

                            


							public:

								/************************************************
								             Constructors and Destructor
								*************************************************/


								/* "Main" class Constructor initializes object
								   state.*/
								TerrainGrad8P3x3(_In_ const Terrain &,
									             _In_ const T,
									             _In_ const T);

								/* Copy Constructor. */
								TerrainGrad8P3x3(_In_ const TerrainGrad8P3x3 &);

								/* Move Constructor. */
								TerrainGrad8P3x3(_In_ TerrainGrad8P3x3 &&);

								/* Class Destructor = default.*/
								~TerrainGrad8P3x3() = default;

								/**************************************************
								             Class member operator
								***************************************************/

								/* operator copy-assignment. */
								auto    operator=(_In_ const TerrainGrad8P3x3 &)->TerrainGrad8P3x3 &;

								/* operator move-assignment. */
								auto    operator=(_In_  TerrainGrad8P3x3 &&)->TerrainGrad8P3x3 &;


								/****************************************************
								           Class member functions
								*****************************************************/

								/* This function returns const reference to
								   member variable m_aFx. */
								auto     getFx()const->Matrix2D const &;

								/* This function returns const reference to
								  member variable m_aFy.*/
								auto     getFy()const->Matrix2D const &;

								/* This function returns const reference to
								  member variable m_aFxx. */
								auto     getFxx()const->Matrix2D const &;

								/* This function returns const reference to
								  member variable m_aFyy. */
								auto     getFyy()const->Matrix2D const &;

								/* This function returns const reference to
								  member variable m_aFxy. */
								auto     getFxy()const->Matrix2D const &;

								/* This function returns all partials packed
								   into std::tuple.*/
								auto     getAllPartials()const->std::tuple<const Matrix2D &,
									                                       const Matrix2D &,
									                                       const Matrix2D &,
									                                       const Matrix2D &,
									                                       const Matrix2D & >;

								/* This function returns object type id.*/
								auto     getTypeID()const->std::string;

								/* This function computes 8-Point gradient on 3x3
								   matrix(plane).*/
								auto     compute_grad8P3x3()->TerrainGrad8P3x3 &;


							private:

								/* Class variable m_TerrainMap, denotes 2D height
								   map of terrain.*/
								Terrain   m_TerrainMap;

								/* Class variable m_aFx, denotes x'  derivative
								   of Terrain variable.*/
								Matrix2D  m_aFx;

								/* Class variable m_aFy, denotes y' derivative
								  of Terrain variable.*/
								Matrix2D  m_aFy;

								/* Class variable m_aFxx, denotes x'' derivative
								  of Terrain variable.*/
								Matrix2D  m_aFxx;

								/* Class variable m_aFyy, denotes y'' derivative
								   of Terrain variable.*/
								Matrix2D  m_aFyy;

								/* Class variable m_aFxy, denotes x/y derivative
								   of Terrain variable.*/
								Matrix2D  m_aFxy;

								/* Class variable m_Dx, denotes dx spacing of
								   Terrain mesh.*/
								T  m_Dx;

								/* Class variable m_Dy, denotes dy spacing of
								   Terrain mesh.*/
								T  m_Dy;
#if defined DEBUG_VERBOSE
            
								/* This is helper function which print actual closure(function)
								    from which it was called.*/
								auto  debug_print(_In_ const WRF_STRING &,
									              _In_ const WRF_INT,
												  _In_ const WRF_WSTRING &)const->void;
#endif

					};

					/* overloaded operator<< , displays TerrainGrad8P3x3 object state.*/
					template<typename T,
						const WRF_ULONGLONG IMS,
						const WRF_ULONGLONG IME,
						const WRF_ULONGLONG JMS,
						const WRF_ULONGLONG JME,
					    class Terrain  >  auto   operator<<(_In_ std::ostream &,
						                                    _In_ wrf_physics::fire_fr_atm::fire_fr_atm_iface::TerrainGrad8P3x3<T, IMS, IME, JMS, JME, Terrain> &)->std::ostream &;


						/*************************************************************************
						    Class HeatFluxDensity templated on type T and on 4 arrays size
							default arguments of type WRF_ULONGLONG.
							Heat flux measured in W/m^2.
						**************************************************************************/

						template<typename T,
							    const WRF_ULONGLONG IMS,
							    const WRF_ULONGLONG IME,
							    const WRF_ULONGLONG JMS,
								const WRF_ULONGLONG JME >     class      HeatFluxDensity {


									/****************************************
									             Class typedefs
									*****************************************/

									typedef boost::multi_array<T, 2> Matrix2D;
									typedef boost::multi_array<boost::units::quantity<boost::units::si::length,T>, 2> Plane;
									typedef boost::multi_array<boost::units::quantity<boost::units::si::power, T>, 2>   HeatFlux;

                                



								public:

									/***********************************************
									            Constructor and Destructor.
									************************************************/

									/* Null Heat Flux Density. */
									HeatFluxDensity(_In_ const Plane &);

									/* "Main Class Constructor initilizes object state
									    to computed specific heat flux density."*/
									HeatFluxDensity(_In_ const Plane &,
										            _In_ const HeatFlux &);

									/* Copy Constructor .*/
									HeatFluxDensity(_In_ const HeatFluxDensity &);

									/* Move Constructor. */
									HeatFluxDensity(_In_ HeatFluxDensity &&);

									/* Destructor = default.*/
									~HeatFluxDensity() = default;


									/************************************************
									           Class member operators.
									*************************************************/

									/* operator copy-assignment.*/
									auto   operator=(_In_ const HeatFluxDensity &)->HeatFluxDensity &;

									/* operator move-assignment. */
									auto   operator=(_In_ HeatFluxDensity &&)->HeatFluxDensity &;

									/* subscription - operator()
									   only member variable m_aHeatDensity is 
									   subscripted.*/
									auto   operator()(_In_ const WRF_ULONGLONG,
										              _In_ const WRF_ULONGLONG)const->T;

									/*********************************************
									           Class member functions.
									**********************************************/

									/* This functions returns a reference to 
									   member variable  m_aPlane*/
									auto    getPlane()const->Plane &;

									/* This function returns a reference to 
									  member variable  m_HeatFlux. */
									auto    getHeatFlux()const->HeatFlux &;

									/* This function returns a reference to 
									 member variable m_aHeatDensity. */
									auto    getHeatDensity()const->Matrix2D &;



								private:

									/* Class member m_aPlane , denotes Plane upon which
									   heat flux density is measured.*/
									Plane  m_aPlane;

									/* Class member m_aHeatFlux, denotes heat flux itself.*/
									HeatFlux  m_aHeatFlux;

									/* Class member m_aHeatDensity, denotes heat flux density
									   over the specific plane. Values converted to type T.*/
									Matrix2D  m_aHeatDensity;

								};

						/* overloaded global operator<< */

						template<typename T,
							const WRF_ULONGLONG IMS,
							const WRF_ULONGLONG IME,
							const WRF_ULONGLONG JMS,
							const WRF_ULONGLONG JME >  auto   operator<<(_In_ std::ostream &,
							                                             _In_ wrf_physics::fire_fr_atm::fire_fr_atm_iface::HeatFluxDensity<T, IMS, IME, JMS, JME> &)->std::ostream &;


						/******************************************************
						   Class DryAirMass templated on parameter T and on four
						   default template arguments of type WRF_ULONLONG which
						   denote array start-end indices.
						*******************************************************/

						template<typename T,
							     const WRF_ULONGLONG IMS,
							     const WRF_ULONGLONG IME,
							     const WRF_ULONGLONG JMS,
								 const WRF_ULONGLONG JME >     class      DryAirMass {



								 public:

									 /***********************************
									            Class typedefs
									 ************************************/
									 typedef  boost::units::quantity<boost::units::si::pressure, T> AirPressure;
									 typedef  boost::multi_array<AirPressure, 2>  AirMass;
									 typedef  boost::multi_array<T, 2> PressureVals;
                                  

									 /********************************************
									           Constructors and Destructor
									 *********************************************/

									 /* "Main" class Constructor - initializes state of
									     the object with the user passed 2D map of 
										 pressure values.*/
									 DryAirMass(_In_ const PressureVals &);

									 /*  Copy Constructor */
									 DryAirMass(_In_ const DryAirMass &);

									 /*  Move Constructor */
									 DryAirMass(_In_ DryAirMass &&);

									 /*  Destructor = default. */
									 ~DryAirMass() = default;

									 /************************************************
									             Class member operators
									 *************************************************/

									 /* copy assignment */
									 auto   operator=(_In_ const DryAirMass &)->DryAirMass &;

									 /* move assignment */
									 auto   operator=(_In_ DryAirMass &&)->DryAirMass &;

									 /* subscription realized by operator()
									    which returns index at (i,j) location.*/
									 auto   operator()(_In_ const WRF_ULONGLONG,
										               _In_ const WRF_ULONGLONG)const-> const T;

									 /* operator== ,  equality between two
									    pressure regions.*/
									 auto   operator==(_In_ const DryAirMass &)const-> const bool;

									 /* operator!=, inequality between two
									    pressure regions.*/
									 auto   operator!=(_In_ const DryAirMass &)const-> const bool;

									 /* operator> , *this > rhs */
									 auto   operator>(_In_ const DryAirMass &)const-> const bool;

									 /* operator<, *this < rhs */
									 auto   operator<(_In_ const DryAirMass &)const-> const bool;

									 /****************************************
									         Class member functions
									 *****************************************/

									 /* This function returns a const reference to
									    member variable m_aAirMass2D. */
									 auto    getAirMass2D()const->AirMass const &;

								 private:

									 /* Class variable m_aAirMass2D , denotes air mass density
									    in units of Pascal (Pa).*/
									 AirMass  m_aAirMass2D;

#if defined DEBUG_VERBOSE

									 /* This is helper function which print actual closure(function)
									 from which it was called.*/
									 auto  debug_print(_In_ const WRF_STRING &,
										               _In_ const WRF_INT,
										               _In_ const WRF_WSTRING &)const->void;
#endif
								 };

						/* overloaded global operator<< */

						template<typename T,
							const WRF_ULONGLONG IMS,
							const WRF_ULONGLONG IME,
							const WRF_ULONGLONG JMS,
							const WRF_ULONGLONG JME  >  auto  operator<<(_In_ std::ostream &,
							                                             _In_ const wrf_physics::fire_fr_atm::fire_fr_atm_iface::DryAirMass<T, IMS, IME, JMS, JME>&)->std::ostream &;


#include "Module_Fr_Fire_Atm_Iface.inl"
		}
	}
}
#endif /*MODULE_FR_FIRE_ATM_IFACE_H_05_08_16*/