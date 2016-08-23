#ifndef MODULE_FR_FIRE_UTIL_IMPL_H_05_25_2016
#define MODULE_FR_FIRE_UTIL_IMPL_H_05_25_2016 100

/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library Module Fire Util Implementation -  declaration.

@file Module_Fr_Fire_Util_Impl.h
@author: Bernard Gingold
@version:  1.0.0  08/05/2016
@description: Module_Fr_Fire_Util_Impl.h
*/

#include "Module_Fr_Fire_Util_Iface.h"
#include "Module_Fr_Fire_Iface.h"

namespace   wrf_physics {

	namespace  fire_fr_util {

		namespace fire_fr_util_impl {



			/*******************************************
			  struct Set Ideal Coordinates templated on
			  type T and on 12 default template arguments
			  of type WRF_ULONGLONG.
			********************************************/

			template<typename T,
				     const WRF_ULONGLONG IFDS,
					 const WRF_ULONGLONG IFDE,
					 const WRF_ULONGLONG JFDS,
					 const WRF_ULONGLONG JFDE,
					 const WRF_ULONGLONG IFMS,
					 const WRF_ULONGLONG IFME,
					 const WRF_ULONGLONG JFMS,
					 const WRF_ULONGLONG JFME,
					 const WRF_ULONGLONG IFTS,
					 const WRF_ULONGLONG IFTE,
					 const WRF_ULONGLONG JFTS,
					 const WRF_ULONGLONG JFTE >    struct   SetIdealCoord {

						
						

						 /* This function sets fake coordinates 
						     in units of meter.*/

						 auto   static   set_ideal_coord(_In_ const T,
							                             _In_ const T,
														 _Out_  wrf_physics::fire_fr_iface::FireAreaCoords<T, IFMS, IFME, JFMS, JFME> &)->void;
							                             

					};

			/***************************************
			 struct CheckMesh2Dim templated only on
			 8 default template arguments of ttype
			 WRF_ULONGLONG.
			***************************************/

			template<const WRF_ULONGLONG IDS,
				     const WRF_ULONGLONG IDE,
					 const WRF_ULONGLONG JDS,
					 const WRF_ULONGLONG JDE,
					 const WRF_ULONGLONG IMS,
					 const WRF_ULONGLONG IME,
					 const WRF_ULONGLONG JMS,
					 const WRF_ULONGLONG JME >     struct   CheckMesh2Dim {


						 /* Check mesh 2d indices 
						    Throws invalid arg exception*/
						 auto   static  check_mesh_2dim()noexcept(false)->void;

						 /* Helper functions displays memory dimensions*/
						 auto   static   mem_dimensions()noexcept(true)->void;

						 /* Helper functions display mesh dimensions */
						 auto   static   mesh_dimensions()noexcept(true)->void;


					 };

			/**********************************
			 struct CheckMesh3Dim templated on
			 12 default template arguments of
			 type WRF_ULONGLONG.
			***********************************/

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
					 const WRF_ULONGLONG JME >    struct     CheckMesh3Dim {


						 /* Check mesh 3D indices 
						    Throws exception of type
							invalid value argument.*/
						 auto   static   check_mesh_3dim()noexcept(false)->void;

						 /* Helper functions displays memory dimensions*/
						 auto   static   mem_dimensions()noexcept(true)->void;

						 /* Helper functions display mesh dimensions */
						 auto   static   mesh_dimensions()noexcept(true)->void;
					 };

			/********************************************
			  struct  SumInterp2DCells templated on type
			  T and on 16 default template arguments of
			  type WRF_ULONGLONG.
			********************************************/

