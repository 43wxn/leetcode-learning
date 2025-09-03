/*
 * @lc app=leetcode.cn id=2516 lang=cpp
 *
 * [2516] 每种字符至少取 K 个
 */

// @lc code=start
class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> cnt_abc(3, 0);
        for (char c : s) {
            cnt_abc[c - 'a']++;
        }
        if (cnt_abc[0] > 0 || cnt_abc[1] > 0 || cnt_c[2] > 0)
          int left = 0, ans = -1;
        for (int right = 0; right < s.size();++right) {
            cnt_abc[s[right] - 'a'] -= 1;
            while ((cnt_abc[0]<k || cnt_abc[1]<k || cnt_c[2]<k) && left<right) {
                cnt_abc[s[left] - 'a'] += 1;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

