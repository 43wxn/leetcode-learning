#
# @lc app=leetcode.cn id=395 lang=python3
#
# [395] 至少有 K 个重复字符的最长子串
#

# @lc code=start
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        '''
        维护一个动态滑动窗口
        统计字符串中的字符种类和各数--> 个数大于k/个数小于k
        右端加入元素 同时统计元素的种类和个数 

        ababbbcababba   k=2
        a:5 b:7 c:1
        当右端碰到个数小于k的元素时，右端到头，检查该窗口是否满足条件
        记录窗口最长值
        '''
        count=cur=dict()
        left=ans=0
        min_cnt=len(s)+1
        for c in s:
            count[s]=count[s].get(s,0)+1

        for right,value in enumerate (s,start=1):
            cur[value]+=1
            min_cnt=min(min_cnt,cur[value])
            if min_cnt>=k:
                ans=max(ans,right-left+1)
            if  count[value]<k:
                left=right+1
            
        return ans


# @lc code=end

