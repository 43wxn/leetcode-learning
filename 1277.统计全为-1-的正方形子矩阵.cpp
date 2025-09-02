/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
 */

// @lc code=start
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;++i){
            for(int j=1;j<n+1;++j){
                if(matrix[i-1][j-1]){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    ans+=dp[i][j];
                }
                else{
                    continue;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

