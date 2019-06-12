#ifndef _BIT_MANIPULATION_TEST
#define _BIT_MANIPULATION_TEST

#include "bit_impl.h"

#include <iostream>
using namespace std;

class BitManipulationTest {
public:
    BitManipulationTest();

    // 136. Single Number Test
    void singleNumber136Test();

private:
    BitManipulationImpl * implObj;
};

#endif