			template<typename T,
				     const WRF_ULONGLONG IMS2,
					 const WRF_ULONGLONG IME2,
					 const WRF_ULONGLONG JMS2,
					 const WRF_ULONGLONG JME2,
					 const WRF_ULONGLONG ITS2,
					 const WRF_ULONGLONG ITE2,
					 const WRF_ULONGLONG JTS2,
					 const WRF_ULONGLONG JTE2,
					 const WRF_ULONGLONG IMS1,
					 const WRF_ULONGLONG IME1,
					 const WRF_ULONGLONG JMS1,
					 const WRF_ULONGLONG JME1,
					 const WRF_ULONGLONG ITS1,
					 const WRF_ULONGLONG ITE1,
					 const WRF_ULONGLONG JTS1,
					 const WRF_ULONGLONG JTE1 >     struct     SumInterpCells2D {



						 /*****************************
						        local  typedefs
						 *****************************/
						 typedef  boost::multi_array<T, 2>   Matrix2D;


						 /****************************************
						         Constructor and Destructor
						 ******************************************/

						 /* Constructor - member instantiation only.*/
						 SumInterpCells2D();

						 /* Destructor = default */
						 ~SumInterpCells2D() = default;

						 /**********************************
						        Class member functions
						 **********************************/

						 /* Sums cell values in mesh2 to
						    coarser values in mesh1*/
						 auto    sum_2d_cells(_In_ const Matrix2D &)noexcept(false)->void;

						 /* Computes: Interpolation of nodal values in mesh2 to
						              nodal values in mesh1.*/
						 auto    interpolate_2d(_In_ const WRF_ULONGLONG,
							                    _In_ const WRF_ULONGLONG,
							                    _In_ const T,
							                    _In_ const T,
							                    _In_ const T,
							                    _In_ const T,
							                    _In_ const Matrix2D &)->void;

						 /* Computes: Interpolation of nodal values in mesh2 to 
						    nodal values in mesh1. */
						 template< const WRF_ULONGLONG IDS2,
							       const WRF_ULONGLONG IDE2,
							       const WRF_ULONGLONG JDS2,
							       const WRF_ULONGLONG JDE2,
							       const WRF_ULONGLONG IDS1,
							       const WRF_ULONGLONG IDE1,
							       const WRF_ULONGLONG JDS1,
							       const WRF_ULONGLONG JDE1 > auto  interpolate_2d_cells2cells(_In_ const Matrix2D &)noexcept(false)->void;

						 /* Computes: Interpolation of nodal values in mesh2 to nodal values in mesh1.
						              Input mesh2 is coarse, output mesh1 is fine.  */
						 template< const WRF_ULONGLONG IDS2,
							       const WRF_ULONGLONG IDE2,
							       const WRF_ULONGLONG JDS2,
							       const WRF_ULONGLONG JDE2,
							       const WRF_ULONGLONG IDS1,
							       const WRF_ULONGLONG IDE1,
							       const WRF_ULONGLONG JDS1,
							       const WRF_ULONGLONG JDE1 > auto  interpolate_2d_cells2nodes(_In_ const Matrix2D &)noexcept(false)->void;

						 /* Computes: Performs interpolation.*/
						 template< const WRF_ULONGLONG IDS2,
							       const WRF_ULONGLONG IDE2,
							       const WRF_ULONGLONG JDS2,
							       const WRF_ULONGLONG JDE2,
							       const WRF_ULONGLONG IDS1,
							       const WRF_ULONGLONG IDE1,
							       const WRF_ULONGLONG JDS1,
							       const WRF_ULONGLONG JDE1 > auto  interpolate_2d_w(_In_ const WRF_ULONGLONG,
							                                                         _In_ const WRF_ULONGLONG,
							                                                         _In_ const WRF_ULONGLONG,
							                                                         _In_ const WRF_ULONGLONG,
							                                                         _In_ const WRF_ULONGLONG,
							                                                         _In_ const WRF_ULONGLONG,
							                                                         _In_ const Matrix2D &    )->void;



						 /* Class member m_v1 */

						 Matrix2D    m_V1;
					 };

