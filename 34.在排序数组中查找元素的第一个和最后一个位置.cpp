/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int find_target_index(vector<int>& nums, int target) {
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
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = find_target_index(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        int end = find_target_index(nums, target+1) - 1;
        return {start, end};
    }
};
// @lc code=end

