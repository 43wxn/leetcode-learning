#
# @lc app=leetcode.cn id=35 lang=python3
#
# [35] 搜索插入位置
#

# @lc code=start
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        '''
        二分法找到>=target的第一个数的索引
        '''
        left = -1
        right = len(nums)
        while left+1 < right:
            mid = (left+right) // 2
            if nums[mid] < target:
                left = mid
            else:
                right = mid
        return right
# @lc code=end

