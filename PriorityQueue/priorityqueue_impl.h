#ifndef _PRIORITYQUEUE_IMPL_H
#define _PRIORITYQUEUE_IMPL_H

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class PriorityQueueImpl {
public:
    PriorityQueueImpl() {
        cout << "Impl object for Leetcode Priority Queue problems constructed.\n";
    }

    // 215. Kth Largest Element in an Array
    int findKthLargest215(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }
        
        return pq.top();
    }

    // 218. The Skyline Problem
    struct SkylineNode {
        int d_x;
        int d_height;
        char d_type; // "L" or "R"

        SkylineNode(int x, int height, char type)
            : d_x(x), d_height(height), d_type(type) {}
    };

    vector<vector<int>> getSkyline218(vector<vector<int>>& buildings) {
        vector<SkylineNode> allNodes;
        for (int i = 0; i < buildings.size(); ++i) {
            allNodes.push_back(SkylineNode(buildings[i][0], buildings[i][2], 'L'));
            allNodes.push_back(SkylineNode(buildings[i][1], buildings[i][2], 'R'));
        }

        sort(
            allNodes.begin(), allNodes.end(), 
            [] (const SkylineNode & a, const SkylineNode & b) {
                if (a.d_x != b.d_x) {
                    return a.d_x < b.d_x;
                }
                if (a.d_type == 'L' && b.d_type == 'L') {
                    return a.d_height > b.d_height;
                }
                if (a.d_type == 'R' && b.d_type == 'R') {
                    return a.d_height < b.d_height;
                }
                return a.d_type == 'L';
            }
        );

        vector<vector<int>> result;
        priority_queue<int> height_heap;
        height_heap.push(0);
        unordered_map<int, int> delete_map;
        int cur_height = 0, pre_height = 0;

        for (int i = 0; i < allNodes.size(); ++i) {
            if (allNodes[i].d_type == 'L') {
                height_heap.push(allNodes[i].d_height);
            } else {
                delete_map[allNodes[i].d_height]++;
                while (!height_heap.empty() && delete_map[height_heap.top()]) {
                    delete_map[height_heap.top()]--;
                    height_heap.pop();
                }
            }

            cur_height = height_heap.top();
            if (cur_height != pre_height) {
                result.push_back({allNodes[i].d_x, cur_height});
                pre_height = cur_height;
            }
        }

        return result;
    }
};

#endif