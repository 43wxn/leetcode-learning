/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int len=code.size(),sum=0;
        int n=abs(k);
        vector<int> ans(len,0);
        for(int i=0;i<abs(k);++i){
            sum+=code[i];
        }
        if(k==0){
            return ans;
        }
        else if(k>0){
            ans[len-1]=sum;
            for(int i=k;i<len+k;++i){
                sum+=code[i%len];
                sum-=code[(i-k)%len];
                ans[(i-k)%len]=sum;
            }
        }
        else{
            ans[n]=sum;
            for(int i=n;i<len+n;++i){
                sum+=code[i%len];
                sum-=code[(i-n)%len];
                ans[(i+1)%len]=sum;
            }
        }
        return ans;
    }
};
// @lc code=end

