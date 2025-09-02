/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start dp[i] means the nums[0:i] is the longest increasing
// subsequence
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int len = nums.size(), maxlen = 1;
    vector<int> dp(len, 1);
    dp[0] = 1;
    for (int i = 1; i < len; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        } else {
          dp[i] = max(dp[i], 1);
        }
      }
      maxlen = max(maxlen, dp[i]);
    }
    return maxlen;
  }
};
// @lc code=end
