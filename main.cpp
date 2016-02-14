#include <iostream>
#include "src/math/var.hpp"
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    backprop::math::var a(1);
    backprop::math::var b(2);
    backprop::math::var *c = new backprop::math::var(3);
    delete c;
    return 0;
}