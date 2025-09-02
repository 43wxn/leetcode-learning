/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
//s+s
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int window=s1.size();
        unordered_map<char,int> goal,cur;
        for(int i=0;i<s1.size();++i){
            if(goal.find(s1[i])==goal.end())    goal[s1[i]]=1;
            else    goal.at(s1[i])++;
        }
        for(int i=0;i<s2.size();++i){
            //cout<<"a"<<endl;
                if(cur.find(s2[i])==cur.end()){
                    //cout<<"b"<<endl;
                    cur[s2[i]]=1;
                }
                else{
                    //cout<<"c"<<endl;
                    cur.at(s2[i])++;
                }
                if(i>=window){
                    //cout<<"!!!"<<endl;
                    if(cur[s2[i-window]]==1)    
                        cur.erase(s2[i-window]);
                    else    
                        cur[s2[i-window]]--;
                }
                if(goal==cur)
                    return true;
        }
        return false;
    }
};
// @lc code=end

