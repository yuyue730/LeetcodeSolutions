#ifndef _MATH_TEST_H
#define _MATH_TEST_H
#include "math_impl.h"

class MathTest {
public:
    MathTest();

    // 7. Reverse Integer Test
    void reverse7Test();

private:
    MathImpl * implObj;
};

#endif