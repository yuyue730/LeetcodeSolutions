#ifndef _SESSION_1_TEST_H
#define _SESSION_1_TEST_H

#include "session1_impl.h"

class Session1Test {
public:
    Session1Test() {
        cout << "Test object for Leetcode Session 1 problems constructed.\n";
        implObj = new Session1Impl();
    }

    // 101. Symmetric Tree Test
    void isSymmetric101Test() {
        cout << "101. Symmetric Tree test starts.\n";

        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);
        cur = cur->left;
        cur->left = new TreeNode(3); cur->right = new TreeNode(4);
        cur = cur->right; cur->left = new TreeNode(5);

        cur = root;
        cur->right = new TreeNode(2);
        cur = cur->right;
        cur->left = new TreeNode(4); cur->right = new TreeNode(3);
        cur = cur->left; cur->right = new TreeNode(5);

        cout << "Is tree symmetirc = [" 
            << (implObj->isSymmetric101(root) ? "True" : "False") << "]\n\n";
        return;
    }

    // 102. Binary Tree Level Order Traversal Test
    void levelOrder102Test() {
        cout << "102. Binary Tree Level Order Traversal test starts.\n";

        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);  cur->right = new TreeNode(3);
        cur = cur->right;
        cur->left = new TreeNode(4);  cur->right = new TreeNode(5);

        vector<vector<int>> result = implObj->levelOrder102(root);
        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "[";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "].\n\n";
    }

    // 103. Binary Tree Zigzag Level Order Traversal Test
    void zigzagLevelOrder103Test() {
        cout << "103. Binary Tree Zigzag Level Order Traversal test starts.\n";

        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);  cur->right = new TreeNode(3);
        cur = cur->right;
        cur->left = new TreeNode(4);  cur->right = new TreeNode(5);

        vector<vector<int>> result = implObj->zigzagLevelOrder103(root);
        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "].\n\n";
    }

    // 104. Maximum Depth of Binary Tree (DFS) Test
    void maxDepth104Test() {
        cout << "104. Maximum Depth of Binary Tree (DFS) test starts.\n";

        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);  cur->right = new TreeNode(3);
        cur = cur->right;
        cur->left = new TreeNode(4);  cur->right = new TreeNode(5);

        cout << "Max depth = [" << implObj->maxDepth104(root) << "]\n\n";
        return;
    }

    // 105. Construct Binary Tree from Preorder and Inorder Traversal Test
    void buildTree105Test() {
        cout << "105. Construct Binary Tree from Preorder and Inorder Traversal " 
            << "test starts.\n";
        
        vector<int> preorder = {3,9,20,15,7};
        vector<int> inorder = {9,3,15,20,7};
        TreeNode * result = implObj->buildTree105(preorder, inorder);
        cout << "Please exam result via debugger. root = [" << result->val << "].\n\n";
        return;
    }

    // 106. Construct Binary Tree from Inorder and Postorder Traversal Test
    void buildTree106Test() {
        cout << "106. Construct Binary Tree from Inorder and Postorder Traversal "
            << "test starts.\n";

        vector<int> inorder = {9,3,15,20,7};
        vector<int> postorder = {9,15,7,20,3};
        TreeNode * result = implObj->buildTree106(inorder, postorder);
        cout << "Please exam result via debugger. root = [" << result->val << "].\n\n";
        return;
    }

    // 107. Binary Tree Level Order Traversal II Test
    void levelOrderBottom107Test() {
        cout << "107. Binary Tree Level Order Traversal II test starts.\n";
        TreeNode * root = new TreeNode(3);
        TreeNode * cur = root;
        cur->left = new TreeNode(9);
        cur->right = new TreeNode(20);

        cur = cur->right;
        cur->left = new TreeNode(15);
        cur->right = new TreeNode(7);

        vector<vector<int>> result = implObj->levelOrderBottom107(root);
        cout << "Layers = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
        return;

    }

    // 108. Convert Sorted Array to Binary Search Tree Test
    void sortedArrayToBST108Test() {
        cout << "108. Convert Sorted Array to Binary Search Tree test starts.\n";
        vector<int> nums = {-10, -3, 0, 5, 9};
        TreeNode * root = implObj->sortedArrayToBST108(nums);
        cout << "Please exam result via debugger. root = [" << root->val << "].\n\n";
        return;
    }

    // 109. Convert Sorted List to Binary Search Tree Test
    void sortedListToBST109Test() {
        cout << "109. Convert Sorted List to Binary Search Tree test starts.\n";
        ListNode * head = new ListNode(-10);
        ListNode * cur = head;
        cur->next = new ListNode(-3); cur = cur->next;
        cur->next = new ListNode(0); cur = cur->next;
        cur->next = new ListNode(5); cur = cur->next;
        cur->next = new ListNode(9);

        TreeNode * result = implObj->sortedListToBST109(head);
        cout << "Please exam result via debugger. root = [" << result->val << "].\n\n";
        return;
    }

    // 110. Balanced Binary Tree Test
    void isBalanced110Test() {
        cout << "110. Balanced Binary Tree test starts.\n";
        TreeNode * root = new TreeNode(5);
        TreeNode * cur = root;
        cur->left = new TreeNode(4);
        cur = cur->left; cur->left = new TreeNode(11);
        cur = cur->left;
        cur->left = new TreeNode(7); cur->right = new TreeNode(2);

        cur = root;
        cur->right = new TreeNode(8); cur = cur->right;
        cur->left = new TreeNode(13); cur->right = new TreeNode(4);
        cur = cur->right;
        cur->left = new TreeNode(5); cur->right = new TreeNode(1);

        cout << "isBalanced = [" << (implObj->isBalanced110(root) ? "True" : "False") 
            << "].\n\n";
        return;
    }

    // 111. Minimum Depth of Binary Tree Test
    void minDepth111Test() {
        cout << "111. Minimum Depth of Binary Tree test starts.\n";
        TreeNode * root = new TreeNode(3);
        TreeNode * cur = root;
        cur->left = new TreeNode(9);
        cur->right = new TreeNode(20);

        cur = cur->right;
        cur->left = new TreeNode(15);
        cur->right = new TreeNode(7);

        cout << "MinDepth = [" << implObj->minDepth111(root) << "]\n\n";
        return;
    }

    // 112. Path Sum Test
    void hasPathSum112Test() {
        cout << "112. Path Sum test starts.\n";
        TreeNode * root = new TreeNode(5);
        TreeNode * cur = root;
        cur->left = new TreeNode(4);
        cur = cur->left; cur->left = new TreeNode(11);
        cur = cur->left;
        cur->left = new TreeNode(7); cur->right = new TreeNode(2);

        cur = root;
        cur->right = new TreeNode(8); cur = cur->right;
        cur->left = new TreeNode(13); cur->right = new TreeNode(4);
        cur = cur->right;
        cur->left = new TreeNode(5); cur->right = new TreeNode(1);

        cout << "hasPathSum = [" << (implObj->hasPathSum112(root, 22) ? "True" : "False")
            << "].\n\n";
        return;
    }

    // 113. Path Sum II Test
    void pathSum113Test() {
        cout << "113. Path Sum II test starts.\n";
        TreeNode * root = new TreeNode(5);
        TreeNode * cur = root;
        cur->left = new TreeNode(4);
        cur = cur->left; cur->left = new TreeNode(11);
        cur = cur->left;
        cur->left = new TreeNode(7); cur->right = new TreeNode(2);

        cur = root;
        cur->right = new TreeNode(8); cur = cur->right;
        cur->left = new TreeNode(13); cur->right = new TreeNode(4);
        cur = cur->right;
        cur->left = new TreeNode(5); cur->right = new TreeNode(1);

        vector<vector<int>> result = implObj->pathSum113(root, 22);
        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "].\n\n";
        return;
    }

    // 114. Flatten Binary Tree to Linked List Test
    void flatten114Test() {
        cout << "114. Flatten Binary Tree to Linked List test starts.\n";
        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2); cur = cur->left;
        cur->left = new TreeNode(3); cur->right = new TreeNode(4);

        cur = root;
        cur->right = new TreeNode(5); cur = cur->right;
        cur->right = new TreeNode(6);

        implObj->flatten114(root);
        cout << "Please exam result via debugger. root = [" << root->val << "].\n\n";
        return;
    }

    // 115. Distinct Subsequences Test
    void numDistinct115Test() {
        cout << "115. Distinct Subsequences test starts.\n";
        cout << "numDistinct = [" << implObj->numDistinct115("rabbbit", "rabbit") << "]\n\n";
        return;
    }

    // 116. Populating Next Right Pointers in Each Node Test
    // 117. Populating Next Right Pointers in Each Node II Test
    void connect116Test() {
        cout << "116. Populating Next Right Pointers in Each Node test starts.\n";
        cout << "117. Populating Next Right Pointers in Each Node II test starts.\n";
        Node * root = new Node(
            3, 
            new Node(9, NULL, NULL, NULL), 
            new Node(
                20, 
                new Node(15, NULL, NULL, NULL), 
                new Node(7, NULL, NULL, NULL), 
                NULL
            ),
            NULL
        );

        Node * result = implObj->connect116(root);
        cout << "Please exam result via debugger. root = [" << result->val << "].\n\n";
        return;
    }

    // 118. Pascal's Triangle Test
    void generate118Test() {
        cout << "118. Pascal's Triangle test starts.\n";
        vector<vector<int>> result = implObj->generate118(5);
        cout << "result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "].\n\n";
        return;
    }

    // 119. Pascal's Triangle II Test
    void getRow119Test() {
        cout << "119. Pascal's Triangle II test starts.\n";
        vector<int> result = implObj->getRow119(3);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n";
    }

    // 120. Triangle Test
    void minimumTotal120Test() {
        cout << "120. Triangle test starts.\n";
        vector<vector<int>> triangle = {
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3}
        };

        cout << "Min total = [" << implObj->minimumTotal120(triangle) << "]\n\n";
        return;
    }

    // 121. Best Time to Buy and Sell Stock Test
    void maxProfit121Test() {
        cout << "121. Best Time to Buy and Sell Stock test starts.\n";
        vector<int> nums = {7,1,5,3,6,4};
        cout << "Max Profit = " << implObj->maxProfit121(nums) << "\n\n";
        return;
    }

    // 122. Best Time to Buy and Sell Stock II Test
    void maxProfit122Test() {
        cout << "122. Best Time to Buy and Sell Stock II test starts.\n";
        vector<int> nums = {7,1,5,3,6,4};
        cout << "Max Profit = " << implObj->maxProfit122(nums) << "\n\n";
        return;
    }

    // 123. Best Time to Buy and Sell Stock III Test
    void maxProfit123Test() {
        cout << "123. Best Time to Buy and Sell Stock III test starts.\n";
        vector<int> prices = {3,3,5,0,0,3,1,4};
        cout << "Max Profit = [" << implObj->maxProfit123(prices) << "]\n\n";
        return;
    }

    // 124. Binary Tree Maximum Path Sum Test
    void maxPathSum124Test()
    {
        cout << "124. Binary Tree Maximum Path Sum test starts.\n";
        TreeNode * root = new TreeNode(-10);
        TreeNode * cur = root;
        cur->left = new TreeNode(9);
        cur->right = new TreeNode(20);
        cur = cur->right;
        cur->left = new TreeNode(15); cur->right = new TreeNode(7);

        cout << "BT Max Path Sum = [" << implObj->maxPathSum124(root) << "]\n\n";
        return;
    }

    // 125. Valid Palindrome Test
    void isPalindrome125Test() {
        cout << "125. Valid Palindrome test starts.\n";
        cout << "'A man, a plan, a canal: Panama' = " 
            << (implObj->isPalindrome125("A man, a plan, a canal: Panama") ? "True" : "False")
            << "\n\n";
        return;
    }

    // 126. Word Ladder II Test
    void findLadders126Test() {
        cout << "126. Word Ladder II test starts.\n";
        string startWord = "hit", endWord = "cog";
        vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

        vector<vector<string>> result = implObj->findLadders126(startWord, endWord, wordList);
        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
        return;
    }

    // 127. Word Ladder Test
    void ladderLength127Test() {
        cout << "127. Word Ladder test starts.\n";
        string startWord = "hit", endWord = "cog";
        vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

        cout << "Steps needed from being to end = [" 
            << implObj->ladderLength127(startWord, endWord, wordList) << "].\n\n";
        return;
    }

    // 128. Longest Consecutive Sequence Test
    void longestConsecutive128Test() {
        cout << "128. Longest Consecutive Sequence test starts.\n";
        vector<int> nums = {100, 4, 200, 1, 3, 2};
        cout << "Longest Consecutive Sequence = [" << implObj->longestConsecutive128(nums) 
            << "].\n\n";
        return;
    }

    // 129. Sum Root to Leaf Numbers Test
    void sumNumbers128Test() {
        cout << "129. Sum Root to Leaf Numbers test starts.\n";
        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);
        cur->right = new TreeNode(3);
        cout << "Sum = [" << implObj->sumNumbers128(root) << "]\n\n";
        return;
    }

    // 130. Surrounded Regions Test
    void solve130Test() {
        cout << "130. Surrounded Regions test starts.\n";
        vector<vector<char>> board = {
            {'X', 'X', 'X', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
            {'O', 'O', 'X', 'O'}
        };
        implObj->solve130(board);
        cout << "Board = [";
        for (int i = 0; i < board.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < board[0].size(); ++j) {
                cout << board[i][j] << ((j == board[0].size() - 1) ?"" : ", ");
            }
            cout << "]\n";
        }
        cout << "].\n\n";
        return;
    }

    // 131. Palindrome Partitioning Test
    void partition131Test() {
        cout << "131. Palindrome Partitioning test starts.\n";
        vector<vector<string>> result = implObj->partition131("aab");
        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "].\n\n";
    }

    // 132. Palindrome Partitioning II Test
    void minCut132Test() {
        cout << "132. Palindrome Partitioning II test starts.\n";
        cout << "Min Cut = " << implObj->minCut132("efe") << "\n\n";
        return;
    }

    // 133. Clone Graph Test
    void cloneGraph133Test() {
        cout << "133. Clone Graph test starts.\n";
        Node133 * n1 = new Node133(); n1->val = 1;
        Node133 * n2 = new Node133(); n2->val = 2;
        Node133 * n3 = new Node133(); n3->val = 3;
        Node133 * n4 = new Node133(); n4->val = 4;

        n1->neighbors = {n2, n3};
        n2->neighbors = {n1, n4};
        n3->neighbors = {n1, n4};
        n4->neighbors = {n4, n2};

        Node133 * clone = implObj->cloneGraph133(n1);
        cout << "Please exam in debugger [" << clone->val << "].\n\n";
        return;
    }

    // 134. Gas Station Test
    void canCompleteCircuit134Test() {
        cout << "134. Gas Station test starts.\n";
        vector<int> gas = {1,2,3,4,5};
        vector<int> cost = {3,4,5,1,2};

        cout << "Starting Index = [" << implObj->canCompleteCircuit134(gas, cost)
            << "].\n\n";
        return;
    }

    // 135. Candy Test
    void candy135Test() {
        cout << "135. Candy test starts.\n";
        vector<int> ratings = {1,0,2};

        cout << "# of candies = [" << implObj->candy135(ratings) << "].\n\n";
        return;
    }

    // 136. Single Number Test
    void singleNumber136Test() {
        cout << "136. Single Number test starts.\n";
        vector<int> nums = {4,1,2,1,2};
        cout << "Single Number = [" << implObj->singleNumber136(nums) << "]\n\n";
        return;
    }

    // 137. Single Number II Test
    void singleNumber137Test() {
        cout << "137. Single Number II test starts.\n";
        vector<int> nums = {0,1,0,1,0,1,99};
        cout << "Single Number = [" << implObj->singleNumber137(nums) << "]\n\n";
        return;
    }

    // 138. Copy List with Random Pointer Test
    void copyRandomList138Test() {
        cout << "138. Copy List with Random Pointer test starts.\n";
        Node138 * head = new Node138(1, NULL, NULL);
        Node138 * next = new Node138(2, NULL, NULL);

        head->next = next;
        head->random = next;
        next->next = NULL;
        next->random = next;
        Node138 * clone = implObj->copyRandomList138(head);
        cout << "Please exam the cloned linked list [" << clone->val << "]\n\n";
        return;
    }

    // 139. Word Break Test
    void wordBreak139Test() {
        cout << "139. Word Break test starts.\n";
        string s = "leetcode";
        vector<string> strVec = {"leet", "code"};
        cout << "Word can break = [" << (implObj->wordBreak139(s, strVec) ? "True" : "False")
            << "].\n\n";
        return;
    }

    // 140. Word Break II Test
    void wordBreak140Test() {
        cout << "140. Word Break II test starts.\n";
        string s = "catsanddog";
        vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
        vector<string> result = implObj->wordBreak140(s, wordDict);

        cout << "Word breaks into [";
        for (int i = 0; i < result.size(); ++i) {
            cout << "\"" << result[i] << "\"" << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 141. Linked List Cycle Test
    void hasCycle141Test() {
        cout << "141. Linked List Cycle test starts.\n";
        ListNode* head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(2); 
        ListNode * two = cur->next;
        cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5); cur = cur->next; 
        cur->next = two;

        cout << "has Cycle = [" << (implObj->hasCycle141(head) ? "True" : "False") << "]\n\n";
        return;
    }

    // 142. Linked List Cycle II Test
    void detectCycle142Test() {
        cout << "142. Linked List Cycle II test starts.\n";
        ListNode* head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(2); 
        ListNode * two = cur->next;
        cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5); cur = cur->next; 
        cur->next = two;

        cout << "Fist overlap node = [" << implObj->detectCycle142(head)->val << "].\n\n";
        return;
    }

    // 143. Reorder List Test
    void reorderList143Test() {
        cout << "143. Reorder List test starts.\n";
        ListNode *head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5);

        implObj->reorderList143(head);
        cout << "Please exam linked list via debugger. [" << head->val << "]\n\n";
        return;
    }

    // 144. Binary Tree Preorder Traversal Test
    void preorderTraversal144Test() {
        cout << "144. Binary Tree Preorder Traversal test starts.\n";
        TreeNode * root = new TreeNode(-10);
        TreeNode * cur = root;
        cur->left = new TreeNode(9);
        cur->right = new TreeNode(20);
        cur = cur->right;
        cur->left = new TreeNode(15); cur->right = new TreeNode(7);

        vector<int> result = implObj->preorderTraversal144(root);
        cout << "Pre order output = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "].\n\n";
        return;
    }

    // 145. Binary Tree Postorder Traversal Test
    void postorderTraversal145Test() {
        cout << "145. Binary Tree Postorder Traversal test starts.\n";
        TreeNode * root = new TreeNode(-10);
        TreeNode * cur = root;
        cur->left = new TreeNode(9);
        cur->right = new TreeNode(20);
        cur = cur->right;
        cur->left = new TreeNode(15); cur->right = new TreeNode(7);

        vector<int> result = implObj->postorderTraversal145(root);
        cout << "Post order output = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "].\n\n";
        return;
    }

    // 146. LRU Cache Test
    void LRUCache146Test() {
        cout << "146. LRU Cache test starts.\n";
        Session1Impl::LRUCache146 cache(2);

        cache.put(1, 1);
        cache.put(2, 2);
        cout << "get 1 = [" << cache.get(1) << "]\n";
        cache.put(3, 3);
        cout << "get 2 = [" << cache.get(2) << "]\n";
        cache.put(4, 4);
        cout << "get 1 = [" << cache.get(1) << "]\n";
        cout << "get 3 = [" << cache.get(3) << "]\n";
        cout << "get 4 = [" << cache.get(4) << "]\n\n";
        return;
    }

    // 148. Sort List Test
    void sortList148Test() {
        cout << "148. Sort List test starts.\n";
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        cur->next = new ListNode(5); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(0);

        ListNode *result = implObj->sortList148(head);
        cout << "Please exam linked list via debugger. [" << result->val << "]\n\n";
        return;
    }

    // 149. Max Points on a Line Test
    void maxPoints149Test() {
        cout << "149. Max Points on a Line test starts.\n";
        vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
        cout << "Max points on a line = [" << implObj->maxPoints149(points) << "].\n\n";
        return; 
    }

    // 150. Evaluate Reverse Polish Notation Test
    void evalRPN150Test() {
        cout << "150. Evaluate Reverse Polish Notation test starts.\n";
        vector<string> tokens = {"4", "13", "5", "/", "+"};
        cout << "Calculation result = [" << implObj->evalRPN150(tokens) << "]\n\n";
        return;
    }

    // 151. Reverse Words in a String Test
    void reverseWords151Test() {
        cout << "151. Reverse Words in a String test starts.\n";
        cout << "Reverse result [" << implObj->reverseWords151("a good   example") << "]\n\n";
        return;
    }

    // 152. Maximum Product Subarray Test
    void maxProduct152Test() {
        cout << "152. Maximum Product Subarray test starts.\n";
        vector<int> nums = {2,3,-2,4};
        cout << "Max Product = [" << implObj->maxProduct152(nums) << "]\n\n";
        return;
    }

    // 153. Find Minimum in Rotated Sorted Array Test
    void findMin153Test() {
        cout << "153. Find Minimum in Rotated Sorted Array test starts.\n";
        vector<int> nums = {4,5,6,7,0,1,2};
        cout << "Find min = [" << implObj->findMin153(nums) << "]\n\n";
        return;
    }
    
    // 154. Find Minimum in Rotated Sorted Array II Test
    void findMin154Test() {
        cout << "154. Find Minimum in Rotated Sorted Array II test starts.\n";
        vector<int> nums = {4,5,6,7,0,1,2};
        cout << "Find min = [" << implObj->findMin154(nums) << "]\n\n";
        return;
    }

    // 155. Min Stack Test
    void MinStack155Test() {
        cout << "155. Min Stack test starts.\n";

        Session1Impl::MinStack155 minStack;
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        cout << "Cur getMin = [" << minStack.getMin() << "]\n";
        minStack.pop();
        cout << "Cur getTop = [" << minStack.top() << "]\n";
        cout << "Cur getMin = [" << minStack.getMin() << "]\n\n";
        return;
    }

    // 157. Read N Characters Given Read4 Test
    void read157Test() {
        cout << "157. Read N Characters Given Read4 test starts.\n";
        implObj->setFileStr("abc");
        char * result1 = new char[1];
        int ct1 = implObj->read157(result1, 4);
        cout << "abc read 3 [" << string(result1).substr(0, ct1) << "]; ct1 = [" << ct1 << "]\n";

        implObj->setFileStr("abcde");
        char * result2 = new char[1];
        int ct2 = implObj->read157(result2, 5);
        cout << "abcde read 5 [" << string(result2).substr(0, ct2) << "]; ct2 = [" << ct2 << "]\n";

        implObj->setFileStr("abcdABCD1234");
        char * result3 = new char[1];
        int ct3 = implObj->read157(result3, 12);
        cout << "abcdABCD1234 read 12 [" << string(result3).substr(0, ct3) << "]; ct3 = [" << ct3 << "]\n";

        implObj->setFileStr("leetcode");
        char * result4 = new char[1];
        int ct4 = implObj->read157(result4, 5);
        cout << "leetcode read 5 [" << string(result4).substr(0, ct4) << "]; ct4 = [" << ct4 << "]\n\n";
        return;
    }

    // 158. Read N Characters Given Read4 II - Call multiple times Test
    void read158Test() {
        cout << "158. Read N Characters Given Read4 II - Call multiple times Test starts.\n";
        implObj->setFileStr("abcdABCD1234");
        char * result5 = new char[16];
        int ct5 = implObj->read158(result5, 5);
        cout << "abcdABCD1234 read 5 [" << string(result5).substr(0, ct5) << "]\n";

        char * result4 = new char[16];
        int ct4 = implObj->read158(result4, 4);
        cout << "abcdABCD1234 read 4 [" << string(result4).substr(0, ct4) << "]\n";

        char * result6 = new char[16];
        int ct6 = implObj->read158(result6, 6);
        cout << "abcdABCD1234 read 4 [" << string(result6).substr(0, ct6) << "]\n\n";
        return;
    }

    // 159. Longest Substring with At Most Two Distinct Characters Test
    void lengthOfLongestSubstringTwoDistinct159Test() {
        cout << "159. Longest Substring with At Most Two Distinct Characters test starts.\n";
        string str = "eceba";
        cout << "Length = [" << implObj->lengthOfLongestSubstringTwoDistinct159(str) << "]\n\n";
        return;
    }

    // 160. Intersection of Two Linked Lists Test
    void getIntersectionNode160Test() {
        cout << "160. Intersection of Two Linked Lists test starts.\n";
        ListNode *common = new ListNode(8);
        ListNode *cur = common;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5);

        ListNode *headA = new ListNode(4);
        cur = headA; cur->next = new ListNode(1);
        cur = cur->next; cur->next = common;

        ListNode *headB = new ListNode(5);
        cur = headB; cur->next = new ListNode(0);
        cur = cur->next; cur->next = new ListNode(1);
        cur = cur->next; cur->next = common;

        ListNode *startPoint = implObj->getIntersectionNode160(headA, headB);
        cout << "Please exam start point in debugger\n\n";
        return;
    }

    // 161. One Edit Distance Test
    void isOneEditDistance161Test() {
        cout << "161. One Edit Distance test starts.\n";
        cout << "1213 and 1203 are the same? [" 
            << (implObj->isOneEditDistance161("1213", "1203") ? "True" : "False")
            << "]\n\n";
        return;
    }

    // 162. Find Peak Element Test
    void findPeakElement162Test() {
        cout << "162. Find Peak Element test starts.\n";
        vector<int> arr = {1,2,11,3,5,6,4};
        cout << "Peak index = " << implObj->findPeakElement162(arr) << "\n\n";
        return;
    }

    // 163. Missing Ranges Test
    void findMissingRanges163Test() {
        cout << "163. Missing Ranges test starts.\n";
        vector<int> arr = {0, 1, 3, 50, 75};
        vector<string> result = implObj->findMissingRanges163(arr, 0, 99);
        cout << "Result array = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 164. Maximum Gap Test
    void maximumGap164Test() {
        cout << "164. Maximum Gap test starts.\n";
        vector<int> nums = {3,6,9,1};
        cout << "Result = [" << implObj->maximumGap164(nums) << "]\n\n";
        return;
    }

    // 165. Compare Version Numbers Test
    void compareVersion165Test() {
        cout << "165. Compare Version Numbers test starts.\n";
        string ver_1 = "1.0.1";
        string ver_2 = "1";
        cout << "Compare result = [" << implObj->compareVersion165(ver_1, ver_2) 
            << "]\n\n";
        return;
    }

    // 166. Fraction to Recurring Decimal Test
    void fractionToDecimal166Test() {
        cout << "166. Fraction to Recurring Decimal test starts.\n";
        cout << "1/2 = [" << implObj->fractionToDecimal166(1, 2) << "]\n";
        cout << "2/1 = [" << implObj->fractionToDecimal166(2, 1) << "]\n";
        cout << "2/3 = [" << implObj->fractionToDecimal166(2, 3) << "]\n\n";
        return;
    }

    // 167. Two Sum II - Input array is sorted Test
    void twoSum167Test() {
        cout << "167. Two Sum II - Input array is sorted test starts.\n";
        vector<int> arr = {2,7,11,15};
        vector<int> result = implObj->twoSum167(arr, 9);
        cout << "result [0] = " << result[0] << "; [1] = " << result[1] << "\n\n";
        return;
    }

    // 168. Excel Sheet Column Title Test
    void convertToTitle168Test() {
        cout << "168. Excel Sheet Column Title test starts.\n";
        cout << "52 = " << implObj->convertToTitle168(52) << "\n\n";
        return;
    }

    // 169. Majority Element Test
    void majorityElement169Test() {
        cout << "169. Majority Element test starts.\n";
        vector<int> nums = {2,2,1,1,1,2,2};
        cout << "result = [" << implObj->majorityElement169(nums) << "]\n\n";
        return;
    }

    // 170. Two Sum III - Data structure design Test
    void TwoSum170Test() {
        cout << "170. Two Sum III - Data structure design test starts.\n";
        Session1Impl::TwoSum170 twoSum;
        twoSum.add(1); twoSum.add(3); twoSum.add(5);
        cout << "Find 4 = " << (twoSum.find(4) ? "True" : "False") << "\n";
        cout << "Find 7 = " << (twoSum.find(7) ? "True" : "False") << "\n\n";
        return;
    }

    // 171. Excel Sheet Column Number Test
    void titleToNumber171Test() {
        cout << "171. Excel Sheet Column Number test starts.\n";
        cout << "AA = [" << implObj->titleToNumber171("AA") << "]\n\n";
        return;
    }


    // 173. Binary Search Tree Iterator Test
    void BSTIterator173Test() {
        cout << "173. Binary Search Tree Iterator test starts.\n";
        TreeNode * root = new TreeNode(7);
        TreeNode * cur = root;
        cur->left = new TreeNode(3);
        cur->right = new TreeNode(15);
        cur = cur->right;
        cur->left = new TreeNode(9);
        cur->right = new TreeNode(20);

        Session1Impl::BSTIterator173 iterator(root);
        cout << "Next = [" << iterator.next() << "]\n";    // return 3
        cout << "Next = [" << iterator.next() << "]\n";    // return 7
        cout << "hasNext = [" << iterator.hasNext() << "]\n"; // return true
        cout << "Next = [" << iterator.next() << "]\n";    // return 3
        cout << "hasNext = [" << iterator.hasNext() << "]\n"; // return true
        cout << "Next = [" << iterator.next() << "]\n";    // return 3
        cout << "hasNext = [" << iterator.hasNext() << "]\n"; // return true
        cout << "Next = [" << iterator.next() << "]\n";    // return 3
        cout << "hasNext = [" << iterator.hasNext() << "]\n\n"; // return true
        return;
    }

    // 174. Dungeon Game Test
    void calculateMinimumHP174Test() {
        cout << "174. Dungeon Game test starts.\n";
        vector<vector<int>> dungeon = {
            {-2, -3, 3},
            {-5, -10, 1},
            {10, 30, -5}
        };

        cout << "Min HP = [" << implObj->calculateMinimumHP174(dungeon) << "]\n\n";
        return;
    }

    // 179. Largest Number Test
    void largestNumber179Test() {
        cout << "179. Largest Number test starts.\n";
        vector<int> nums1 = {10,2};
        cout << "[10,2]->[" << implObj->largestNumber179(nums1) << "]\n";
        vector<int> nums2 = {3,30,34,5,9};
        cout << "[3,30,34,5,9]->[" << implObj->largestNumber179(nums2) << "]\n\n";
        return;
    }

    // 186. Reverse Words in a String II Test
    void reverseWords186Test() {
        cout << "186. Reverse Words in a String II test starts.\n";
        vector<char> s = {
            't', 'h', 'e', ' ',
            's', 'k', 'y', ' ',
            'i', 's', ' ',
            'b', 'l', 'u', 'e'
        };
        implObj->reverseWords186(s);
        cout << "Reverse `the sky is blue` = [";
        for (int i = 0; i < s.size(); ++i) {
            cout << s[i] << ((i == s.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

    // 187. Repeated DNA Sequences Test
    void findRepeatedDnaSequences187Test() {
        cout << "187. Repeated DNA Sequences test starts.\n";
        vector<string> result 
            = implObj->findRepeatedDnaSequences187("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

    // 188. Best Time to Buy and Sell Stock IV Test
    void maxProfit188Test() {
        cout << "188. Best Time to Buy and Sell Stock IV test starts.\n";
        vector<int> prices = {3, 2, 6, 5, 0, 3};
        cout << "max profit = [" << implObj->maxProfit188(2, prices) << "]\n\n";
        return;
    }

    // 189. Rotate Array Test
    void rotate189Test() {
        cout << "189. Rotate Array test starts.\n";
        vector<int> nums = {1,2,3,4,5,6,7};
        implObj->rotate189(nums, 3);
        cout << "result [";
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << ((i == nums.size() - 1) ? "" : ",");
        }
        cout << "]\n\n";
    }

    // 190. Reverse Bits Test
    void reverseBits190Test() {
        cout << "190. Reverse Bits test starts.\n";
        cout << "Reverse 00000010100101000001111010011100 = ["
            << implObj->reverseBits190(43261596) << "]\n\n";
        return;
    }

    // 198. House Robber Test
    void rob198Test() {
        cout << "198. House Robber test starts.\n";
        vector<int> nums = {1,2,3,1};
        cout << "Max money = [" << implObj->rob198(nums) << "]\n\n";
        return;
    }

    // 199. Binary Tree Right Side View
    void rightSideView199Test() {
        cout << "199. Binary Tree Right Side View test starts.\n";
        TreeNode * root = new TreeNode(-10);
        TreeNode * cur = root;
        cur->left = new TreeNode(9);
        cur->right = new TreeNode(20);
        cur = cur->right;
        cur->left = new TreeNode(15); cur->right = new TreeNode(7);

        vector<int> result = implObj->rightSideView199(root);
        cout << "Right side view vector [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "].\n\n";
        return;
    }

    // 200. Number of Islands Test
    void numIslands200Test() {
        cout << "200. Number of Islands test starts.\n";
        vector<vector<char>> grid = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
        };
        cout << "Num of islands = [" << implObj->numIslands200(grid) << "]\n\n";
    }

private:
    Session1Impl * implObj;
};

#endif