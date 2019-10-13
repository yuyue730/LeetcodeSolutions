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
    void removeKdigits402Test()
    {
        cout << "402. Remove K Digits test starts.\n";
        string num = "1432219";
        cout << "1432219 => [" << implObj->removeKdigits402(num, 3) << "]\n\n";
        return;
    }

private:
    Session4Impl * implObj;
};

#endif