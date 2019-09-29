#ifndef _BIT_MANIPULATION_TEST
#define _BIT_MANIPULATION_TEST

#include "bit_impl.h"

#include <iostream>
using namespace std;

class BitManipulationTest {
public:
    BitManipulationTest() {
        cout << "Test object for Leetcode Bit Manipulation problems constructed.\n";
        implObj = new BitManipulationImpl();
    }

    // 136. Single Number Test
    void singleNumber136Test() {
        cout << "136. Single Number test starts.\n";
        vector<int> nums = {4,1,2,1,2};
        cout << "Single Number = [" << implObj->singleNumber136(nums) << "]\n\n";
        return;
    }

    // 137. Single Number II Test
    void singleNumber137Test() {
        cout << "137. Single Number II test starts.\n";
        vector<int> nums = {0,1,0,1,0,1,99};
        cout << "Single Number = [" << implObj->singleNumber137(nums) << "]\n\n";
        return;
    }

    // 201. Bitwise AND of Numbers Range Test
    void rangeBitwiseAnd201Test() {
        cout << "201. Bitwise AND of Numbers Range test starts.\n";
        int result = implObj->rangeBitwiseAnd201(26, 30);
        cout << "range AND = [" << result << "]\n\n";
        return;
    }

    // 268. Missing Number Test
    void missingNumber268Test() {
        cout << "268. Missing Number test.\n";
        vector<int> nums = {9,6,4,2,3,5,7,0,1};
        cout << "Missing number = [" << implObj->missingNumber268(nums) << "]\n\n";
        return;
    }

    // 371. Sum of Two Integers Test
    void getSum371Test() {
        cout << "371. Sum of Two Integers test starts.\n";
        cout << "1 + 2 = [" << implObj->getSum371(1, 2) << "]\n\n";
        return;
    }

    // 393. UTF-8 Validation Test
    void validUtf8_393Test() {
        cout << "393. UTF-8 Validation test starts.\n";
        vector<int> data = {248, 130, 1};
        cout << "Is valid = [" << implObj->validUtf8_393(data) << "]\n\n";
        return;
    }

private:
    BitManipulationImpl * implObj;
};

#endif