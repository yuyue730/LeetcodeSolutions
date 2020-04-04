#ifndef _SESSION_6_IMPL_H
#define _SESSION_6_IMPL_H

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

class Session6Impl {
public:
    Session6Impl() {
        cout << "Impl object for Leetcode Session 6 problems constructed.\n";
    }

    // 604. Design Compressed String Iterator
    class StringIterator604 {
    public:
        StringIterator604(string compressedString) {
            istringstream iss(compressedString);
            char curChar = ' ';
            int curFreq = 0;
            while (iss >> curChar >> curFreq) {
                charFreqQ.push({curChar, curFreq});
            }
        }
        
        char next() {
            if (!hasNext()) {
                return ' ';
            }

            int curChar = charFreqQ.front().first;
            charFreqQ.front().second--;
            if (charFreqQ.front().second == 0) {
                charFreqQ.pop();
            }
            return curChar;
        }
        
        bool hasNext() {
            return !charFreqQ.empty();
        }
    
    private:
        queue<pair<char, int>> charFreqQ;
    };

    // 605. Can Place Flowers
    bool canPlaceFlowers605(vector<int>& flowerbed, int n) {
        if (flowerbed.empty()) {
            return 0;
        }
        if (flowerbed[0] == 0) {
            flowerbed.insert(flowerbed.begin(), 0);
        }
        if (flowerbed.back() == 0) {
            flowerbed.push_back(0);
        }

        int count = 0, result = 0;
        for (int i = 0; i <= flowerbed.size(); ++i) {
            if (i < flowerbed.size() && flowerbed[i] == 0) {
                count++;
            }
            else {
                result += (count - 1) / 2;
                count = 0;
            }
        }
        return (result >= n);
    }
};

#endif