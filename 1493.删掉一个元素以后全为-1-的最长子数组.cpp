/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> index;
        for (int i = 0; i < nums.size();++i) {
            if(nums[i]==0) {
                index.push_back(i);
            }
        }
        int ans = 0;
        for (int i = 2; i < index.size();++i) {
            ans = max(ans, index[i] - index[i - 2] - 1);
        }
        return ans;
    }
};
// @lc code=end

