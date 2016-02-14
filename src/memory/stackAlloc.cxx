//
// Created by Zeling on 16/2/14.
//
#include <assert.h>
#include "stackAlloc.hpp"

using backprop::memory::stackAlloc;


stackAlloc stackAlloc::instance_;

void *stackAlloc::alloc(size_t bytes) {

    size_t cur_size = buffer_.size();
//    std::cout << "current size:" << cur_size << '\n';
//    std::cout << "size in need:" << stack_top_ + bytes;
    if (stack_top_ + bytes > cur_size) {
        buffer_.resize(cur_size>kThreshold ? cur_size+kThreshold : 2*cur_size);
    }

//    std::cout<< buffer_.size() << '\n';
//    std::cout<< stack_top_ << '\n';

    assert(stack_top_ + bytes < buffer_.size());

    size_t old_top = stack_top_;
    stack_top_ += bytes;

    return static_cast<void*>(&*buffer_.begin() + old_top);
}

void stackAlloc::dealloc(void *p) {

}
