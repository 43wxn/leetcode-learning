/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int start=0;
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        for(int i=0;i<s.size();i++){
            for(int j=0;j<=i;j++){
                if(dp[j]&&wordSet.count(s.substr(j,i-j+1))){
                    dp[i+1]=true;
                    break;
                }    
                else{
                    dp[i+1]=false;
                }        
            }
        }
        return dp[s.size()]==1?true:false;
    }
};
// @lc code=end

