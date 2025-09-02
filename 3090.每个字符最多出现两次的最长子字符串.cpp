/*
 * @lc app=leetcode.cn id=3090 lang=cpp
 *
 * [3090] 每个字符最多出现两次的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int maximumLengthSubstring(string s) {
      unordered_map<char, int> first, second;
      int ans = 0, left = 0;
      for (int right = 0; right < s.size(); ++right) {
            if (first.find(s[right]) == first.end()) {
                first[s[right]] = right;
            }
            else if (second.find(s[right])==second.end()) {
                second[s[right]] = right;
            }
            else {
                left = max(left, first[s[right]] + 1);
                first[s[right]] = second[s[right]];
                second[s[right]] = right;
            }
            ans = max(ans, right - left + 1);
            //cout << s.substr(left, right - left + 1) << endl;
      }
      return ans;
    }
};
// @lc code=end

