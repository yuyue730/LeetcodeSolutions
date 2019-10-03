#ifndef _UNION_FIND_TEST_H
#define _UNION_FIND_TEST_H

#include "union_find_impl.h"

class UnionFindTest {
public:
    UnionFindTest() {
        cout << "Test object for Leetcode Union Find problems constructed.\n";
        implObj = new UnionFindImpl();
    }

private:
    UnionFindImpl * implObj;
};

#endif