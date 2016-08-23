
/* Copyright (c) 2015, Bernard Gingold. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
C++ WRF Port Physical library Module Fire Util Implementation - implementation.

@file Module_Fr_Fire_Util_Impl.inl
@author: Bernard Gingold
@version:  1.0.0  08/05/2016
@description: Module_Fr_Fire_Util_Impl.h
*/


/****************************************************
   Implementation of struct SetIdealCoord
****************************************************/
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
	     const WRF_ULONGLONG JFTE  >   auto  wrf_physics::fire_fr_util::fire_fr_util_impl::
		                                     SetIdealCoord<T,IFDS,IFDE,JFDS,JFDE,IFMS,IFME,JFMS,JFME,
		                                                        IFTS, IFTE, JFTS, JFTE>::set_ideal_coord(_In_ const T dxf,
		                                                                                                 _In_ const T dyf,
																					                     _Out_  wrf_physics::fire_fr_iface::
																										        FireAreaCoords<T, IFMS, IFME, JFMS, JFME> &fire_coords)->void {
																					
			                                          /* Set fake coordinates in m */
												 for (WRF_ULONGLONG i{ IFTS }; i != IFTE; ++i) {
													 for (WRF_ULONGLONG j{ JFTS }; j != JFTE; ++j) {
														 /* Uniform mesh, lower left cdomain corner
														    is (0,0) */
														fire_coords.m_Fxlong[i][j] = (i - IFDS + 0.5) * dxf;
														fire_coords.m_Fylat[i][j] =  (j - JFDS + 0.5) * dyf;
													 }
												 }

		 }

/******************************************************************
           Implementation of struct CheckMesh2Dim
*******************************************************************/

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME >    auto    wrf_physics::fire_fr_util::fire_fr_util_impl::CheckMesh2Dim<IDS,IDE,JDS,JDE,IMS,IME,JMS,JME>::
		                                      check_mesh_2dim()->void {
                 
												  using namespace wrf_physics::utils_exceptions;
												  if ((IDS < IMS) || (IDE > IME) || (JDS < JMS) || (JDE > JME)){
													  mesh_dimensions();
													  mem_dimensions();
													  throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), IDS, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

												  }
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME >     auto    wrf_physics::fire_fr_util::fire_fr_util_impl::CheckMesh2Dim<IDS,IDE,JDS,JDE,IMS,IME,JMS,JME>::
		                                       mem_dimensions()->void {
							
												   std::cerr << "Memory dimensions: " << std::endl;
												   std::cerr << "IMS: " << IMS << std::endl;
												   std::cerr << "IME: " << IME << std::endl;
												   std::cerr << "JMS: " << JMS << std::endl;
												   std::cerr << "JME: " << JME << std::endl;
		 }

template<const WRF_ULONGLONG IDS,
	     const WRF_ULONGLONG IDE,
	     const WRF_ULONGLONG JDS,
	     const WRF_ULONGLONG JDE,
	     const WRF_ULONGLONG IMS,
	     const WRF_ULONGLONG IME,
	     const WRF_ULONGLONG JMS,
	     const WRF_ULONGLONG JME >      auto    wrf_physics::fire_fr_util::fire_fr_util_impl::CheckMesh2Dim<IDS,IDE,JDS,JDE,IMS,IME,JMS,JME>::
		                                        mesh_dimensions()->void {

													std::cerr << "Mesh dimensions: " << std::endl;
													std::cerr << "IDS: " << IDS << std::endl;
													std::cerr << "IDE: " << IDE << std::endl;
													std::cerr << "JDS: " << JDS << std::endl;
													std::cerr << "JDE: " << JDE << std::endl;
		 }


