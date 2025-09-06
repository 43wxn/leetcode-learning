#
# @lc app=leetcode.cn id=1385 lang=python3
#
# [1385] 两个数组间的距离值
#

# @lc code=start
class Solution:
    def find_j(self, nums: List[int], target: int) -> int:
        '''找在升序排序的nums中第一个大于等于target的数的索引'''
        left = -1
        right = len(nums)
        while left+1 < right:
            mid = (left+right) // 2
            if nums[mid] < target:
                left = mid
            else:
                right = mid
        return right
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        '''
        排序+二分查找
        对arr2排序，遍历arr1
        |arr1[i]-arr2[j]| <= d 不满足这个条件 则对于每一个arr1[i]
        arr2中的元素都不能满足arr2[j]<=aee1[i]+d && arr[i]-d<=arr2[j]
        即每一个元素都满足arr2[j]>arr1[i]+d || arr[i]-d>arr2[j]
        二分查找arr1[i]+d 和 arr1[i]-d的位置 看是否在-1和len(nums)位置
        '''
        arr2.sort()
        ans = 0
        for x in arr1:
            #区间的上下限，如果在arr2中
            low = x - d
            high = x + d 
            low_index = self.find_j(arr2, low)
            high_index = self.find_j(arr2, high+1) - 1
            if low_index > high_index:
                ans+=1
        return ans
# @lc code=end
