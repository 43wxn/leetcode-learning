/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        int maxNum=0;
        unordered_map<int,int> sum;
        for(int num:nums){
            maxNum=max(maxNum,num);
            sum[num]+=num;
        }
        vector<int> dp(maxNum+1,0);
        dp[0]=0;
        dp[1]=sum.count(1)?sum[1]:0;
        for(int i=2;i<maxNum+1;++i){
            dp[i]=max(dp[i-1],dp[i-2]+(sum.count(i)?sum[i]:0));
        }
        return dp[maxNum];
    }
};
// @lc code=end

