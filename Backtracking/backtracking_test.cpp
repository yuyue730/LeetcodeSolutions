#include "baccktracking_test.h"

#include <vector>
using namespace std;

BacktrackingTest::BacktrackingTest() {
    cout << "Test object for Leetcode Array problems constructed.\n";
    implObj = new BacktrackingImpl();
}

// 17. Letter Combinations of a Phone Number Test
void BacktrackingTest::letterCombinations17Test() {
    cout << "17. Letter Combinations of a Phone Number test starts.\n";
    vector<string> result = implObj->letterCombinations17("23");
    for (int i = 0; i < result.size(); ++i) {
        cout << "index " << i << "--" << result[i] << "; ";
    }

    cout << "\n\n";
    return;
}

// 22. Generate Parentheses Test
void BacktrackingTest::generateParenthesis22Test() {
    cout << "22. Generate Parentheses test starts.\n";
    vector<string> result = implObj->generateParenthesis22(3);
    for (int i = 0; i < result.size(); ++i) {
        cout << "index " << i << "--" << result[i] << "; ";
    }

    cout << "\n\n";
    return;
}