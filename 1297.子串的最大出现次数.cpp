/*
 * @lc app=leetcode.cn id=1297 lang=cpp
 *
 * [1297] 子串的最大出现次数
 */

// @lc code=start
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<char,int> cnt;
        unordered_map<string,int> num;
        int len=s.size(),ans=0;
        for(int size=minSize;size<=maxSize;++size){
            cnt.clear();
            num.clear();
            for(int i=0;i<size;++i){
                if(cnt.find(s[i])==cnt.end()){
                    cnt[s[i]]=1;
                }
                else{
                    cnt[s[i]]++;
                }
            }
            if(cnt.size()<=maxLetters){
                num[s.substr(0,size)]=1;
            }
            for(int left=1,right=size;right<len;++left,++right){
                if(cnt.find(s[right])==cnt.end()){
                    cnt[s[right]]=1;
                }
                else{
                    cnt[s[right]]++;
                }
                if(cnt[s[left-1]]==1){
                    cnt.erase(s[left-1]);
                }
                else{
                    cnt[s[left-1]]--;
                }
                if(cnt.size()<=maxLetters){
                    if(num.find(s.substr(left,right-left+1))==num.end()){
                        num[s.substr(left,right-left+1)]=1;
                    }
                    else{
                        num[s.substr(left,right-left+1)]++;
                    }
                }
            }
            for(const auto&[key,value]:num){
                ans=max(value,ans);
            }
        }
        return ans;
    }
};
// @lc code=end

