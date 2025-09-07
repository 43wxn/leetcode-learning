/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size();++i) {
            nums[i] = nums[i - 1] + nums[i];
        }

            vector<int> ans;
        for (int target : queries) {
            auto idx = upper_bound(nums.begin(), nums.end(), target);
            ans.push_back(idx-nums.begin());
        }
        return ans;
    }
};
// @lc code=end

