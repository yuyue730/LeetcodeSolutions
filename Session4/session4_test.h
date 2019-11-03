#ifndef _SESSION_4_TEST_H
#define _SESSION_4_TEST_H

#include "session4_impl.h"

class Session4Test 
{
public:
    Session4Test() 
    {
        cout << "Test object for Leetcode Session 4 problems constructed.\n";
        implObj = new Session4Impl();
    }

    // 402. Remove K Digits Test
    void removeKdigits402Test() {
        cout << "402. Remove K Digits test starts.\n";
        string num = "1432219";
        cout << "1432219 => [" << implObj->removeKdigits402(num, 3) << "]\n\n";
        return;
    }

    // 403. Frog Jump Test
    void canCross403Test() {
        cout << "403. Frog Jump test starts.\n";
        vector<int> nums = {0, 1, 3, 5, 6, 8, 12, 17};
        cout << "Can find = [" << implObj->canCross403(nums) << "]\n\n";
        return;
    }

    // 406. Queue Reconstruction by Height Test
    void reconstructQueue406Test() {
        cout << "406. Queue Reconstruction by Height test starts.\n";
        vector<vector<int>> people = {
            {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}
        };
        cout << "result = [";
        vector<vector<int>> result = implObj->reconstructQueue406(people);
        for (int i = 0; i < result.size(); ++i) {
            cout << "[" << result[i][0] << ", " << result[i][1] << "]"
                << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 410. Split Array Largest Sum Test
    void splitArray410Test() {
        cout << "410. Split Array Largest Sum test starts.\n";
        vector<int> nums = {7, 2, 5, 10, 8};
        cout << "Min(Max(sub array sum)) = [" << implObj->splitArray410(nums, 2) << "]\n\n";
        return;
    }

    // 412. Fizz Buzz Test
    void fizzBuzz412Test() {
        cout << "412. Fizz Buzz test starts.\n";
        vector<string> result = implObj->fizzBuzz412(15);
        cout << "result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 414. Third Maximum Number Test
    void thirdMax414Test() {
        cout << "414. Third Maximum Number test starts.\n";
        vector<int> nums = {3, 2, 1};
        cout << "Third Max = [" << implObj->thirdMax414(nums) << "].\n\n";
        return;
    }

    // 415. Add Strings Test
    void addStrings415Test() {
        cout << "415. Add Strings test starts.\n";
        cout << "123 + 568 = [" << implObj->addStrings415("123", "568") << "]\n\n";
        return;
    }

    // 416. Partition Equal Subset Sum Test
    void canPartition416Test() {
        cout << "416. Partition Equal Subset Sum test starts.\n";
        vector<int> nums = {1, 5, 11, 5};
        cout << "Can partition = [" << implObj->canPartition416(nums) << "]\n\n";
        return;
    }

    // 417. Pacific Atlantic Water Flow Test
    void pacificAtlantic417Test() {
        cout << "417. Pacific Atlantic Water Flow test starts.\n";
        vector<vector<int>> matrix = {
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4}
        };
        vector<vector<int>> result = implObj->pacificAtlantic417(matrix);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << "(" << result[i][0] << ", " << result[i][1] << ")"
                << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 418. Sentence Screen Fitting Test
    void wordsTyping418Test() {
        cout << "418. Sentence Screen Fitting test starts.\n";
        int rows = 3, cols = 6; 
        vector<string> sentence = {"a", "bcd", "e"};
        cout << "Repeating = [" << implObj->wordsTyping418(sentence, rows, cols) << "]\n\n";
        return;
    }

    // 419. Battleships in a Board Test
    void countBattleships419Test() {
        cout << "419. Battleships in a Board test starts.\n";
        vector<vector<char>> ships = {
            {'X', '.', '.', 'X'},
            {'.', '.', '.', 'X'},
            {'.', '.', '.', 'X'}
        };

        cout << "# of ships = [" << implObj->countBattleships419(ships) << "]\n\n";
        return;
    }

    // 424. Longest Repeating Character Replacement Test
    void characterReplacement424Test() {
        cout << "424. Longest Repeating Character Replacement test starts.\n";
        cout << "Longest replacement len = [" << implObj->characterReplacement424("AABABBA", 2) << "]\n\n";
        return;
    }

    // 426. Convert Binary Search Tree to Sorted Doubly Linked List Test
    void treeToDoublyList426Test() {
        cout << "426. Convert Binary Search Tree to Sorted Doubly Linked List test starts.\n";
        Node426 * root = new Node426(4, NULL, NULL);
        root->left = new Node426(2, NULL, NULL);
        root->right = new Node426(5, NULL, NULL);;

        Node426 * cur = root->left;
        cur->left = new Node426(1, NULL, NULL);
        cur->right = new Node426(3, NULL, NULL);

        Node426 * result = implObj->treeToDoublyList426(root);
        cout << "Please exam result = [" << result->val << "]\n\n";
        return;
    }

    // 428. Serialize and Deserialize N-ary Tree Test
    void Codec428Test() {
        cout << "428. Serialize and Deserialize N-ary Tree test starts.\n";
        Session4Impl::Codec428 codec;
        Node428 * child1 = new Node428(3, {
            new Node428(5, {}), new Node428(6, {})
        });
        Node428 * child2 = new Node428(2, {});
        Node428 * child3 = new Node428(4, {});
        Node428 * root = new Node428(1, {child1, child2, child3});
        
        string str_res = codec.serialize(root);
        cout << "Serilize result = [" << str_res << "]\n";
        cout << "Please exam deserilze result = [" << codec.deserialize(str_res)->val << "]\n\n";
        return;
    }

    // 430. Flatten a Multilevel Doubly Linked List Test
    void flatten430Test() {
        cout << "430. Flatten a Multilevel Doubly Linked List test starts.\n";
        Node430* head = new Node430(1, NULL, NULL, NULL);
        Node430* node2 = new Node430(2, NULL, NULL, NULL);
        Node430* node3 = new Node430(3, NULL, NULL, NULL);
        Node430* node4 = new Node430(4, NULL, NULL, NULL);
        Node430* node5 = new Node430(5, NULL, NULL, NULL);
        Node430* node6 = new Node430(6, NULL, NULL, NULL);

        head->next = node2; node2->prev = head;
        node2->next = node3; node3->prev = node2;
        node3->next = node4; node4->prev = node3;

        node5->next = node6; node6->prev = node5;
        node3->child = node5;

        Node430* result = implObj->flatten430(head);
        cout << "Please exam [" << result << "]\n\n";
        return;
    }

    // 432. All O`one Data Structure Test
    void AllOne432Test() {
        cout << "432. All O`one Data Structure test starts.\n";
        Session4Impl::AllOne432 obj;
        obj.inc("A");
        obj.inc("B");
        obj.inc("B");
        obj.inc("B");
        obj.inc("B");
        obj.inc("B");
        obj.dec("B");
        obj.dec("B");
        cout << "getMax = [" << obj.getMaxKey() << "]; getMin = [" << obj.getMinKey() << "]\n\n";
    }

    // 433. Minimum Genetic Mutation Test
    void minMutation433Test() {
        cout << "433. Minimum Genetic Mutation test starts.\n";
        string start = "AAAAACCC";
        string end = "AACCCCCC";
        vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
        cout << "# of steps to reach = [" << implObj->minMutation433(start, end, bank) << "]\n\n";
        return;
    }

    // 435. Non-overlapping Intervals Test
    void eraseOverlapIntervals435Test() {
        cout << "435. Non-overlapping Intervals test starts.\n";
        vector<vector<int>> intervals = {
            {2, 3}, {1, 2}, {1, 5}, {1, 3}
        };
        cout << "# to remove = [" << implObj->eraseOverlapIntervals435(intervals) << "]\n\n";
        return;
    }

    // 437. Path Sum III Test
    void pathSum437Test() {
        cout << "437. Path Sum III test starts.\n";
        TreeNode* root = new TreeNode(10);
        root->left = new TreeNode(5);
        root->right = new TreeNode(-3);

        TreeNode* cur = root->left;
        cur->left = new TreeNode(3);
        cur->right = new TreeNode(2);

        cur = cur->left;
        cur->left = new TreeNode(3);
        cur->right = new TreeNode(-2);

        cur = root->left->right;
        cur->right = new TreeNode(1);

        cur = root->right;
        cur->right = new TreeNode(11);

        cout << "# of paths = [" << implObj->pathSum437(root, 8) << "]\n\n";
        return;
    }

    // 438. Find All Anagrams in a String Test
    void findAnagrams438Test() {
        cout << "438. Find All Anagrams in a String test starts.\n";
        string s = "cbaebabacd"; 
        string p = "abc";

        vector<int> result = implObj->findAnagrams438(s, p);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 440. K-th Smallest in Lexicographical Order Test
    void findKthNumber440Test() {
        cout << "440. K-th Smallest in Lexicographical Order test starts.\n";
        cout << "(13, 3) will return [" << implObj->findKthNumber440(13, 3) << "]\n\n";
        return;
    }

    // 442. Find All Duplicates in an Array Test
    void findDuplicates442Test() {
        cout << "442. Find All Duplicates in an Array test starts.\n";
        vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
        vector<int> result = implObj->findDuplicates442(nums);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 443. String Compression Test
    void compress443Test() {
        cout << "443. String Compression test starts.\n";
        vector<char> chars = {'a','a','b','b','c','c','c'};
        int result = implObj->compress443(chars);
        cout << "Result = [" << result << "] chars = [";
        for (int i = 0; i < chars.size(); ++i) {
            cout << chars[i] << ((i == chars.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 445. Add Two Numbers II Test
    void addTwoNumbers445Test() {
        cout << "445. Add Two Numbers II test starts.\n";
        ListNode *head1 = new ListNode(7);
        ListNode *cur = head1;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(3);
        
        ListNode *head2 = new ListNode(5);
        cur = head2;
        cur->next = new ListNode(6); cur = cur->next;
        cur->next = new ListNode(4);

        ListNode* result = implObj->addTwoNumbers445(head1, head2);
        cout << "Result = [";
        while (result) {
            cout << result->val << (result->next ? "->" : "");
            result = result->next;
        }
        cout << "]\n\n";
        return;
    }

    // 448. Find All Numbers Disappeared in an Array Test
    void findDisappearedNumbers448Test() {
        cout << "448. Find All Numbers Disappeared in an Array test starts.\n";
        vector<int> nums = {4,3,2,7,8,2,3,1};
        vector<int> result = implObj->findDisappearedNumbers448(nums);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 449. Serialize and Deserialize BST Test
    void Codec449Test() {
        cout << "449. Serialize and Deserialize BST test starts.\n";
        TreeNode* root = new TreeNode(4);
        TreeNode* cur = root;
        cur->left = new TreeNode(2);
        cur->right = new TreeNode(5);

        cur = cur->left;
        cur->left = new TreeNode(1);
        cur->right = new TreeNode(3);

        Session4Impl::Codec449 obj;
        string serialize = obj.serialize(root);
        cout << "Serialize = [" << serialize << "]\n";
        TreeNode* deserialize = obj.deserialize(serialize);
        cout << "Please exam deserialize = [" << deserialize->val << "]\n\n";
        return;
    }

    // 450. Delete Node in a BST Test
    void deleteNode450Test() {
        cout << "450. Delete Node in a BST test starts.\n";
        TreeNode* root = new TreeNode(4);
        TreeNode* cur = root;
        cur->left = new TreeNode(2);
        cur->right = new TreeNode(6);

        cur = cur->left;
        cur->left = new TreeNode(1);
        cur->right = new TreeNode(3);

        cur = root->right;
        cur->left = new TreeNode(5);
        cur->right = new TreeNode(7);

        TreeNode* result = implObj->deleteNode450(root, 5);
        cout << "Please exam result [" << result->val << "]\n\n";
        return;
    }

    // 451. Sort Characters By Frequency Test
    void frequencySort451Test() {
        cout << "451. Sort Characters By Frequency test starts.\n";
        cout << "tree => [" << implObj->frequencySort451("tree") << "]\n\n";
        return;
    }

    // 452. Minimum Number of Arrows to Burst Balloons Test
    void findMinArrowShots452Test() {
        cout << "452. Minimum Number of Arrows to Burst Balloons test starts.\n";
        vector<vector<int>> points = {
            {10, 16}, {2, 8}, {1, 6}, {7, 12}
        };
        cout << "# of arrows = [" << implObj->findMinArrowShots452(points) << "].\n\n";
        return;
    }

    // 456. 132 Pattern Test
    void find132pattern456Test() {
        cout << "456. 132 Pattern test starts.\n";
        vector<int> nums = {3, 1, 4, 2};
        cout << "Can find 132 = [" << implObj->find132pattern456(nums) << "]\n\n";
        return;
    }

    // 459. Repeated Substring Pattern Test
    void repeatedSubstringPattern459Test() {
        cout << "459. Repeated Substring Pattern test starts.\n";
        string s = "abab";
        cout << "Is repeated = [" << implObj->repeatedSubstringPattern459(s) << "]\n\n";
        return;
    }

    // 460. LFU Cache Test
    void LFUCache460Test() {
        cout << "460. LFU Cache test starts.\n";
        Session4Impl::LFUCache460 cache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        cout << "Get 1 = [" << cache.get(1) << "]\n";
        cache.put(3, 3);
        cout << "Get 2 = [" << cache.get(2) << "]\n";
        cout << "Get 3 = [" << cache.get(3) << "]\n";
        cache.put(4, 4);
        cout << "Get 1 = [" << cache.get(1) << "]\n";
        cout << "Get 3 = [" << cache.get(3) << "]\n";
        cout << "Get 4 = [" << cache.get(4) << "]\n\n";
        return;
    }

    // 463. Island Perimeter Test
    void islandPerimeter463Test() {
        cout << "463. Island Perimeter test starts.\n";
        vector<vector<int>> grid = {
            {0,1,0,0},
            {1,1,1,0},
            {0,1,0,0},
            {1,1,0,0}
        };

        cout << "Perimeter = [" << implObj->islandPerimeter463(grid) << "]\n\n";
        return;
    }

    // 464. Can I Win Test
    void canIWin464Test() {
        cout << "464. Can I Win test starts.\n";
        cout << "Can win with (4, 6) = [" << implObj->canIWin464(4, 6) << "]\n\n";
        return;
    }

    // 465. Optimal Account Balancing Test
    void minTransfers465Test() {
        cout << "465. Optimal Account Balancing test starts.\n";
        vector<vector<int>> transactions = {
            {0, 1, 10}, {2, 0, 5}
        };
        cout << "# of transactions = [" << implObj->minTransfers465(transactions) << "]\n\n";
        return;
    }

    // 468. Validate IP Address Test
    void validIPAddress468Test() {
        cout << "468. Validate IP Address test starts.\n";
        cout << "2001:0db8:85a3:0:0:8A2E:0370:7334 => [" 
            << implObj->validIPAddress468("2001:0db8:85a3:0:0:8A2E:0370:7334") 
            << "]\n";
        cout << "256.256.256.256 => [" << implObj->validIPAddress468("256.256.256.256") << "]\n\n";
    }

    // 472. Concatenated Words Test
    void findAllConcatenatedWordsInADict472Test() {
        cout << "472. Concatenated Words test starts.\n";
        vector<string> words = {
            "cat", "cats", "catsdogcats", "dog",
            "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"
        };
        vector<string> result = implObj->findAllConcatenatedWordsInADict472(words);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

private:
    Session4Impl * implObj;
};

#endif