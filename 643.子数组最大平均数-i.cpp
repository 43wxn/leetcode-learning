/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len=nums.size();
        double ans=0.0;
        for(int i=0;i<k;i++){
            ans+=nums[i];
        }
        double maxsum=ans;
        for(int i=k;i<len;i++){
            ans+=nums[i];
            ans-=nums[i-k];
            maxsum=max(maxsum,ans);
        }
        return maxsum/k;
    }
};
// @lc code=end

