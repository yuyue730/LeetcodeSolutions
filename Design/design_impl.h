#ifndef _DESIGN_IMPL_H
#define _DESIGN_IMPL_H

#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

// 208. Implement Trie (Prefix Tree)
struct TrieNode {
    TrieNode * child[26];
    bool is_word;

    TrieNode() {
        is_word = false;
        for (int i = 0; i < 26; ++i) {
            child[i] = NULL;
        }
    }
};

class Trie208 {
public:
    /** Initialize your data structure here. */
    Trie208() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int next_idx = word[i] - 'a';
            if (!cur->child[next_idx]) {
                cur->child[next_idx] = new TrieNode();
            }
            cur = cur->child[next_idx];
        }

        cur->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int next_idx = word[i] - 'a';
            if (!cur->child[next_idx]) {
                return false;
            }
            cur = cur->child[next_idx];
        }

        return cur->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * cur = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int next_idx = prefix[i] - 'a';
            if (!cur->child[next_idx]) {
                return false;
            }
            cur = cur->child[next_idx];
        }

        return true;
    }

private:
    TrieNode * root;
};

// 211. Add and Search Word - Data structure design
class WordDictionary211 {
public:
    /** Initialize your data structure here. */
    WordDictionary211() {
        d_root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode * cur = d_root;
        for (int i = 0; i < word.size(); ++i) {
            int next_idx = word[i] - 'a';
            if (!cur->child[next_idx]) {
                cur->child[next_idx] = new TrieNode();
            }
            cur = cur->child[next_idx];
        }

        cur->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchRec(word, d_root, 0);
    }

private:
    TrieNode * d_root;

    bool searchRec(const string word, TrieNode * cur, int cur_idx) {
        if (cur_idx == word.size()) {
            return cur->is_word;
        }

        if (word[cur_idx] == '.') {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (cur->child[c - 'a']) {
                    if (searchRec(word, cur->child[c - 'a'], cur_idx + 1)) {
                        return true;
                    }
                }
            }

            return false;
        } else {
            if (cur->child[word[cur_idx] - 'a']) {
                return searchRec(word, cur->child[word[cur_idx] - 'a'], cur_idx + 1);
            } else {
                return false;
            }
        }
    }
};

// 225. Implement Stack using Queues
class MyStack225 {
public:
    /** Initialize your data structure here. */
    MyStack225() { }
    
    /** Push element x onto stack. */
    void push(int x) {
        front_queue.push(x);
        while (front_queue.size() > 1) {
            data_queue.push(front_queue.front());
            front_queue.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int to_return = top();
        front_queue.pop();
        return to_return;
    }
    
    /** Get the top element. */
    int top() {
        if (front_queue.empty()) {
            for (int i = 0; i < data_queue.size() - 1; ++i) {
                data_queue.push(data_queue.front());
                data_queue.pop();
            }
            front_queue.push(data_queue.front());
            data_queue.pop();
        }
        return front_queue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return front_queue.empty() && data_queue.empty();
    }

private:
    queue<int> front_queue;
    queue<int> data_queue;
};

// 232. Implement Queue using Stacks
class MyQueue232 {
public:
    /** Initialize your data structure here. */
    MyQueue232() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        while (!q_stack.empty()) {
            temp.push(q_stack.top());
            q_stack.pop();
        }

        temp.push(x);
        while (!temp.empty()) {
            q_stack.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = q_stack.top();
        q_stack.pop();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        return q_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q_stack.empty();
    }

private:
    stack<int> q_stack;
};

// 284. Peeking Iterator
class Iterator {
public:
    struct Data {
        vector<int> d_arr;

        Data(vector<int> nums) {
            d_arr.clear();
            for (auto i : nums) {
                d_arr.push_back(i);
            }
        }
    };

	Data* data;

    int d_idx;

public:
	Iterator(const vector<int>& nums) {
        data = new Data(nums);
        d_idx = 0;
    }

	Iterator(const Iterator& iter) { }

	virtual ~Iterator() { }

	// Returns the next element in the iteration.
	int next() {
        int result = data->d_arr[d_idx];
        d_idx++;
        return result;
    }

	// Returns true if the iteration has more elements.
	bool hasNext() const {
        return (d_idx < data->d_arr.size());
    }
};

class PeekingIterator284 : public Iterator {
public:
	PeekingIterator284(const vector<int>& nums) : Iterator(nums) {
        d_peek = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!d_peek) {
            d_cur_peek = Iterator::next();
            d_peek = true;
        }

        return d_cur_peek;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (d_peek) {
            d_peek = false;
            return d_cur_peek;
        } else {
            return Iterator::next();
        }
	}

	bool hasNext() const {
	    return d_peek || Iterator::hasNext();
	}

private:
    int d_cur_peek;
    bool d_peek;
};

// 295. Find Median from Data Stream
class MedianFinder295 {
public:
    MedianFinder295() { }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();

        while (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() == large.size()) {
            return 0.5 * (small.top() - large.top());
        } else {
            return small.top();
        }
    }

private:
    priority_queue<int> small, large;
};

