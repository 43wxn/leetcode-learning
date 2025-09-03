#
# @lc app=leetcode.cn id=2831 lang=python3
#
# [2831] 找出最长等值子数组
#

# @lc code=start
class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        '''
        维护一个动态滑动窗口
        右端加入元素，同时用一个hash表统计数字出现的频率，其中最大频数是该窗口的等值，其他频数之和是可删去的 需<=k
        在窗口达不到要求时，左端移出元素使窗口重新达到要求
        记录窗口的最长值
        '''
        count=defaultdict(int)  #用字典统计频率，而不是count=[0]*(max(nums)+1) 节省空间
        left=ans=max_count=0

        for right,value in enumerate(nums,start=0):
            count[value]+=1
            #我们只需要找到窗口中的最大频率，在右端加入元素的时候，只有可能被加入的那个元素的频率大于当前最大频率
            #这里做一下判断
            max_count=max(max_count,count[value])  
            #在上一个状态，窗口一定是合法的，只有在加入了不属于等值子数组的元素时，才会进入while循环
            while (right-left+1)-max_count>k:
                count[nums[left]]-=1
                left+=1
            ans=max(ans,max_count)
        return ans
# @lc code=end

