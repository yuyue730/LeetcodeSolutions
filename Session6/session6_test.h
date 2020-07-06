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

    // 616. Add Bold Tag in String Test
    void addBoldTag616Test() {
        cout << "616. Add Bold Tag in String test starts.\n";
        string str = "aaabbcc";
        vector<string> dict = {"aaa", "aab", "bc"};
        string result = implObj->addBoldTag616(str, dict);
        cout << "Result string = [" << result << "]\n\n";
    }

    // 617. Merge Two Binary Trees Test
    void mergeTrees617Test() {
        cout << "617. Merge Two Binary Trees test starts.\n";
        TreeNode *t1 = new TreeNode(1);
        TreeNode *cur = t1;
        cur->left = new TreeNode(3); cur->right = new TreeNode(2);
        cur = cur->left; cur->left = new TreeNode(5);

        TreeNode *t2 = new TreeNode(2);
        cur = t2;
        cur->left = new TreeNode(1); cur->right = new TreeNode(3);
        cur = t2->left; cur->right = new TreeNode(4);
        cur = t2->right; cur->right = new TreeNode(7);

        TreeNode *result = implObj->mergeTrees617(t1, t2);
        cout << "Please exam the result tree [" << result->val << "]\n\n";
    }

    // 621. Task Scheduler Test
    void leastInterval621Test() {
        cout << "621. Task Scheduler test starts.\n";
        vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B', 'C'};
        int result = implObj->leastInterval621(tasks, 2);
        cout << "Need to have [" << result << "] sessions.\n\n";
    }

    // 622. Design Circular Queue Test
    void MyCircularQueue622Test() {
        cout << "622. Design Circular Queue test starts.\n";
        Session6Impl::MyCircularQueue622* obj 
            = new Session6Impl::MyCircularQueue622(3);
        bool param_1 = obj->enQueue(3);
        cout << "Enqueue is [" << (param_1 ? "True" : "False") << "]\n";
        bool param_2 = obj->deQueue();
        cout << "Dequeue is [" << (param_2 ? "True" : "False") << "]\n";
        int param_3 = obj->Front();
        cout << "Front is [" << param_3 << "]\n";
        int param_4 = obj->Rear();
        cout << "Rear is [" << param_4 << "]\n";
        bool param_5 = obj->isEmpty();
        cout << "isEmpty is [" << (param_5 ? "True" : "False") << "]\n";
        bool param_6 = obj->isFull();
        cout << "isFull is [" << (param_4 ? "True" : "False") << "]\n\n";
    }

    // 623. Add One Row to Tree Test
    void addOneRow623Test() {
        cout << "623. Add One Row to Tree test starts.\n";
        TreeNode * root = new TreeNode(4);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);
        cur = cur->left;
        cur->left = new TreeNode(3); cur->right = new TreeNode(1);

        TreeNode * result = implObj->addOneRow623(root, 1, 3);
        cout << "<v, d> = <1, 3> will result in [" << result->val << "]\n\n";
    }

    // 624. Maximum Distance in Arrays Test
    void maxDistance624Test() {
        cout << "624. Maximum Distance in Arrays test starts.\n";
        vector<vector<int>> arrays = {
            {1, 2, 3},
            {4, 5},
            {1, 2, 3}
        };
        int result = implObj->maxDistance624(arrays);
        cout << "Max Distance = [" << result << "]\n\n";
    }

    // 625. Minimum Factorization Test
    void smallestFactorization625Test() {
        cout << "625. Minimum Factorization test starts.\n";
        int result = implObj->smallestFactorization625(48);
        cout << "48 will generate [" << result << "]\n\n";
    }

    // 628. Maximum Product of Three Numbers Test
    void maximumProduct628Test() {
        cout << "628. Maximum Product of Three Numbers test starts.\n";
        vector<int> nums = {1, 2, 3, 4};
        int result = implObj->maximumProduct628(nums);
        cout << "{1,2,3,4} will generate max product = [" << result << "]\n\n";
    }

    // 629. K Inverse Pairs Array Test
    void kInversePairs629Test() {
        cout << "629. K Inverse Pairs Array test starts.\n";
        int result = implObj->kInversePairs629(1000, 1000);
        cout << "(1000, 1000) will result in [" << result << "]\n\n";
    }

    // 630. Course Schedule III Test
    void scheduleCourse630Test() {
        cout << "630. Course Schedule III test starts.\n";
        vector<vector<int>> courses = {
            {100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
        int result = implObj->scheduleCourse630(courses);
        cout << "Can take a total of [" << result << "] courses.\n\n";
    }

    // 633. Sum of Square Numbers Test
    void judgeSquareSum633Test() {
        cout << "633. Sum of Square Numbers test starts.\n";
        bool result = implObj->judgeSquareSum633(5);
        cout << "Can 5 be judged by square sum = [" << (result ? "True" : "False")
            << "]\n\n";
    }

    // 632. Smallest Range Covering Elements from K Lists Test
    void smallestRange632Test() {
        cout << "632. Smallest Range Covering Elements from K Lists test starts.\n";
        vector<vector<int>> nums = {
            {4,10,15,24,26},
            {0,9,12,20},
            {5,18,22,30}};
        vector<int> result = implObj->smallestRange632(nums);
        cout << "Smallest range =[" << result[0] << "," << result[1] << "]\n\n";
    }

    // 634. Find the Derangement of An Array Test
    void findDerangement634Test() {
        cout << "634. Find the Derangement of An Array test starts.\n";
        int result = implObj->findDerangement634(3);
        cout << "3 will have derangements = [" << result << "]\n\n";
    }

    // 635. Design Log Storage System Test
    void LogSystem635Test() {
        cout << "635. Design Log Storage System test starts.\n";
        Session6Impl::LogSystem635 logSys;
        logSys.put(1, "2019:01:02:10:17:10");
        logSys.put(2, "2019:02:03:12:20:15");
        logSys.put(3, "2018:12:27:23:14:12");
        logSys.put(4, "2018:12:23:21:15:13");
        vector<int> result = logSys.retrieve("2018:12:24:10:00:00",
            "2019:02:23:12:26:14", "Minute");
        cout << "Retrieved ids are [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

    // 637. Average of Levels in Binary Tree Test
    void averageOfLevels637Test() {
        cout << "637. Average of Levels in Binary Tree test starts.\n";
        TreeNode * root = new TreeNode(3);
        TreeNode * cur = root;
        cur->left = new TreeNode(9);  cur->right = new TreeNode(20);
        cur = cur->right;
        cur->left = new TreeNode(15);  cur->right = new TreeNode(7);
        vector<double> result = implObj->averageOfLevels637(root);
        cout << "Level average result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

    // 638. Shopping Offers Test
    void shoppingOffers638Test() {
        cout << "638. Shopping Offers test starts.\n";
        vector<int> price = {2, 5};
        vector<vector<int>> special = {
            {3, 0, 5}, {1, 2, 10}};
        vector<int> needs = {3, 2};
        int result = implObj->shoppingOffers638(price, special, needs);
        cout << "Best offer price is [" << result << "]\n\n";
    }

    // 641. Design Circular Deque Test
    void MyCircularDeque641Test() {
        cout << "641. Design Circular Deque test starts.\n";
        Session6Impl::MyCircularDeque641 circularDeque(3);
        cout << "Can insert last 1 = [" << (circularDeque.insertLast(1) ? "True" : "False") 
            << "]\n";
        cout << "Can insert last 2 = [" << (circularDeque.insertLast(1) ? "True" : "False") 
            << "]\n";
        cout << "Can insert front 3 = [" << (circularDeque.insertFront(3) ? "True" : "False") 
            << "]\n";
        cout << "Can insert front 4 = [" << (circularDeque.insertFront(4) ? "True" : "False") 
            << "]\n";
        cout << "Get Rear = [" << circularDeque.getRear() << "]\n";
        cout << "Is Full = [" << (circularDeque.isFull() ? "True" : "False") << "]\n";
        cout << "Delete last = [" << (circularDeque.deleteLast() ? "True" : "False")
            << "]\n";
        cout << "Can insert front 4 = [" << (circularDeque.insertFront(4) ? "True" : "False")
            << "]\n";
        cout << "Get front = [" << circularDeque.getFront() << "]\n\n";
    }

    // 642. Design Search Autocomplete System Test
    void AutocompleteSystem642Test() {
        cout << "642. Design Search Autocomplete System test starts.\n";
        vector<string> sentences = {
            "i love you", "island", "ironman", "i love leetcode"};
        vector<int> times = {5, 3, 2, 2};
        Session6Impl::AutocompleteSystem642 as(sentences, times);
        vector<string> result1 = as.input('i');
        cout << "Input i result = [";
        for (int i = 0; i < result1.size(); ++i) {
            cout << result1[i] << ((i == result1.size() - 1) ? "" : ", ");
        }
        cout << "].\n";
        vector<string> result2 = as.input(' ');
        cout << "Input ' ' result = [";
        for (int i = 0; i < result2.size(); ++i) {
            cout << result2[i] << ((i == result2.size() - 1) ? "" : ", ");
        }
        cout << "].\n\n";
        return;
    }

    // 643. Maximum Average Subarray I Test
    void findMaxAverage643Test() {
        cout << "643. Maximum Average Subarray I test starts.\n";
        vector<int> nums = {1, 12, -5, -6, 50, 3};
        double result = implObj->findMaxAverage643(nums, 4);
        cout << "Max Average = [" << result << "]\n\n";
    }

    // 644. Maximum Average Subarray II Test
    void findMaxAverage644Test() {
        cout << "644. Maximum Average Subarray II test starts.\n";
        vector<int> nums = {1, 12, -5, -6, 50, 3};
        double result = implObj->findMaxAverage644(nums, 4);
        cout << "Max Average II = [" << result << "]\n\n";
    }

    // 645. Set Mismatch Test
    void findErrorNums645Test() {
        cout << "645. Set Mismatch test starts.\n";
        vector<int> nums = {1, 2, 2, 4};
        vector<int> result = implObj->findErrorNums645(nums);
        cout << "Missing numbers are [" << result[0] << ", " << result[1] << "]\n\n";
    }

    // 646. Maximum Length of Pair Chain Test
    void findLongestChain646Test() {
        cout << "646. Maximum Length of Pair Chain test starts.\n";
        vector<vector<int>> pairs = {
            {1,2}, {2, 3}, {3, 4}
        };
        cout << "Max # of chains = [" << implObj->findLongestChain646(pairs) 
            << "]\n\n";
    }

    // 647. Palindromic Substrings Test
    void countSubstrings647Test() {
        cout << "647. Palindromic Substrings test starts.\n";
        int result = implObj->countSubstrings647("aaa");
        cout << "aaa will have [" << result << "] palidromic substrings.\n\n";
    }

    // 648. Replace Words Test
    void replaceWords648Test() {
        cout << "648. Replace Words test starts.\n";
        vector<string> dict = {"cat", "bat", "rat"};
        string sentence = "the cattle was rattled by the battery";
        string result = implObj->replaceWords648(dict, sentence);
        cout << "[the cattle was rattled by the battery] converts to [" << result
            << "]\n\n";
    }

    // 649. Dota2 Senate Test
    void predictPartyVictory649Test() {
        cout << "649. Dota2 Senate test starts.\n";
        string senate = "RDD";
        cout << "RDD will generate victory side as [" << 
            implObj->predictPartyVictory649(senate) << "]\n\n";
    }

    // 650. 2 Keys Keyboard Test
    void minSteps650Test() {
        cout << "650. 2 Keys Keyboard test starts.\n";
        cout << "12 A's will need [" << implObj->minSteps650(12) << "] steps.\n\n";
    }

    // 651. 4 Keys Keyboard Test
    void maxA651Test() {
        cout << "651. 4 Keys Keyboard test starts.\n";
        cout << "5 will have maximal [" << implObj->maxA651(5) << "] A's.\n\n";
    }

    // 652. Find Duplicate Subtrees Test
    void findDuplicateSubtrees652Test() {
        cout << "652. Find Duplicate Subtrees test starts.\n";
        TreeNode* root = new TreeNode(1);
        TreeNode* cur = root;
        cur->left = new TreeNode(2); cur->right = new TreeNode(3);
        cur = cur->left; cur->left = new TreeNode(4);
        cur = root->right;
        cur->left = new TreeNode(2); cur->right = new TreeNode(4);
        cur = cur->left; cur->left = new TreeNode(4);
        vector<TreeNode*> result = implObj->findDuplicateSubtrees652(root);
        cout << "Please exam the following results [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i]->val << ((i == result.size() - 1) ? "" :", ");
        }
        cout << "]\n\n";
    }

    // 653. Two Sum IV - Input is a BST Test
    void findTarget653Test() {
        cout << "653. Two Sum IV - Input is a BST test starts.\n";
        TreeNode* root = new TreeNode(5);
        TreeNode* cur = root;
        cur->left = new TreeNode(3); cur->right = new TreeNode(6);
        cur = cur->left;
        cur->left = new TreeNode(2); cur->right = new TreeNode(4);
        root->right->right = new TreeNode(7);
        cout << "Find 9 = [" << (implObj->findTarget653(root, 9) ? "True" : "False")
            << "].\n\n";
    }

    // 654. Maximum Binary Tree Test
    void constructMaximumBinaryTree654Test() {
        cout << "654. Maximum Binary Tree test starts.\n";
        vector<int> nums = {3, 2, 1, 6, 0, 5};
        TreeNode* result = implObj->constructMaximumBinaryTree654(nums);
        cout << "Please exma the result tree [" << result->val << "]\n\n";
    }

    // 656. Coin Path Test
    void cheapestJump656Test() {
        cout << "656. Coin Path test starts.\n";
        vector<int> A = {1, 2, 4, -1, 2};
        int B = 2;
        vector<int> result = implObj->cheapestJump656(A, B);
        cout << "Cheapest jump path = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" :", ");
        }
        cout << "]\n\n";
    }

    // 657. Robot Return to Origin Test
    void judgeCircle657Test() {
        cout << "657. Robot Return to Origin test starts.\n";
        cout << "UD will have result = [" 
            << (implObj->judgeCircle657("UD") ? "True" : "False") << "]\n\n";
    }

    // 658. Find K Closest Elements Test
    void findClosestElements658Test() {
        cout << "658. Find K Closest Elements test starts.\n";
        // vector<int> arr = {1, 2, 3, 4, 5};
        // vector<int> result = implObj->findClosestElements658(arr, 4, 3);
        vector<int> arr = {0,0,1,2,3,3,4,7,7,8};
        vector<int> result = implObj->findClosestElements658(arr, 3, 5);
        cout << "K cloest elements are [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" :", ");
        }
        cout << "]\n\n";
    }

    // 659. Split Array into Consecutive Subsequences Test
    void isPossible659Test() {
        cout << "659. Split Array into Consecutive Subsequences test starts.\n";
        vector<int> nums = {1, 2, 3, 3, 4, 4, 5, 5};
        cout << "Can generate sequences = ["
            << (implObj->isPossible659(nums) ? "True" : "False") << "]\n\n";
    }

    // 662. Maximum Width of Binary Tree Test
    void widthOfBinaryTree662Test() {
        cout << "662. Maximum Width of Binary Tree test starts.\n";
        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(3); cur->right = new TreeNode(2);
        cur = root->left;
        cur->left = new TreeNode(5); cur->right = new TreeNode(3);
        cur = root->right;
        cur->right = new TreeNode(9);
        int width = implObj->widthOfBinaryTree662(root);
        cout << "Max width of a BT = [" << width << "]\n\n";
    }

    // 663. Equal Tree Partition Test
    void checkEqualTree663Test() {
        cout << "663. Equal Tree Partition test starts.\n";
        TreeNode* root = new TreeNode(5);
        TreeNode* cur = root;
        cur->left = new TreeNode(10); cur->right = new TreeNode(10);
        cur = cur->right;
        cur->left = new TreeNode(2); cur->right = new TreeNode(3);
        bool result = implObj->checkEqualTree663(root);
        cout << "Can split into Equal Sum Tree = [" << (result ? "True" : "False")
            << "]\n\n";
    }

    // 664. Strange Printer Test
    void strangePrinter664Test() {
        cout << "664. Strange Printer test starts.\n";
        cout << "aba will need [" << implObj->strangePrinter664("aba") 
            << "] steps to generate.\n\n";
    }

    // 665. Non-decreasing Array Test
    void checkPossibility665Test() {
        cout << "665. Non-decreasing Array test starts.\n";
        vector<int> nums = {2, 3, 3, 2, 4};
        cout << "{2,3,3,2,4} can be modified to be mono-increasing = ["
            << (implObj->checkPossibility665(nums) ? "True" : "False") << "]\n\n";
    }

    // 668. Kth Smallest Number in Multiplication Table Test
    void findKthNumber668Test() {
        cout << "668. Kth Smallest Number in Multiplication Table test starts.\n";
        int result = implObj->findKthNumber668(3, 3, 5);
        cout << "(3, 3, 5) will generate result = [" << result << "]\n\n";
    }

private:
    Session6Impl * implObj;
};

#endif