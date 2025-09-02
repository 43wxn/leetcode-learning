#
# @lc app=leetcode.cn id=1695 lang=python3
#
# [1695] 删除子数组的最大得分
#

# @lc code=start
class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        map={}
        left=right=ans=cur=0
        for right in range(len(nums)):
            if nums[right] not in map:
                map[nums[right]]=right
                cur=cur+nums[right]
            else :
                left=map[nums[right]]+1
                map[nums[right]]=right
                cur=nums[left]+nums[right]
            ans=max(ans,cur)
        return ans
# @lc code=end

