#
# @lc app=leetcode.cn id=2516 lang=python3
#
# [2516] 每种字符至少取 K 个
#

# @lc code=start
class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        '''
        正难则反
        abc三种字符至少取k个 那么先统计字符串s中abc字符的总数
        则要取一个连续的窗口，包含abc三个字符至多cot_a/cot_b/cot_c - k个
        取一个这样的最长的窗口
        '''
        list_abc=[0,0,0]
        for c in s:
            list_abc[ord(c)-ord('a')]+=1
        
        target=[x-k for x in list_abc]
        if target[0]<0 or target[1]<0 or target[2]<0:
            return -1
        #print(target)
        left=right=0
        ans=-1
        for right in range(len(s)):
            target[ord(s[right])-ord('a')]-=1
            while (target[0]<0 or target[1]<0 or target[2]<0) and left<=right:
                target[ord(s[left])-ord('a')]+=1
                left+=1
            ans=max(ans,right-left+1)
        if ans==-1:
            return -1
        else :
            return len(s)-ans
# @lc code=end

