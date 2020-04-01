#ifndef _SESSION_1_IMPL_H
#define _SESSION_1_IMPL_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Node133 {
public:
    int val;
    vector<Node133*> neighbors;

    Node133() {}

    Node133(int _val, vector<Node133*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Node138 {
public:
    int val;
    Node138* next;
    Node138* random;

    Node138() {}

    Node138(int _val, Node138* _next, Node138* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Session1Impl {
public:
    Session1Impl() {
        cout << "Impl object for Leetcode Session 1 problems constructed.\n";
    }

    // 101. Symmetric Tree
    bool isSymmetric101(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSymmetric101DFS(root->left, root->right);
    }

    bool isSymmetric101DFS(
        TreeNode *left, TreeNode *right
    ) {
        if (left == NULL && right == NULL) {
            return true;
        }

        if (left == NULL || right == NULL) {
            return false;
        }

        if (left->val != right->val) {
            return false;
        }

        return isSymmetric101DFS(left->left, right->right)
            && isSymmetric101DFS(left->right, right->left);
    }

    // 102. Binary Tree Level Order Traversal
    vector<vector<int>> levelOrder102(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode *> curQ;
        curQ.push(root);

        while (!curQ.empty()) {
            vector<int> curLevelVec;
            for (int i = curQ.size(); i > 0; --i) {
                TreeNode *cur = curQ.front();
                curQ.pop();
                curLevelVec.push_back(cur->val);
                if (cur->left) {
                    curQ.push(cur->left);
                }
                if (cur->right) {
                    curQ.push(cur->right);
                }
            }

            result.push_back(curLevelVec);
        }

        return result;
    }

    // 103. Binary Tree Zigzag Level Order Traversal
    vector<vector<int>> zigzagLevelOrder103(TreeNode* root)
    {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }

        stack<TreeNode *> * curLevel = new stack<TreeNode *>();
        bool isLeft = false;
        curLevel->push(root);

        while (!curLevel->empty()) {
            vector<int> curResult;
            stack<TreeNode *> * nextLevel = new stack<TreeNode *>();

            while (!curLevel->empty()) {
                TreeNode * cur = curLevel->top();
                curLevel->pop();
                curResult.push_back(cur->val);
                if (isLeft) {
                    if (cur->left)
                        nextLevel->push(cur->left);
                    if (cur->right)
                        nextLevel->push(cur->right);
                } else {
                    if (cur->right)
                        nextLevel->push(cur->right);
                    if (cur->left)
                        nextLevel->push(cur->left);
                }
            }

            result.push_back(curResult);
            curLevel = nextLevel;
            isLeft = !isLeft;
        }

        return result;
    }

    // 104. Maximum Depth of Binary Tree (DFS)
    int maxDepth104(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(maxDepth104(root->left), maxDepth104(root->right));
    }

    // 105. Construct Binary Tree from Preorder and Inorder Traversal
    TreeNode* buildTree105(
        vector<int>& preorder, vector<int>& inorder
    ) {
        int preLeft = 0, preRight = preorder.size() - 1;
        int inLeft = 0, inRight = inorder.size() - 1;
        return buildTree105helper(
            preorder, 0, preorder.size() - 1,
            inorder, 0, inorder.size() - 1
        );
    }

    TreeNode * buildTree105helper(
        const vector<int>& pre, int preLeft, int preRight,
        const vector<int>& in, int inLeft, int inRight
    ) {
        if (preLeft > preRight || inLeft > inRight) {
            return NULL;
        }

        int i = inLeft;
        for (; i <= inRight; ++i) {
            if (in[i] == pre[preLeft]) {
                break;
            }
        }

        TreeNode * root = new TreeNode(pre[preLeft]);
        root->left = buildTree105helper(
            pre, preLeft + 1, preLeft + i - inLeft,
            in, inLeft, i - 1
        );
        root->right = buildTree105helper(
            pre, preLeft + i - inLeft + 1, preRight,
            in, i + 1, inRight
        );
        return root;
    }

    // 106. Construct Binary Tree from Inorder and Postorder Traversal
    TreeNode * buildTree106(
        vector<int>& inorder, vector<int>& postorder
    ) {
        int inLeft = 0, inRight = inorder.size() - 1;
        int postLeft = 0, postRight = postorder.size() - 1;
        return buildTree106helper(
            inorder, 0, inorder.size() - 1,
            postorder, 0, postorder.size() - 1
        );
    }

    TreeNode * buildTree106helper(
        const vector<int>& in, int inLeft, int inRight, 
        const vector<int>& post, int postLeft, int postRight
    ) {
        if (inLeft > inRight || postLeft > postRight) {
            return NULL;
        }

        TreeNode * cur = new TreeNode(post[postRight]);
        int i = inLeft;
        for (; i <= inRight; ++i) {
            if (in[i] == cur->val) {
                break;
            }
        }

        cur->left = buildTree106helper(
            in, inLeft, i - 1, post, postLeft, postLeft + i - inLeft - 1
        );
        cur->right = buildTree106helper(
            in, i + 1, inRight, post, postLeft + i - inLeft, postRight - 1
        );

        return cur;
    }

    // 107. Binary Tree Level Order Traversal II
    vector<vector<int>> levelOrderBottom107(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        queue<TreeNode *> layer_q({root});
        while (!layer_q.empty()) {
            vector<int> cur_layer;
            int pre_layer_size = layer_q.size();
            for (int i = 0; i < pre_layer_size; ++i) {
                TreeNode * cur = layer_q.front();
                layer_q.pop();
                cur_layer.push_back(cur->val);
                if (cur->left) {
                    layer_q.push(cur->left);
                }
                if (cur->right) {
                    layer_q.push(cur->right);
                }
            }
            result.insert(result.begin(), cur_layer);
        }
        return result;
    }

    // 108. Convert Sorted Array to Binary Search Tree
    TreeNode * sortedArrayToBST108(vector<int>& nums) {
        return sortedArrayToBST108helper(nums, 0, nums.size() - 1);
    }

    TreeNode * sortedArrayToBST108helper(
        const vector<int>& arr, int left, int right
    ) {
        if (left > right) {
            return NULL;
        }

        int mid = (left + right) / 2;
        TreeNode * cur = new TreeNode(arr[mid]);

        cur->left = sortedArrayToBST108helper(arr, left, mid - 1);
        cur->right = sortedArrayToBST108helper(arr, mid + 1, right);
        return cur;
    }

    // 109. Convert Sorted List to Binary Search Tree
    TreeNode * sortedListToBST109(ListNode* head) {
        if (head == NULL) {
            return NULL;
        } 
        if (head->next == NULL) {
            return new TreeNode(head->val);
        }

        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * last = slow;
        while (fast->next && fast->next->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        last->next = NULL;

        TreeNode * root = new TreeNode(slow->val);
        if (slow != head) {
            root->left = sortedListToBST109(head);
        }
        root->right = sortedListToBST109(fast);
        return root;
    }

    // 110. Balanced Binary Tree
    bool isBalanced110(TreeNode* root)
    {
        return (checkDepth110(root) != -1);
    }

    int checkDepth110(TreeNode * cur)
    {
        if (cur == NULL) {
            return 0;
        }

        int leftDepth = checkDepth110(cur->left);
        if (leftDepth == -1) {
            return -1;
        }
        int rightDepth = checkDepth110(cur->right);
        if (rightDepth == -1) {
            return -1;
        }

        if (abs(leftDepth - rightDepth) > 1) 
            return -1;
        else return max(leftDepth, rightDepth) + 1;
    }

    // 111. Minimum Depth of Binary Tree
    int minDepth111(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int result = INT_MAX;
        minDepth_rec(root, result, 1);
        return result;
    }
    
    void minDepth_rec(TreeNode* curNode, int& result, int curDepth) {
        if (!curNode->left && !curNode->right) {
            result = min(result, curDepth);
            return;
        }
        
        if (curNode->left) {
            minDepth_rec(curNode->left, result, curDepth + 1);
        }
        if (curNode->right) {
            minDepth_rec(curNode->right, result, curDepth + 1);
        }
    }

    // 112. Path Sum
    bool hasPathSum112(TreeNode* root, int sum)
    {
        if (root == NULL || sum < 0) {
            return false;
        }

        if (root->left == NULL && root->right == NULL) {
            return true;
        }

        return hasPathSum112(root->left, sum - root->val)
            || hasPathSum112(root->right, sum - root->val);
    }

    // 113. Path Sum II
    vector<vector<int>> pathSum113(TreeNode* root, int sum) {
        vector<vector<int>> allResults;
        if (root == NULL) {
            return allResults;
        }
        vector<int> curResult;
        pathSum113helper(curResult, allResults, sum, root);
        return allResults;
    }

    void pathSum113helper(
        vector<int> & curResult,
        vector<vector<int>> & allResults,
        int remain,
        TreeNode * cur
    ) {
        if (cur == NULL) {
            return;
        }

        curResult.push_back(cur->val);

        if (remain == cur->val && cur->left == NULL && cur->right == NULL) {
            allResults.push_back(curResult);
            curResult.pop_back();
            return;
        }

        pathSum113helper(curResult, allResults, remain - cur->val, cur->left);
        pathSum113helper(curResult, allResults, remain - cur->val, cur->right);
        curResult.pop_back();
    }

    // 114. Flatten Binary Tree to Linked List
    void flatten114(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        if (root->left) {
            flatten114(root->left);
        }
        if (root->right) {
            flatten114(root->right);
        }

        TreeNode * tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right) {
            root = root->right;
        }
        root->right = tmp;
    }

    // 115. Distinct Subsequences
    int numDistinct115(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        for (int j = 0; j < dp[0].size(); ++j) {
            dp[0][j] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i][j - 1] + ((s[j - 1] == t[i - 1]) ? dp[i - 1][j - 1] : 0);
            }
        }

        return static_cast<int>(dp.back().back());
    }

    // 116. Populating Next Right Pointers in Each Node
    // 117. Populating Next Right Pointers in Each Node II
    Node* connect116(Node* root) {
        if (!root) {
            return NULL;
        }

        vector<Node *> * curLevel = new vector<Node *>();
        curLevel->push_back(root);
        while (!curLevel->empty()) {
            vector<Node *> * nextLevel = new vector<Node *>();

            for (int i = 0; i < curLevel->size(); ++i) {
                if (i < curLevel->size() - 1) {
                    curLevel->at(i)->next = curLevel->at(i + 1);
                }

                if ((*curLevel)[i]->left) {
                    nextLevel->push_back((*curLevel)[i]->left);
                }
                if ((*curLevel)[i]->right) {
                    nextLevel->push_back((*curLevel)[i]->right);
                }
            }

            curLevel = nextLevel;
        }

        return root;
    }

    // 118. Pascal's Triangle
    vector<vector<int>> generate118(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) {
            return result;
        }
        result.push_back({1});

        for (int i = 2; i <= numRows; ++i) {
            vector<int> curRow(i, 0);
            for (int j = 0; j < i; ++j) {
                if (j == 0) {
                    curRow[0] = result.back()[0];
                } else if (j == i - 1) {
                    curRow[i - 1] = result.back().back();
                } else {
                    curRow[j] = result.back()[j - 1] + result.back()[j];
                }
            }
            result.push_back(curRow);
        }

        return result;
    }

    // 119. Pascal's Triangle II
    vector<int> getRow119(int rowIndex) {
        vector<int> * cur = new vector<int>(1, 1);
        for (int i = 1; i <= rowIndex; ++i) {
            vector<int> * next = new vector<int>(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                (*next)[j] = (*cur)[j - 1] + (*cur)[j];
            }
            
            cur = next;
        }
        
        return *cur;
    }

    // 120. Triangle
    int minimumTotal120(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) {
            return triangle[0][0];
        }

        vector<int> * dp = &(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; --i) {
            vector<int> * nextDp = new vector<int>(i + 1);
            for (int j = 0; j < nextDp->size(); ++j) {
                nextDp->at(j) = min(dp->at(j), dp->at(j + 1)) + triangle[i][j];
            }
            dp = nextDp;
        }
        return dp->at(0);
    }

    // 121. Best Time to Buy and Sell Stock
    int maxProfit121(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int minPrice = prices[0], maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }

        return maxProfit;
    }

    // 122. Best Time to Buy and Sell Stock II
    int maxProfit122(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] >= prices[i - 1]) {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        
        return profit;
    }

    // 123. Best Time to Buy and Sell Stock III
    int maxProfit123(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        vector<int> leftMaxProfit(prices.size(), 0);
        int localMinPrice = prices[0];
        int curMaxLeftProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < localMinPrice) {
                localMinPrice = prices[i];
            }
            else {
                curMaxLeftProfit = max(
                    curMaxLeftProfit, prices[i] - localMinPrice
                );
            }
            leftMaxProfit[i] = curMaxLeftProfit;
        }

        int result = leftMaxProfit.back();
        int localMaxPrice = prices.back();
        int curMaxRightProfit = 0;
        for (int i = prices.size() - 2; i >= 0; --i) {
            if (prices[i] > localMaxPrice) {
                localMaxPrice = prices[i];
            } else {
                curMaxRightProfit = max(
                    curMaxRightProfit, localMaxPrice - prices[i]
                );
            }
            result = max(result, leftMaxProfit[i] + curMaxRightProfit);
        }

        return result;
    }

    // 124. Binary Tree Maximum Path Sum
    int maxPathSum124(TreeNode* root)
    {
        if (root == NULL) {
            return 0;
        }

        int result = INT_MIN;
        maxPathSum124helper(root, result);
        return result;
    }

    int maxPathSum124helper(TreeNode * cur, int & result)
    {
        if (cur == NULL) {
            return 0;
        }

        int left = max(maxPathSum124helper(cur->left, result), 0);
        int right = max(maxPathSum124helper(cur->right, result), 0);
        result = max(result, left + right + cur->val);
        return max(left, right) + cur->val;
    }

    // 125. Valid Palindrome
    bool isPalindrome125(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            if (!isalpha(s[left]) && !isdigit(s[left])) {
                ++left;
            } else if (!isalpha(s[right]) && !isdigit(s[right])) {
                --right;
            } else {
                if (toupper(s[left]) != toupper(s[right])) {
                    return false;
                } else {
                    ++left; --right;
                }
            }
        }
        return true;
    }

    // 126. Word Ladder II
    vector<vector<string>> findLadders126(
        string beginWord, 
        string endWord, 
        vector<string>& wordList
    ) {
        vector<vector<string>> result;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<string> initialPath({beginWord});
        queue<vector<string>> pathQ;
        pathQ.push(initialPath);
        unordered_set<string> visitedWords;
        int curLevel = 1, minLevel = INT_MIN;

        while (!pathQ.empty()) {
            vector<string> curPath = pathQ.front();
            pathQ.pop();
            if (curPath.size() > curLevel) {
                for (string curWord : visitedWords) {
                    dict.erase(curWord);    
                }
                visitedWords.clear();
                if (curPath.size() > minLevel) {
                    break;
                }
                curLevel = curPath.size();
            }

            string frontier = curPath.back();
            for (int i = 0; i < frontier.size(); ++i) {
                string newWord = frontier;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (ch == frontier[i]) {
                        continue;
                    }

                    newWord[i] = ch;
                    if (dict.count(newWord) == 0) {
                        continue;
                    }
                    visitedWords.insert(newWord);
                    vector<string> nextPath = curPath;
                    nextPath.push_back(newWord);
                    if (newWord == endWord) {
                        result.push_back(nextPath);
                        minLevel = curLevel;
                    }
                    pathQ.push(nextPath);
                }
            }
        }

        return result;
    }

    // 127. Word Ladder
    int ladderLength127(
        string beginWord, 
        string endWord, 
        vector<string>& wordList
    ) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return 0;
        }

        unordered_map<string, int> wordLevelMap;
        wordLevelMap.insert({beginWord, 1});
        queue<string> wordQ({beginWord});

        while (!wordQ.empty()) {
            string curWord = wordQ.front();
            wordQ.pop();
            for (int i = 0; i < curWord.size(); ++i) {
                string newWord = curWord;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (ch == curWord[i]) {
                        continue;
                    }
                    newWord[i] = ch;
                    if (dict.count(newWord) && newWord == endWord) {
                        return wordLevelMap[curWord] + 1;
                    }

                    if (dict.count(newWord) && !wordLevelMap.count(newWord)) {
                        wordLevelMap[newWord] = wordLevelMap[curWord] + 1;
                        wordQ.push(newWord);
                    }
                }
            }
        }
        return 0;
    }

    // 128. Longest Consecutive Sequence
    int longestConsecutive128(vector<int>& nums) {
        unordered_map<int, int> numLengthMap;
        int result = 0;
        for (int num : nums) {
            if (numLengthMap.count(num)) {
                continue;
            }
            int left = numLengthMap.count(num - 1) ? numLengthMap[num - 1] : 0;
            int right = numLengthMap.count(num + 1) ? numLengthMap[num + 1] : 0;
            int curLength = left + right + 1;
            numLengthMap[num - left] = curLength;
            numLengthMap[num + right] = curLength;
            result = max(result, curLength);
        }
        return result;
    }

    // 129. Sum Root to Leaf Numbers
    int sumNumbers128(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        vector<int> allNumbers;
        sumNumbers_dfs(allNumbers, 0, root);
        return accumulate(allNumbers.begin(), allNumbers.end(), 0);
    }
    
    void sumNumbers_dfs(vector<int> &allNumbers, int curVal, TreeNode* curNode) {
        curVal = curVal * 10 + curNode->val;
        
        if (!curNode->left && !curNode->right) {
            allNumbers.push_back(curVal);
        }
        
        if (curNode->left) {
            sumNumbers_dfs(allNumbers, curVal, curNode->left);
        }
        if (curNode->right) {
            sumNumbers_dfs(allNumbers, curVal, curNode->right);
        }
    }

    // 130. Surrounded Regions
    void solve130(vector<vector<char>>& board)
    {
        if (board.size() == 0) {
            return;
        }
        int mSize = board.size(), nSize = board[0].size();
        for (int i = 0; i < mSize; ++i) {
            for (int j = 0; j < nSize; ++j) {
                if (i == 0 || i == mSize - 1 || j == 0 || j == nSize - 1) {
                    solve130DFS(board, i, j);
                }
            }
        }

        for (int i = 0; i < mSize; ++i) {
            for (int j = 0; j < nSize; ++j) {
                if (board[i][j] == 'P') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void solve130DFS(
        vector<vector<char>>& board, int iIdx, int jIdx
    ) {
        int mSize = board.size(), nSize = board[0].size();
        if (board[iIdx][jIdx] == 'O') {
            board[iIdx][jIdx] = 'P';
            if (iIdx > 0 && board[iIdx - 1][jIdx] == 'O') {
                solve130DFS(board, iIdx - 1, jIdx);
            }
            if (iIdx < mSize - 1 && board[iIdx + 1][jIdx] == 'O') {
                solve130DFS(board, iIdx + 1, jIdx);
            }
            if (jIdx > 0 && board[iIdx][jIdx - 1] == 'O') {
                solve130DFS(board, iIdx, jIdx - 1);
            }
            if (jIdx < nSize - 1 && board[iIdx][jIdx + 1] == 'O') {
                solve130DFS(board, iIdx, jIdx + 1);
            }
        }
    }

    // 131. Palindrome Partitioning
    vector<vector<string>> partition131(string s)
    {
        vector<string> curRes;
        vector<vector<string>> allRes;
        partition131helper(s, 0, curRes, allRes);
        return allRes;
    }

    void partition131helper(
        const string s, int startIdx, 
        vector<string> & curRes, 
        vector<vector<string>> & allRes
    ) {
        if (startIdx == s.size()) {
            allRes.push_back(curRes);
            return;
        }

        for (int i = startIdx; i < s.size(); ++i) {
            if (isPalindrome(s, startIdx, i)) {
                curRes.push_back(s.substr(startIdx, i - startIdx + 1));
                partition131helper(s, i + 1, curRes, allRes);
                curRes.pop_back();
            }
        }
    }

    bool isPalindrome(const string s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++; right--;
        }
        return true;
    }

    // 132. Palindrome Partitioning II
    int minCut132(string s) {
        if (s.empty()) {
            return 0;
        }

        int nSize = s.size();
        vector<vector<bool>> palinState(nSize, vector<bool>(nSize, false));
        vector<int> dp(nSize);

        for (int i = 0; i < nSize; ++i) {
            dp[i] = i;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j < 2 || palinState[j + 1][i - 1])) {
                    palinState[j][i] = true;
                    dp[i] = (j == 0 ? 0 : min(dp[j - 1] + 1, dp[i]));
                }
            }
        }
        return dp[nSize - 1];
    }

    // 133. Clone Graph
    Node133* cloneGraph133(Node133* node) {
        unordered_map<Node133 *, Node133 *> curNewMap;
        return cloneGraph133DFS(node, curNewMap);
    }

    Node133* cloneGraph133DFS(
        Node133 *node, 
        unordered_map<Node133 *, Node133 *> & curNewMap
    ) {
        if (node == NULL) {
            return NULL;
        }
        if (curNewMap.count(node)) {
            return curNewMap[node];
        }
        Node133* clone = new Node133();
        clone->val = node->val;
        curNewMap[node] = clone;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            clone->neighbors.push_back(cloneGraph133DFS(node->neighbors[i], curNewMap));
        }
        return clone;
    }

    // 134. Gas Station
    int canCompleteCircuit134(vector<int>& gas, vector<int>& cost)
    {
        int total = 0, curMax = 0, curStart = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            curMax += gas[i] - cost[i];
            if (curMax < 0) {
                curMax = 0;
                curStart = i + 1;
            }
        }

        return (total < 0) ? -1 : curStart;
    }

    // 135. Candy
    int candy135(vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        }

        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i + 1] + 1, candies[i]);
            }
        }

        int result = 0;
        for (int i = 0; i < candies.size(); ++i) {
            result += candies[i];
        }

        return result;
    }

    // 136. Single Number
    int singleNumber136(vector<int>& nums) {
        int andValue = 0;
        for (int i = 0; i < nums.size(); ++i) {
            andValue ^= nums[i];
        }

        return andValue;
    }

    // 137. Single Number II
    int singleNumber137(vector<int>& nums) {
        int result = 0;
        for (int pos = 0; pos < 32; ++pos) {
            int curBitVal = 0;
            for (int i = 0; i < nums.size(); ++i) {
                curBitVal += (nums[i] >> pos) & 1;
            }

            result += (curBitVal % 3) << pos;
        }

        return result;
    }

    // 138. Copy List with Random Pointer
    Node138* copyRandomList138(Node138* head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node138 *, Node138 *> curNewMap;
        return copyRandomList138DFS(head, curNewMap);
    }

    Node138* copyRandomList138DFS(
        Node138 * cur, unordered_map<Node138 *, Node138 *> &curNewMap
    ) {
        if (cur == NULL) {
            return NULL;
        }

        if (curNewMap.count(cur)) {
            return curNewMap[cur];
        }
        Node138 * newNode = new Node138(cur->val, NULL, NULL);
        curNewMap[cur] = newNode;
        newNode->next = copyRandomList138DFS(cur->next, curNewMap);
        newNode->random = copyRandomList138DFS(cur->random, curNewMap);
        return newNode;
    }

    // 139. Word Break
    bool wordBreak139(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return true;
        }

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_set<string> dictSet(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string curWord = s.substr(j, i - j);
                dp[i] = dp[j] && dictSet.count(curWord);
                if (dp[i]) {
                    break;
                }
            }
        }

        return dp.back();
    }

    // 140. Word Break II
    vector<string> wordBreak140(
        string s, vector<string>& wordDict
    ) {
        unordered_map<string, vector<string>> strVecMap;
        return wordBreak140helper(s, wordDict, strVecMap);
    }

    vector<string> wordBreak140helper(
        string s, const vector<string> & wordDict, 
        unordered_map<string, vector<string>> & strVecMap
    ) {
        if (strVecMap.count(s)) {
            return strVecMap[s];
        }
        if (s == "") {
            return {""};
        }

        vector<string> result;
        for (int i = 0; i < wordDict.size(); ++i) {
            if (s.substr(0, wordDict[i].size()) != wordDict[i]) {
                continue;
            }

            vector<string> remainResult = wordBreak140helper(
                s.substr(wordDict[i].size()), wordDict, strVecMap
            );
            for (int remIdx = 0; remIdx < remainResult.size(); ++remIdx) {
                string curRemStr = remainResult[remIdx];
                result.push_back(
                    wordDict[i] + (curRemStr == "" ? "" : " ") + curRemStr
                );
            }
        }
        strVecMap[s] = result;
        return result;
    }

    // 141. Linked List Cycle
    bool hasCycle141(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    // 142. Linked List Cycle II
    ListNode *detectCycle142(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }

        if (!fast || !fast->next) {
            return NULL;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }

    // 143. Reorder List
    void reorderList143(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }

        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *pre = NULL, *cur = mid;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        while (head && pre) {
            ListNode *nextHead = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = nextHead;
            head = nextHead;
        }
    }

    // 144. Binary Tree Preorder Traversal
    vector<int> preorderTraversal144(TreeNode* root)
    {
        vector<int> result;
        if (root == NULL) {
            return result;
        }

        stack<TreeNode *> preStk({root});
        while (!preStk.empty()) {
            TreeNode *cur = preStk.top();
            preStk.pop();
            result.push_back(cur->val);
            if (cur->right) {
                preStk.push(cur->right);
            }
            if (cur->left) {
                preStk.push(cur->left);
            }
        }

        return result;
    }

    // 145. Binary Tree Postorder Traversal
    vector<int> postorderTraversal145(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }

        stack<TreeNode*> stk({root});
        TreeNode* head = root;

        while (!stk.empty()) {
            TreeNode* curTop = stk.top();
            if ((!curTop->left && !curTop->right) 
                || curTop->left == head || curTop->right == head) {
                result.push_back(curTop->val);
                head = curTop;
                stk.pop();
            } else {
                if (curTop->right)
                    stk.push(curTop->right);
                if (curTop->left)
                    stk.push(curTop->left);
            }
        }

        return result;
    }

    // 146. LRU Cache
    class LRUCache146 {
    public:
        LRUCache146(int capacity) {
            d_capacity = capacity;
        }
        
        int get(int key) {
            if (d_keyIterMap.count(key) == 0) {
                return -1;
            }

            list<pair<int, int>>::iterator iter = d_keyIterMap[key];
            d_list.splice(d_list.begin(), d_list, iter);
            return iter->second;
        }
        
        void put(int key, int value) {
            if (d_keyIterMap.count(key) != 0) {
                d_list.erase(d_keyIterMap[key]);
            }

            d_list.push_front(pair<int, int>(key, value));
            d_keyIterMap[key] = d_list.begin();

            if (d_keyIterMap.size() > d_capacity) {
                int backKey = d_list.back().first;
                d_keyIterMap.erase(backKey);
                d_list.pop_back();
            }
        }

    private:
        int d_capacity;
        list<pair<int, int>> d_list;
        unordered_map<int, list<pair<int, int>>::iterator> d_keyIterMap;
    };

    // 148. Sort List
    ListNode* sortList148(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = NULL;
        return mergeSortList(sortList148(head), sortList148(slow));
    }

    ListNode * mergeSortList(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode *dummy = new ListNode(-1), *cur = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        if (l1) {
            cur->next = l1;
        }
        if (l2) {
            cur->next = l2;
        }

        return dummy->next;
    }

    // 149. Max Points on a Line
    int maxPoints149(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        int result = 0;

        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> vecCtMap;
            int duplicate = 1;

            for (int j = i + 1; j < points.size(); ++j) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    duplicate++;
                } else {
                    int deltaX = points[j][0] - points[i][0];
                    int deltaY = points[j][1] - points[i][1];
                    int deltaGCD = greatestCommonFactor(deltaX, deltaY);

                    vecCtMap[make_pair(deltaX / deltaGCD, deltaY / deltaGCD)]++;
                }
            }

            result = max(result, duplicate);
            for (map<pair<int, int>, int>::iterator iter = vecCtMap.begin();
                iter != vecCtMap.end(); ++iter) {
                result = max(result, duplicate + iter->second);
            }
        }

        return result;
    }

    int greatestCommonFactor(int a, int b) {
        return b == 0 ? a : greatestCommonFactor(b, a % b);
    }

    // 150. Evaluate Reverse Polish Notation
    int evalRPN150(vector<string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }

        stack<int> valueStk;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" 
                || tokens[i] == "*" || tokens[i] == "/") {
                int second = valueStk.top(); valueStk.pop();
                int first = valueStk.top(); valueStk.pop();
                int curValue = 0;
                if (tokens[i] == "+") {
                    curValue = first + second;
                } else if (tokens[i] == "-") {
                    curValue = first - second;
                } else if (tokens[i] == "*") {
                    curValue = first * second;
                } else if (tokens[i] == "/") {
                    curValue = first / second;
                }
                valueStk.push(curValue);
            } else {
                valueStk.push(stoi(tokens[i]));
            }
        }

        return valueStk.top();
    }

    // 151. Reverse Words in a String
    string reverseWords151(string s) {
        if (s.empty()) {
            return "";
        }

        reverse(s.begin(), s.end());
        int curLastIndex = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (curLastIndex != 0) {
                    s[curLastIndex] = ' ';
                    curLastIndex++;
                }
                int curWordIdx = i;
                while (curWordIdx < s.size() && s[curWordIdx] != ' ') {
                    s[curLastIndex] = s[curWordIdx];
                    ++curLastIndex; ++curWordIdx;
                }

                reverse(
                    s.begin() + curLastIndex - (curWordIdx - i), 
                    s.begin() + curLastIndex
                );
                i = curWordIdx;
            }
        }

        return s.substr(0, curLastIndex);
    }

    // 152. Maximum Product Subarray
    int maxProduct152(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        vector<int> smallDp(nums.size(), 0);
        vector<int> largeDp(nums.size(), 0);
        smallDp[0] = largeDp[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            smallDp[i] = min(
                smallDp[i - 1] * nums[i], min(largeDp[i - 1] * nums[i], nums[i])
            );
            largeDp[i] = max(
                smallDp[i - 1] * nums[i], max(largeDp[i - 1] * nums[i], nums[i])
            );
            result = max(result, largeDp[i]);
        }

        return result;
    }

    // 153. Find Minimum in Rotated Sorted Array
    int findMin153(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int left = 0, right = nums.size() - 1;
        if (nums[left] > nums[right]) {
            while (left != right - 1) {
                int mid = (left + right) / 2;
                if (nums[mid] > nums[right]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            return min(nums[left], nums[right]);
        } else {
            return nums[0];
        }     
    }

    // 154. Find Minimum in Rotated Sorted Array II
    int findMin154(vector<int>& nums) {
        return findMin154_rec(nums, 0, nums.size() - 1);
    }

    int findMin154_rec(vector<int>& nums, int left, int right) {
        if (right - left <= 1) {
            return min(nums[left], nums[right]);
        }

        if (nums[left] < nums[right]) {
            return nums[left];
        }

        int mid = (left + right) / 2;
        return min(
            findMin154_rec(nums, left, mid),
            findMin154_rec(nums, mid + 1, right));
    }

    // 155. Min Stack
    class MinStack155 {
    public:
        MinStack155() { }
        
        void push(int x) {
            if (d_minStk.empty() || x <= d_minStk.top()) {
                d_minStk.push(x);
            }

            d_valStk.push(x);
        }
        
        void pop() {
            if (d_minStk.top() == d_valStk.top()) {
                d_minStk.pop();
            }
            d_valStk.pop();
        }
        
        int top() {
            return d_valStk.top();
        }
        
        int getMin() {
            return d_minStk.top();
        }

    private:
        stack<int> d_valStk;
        stack<int> d_minStk;
    };

    // The following read4 implementation is used by Problem 157 and Problem 158
    string d_fileStr = "";
    int d_curPos = 0;

    void setFileStr(string str) {
        d_fileStr = str;
        d_curPos = 0;
    }

    int read4(char *buf) {
        if (d_curPos >= d_fileStr.size()) {
            return 0;
        }
        
        string toReturn = (d_curPos + 4 >= d_fileStr.size()) 
            ? d_fileStr.substr(d_curPos)
            : d_fileStr.substr(d_curPos, 4);
    
        for (int i = 0; i < toReturn.size(); ++i) {
            (*(buf + i)) = toReturn.at(i);
        }
        d_curPos += toReturn.size();
        return toReturn.size();
    }

    // 157. Read N Characters Given Read4
    int read157(char *buf, int n) {
        int nCharCt = 0;
        for (int i = 0; i <= n / 4; ++i) {
            int curReadSize = read4(buf + nCharCt);
            if (curReadSize == 0) {
                break;
            }
            nCharCt += curReadSize;
        }

        return min(nCharCt, n);
    }

    // 158. Read N Characters Given Read4 II - Call multiple times
    queue<char> d_bufferQ;
    bool isEndOfFile = false;
    int read158(char *buf, int n) {
        while (d_bufferQ.size() <= n && !isEndOfFile) {
            char * temp = new char[4];
            int curReadCt = read4(temp);
            if (curReadCt < 4) {
                isEndOfFile = true;
            }

            for (int i = 0; i < curReadCt; ++i) {
                d_bufferQ.push(temp[i]);
            }
        }

        int outLen = n < d_bufferQ.size() ? n : d_bufferQ.size();
        for (int i = 0; i < outLen; ++i) {
            buf[i] = d_bufferQ.front();
            d_bufferQ.pop();
        }
        return outLen;
    }

    // 159. Longest Substring with At Most Two Distinct Characters
    int lengthOfLongestSubstringTwoDistinct159(string s) {
        unordered_map<char, int> charFreqMap;
        int result = 0, left = 0;

        for (int i = 0; i < s.size(); ++i) {
            ++charFreqMap[s[i]];
            while (charFreqMap.size() > 2) {
                --charFreqMap[s[left]];
                if (charFreqMap[s[left]] == 0) {
                    charFreqMap.erase(s[left]);
                }
                ++left;
            }

            result = max(result, i - left + 1);
        }

        return result;
    }

    // 160. Intersection of Two Linked Lists
    ListNode * getIntersectionNode160(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        int lenA = getLinkedListLength(headA);
        int lenB = getLinkedListLength(headB);

        if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; ++i) {
                headB = headB->next;
            }
        } else {
            for (int i = 0; i < lenA - lenB; ++i) {
                headA = headA->next;
            }
        }

        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return (headA == headB) ? headA : NULL;
    }

    int getLinkedListLength(ListNode *head) {
        int result = 0;
        ListNode * cur = head;
        while (cur) {
            ++result;
            cur = cur->next;
        }

        return result;
    }

    // 161. One Edit Distance
    bool isOneEditDistance161(string s, string t) {
        if (s.length() < t.length()) {
            swap(s, t);
        }

        if (s.length() - t.length() >= 2) {
            return false;
        } else if (s.length() - t.length() == 1) {
            for (int i = 0; i < t.length(); ++i) {
                if (s[i] != t[i]) {
                    return s.substr(i + 1) == t.substr(i);
                }
            }
            return true;
        } else {
            int ct = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] != t[i]) {
                    ++ct;
                }
            }

            return ct == 1;
        }
    }

    // 162. Find Peak Element
    int findPeakElement162(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return right;
    }

    // 163. Missing Ranges
    vector<string> findMissingRanges163(vector<int>& nums, int lower, int upper) {
        int left = lower;
        vector<string> result;
        for (int i = 0; i <= nums.size(); ++i) {
            long long right = (i != nums.size()) 
                ? nums[i] : static_cast<long long>(upper) + 1;
            if (left == right) {
                left = right + 1;
            } else if (right > left) {
                string curResult = (right - left == 1)
                    ? to_string(left) : (to_string(left) + "->" + to_string(right - 1));
                result.push_back(curResult);
                left = right + 1;
            }
        }
        return result;
    }

    // 164. Maximum Gap
    int maximumGap164(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        int g_max = INT_MIN, g_min = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            g_max = max(g_max, nums[i]);
            g_min = min(g_min, nums[i]);
        }

        int n_size = nums.size();
        int b_size = (g_max - g_min) / n_size + 1;
        int b_ct = (g_max - g_min) / b_size + 1;

        vector<pair<int, int>> b_minmax(b_ct, {INT_MAX, INT_MIN});
        for (int i = 0; i < n_size; ++i) {
            int b_id = (nums[i] - g_min) / b_size;
            b_minmax[b_id].first = min(b_minmax[b_id].first, nums[i]);
            b_minmax[b_id].second = max(b_minmax[b_id].second, nums[i]);
        }

        int pre = 0;
        int result = 0;
        for (int i = 1; i < b_ct; ++i) {
            if (b_minmax[i].first == INT_MAX || b_minmax[i].second == INT_MIN) {
                continue;
            }

            result = max(result, b_minmax[i].first - b_minmax[pre].second);
            pre = i;
        }

        return result;
    }

    // 165. Compare Version Numbers
    int compareVersion165(string version1, string version2) {
        int idx1 = 0, idx2 = 0, n1 = version1.size(), n2 = version2.size();
        while (idx1 < n1 || idx2 < n2) {
            string v1Str = "0", v2Str = "0"; 
                // Compiler throws when stoi is called with an empty string
            while (idx1 < n1 && version1[idx1] != '.') {
                v1Str.push_back(version1[idx1]);
                idx1++;
            }
            int cur_ver_1 = stoi(v1Str);

            while (idx2 < n2 && version2[idx2] != '.') {
                v2Str.push_back(version2[idx2]);
                idx2++;
            }
            int cur_ver_2 = stoi(v2Str);

            if (cur_ver_1 > cur_ver_2) {
                return 1;
            } else if (cur_ver_1 < cur_ver_2) {
                return -1;
            }

            ++idx1;
            ++idx2;
        }
        return 0;
    }

    // 166. Fraction to Recurring Decimal
    string fractionToDecimal166(int numerator, int denominator) {
        if (numerator == 0) {
            return 0;
        }
        bool isPositive = (numerator > 0) == (denominator > 0);
        string result = isPositive ? "" : "-";

        long long num_abs = abs(static_cast<long long>(numerator));
        long long den_abs = abs(static_cast<long long>(denominator));

        long long int_part = num_abs / den_abs;
        long long remain = num_abs % den_abs;
        result += to_string(int_part);

        if (remain == 0) {
            return result;
        }
        result.push_back('.');
        string decimal_part("");
        unordered_map<long long, int> remain_position_map;
        int cur_position = 0;
        while (remain != 0) {
            if (remain_position_map.find(remain) != remain_position_map.end()) {
                decimal_part.insert(remain_position_map[remain], "(");
                decimal_part.push_back(')');
                return result + decimal_part;
            }

            remain_position_map[remain] = cur_position;
            decimal_part += to_string((remain * 10) / den_abs);
            remain = (remain * 10) % den_abs;
            cur_position++;
        }

        return result + decimal_part;
    }

    // 167. Two Sum II - Input array is sorted
    vector<int> twoSum167(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                return {left + 1, right + 1};
            } else if (numbers[left] + numbers[right] < target) {
                ++left;
            } else {
                --right;
            }
        }
        return {};
    }

    // 168. Excel Sheet Column Title
    string convertToTitle168(int n) {
        string res;
        while (n) {
            if (n % 26) {
                res += (n % 26) - 1 + 'A';
                n -= n % 26;
            } else {
                res += 'Z';
                n -= 26;
            }
            n /= 26;
        }

        reverse(res.begin(), res.end());
        return res;
    }

    // 169. Majority Element
    int majorityElement169(vector<int>& nums) {
        int count = 0, result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                result = nums[i];
                ++count;
            } else {
                (result == nums[i]) ? ++count : --count;
            }
        }

        return result;
    }

    // 170. Two Sum III - Data structure design
    class TwoSum170 {
    public:
        /** Initialize your data structure here. */
        TwoSum170() {}
        
        /** Add the number to an internal data structure.. */
        void add(int number) {
            numberFreqMap[number]++;
        }
        
        /** Find if there exists any pair of numbers which sum is equal to the value. */
        bool find(int value) {
            for (unordered_map<int, int>::iterator iter = numberFreqMap.begin();
                iter != numberFreqMap.end(); ++iter) {
                int toFind = value - iter->first;
                if (toFind == iter->first && iter->second > 1) {
                    return true;
                } else if (toFind != iter->first && numberFreqMap.count(toFind) > 0) {
                    return true;
                }
            }

            return false;
        }

    private:
        unordered_map<int, int> numberFreqMap;
    };

    // 171. Excel Sheet Column Number
    int titleToNumber171(string s) {
        int result = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            result = result * 26 + (s[i] - 'A' + 1);
        }
        
        return result;
    }
    
    // 172. Factorial Trailing Zeroes
    int trailingZeroes172(int n) {
        int result = 0;
        while (n > 0) {
            result += n / 5;
            n /= 5;
        }
        return result;
    }

    // 173. Binary Search Tree Iterator
    class BSTIterator173 {
    public:
        BSTIterator173(TreeNode* root) {
            while (root) {
                node_stk.push(root);
                root = root->left;
            }
        }
        
        /** @return the next smallest number */
        int next() {
            TreeNode * next = node_stk.top();
            int result = next->val;
            node_stk.pop();
            if (next->right) {
                TreeNode * cur = next->right;
                while (cur) {
                    node_stk.push(cur);
                    cur = cur->left;
                }
            }
            return result;
        }
        
        /** @return whether we have a next smallest number */
        bool hasNext() {
            return !node_stk.empty();
        }

    private:
        stack <TreeNode *> node_stk;
    };

    // 174. Dungeon Game
    int calculateMinimumHP174(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m - 1][n] = 1;
        dp[m][n - 1] = 1;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        }

        return dp[0][0];
    }

    // 179. Largest Number
    string largestNumber179(vector<int>& nums) {
        string result;
        struct numStrComparator {
            bool operator() (int a, int b) {
                return to_string(a) + to_string(b) > to_string(b) + to_string(a);
            }
        } myNumStrComp;
        sort(nums.begin(), nums.end(), myNumStrComp);
        for (int i = 0; i < nums.size(); ++i) {
            result += to_string(nums[i]);
        }
        return result[0] == '0' ? "0" : result;
    }

    // 186. Reverse Words in a String II
    void reverseWords186(vector<char>& s) {
        int pre = 0, last = 0;
        while (last < s.size()) {
            while (last < s.size() && s[last] != ' ') {
                last++;
            }

            reverse(s.begin() + pre, s.begin() + last);
            last++;
            pre = last;
        }
        
        reverse(s.begin(), s.end());
    }

    // 187. Repeated DNA Sequences
    vector<string> findRepeatedDnaSequences187(string s) {
        if (s.size() < 10) {
            vector<string> result;
            return result;
        }

        unordered_set<string> elementSet;
        unordered_set<string> resultSet;

        for (int i = 0; i <= s.size() - 10; ++i) {
            string curStr = s.substr(i, 10);
            if (elementSet.count(curStr)) {
                resultSet.insert(curStr);
            } else {
                elementSet.insert(curStr);
            }
        }
        return vector<string>(resultSet.begin(), resultSet.end());
    }

    // 188. Best Time to Buy and Sell Stock IV
    int maxProfit188(int k, vector<int>& prices) {
        int n = prices.size();

        if (n == 0) {
            return 0;
        }

        if (k > n) {
            int max_profit = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i - 1]) {
                    max_profit += prices[i] - prices[i - 1];
                }
            }
            return max_profit;
        }

        vector<int> local(k + 1, 0);
        vector<int> global(k + 1, 0);

        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = k; j >= 1; --j) {
                local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }

        return global.back();
    }

    // 189. Rotate Array
    void rotate189(vector<int>& nums, int k) {
        if (nums.empty()) {
            return;
        }

        k = k % nums.size();
        if (k == 0) {
            return;
        }
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    // 190. Reverse Bits
    uint32_t reverseBits190(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; ++i) {
            if ((n & 1) == 1) {
                result = (result << 1) + 1;
            } else {
                result = result << 1;
            }
            
            n = n >> 1;
        }
        
        return result;
    }

    // 191. Number of 1 Bits
    int hammingWeight191(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            if ((n & 1) == 1) {
                result++;
            }
            
            n = n >> 1;
        }
        
        return result;
    }

    // 198. House Robber
    int rob198(vector<int>& nums) {
        if (nums.size() <= 1) {
            return (nums.size() == 1) ? nums[0] : 0;
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back();
    }

    // 199. Binary Tree Right Side View
    vector<int> rightSideView199(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode *> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            result.push_back(node_queue.back()->val);
            int q_size = node_queue.size();
            for (int i = 0; i < q_size; ++i) {
                TreeNode * cur = node_queue.front();
                node_queue.pop();
                if (cur->left) {
                    node_queue.push(cur->left);
                }
                if (cur->right) {
                    node_queue.push(cur->right);
                }
            }
        }

        return result;
    }

    // 200. Number of Islands
    int numIslands200(vector<vector<char>>& grid) {
        int result = 0;
        if (grid.empty() || grid[0].empty()) {
            return result;
        }

        int n_size = grid.size(), m_size = grid[0].size();
        vector<vector<bool>> visited_matrix(n_size, vector<bool>(m_size, false));

        for (int i = 0; i < n_size; ++i) {
            for (int j = 0; j < m_size; ++j) {
                if (grid[i][j] == '1' && !visited_matrix[i][j]) {
                    visitIslandDFS(grid, visited_matrix, i, j);
                    ++result;
                }
            }
        }

        return result;
    }

    void visitIslandDFS(
        const vector<vector<char>>& grid,
        vector<vector<bool>> & visitedMatrix,
        int curI, int curJ
    ) {
        if (curI < 0 || curI >= grid.size()) {
            return;
        }
        if (curJ < 0 || curJ >= grid[0].size()) {
            return;
        }
        if (visitedMatrix[curI][curJ] || grid[curI][curJ] != '1') {
            return;
        }

        visitedMatrix[curI][curJ] = true;
        visitIslandDFS(grid, visitedMatrix, curI + 1, curJ);
        visitIslandDFS(grid, visitedMatrix, curI - 1, curJ);
        visitIslandDFS(grid, visitedMatrix, curI, curJ + 1);
        visitIslandDFS(grid, visitedMatrix, curI, curJ - 1);
    }
};

#endif