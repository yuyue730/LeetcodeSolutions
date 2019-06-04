#include "graph_test.h"

GraphTest::GraphTest() {
    cout << "Test object for Leetcode Graph problems constructed.\n";
    implObj = new GraphImpl();
}

// 126. Word Ladder II Test
void GraphTest::findLadders126Test() {
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