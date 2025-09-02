/*
 * @lc app=leetcode.cn id=2134 lang=cpp
 *
 * [2134] 最少交换次数来组合所有的 1 II
 */

// @lc code=start
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count=0,minswap=0,swap=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1)
                count++;
        }
        for(int i=0;i<count;++i){
            if(nums[i]==0)
                swap++;
        }
        minswap=swap;
        for(int i=count;i<nums.size()+count;++i){
            if(nums[i%nums.size()]==0)
                swap++;
            if(nums[(i-count)%nums.size()]==0)
                swap--;
            minswap=min(minswap,swap);
        }
        return minswap;
    }
};
// @lc code=end

