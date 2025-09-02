/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int len=blocks.size(),ans=0,cnt=0;
        for(int i=0;i<k;++i){
            if(blocks[i]=='W'){
                cnt++;
            }
        }
        ans=cnt;
        for(int i=k;i<len;++i){
            if(blocks[i]=='W'){
                cnt++;
            }
            if(blocks[i-k]=='W'){
                cnt--;
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
};
// @lc code=end

