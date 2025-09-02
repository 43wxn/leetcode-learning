/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) {
            return 0; // 如果起点有障碍物，直接返回0
        }
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if(i==0||j==0){
                    if(obstacleGrid[i][j]==1){
                        dp[i][j]=0;
                    }
                    else{
                        if(i==0 && j==0) 
                            dp[i][j] = 1; // 起点处的路径数为1
                        else if(i==0) 
                            dp[i][j]=dp[i][j-1];
                        else 
                            dp[i][j]=dp[i-1][j];
                    }
                }
                else{
                    if(obstacleGrid[i][j]==1){
                        dp[i][j]=0;
                    }
                    else{
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

