/*
 * @lc app=leetcode.cn id=2348 lang=cpp
 *
 * [2348] 全 0 子数组的数目
 */

// @lc code=start
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        for(int left=0;left<nums.size();++left){
            if(!nums[left]){
                ans++;
                for(int right=left+1;right<nums.size();++right){
                    if(nums[right]){
                        left=right;
                        break;
                    }
                    else{
                        ans+=right-left+1;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

