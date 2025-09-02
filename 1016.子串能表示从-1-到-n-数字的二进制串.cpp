// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 */

// @lc code=start
class Solution {
public:
    bool queryString(string s, int n) {
        unordered_map<int,int> cur;
        auto getBinary=[](int n){
            int count=0;
            while(n){
                count++;
                n>>=1;
            }
            return count;
        };
        for(int window=1;window<=getBinary(n);++window){
            int count=pow(2,window-1);//窗口为window时需要找count个数
            cout<<"count:"<<count<<endl;
            int num=0;
            for(int i=0;i<s.size();++i){
                if(i<window){
                    num+=(s[i]-'0')*pow(2,window-i-1);
                }
                else{
                    num-=pow(2,window-1)*(s[i-window]-'0');
                    num*=2;
                    num+=s[i]-'0';
                }
                cout<<num<<endl;
                if(i>=window-1){
                    if(num>=1&&num<=n){
                        if(cur.find(num)==cur.end()){
                            count--;
                            cur[num]=1;
                            cout<<"exist"<<endl;
                        }
                        else{
                            continue;
                        }
                        if(count<=0){
                            break;
                        }
                    }
                }
            }
        }
        cout<<cur.size()<<endl;
        if(cur.size()==n){
            return true;
        }
        else{
            return false;
        }
    }
};
// @lc code=end

