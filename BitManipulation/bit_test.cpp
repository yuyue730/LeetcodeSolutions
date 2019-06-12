#include "bit_test.h"

#include <iostream>
using namespace std;

BitManipulationTest::BitManipulationTest() {
    cout << "Test object for Leetcode Bit Manipulation problems constructed.\n";
    implObj = new BitManipulationImpl();
}

// 136. Single Number Test
void BitManipulationTest::singleNumber136Test() {
    cout << "136. Single Number test starts.\n";
    vector<int> nums = {4,1,2,1,2};
    cout << "Single Number = [" << implObj->singleNumber136(nums) << "]\n\n";
    return;
}

// 137. Single Number II Test
void BitManipulationTest::singleNumber137Test() {
    cout << "137. Single Number II test starts.\n";
    vector<int> nums = {0,1,0,1,0,1,99};
    cout << "Single Number = [" << implObj->singleNumber137(nums) << "]\n\n";
    return;
}