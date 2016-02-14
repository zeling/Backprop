//
// Created by Zeling on 16/2/13.
//

#ifndef BACKPROP_PROPAGATABLE_HPP
#define BACKPROP_PROPAGATABLE_HPP

#include "../memory/stackAlloc.hpp"

namespace backprop {
    namespace math {

        template <typename allocator>
        class propagatable {
        public:
            propagatable() {}
            virtual ~propagatable() {}
            virtual void propagate() = 0;

            static inline void *operator new(size_t size) {
                return allocator::instance().alloc(size);
            }

            static inline void operator delete(void *p) {
                allocator::instance().dealloc(p);
            }
        };

        /* because the memory usage happens to obey the FILO pattern */
        using chainable = propagatable<backprop::memory::stackAlloc>;
    }
}


#endif //BACKPROP_PROPAGATABLE_HPP
