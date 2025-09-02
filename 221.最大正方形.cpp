/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==1&&matrix[0].size()==1) return matrix[0][0]=='1'?1:0;
        int m=matrix.size(),n=matrix[0].size();
        int maxsize=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=1;
                }
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(matrix[i-1][j-1]=='0')
                    continue;
                else{
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
                maxsize=max(maxsize,dp[i][j]);
            }
        }
        return maxsize*maxsize;
    }
};
// @lc code=end

