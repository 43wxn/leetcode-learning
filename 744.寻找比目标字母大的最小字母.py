#
# @lc app=leetcode.cn id=744 lang=python3
#
# [744] 寻找比目标字母大的最小字母
#

# @lc code=start
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        left = -1
        right = len(letters)
        while left+1 < right:
            mid = (left+right)//2
            if ord(letters[mid]) < ord(target)+1:
                left = mid
            else:
                right = mid
        if right == len(letters):
            return letters[0]
        else:
            return letters[right]
# @lc code=end

