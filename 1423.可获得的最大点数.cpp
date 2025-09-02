/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len=cardPoints.size();
        int sum=0;
        for(int i=k-1;i>=0;--i){
            sum+=cardPoints[i];
        }
        int ans=sum;
        for(int i=len-1;i>=len-k;--i){
            sum+=cardPoints[i];
            sum-=cardPoints[(i+k)%len];
            ans=max(ans,sum);
        }
        return ans;
    }
};
// @lc code=end

