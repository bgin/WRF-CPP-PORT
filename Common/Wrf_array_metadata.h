
#ifndef WRF_ARRAY_METADATA_H_
#define WRF_ARRAY_METADATA_H_

#ifndef WRF_ARRAY_METADATA_VERSION_MAJOR
#define WRF_ARRAY_METADATA_VERSION_MAJOR 1
#endif

#ifndef WRF_ARRAY_METADATA_VERSION_MINOR
#define WRF_ARRAY_METADATA_VERSION_MINOR 0
#endif

#ifndef WRF_ARRAY_METADATA_CREATE_DATE
#define WRF_ARRAY_METADATA_CREATE_DATE 20160722
#endif

/* Set this value to last date of successful  build*/
#ifndef WRF_ARRAY_METADATA_BUILD_DATE 
#define WRF_ARRAY_METADATA_BUILD_DATE 0
#endif

#include "WRF_PHYS_LIB_TYPEDEFS.h"
#include "Wrf_date_time.h"

#ifdef DEBUG_VERBOSE
#include "Wrf_debug_print.h"
#endif
namespace wrf_physics {

	namespace wrf_physics_utils {


		/*******************************************
		  Object containing container metadata info.
		  Templated on type Container_t.
		********************************************/

		template<class Container_t> 
		                       class ArrayMetaData {


							   public:

								   /************************************
								       Constructors and Destructor
								   *************************************/

								   ArrayMetaData(_In_ WRF_CPP_CONST WRF_STRING &,
									             _In_ WRF_CPP_CONST WRF_STRING &,
									             _In_ WRF_CPP_CONST WRF_STRING &,
									             _In_ WRF_CPP_CONST WRF_WSTRING &,
									             _In_ WRF_CPP_CONST WRF_ULONGLONG,
									             _In_ WRF_CPP_CONST WRF_ULONGLONG,
									             _In_ WRF_CPP_CONST WRF_STRING &);

								   ArrayMetaData(_In_ WRF_CPP_CONST ArrayMetaData &);

								   ArrayMetaData(_In_ ArrayMetaData &&);

								   ~ArrayMetaData() = WRF_CPP_DEFAULT;

								   /*********************************************
								                Member operators
								   **********************************************/

								   auto  operator=(_In_ WRF_CPP_CONST ArrayMetaData &)->ArrayMetaData &;

								   auto  operator=(_In_ ArrayMetaData &&)->ArrayMetaData &;

								   /**************************************************
								               Member functions - accessors
								   ***************************************************/

								   auto  get_container_type()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING;

								   auto  get_container_tag_type()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING;

								   auto  get_description()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING;

								   auto  get_func_address()WRF_CPP_CONST->WRF_CPP_CONST WRF_WSTRING;

								   auto  get_container_size()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

								   auto  get_container_extent()WRF_CPP_CONST->WRF_CPP_CONST WRF_ULONGLONG;

								   auto  get_primitive_type()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING;

								   auto  get_class_members()WRF_CPP_CONST->std::tuple<WRF_CPP_CONST WRF_STRING,
									                                                  WRF_CPP_CONST WRF_STRING,
									                                                  WRF_CPP_CONST WRF_STRING,
									                                                  WRF_CPP_CONST WRF_WSTRING,
									                                                  WRF_CPP_CONST WRF_ULONGLONG,
									                                                  WRF_CPP_CONST WRF_ULONGLONG,
									                                                  WRF_CPP_CONST WRF_STRING>;

								   /**********************************************
								          Member functions - class helpers
								   ***********************************************/

								   auto  class_typeID()WRF_CPP_CONST->WRF_CPP_CONST WRF_STRING;

								   auto  class_info()WRF_CPP_CONST->std::tuple<WRF_STRING, WRF_ULONGLONG, WRF_STRING>;

								   auto static class_member_names()->std::array<WRF_STRING, 7Ui64>;

								   
							   private:

								   WRF_STRING  m_container_type;

								   WRF_STRING  m_container_tag_type;

								   WRF_STRING  m_description;

								   WRF_WSTRING m_func_address;

								   WRF_ULONGLONG m_container_size;

								   WRF_ULONGLONG m_container_extent;

								   WRF_STRING m_primitive_type;




		};

							   /*********************************************
							                    Global operators
							   **********************************************/
							   template<class Container_t>
							   auto  operator<<(_In_ std::ostream &, 
								                _In_ WRF_CPP_CONST wrf_physics::wrf_physics_utils::
												                                   ArrayMetaData<Container_t> &)->std::ostream &;
												                                                                             

#include "Wrf_array_metadata.inl"
	}
}
#endif /*WRF_ARRAY_METADATA_H_*/