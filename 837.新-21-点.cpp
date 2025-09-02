/*
 * @lc app=leetcode.cn id=837 lang=cpp
 *
 * [837] 新 21 点
 */

// @lc code=start
//f[i]表示从手牌点数为i的时候再进行一次抽牌而到达[k,n]区间的概率
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> f(n+1,0);
        double window=0;
        for(int i=k;i<n+1;++i){
            f[i]=1;
        }
        for(int i=k;i<k+maxPts;++i){
            if(i>n) window+=0;
            else    window+=f[i];
        }
        for(int i=k-1;i>=0;--i){
            f[i]=window/maxPts;
            if(i+maxPts>n) window-=0;
            else    window-=f[i+maxPts];
            window+=f[i];
        }
        return f[0];
    }
};
// @lc code=end

