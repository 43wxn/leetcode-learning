/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int len = nums.size(),maxlen = 1;
        vector<int> dp(len,1),cnt(len,1);
        for(int i=0;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    if(dp[i]>maxlen){
                        maxlen=dp[i];
                        cnt[i]=cnt[j];
                    }
                    else if(dp[i]==maxlen){
                        cnt[i]+=cnt[j];
                    }
                    else{
                        ;
                    }
               }         
                else if(nums[i]==nums[j]){
                    cnt[i]=cnt[j];
                }
                else{
                    ;
                }
            }
        }
        return cnt[len-1];
    }
};
// @lc code=end

