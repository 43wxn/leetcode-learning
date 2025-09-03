/*
 * @lc app=leetcode.cn id=2831 lang=cpp
 *
 * [2831] 找出最长等值子数组
 */

// @lc code=start
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int left = 0, ans = 0, max_cnt=0;
        for (int right = 0; right < nums.size();++right) {
            count[nums[right]]++;
            max_cnt = max(max_cnt,count[nums[right]]);
            while ((right-left+1)-max_cnt>k) {
                count[nums[left]]--;
                left++;
            }
            ans = max(ans, max_cnt);
        }
        return ans;
    }
};
// @lc code=end

