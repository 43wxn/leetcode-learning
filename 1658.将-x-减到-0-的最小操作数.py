#
# @lc app=leetcode.cn id=1658 lang=python3
#
# [1658] 将 x 减到 0 的最小操作数
#

# @lc code=start
class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        """
        正难则反
        """
        total=0
        for num in nums:
            total+=num
        
        target=total-x
        length=-1
        right=-1
        left=0
        for num in nums:
            target-=num
            right+=1
            while target<0:
                target+=nums[left]
                left+=1
            if target==0:
                length=max(length,right-left+1)
        if length==-1:
            return -1
        else:
            return len(nums)-length
                
                   
# @lc code=end

