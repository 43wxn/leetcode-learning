/*
 * @lc app=leetcode.cn id=2156 lang=cpp
 *
 * [2156] 查找给定哈希值的子串
 */

// @lc code=start
class Solution {
public:
    int hash(string sub,int power,int modulo){
        long long value=0;
        for(int i=0;i<sub.size();++i){
            value+=((sub[i]-'a'+1)%modulo*pow(power,i)%modulo)%modulo;
        }
        return value%modulo;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        string ans="";
        for(int i=0;i<k;++i){
            for(int left=i;left+k<s.size()+1;left+=k){
                ans=s.substr(left,k);
                if(hash(ans,power,modulo)==hashValue){
                    return ans;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

