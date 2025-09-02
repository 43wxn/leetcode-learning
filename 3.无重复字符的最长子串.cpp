/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, window = 0;
        unordered_map<char,int> letter;
        for (int right = 0; right < s.size();++right) {
            int left = right - window;
            //cout << "left" << left << endl;
            if (letter.find(s[right]) == letter.end() || letter[s[right]] < left)
            {
                letter[s[right]] = right;
                window++;
            }
            else {
                window = right - letter[s[right]];
                letter[s[right]] = right;
            }
            //cout << "window" << window << endl;
            ans = max(ans, window);
            //cout << "ans" << ans << endl;
        }
        return ans;
    }
};
// @lc code=end

