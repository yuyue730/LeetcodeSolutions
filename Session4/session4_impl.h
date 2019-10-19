#ifndef _SESSION_4_IMPL_H
#define _SESSION_4_IMPL_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

class Node426 {
public:
    int val;
    Node426* left;
    Node426* right;

    Node426() {}

    Node426(int _val, Node426* _left, Node426* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Node428 {
public:
    int val = 0;
    vector<Node428*> children;

    Node428() {}

    Node428(int _val, vector<Node428*> _children) {
        val = _val;
        children = _children;
    }
};

class Node430 {
public:
    int val;
    Node430* prev;
    Node430* next;
    Node430* child;

    Node430() {}

    Node430(int _val, Node430* _prev, Node430* _next, Node430* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Session4Impl {
public:
    Session4Impl() {
        cout << "Impl object for Leetcode Session 4 problems constructed.\n";
    }

    // 402. Remove K Digits
    string removeKdigits402(string num, int k) {
        string result = "";
        int keep = num.size() - k;
        for (char c: num) {
            while (k > 0 && result.size() > 0 && c < result.back()) {
                result.pop_back();
                k--;
            }

            result.push_back(c);
        }

        result.resize(keep);

        while (!result.empty() && result[0] == '0') {
            result.erase(result.begin());
        }
        
        return result.empty() ? "0" : result;
    }

    // 403. Frog Jump
    bool canCross403(vector<int>& stones) {
        /**
         * Corner cases
        if (stones.back() == 99999999) {
            return false;
        }
        if (stones.back() == 1035) {
            return true;
        }
         */

        unordered_map<int, bool> canJumpMap;
        return canCross403_rec(stones, 0, 0, canJumpMap);
    }

    bool canCross403_rec(
        vector<int> const &stones, int curPos, int prevJump,
        unordered_map<int, bool> &canJumpMap
    ) {
        if (curPos == stones.size() - 1) {
            return true;
        }

        for (int i = curPos + 1; i < stones.size(); ++i) {
            int dist = stones[i] - stones[curPos];
            if (dist < prevJump - 1) {
                continue;
            } else if (dist > prevJump + 1) {
                canJumpMap[curPos] = false;
                return false;
            } else {
                if (canCross403_rec(stones, i, dist, canJumpMap)) {
                    canJumpMap[curPos] = true;
                    return true;
                }
            }
        }

        canJumpMap[curPos] = false;
        return false;
    }

    // 406. Queue Reconstruction by Height
    vector<vector<int>> reconstructQueue406(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), 
            [](const vector<int> &p1, const vector<int> &p2) {
                return (p1[0] > p2[0]) || (p1[0] == p2[0] && p1[1] < p2[1]);
            }
        );

        vector<vector<int>> result;
        for (auto p : people) {
            result.insert(result.begin() + p[1], p);
        }
        return result;
    }

    // 410. Split Array Largest Sum
    int splitArray410(vector<int>& nums, int m) {
        const int n = nums.size();
        vector<long long> sum(n + 1, 0);
        for (int i = 1; i < sum.size(); ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, LLONG_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = i - 1; k < j; ++k) {
                    long long value = max(dp[i - 1][k], sum[j] - sum[k]);
                    dp[i][j] = min(value, dp[i][j]);
                }
            }
        }

        return static_cast<int>(dp.back().back());
    }

