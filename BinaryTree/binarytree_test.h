#ifndef _BINARYTREE_TEST_H
#define _BINARYTREE_TEST_H

#include "binarytree_impl.h"

#include <iostream>
using namespace std;

class BinaryTreeTest {
public:
    BinaryTreeTest();

    // 94. Binary Tree Inorder Traversal Test
    void inorderTraversal94Test();
    
private:
    BinaryTreeImpl * implObj;
};

#endif