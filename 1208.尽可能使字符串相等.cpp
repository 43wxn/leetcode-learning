/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> cost(s.size(), 0);

        for (int i = 0; i < s.size();++i) {
            cost[i] = abs(int(s[i]) - int(t[i]));
        }

        int window_len = 0,max_window=0;
        int right = 0;
        while (right<s.size()) {
            if (cost[right]<=maxCost) {
                maxCost -= cost[right];
                window_len++;
                right++;
            }
            else {
                if (window_len>0) {
                    maxCost += cost[right - window_len];
                    window_len--;
                }
                else {
                    right++;
                }
            }
            max_window = max(max_window, window_len);
        }
        return max_window;
    }
};
// @lc code=end

