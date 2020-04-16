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

private:
    Session6Impl * implObj;
};

#endif