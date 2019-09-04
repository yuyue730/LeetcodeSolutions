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
    testObj->isSymmetric101Test();
    testObj->levelOrder102Test();
    testObj->zigzagLevelOrder103Test();
    testObj->maxDepth104Test();
    testObj->buildTree105Test();
    testObj->buildTree106Test();
    testObj->levelOrderBottom107Test();
    testObj->sortedArrayToBST108Test();
    testObj->sortedListToBST109Test();
    testObj->isBalanced110Test();
    testObj->hasPathSum112Test();
    testObj->pathSum113Test();
    testObj->flatten114Test();
    testObj->connect116Test();
    testObj->maxPathSum124Test();
    testObj->preorderTraversal144Test();
    testObj->rightSideView199Test();
    testObj->countNodes222Test();
    testObj->invertTree226Test();
    testObj->kthSmallest230Test();
    testObj->lowestCommonAncestor235Test();
    testObj->lowestCommonAncestor236Test();
    testObj->countUnivalSubtrees250Test();
    testObj->binaryTreePaths257Test();
    testObj->closestKValues272Test();
    testObj->verticalOrder314Test();
    testObj->largestBSTSubtree333Test();

    return 0;
}