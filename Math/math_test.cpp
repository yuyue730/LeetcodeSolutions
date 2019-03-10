#include <iostream>
#include "math_test.h"
using namespace std;

MathTest::MathTest() {
    cout << "Test object for Leetcode Math problems constructed.\n";
    implObj = new MathImpl();
}

// 7. Reverse Integer Test
void MathTest::reverse7Test() {
    cout << "7. Reverse Integer test starts\n";

    cout << "Number 123 is reversed to be " << implObj->reverse7(123) << ".\n\n";

    return;

}