#
# @lc app=leetcode.cn id=3488 lang=python3
#
# [3488] 距离最小相等元素查询
#

# @lc code=start
class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        '''将nums按照元素值进行统计'''
        index=defaultdict(list)
        n=len(nums)
        for i,x in enumerate(nums):
            index[x].append(i)
        
        ans=[]
        for x in queries:
            length=len(index[nums[x]])
            if length==1:
                ans.append(-1)
            else:
                idx=bisect_left(index[nums[x]],x)
                '''
                if x==5:
                    print(idx)
                    print(index[nums[x]][idx-1])
                    print(index[nums[x]][(idx+1)%len(index[nums[x]])])
                '''
                right=(idx+1)%length
                left=(idx-1+length)%length
                dis1=min(abs(x-index[nums[x]][right]),n-abs(x-index[nums[x]][right]))
                dis2=min(abs(x-index[nums[x]][left]),n-abs(x-index[nums[x]][left]))
                min_distance=min(dis1,dis2)
                ans.append(min_distance)
        return ans
# @lc code=end

