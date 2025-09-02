/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
 */

// @lc code=start
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int> cnt;
        int len=nums.size();
        long long sum=0,ans=0;                        
        for(int i=0;i<k;++i){
            sum+=nums[i];
            if(cnt.find(nums[i])!=cnt.end())
                cnt.at(nums[i])++;
            else{
                cnt[nums[i]]=1;
            }
        }
        if(cnt.size()>=m)
            ans=sum;
        for(int i=k;i<len;++i){
            sum+=nums[i];
            sum-=nums[i-k];
            if(cnt.find(nums[i])!=cnt.end())
                cnt.at(nums[i])++;
            else{
                cnt[nums[i]]=1;
            }
            cnt[nums[i-k]]--;
            if(cnt[nums[i-k]]==0)
                cnt.erase(nums[i-k]);
            if(cnt.size()>=m)
                ans=max(ans,sum);
        }
        return ans;
    }
};
// @lc code=end

