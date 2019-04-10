// Leetcode HashMap Problems main function
#include "hashmap_test.h"

#include <iostream>
using namespace std;

int main() {
    cout << "Leetcode HashMap Problem Solution Application starts.\n";
    HashMapTest* testObj = new HashMapTest();
    cout << "\nTest for problems starts.\n";

    testObj->findSubstring30Test();
    testObj->isValidSudoku36Test();

    return 0;
}