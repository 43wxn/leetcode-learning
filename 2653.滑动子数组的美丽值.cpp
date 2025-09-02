/*
 * @lc app=leetcode.cn id=2653 lang=cpp
 *
 * [2653] 滑动子数组的美丽值
 */

// @lc code=start
//
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size(),index=0;
        vector<int> ans(n-k+1,0);
        vector<int> freq(101,0);
        auto getXth=[&](int x){
            int cnt=0;
            for(int i=0;i<101;++i){ 
                cnt+=freq[i];
                if(cnt>=x) return i-50;
            }
            return 0;
        };
        for(int i=0;i<k;++i){
            freq[nums[i]+50]++;
        }
        ans[index++]=min(0,getXth(x));
        for(int i=k;i<n;++i){
            freq[nums[i-k]+50]--;
            freq[nums[i]+50]++;
            ans[index++]=min(0,getXth(x));
        }
        return ans;
    }
};
// @lc code=end

 