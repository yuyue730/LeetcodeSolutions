#ifndef _SESSION_3_TEST_H
#define _SESSION_3_TEST_H

#include "session3_impl.h"

class Session3Test {
public:
    Session3Test() {
        cout << "Test object for Leetcode Session 3 problems constructed.\n";
        implObj = new Session3Impl();
    }

    // 301. Remove Invalid Parentheses Test
    void removeInvalidParentheses301Test() {
        cout << "301. Remove Invalid Parentheses test starts.\n";
        string str = "()())()";
        vector<string> results = implObj->removeInvalidParentheses301(str);
        cout << "Result is [\n";
        for (int i = 0; i < results.size(); ++i) {
            cout << results[i] << ",\n";
        }
        cout << "]\n\n";
        return;
    }

    // 302. Smallest Rectangle Enclosing Black Pixels Test
    void minArea302Test() {
        cout << "302. Smallest Rectangle Enclosing Black Pixels test starts.\n";
        vector<vector<char>> pixels = {
            {'0', '0', '1', '0'},
            {'0', '1', '1', '0'},
            {'0', '1', '0', '0'}
        };
        cout << "Minimal area will be [" << implObj->minArea302(pixels, 0, 2) << "]\n\n";
    }

    // 303. Range Sum Query - Immutable Test
    void NumArray303Test() {
        cout << "303. Range Sum Query - Immutable test starts.\n";
        vector<int> nums = {-2, 0, 3, -5, 2, -1};

        Session3Impl::NumArray303 numArray(nums);
        int result1 = numArray.sumRange(0, 2);
        int result2 = numArray.sumRange(2, 5);
        int result3 = numArray.sumRange(0, 5);
        cout << "[0->2] sum = [" << result1 << "]; [2->5] sum = [" << result2 << "]"
            << "; [0->5] sum = [" << result3 << "]\n\n";
    }

    // 304. Range Sum Query 2D - Immutable Test
    void NumMatrix304Test() {
        cout << "304. Range Sum Query 2D - Immutable test starts.\n";
        vector<vector<int>> matrix = {
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
        };
        Session3Impl::NumMatrix304 impl(matrix);
        cout << "Sum = [" << impl.sumRegion(2, 1, 4, 3) << "]\n\n";
        return;
    }

