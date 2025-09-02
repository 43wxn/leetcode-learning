/*
 * @lc app=leetcode.cn id=1504 lang=cpp
 *
 * [1504] 统计全 1 子矩形
 */
//动态规划问题 dp[i][j]表示以（i，j）为右下角，产生的子矩形数量；
// @lc code=start
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int ans=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (int i=1;i<m+1;++i) {
            for (int j=1;j<n;++j) {
                if (mat[i-1][j-1]) {

                }
            }
        }
    }
};
// @lc code=end

