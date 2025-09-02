#
# @lc app=leetcode.cn id=1004 lang=python3
#
# [1004] 最大连续1的个数 III
#

# @lc code=start
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        count=0
        ans=left=0
        right=-1
        for x in nums:
            if not x:
                count+=1
            right+=1
            while count > k:
                if not nums[left]:
                    count-=1
                left+=1
            ans=max(ans,right-left+1)
        return ans
# @lc code=end

