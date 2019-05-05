#ifndef _DP_IMPL_H
#define _DP_IMPL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DpImpl {
public:
    DpImpl();

    // 44. Wildcard Matching
    bool isMatch44(string s, string p);

    // 64. Minimum Path Sum
    int minPathSum64(vector<vector<int>>& grid);
};

#endif