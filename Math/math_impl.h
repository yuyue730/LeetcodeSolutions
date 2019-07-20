#ifndef _MATH_IMPL_H
#define _MATH_IMPL_H

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>
using namespace std;

class MathImpl {
public:
    MathImpl() {
        cout << "Impl object for Leetcode Math problems constructed.\n";
    }
    
    // 7. Reverse Integer
    int reverse7(int x) {
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
    int myAtoi8(string str) {
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
    bool isPalindrome9(int num) {
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
    string intToRoman12(int num) {
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
    int romanToInt13(string s) {
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
    int divide29(int dividend, int divisor) {
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
    string multiply43(string num1, string num2) {
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
    double myPow50(double x, int n) {
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
    bool isNumber65(string s) {
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

    // 67. Add Binary
    string addBinary67(string a, string b) {
        string result = "";
        if (a.empty() && b.empty()) {
            return result;
        }

        int nSize = max(a.size(), b.size());
        while (a.size() < nSize) {
            a.insert(a.begin(), '0');
        }
        while (b.size() < nSize) {
            b.insert(b.begin(), '0');
        }

        bool carry = false;
        for (int i = nSize - 1; i >= 0; --i) {
            if (a[i] == '1' && b[i] == '1') {
                result.insert(result.begin(), carry ? '1': '0');
                carry = true;
            } else if (a[i] == '1' || b[i] == '1') {
                result.insert(result.begin(), carry ? '0' : '1');
            } else {
                result.insert(result.begin(), carry ? '1' : '0');
                carry = false;
            }
        }

        if (carry) {
            result.insert(result.begin(), '1');
        }
        return result;
    }

    // 69. Sqrt(x)
    int mySqrt69(int x) {
        if (x <= 3) {
            return 1;
        }

        int left = 0, right = x;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x / mid >= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return right - 1;
    }

    // 166. Fraction to Recurring Decimal
    string fractionToDecimal166(int numerator, int denominator) {
        if (numerator == 0) {
            return 0;
        }
        bool isPositive = (numerator > 0) == (denominator > 0);
        string result = isPositive ? "" : "-";

        long long num_abs = abs(static_cast<long long>(numerator));
        long long den_abs = abs(static_cast<long long>(denominator));

        long long int_part = num_abs / den_abs;
        long long remain = num_abs % den_abs;
        result += to_string(int_part);

        if (remain == 0) {
            return result;
        }
        result.push_back('.');
        string decimal_part("");
        unordered_map<long long, int> remain_position_map;
        int cur_position = 0;
        while (remain != 0) {
            if (remain_position_map.find(remain) != remain_position_map.end()) {
                decimal_part.insert(remain_position_map[remain], "(");
                decimal_part.push_back(')');
                return result + decimal_part;
            }

            remain_position_map[remain] = cur_position;
            decimal_part += to_string((remain * 10) / den_abs);
            remain = (remain * 10) % den_abs;
            cur_position++;
        }

        return result + decimal_part;
    }

    // 204. Count Primes
    int countPrimes204(int n) {
        vector<bool> is_prime(n, true);
        int result = 0;
        for (int i = 2; i < n; ++i) {
            if (!is_prime[i]) {
                continue;
            }
            ++result;
            for (int j = 2; i * j < n; ++j) {
                is_prime[i * j] = false;
            }
        }

        return result;
    }

    // 241. Different Ways to Add Parentheses
    vector<int> diffWaysToCompute241(string input) {
        vector<int> result;

        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute241(input.substr(0, i));
                vector<int> right = diffWaysToCompute241(input.substr(i + 1));

                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        switch (input[i]) {
                        case '+':
                            result.push_back(left[j] + right[k]);
                            break;
                        case '-':
                            result.push_back(left[j] - right[k]);
                            break;
                        case '*':
                            result.push_back(left[j] * right[k]);
                            break;
                        default:
                            assert(false);
                        }
                    }
                }
            }
        }

        if (result.empty()) {
            result.push_back(stoi(input));
        }

        return result;
    }

    // 247. Strobogrammatic Number II
    vector<string> findStrobogrammatic247(int n) {
        return find_by_level(n, n);
    }

    vector<string> find_by_level(int cur_level, int n) {
        if (cur_level == 0) {
            return {""};
        }

        if (cur_level == 1) {
            return {"0", "1", "8"};
        }

        vector<string> lower_level_result = find_by_level(cur_level - 2, n);
        vector<string> result;

        for (int i = 0; i < lower_level_result.size(); ++i) {
            string str = lower_level_result[i];
            if (cur_level != n) {
                result.push_back("0" + str + "0");
            }
            result.push_back("1" + str + "1");
            result.push_back("6" + str + "9");
            result.push_back("8" + str + "8");
            result.push_back("9" + str + "6");
        }

        return result;
    }
};

#endif