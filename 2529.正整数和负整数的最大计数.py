#
# @lc app=leetcode.cn id=2529 lang=python3
#
# [2529] 正整数和负整数的最大计数
#

# @lc code=start
class Solution:
    def find_zero_index(self, nums: List[int], target: int) -> int:
        left = -1
        right = len(nums)
        while left+1 < right:
            mid = (left+right) // 2
            if nums[mid] < target:
                left = mid
            else:
                right = mid
        return right
    def maximumCount(self, nums: List[int]) -> int:
        '''
        二分查找 找0的第一个索引和最后一个索引
        '''
        start = self.find_zero_index(nums, 0)
        if start == len(nums):
            #print(1)
            return start
        elif not nums[start] == 0 :
            if nums[start] < 0:
                #print(2)
                return max(start+1,len(nums)-start-1)
            else:
                #print(3)
                return max(start,len(nums)-start)
        else:
            end = self.find_zero_index(nums, 1) - 1
            #print(4)
            return max(start,len(nums)-end-1)
# @lc code=end

