/*
 * @lc app=leetcode.cn id=2730 lang=cpp
 *
 * [2730] 找到最长的半重复子字符串
 */

// @lc code=start
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int index = 0, left = 0, ans = 0;
        for (int right = 0; right < s.size();++right) {
            if (s[right]==s[right-1]) {
                left = index;
                index = right;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

