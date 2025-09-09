#
# @lc app=leetcode.cn id=2080 lang=python3
#
# [2080] 区间内查询数字的频率
#

# @lc code=start
class RangeFreqQuery:

    def __init__(self, arr: List[int]):
        pos=defaultdict(list)
        for index,value in enumerate(arr):
            pos[value].append(index)
        self.pos=pos
    
    def query(self, left: int, right: int, value: int) -> int:
        start=bisect_left(self.pos[value],left)
        end=bisect_left(self.pos[value],right+1)-1
        return end-start+1

# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)
# @lc code=end

