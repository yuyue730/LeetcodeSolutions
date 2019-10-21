#ifndef _SESSION_0_TEST_H
#define _SESSION_0_TEST_H

#include <iomanip>

#include "session0_impl.h"
using namespace std;

class Session0Test {
public:
    Session0Test() {
        cout << "Test object for Leetcode Session 0 problems constructed.\n";
        implObj = new Session0Impl();
    }

    // 1. Two Sum Test
    void twoSum1Test() {
        cout << "1. Two Sum test starts.\n";
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;

        vector<int> result = implObj->twoSum1(nums, target);
        cout << "{2, 7, 11, 15} and 9 will return " << result[0] << " and " << result[1] << "\n\n";
        return;
    }

    // 2. Add Two Numbers Test
    void addTwoNumbers2Test() {
        cout << "2. Add Two Numbers test starts\n";

        ListNode * tmp = NULL;
        ListNode * l1 = new ListNode(2);
        tmp = l1; tmp->next = new ListNode(4); 
        tmp = tmp->next; tmp->next = new ListNode(3);
        ListNode * l2 = new ListNode(5);
        tmp = l2; tmp->next = new ListNode(6);
        tmp = tmp->next; tmp->next = new ListNode(7);

        ListNode * result = implObj->addTwoNumbers2(l1, l2);
        cout << "Result list: ";
        while (result) {
            cout << result->val << "->";
            result = result->next;
        }
        cout << "\n\n";

        return;
    }

    // 3. Longest Substring Without Repeating Characters Test
    void lengthOfLongestSubstring3Test() {
        cout << "3. Longest Substring Without Repeating Characters test starts.\n";

        string str = "abcabcbb";
        cout << "Test string has longest non-repeating chars at " << implObj->lengthOfLongestSubstring3(str) << ".\n\n";

        return;
    }

    // 4. Median of Two Sorted Arrays Test
    void findMedianSortedArrays4Test() {
        cout << "4. Median of Two Sorted Arrays starts\n";

        vector<int> num1 = {1, 3, 5, 7, 9};
        vector<int> num2 = {2, 4, 6, 8, 10};

        cout << "Median of two array is " << implObj->findMedianSortedArrays4(num1, num2) << "\n\n";

        return;
    }

    // 5. Longest Palindromic Substring Test
    void longestPalindrome5Test() {
        cout << "5. Longest Palindromic Substring test starts.\n";

        string str = "babad";
        cout << "Longest Palindromic substring is " << implObj->longestPalindrome5(str) << ".\n\n";

        return;
    }

    // 6. ZigZag Conversion Test
    void convert6Test() {
        cout << "6. ZigZag Conversion test starts.\n";

        string str = "PAYPALISHIRING";
        cout << "ZigZag conversion = " << implObj->convert6(str, 4) << ".\n\n";

        return;
    }

    // 7. Reverse Integer Test
    void reverse7Test() {
        cout << "7. Reverse Integer test starts\n";
        cout << "Number 123 is reversed to be " << implObj->reverse7(123) << ".\n\n";
        return;
    }

    // 8. String to Integer (atoi) Test
    void myAtoi8Test() {
        cout << "8. String to Integer (atoi) test starts\n";
        cout << "String '     -43' can be atoi-ed to " << implObj->myAtoi8("     -43") << ".\n\n";
        return;
    }

    // 9. Palindrome Number Test
    void isPalindrome9Test() {
        cout << "9. Palindrome Number test starts\n";
        cout << "Number 121 isPalindrome = " << implObj->isPalindrome9(121) << ".\n\n";
        return;
    }

    // 10. Regular Expression Matching Test
    void isMatch10Test() {
        cout << "10. Regular Expression Matching test starts.\n";
        cout << "isMatch between 'aab' and 'c*a*b' is " << implObj->isMatch10("aab", "c*a*b") << ".\n\n";
        return;
    }

    // 11. Container With Most Water Test
    void maxArea11Test() {
        cout << "11. Container With Most Water test starts\n";

        vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int result = implObj->maxArea11(heights);
        cout << "Current max Area = " << result << "\n\n";

        return;
    }

    // 12. Integer to Roman Test
    void intToRoman12Test() {
        cout << "12. Integer to Roman test starts\n";
        cout << "Number 49 can be " << implObj->intToRoman12(49) << ".\n\n";
        return;
    }

    // 13. Roman to Integer Test
    void romanToInt13Test() {
        cout << "13. Roman to Integer test starts\n";
        cout << "Number XLIX is " << implObj->romanToInt13("XLIX") << ".\n\n";
        return;  
    }

