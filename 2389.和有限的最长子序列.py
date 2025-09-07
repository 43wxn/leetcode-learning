#
# @lc app=leetcode.cn id=2389 lang=python3
#
# [2389] 和有限的最长子序列
#

# @lc code=start
class Solution:
    #from bisect import bisect_right
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        '''先把nums排序 再遍历一遍记录当前位置的总和
            二分查找大于等于queries[i]的第一个数'''
        nums.sort()
        for i in range(1,len(nums)):
            nums[i]=nums[i-1]+nums[i]
        
        #二分查找
        ans=[]
        for target in queries:
            idx=bisect_right(nums,target)
            ans.append(idx)
        return ans            
# @lc code=end

