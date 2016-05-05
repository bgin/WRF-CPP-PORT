
#ifndef WRF_PORT_FIRE_TENDENCY_IMPL_H_05_04_16
#define WRF_PORT_FIRE_TENDENCY_IMPL_H_05_04_16 0x100

#include "wrf_port_fire_tendency_iface.h"

namespace  wrf_port_cpp{

	namespace wrf_physics_impl {


		template < typename T,
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
			const std::size_t JTE > class FireTendencyGenImpl : public wrf_port_cpp::wrf_physics_iface::FireTendencyIface < T > {


			public:




				/*******************************************************
				              Constructors and Destructor
				********************************************************/

				/* "Main" Constructor  initializes 
				   object arrays and zero-fills them*/

				FireTendencyGenImpl();

				/* Copy Constructor */

				FireTendencyGenImpl(_In_ const FireTendencyGenImpl &);

				/* Move Constructor */

				FireTendencyGenImpl(_In_ FireTendencyGenImpl &&);

				/* Destructor */
				 ~FireTendencyGenImpl() {}

				/* Class member and friend operators  */


				/* copy-assignment */
				auto   operator=(_In_ const FireTendencyGenImpl &)->FireTendencyGenImpl &;

				/* move-assignment */
				auto   operator=(_In_ FireTendencyGenImpl &&)->FireTendencyGenImpl &;

				/* arrays subscript operations */
				auto   operator()(_In_ const std::size_t, _In_ const std::size_t, _In_ const std::size_t)const->std::pair < T, T > ;

				
				 


				/***********************************************************
				                Class member functions 
				************************************************************/

				/* This function returns a const reference to 
				   m_aRthFrTen class member variable.*/
				__forceinline auto   getRthFrTen()const->boost::multi_array<T, 3> const & {
					return (this->m_aRthFrTen);
				}

				/* This function returns a const reference to
				   m_RQvFrTen class member variable.*/
				__forceinline auto   getRQvFrTen()const->boost::multi_array<T, 3> const & {
					return (this->m_aRQvFrTen);
				}

				/* main computation kernel overrides its abstract definition*/
				virtual  void  compute_fire_tendency(_In_  std::tuple<boost::multi_array<T, 2>,
					boost::multi_array<T, 2>,
					boost::multi_array<T, 2>,
					boost::multi_array<T, 2>,
					boost::multi_array<T, 2>,
					boost::multi_array<T, 2>,
					boost::multi_array<T, 3>,
					boost::multi_array<T, 3>,
					boost::multi_array<T, 3>> &,
					_In_ const T, _In_ const T, _In_ const T)override;




			private:

				/* Class member variable m_aRthFrTen, denotes fire theta 
				  tendency in  units of mass. */
				  
				boost::multi_array<T, 3> m_aRthFrTen;

				/* Class member variable m_aRQvFrTen, denotes fire Qv
				   tendency in units of mass.*/
				boost::multi_array<T, 3>  m_aRQvFrTen;


		};

			/* Primary template */

		template < typename T,
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
			const std::size_t JTE > class FireTendencySPImpl : public wrf_port_cpp::wrf_physics_iface::FireTendencyIface < T > {};

		/* double floating-point specialization 
		   for manual vectorization.*/
		
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
			const std::size_t JTE > class FireTendencySPImpl < double, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
			IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE > : public wrf_port_cpp::wrf_physics_iface::FireTendencyIface < double > {

			public:

				/***************************************************
				         Class Constructors and Destructor
				****************************************************/


				/*  Class default Constructor */
				FireTendencySPImpl();

				/* Copy Constructor */
				FireTendencySPImpl(_In_ const FireTendencySPImpl &);

				/* Move Constructor */
				FireTendencySPImpl(_In_ FireTendencySPImpl &&);

				/* Destructor = default */
				 ~FireTendencySPImpl() {}

				/*************************************************
				   Class member and friend operators
				**************************************************/

				/* copy assignment */
				auto    operator=(_In_ const FireTendencySPImpl &)->FireTendencySPImpl &;

				/* move assignment */
				auto    operator=(_In_ FireTendencySPImpl &&)->FireTendencySPImpl &;

				/* arrays subscript operations */
				auto   operator()(_In_ const std::size_t, _In_ const std::size_t, _In_ const std::size_t)const->std::pair<double,double>;

				/* overloaded operator<< */
				

				/**********************************************
				            Class member functions
				***********************************************/

				/* This function returns a const reference to
				m_aRthFrTen class member variable.*/
				auto  getRthFrTen()const->boost::multi_array<double, 3> const & {
					return (this->m_aRthFrTen);
				}

				/* This function returns a const reference to
				  m_aRQvFrTen class member variable.*/
				auto  getRQvFrTen()const->boost::multi_array<double, 3> const & {
					return (this->m_aRQvFrTen);
				}



				virtual  void  compute_fire_tendency(_In_ std::tuple<boost::multi_array<double, 2>,
					boost::multi_array<double, 2>,
					boost::multi_array<double, 2>,
					boost::multi_array<double, 2>,
					boost::multi_array<double, 2>,
					boost::multi_array<double, 2>,
					boost::multi_array<double, 3>,
					boost::multi_array<double, 3>,
					boost::multi_array<double, 3>>&,
					_In_ const double, _In_ const double, _In_ const double)override;




			private:

				/* Class member variable m_aRthFrTen, denotes fire theta
				tendency in  units of mass. */
				boost::multi_array<double, 3>  m_aRthFrTen;

				/* Class member variable m_aRQvFrTen, denotes fire Qv
				tendency in units of mass.*/
				boost::multi_array<double, 3>   m_aRQvFrTen;
		};


		template < typename T,
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
			const std::size_t JTE >		auto   operator<<(_In_ std::ostream&, _In_ const FireTendencyGenImpl<T, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
			IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE>  &)->std::ostream &;

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
			const std::size_t JTE >    auto   operator<<(_In_ std::ostream &, _In_ const FireTendencySPImpl<double, IDS, IDE, KDS, KDE, JDS, JDE, IMS,
			IME, KMS, KME, JMS, JME, ITS, ITE, KTS, KTE, JTS, JTE> &)->std::ostream &;
		                             

#include "wrf_port_fire_tendency_impl.inl"

	}
}
#endif /*WRF_PORT_FIRE_TENDENCY_IMPL_H_05_04_16 */