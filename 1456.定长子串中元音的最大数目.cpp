/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    int maxVowels(string s, int k) {
        int len=s.size(),ans=0,maxans=0;
        int right=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i]))
                ans++;
        }
        maxans=ans;
        for(int i=k;i<len;i++){
            if(isVowel(s[i]))
                ans++;
            if(isVowel(s[i-k]))
                ans--;
            maxans=max(maxans,ans);
        }
        return maxans;
    }
};
// @lc code=end

