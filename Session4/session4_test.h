#ifndef _SESSION_4_TEST_H
#define _SESSION_4_TEST_H

#include "session4_impl.h"

class Session4Test 
{
public:
    Session4Test() 
    {
        cout << "Test object for Leetcode Session 4 problems constructed.\n";
        implObj = new Session4Impl();
    }

    // 402. Remove K Digits Test
    void removeKdigits402Test() {
        cout << "402. Remove K Digits test starts.\n";
        string num = "1432219";
        cout << "1432219 => [" << implObj->removeKdigits402(num, 3) << "]\n\n";
        return;
    }

    // 403. Frog Jump Test
    void canCross403Test() {
        cout << "403. Frog Jump test starts.\n";
        vector<int> nums = {0, 1, 3, 5, 6, 8, 12, 17};
        cout << "Can find = [" << implObj->canCross403(nums) << "]\n\n";
        return;
    }

    // 406. Queue Reconstruction by Height Test
    void reconstructQueue406Test() {
        cout << "406. Queue Reconstruction by Height test starts.\n";
        vector<vector<int>> people = {
            {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}
        };
        cout << "result = [";
        vector<vector<int>> result = implObj->reconstructQueue406(people);
        for (int i = 0; i < result.size(); ++i) {
            cout << "[" << result[i][0] << ", " << result[i][1] << "]"
                << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 410. Split Array Largest Sum Test
    void splitArray410Test() {
        cout << "410. Split Array Largest Sum test starts.\n";
        vector<int> nums = {7, 2, 5, 10, 8};
        cout << "Min(Max(sub array sum)) = [" << implObj->splitArray410(nums, 2) << "]\n\n";
        return;
    }

    // 412. Fizz Buzz Test
    void fizzBuzz412Test() {
        cout << "412. Fizz Buzz test starts.\n";
        vector<string> result = implObj->fizzBuzz412(15);
        cout << "result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 414. Third Maximum Number Test
    void thirdMax414Test() {
        cout << "414. Third Maximum Number test starts.\n";
        vector<int> nums = {3, 2, 1};
        cout << "Third Max = [" << implObj->thirdMax414(nums) << "].\n\n";
        return;
    }

    

private:
    Session4Impl * implObj;
};

#endif