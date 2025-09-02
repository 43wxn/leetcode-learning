/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int n : nums) {
            total += n;
        }

        int target = total - x, left = 0, right = 0, length = -1;

        for (; right < nums.size();++right) {
            target -= nums[right];
            while (target<0) {
                target += nums[left];
                left++;
            }
            if (!target) {
                length = max(length, right - left + 1);
            }        
        }
        if (length==-1) {
            return -1;
        }
        else {
            return nums.size() - length;
        }
    }
};
// @lc code=end

