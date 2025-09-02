/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
//用一个二维数组来存储每个子数组的和，dp[i][j]表示从i到j的子数组和
//通过计算每个子数组的和来找到最大的子数组和，
//使用二维数组会出现超出内存限制的情况 但是注意到 我们只使用了二维数组的上三角部分
//所以可以用一维数组来代替二维数组 
//下标映射公式：dp[i]=dp[i]
//用一维数组依然会超出内存限制 
//考虑只创建一个长度为nums.size()的数组来存储每个子数组的和
//只保存一行的数据
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0];
        int cur=nums[0];
        for(int i=1;i<nums.size();i++){
            cur=max(nums[i],cur+nums[i]);
            maxSum=max(maxSum,cur);
        }
        return maxSum;
    }
};
// @lc code=end

