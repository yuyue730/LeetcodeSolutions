#ifndef _BACKTRACKING_TEST_H
#define _BACKTRACKING_TEST_H

#include "backtracking_impl.h"

#include <iostream>
using namespace std;

class BacktrackingTest {
public:
    BacktrackingTest();

    // 17. Letter Combinations of a Phone Number Test
    void letterCombinations17Test();

private:
    BacktrackingImpl * implObj;
};

#endif