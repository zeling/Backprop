//
// Created by Zeling on 16/2/14.
//

#ifndef BACKPROP_STACK_ALLOC_HPP
#define BACKPROP_STACK_ALLOC_HPP

#include <vector>

namespace backprop {
    namespace memory {

        class stackAlloc {
        public:
            static const size_t kThreshold = 2 * 1024 * 1024;
            static const size_t kInitial = 1024;


            void *alloc(size_t bytes);
            void dealloc(void *p);
            static stackAlloc &instance() { return instance_; }

            /* noncopyable */
            stackAlloc (const stackAlloc &other) = delete;
            void operator = (const stackAlloc &other) = delete;
        private:

            stackAlloc(): buffer_(kInitial), stack_top_(0) {}

            static stackAlloc instance_;
            std::vector<char> buffer_;
            std::vector<size_t> sizes_;
            size_t stack_top_;
        };

    }
}


#endif //BACKPROP_STACK_ALLOC_HPP
