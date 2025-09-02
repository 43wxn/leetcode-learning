/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
//因为一次只能往右或者往下走一格 那么 对于一个 m*n 的矩形
//走到（i，j）这个点的路径数目等于走到（i-1，j）和（i，j-1）这两个点的路径之和 
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(i==1&&j==1)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

