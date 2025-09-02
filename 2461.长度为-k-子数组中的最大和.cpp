/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
 */

// @lc code=start
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int len=nums.size();
        unordered_map<int,int> cnt;
        long long sum=0,ans=0;
        for(int i=0;i<k;++i){
            sum+=nums[i];
            if(cnt.find(nums[i])!=cnt.end())
                cnt[nums[i]]++;
            else
                cnt.insert({nums[i],true});
        }
        if(cnt.size()==k)
            ans=sum;
        for(int i=k;i<len;++i){
            sum+=nums[i];
            sum-=nums[i-k];
            cnt[nums[i-k]]--;
            if(cnt[nums[i-k]]==0)
                cnt.erase(nums[i-k]);
            if(cnt.find(nums[i])!=cnt.end())
                cnt[nums[i]]++;
            else
                cnt.insert({nums[i],true});
            if(cnt.size()==k)
                ans=max(ans,sum);
        }
        return ans;
    }
};
// @lc code=end

