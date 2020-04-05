#ifndef _SESSION_6_TEST_H
#define _SESSION_6_TEST_H

#include "session6_impl.h"

class Session6Test {
public:
    Session6Test() {
        cout << "Test object for Leetcode Session 6 problems constructed.\n";
        implObj = new Session6Impl();
    }

    // 604. Design Compressed String Iterator Test
    void StringIterator604Test() {
        cout << "604. Design Compressed String Iterator test starts.\n";
        Session6Impl::StringIterator604 iterator("L1t1C1o1d1e1");

        cout << "Next = [" << iterator.next() << "]\n"; // return 'L'
        cout << "hasNext = [" << (iterator.hasNext() ? "True" : "False") 
            << "]\n"; // return 'True'
        cout << "Next = [" << iterator.next() << "]\n"; // return 't'
        cout << "Next = [" << iterator.next() << "]\n"; // return 'C'
        cout << "Next = [" << iterator.next() << "]\n"; // return 'o'
        cout << "Next = [" << iterator.next() << "]\n"; // return 'd'
        cout << "hasNext = [" << (iterator.hasNext() ? "True" : "False") 
            << "]\n"; // return 'True'
        cout << "Next = [" << iterator.next() << "]\n"; // return 'e'
        cout << "hasNext = [" << (iterator.hasNext() ? "True" : "False") 
            << "]\n"; // return 'False'
        cout << "Next = [" << iterator.next() << "]\n\n"; // return ' '
    }

    // 605. Can Place Flowers Test
    void canPlaceFlowers605Test() {
        cout << "605. Can Place Flowers test starts.\n";
        vector<int> nums = {1, 0, 0, 0, 1, 0, 0};
        cout << "Can plant 2 flowers = ["
            << (implObj->canPlaceFlowers605(nums, 2) ? "True" : "False")
            << "]\n\n";
    }

    // 611. Valid Triangle Number Test
    void triangleNumber611Test() {
        cout << "611. Valid Triangle Number test starts.\n";
        vector<int> nums = {1, 2, 3, 4, 5};
        int result = implObj->triangleNumber611(nums);
        cout << "Can format [" << result << "] triangles.\n\n";
    }

private:
    Session6Impl * implObj;
};

#endif