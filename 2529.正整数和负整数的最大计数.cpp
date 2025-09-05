/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 */

// @lc code=start
class Solution {
public:
    int find_zero_index(vector<int> nums, int target) {
        int left = -1, right = nums.size();
        while (left+1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
    int maximumCount(vector<int>& nums) {
        int start = find_zero_index(nums, 0);
        if (start == nums.size()) {
            return start;
        }
        else if (nums[start]!=0) {
            return nums[start] < 0 ? max(start + 1, (int)nums.size() - start - 1) : max(start, (int)nums.size() - start);
        }
        else {
            int end = find_zero_index(nums, 1);
            return max(start, (int)nums.size() - end);
        }
    }
};
// @lc code=end

