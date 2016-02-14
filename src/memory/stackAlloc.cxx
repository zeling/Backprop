//
// Created by Zeling on 16/2/14.
//
#include <iostream>
#include <assert.h>
#include "stackAlloc.hpp"

using backprop::memory::stackAlloc;


stackAlloc stackAlloc::instance_;

void *stackAlloc::alloc(size_t bytes) {

    size_t cur_size = buffer_.size();
    if (stack_top_ + bytes > cur_size) {
        buffer_.resize(cur_size>kThreshold ? cur_size+kThreshold : 2*cur_size);
    }

    std::cout << "size in total:" << cur_size << '\n';
    std::cout << "size used:" << stack_top_ << '\n';
    std::cout << "size in need:" << bytes << '\n';

    assert(stack_top_ + bytes < buffer_.size());

    size_t old_top = stack_top_;
    stack_top_ += bytes;

    sizes_.push_back(bytes);
    return static_cast<void*>(&*buffer_.begin() + old_top);
}

void stackAlloc::dealloc(void * /*p*/) {
    std::cout << "freeing a blk of size:" << sizes_.back() << '\n';
    stack_top_ -= sizes_.back();
    sizes_.pop_back();
}
