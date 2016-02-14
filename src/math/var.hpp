//
// Created by Zeling on 16/2/13.
//

#ifndef BACKPROP_VAR_HPP
#define BACKPROP_VAR_HPP

#include "propagatable.hpp"

namespace backprop {
    namespace math {

        class varImpl : public chainable {
        public:
            varImpl(double val) : val_(val), diff_(0) {}
            ~varImpl() {}
            double val_;
            double diff_;

            void propagate();
        };

        class var {
        public:

            var() : vari_(static_cast<varImpl *>(nullptr)) {}
            var(double v) : vari_(new varImpl(v)) {}
            ~var() { delete vari_; }

            double val() const { return vari_->val_; }
            double diff() const { return vari_-> diff_; }

        private:
            varImpl *vari_;

        };

    }

}


#endif //BACKPROP_VAR_HPP
