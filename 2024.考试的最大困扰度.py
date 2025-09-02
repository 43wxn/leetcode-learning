#
# @lc app=leetcode.cn id=2024 lang=python3
#
# [2024] 考试的最大困扰度
#

# @lc code=start
class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        num_true=num_false=0
        left=0
        right=-1
        ans=0
        for c in answerKey :
            if c=='T':
                num_true+=1
            else :
                num_false+=1
            right+=1
            while min(num_false,num_true) > k:
                if answerKey[left] == 'T':
                    num_true-=1
                else :
                    num_false-=1
                left+=1
            ans=max(ans,right-left+1)
        return ans

# @lc code=end

