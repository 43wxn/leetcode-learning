#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#

# @lc code=start
class Solution:
    def find_target_index(self, nums: list[int], target: int) -> int:
        left = -1
        right = len(nums)
        while left + 1 < right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid
            else:
                right = mid
        return right
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start = self.find_target_index(nums, target)
        if start == len(nums) or not nums[start] == target:
            return [-1,-1]
        end = self.find_target_index(nums, target+1) - 1
        return [start,end]
# @lc code=end

