
#ifndef WRF_PERF_COLLECTORS_H_
#define WRF_PERF_COLLECTORS_H_

#ifndef WRF_PERF_COLLECTORS_VERSION_MAJOR 
#define WRF_PERF_COLLECTORS_VERSION_MAJOR 1
#endif

#ifndef WRF_PERF_COLLECTORS_VERSION_MINOR
#define WRF_PERF_COLLECTORS_VERSION_MINOR 0
#endif

#ifndef WRF_PERF_COLLECTORS_CREATE_DATE
#define WRF_PERF_COLLECTORS_CREATE_DATE 20160705
#endif

/* set this macro  to successful build date*/
#ifndef WRF_PERF_COLLECTORS_BUILD_DATE
#define WRF_PERF_COLLECTORS_BUILD_DATE 0
#endif


#include "WRF_PHYS_LIB_TYPEDEFS.h"
#include <map>

namespace wrf_physics {

	namespace wrf_service {

		namespace wrf_wsm_perf_collectors {


			/***********************************************
			   Performance Collector for WSM5 Class
			************************************************/

			template<typename dataType_t, 
				     const WRF_INT dataSize > 
			                  struct  WSM5_PerfCollector {


				
				
				/****************************
				        local typedefs
				*****************************/
				typedef boost::multi_array<dataType_t, 1> Collector1D;
				typedef std::vector<WRF_STRING> CollectorsNames;
				typedef std::map < WRF_STRING, std::pair<Collector1D, Collector1D>> CollectorMap;

				/*************************************
				      Constructors and Destructor
				**************************************/

				WSM5_PerfCollector();
					

				~WSM5_PerfCollector() = default;

				/* Deleted special functions*/
				WSM5_PefrCollector(_In_ const WSM5_PerfCollector &) = delete;

				WSM5_PerfCollector & operator=(_In_ const WSM5_PerfCollector &) = delete;

				/**************************************************
				                 Member functions
				**************************************************/

				auto static  getCollectionName()->const WRF_STRING;

				auto  static getCollectorsNames()->const CollectorsNames;

				auto         createCollectorMap()->const CollectorMap;

				auto   getNumCollectors()->const WRF_INT;

				/* Public variables */
				/* Name denotes:
				   variable name m_loop_x
				 - std::pair<T,T>::first - start
				 - std::pair<T,T>::second - end*/


				/* Inner structure - Collector record*/

				struct CollectionRecord {

					CollectionRecord() :
					m_collector_name{ "" },
					m_function_name{ "" },
					
					m_collection_date{ "" },
					m_collection_time{ "" }
					{
						this->m_loop_loc = WRF_StdVectorInt32(5);
					}

					~CollectionRecord() = default;


					WRF_STRING m_collector_name;

					WRF_STRING m_function_name;

					WRF_StdVectorInt32 m_loop_loc;

					WRF_WSTRING m_collection_date;

					WRF_WSTRING m_collection_time;

				};
				
				Collector1D m_loop_1s;

				Collector1D m_loop_1e;

				Collector1D m_loop_2s;

				Collector1D m_loop_2e;

				Collector1D m_loop_2s;

				Collector1D m_loop_2e;

				Collector1D m_loop_3s;

				Collector1D m_loop_3e;

				Collector1D m_loop_4s;

				Collector1D m_loop_4e;

				Collector1D m_loop_5s;

				Collector1D m_loop_5e;

				std::pair<Collector1D, Collector1D>  m_collector_pair1;

				std::pair<Collector1D, Collector1D>  m_collector_pair2;

			    std::pair<Collector1D, Collector1D>  m_collector_pair3;

				std::pair<Collector1D, Collector1D>  m_collector_pair4;

				std::pair<Collector1D, Collector1D>  m_collector_pair5;

				CollectionRecord m_record;

				std::shared_ptr<WRF_ULONGLONG(*)()> m_func_ptr;

				static const WRF_INT m_nCollectors;
			};


#include "Wrf_perf_collectors.inl"
		}
	}
}



#endif /* WRF_PERF_COLLECTORS_H_02_07_16*/