/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int len=arr.size(),ans=0;
        double sum=0.0;
        for(int i=0;i<k;++i){
            sum+=arr[i];
        }
        double m = (double)k * threshold;
        if(sum >= m)
            ans++;
        for(int i=k;i<len;++i){
            sum+=arr[i];
            sum-=arr[i-k];
            if(sum>=m)
                ans++;
            
        }
        return ans;
    }
};
// @lc code=end