    // 14. Longest Common Prefix Test
    void longestCommonPrefix14Test() {
        cout << "14. Longest Common Prefix test starts.\n";
        vector<string> strArr = {"flower", "flow", "flight"};
        cout << "Longest Common Prefix is " << implObj->longestCommonPrefix14(strArr) << ".\n\n";
        return;
    }

    // 15. 3Sum Test
    void threeSum15Test() {
        cout << "15. 3Sum test starts\n";
        vector<int> nums = {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};
        vector<vector<int>> result = implObj->threeSum15(nums);

        cout << "Each sub arrays are\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "Subarray " << i << ": [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ";";
            }
            cout << "]\n";
        }
        cout << "\n";
        return;
    }

    // 16. 3Sum Closest Test
    void threeSumClosest16Test() {
        cout << "16. 3Sum Closest test starts\n";
        vector<int> nums = {-1, 2, 1, -4};
        int target = 1;

        cout << "The closest difference is " << implObj->threeSumClosest16(nums, target) << ".\n\n";

        return;
    }

    // 17. Letter Combinations of a Phone Number Test
    void letterCombinations17Test() {
        cout << "17. Letter Combinations of a Phone Number test starts.\n";
        vector<string> result = implObj->letterCombinations17("23");
        for (int i = 0; i < result.size(); ++i) {
            cout << "index " << i << "--" << result[i] << "; ";
        }

        cout << "\n\n";
        return;
    }

    // 18. 4Sum Test
    void fourSum18Test() {
        cout << "18. 4Sum test starts.";
        vector<int> nums = {1, 0, -1, 0, -2, 2};
        int target = 0;

        vector<vector<int>> result = implObj->fourSum18(nums, target);
        cout << "Result array of array is \n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "subarray " << i << " [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << "; ";
            }
            cout << "]\n";
        }
        cout << "\n";
        return;
    }

    // 19. Remove Nth Node From End of List Test
    void removeNthFromEnd19Test() {
        cout << "19. Remove Nth Node From End of List test starts.\n";
        ListNode * head = new ListNode(1);
        ListNode * cur = head;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5); cur = cur->next;

        ListNode * new_head = implObj->removeNthFromEnd19(head, 2);
        cur = new_head;

        cout << "Output linked list is [";
        while (cur) {
            cout << cur->val << "; ";
            cur = cur->next;
        }
        cout << "]\n\n";
        return;
    }

    // 20. Valid Parentheses Test
    void isValid20Test() {
        cout << "20. Valid Parentheses test starts.\n";   
        string s = "([)]";
        cout << "([)] isValid = " << implObj->isValid20(s) << ".\n\n";
        return;
    }

    // 21. Merge Two Sorted Lists Test
    void mergeTwoLists21Test() {
        cout << "21. Merge Two Sorted Lists test starts.\n";
        ListNode * head1 = new ListNode(1);
        ListNode * cur = head1; 
        cur->next = new ListNode(2);
        cur->next->next = new ListNode(4);

        ListNode * head2 = new ListNode(1);
        cur = head2;
        cur->next = new ListNode(3);
        cur->next->next = new ListNode(4);

        ListNode * head = implObj->mergeTwoLists21(head1, head2);
        cout << "Output linked list is [";
        while (head) {
            cout << head->val << "; ";
            head = head->next;
        }
        cout << "]\n\n";
        return;
    }

    // 22. Generate Parentheses Test
    void generateParenthesis22Test() {
        cout << "22. Generate Parentheses test starts.\n";
        vector<string> result = implObj->generateParenthesis22(3);
        for (int i = 0; i < result.size(); ++i) {
            cout << "index " << i << "--" << result[i] << "; ";
        }

        cout << "\n\n";
        return;
    }

    // 23. Merge k Sorted Lists Test
    void mergeKLists23Test() {
        cout << "23. Merge k Sorted Lists test starts.\n";

        ListNode * head1 = new ListNode(1);
        ListNode * cur = head1; 
        cur->next = new ListNode(4);
        cur->next->next = new ListNode(5);

        ListNode * head2 = new ListNode(1);
        cur = head2; 
        cur->next = new ListNode(3);
        cur->next->next = new ListNode(4);

        ListNode * head3 = new ListNode(2);
        cur = head3; 
        cur->next = new ListNode(6);

        vector<ListNode *> lists = {head1, head2, head3};
        ListNode * head = implObj->mergeKLists23(lists);

        cout << "Output linked list is [";
        while (head) {
            cout << head->val << "; ";
            head = head->next;
        }
        cout << "]\n\n";
    }

    // 24. Swap Nodes in Pairs Test
    void swapPairs24Test() {
        cout << "24. Swap Nodes in Pairs test starts.\n";

        ListNode * head = new ListNode(1);
        ListNode * cur = head; 
        cur->next = new ListNode(2);  cur = cur->next;
        cur->next = new ListNode(3);  cur = cur->next;
        cur->next = new ListNode(4);

        ListNode* newHead = implObj->swapPairs24(head);

        cout << "Output linked list is [";
        while (newHead) {
            cout << newHead->val << "; ";
            newHead = newHead->next;
        }
        cout << "]\n\n";
    }

    // 25. Reverse Nodes in k-Group Test
    void reverseKGroup25Test() {
        cout << "25. Reverse Nodes in k-Group test starts.\n";

        ListNode * head = new ListNode(1);
        ListNode * cur = head; 
        cur->next = new ListNode(2);  cur = cur->next;
        cur->next = new ListNode(3);  cur = cur->next;
        cur->next = new ListNode(4);  cur = cur->next;
        cur->next = new ListNode(5);

        ListNode* result = implObj->reverseKGroup25(head, 3);
        cout << "Output linked list is [";
        while (result) {
            cout << result->val << "; ";
            result = result->next;
        }

        cout << "]\n\n";
    }

    // 26. Remove Duplicates from Sorted Array Test
    void removeDuplicates26Test() {
        cout << "26. Remove Duplicates from Sorted Array test starts\n";

        vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        cout << "Unique # of items is " << implObj->removeDuplicates26(nums) << "\n\n";
        return;
    }

    // 27. Remove Element Test
    void removeElement27Test() {
        cout << "27. Remove Element test starts.\n";
        vector<int> nums = {3, 2, 2, 3};
        cout << "length = [" << implObj->removeElement27(nums, 3) << "]\n\n";
        return;
    }

    // 28. Implement strStr() Test
    void strStr28Test() {
        cout << "28. Implement strStr() test starts.\n";
        cout << "hello and ll will return " << implObj->strStr28("hello", "ll") << ".\n\n";
        return;
    }

    // 29. Divide Two Integers Test
    void divide29Test() {
        cout << "29. Divide Two Integers test starts\n";
        cout << "16 / 3 = " << implObj->divide29(16, 3) << ".\n\n";
        return;
    }

    // 30. Substring with Concatenation of All Words Test
    void findSubstring30Test() {
        cout << "30. Substring with Concatenation of All Words test starts.\n";
        string s = "barfoothefoobarman";
        vector<string> words = {"foo", "bar"};

        vector<int> result = implObj->findSubstring30(s, words);
        cout << "barfoothefoobarman and {foo, bar} will generate [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ";";
        }
        cout << "].\n\n";
    }

    // 31. Next Permutation Test
    void nextPermutation31Test() {
        cout << "31. Next Permutation test starts\n";

        vector<int> nums = {1, 2, 7, 4, 3, 1};
        implObj->nextPermutation31(nums);
        cout << "Next Permutation is [";
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << "; ";
        }
        cout << "].\n\n";
        return;
    }

    // 32. Longest Valid Parentheses Test
    void longestValidParentheses32Test() {
        cout << "32. Longest Valid Parentheses test starts.\n";
        cout << "((())() will have max length = [" << implObj->longestValidParentheses32("((())()") << "]\n\n";
        return;
    }

    // 33. Search in Rotated Sorted Array Test
    void search33Test() {
        cout << "33. Search in Rotated Sorted Array test starts.\n";
        vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
        cout << "Find 0 will have idx = [" << implObj->search33(nums, 0) << "]\n\n";
        return;
    }

    // 34. Find First and Last Position of Element in Sorted Array Test
    void searchRange34Test() {
        cout << "34. Find First and Last Position of Element in Sorted Array test starts.\n";
        vector<int> nums = {5, 7, 7, 8, 8, 10};
        vector<int> result = implObj->searchRange34(nums, 8);
        cout << "Find 8 will have idxes " << result[0] << "; " << result[1] << ".\n\n";
        return; 
    }

    // 35. Search Insert Position Test
    void searchInsert35Test() {
        cout << "35. Search Insert Position test starts.\n";
        vector<int> nums = {1, 3, 5, 6};
        cout << "Insert 2 into index = " << implObj->searchInsert35(nums, 2) << ".\n\n";
        return;
    }

    // 36. Valid Sudoku Test
    void isValidSudoku36Test() {
        cout << "36. Valid Sudoku test starts.\n";
        vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };

        cout << "Current board is [" << implObj->isValidSudoku36(board) << "].\n\n";
        return;
    }

    // 37. Sudoku Solver Test
    void solveSudoku37Test() {
        cout << "37. Sudoku Solver test starts.\n";
        vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };

        implObj->solveSudoku37(board);
        cout << "Current board solution is \n";
        for (int i = 0; i < 9; ++i) {
            cout << "[";
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << "; ";
            }
            cout << "]\n";
        }
        cout << "\n";
        return;
    }

    // 38. Count and Say Test
    void countAndSay38Test() {
        cout << "38. Count and Say test starts.\n";
        cout << "6 will generate " << implObj->countAndSay38(6) << ".\n\n";
        return;
    }

    // 39. Combination Sum Test
    void combinationSum39Test() {
        cout << "39. Combination Sum test starts.\n";
        vector<int> candidate = {2,3,5};
        vector<vector<int>> result = implObj->combinationSum39(candidate, 8);
        cout << "candidate = {2, 3, 5}, target 8 will have \n";

        for (int i = 0; i < result.size(); ++i) {
            cout << "row " << i << "[";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ";";
            }
            cout << "]\n";
        }
        cout << "\n";
        return;
    }

    // 40. Combination Sum II Test
    void combinationSum2_40Test() {
        cout << "40. Combination Sum II test starts.\n";
        vector<int> candidates = {10,1,2,7,6,1,5};
        int target = 8;
        vector<vector<int>> result = implObj->combinationSum2_40(candidates, target);
        cout << "{10,1,2,7,6,1,5} and 8 will generate [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "[";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ",");
            }
            cout << "]" << ((i == result.size() - 1) ? "\n" : ",\n");
        }
        cout << "].\n\n";
    }

    // 41. First Missing Positive Test
    void firstMissingPositive41Test() {
        cout << "41. First Missing Positive test starts.\n";
        vector<int> nums = {3, 4, -1, 1};

        cout << "First missing postive is " << implObj->firstMissingPositive41(nums) << ".\n\n";
        return;
    }

    // 42. Trapping Rain Water Test
    void trap42Test() {
        cout << "42. Trapping Rain Water test starts.\n";
        vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        cout << "[0,1,0,2,1,0,1,3,2,1,2,1] will contain " << implObj->trap42(height) << " units of water.\n\n";
        return;
    }

    // 43. Multiply Strings Test
    void multiply43Test() {
        cout << "43. Multiply Strings test starts\n";
        cout << "123 * 456 = [" << implObj->multiply43("123", "456") << "].\n\n";
        return;
    }

    // 44. Wildcard Matching Test
    void isMatch44Test() {
        cout << "44. Wildcard Matching test starts.\n";
        cout << "*a*b and adceb isMatch = [" << implObj->isMatch44("adceb", "*a*b") << "].\n\n";
        return;
    }

    // 45. Jump Game II Test
    void jump45Test() {
        cout << "45. Jump Game II test starts.\n";
        vector<int> nums = {2, 3, 1, 1, 4};

        cout << "Min step to jump is [" << implObj->jump45(nums) << "].\n\n";
        return;
    }

    // 46. Permutations Test
    void permute46Test() {
        cout << "46. Permutations test starts.\n";
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> results = implObj->permute46(nums);
        
        cout << "Result is \n";
        for (int i = 0; i < results.size(); ++i) {
            cout << "Item " << i << " -- [";
            for (int j = 0; j < results[i].size(); ++j) {
                cout << results[i][j] << "; ";
            }
            cout << "]\n";
        }
        cout << "\n";
        return;
    }

    // 47. Permutations II Test
    void permuteUnique47Test() {
        cout << "47. Permutations II test starts.\n";
        vector<int> nums = {1,1,2};
        vector<vector<int>> results = implObj->permuteUnique47(nums);
        cout << "Result is [\n";
        for (int i = 0; i < results.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < results[i].size(); ++j) {
                cout << results[i][j] << ((j == results[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n";
        return;
    }

    // 48. Rotate Image Test
    void rotate48Test() {
        cout << "48. Rotate Image test.\n";
        vector<vector<int>> matrix = {
            {5, 1, 9, 11},
            {2, 4, 8, 10},
            {13, 3, 6, 7},
            {15, 14, 12, 16}
        };

        implObj->rotate48(matrix);
        cout << "After rotation, matrix is \n";
        for (int i = 0; i < matrix.size(); ++i) {
            cout << "Row " << i << "[";
            for (int j = 0; j < matrix[i].size(); ++j) {
                cout << matrix[i][j] << "; ";
            }
            cout << "]\n";
        }
        cout << "\n";
        return;
    }

    // 49. Group Anagrams Test
    void groupAnagrams49Test() {
        cout << "49. Group Anagrams test starts.\n";
        vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        vector<vector<string>> result = implObj->groupAnagrams49(strs);
        cout << "Result is \n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "Patch " << i << ": [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j < result[i].size() - 1) ? "; " : "");
            }
            cout << "]\n";
        }
        cout << "\n";
        return;
    }

    // 50. Pow(x, n) Test
    void myPow50Test() {
        cout << "50. Pow(x, n) test starts.\n";
        cout << "2.1^3 = [" << setprecision(5) << implObj->myPow50(2.1, 3) << "]\n\n";
        return;
    }

    // 51. N-Queens Test
    void solveNQueens51Test() {
        cout << "51. N-Queens test starts.\n";

        vector<vector<string>> results = implObj->solveNQueens51(4);
        cout << "N = " << 4 << "; Results are ";
        for (int i = 0; i < results.size(); ++i) {
            cout << "Answer " << i << " [\n";
            for (int j = 0; j < results[i].size(); ++j) {
                cout << "  [" << results[i][j] << "]\n";
            }
            cout << "]\n";
        }
        cout << "\n";
        return;
    }

    // 53. Maximum Subarray Test
    void maxSubArray53Test() {
        cout << "53. Maximum Subarray test starts (Divide and Conquer method)\n";

        vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int result = implObj->maxSubArray53(nums);
        cout << "Current max SubArray = " << result << "\n\n";

        return;
    }

    // 54. Spiral Matrix Test
    void spiralOrder54Test() {
        cout << "54. Spiral Matrix test starts.\n";
        vector<vector<int>> matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        };
        vector<int> result = implObj->spiralOrder54(matrix);

        cout << "Spiral order vector [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : "; ");
        }
        cout << "]\n\n";
        return;
    }

    // 55. Jump Game Test
    void canJump55Test() {
        cout << "55. Jump Game test starts.\n";
        vector<int> case1 = {2, 3, 1, 1, 4};
        cout << "Case 1 [2,3,1,1,4] canJump = " 
            << (implObj->canJump55(case1) ? "true" : "false") << ".\n";
        vector<int> case2 = {3, 2, 1, 0, 4};
        cout << "Case 2 [3,2,1,0,4] canJump = " 
            << (implObj->canJump55(case2) ? "true" : "false") << ".\n\n";
        return;
    }

    // 56. Merge Intervals Test
    void merge56Test() {
        cout << "56. Merge Intervals test starts.\n";
        vector<vector<int>> intervals = {
            {1, 3}, {2, 6}, {8, 10}, {15, 18}
        };

        vector<vector<int>> result = implObj->merge56(intervals);
        cout << "Merge result is ";
        for (int i = 0; i < result.size(); ++i) {
            cout << "[" << result[i][0] << ", " << result[i][1] << "]"
                << ((i == result.size() - 1) ? "" : "; ");
        }
        cout << "\n\n";
        return;
    }

    // 57. Insert Interval Test
    void insert57Test() {
        cout << "57. Insert Interval test starts.\n";
        vector<vector<int>> intervals = {
            {1, 3}, {6, 9}
        };
        vector<int> newInterval = {2, 5};

        vector<vector<int>> result = implObj->insert57(intervals, newInterval);
        cout << "Insert result is ";
        for (int i = 0; i < result.size(); ++i) {
            cout << "[" << result[i][0] << ", " << result[i][1] << "]"
                << ((i == result.size() - 1) ? "" : "; ");
        }
        cout << "\n\n";
        return;
    }

    // 59. Spiral Matrix II Test
    void generateMatrix59Test() {
        cout << "59. Spiral Matrix II test.\n";
        vector<vector<int>> result = implObj->generateMatrix59(3);

        cout << "Generate result [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[0].size(); ++j) {
                cout << result[i][j] << (j == result.size() - 1 ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
        return;
    }

    // 60. Permutation Sequence Test
    void getPermutation60Test() {
        cout << "60. Permutation Sequence test starts.\n";
        cout << "n = 4; k = 17 -> [" << implObj->getPermutation60(4, 17) << "]\n\n";
        return;
    }

    // 61. Rotate List Test
    void rotateRight61Test() {
        cout << "61. Rotate List test starts.\n";
        ListNode * head = new ListNode(1);
        ListNode * cur = head; 
        cur->next = new ListNode(2);  cur = cur->next;
        cur->next = new ListNode(3);  cur = cur->next;
        cur->next = new ListNode(4);  cur = cur->next;
        cur->next = new ListNode(5);

        ListNode* result = implObj->rotateRight61(head, 2);
        cout << "Output linked list is [";
        while (result) {
            cout << result->val << "; ";
            result = result->next;
        }

        cout << "]\n\n";
    }

    // 62. Unique Paths Test
    void uniquePaths62Test() {
        cout << "62. Unique Paths test starts.\n";
        cout << "3 * 2 grid will have " << implObj->uniquePaths62(3, 2) << " methods.\n\n";
        return;
    }

    // 63. Unique Paths II Test
    void uniquePathsWithObstacles63Test() {
        cout << "63. Unique Paths II test starts.\n";
        vector<vector<int>> obstacles = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
        };
        cout << "Number of unique paths = " << implObj->uniquePathsWithObstacles63(obstacles) << "\n\n";
        return;
    }

    // 64. Minimum Path Sum Test
    void minPathSum64Test() {
        cout << "64. Minimum Path Sum test starts.\n";
        vector<vector<int>> grid = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
        };
        cout << "Grid will have min path = " << implObj->minPathSum64(grid) << ".\n\n";
        return;
    }

    // 65. Valid Number Test
    void isNumber65Test() {
        cout << "65. Valid Number test starts.\n";

        cout << "'0' is valid = " << (implObj->isNumber65("0") ? "True" : "False") << ".\n";
        cout << "' 0.1' is valid = " << (implObj->isNumber65(" 0.1") ? "True" : "False") << ".\n";
        cout << "'abc' is valid = " << (implObj->isNumber65("abc") ? "True" : "False") << ".\n";
        cout << "'1 a' is valid = " << (implObj->isNumber65("1 a") ? "True" : "False") << ".\n";
        cout << "'2e10' is valid = " << (implObj->isNumber65("2e10") ? "True" : "False") << ".\n";
        cout << "'-90e3' is valid = " << (implObj->isNumber65("-90e3") ? "True" : "False") << ".\n";
        cout << "'1e' is valid = " << (implObj->isNumber65("1e") ? "True" : "False") << ".\n";
        cout << "' 6e-1' is valid = " << (implObj->isNumber65(" 6e-1") ? "True" : "False") << ".\n";
        cout << "' 99e2.5' is valid = " << (implObj->isNumber65(" 99e2.5") ? "True" : "False") << ".\n";
        cout << "'53.5e93' is valid = " << (implObj->isNumber65("53.5e93") ? "True" : "False") << ".\n";
        cout << "' --6' is valid = " << (implObj->isNumber65(" --6") ? "True" : "False") << ".\n";
        cout << "'-+3' is valid = " << (implObj->isNumber65("-+3") ? "True" : "False") << ".\n";
        cout << "'95a54e53' is valid = " << (implObj->isNumber65("95a54e53") ? "True" : "False") << ".\n\n";

        return;
    }

    // 66. Plus One Test
    void plusOne66Test() {
        cout << "66. Plus One test starts.\n";

        vector<int> nums = {9, 9, 9, 9};
        vector<int> result = implObj->plusOne66(nums);

        cout << "Result digits are: ";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << "; ";
        }
        cout << "\n\n";

        return;
    }

    // 67. Add Binary Test
    void addBinary67Test() {
        cout << "67. Add Binary test starts.\n";
        cout << "a = '1010', b = '1011' will add up to " << implObj->addBinary67("1010", "1011") << "\n\n";
        return;
    }

    // 68. Text Justification Test
    void fullJustify68Test() {
        cout << "68. Text Justification test starts.\n";
        vector<string> words = {
            "This", "is", "an", "example", "of", "text", "justification."
        };
        vector<string> results = implObj->fullJustify68(words, 16);
        cout << "Result is [\n";
        for (int i = 0; i < results.size(); ++i) {
            cout << results[i] << ",\n";
        }
        cout << "]\n\n";
        return;
    }

    // 69. Sqrt(x) Test
    void mySqrt69Test() {
        cout << "69. Sqrt(x) test starts.\n";
        cout << "sqrt(8) = " << implObj->mySqrt69(10) << "\n\n";
        return;
    }

    // 70. Climbing Stairs Test
    void climbStairs70Test() {
        cout << "70. Climbing Stairs test starts.\n";
        cout << "3 starts will have " << implObj->climbStairs70(3) << " ways.\n\n";
        return;
    }

    // 71. Simplify Path Test
    void simplifyPath71Test() {
        cout << "71. Simplify Path test starts.\n";
        cout << "'/a//b////c/d//././/..' will generate " << implObj->simplifyPath71("/a//b////c/d//././/..") << "\n\n";
        return;
    }

    // 72. Edit Distance Test
    void minDistance72Test() {
        cout << "72. Edit Distance test starts.\n";
        cout << "'horse' and 'ros' will have " << implObj->minDistance72("horse", "ros") << " steps.\n\n";
        return;
    }

    // 73. Set Matrix Zeroes Test
    void setZeroes73Test() {
        cout << "73. Set Matrix Zeroes test starts.\n";
        vector<vector<int>> matrix = {
            {0, 1, 2, 0},
            {3, 4, 0, 2},
            {1, 3, 1, 5}
        };

        implObj->setZeroes73(matrix);
        cout << "Result = [\n";
        for (int i = 0; i < matrix.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < matrix[i].size(); ++j) {
                cout << matrix[i][j] << ((j == matrix[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
        return;
    }

    // 74. Search a 2D Matrix Test
    void searchMatrix74Test() {
        cout << "74. Search a 2D Matrix test starts.\n";

        vector<vector<int>> matrix = {
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
        };

        cout << "Find 3 result in [" << (implObj->searchMatrix74(matrix, 3) ? "True" : "False") 
            << "].\n\n";
        return;
    }

    // 75. Sort Colors Test
    void sortColors75Test() {
        cout << "75. Sort Colors test starts.\n";
        vector<int> nums = {2, 0, 2, 1, 1, 0};
        implObj->sortColors75(nums);
        
        cout << "Sorted array is [";
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << ((i == nums.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 76. Minimum Window Substring Test
    void minWindow76Test() {
        cout << "76. Minimum Window Substring test starts.\n";
        string S = "ADOBECODEBANC", T = "ABC";
        string result = implObj->minWindow76(S, T);
        cout << "Minimum Window Substring is " << result << ".\n\n";
        return;
    }

    // 77. Combinations Test
    void combine77Test() {
        cout << "77. Combinations test starts.\n";
        vector<vector<int>> result = implObj->combine77(4, 2);
        cout << "All subsets [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
    }

    // 78. Subsets Test
    void subsets78Test() {
        cout << "78. Subsets test starts.\n";
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> result = implObj->subsets78(nums);
        cout << "All subsets [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
    }

    // 79. Word Search Test
    void exist79Test() {
        cout << "79. Word Search test starts.\n";
        vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        };
        cout << "Find 'ABCCED' is [" 
            << (implObj->exist79(board, "ABCCED") ? "True" : "False") <<"]\n";
        cout << "Find 'ABCB' is [" 
            << (implObj->exist79(board, "ABCB") ? "True" : "False") << "]\n\n";
        return;
    }

    // 81. Search in Rotated Sorted Array II Test
    void search81Test() {
        cout << "81. Search in Rotated Sorted Array II test starts.\n";
        vector<int> nums = {2,5,6,0,0,1,2};
        cout << "Search for 0 is [" << (implObj->search81(nums, 0) ? "True" : "False")
            << "].\n";
        cout << "Search for 8 is [" << (implObj->search81(nums, 8) ? "True" : "False")
            << "].\n\n";
        return;
    }

    // 82. Remove Duplicates from Sorted List II Test
    void deleteDuplicates82Test() {
        cout << "82. Remove Duplicates from Sorted List II test.\n";
        ListNode *head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5);

        ListNode *result = implObj->deleteDuplicates82(head);
        cout << "Result LinkedList [";
        while (result) {
            cout << result->val << ((result->next == NULL) ? "" : "->");
            result = result->next;
        }
        cout << "]\n\n";
        return;
    }

    // 83. Remove Duplicates from Sorted List Test
    void deleteDuplicates83Test() {
        cout << "83. Remove Duplicates from Sorted List test starts.\n";
        ListNode *head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(1); cur = cur->next;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(3);

        ListNode *result = implObj->deleteDuplicates83(head);
        cout << "Result LinkedList [";
        while (result) {
            cout << result->val << ((result->next == NULL) ? "" : "->");
            result = result->next;
        }
        cout << "]\n\n";
        return;
    }

    // 84. Largest Rectangle in Histogram Test
    void largestRectangleArea84Test() {
        cout << "84. Largest Rectangle in Histogram test starts.\n";
        vector<int> heights = {2, 1, 5, 6, 2, 3};
        cout << "Largest rectangle is [" << implObj->largestRectangleArea84(heights)
            << "].\n\n";
        return;
    }

    // 85. Maximal Rectangle Test
    void maximalRectangle85Test() {
        cout << "85. Maximal Rectangle test starts.\n";
        vector<vector<char>> matrix = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
        };

        cout << "Largest rectangle is [" << implObj->maximalRectangle85(matrix) 
            << "]\n\n";
        return;
    }

    // 86. Partition List Test
    void partition86Test() {
        cout << "86. Partition List test starts.\n";
        ListNode* head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(1); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(5); cur = cur->next;
        cur->next = new ListNode(2);

        ListNode *result = implObj->partition86(head, 3);
        cout << "Result LinkedList [";
        while (result) {
            cout << result->val << ((result->next == NULL) ? "" : "->");
            result = result->next;
        }
        cout << "]\n\n";
        return;
    }

    // 88. Merge Sorted Array Test
    void merge88Test() {
        cout << "88. Merge Sorted Array test starts.\n";
        vector<int> nums1 = {1,2,3,0,0,0};
        vector<int> nums2 = {2,5,6};
        implObj->merge88(nums1, 3, nums2, 3);
        cout << "Merged array is [";
        for (int i = 0; i < nums1.size(); ++i) {
            cout << nums1[i] << ((i == nums1.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 91. Decode Ways Test
    void numDecodings91Test() {
        cout << "91. Decode Ways test starts.\n";
        cout << "226 will be decoded into [" << implObj->numDecodings91("12") << "].\n\n";
        return;
    }

    // 92. Reverse Linked List II Test
    void reverseBetween92Test()  {
        cout << "92. Reverse Linked List II test starts.\n";
        ListNode* head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5);

        ListNode *result = implObj->reverseBetween92(head, 2, 4);
        cout << "Reversed LinkedList [";
        while (result) {
            cout << result->val << ((result->next == NULL) ? "" : "->");
            result = result->next;
        }
        cout << "]\n\n";
        return;
    }

    // 93. Restore IP Addresses Test
    void restoreIpAddresses93Test() {
        cout << "Restore IP Addresses test starts.\n";
        string s = "25525511135";
        vector<string> allIps = implObj->restoreIpAddresses93(s);
        cout << "All Ips [";
        for (int i = 0; i < allIps.size(); ++i) {
            cout << allIps[i] << ((i == allIps.size() - 1) ? "" : ", "); 
        }
        cout << "]\n\n";
        return;
    }

    // 94. Binary Tree Inorder Traversal Test
    void inorderTraversal94Test() {
        cout << "94. Binary Tree Inorder Traversal test starts.\n";

        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);
        cur = cur->left;
        cur->left = new TreeNode(3);
        cur->right = new TreeNode(4);
        root->right = new TreeNode(5);

        vector<int> result = implObj->inorderTraversal94(root);
        cout << "Inorder traversal result [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 95. Unique Binary Search Trees II Test
    void generateTrees95Test() {
        cout << "95. Unique Binary Search Trees II test starts.\n";
        vector<TreeNode *> result = implObj->generateTrees95(3);
        cout << "Can generate " << result.size() << " trees.\n";
        for (int i = 0; i < result.size(); ++i) {
            TreeNode * cur = result[i];
            cout << "i = " << i << "; Root value " << cur->val << "\n";
        }
        cout << "\n";
        return;
    }

    // 96. Unique Binary Search Trees Test
    void numTrees96Test() {
        cout << "96. Unique Binary Search Trees test starts.\n";
        cout << "4 will generate [" << implObj->numTrees96(4) << "]\n";
        cout << "5 will generate [" << implObj->numTrees96(5) << "]\n\n";
        return;
    }

    // 97. Interleaving String Test
    void isInterleave97Test() {
        cout << "97. Interleaving String test.\n";
        string s1 = "a", s2 = "", s3 = "a";//s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
        cout << "s1 and s2 can generage 3 [" << (implObj->isInterleave97(s1, s2, s3) ? "True" : "False")
            << "].\n\n";
        return; 
    }

    // 98. Validate Binary Search Tree Test
    void isValidBST98Test() {
        cout << "98. Validate Binary Search Tree test starts.\n";

        TreeNode * root = new TreeNode(5);
        TreeNode * cur = root;
        root->left = new TreeNode(3);
        cur = root->left;
        cur->left = new TreeNode(2); cur->right = new TreeNode(4);

        cur = root;
        cur->right = new TreeNode(6);
        cur = cur->right; cur->right = new TreeNode(8);

        cout << "Is Valid BST = [" << (implObj->isValidBST98(root) ? "True" : "False")
            << "]\n\n";
        return;
    }

    // 99. Recover Binary Search Tree Test
    void recoverTree99Test() {
        cout << "99. Recover Binary Search Tree test starts.\n";

        TreeNode * root = new TreeNode(5);
        TreeNode * cur = root;
        root->left = new TreeNode(6);
        cur = root->left;
        cur->left = new TreeNode(2); cur->right = new TreeNode(3);

        cur = root;
        cur->right = new TreeNode(4);
        cur = cur->right; cur->right = new TreeNode(8);

        implObj->recoverTree99(root);
        cout << "Please exam the root [" << root->val << "]\n";
        return;
    }

private:
    Session0Impl * implObj;
};

#endif