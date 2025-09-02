/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n == 1) return 1;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        int maxLen = 1;
        for(int interval = 0; interval < n; ++interval) {
            for(int j = 0; j + interval + 1 < n; ++j) {
                int left = j;
                int rigth = j + interval + 1;

                if(s[left] == s[rigth]) {
                    if(left + 1 <= rigth - 1) {
                        dp[left][rigth] = dp[left + 1][rigth - 1] + 2;
                    } 
                    else {
                        dp[left][rigth] = 2;
                    }
                } 
                else {
                    dp[left][rigth] = max(dp[left + 1][rigth], dp[left][rigth - 1]);
                }

                maxLen = max(maxLen, dp[left][rigth]);
            }
        }

        return maxLen;
    }
};
// @lc code=end

