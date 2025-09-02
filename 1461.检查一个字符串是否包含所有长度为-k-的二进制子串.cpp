/*
 * @lc app=leetcode.cn id=1461 lang=cpp
 *
 * [1461] 检查一个字符串是否包含所有长度为 K 的二进制子串
 */

// @lc code=start
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int maxNum=pow(2,k)-1,num=0,total=0;
        //cout<<maxNum<<endl;
        unordered_map<int,bool> count;
        for (int i=0;i<s.size();++i) {
            if (i<k) {
                num+=pow(2,k-i-1)*(s[i]-'0');
            }
            else {
                if (num<=maxNum) {
                    //cout<<"there"<<endl;
                    if (count.find(num)==count.end()) {
                        cout<<"here"<<endl;
                        count[num]=true;
                        total++;
                    }
                }  
                num-=pow(2,k-1)*(s[i-k]-'0');
                num*=2;
                num+=s[i]-'0';
            }
            cout<<i<<":"<<num<<endl;
        }
        if(total==maxNum+1){
            return true;
        }
        else{
            return false;
        }
    }
};
// @lc code=end

