#
# @lc app=leetcode.cn id=2730 lang=python3
#
# [2730] 找到最长的半重复子字符串
#

# @lc code=start
class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        '''
        寻找一个最长字串
        满足字串中最多只要一个相邻字符相等
        维护一个动态的窗口 窗口右端加入元素
        在入口检测是否有成对字符进入窗口,记录上一次成对字符出现的索引，
        当再次出现成对字符的时候把左端点移动到上一次成对字符的最后一个，并更新上一次成对字符出现的索引
        统计最长字串

        '''
        if len(s)==1:
            return 1
        ans=0
        left=index=0
        for right in range(1,len(s)):
            if s[right]==s[right-1]:
                left=index
                index=right
            ans=max(ans,right-left+1)
        return ans

                
# @lc code=end