/***************************************************
       Implementation of struct CheckMesh3Dim
****************************************************/

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
	     const WRF_ULONGLONG JME  >   auto    wrf_physics::fire_fr_util::fire_fr_util_impl::CheckMesh3Dim<IDS,IDE,KDS,KDE,JDS,JDE,IMS,IME,
		                                      KMS, KME, JMS, JME>::check_mesh_3dim()->void {

												  using namespace wrf_physics::utils_exceptions;
												  if ((IDS < IMS) || (IDE > IME) || (JDS < JMS) || (JDE > JME) || (KDS < KME) || (KDE > KME)){
													  mesh_dimensions();
													  mem_dimensions();
													  throw Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), IDS, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
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
	     const WRF_ULONGLONG JME  >   auto    wrf_physics::fire_fr_util::fire_fr_util_impl::CheckMesh3Dim<IDS,IDE,KDS,KDE,JDS,JDE,IMS,IME,
		                                      KMS, KME, JMS, JME>::mem_dimensions()->void {
												  std::cerr << "Memory dimensions: " << std::endl;
												  std::cerr << "IMS: " << IMS << std::endl;
												  std::cerr << "IME: " << IME << std::endl;
												  std::cerr << "KMS: " << KMS << std::endl;
												  std::cerr << "KME: " << KME << std::endl;
												  std::cerr << "JMS: " << JMS << std::endl;
												  std::cerr << "JME: " << JME << std::endl;
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
	     const WRF_ULONGLONG JME >   auto       wrf_physics::fire_fr_util::fire_fr_util_impl::CheckMesh3Dim<IDS,IDE,KDS,KDE,JDS,JDE,IMS,IME,
		                                        KMS, KME, JMS, JME>::mesh_dimensions()->void {
													std::cerr << "Mesh dimensions: " << std::endl;
													std::cerr << "IDS: " << IDS << std::endl;
													std::cerr << "IDE: " << IDE << std::endl;
													std::cerr << "KDS: " << KDS << std::endl;
													std::cerr << "KDE: " << KDE << std::endl;
													std::cerr << "JDS: " << JDS << std::endl;
													std::cerr << "JDE: " << JDE << std::endl;
		 }

/***********************************************************
        Implementation of struct SumInterpCells2D
************************************************************/

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
	     const WRF_ULONGLONG JTE1 >   wrf_physics::fire_fr_util::fire_fr_util_impl::SumInterpCells2D<T,IMS2,IME2,JMS2,JME2,ITS2,ITE2,JTS2,JTE2,
		                              IMS1, IME1, JMS1, JME1, ITS1, ITE1, JTS1, JTE1>::SumInterpCells2D() :

		          m_V1{ boost::extents[IME1][JME1] } {}

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
		const WRF_ULONGLONG JTE1 >   auto    wrf_physics::fire_fr_util::fire_fr_util_impl::SumInterpCells2D<T, IMS2, IME2, JMS2, JME2, ITS2, ITE2, JTS2, JTE2,
		                                     IMS1, IME1, JMS1, JME1, ITS1, ITE1, JTS1, JTE1>::sum_2d_cells(_In_ const Matrix2D &V2)->void {
            
					/* Local variable */
			 WRF_ULONGLONG i1, i2, j1, j2, ir, jr, isz1, isz2, jsz1, jsz2, ioff, joff, ibase, jbase;
			 T t;

			 /* Check mesh dimensions and domain dimensions. */
			 CheckMesh2Dim<ITS1, ITE1, JTS1, JTE1, IMS1, IME1, JMS1, JME1>::check_mesh_2dim();
			 CheckMesh2Dim<ITS2, ITE2, JTS2, JTE2, IMS2, IME2, JMS2, JME2>::check_mesh_2dim();

			 /* Compute mesh sizes */
			 isz1 = ITE1 - ITS1 + 1;
			 jsz1 = JTE1 - JTS1 + 1;
			 isz2 = ITE2 - ITS2 + 1;
			 jsz2 = JTE2 - JTS2 + 1;

			 /* Check mesh sizes */
			 using wrf_physics::utils_exceptions;
			 if ((isz1 <= 0) || (jsz1 <= 0) || (isz2 <= 0) || (jsz2 <= 0)) {
				 std::cerr << "All mesh sizes must be positive!!" << std::endl;
				 std::cerr << "Input mesh size: " << std::endl;
				 std::cerr << "isz2: " << isz2 << std::endl;
				 std::cerr << "jsz2: " << jsz2 << std::endl;
				 std::cerr << "Output mesh size: " << std::endl;
				 std::cerr << "isz1: " << isz1 << std::endl;
				 std::cerr << "jsz1: " << jsz1 << std::endl;
				 throw utils_exceptions::Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), isz1, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
			 }
			 
			 /* Compute mesh ratios */
			 ir = isz2 / isz1;
			 jr = jsz2 / jsz1;
			 
			 if ((isz2 != isz1 * ir) || (jsz2 != jsz1 * jr)) {
				 std::cerr << "Input mesh size must be a multiple of output mesh size!!" << std::endl;
				 std::cerr << "Input mesh size: " << std::endl;
				 std::cerr << "isz2: " << isz2 << std::endl;
				 std::cerr << "jsz2: " << jsz2 << std::endl;
				 std::cerr << "Output mesh size: " << std::endl;
				 std::cerr << "isz1: " << isz1 << std::endl;
				 std::cerr << "jsz1: " << jsz1 << std::endl;
				 throw utils_exceptions::Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), isz1, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
			 }

			 for (i1 = ITS1; i != ITE1; ++i1) {
				 ibase = ITS2 + ir * (i1 - ITS1);
				 for (j1 = JTS1; j != JTE1; ++j) {
					 jbase = JTS2 + jr * (j1 - JTS1);
					 t = static_cast<T>(0);
					 for (ioff{ 0 }; ioff != ir - 1; ++ioff) {
						 i2 = ioff + ibase;
						 for (joff{ 0 }; joff != jr - 1; ++joff) {
							 j2 = joff + jbase;
							 t += this->m_V1[i2][j2];
						 }
					 }
					 this->m_V1[i1][j1] = t;
				 }
			 }
		}

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
		 const WRF_ULONGLONG JTE1 >  auto wrf_physics::fire_fr_util::fire_fr_util_impl::SumInterpCells2D<T, IMS2, IME2, JMS2, JME2, ITS2, ITE2, JTS2, JTE2,
		                                                        IMS1, IME1, JMS1, JME1, ITS1, ITE1, JTS1, JTE1>::interpolate_2d(_In_ const WRF_ULONGLONG ir,
		                                                                                                                        _In_ const WRF_ULONGLONG jr,
		                                                                                                                        _In_ const T rip2,
		                                                                                                                        _In_ const T rjp2,
		                                                                                                                        _In_ const T rip1,
		                                                                                                                        _In_ const T rjp1,
		                                                                                                                        _In_ const Matrix2D &v2)->void {
						/* Local variables*/
				WRF_ULONGLONG i1, i2, j1, j2, is, ie, js, je;
				T tx, ty, rx, ry;
				T rio, rjo;
				/* Checks mesh dimensions and domain dimensions*/
				CheckMesh2Dim<ITS1, ITE1, JTS1, JTE1, IMS1, IME1, JMS1, JME1>::check_mesh_2dim();
				CheckMesh2Dim<ITS2, ITE2, JTS2, JTE2, IMS2, IME2, JMS2, JME2>::check_mesh_2dim();
				/* Compute mesh ratios*/
				rx = static_cast<T>(1) / static_cast<T>(ir);
				ry = static_cast<T>(1) / static_cast<T>(jr);

				/* Computation loops*/
				for (i2{ ITS2 }; i2 != ITE2 - 1; ++i2) {
					rio = rip1 + ir * (i2 - rip2);
					is = std::max(ITS1, std::ceil(rio));
					ie = std::min(ITE1, std::floor(rjo) + ir);
					for (j2{ JTS2 }; j2 != JTE2 - 1; ++j2) {
						rjo = rjp1 + jr * (j2 - rjp2);
						js = std::max(JTS1, std::ceil(rjo));
						je = std::min(JTE1, std::floor(rjo) + jr);
						for (i1{ is }; i1 != ie; ++i1) {
							tx = (i1 - rio) * rx;
							for (j1{ js }; j1 != je; ++j1) {
								ty = (j1 - rjo) * rj;
								this->m_V1[i1][j1] = (static_cast<T>(1) - tx) *
									(static_cast<T>(1) - ty)      *
									v2[i2][j] + (static_cast<T>(1) - tx) * ty *
									v2[i2][j2 + 1] + tx * (static_cast<T>(1) - ty) *
									v2[i2 + 1][j2] + tx * ty * v2[i2 + 1][j2 + 1];
							}
						}
					}
				}

		 }

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
		 const WRF_ULONGLONG JTE1 >  template< const WRF_ULONGLONG IDS2,
		                                       const WRF_ULONGLONG IDE2,
		                                       const WRF_ULONGLONG JDS2,
		                                       const WRF_ULONGLONG JDE2,
		                                       const WRF_ULONGLONG IDS1,
		                                       const WRF_ULONGLONG IDE1,
		                                       const WRF_ULONGLONG JDS1,
											   const WRF_ULONGLONG JDE1 > auto wrf_physics::fire_fr_util::fire_fr_util_impl::SumInterpCells2D<T, IMS2, IME2, JMS2, JME2, ITS2, ITE2, JTS2, JTE2,
											                                                             IMS1, IME1, JMS1, JME1, ITS1, ITE1, JTS1, JTE1>::interpolate_2d_cells2cells(_In_ const Matrix2D &v2)->void {


					 WRF_ULONGLONG ir, jr, isz1, jdz1, isz2, jsz2, ip, jp, ih, jh;
					 /*Check mesh dimensions and domain dimensions*/
					 CheckMesh2Dim<IDS1, IDE1, JDS1, JDE1, IMS1, IME1, JMS1, JME1>::check_mesh_2dim();
					 CheckMesh2Dim<IDS2, IDE2, JDS2, JDE2, IMS2, IME2, JMS2, JME2>::check_mesh_2dim();

					 /*Compute mesh sizes*/
					 isz1 = IDE1 - IDS1 + 1;
					 jsz1 = JDE1 - JDS1 + 1;
					 isz2 = IDE2 - IDS2 + 1;
					 jsz2 = JDE2 - JDS2 + 1;

					 /* Check mesh sizes*/
					 if ((isz1 <= 0) || (jsz1 <= 0) || (isz2 <= 0) || (jsz2 <= )) {
						 std::cerr << "All mesh sizes must be positive!!" << std::endl;
						 std::cerr << "Input mesh size: " << std::endl;
						 std::cerr << "isz2: " << isz2 << std::endl;
						 std::cerr << "jsz2: " << jsz2 << std::endl;
						 std::cerr << "Output mesh size: " << std::endl;
						 std::cerr << "isz1: " << isz1 << std::endl;
						 std::cerr << "jsz1: " << jsz1 << std::endl;
						 throw utils_exceptions::Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), isz1, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));
					 
					 }

					 if ((isz1%isz2 != 0) || (jsz1%jsz2 != 0)) {
						 std::cerr << "Modulo values must be zero!!" << std::endl;
						 std::cerr << "Input mesh size: " << std::endl;
						 std::cerr << "isz2: " << isz2 << std::endl;
						 std::cerr << "jsz2: " << jsz2 << std::endl;
						 std::cerr << "Output mesh size: " << std::endl;
						 std::cerr << "isz1: " << isz1 << std::endl;
						 std::cerr << "jsz1: " << jsz1 << std::endl;
						 throw utils_exceptions::Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), isz1, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

					 }

					 /* Compute mesh ratios*/
					 ir = isz1 / jsz1;
					 jr = isz2 / jsz2;

					 /* Offset to the last node in the first
					    half of the cell.*/
					 ih = ir / 2;
					 jh = jr / 2;

					 /* If coarse cell center coincides with fine,  then 0, otherwise 1*/
					 ip = (ir + 1) % 2;
					 jp = (jr + 1) % 2;

					 // Call here interpolate_2d_w
					 interpolate_2d_w(ip, jp, ih, jh, ir, jr, v2);

		 }

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
		 const WRF_ULONGLONG JTE1 >  template< const WRF_ULONGLONG IDS2,
		                                       const WRF_ULONGLONG IDE2,
		                                       const WRF_ULONGLONG JDS2,
		                                       const WRF_ULONGLONG JDE2,
		                                       const WRF_ULONGLONG IDS1,
		                                       const WRF_ULONGLONG IDE1,
		                                       const WRF_ULONGLONG JDS1,
											   const WRF_ULONGLONG JDE1 >  auto wrf_physics::fire_fr_util::fire_fr_util_impl::SumInterpCells2D<T, IMS2, IME2, JMS2, JME2, ITS2, ITE2, JTS2, JTE2,
											                                                                      IMS1, IME1, JMS1, JME1, ITS1, ITE1, JTS1, JTE1>::interpolate_2d_cells2nodes(_In_ const Matrix2D &v2)->void {


						WRF_ULONGLONG ir, jr, isz1, isz2, jsz1, jsz2, ip, jp, ih, jh;

						CheckMesh2Dim<IDS1, IDE1 + 1, JDS1, JDE1 + 1, IMS1, IME1, JMS1, JME1>::check_mesh_2dim();
						CheckMesh2Dim<IDS2, IDE2, JDS2, JDE2, IMS2, IME2, JMS2, JME2>::check_mesh_2dim();

						/* Compute mesh sizes.*/
						isz1 = IDE1 - IDS1 + 1;
						jsz1 = JDE1 - JDS1 + 1;
						isz2 = IDE2 - IDS2 + 1;
						jsz2 = JDE2 - JDS2 + 1;

						/* Check mesh sizes */
						if ((isz1 <= 0) || (jsz1 <= 0) || (isz2 <= 0) || (jsz2 <= 0)) {
							std::cerr << "All mesh sizes must be positive!!" << std::endl;
							std::cerr << "Input mesh size: " << std::endl;
							std::cerr << "isz2: " << isz2 << std::endl;
							std::cerr << "jsz2: " << jsz2 << std::endl;
							std::cerr << "Output mesh size: " << std::endl;
							std::cerr << "isz1: " << isz1 << std::endl;
							std::cerr << "jsz1: " << jsz1 << std::endl;
							throw utils_exceptions::Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), isz1, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

						}

						if ((isz1%isz2 != 0) || (jsz1%jsz2 != 0)) {
							std::cerr << "Modulo values must be zero!!" << std::endl;
							std::cerr << "Input mesh size: " << std::endl;
							std::cerr << "isz2: " << isz2 << std::endl;
							std::cerr << "jsz2: " << jsz2 << std::endl;
							std::cerr << "Output mesh size: " << std::endl;
							std::cerr << "isz1: " << isz1 << std::endl;
							std::cerr << "jsz1: " << jsz1 << std::endl;
							throw utils_exceptions::Wrf_invalid_arg_except<WRF_ULONGLONG>(WRF_STRING("Invalid input: index!!"), isz1, (__LINE__ - 1), WRF_WSTRING(__FUNCTIONW__));

						}
                         
						/* Compute mesh ratios*/
						ir = isz1 / jsz1;
						jr = isz2 / jsz2;

						/* Offset of the last node in the first half of the cell.*/
						ih = (ir + 1) / 2;
						jh = (jr + 1) / 2;
						/* If coarse cell center coincides with fine,  then 0, otherwise 1*/
						ip = ir % 2;
						jp = jr % 2;
						// Call interpolate_2d_w here!!
						interpolate_2d_w(ip, jp, ih, jh, ir, jr, v2);

		  }

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
		 const WRF_ULONGLONG JTE1 >   template< const WRF_ULONGLONG IDS2,
		                                        const WRF_ULONGLONG IDE2,
		                                        const WRF_ULONGLONG JDS2,
		                                        const WRF_ULONGLONG JDE2,
		                                        const WRF_ULONGLONG IDS1,
		                                        const WRF_ULONGLONG IDE1,
		                                        const WRF_ULONGLONG JDS1,
												const WRF_ULONGLONG JDE1 > auto wrf_physics::fire_fr_util::fire_fr_util_impl::SumInterpCells2D<T, IMS2, IME2, JMS2, JME2, ITS2, ITE2, JTS2, JTE2,
												                                                                              IMS1, IME1, JMS1, JME1, ITS1, ITE1, JTS1, JTE1>::interpolate_2d_w(_In_ const WRF_ULONGLONG ip,
												                                                                                                                                                _In_ const WRF_ULONGLONG jp,
												                                                                                                                                                _In_ const WRF_ULONGLONG ih,
												                                                                                                                                                _In_ const WRF_ULONGLONG jh,
												                                                                                                                                                _In_ const WRF_ULONGLONG ir,
												                                                                                                                                                _In_ const WRF_ULONGLONG jr,
												                                                                                                                                                _In_ const Matrix2D &v2    )->void {
							 /* locals*/
							 T tx, ty, rx, ry, xoff, yoff;
							 WRF_ULONGLONG i1, i2, j1, j2, ioff, joff;
							 constexpr T halfx{ 0.5 };

							 /*executable statements*/
							 rx = static_cast<T>(ir);
							 ry = static_cast<T>(jr);
							 xoff = static_cast<T>(ip) * half;
							 yoff = static_cast<T>(jp) * half;

							 for (i2{ IDS2 }; i2 != IDE2 - 1; ++i2) {
								 for (j2{ JDS2 }; j2 != JDE2 - 1; ++j2) {
									 for (ioff{ 0 }; ioff != ir - ip; ++ioff) {
#pragma prefetch v2:1:8
#pragma prefetch v2:0:4
										 for (joff{ 0 }; joff != jr - jp; ++joff) {
											 /* Compute fine mesh index*/
											 i1 = ioff + (ih + IDS1) + ir * (i2 - IDS2);
											 j1 = joff + (jh + JDS1) + jr * (j2 - JDS2);
											 /* weights */
											 tx = (ioff + xoff) / rx;
											 ty = (joff + yoff) / ry;
											 /* Interpolation */
											 this->m_V1[i1][j1] = (static_cast<T>(1) - tx) * (static_cast<T>(1) - ty) *  
												                   v2[i2][j2]
												                + (static_cast<T>(1) - tx) * ty 
																* v2[i2][j2 + 1]
												                + tx * (static_cast<T>(1) - ty) *
																  v2[i2 + 1][j2]
												                + tx * ty * v2[i2 + 1][j2 + 1];

										 }
									 }
								 }
							 }
							 /* Extends boundary strip from the nearest
							 known.*/
							 for (ioff{ 0 }; ioff != ih - 1; ++ioff) {
#pragma  prefetch v2:0:4
#pragma  prefetch v2:1:8
								 for (j2{ JDS2 }; j2 != JDE2 - 1; ++j2) {
									 for (joff{ 0 }; joff != jr - jp; ++joff) {
										 j1 = joff + (jh + JDS1) + jr * (j2 - JDS2);
										 /* weights */
										 ty = (joff + yoff) / ry;
										 /* Interpolation*/
										 this->m_V1[IDS1 + ioff][j1] = (static_cast<T>(1) - ty) *
											                           v2[IDS2][j2] + ty * 
																	   v2[IDS2][j2 + 1];
										 this->m_V1[IDE1 - ioff][j1] = (static_cast<T>(1) - ty) *
											                           v2[IDE2][j2] + ty * 
																	   v2[IDE2][j2 + 1];
									 }
								 }
							 }
							 /* Left and right strips */
							 for (joff{ 0 }; joff != jh - 1; ++joff) {
#pragma prefetch v2:0:4
#pragma prefetch v2:1:8
								 for (i2{ IDS2 }; i2 != IDE2 - 1; ++i2) {
									 for (ioff{ 0 }; ioff != ir - ip; ++ioff) {
										 i1 = ioff + (ih + IDS1) + ir * (i2 - IDS2);
										 /* weights*/
										 tx = (ioff + xoff) / rx;
										 /* Interpolation*/
										 this->m_V1[i1][JDS1 + joff] = (static_cast<T>(1) - tx) * 
                                                                        v2[i2][JDS2] +
											                            tx * v2[i2 + 1][JDS2];
										 this->m_V1[i1][JDE1 - joff] = (static_cast<T>(1) - tx) * 
											                           v2[i2][JDE2] +
											                            tx * v2[i2 + 1][JDE2];
									 }
								 }
							 }
							 /* Extend to 4 corner squares from the nearest known.*/
							 for (ioff{ 0 }; ioff != ih - 1; ++ioff) {
#pragma  simd
#pragma  unroll(4)
								 for (joff{ 0 }; joff != jh - 1; ++joff) {
									 this->m_V1[IDS1 + ioff][JDS1 + joff] = v2[IDS2][JDS2];
									 this->m_V1[IDE1 - ioff][JDS1 + joff] = v2[IDS2][JDS2];
									 this->m_V1[IDS1 + ioff][JDE1 - joff] = v2[IDS2][JDE2];
									 this->m_V1[IDE1 - ioff][JDE1 - joff] = v2[IDE2][JDE2];
								 }
							 }

				}

				/***********************************************************************
										Implementation of struct Interp
				************************************************************************/

				template<typename T,
					const WRF_ULONGLONG IDS,
					const WRF_ULONGLONG IDE,
					const WRF_ULONGLONG JDS,
					const WRF_ULONGLONG JDE,
					const WRF_ULONGLONG IMS,
					const WRF_ULONGLONG IME,
					const WRF_ULONGLONG JMS,
					const WRF_ULONGLONG JME >  auto   wrf_physics::fire_fr_util::fire_fr_util_impl::Interp<T, IDS, IDE, JDS, JDE, IMS, IME, JMS, JME>::interp(_In_ const T x,
					                                                                                                                                          _In_ const T y,
					                                                                                                                                          _In_ const Matrix2D &v)->const T{
					WRF_ULONGLONG i, j;
					T tx, ty;

					i = std::floor(x);
					i = std::min(std::min(i, IDE), IDS);
					j = std::floor(y);
					j = std::max(std::min(j, JDE), JDS);

					tx = x - static_cast<T>(i);
					ty = y - static_cast<T>(j);

					return ((1.0 - tx) * (1.0 - ty) * v[i][j]
						+ tx * (1.0 - ty) * v[i + 1][j]
						+ (1.0 - tx) * ty * v[i][j + 1]
						+ tx * ty * v[i + 1][j + 1]);
				}

		/********************************************************************
		              Implementation of  struct MeshDiff
		**********************************************************************/

				template<typename T,
					     const WRF_ULONGLONG IDS,
					     const WRF_ULONGLONG IDE,
					     const WRF_ULONGLONG JDS,
					     const WRF_ULONGLONG JDE,
					     const WRF_ULONGLONG IMS1,
					     const WRF_ULONGLONG IME1,
					     const WRF_ULONGLONG JMS1,
					     const WRF_ULONGLONG JME1,
						 class Matrix2D = boost::multi_array<T,2> >  wrf_physics::fire_fr_util::fire_fr_util_impl::MeshDiff<T,IDS,IDE,JDS,JDE,IMS1,IME1,JMS1,JME1,
							                                         Matrix2D>::MeshDiff() :
							   m_diffCx{ boost::extents[IME1][JME1] },
							   m_diffCy{ boost::extents[IME1][JME1] } {

								                                                   /* Zero fill member arrays*/
																		 for (WRF_ULONGLONG i{ IDS }; i != IDE; ++i) {
																			 for (WRF_ULONGLONG j{ JDS }; j != JDE; ++j) {
																				 this->m_diffCx[i][j] = static_cast<T>(0);
																				 this->m_diffCy[i][j] = static_cast<T>(0);
																			 }
																		 }
							 }

						 template<typename T,
							      const WRF_ULONGLONG IDS,
							      const WRF_ULONGLONG IDE,
							      const WRF_ULONGLONG JDS,
							      const WRF_ULONGLONG JDE,
							      const WRF_ULONGLONG IMS1,
							      const WRF_ULONGLONG IME1,
							      const WRF_ULONGLONG JMS1,
							      const WRF_ULONGLONG JME1,
						          class Matrix2D = boost::multi_array<T, 2> > auto wrf_physics::fire_fr_util::fire_fr_util_impl::MeshDiff<T, IDS, IDE, JDS, JDE, IMS1, IME1, JMS1, JME1,
									                                                                                                             Matrix2D>::meshdiffc_2d(_In_ const T dx,
									                                                                                                                                     _In_ const T dy,
																																										 _In_ const Matrix2D &lfn)->void {

																/*Local variables*/
														 Matrix2D diffLx{ boost::extents[IME1][JME1] };
														 Matrix2D diffLy{ boost::extents[IME1][JME1] };
													     Matrix2D diffRx{ boost::extents[IME1][JME1] };
														 Matrix2D diffRy{ boost::extents[IME1][JME1] };

														 // Call meshdiff_2d
														 meshdiff2d(dx, dy, lfn, diffLx, diffRx, diffLy, diffRy);
														 
														 /* Notice:
														    Fortran version uses swapped loops , do j =
															 do i = , in order to iterate over rows.
															 Fortran default behaviour is column-wise order,
															 hence Fortran version would be written as follows:
															 do j =
															    do i =
																   diffCx(i,j) =
																   diffCy(i,j) =
																 enddo
															  enddo	 */
														 for (WRF_ULONGLONG i{ IDS }; i != IDE; ++i) {
#pragma prefetch diffLx:0:4
#pragma prefetch diffRx:0:4
#pragma prefetch diffLy:0:4
#pragma prefetch diffRy:0:4
#pragma ivdep
#pragma simd
#pragma unroll(4)
															 for (WRF_ULONGLONG j{ JDS }; j != JDE; ++j) {

																 this->m_diffCx[i][j] = 0.5 * (diffLx[i][j] + diffRx[i][j]);
																 this->m_diffCy[i][j] = 0.5 * (diffLy[i][j] + diffRy[i][j]);
															 }
														 }


									  }

						template<typename T,
							     const WRF_ULONGLONG IDS,
							     const WRF_ULONGLONG IDE,
							     const WRF_ULONGLONG JDS,
							     const WRF_ULONGLONG JDE,
							     const WRF_ULONGLONG IMS1,
							     const WRF_ULONGLONG IME1,
							     const WRF_ULONGLONG JMS1,
							     const WRF_ULONGLONG JME1,
						         class Matrix2D = boost::multi_array<T, 2> > auto wrf_physics::fire_fr_util::fire_fr_util_impl::MeshDiff<T, IDS, IDE, JDS, JDE, IMS1, IME1, JMS1, JME1,
									                                                                                                             Matrix2D>::meshdiff2d(_In_ const T dx,
									                                                                                                                                   _In_ const T dy,
									                                                                                                                                   _In_ const Matrix2D &lfn,
									                                                                                                                                   _In_ Matrix2D &diffLx,
									                                                                                                                                   _In_ Matrix2D &diffLy,
									                                                                                                                                   _In_ Matrix2D &diffRx,
									                                                                                                                                   _In_ Matrix2D &diffRy)->void {

												/*Local variables*/
											T tempx, tempy;
										    T dx_i{ static_cast<T>(1) / dx };
										    T dy_i{ static_cast<T>(1) / dy };

											CheckMesh2Dim<IDS, IDE + 1, JDS, JDE + 1, IMS1, IME1, JMS1, JME1>::check_mesh_2dim();

											for (WRF_ULONGLONG i{ IDS }; i != IDE - 1; ++i) {
#pragma prefetch lfn:0:4
#pragma prefetch lfn:1:8
#pragma simd
#pragma unroll(4)
												for (WRF_ULONGLONG j{ JDS }; j != JDE - 1; ++j) {
													tempx = (lfn[i][j + 1] - lfn[i][j]) * dx_i;
													diffLx[i][j + 1] = tempx;
													diffRx[i][j] = tempx;
													tempy = (lfn[i + 1][j] - lfn[i][j]) * dy_i;
													diffLy[i + 1][j] = tempy;
													diffRy[i][j] = tempy;
												}
												diffLx[IDS][j] = diffLx[IDS + 1][j];
												diffRx[IDE + 1][j] = diffRx[IDE][j];
											}

											/* Cleanup for dx.*/
											WRF_ULONGLONG j{ JDE + 1 };
											for (WRF_ULONGLONG i{ IDS }; i != IDE; ++i) {
												tempx = (lfn[i + 1][j] - lfn[i][j]) * dx_i;
												diffLx[i + 1][j] = tempx;
												diffRx[i][j] = tempx;
											}

											/* Cleanup for dy.*/
											WRF_ULONGLONG i{ IDE + 1 };
											for (WRF_ULONGLONG j{ JDS }; j != JDE; ++j) {
												tempy = (lfn[i][j + 1] - lfn[i][j]) * dy_i;
												diffLy[i][j + 1] = tempy;
												diffRy[i][j] = tempy;
											}
											diffLx[IDS][j] = diffLx[IDS + 1][j];
											diffRx[IDE + 1][j] = diffRx[IDE][j];
											for (WRF_ULONGLONG i{ IDS }; i != IDE + 1; ++i) {
												diffLy[i][JDS] = diffLy[i][JDS + 1];
												diffRy[i][JDE + 1] = diffRy[i][JDE];
											}

																																				 }

 /*******************************************************************
			 Implementation of struct Array2DStats
********************************************************************/

								 template<typename T,
									 const WRF_ULONGLONG ITS,
									 const WRF_ULONGLONG ITE,
									 const WRF_ULONGLONG JTS,
									 const WRF_ULONGLONG JTE 
									                       >  auto wrf_physics::fire_fr_util::fire_fr_util_impl::Array2DStats<T, ITS, ITE, JTS, JTE>
									                                                                                        ::sum_2darray(_In_ const Matrix2D &a)->const T{

									 T t = static_cast<T>(0);
									 WRF_ULONGLONG i, j;
#ifdef USE_OPENMP
#pragma omp parallel for private(i,j) public(a)  reduction(+:t)
									 for ( i = ITS ; i < ITE; ++i) {
										 for ( j = JTS; j < JTE; ++j) {

											 t += a[i][j];
										 }
									 }
#else
									 for ( i = ITS ; i < ITE; ++i) {
										 for (j = JTS; j < JTE; ++j) {

											 t += a[i][j];
										 }
									 }
#endif
									 return (t);

						 }

								 template<typename T,
									      const WRF_ULONGLONG ITS,
									      const WRF_ULONGLONG ITE,
									      const WRF_ULONGLONG JTS,
									      const WRF_ULONGLONG JTE
									                               >  auto  wrf_physics::fire_fr_util::fire_fr_util_impl::Array2DStats<T, ITS, ITE, JTS, JTE>
									                                                                                          ::max_2darray(_In_ const Matrix2D &a)->const T{

									 T t = static_cast<T>(0);
									 for (WRF_ULONGLONG i{ ITS }; i != ITE; ++i) {
										 for (WRF_ULONGLONG j{ JTS }; j != JTE; ++i) {
											 
											 t = std::max(a[i][j], t);
										 }
									 }
									 return (t);
								 }

								 template<typename T,
									 const WRF_ULONGLONG ITS,
									 const WRF_ULONGLONG ITE,
									 const WRF_ULONGLONG JTS,
									 const WRF_ULONGLONG JTE > auto   wrf_physics::fire_fr_util::fire_fr_util_impl::Array2DStats<T, ITS, ITE, JTS, JTE>
									                                                                                    ::avg_2darray_vec(_In_ const Matrix2D &ax,
									                                                                                                      _In_ const Matrix2D &ay)->const T{

									 T t = static_cast<T>(0);
									 for (WRF_ULONGLONG i{ ITS }; i != ITE; ++i) {
										 for (WRF_ULONGLONG j{ JTS }; j != JTE; ++j) {

											 t += std::sqrt(ax[i][j] * ax[i][j] + ay[i][j] * ay[i][j]);
										 }
									 }
									 t = t / ((ITE - ITS) * (JTE - JTS));
									 return (t);
								 }
