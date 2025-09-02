#
# @lc app=leetcode.cn id=1838 lang=python3
#
# [1838] 最高频元素的频数
#

# @lc code=start
class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        '''
        先对数组进行倒序排序
        维护一个动态滑动窗口 右端进入元素，同时计算其与左端元素的差值，窗口中的元素差值总和<k
        差值总和>k时，移动左端移出元素，同时重新计算差值
        寻找这样最长的子数组
        '''
        nums.sort(reverse=True)
        left=ans=total=0
        for right in range(0,len(nums)):
            total+=nums[left]-nums[right]
            while total > k:
                total-=(nums[left]-nums[left+1])*(right-left)
                left+=1
            ans=max(ans,right-left+1)
        return ans
# @lc code=end

