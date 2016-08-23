
#ifndef __WRF_MEMORY_HPP__
#define __WRF_MEMORY_HPP__

#ifndef WRF_MEMORY_VERSION_MAJOR
#define WRF_MEMORY_VERSION_MAJOR 1
#endif

#ifndef WRF_MEMORY_VERSION_MINOR
#define WRF_MEMORY_VERSION_MINOR 0
#endif

#ifndef WRF_MEMORY_CREATE_DATE
#define WRF_MEMORY_CREATE_DATE 20160804
#endif

/* Set this to successful build date */
#ifndef WRF_MEMORY_BUILD_DATE
#define WRF_MEMORY_BUILD_DATE 0
#endif

#include "MARCH.h"


#if defined (_WIN64)
#define MALLOC_ALREADY_ALIGNED 1
#else
#define MALLOC_ALREADY_ALIGNED 0
#endif

#if SIMD_INSTR_SET > 1
#define WRF_HAS_MM_MALLOC 1
#else
#define WRF_HAS_MM_MALLOC 0
#endif




namespace wrf_physics {

	namespace wrf_physics_internal {

		namespace memory {

			/**********************************************
			          Aligned Allocator Interface
			***********************************************/

			template<typename T, int N>
			             class aligned_allocator {



						 public:

							 typedef T value_type;

							 typedef T& reference;

							 typedef const T& const_reference;

							 typedef T* pointer;

							 typedef const T* const_pointer;

							 typedef size_t size_type;

							 typedef ptrdiff_t difference_type;

							 template<typename U>
							        struct rebind {

										typedef aligned_allocator<U, N> other;
							 };

									inline aligned_allocator() throw() {}
										             

									inline aligned_allocator(_In_ const aligned_allocator &) throw() {}
										                                        

									template<typename U>
									inline aligned_allocator(_In_ const aligned_allocator<U, N> &) throw() {}
										                                                

									inline ~aligned_allocator() throw() {}
										               

									inline pointer address(_In_ reference ref) { 
										return (&ref); 
									}

									inline const_pointer address(_In_ const_reference ref) const{ 
										return (&ref);
									}

									pointer allocate(size_type n, typename std::allocator<void>::const_pointer hint = 0) {

										pointer result = reinterpret_cast<pointer>(aligned_malloc(sizeof(T)* n, N));
										if (result == 0)
											throw std::bad_alloc{};
										return result;
									}

									inline void deallocate(pointer p, size_t) {

										aligned_free(p);
									}


									inline void construct(_In_ pointer p, const_reference value) {
										new (p) value_type();
									}

									inline void destroy(_In_ pointer p) {
										p->~value_type();
									}

									inline size_type max_size()const throw(){

										return (size_type(-1) / sizeof(T));
									}

									inline bool operator==(_In_ aligned_allocator &) {

										return true;
									}

									inline bool operator!=(_In_ aligned_allocator &rhs) {

										return (!operator==(rhs));
									}

			};

						 

						 inline void* aligned_malloc(size_t size, size_t alignment) {
							 
#if  WRF_HAS_MM_MALLOC
							 return _mm_malloc(size,alignment);
#elif MALLOC_ALREADY_ALIGNED
							 return malloc(size);
#elif defined (_MSC_VER)
							 return _aligned_malloc(size,alignment);
#else
							 return detail::_aligned_malloc(size, alignment);
#endif
						 }

						 inline void aligned_free(void* ptr) {

#if WRF_HAS_MM_MALLOC
							 _mm_free(ptr);
#elif MALLOC_ALREADY_ALIGNED
							   free(ptr);
#elif defined (_MSC_VER)
							 _aligned_free(ptr);
#else
							 detail::_aligned_free(ptr);
#endif

						 }


						 /********************************
						   Allocator "internal" namespace
						 **********************************/
			namespace detail {

				
				inline void* 
					          _aligned_malloc(size_t size, size_t alignment) {

								  void* result = 0;
								  void* ptr = malloc(size + alignment);
								  if (ptr != 0) {

									  result = reinterpret_cast<void*>((reinterpret_cast<size_t>(ptr)& ~(size_t(alignment - 1))) + alignment);
									  *(reinterpret_cast<void**>(result)-1) = ptr;
								  }
								  return (result);
				}

				inline void 
					          _aligned_free(void* ptr) {

								  if (ptr != 0) {

									  free(*(reinterpret_cast<void**>(ptr)-1));
								  }
					}

			}

		}
	}
}

#endif /*__WRF_MEMORY_HPP__*/