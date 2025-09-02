/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
 */

// @lc code=start
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(),-1);
        if(nums.size()<2*k+1) return ans;
        if(k==0) return nums;
        int len=nums.size();
        double sum=0;
        for(int i=0;i<2*k+1;++i){
            sum+=nums[i];
        }
        ans[k]=sum/(2*k+1);
        for(int i=2*k+1;i<len;++i){
            sum+=nums[i];
            sum-=nums[i-(2*k+1)];
            ans[i-k]=sum/(2*k+1);
        }
        return ans;
    }
};
// @lc code=end

