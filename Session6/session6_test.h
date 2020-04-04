#ifndef _SESSION_6_TEST_H
#define _SESSION_6_TEST_H

#include "session6_impl.h"

class Session6Test {
public:
    Session5Test() {
        cout << "Test object for Leetcode Session 6 problems constructed.\n";
        implObj = new Session6Impl();
    }

private:
    Session6Impl * implObj;
};

#endif