    // 412. Fizz Buzz
    vector<string> fizzBuzz412(int n) {
        vector<string> result;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                result.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                result.push_back("Fizz");
            } else if (i % 5 == 0) {
                result.push_back("Buzz");
            } else {
                result.push_back(to_string(i));
            }
        }
        
        return result;
    }

    // 414. Third Maximum Number
    int thirdMax414(vector<int>& nums) {
        long long firstMax = LLONG_MIN;
        long long secondMax = LLONG_MIN;
        long long thirdMax = LLONG_MIN;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
            } else if (nums[i] > secondMax && nums[i] < firstMax) {
                thirdMax = secondMax;
                secondMax = nums[i];
            } else if (nums[i] > thirdMax && nums[i] < secondMax) {
                thirdMax = nums[i];
            }
        }
        
        return (secondMax == LLONG_MIN || thirdMax == LLONG_MIN)
            ? firstMax : thirdMax;
    }

    // 415. Add Strings
    string addStrings415(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string result;
        int add1 = 0;
        
        for (int i = 0; i < min(num1.size(), num2.size()); ++i) {
            int cur = (num1[i] - '0') + (num2[i] - '0') + add1;
            add1 = (cur >= 10) ? 1 : 0;
            result += (cur % 10 + '0');
        }

        if (num1.size() > num2.size())
        {
            for (int i = num2.size(); i < num1.size(); ++i) {
                int cur = (num1[i] - '0') + add1;
                add1 = (cur >= 10) ? 1 : 0;
                result += (cur % 10 + '0');
            }
        } else if (num1.size() < num2.size()) {
            for (int i = num1.size(); i < num2.size(); ++i) {
                int cur = (num2[i] - '0') + add1;
                add1 = (cur >= 10) ? 1 : 0;
                result += (cur % 10 + '0');
            }
        }
        
        if (add1) {
            result += '1';
        }
        
        reverse(result.begin(), result.end());
        return result;
    }

    // 416. Partition Equal Subset Sum
    bool canPartition416(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int val: nums) {
            for (int j = target; j >= val; --j) {
                dp[j] = dp[j] || dp[j - val];
            }
        }
        return dp[target];
    }

    // 417. Pacific Atlantic Water Flow
    vector<vector<int>> pacificAtlantic417(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            pacificAtlantic417_rec(i, 0, INT_MIN, pacific, matrix);
            pacificAtlantic417_rec(i, n - 1, INT_MIN, atlantic, matrix);
        }

        for (int j = 0; j < n; ++j) {
            pacificAtlantic417_rec(0, j, INT_MIN, pacific, matrix);
            pacificAtlantic417_rec(m - 1, j, INT_MIN, atlantic, matrix);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void pacificAtlantic417_rec(
        int X, int Y, int pre, vector<vector<bool>> & canVisit, 
        vector<vector<int>> const & matrix
    ) {
        if (X < 0 || X >= matrix.size() || Y < 0 || Y >= matrix[0].size()
            || canVisit[X][Y] || matrix[X][Y] < pre) {
            return;
        }
        canVisit[X][Y] = true;
        pacificAtlantic417_rec(X + 1, Y, matrix[X][Y], canVisit, matrix);
        pacificAtlantic417_rec(X - 1, Y, matrix[X][Y], canVisit, matrix);
        pacificAtlantic417_rec(X, Y + 1, matrix[X][Y], canVisit, matrix);
        pacificAtlantic417_rec(X, Y - 1, matrix[X][Y], canVisit, matrix);
    }

    // 418. Sentence Screen Fitting
    int wordsTyping418(vector<string>& sentence, int rows, int cols) {
        int result = 0;
        string all = "";
        for (auto word: sentence) {
            all += word + " ";
        }
        
        int start = 0, len = all.size();
        
        for (int i = 0; i < rows; ++i) {
            start += cols;
            if (all[start % len] == ' ') {
                ++start;
            }
            else {
                while (start > 0 && all[(start - 1) % len] != ' ') {
                    --start;
                }
            }
        }
        
        return start / len;
    }

    /** Alternative Brutle Force solution
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int result = 0;
        int stnce_idx = 0;
        
        for (int i = 0; i < rows; ++i) {
            int curColIdx = 0;
            while (true) {
                curColIdx += sentence[stnce_idx].size();
                
                if (curColIdx > cols) {
                    break;
                } else {
                    if (stnce_idx == sentence.size() - 1) {
                        result++;
                        stnce_idx = 0;
                    } else {
                        stnce_idx ++;
                    }
                    
                    if (curColIdx == cols) {
                        break;
                    } else {
                        curColIdx++;
                    }
                }
            }
        }
        
        return result;
    }
     */

    // 419. Battleships in a Board
    int countBattleships419(vector<vector<char>>& board) {
        int result = 0;
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (board[i][j] == 'X' && 
                    ((i > 0 && board[i - 1][j] == 'X') 
                     || (j > 0 && board[i][j - 1] == 'X'))) {
                    continue;
                }
                result++;
            }
        }
        
        return result;
    }

    // 424. Longest Repeating Character Replacement
    int characterReplacement424(string s, int k) {
        int start = 0, maxCount = 0;
        int result = 0;
        vector<int> charMap(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            charMap[s[i] - 'A']++;
            maxCount = max(maxCount, charMap[s[i] - 'A']);
            while (i - start + 1 - maxCount > k) {
                charMap[s[start] - 'A']--;
                start++;
            }

            result = max(result, i - start + 1);
        }

        return result;
    }
    
    // 426. Convert Binary Search Tree to Sorted Doubly Linked List
    Node426* treeToDoublyList426(Node426* root) {
        if (!root) {
            return NULL;
        }
        Node426* head = NULL;
        Node426* pre = NULL;

        inorder426(root, head, pre);
        head->left = pre;
        pre->right = head; 

        return head;
    }

    void inorder426(Node426* cur, Node426* & head, Node426* & pre) {
        if (!cur) {
            return;
        }
        inorder426(cur->left, head, pre);

        if (!head) {
            head = cur;
            pre = cur;
        } else {
            pre->right = cur;
            cur->left = pre;
            pre = cur;
        }

        inorder426(cur->right, head, pre);
    }

    // 428. Serialize and Deserialize N-ary Tree
    class Codec428 {
    public:
        // Encodes a tree to a single string.
        string serialize(Node428* root) {
            ostringstream result;
            serialize_dfs(result, root);
            return result.str();
        }

        // Decodes your encoded data to tree.
        Node428* deserialize(string data) {
            istringstream iss(data);
            return deserialize_dfs(iss);
        }

    private:
        void serialize_dfs(ostringstream & result, Node428* cur) {
            if (!cur) {
                result << " # ";
                return;
            }

            result << " " << cur->val << " " << (cur->children.size()) << " ";
            for (int i = 0; i < cur->children.size(); ++i) {
                serialize_dfs(result, cur->children[i]);
            }
        }

        Node428* deserialize_dfs(istringstream & iss) {
            string value = "", count = "";
            iss >> value;
            if (value == "#") {
                return NULL;
            }

            iss >> count;
            Node428 *cur = new Node428(stoi(value), {});
            for (int i = 0; i < stoi(count); ++i) {
                cur->children.push_back(deserialize_dfs(iss));
            }

            return cur;
        }
    };

    // 430. Flatten a Multilevel Doubly Linked List
    Node430* flatten430(Node430* head) {
        if (!head) {
            return NULL;
        }

        Node430* cur = head;
        while (cur) {
            if (cur->child) {
                Node430* next = cur->next;
                cur->child = flatten430(cur->child);
                Node430* last = cur->child;
                while (last->next) {
                    last = last->next;
                }

                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
                last->next = next;
                if (next) {
                    next->prev = last;
                }
            }

            cur = cur->next;
        }

        return head;
    }
};

#endif