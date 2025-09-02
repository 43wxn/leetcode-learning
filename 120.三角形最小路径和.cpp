/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int index(int i,int j){
        return i*(i+1)/2+j;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1) return triangle[0][0];
        int n=triangle.size(); 
        vector<int> dp(n*(n+1)/2,0);
        dp[0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    dp[index(i,j)]=dp[index(i-1,j)]+triangle[i][j];
                }
                else if(j==i){
                    dp[index(i,j)]=dp[index(i-1,j-1)]+triangle[i][j];
                }
                else{
                    dp[index(i,j)]=min(dp[index(i-1,j)],dp[index(i-1,j-1)])+triangle[i][j];
                }
            }
        }
        int minSum=INT_MAX;
        for(int i=index(n-1,0);i<index(n,0);i++){
            minSum=min(minSum,dp[i]);
        }
        return minSum;
    }
};
// @lc code=end

