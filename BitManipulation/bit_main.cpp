// Leetcode Bit Manipulation Problems main function
#include <iostream>
#include "bit_test.h"
using namespace std;

int main() {
    cout << "Leetcode Bit Manipulation Problem Solution Application starts.\n";
    BitManipulationTest * testObj = new BitManipulationTest();
    cout << "\nTest for problems starts.\n";

    testObj->singleNumber136Test();
    testObj->singleNumber137Test();
    testObj->rangeBitwiseAnd201Test();
    testObj->missingNumber268Test();
    testObj->getSum371Test();
    return 0;
}