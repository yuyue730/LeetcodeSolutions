#include "dp_test.h"

DpTest::DpTest() {
    cout << "Test object for Leetcode Dynamic Programming problems constructed.\n";
    implObj = new DpImpl();
}

// 44. Wildcard Matching Test
void DpTest::isMatch44Test() {
    cout << "44. Wildcard Matching test.\n";
    cout << "*a*b and adceb isMatch = [\n" << implObj->isMatch44("adceb", "*a*b") << "].\n\n";
    return;
}