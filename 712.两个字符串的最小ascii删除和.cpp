/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start  let dp[i,j]be the answer for inputs s1[i:] and s2[j:]
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1=s1.size(),len2=s2.size();
        vector<vector<int>> dp(len1+1,vector(len2+1,0));//dp[i,j]是输入的字符串s1.s2的前i，j位的达到目标的最小ASCII删除和
        //initialize dp 
        for(int i=1;i<len1+1;++i){
            dp[i][0]=dp[i-1][0]+s1[i-1];
        }
        for(int j=1;j<len2+1;++j){
            dp[0][j]=dp[0][j-1]+s2[j-1];
        }
        dp[0][0]=0;
        for(int i=1;i<len1+1;++i){
            for(int j=1;j<len2+1;++j){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{ 
                    dp[i][j]=min(dp[i][j-1]+s2[j-1],dp[i-1][j]+s1[i-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end

