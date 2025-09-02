/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */

// @lc code=start
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=k-1;i<nums.size();++i) {
            ans=min(ans,nums[i]-nums[i-k+1]);
        }
        return ans;
    }
};
// @lc code=end

