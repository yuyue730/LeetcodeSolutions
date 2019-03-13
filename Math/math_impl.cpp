#include "math_impl.h"

#include <cmath>
#include <string>
#include <unordered_map>
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

// 12. Integer to Roman
string MathImpl::intToRoman12(int num) {
    const vector<pair<char, int> > romanIntPairVec = {
        make_pair('M', 1000),
        make_pair('D', 500), 
        make_pair('C', 100), 
        make_pair('L', 50), 
        make_pair('X', 10), 
        make_pair('V', 5), 
        make_pair('I', 1)
    };
    string result = "";

    for (int i = 0; i < romanIntPairVec.size(); i += 2) {
        int count = num / romanIntPairVec[i].second;

        if (count == 0) {
            continue;
        } else if (count < 4) {
            for (int j = 0; j < count; ++j) {
                result += romanIntPairVec[i].first;
            }
        } else if (count == 4) {
            result = result + romanIntPairVec[i].first + romanIntPairVec[i - 1].first;
        } if (count == 5) {
            result += romanIntPairVec[i - 1].first;
        } else if (count > 5 && count < 9) {
            result += romanIntPairVec[i - 1].first;
            for (int j = 6; j <= count; ++j) {
                result += romanIntPairVec[i].first;
            }
        } else if (count == 9) {
            result = result + romanIntPairVec[i].first + romanIntPairVec[i - 2].first;
        }

        num %= romanIntPairVec[i].second;
    }

    return result;
}

// 13. Roman to Integer
int MathImpl::romanToInt13(string s) {
    unordered_map<char, int> charIntMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    for (int i = 0; i < s.length(); ++i) {
        int curVal = charIntMap[s[i]];
        if (i == s.length() - 1 || charIntMap[s[i]] >= charIntMap[s[i + 1]]) {
            result += curVal;
        } else {
            result -= curVal;
        }
    }

    return result;
}