// 297. Serialize and Deserialize Binary Tree
class Codec297 {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }

        ostringstream out;
        queue<TreeNode *> node_q;
        node_q.push(root);

        while (!node_q.empty()) {
            TreeNode * cur = node_q.front();
            node_q.pop();
            if (cur) {
                out << to_string(cur->val) << " ";
                node_q.push(cur->left);
                node_q.push(cur->right);
            } else {
                out << "# ";
            }
        }

        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        istringstream in(data);
        string cur_str;
        in >> cur_str;
        int cur_val = stoi(cur_str);
        TreeNode * root = new TreeNode(cur_val);
        queue<TreeNode *> node_q;
        node_q.push(root);
        while (!node_q.empty()) {
            TreeNode * cur = node_q.front();
            node_q.pop();

            string next_left;
            if (!(in >> next_left)) {
                break;
            }
            if (next_left != "#") {
                int left_val = stoi(next_left);
                cur->left = new TreeNode(left_val);
                node_q.push(cur->left);
            }
            
            string next_right;
            if (!(in >> next_right)) {
                break;
            }
            if (next_right != "#") {
                int right_val = stoi(next_right);
                cur->right = new TreeNode(right_val);
                node_q.push(cur->right);
            }
        }

        return root;
    }
};

// 341. Flatten Nested List Iterator
/*
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            st.push(nestedList[i]);
        }
    }

    int next() {
        int result = st.top().getInteger();
        st.pop();
        return result;
    }

    bool hasNext() {
        while (!st.empty()) {
            NestedInteger cur = st.top();
            if (cur.isInteger()) {
                return true;
            }
            st.pop();
            
            for (int i = cur.getList().size() - 1; i >= 0; --i) {
                st.push(cur.getList()[i]);
            }
        }
        return false;
    }
    
private:
    stack<NestedInteger> st;
};
*/

// 346. Moving Average from Data Stream
class MovingAverage346 {
public:
    /** Initialize your data structure here. */
    MovingAverage346(int size) {
        m_size = size;
        m_curSum = 0;
    }
    
    double next(int val) {
        if (m_window.size() == m_size) {
            m_curSum -= m_window.front();
            m_window.pop();
        }

        m_curSum += val;
        m_window.push(val);
        return static_cast<double>(m_curSum) / m_window.size();
    }

private:
    int m_size;
    int m_curSum;
    queue<int> m_window;
};

// 348. Design Tic-Tac-Toe
class TicTacToe348 {
public:
    /** Initialize your data structure here. */
    TicTacToe348(int n) {
        board.resize(n, vector<int>(n, 0));
        m_size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (board[row][col] != 0) {
            throw "Cannot play on non zero grid";
        }

        board[row][col] = player;
        int i = 1;
        while (i < m_size) {
            if (board[i][col] != board[i - 1][col]) {
                break;
            }
            ++i;
        }
        if (i == m_size) {
            return player;
        }

        int j = 1;
        while (j < m_size) {
            if (board[row][j] != board[row][j - 1]) {
                break;
            }
            ++j;
        }
        if (j == m_size) {
            return player;
        }

        if (col == row) {
            int m = 1;
            while (m < m_size) {
                if (board[m][m] != board[m - 1][m - 1]) {
                    break;
                }
                ++m;
            }
            if (m == m_size) {
                return player;
            }
        }

        if (row + col == m_size - 1) {
            int n = 1;
            while (n < m_size) {
                if (board[n][m_size - n - 1] != board[n - 1][m_size - n]) {
                    break;
                }
                ++n;
            }
            if (n == m_size) {
                return player;
            }
        }

        return 0;
    }

private:
    vector<vector<int>> board;
    int m_size;
};

// 353. Design Snake Game
class SnakeGame353 {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame353(int width, int height, vector<vector<int>>& food) {
        m_height = height;
        m_width = width;
        m_score = 0;

        for (int i = 0; i < food.size(); ++i) {
            m_food.push_back({food[i][0], food[i][1]});
        }

        m_snake.push_back({0, 0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto head = m_snake.front(), tail = m_snake.back();
        m_snake.pop_back();

        if (direction == "U") {
            head.first--;
        } else if (direction == "D") {
            head.first++;
        } else if (direction == "L") {
            head.second--;
        } else if (direction == "R") {
            head.second++;
        }

        if (head.first < 0 || head.first >= m_height || 
            head.second < 0 || head.second >= m_width || 
            count(m_snake.begin(), m_snake.end(), head))
        {
            return -1;
        }

        m_snake.insert(m_snake.begin(), head);
        if (!m_food.empty() && m_food.front() == head) {
            ++m_score;
            m_food.erase(m_food.begin());
            m_snake.push_back(tail);
        }

        return m_score;
    }

private:
    vector<pair<int, int>> m_food, m_snake;
    int m_height, m_width, m_score;
};

// 355. Design Twitter
class Twitter355 {
public:
    /** Initialize your data structure here. */
    Twitter355() {
        m_time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        m_person_tweets_map[userId].insert({m_time, tweetId});
        m_time++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        m_person_friends_map[userId].insert(userId);

        map<int, int> latest10;

        for (auto each_friend: m_person_friends_map[userId]) {
            for (auto each_tweet: m_person_tweets_map[each_friend]) {
                latest10.insert(each_tweet);
                while (latest10.size() > 10) {
                    latest10.erase(latest10.begin());
                }
            }
        }

        vector<int> result;
        for (auto each: latest10) {
            result.push_back(each.second);
        }
        reverse(result.begin(), result.end());

        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        m_person_friends_map[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        m_person_friends_map[followerId].erase(followeeId);
    }

private:
    unordered_map<int, unordered_set<int>> m_person_friends_map;
    unordered_map<int, unordered_map<int, int>> m_person_tweets_map;
    int m_time;
};

#endif