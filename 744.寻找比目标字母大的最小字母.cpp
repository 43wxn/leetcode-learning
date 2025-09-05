/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = -1, right = letters.size();
        while (left+1 < right) {
            int mid = left + (right - left) / 2;
            if ((int)letters[mid] < (int)target+1) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return right == letters.size() ? letters[0] : letters[right];
    }
};
// @lc code=end

