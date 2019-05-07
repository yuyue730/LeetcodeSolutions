// Leetcode Dynamic Programming main function
#include <iostream>
#include "dp_test.h"
using namespace std;

int main() {
    cout << "Leetcode Dynamic Programming Problem Solution Application starts.\n";
    DpTest * testObj = new DpTest();
    cout << "\nTest for problems starts.\n";

    testObj->isMatch44Test();
    testObj->uniquePaths62Test();
    testObj->minPathSum64Test();

    return 0;
}