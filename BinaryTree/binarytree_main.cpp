// Leetcode Binary Tree Problems main function
#include <iostream>
#include "binarytree_test.h"
using namespace std;

int main() {
    cout << "Leetcode Binary Tree Problem Solution Application starts.\n";
    BinaryTreeTest * testObj = new BinaryTreeTest();
    cout << "\nTest for problems starts.\n";

    testObj->inorderTraversal94Test();
    testObj->generateTrees95Test();
    testObj->isValidBST98Test();
    testObj->recoverTree99Test();

    return 0;
}