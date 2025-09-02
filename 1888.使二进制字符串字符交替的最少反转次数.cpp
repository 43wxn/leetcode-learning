/*
 * @lc app=leetcode.cn id=1888 lang=cpp
 *
 * [1888] 使二进制字符串字符交替的最少反转次数
 */

// @lc code=start
class Solution {
public:
    int minFlips(string s) {
        int len=s.size(),window=len;
        int ans=INT_MAX,count=0;
        for(int i=0;i<len+window;++i){
            if(i<window){
                if(s[i%len]-'0'==i%2){
                    count++;
                }
                cout<<count<<endl;
            }
            else{
                ans=min(ans,min(count,window-count));
                if(s[i%len]-'0'==i%2){
                    count++;
                }
                if(s[(i-window)%len]-'0'==(i-window)%2){
                    count--;
                }
            }
       }
       return ans;
    }
}; 
// @lc code=end

