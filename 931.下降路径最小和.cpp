/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        if(matrix.size()==1) return matrix[0][0];
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;++i){
            for(int j=0;j<n;++j){
                if(j==0){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+matrix[i][j];
                }
                else if(j==n-1){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+matrix[i][j];
                }
                else{
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]))+matrix[i][j];
                }
            }
        }
        int minSum=INT_MAX;
        for(int i=n-1,j=0;j<n;++j){
            minSum=min(minSum,dp[i][j]);
        }
        return minSum;
    }
};
// @lc code=end