    // 305. Number of Islands II Test
    void numIslands2_305Test() {
        cout << "305. Number of Islands II test starts.\n";
        vector<vector<int>> positions = {
            {0, 0}, {0, 1}, {1, 2}, {2, 1}
        };
        vector<int> result = implObj->numIslands2_305(3, 3, positions);
        cout << "# of islands after each step is [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

    // 306. Additive Number Test
    void isAdditiveNumber306Test() {
        cout << "306. Additive Number test starts.\n";
        cout << "Is additive = [" << implObj->isAdditiveNumber306("199100199") << "]\n\n";
        return;
    }

    // 309. Best Time to Buy and Sell Stock with Cooldown Test
    void maxProfit309Test() {
        cout << "309. Best Time to Buy and Sell Stock with Cooldown test starts.\n";
        vector<int> prices = {1, 2, 3, 0, 2};
        cout << "max profit = [" << implObj->maxProfit309(prices) << "]\n\n";
        return;
    }

    // 311. Sparse Matrix Multiplication Test
    void multiply311Test() {
        cout << "311. Sparse Matrix Multiplication test starts.\n";
        vector<vector<int>> A = {
            {1, 0, 0},
            {-1, 0, 3}
        };
        vector<vector<int>> B = {
            {7, 0, 0},
            {0, 0, 0},
            {0, 0, 1}
        };

        vector<vector<int>> result = implObj->multiply311(A, B);
        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[0].size(); ++j) {
                cout << result[i][j] << ((j == result[0].size() - 1) ? "": ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
        return;
    }

    // 312. Burst Balloons Test
    void maxCoins312Test() {
        cout << "312. Burst Balloons test starts.\n";
        vector<int> nums = {3, 1, 5, 8};
        cout << "max coins = [" << implObj->maxCoins312(nums) << "]\n\n";
        return;
    }

    // 314. Binary Tree Vertical Order Traversal Test
    void verticalOrder314Test() {
        cout << "314. Binary Tree Vertical Order Traversal test starts.\n";
        TreeNode * root = new TreeNode(3);
        TreeNode * cur = root;
        cur->left = new TreeNode(9);
        cur->right = new TreeNode(20);

        cur = cur->right;
        cur->left = new TreeNode(15);
        cur->right = new TreeNode(7);

        vector<vector<int>> result = implObj->verticalOrder314(root);
        cout << "Vector result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "[";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
        return;
    }

    // 315. Count of Smaller Numbers After Self Test
    void countSmaller315Test() {
        cout << "315. Count of Smaller Numbers After Self test starts.\n";
        vector<int> nums = {5, 2, 6, 1};
        vector<int> result = implObj->countSmaller315(nums);

        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 316. Remove Duplicate Letters Test
    void removeDuplicateLetters316Test() {
        cout << "316. Remove Duplicate Letters test starts.\n";
        cout << "Result = [" << implObj->removeDuplicateLetters316("cbacdcbc") << "]\n\n";
        return;
    }

    // 317. Shortest Distance from All Buildings Test
    void shortestDistance317Test() {
        cout << "317. Shortest Distance from All Buildings test starts.\n";
        vector<vector<int>> grid = {
            {1, 0, 2, 0, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0}
        };
        cout << "Distance = [" << implObj->shortestDistance317(grid) << "]\n\n";
        return;
    }

    // 319. Bulb Switcher Test
    void bulbSwitch319Test() {
        cout << "319. Bulb Switcher test starts.\n";
        cout << "36 will result in [" << implObj->bulbSwitch319(36) << "]\n\n";
        return;
    }

    // 321. Create Maximum Number Test
    void maxNumber321Test()
    {
        cout << "321. Create Maximum Number test starts.\n";
        vector<int> nums1 = {3, 4, 6, 5};
        vector<int> nums2 = {9, 1, 2, 5, 8, 3};
        vector<int> res = implObj->maxNumber321(nums1, nums2, 5);

        cout << "Merge result = [";
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << ((i == res.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 322. Coin Change Test
    void coinChange322Test() {
        cout << "322. Coin Change test starts.\n";
        vector<int> coins = {1, 2, 5};
        cout << "# of coins = [" << implObj->coinChange322(coins, 11) << "]\n\n";
        return;
    }

    // 329. Longest Increasing Path in a Matrix Test
    void longestIncreasingPath329Test() {
        cout << "329. Longest Increasing Path in a Matrix test starts.\n";
        vector<vector<int>> nums = {
            {9, 9, 4},
            {6, 6, 8},
            {2, 1, 1}
        };
        cout << "Max increasing length = [" << implObj->longestIncreasingPath329(nums) << "]\n\n";
        return;
    }

    // 332. Reconstruct Itinerary Test
    void findItinerary332Test() {
        cout << "332. Reconstruct Itinerary test starts.\n";
        vector<vector<string>> tickets = {
            {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}
        };

        vector<string> result = implObj->findItinerary332(tickets);
        cout << "result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 333. Largest BST Subtree Test
    void largestBSTSubtree333Test() {
        cout << "333. Largest BST Subtree test starts.\n";
        TreeNode *root = new TreeNode(10);
        TreeNode *cur = root;
        cur->left = new TreeNode(5);
        cur->right = new TreeNode(15);

        cur = cur->left;
        cur->left = new TreeNode(1);
        cur->right = new TreeNode(8);

        cur = root;
        cur->right = new TreeNode(15);
        cur = cur->right;
        cur->right = new TreeNode(7);

        cout << "Size of max BST = [" << implObj->largestBSTSubtree333(root) << "]\n\n";
        return;
    }

    // 334. Increasing Triplet Subsequence Test
    void increasingTriplet334Test() {
        cout << "334. Increasing Triplet Subsequence test.\n";
        vector<int> nums = {3, 2, 5, 4, 8, 1};
        cout << "Is increasing triplet = [" << implObj->increasingTriplet334(nums) << "]\n\n";
        return;
    }

    // 336. Palindrome Pairs Test
    void palindromePairs336Test() {
        cout << "336. Palindrome Pairs test starts.\n";
        vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
        vector<vector<int>> result = implObj->palindromePairs336(words);

        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [" << result[i][0] << ", " << result[i][1] << "]\n";
        }
        cout << "]\n\n";
        return;
    }

    // 340. Longest Substring with At Most K Distinct Characters Test
    void lengthOfLongestSubstringKDistinct340Test() {
        cout << "340. Longest Substring with At Most K Distinct Characters test starts.\n";
        cout << "eceba and 2 will have max length = [" 
            << implObj->lengthOfLongestSubstringKDistinct340("eceba", 2)
            << "]\n\n";
        return;
    }

    // 344. Reverse String Test
    void reverseString344Test() {
        cout << "344. Reverse String test starts.\n";
        vector<char> ch = {'h', 'e', 'l', 'l', 'o'};
        implObj->reverseString344(ch);
        cout << "result = [";
        for (int i = 0; i < ch.size(); ++i) {
            cout << ch[i];
        }
        cout << "]\n\n";
        return;
    }

    // 346. Moving Average from Data Stream Test
    void MovingAverage346Test() {
        cout << "346. Moving Average from Data Stream test starts.\n";
        Session3Impl::MovingAverage346 m(3);
        cout << "Push 1 = [" << (double)m.next(1) << "];\n";
        cout << "Push 10 = [" << (double)m.next(10) << "];\n";
        cout << "Push 3 = [" << (double)m.next(3) << "];\n";
        cout << "Push 5 = [" << (double)m.next(5) << "]\n\n";
        return;
    }

    // 347. Top K Frequent Elements Test
    void topKFrequent347Test() {
        cout << "347. Top K Frequent Elements test starts.\n";
        vector<int> nums = {1, 1, 1, 2, 2, 3};
        vector<int> result = implObj->topKFrequent347(nums, 2);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 348. Design Tic-Tac-Toe Test
    void TicTacToe348Test() {
        cout << "348. Design Tic-Tac-Toe test starts.\n";
        Session3Impl::TicTacToe348 toe(3);
        cout << "Step 1 (0,0,1) = [" << toe.move(0, 0, 1) << "]\n";
        cout << "Step 2 (0,2,2) = [" << toe.move(0, 2, 2) << "]\n";
        cout << "Step 3 (2,2,1) = [" << toe.move(2, 2, 1) << "]\n";
        cout << "Step 4 (1,1,2) = [" << toe.move(1, 1, 2) << "]\n";
        cout << "Step 5 (2,0,1) = [" << toe.move(2, 0, 1) << "]\n";
        cout << "Step 6 (1,0,2) = [" << toe.move(1, 0, 2) << "]\n";
        cout << "Step 7 (2,1,1) = [" << toe.move(2, 1, 1) << "]\n\n";
        return;
    }

    // 349. Intersection of Two Arrays Test
    void intersection349Test() {
        cout << "349. Intersection of Two Arrays test starts.\n";
        vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
        vector<int> result = implObj->intersection349(nums1, nums2);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 350. Intersection of Two Arrays II Test
    void intersect350Test() {
        cout << "350. Intersection of Two Arrays II test starts.\n";
        vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
        vector<int> result = implObj->intersect350(nums1, nums2);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 352. Data Stream as Disjoint Intervals Test
    void SummaryRanges352Test() {
        cout << "352. Data Stream as Disjoint Intervals test starts.\n";
        Session3Impl::SummaryRanges352 range;
        range.addNum(1);
        range.addNum(3);
        range.addNum(7);
        range.addNum(2);
        range.addNum(6);
        vector<vector<int>> result = range.getIntervals();
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << "[" << result[i][0] << ", " << result[i][1] 
                << ((i == result.size() - 1) ? "]" : "], ");
        }
        cout << "]\n\n";
        return;
    }

    // 353. Design Snake Game Test
    void SnakeGame353Test() {
        cout << "353. Design Snake Game test starts.\n";
        int width = 3, height = 2; 
        vector<vector<int>> food = {{1, 2}, {0, 1}};

        Session3Impl::SnakeGame353 snake(width, height, food);

        cout << "R => " << snake.move("R") << "; ";
        cout << "D => " << snake.move("D") << "; ";
        cout << "R => " << snake.move("R") << "\n";
        cout << "U => " << snake.move("U") << "; ";
        cout << "L => " << snake.move("L") << "; ";
        cout << "U => " << snake.move("U") << "\n\n";
        return;
    }

    // 354. Russian Doll Envelopes Test
    void maxEnvelopes354Test() {
        cout << "354. Russian Doll Envelopes test starts.\n";
        vector<vector<int>> envelopes = {
            {5, 4}, {6, 4}, {6, 7}, {2, 3}
        };

        cout << "Number of envelopes = [" << implObj->maxEnvelopes354(envelopes) << "]\n\n";
        return;
    }

    // 355. Design Twitter Test
    void Twitter355Test() {
        cout << "355. Design Twitter test starts.\n";
        Session3Impl::Twitter355 twitter;
        twitter.postTweet(1, 5);
        twitter.follow(1, 2);
        twitter.postTweet(2, 6);

        vector<int> get1_follow2 = twitter.getNewsFeed(1);
        cout << "postTweet(1, 5) -> follow(1, 2) -> postTweet(2, 6) -> Get 1 = [";
        for (int i = 0; i < get1_follow2.size(); ++i) {
            cout << get1_follow2[i] << ((i == get1_follow2.size() - 1) ? "" : ", ");
        }
        cout << "]\n";

        twitter.unfollow(1, 2);
        vector<int> get1_unfollow2 = twitter.getNewsFeed(1);
        cout << "unfollow(1, 2) -> Get 1 = [";
        for (int i = 0; i < get1_unfollow2.size(); ++i) {
            cout << get1_unfollow2[i] << ((i == get1_unfollow2.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

    // 359. Logger Rate Limiter Test
    void Logger359Test() {
        cout << "359. Logger Rate Limiter test starts.\n";
        Session3Impl::Logger359 logger;

        cout << "1, foo -> [" << logger.shouldPrintMessage(1, "foo") << "]\n";
        cout << "2, bar -> [" << logger.shouldPrintMessage(2, "bar") << "]\n";
        cout << "3, foo -> [" << logger.shouldPrintMessage(3, "foo") << "]\n";
        cout << "8, bar -> [" << logger.shouldPrintMessage(8, "bar") << "]\n";
        cout << "10, foo -> [" << logger.shouldPrintMessage(10, "foo") << "]\n";
        cout << "11, foo -> [" << logger.shouldPrintMessage(11, "foo") << "]\n\n";
    }

    // 362. Design Hit Counter Test
    void HitCounter362Test() {
        cout << "362. Design Hit Counter test starts.\n";
        Session3Impl::HitCounter362 counter;
        counter.hit(1);
        counter.hit(2);
        counter.hit(3);
        cout << "Get hit @4 = [" << counter.getHits(4) << "]\n";
        counter.hit(300);
        cout << "Get hit @300 = [" << counter.getHits(300) << "]\n";
        cout << "Get hit @301 = [" << counter.getHits(301) << "]\n\n";
        return; 
    }

    // 363. Max Sum of Rectangle No Larger Than K Test
    void maxSumSubmatrix363Test() {
        cout << "363. Max Sum of Rectangle No Larger Than K test starts.\n";
        vector<vector<int>> matrix = {
            {1, 0, 1}, 
            {0, -2, 3}
        };
        cout << "Max Sum = [" << implObj->maxSumSubmatrix363(matrix, 2) << "]\n\n";
        return;
    }

    // 366. Find Leaves of Binary Tree Test
    void findLeaves366Test() {
        cout << "366. Find Leaves of Binary Tree test starts.\n";
        TreeNode *root = new TreeNode(1);
        TreeNode *cur = root;
        cur->left = new TreeNode(2);
        cur->right = new TreeNode(3);

        cur = cur->left;
        cur->left = new TreeNode(4);
        cur->right = new TreeNode(5);

        vector<vector<int>> result = implObj->findLeaves366(root);
        cout << "Vector result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "[";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
        return;
    }

    // 371. Sum of Two Integers Test
    void getSum371Test() {
        cout << "371. Sum of Two Integers test starts.\n";
        cout << "1 + 2 = [" << implObj->getSum371(1, 2) << "]\n\n";
        return;
    }

    // 378. Kth Smallest Element in a Sorted Matrix Test
    void kthSmallest378Test() {
        cout << "378. Kth Smallest Element in a Sorted Matrix test starts.\n";
        vector<vector<int>> matrix = {
            {1, 5, 9},
            {10, 11, 13},
            {12, 13, 15}
        };

        cout << "8th smallest = [" << implObj->kthSmallest378(matrix, 8) << "]\n\n";
        return;
    }

    // 379. Design Phone Directory Test
    void PhoneDirectory379Test() {
        cout << "379. Design Phone Directory test starts.\n";
        Session3Impl::PhoneDirectory379 directory(3);
        cout << "Get = " << directory.get() << "; ";
        cout << "Get = " << directory.get() << "; ";
        cout << "Check(2) = " << directory.check(2) << "\n";
        cout << "Get = " << directory.get() << "; ";
        cout << "Check(2) = " << directory.check(2) << "; ";
        directory.release(2);
        cout << "Release (2) and Check(2) = " << directory.check(2) << "\n\n";
        return;
    }

    // 380. Insert Delete GetRandom O(1) Test
    void RandomizedSet380Test() {
        cout << "380. Insert Delete GetRandom O(1) test starts.\n";
        Session3Impl::RandomizedSet380 randomSet;
        cout << "Insert 1 = [" << randomSet.insert(1) << "]\n";
        cout << "Remove 2 = [" << randomSet.remove(2) << "]\n";
        cout << "Insert 2 = [" << randomSet.insert(2) << "]\n";
        cout << "getRandom = [" << randomSet.getRandom() << "]\n";
        cout << "Remove 1 = [" << randomSet.remove(1) << "]\n";
        cout << "Insert 2 = [" << randomSet.insert(2) << "]\n";
        cout << "getRandom = [" << randomSet.getRandom() << "]\n\n";
        return;
    }

    // 381. Insert Delete GetRandom O(1) - Duplicates allowed Test
    void RandomizedCollection381Test() {
        cout << "381. Insert Delete GetRandom O(1) - Duplicates allowed test starts.\n";
        Session3Impl::RandomizedCollection381 randomCollection;
        cout << "Insert 1 = [" << randomCollection.insert(1) << "]\n";
        cout << "Insert 1 = [" << randomCollection.insert(1) << "]\n";
        cout << "Insert 2 = [" << randomCollection.insert(2) << "]\n";
        cout << "Get random for 10 times [";
        for (int i = 0; i < 10; ++i) {
            cout << randomCollection.getRandom();
        }
        cout << "]\n";
        cout << "Remove 1 = [" << randomCollection.remove(1) << "]\n";
        cout << "Get random for 10 times [";
        for (int i = 0; i < 10; ++i) {
            cout << randomCollection.getRandom();
        }
        cout << "]\n\n";
    }

    // 384. Shuffle an Array Test
    void Solution384Test() {
        cout << "384. Shuffle an Array test starts.\n";
        vector<int> nums = {1, 2, 3};
        Session3Impl::Solution384 sol(nums);
        vector<int> shuffle = sol.shuffle();
        cout << "Shuffle = [";
        for (int i = 0; i < shuffle.size(); ++i) {
            cout << shuffle[i] << ((i == shuffle.size() - 1) ? "" : ", ");
        }
        cout << "]\n";

        vector<int> reset = sol.reset();
        cout << "Reset = [";
        for (int i = 0; i < reset.size(); ++i) {
            cout << reset[i] << ((i == reset.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

    // 386. Lexicographical Numbers Test
    void lexicalOrder386Test() {
        cout << "386. Lexicographical Numbers test starts.\n";
        vector<int> result = implObj->lexicalOrder386(13);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

    // 387. First Unique Character in a String Test
    void firstUniqChar387Test() {
        cout << "387. First Unique Character in a String test starts.\n";
        cout << "First unique index of leetcode is [" << implObj->firstUniqChar387("leetcode") 
            << "]\n\n";
        return;
    }

    // 388. Longest Absolute File Path Test
    void lengthLongestPath388Test() {
        cout << "388. Longest Absolute File Path test starts.\n";
        string s = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
        cout << "Max len = [" << implObj->lengthLongestPath388(s) << "]\n\n";
        return;
    }

    // 393. UTF-8 Validation Test
    void validUtf8_393Test() {
        cout << "393. UTF-8 Validation test starts.\n";
        vector<int> data = {248, 130, 1};
        cout << "Is valid = [" << implObj->validUtf8_393(data) << "]\n\n";
        return;
    }

    // 394. Decode String Test
    void decodeString394Test() {
        cout << "394. Decode String test starts.\n";
        cout << "Decode 3[a2[c]] = [" << implObj->decodeString394("3[a2[c]]") << "]\n\n";
        return;
    }

    // 395. Longest Substring with At Least K Repeating Characters Test
    void longestSubstring395Test()
    {
        cout << "395. Longest Substring with At Least K Repeating Characters test starts.\n";
        cout << "s = \"ababbc\", k = 2 will return [" << implObj->longestSubstring395("ababbc", 2)
            << "].\n\n";
        return;
    }

    // 399. Evaluate Division Test
    void calcEquation399Test()
    {
        cout << "399. Evaluate Division test starts.\n";
        vector<vector<string>> equations = {
            {"a", "e"}, {"b", "e"}// {"a", "b"}, {"b", "c"}
        };
        vector<double> values = {4.0, 3.0};//{2.0, 3.0};
        vector<vector<string>> queries = {
            {"a", "b"}, {"e", "e"}, {"x", "x"}//{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}
        };
        vector<double> results = implObj->calcEquation399(equations, values, queries);
        cout << "Result = [";
        for (int i = 0; i < results.size(); ++i) {
            cout << results[i] << ((i == results.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

private:
    Session3Impl * implObj;
};

#endif