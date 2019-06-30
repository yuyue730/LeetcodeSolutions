#ifndef _GRAPH_IMPL_H
#define _GRAPH_IMPL_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

// For Problem 133
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class GraphImpl {
public:
    GraphImpl() {
        cout << "Impl object for Leetcode Graph problems constructed.\n";
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

    // 133. Clone Graph
    Node* cloneGraph133(Node* node) {
        unordered_map<Node *, Node *> curNewMap;
        return cloneGraph133DFS(node, curNewMap);
    }

    Node* cloneGraph133DFS(
        Node *node, 
        unordered_map<Node *, Node *> & curNewMap
    ) {
        if (node == NULL) {
            return NULL;
        }
        if (curNewMap.count(node)) {
            return curNewMap[node];
        }
        Node* clone = new Node();
        clone->val = node->val;
        curNewMap[node] = clone;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            clone->neighbors.push_back(cloneGraph133DFS(node->neighbors[i], curNewMap));
        }
        return clone;
    }

    // 207. Course Schedule
    bool canFinish207(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> directed_graph(numCourses, vector<int>(0));
        vector<int> node_requisite(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); ++i) {
            directed_graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++node_requisite[prerequisites[i][0]];
        }

        queue<int> course_bfs;
        for (int i = 0; i < node_requisite.size(); ++i) {
            if (node_requisite[i] == 0) {
                course_bfs.push(i);
            }
        }

        while (!course_bfs.empty()) {
            int cur_course = course_bfs.front();
            course_bfs.pop();
            for (int i = 0; i < directed_graph[cur_course].size(); ++i) {
                int next_course = directed_graph[cur_course][i];
                --node_requisite[next_course];
                if (node_requisite[next_course] == 0) {
                    course_bfs.push(next_course);
                }
            }
        }

        for (int i = 0; i < node_requisite.size(); ++i) {
            if (node_requisite[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

#endif