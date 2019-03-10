#include "math_impl.h"

#include <cmath>
using namespace std;

MathImpl::MathImpl() {
    cout << "Impl object for Leetcode Math problems constructed.\n";
}

// 7. Reverse Integer
int MathImpl::reverse7(int x) {
    bool isPositive = (x > 0);
    long long absX = abs(static_cast<long long>(x));
    long long result = 0;

    while (absX > 0) {
        result = result * 10 + absX % 10;
        absX /= 10;
    }

    if (result > INT_MAX) {
        return 0;
    } else {
        return (isPositive ? 1 : -1) * static_cast<int>(result);
    }
}