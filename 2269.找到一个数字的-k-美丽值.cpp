/*
 * @lc app=leetcode.cn id=2269 lang=cpp
 *
 * [2269] 找到一个数字的 K 美丽值
 */

// @lc code=start
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num),window="";
        int ans=0;
        for(int i=0;i<s.size();++i){
            window+=s[i];
            if (i>=k) {
                window=window.substr(1,window.size());
            }
            int bnum = stoi(window);
            if (!bnum) continue;
            cout<<bnum<<endl;
            if (!(num%bnum)&&i>=k-1) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

