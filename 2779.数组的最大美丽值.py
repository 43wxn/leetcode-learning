#
# @lc app=leetcode.cn id=2779 lang=python3
#
# [2779] 数组的最大美丽值
#

# @lc code=start
class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        '''
        维护一个动态的滑动窗口，先对数组排序
        所以问题就变成了 寻找一个子数组，A[i.....j]使之满足A[i]-A[i]<=2*k
        寻找最长的这个子数组
        '''
        nums.sort()
        left=ans=0
        for right in range(0,len(nums)) :
            while nums[right]-nums[left]>2*k:
                left+=1
            ans=max(ans,right-left+1)
        return ans

# @lc code=end

