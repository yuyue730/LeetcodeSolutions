#include "math_impl.h"

#include <cmath>
#include <string>
#include <unordered_map>
using namespace std;

MathImpl::MathImpl() {
    cout << "Impl object for Leetcode Math problems constructed.\n";
}

// 7. Reverse Integer
int MathImpl::reverse7(int x)
{
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
int MathImpl::myAtoi8(string str)
{
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
bool MathImpl::isPalindrome9(int num)
{
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
string MathImpl::intToRoman12(int num)
{
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
int MathImpl::romanToInt13(string s)
{
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

// 29. Divide Two Integers
int MathImpl::divide29(int dividend, int divisor)
{
    long long absDividend = abs(static_cast<long long>(dividend));
    long long absDivisor = abs(static_cast<long long>(divisor));

    if (absDivisor > absDividend) {
        return 0;
    }

    long long result = 0;

    while (absDividend >= absDivisor) {
        int p = 1;
        long long t = absDivisor;

        while (absDividend > (t << 1)) {
            p <<= 1;
            t <<= 1;
        }

        result += p;
        absDividend -= t;
    }

    bool isNegative = (dividend < 0) ^ (divisor < 0);

    if (isNegative) {
        result = -result;
    }

    return result > INT_MAX ? INT_MAX : result;
}

// 43. Multiply Strings
string MathImpl::multiply43(string num1, string num2)
{
    int totalLen = num1.size() + num2.size();
    vector<int> resVec(totalLen, 0);
    for (int i = num1.size() - 1; i >= 0; --i) {
        for (int j = num2.size() - 1; j >= 0; --j) {
            int pos1 = i + j, pos2 = i + j + 1;
            int val = (num1[i] - '0') * (num2[j] - '0');
            int curSum = val + resVec[pos2];

            resVec[pos1] += curSum / 10;
            resVec[pos2] = curSum % 10;
        }
    }

    string resStr = "";
    int i = 0;
    while (i < resVec.size() && resVec[i] == 0) {
        ++i;
    }
    for (; i < resVec.size(); ++i) {
        resStr.push_back('0' + resVec[i]);
    }

    return resStr == "" ? "0" : resStr;
}

// 50. Pow(x, n)
double MathImpl::myPow50(double x, int n)
{
    if (n == 0) {
        return 1;
    }
    double half = myPow50(x, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return (n > 0) ? half * half * x : half * half / x;
    }
}

// 65. Valid Number
bool MathImpl::isNumber65(string s)
{
    int left = 0, right = s.size() - 1;
    while (left <= right && s[left] == ' ') {
        ++left;
    }

    while (right >= left && s[right] == ' ') {
        --right;
    }

    if (left == right) {
        // Only one character in string
        return isdigit(s[left]);
    }

    bool isDotExist = false;
    bool isEExist = false;
    bool isDigitExist = false;

    // Process the first non space character
    if (s[left] == '.') {
        isDotExist = true;
    } else if (isdigit(s[left])) {
        isDigitExist = true;
    } else if (s[left] != '+' && s[left] != '-') {
        return false;
    }

    // Process [left + 1, right - 1]
    for (int i = left + 1; i <= right - 1; ++i) {
        if (isdigit(s[i])) {
            isDigitExist = true;
        } else if (s[i] == 'e' || s[i] == 'E') {
            if (isEExist) {
                return false;
            } else if (isDigitExist) {
                isEExist = true;
            } else {
                return false;
            }
        } else if (s[i] == '.') {
            if (isEExist || isDotExist) {
                return false;
            } else {
                isDotExist = true;
            }
        } else if (s[i] == '+' || s[i] == '-') {
            if (s[i - 1] != 'e' && s[i - 1] != 'E') {
                return false;
            }
        } else return false;
    }

    // Process right
    if (isdigit(s[right])) {
        return true;
    } else if (s[right] == '.' && !isDotExist && !isEExist && isDigitExist) {
        return true;
    } else return false;
}