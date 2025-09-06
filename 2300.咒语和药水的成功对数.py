#
# @lc app=leetcode.cn id=2300 lang=python3
#
# [2300] 咒语和药水的成功对数
#

# @lc code=start
class Solution:
    def find_first_potion(self, nums: List[int], target: float) -> int:
        left=-1
        right=len(nums)
        while left+1 < right:
            mid = (left+right) // 2
            if nums[mid] >= target : #维护left的左边一直比target大
                left = mid
            else :
                right = mid
        return right
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        '''
        遍历sells数组，对于每一个咒语，算出所需的最低药水能量
        对potions降序排序，二分查找该最低药水能量的索引
        '''
        potions.sort(reverse=True)
        pairs = []
        for x in spells:
            target = success /x #python中浮点数和整数比较 回自动把整数转化为浮点数
            index = self.find_first_potion(potions, target)
            pairs.append(index)
        return pairs
# @lc code=end

