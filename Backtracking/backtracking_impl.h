#ifndef _BACKTRACKING_IMPL_H
#define _BACKTRACKING_IMPL_H

#include <iostream>
#include <vector>
using namespace std;

class BacktrackingImpl {
public:
    BacktrackingImpl();

    // 17. Letter Combinations of a Phone Number
    vector<string> letterCombinations17(string digits);

    // 22. Generate Parentheses
    vector<string> generateParenthesis22(int n);

private:
    // 17. Letter Combinations of a Phone Number helper
    void generateLetterCombRec(
            const vector<string>& digitLetterMap, const string digits, 
            int curIdx, string curResult, vector<string> & result);

    // 22. Generate Parentheses helper
    void generateParenthesisRec(int left, int right, string curStr, vector<string> & result);
};

#endif