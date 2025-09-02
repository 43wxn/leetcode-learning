#
# @lc app=leetcode.cn id=6 lang=python3
#
# [6] Z 字形变换
#

# @lc code=start
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        rows=['']*numRows
        flag,cur_row=0,0
        for c in s:
            rows[cur_row]+=c
            if cur_row==0:
                flag=1
            elif cur_row==numRows-1:
                flag=-1
            cur_row+=flag
        return ''.join(rows)

# @lc code=end

