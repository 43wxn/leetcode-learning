/*
 * @lc app=leetcode.cn id=2958 lang=cpp
 *
 * [2958] 最多 K 个重复元素的最长子数组
 */

// @lc code=start
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0, left = 0, right = -1;
        for (int x : nums) {
            freq[x] += 1;
            right++;
            while (freq[x] > k) {
            freq[nums[left]] -= 1;
            left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
        }
};
// @lc code=end

