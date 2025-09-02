#
# @lc app=leetcode.cn id=2958 lang=python3
#
# [2958] 最多 K 个重复元素的最长子数组
#

# @lc code=start
class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        freq=dict()
        ans=0
        left=0
        right=-1
        for x in nums :
            freq[x]=freq.get(x,0)+1
            right+=1
            while freq[x]>k :
                freq[nums[left]]-=1
                left+=1
            ans=max(ans,right-left+1)
        return ans


# @lc code=end

