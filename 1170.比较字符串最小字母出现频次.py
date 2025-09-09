#
# @lc app=leetcode.cn id=1170 lang=python3
#
# [1170] 比较字符串最小字母出现频次
#

# @lc code=start
class Solution:
    def count_characters(self, s: str) -> int:
        counter=Counter(s)
        min_char=min(counter.keys())
        return counter[min_char]
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        words_cnt=[]
        for s in words:
            words_cnt.append(self.count_characters(s))

        n=len(words_cnt)
        words_cnt.sort()
        ans=[]
        for s in queries:
            idx=bisect_right(words_cnt,self.count_characters(s))
            ans.append(n-idx)

        return ans
# @lc code=end

