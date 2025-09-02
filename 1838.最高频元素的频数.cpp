/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 *
 * [1838] 最高频元素的频数
 */

// @lc code=start
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(),[](int a,int b){return a<b});
        int left = 0, ans = 0, total = 0;
        for (int right = 0; right < nums.size();++right) {
            total += nums[left] - nums[right];
            while (total > k) {
                total -= (nums[left] - nums[left + 1]) * (right - left);
                left++;
            }
            ans = max(ans, right - left - 1);
        }
        return ans;
    }
};
// @lc code=end

