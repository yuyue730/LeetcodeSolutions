#ifndef _SESSION_5_IMPL_H
#define _SESSION_5_IMPL_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Session5Impl {
public:
    Session5Impl() {
        cout << "Impl object for Leetcode Session 5 problems constructed.\n";
    }

    // 503. Next Greater Element II
    vector<int> nextGreaterElements503(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> stk;

        for (int i = 0; i < n * 2; ++i) {
            int curNum = nums[i % n];
            while (!stk.empty() && nums[stk.top()] < curNum) {
                result[stk.top()] = curNum;
                stk.pop();
            }

            if (i < n) {
                stk.push(i);
            }
        }

        return result;
    }

    // 505. The Maze II
    int shortestDistance505(
        vector<vector<int>>& maze, vector<int>& start, 
        vector<int>& destination) {
        if (maze.empty() || maze[0].empty()) {
            return -1;
        }

        const int m = maze.size();
        const int n = maze[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        vector<vector<int>> const direction = {
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}
        };
        distance[start[0]][start[1]] = 0;
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (auto iter: direction) {
                int x = cur.first;
                int y = cur.second;
                int curDist = distance[cur.first][cur.second];
                
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] != 1) {
                    x += iter[0];
                    y += iter[1];
                    curDist++;
                }

                x -= iter[0];
                y -= iter[1];
                curDist--;

                if (curDist < distance[x][y]) {
                    distance[x][y] = curDist;
                    if (x != destination[0] || y != destination[1]) {
                        q.push({x, y});
                    }
                }
            }
        }

        return (distance[destination[0]][destination[1]] == INT_MAX) 
            ? -1 : distance[destination[0]][destination[1]];
    }
};

#endif