#
# @lc app=leetcode.cn id=904 lang=python3
#
# [904] 水果成篮
#

# @lc code=start
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        '''
        两个篮子则代表至多出现两个不同的数值
        动态滑动窗口，right端增大，当出现两个不同的数时，在第三个数停下
        出现第三个数，left端移动到第一个数的最后一个index+1位置处，right端继续增大
        计算窗口的最大值
        '''
        map={}
        ans=0
        left=right=0
        for right in range(len(fruits)): 
            if len(map)<=2 and fruits[right] not in map:
                left=map[fruits[left]]
                del map[fruits[left]]
                left=left+1
            else :
                map[fruits[right]]=right
            ans=max(ans,right-left+1)
        return ans            

# @lc code=end

