#ifndef _MATH_TEST_H
#define _MATH_TEST_H

#include <iomanip>

#include "math_impl.h"

class MathTest {
public:
    MathTest() {
        cout << "Test object for Leetcode Math problems constructed.\n";
        implObj = new MathImpl();
    }

    // 7. Reverse Integer Test
    void reverse7Test() {
        cout << "7. Reverse Integer test starts\n";
        cout << "Number 123 is reversed to be " << implObj->reverse7(123) << ".\n\n";
        return;
    }

    // 8. String to Integer (atoi) Test
    void myAtoi8Test() {
        cout << "8. String to Integer (atoi) test starts\n";
        cout << "String '     -43' can be atoi-ed to " << implObj->myAtoi8("     -43") << ".\n\n";
        return;
    }

    // 9. Palindrome Number Test
    void isPalindrome9Test() {
        cout << "9. Palindrome Number test starts\n";
        cout << "Number 121 isPalindrome = " << implObj->isPalindrome9(121) << ".\n\n";
        return;
    }

    // 12. Integer to Roman Test
    void intToRoman12Test() {
        cout << "12. Integer to Roman test starts\n";
        cout << "Number 49 can be " << implObj->intToRoman12(49) << ".\n\n";
        return;
    }

    // 13. Roman to Integer Test
    void romanToInt13Test() {
        cout << "13. Roman to Integer test starts\n";
        cout << "Number XLIX is " << implObj->romanToInt13("XLIX") << ".\n\n";
        return;  
    }

    // 29. Divide Two Integers Test
    void divide29Test() {
        cout << "29. Divide Two Integers test starts\n";
        cout << "16 / 3 = " << implObj->divide29(16, 3) << ".\n\n";
        return;
    }

    // 43. Multiply Strings Test
    void multiply43Test() {
        cout << "43. Multiply Strings test starts\n";
        cout << "123 * 456 = [" << implObj->multiply43("123", "456") << "].\n\n";
        return;
    }

    // 50. Pow(x, n) Test
    void myPow50Test() {
        cout << "50. Pow(x, n) test starts.\n";
        cout << "2.1^3 = [" << setprecision(5) << implObj->myPow50(2.1, 3) << "]\n\n";
        return;
    }

    // 65. Valid Number Test
    void isNumber65Test() {
        cout << "65. Valid Number test starts.\n";

        cout << "'0' is valid = " << (implObj->isNumber65("0") ? "True" : "False") << ".\n";
        cout << "' 0.1' is valid = " << (implObj->isNumber65(" 0.1") ? "True" : "False") << ".\n";
        cout << "'abc' is valid = " << (implObj->isNumber65("abc") ? "True" : "False") << ".\n";
        cout << "'1 a' is valid = " << (implObj->isNumber65("1 a") ? "True" : "False") << ".\n";
        cout << "'2e10' is valid = " << (implObj->isNumber65("2e10") ? "True" : "False") << ".\n";
        cout << "'-90e3' is valid = " << (implObj->isNumber65("-90e3") ? "True" : "False") << ".\n";
        cout << "'1e' is valid = " << (implObj->isNumber65("1e") ? "True" : "False") << ".\n";
        cout << "' 6e-1' is valid = " << (implObj->isNumber65(" 6e-1") ? "True" : "False") << ".\n";
        cout << "' 99e2.5' is valid = " << (implObj->isNumber65(" 99e2.5") ? "True" : "False") << ".\n";
        cout << "'53.5e93' is valid = " << (implObj->isNumber65("53.5e93") ? "True" : "False") << ".\n";
        cout << "' --6' is valid = " << (implObj->isNumber65(" --6") ? "True" : "False") << ".\n";
        cout << "'-+3' is valid = " << (implObj->isNumber65("-+3") ? "True" : "False") << ".\n";
        cout << "'95a54e53' is valid = " << (implObj->isNumber65("95a54e53") ? "True" : "False") << ".\n";

        return;
    }

    // 67. Add Binary Test
    void addBinary67Test() {
        cout << "67. Add Binary test starts.\n";
        cout << "a = '1010', b = '1011' will add up to " << implObj->addBinary67("1010", "1011") << "\n\n";
        return;
    }

    // 69. Sqrt(x) Test
    void mySqrt69Test() {
        cout << "69. Sqrt(x) test starts.\n";
        cout << "sqrt(8) = " << implObj->mySqrt69(10) << "\n\n";
        return;
    }

    // 166. Fraction to Recurring Decimal Test
    void fractionToDecimal166Test() {
        cout << "166. Fraction to Recurring Decimal test starts.\n";
        cout << "1/2 = [" << implObj->fractionToDecimal166(1, 2) << "]\n";
        cout << "2/1 = [" << implObj->fractionToDecimal166(2, 1) << "]\n";
        cout << "2/3 = [" << implObj->fractionToDecimal166(2, 3) << "]\n";
        return;
    }

    // 204. Count Primes Test
    void countPrimes204Test() {
        cout << "204. Count Primes test starts.\n";
        cout << "10 prime count = [" << implObj->countPrimes204(10) << "]\n\n";
        return;
    }

    // 241. Different Ways to Add Parentheses Test
    void diffWaysToCompute241Test() {
        cout << "241. Different Ways to Add Parentheses test starts.\n";
        cout << "2*3-4*5 = [";
        vector<int> result = implObj->diffWaysToCompute241("2*3-4*5");
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

private:
    MathImpl * implObj;
};

#endif