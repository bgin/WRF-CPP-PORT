
/*****************************************
 Implementation of WSM_PerfCollectors class
******************************************/

template<typename dataType_t ,
	    const WRF_INT dataSize > wrf_physics::wrf_service::wrf_wsm_perf_collectors::WSM5_PerfCollector<dataType_t, dataSize>
	                                    ::WSM5_PerfCollector() :
	m_loop_1s{ boost::extents[dataSize] },
	m_loop_1e{ boost::extents[dataSize] },
	m_loop_2s{ boost::extents[dataSize] },
	m_loop_2e{ boost::extents[dataSize] },
	m_loop_3s{ boost::extents[dataSize] },
	m_loop_3e{ boost::extents[dataSize] },
	m_loop_4s{ boost::extents[dataSize] },
	m_loop_4e{ boost::extents[dataSize] },
	m_loop_5s{ boost::extents[dataSize] },
	m_loop_5e{ boost::extents[dataSize] },
	m_record{}
	
{

											/* Zero-initialize the collectors.*/
											for (WRF_ULONGLONG i{ 0 }; i != dataSize; ++i) {

												this->m_loop_1s[i] = static_cast<dataType_t>(0);
												this->m_loop_1e[i] = static_cast<dataType_t>(0);
												this->m_loop_2s[i] = static_cast<dataType_t>(0);
												this->m_loop_2e[i] = static_cast<dataType_t>(0);
												this->m_loop_3s[i] = static_cast<dataType_t>(0);
												this->m_loop_3e[i] = static_cast<dataType_t>(0);
												this->m_loop_4s[i] = static_cast<dataType_t>(0);
												this->m_loop_4e[i] = static_cast<dataType_t>(0);
												this->m_loop_5s[i] = static_cast<dataType_t>(0);
												this->m_loop_5e[i] = static_cast<dataType_t>(0);


											}

											this->m_func_ptr = std::shared_ptr<WRF_ULONGLONG(*)()>(nullptr);
											this->m_collector_pair1 = std::make_pair(this->m_loop_1s, this->m_loop_1e);
											this->m_collector_pair2 = std::make_pair(this->m_loop_2s, this->m_loop_2e);
											this->m_collector_pair3 = std::make_pair(this->m_loop_3s, this->m_loop_3e);
											this->m_collector_pair4 = std::make_pair(this->m_loop_4s, this->m_loop_5e);
											this->m_collector_pair5 = std::make_pair(this->m_loop_5s, this->m_loop_5e);
											

										}

template<typename dataType_t,
	    const WRF_INT dataSize> auto wrf_physics::wrf_service::wrf_wsm_perf_collectors::WSM5_PerfCollector<dataType_t, dataSize>::
		                                                                                              getCollectionName()->const WRF_STRING{

	return (WRF_STRING{ "Perf_Collection: Module_mp_wsm5" });
}

template<typename dataType_t,
	const WRF_INT dataSize> auto wrf_physics::wrf_service::wrf_wsm_perf_collectors::WSM5_PerfCollector<dataType_t, dataSize>::
	                                                                                       getCollectorsNames()->const CollectorsNames{
	const CollectorsNames names;

	names.push_back(WRF_STRING{ "Module_mp_wsm5::collector_pair1" });
	names.push_back(WRF_STRING{ "Module_mp_wsm5::collector_pair2" });
	names.push_back(WRF_STRING{ "Module_mp_wsm5::collector_pair3" });
	names.push_back(WRF_STRING{ "Module_mp_wsm5::collector_pair4" });
	names.push_back(WRF_STRING{ "Module_mp_wsm5::collector_pair5" });
	

	return (names);
}

template<typename dataType_t,
	const WRF_INT dataSize> auto wrf_physics::wrf_service::wrf_wsm_perf_collectors::WSM5_PerfCollector<dataType_t, dataSize>
	                                                                                     ::createCollectorMap()->const CollectorMap{

	const CollectorMap map;
	map[getCollectorsNames().operator[](0)] = this->m_collector_pair1;
	map[getCollectorsNames().operator[](1)] = this->m_collector_pair2;
	map[getCollectorsNames().operator[](2)] = this->m_collector_pair3;
	map[getCollectorsNames().operator[](3)] = this->m_collector_pair4;
	map[getCollectorsNames().operator[](4)] = this->m_collector_pair5;

	return (map);
}