			/**************************************************
			 struct Interp templated on type T and on 8 default
			 template arguments.
			**************************************************/
             template<typename T,
				      const WRF_ULONGLONG IDS,
					  const WRF_ULONGLONG IDE,
					  const WRF_ULONGLONG JDS,
					  const WRF_ULONGLONG JDE,
					  const WRF_ULONGLONG IMS,
					  const WRF_ULONGLONG IME,
					  const WRF_ULONGLONG JMS,
					  const WRF_ULONGLONG JME >   struct Interp {


						  /********************************
						  Local typedefs
						  ********************************/
						  typedef boost::multi_array<T, 2>  Matrix2D;


						  /* Computes: General interpolation in rectangular.*/
						  auto static  interp(_In_ const T,
							                  _In_ const T,
							                  _In_ const Matrix2D &)->const T;

					  };


			 /************************************************************
			   struct MeshDiff templated on type T , on default type
			   Matrix2D and on 8 default template arguments of type
			   WRF_ULONGLONG.
			 *************************************************************/

			 template<typename T,
				     const WRF_ULONGLONG IDS,
					 const WRF_ULONGLONG IDE,
					 const WRF_ULONGLONG JDS,
					 const WRF_ULONGLONG JDE,
					 const WRF_ULONGLONG IMS1,
					 const WRF_ULONGLONG IME1,
					 const WRF_ULONGLONG JMS1,
					 const WRF_ULONGLONG JME1,
			         class Matrix2D = boost::multi_array<T, 2> >  struct  MeshDiff {

                      
						 /***********************************
						       Constructor and Destructor
						 ************************************/

						 /* Default Ctor - members instantiation
						    only*/
						 MeshDiff();

						 /* Destructor = default*/
						 ~MeshDiff() = default;

						 /*********************************************
						             Member functions
						 **********************************************/

						 /* Computes: Central difference on 2d mesh.
						              One of the arguments is member
									  of class InitNoFire::m_lfn
									  */
						 auto    meshdiffc_2d(_In_ const T,
							                        _In_ const T,
							                        _In_ const Matrix2D &)->void;

						 /* Computes: One-sided difference on 2d mesh
						              One of the arguments is a member
									  of class InitNoFire::m_lfn
									  */
						 auto  static  meshdiff2d(_In_ const T,
							                      _In_ const T,
							                      _In_ const Matrix2D &,
							                      _In_ Matrix2D &,
							                      _In_ Matrix2D &,
							                      _In_ Matrix2D &,
							                      _In_ Matrix2D &)->void;


						 /* Class member variable m_diffCx*/
						 Matrix2D   m_diffCx;
						 /* Class member variable m_diffCy*/
						 Matrix2D   m_diffCy;
			 };
					  

						  
					 /**********************************************************
					   Helper  struct Array2DStats  templated on type T and
					   on 4 default template arguments of type WRF_ULONGLONG
					 ***********************************************************/
					  template<typename T,
						       const WRF_ULONGLONG ITS,
							   const WRF_ULONGLONG ITE,
							   const WRF_ULONGLONG JTS,
							   const WRF_ULONGLONG JTE  >   struct   Array2DStats {
							                        


								   /**********************************
								              local typedefs
								   ***********************************/
								   typedef boost::multi_array<T, 2> Matrix2D;


								   /*******************************
								   static function
								   ********************************/

								   /* Purpose: sums user passed array 2d.*/
								   auto   static  sum_2darray(_In_ const Matrix2D &)->const T;

								   /* Purpose: finds maximum of user passed array 2d.*/
								   auto   static  max_2darray(_In_ const Matrix2D &)->const T;

								   /* Purpose: average of user passed array 2d.*/
								   auto   static  avg_2darray(_In_ const Matrix2D &)->const T;

								   /* Purpose: sqrt of average array 2d.*/
								   auto   static  avg_2darray_vec(_In_ const Matrix2D &,
									                              _In_ const Matrix2D &)->const T;



							   };








#include "Module_Fr_Fire_Util_Impl.inl"
		}
	}
}
#endif /* MODULE_FR_FIRE_UTIL_IMPL_H_05_25_2016*/