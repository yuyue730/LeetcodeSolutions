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

// 8. String to Integer (atoi)
int MathImpl::myAtoi8(string str) {
    if (str.empty()) {
        return 0;
    }

    int curIdx = 0;
    bool isPositive = true;
    while (curIdx < str.size() && str[curIdx] == ' ') {
        curIdx++;
    }
    if (curIdx < str.size() && (str[curIdx] == '+' || str[curIdx] == '-')) {
        isPositive = (str[curIdx] == '+');
        curIdx++;
    }

    long long resultAbs = 0;
    while (curIdx < str.size() && isdigit(str[curIdx])) {
        resultAbs = resultAbs * 10 + (str[curIdx] - '0');
        if (resultAbs > INT_MAX) {
            return isPositive ? INT_MAX : INT_MIN;
        }
        curIdx++;
    }

    return (isPositive ? 1 : -1) * static_cast<int>(resultAbs);
}

// 9. Palindrome Number
bool MathImpl::isPalindrome9(int num) {
    if (num < 0) {
        return false;
    }

    int magnitude = log10(num);
    int div = pow(10, magnitude);

    while (num > 0) {
        int left = num / div;
        int right = num % 10;
        if (left != right) {
            return false;
        }

        num = (num % div) / 10;
        div /= 100;
    }

    return true;
}