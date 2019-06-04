#include "graph_impl.h"

#include <unordered_set>
#include <queue>
using namespace std;

GraphImpl::GraphImpl() {
    cout << "Impl object for Leetcode Graph problems constructed.\n";
}

// 126. Word Ladder II
vector<vector<string>> GraphImpl::findLadders126(
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