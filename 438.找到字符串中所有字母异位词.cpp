/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int window=p.size(),index=0;;
        vector<int> ans;
        unordered_map<char,int> goal,cur;
        for(int i=0;i<window;++i){
            if(goal.find(p[i])==goal.end()){
                goal[p[i]]=1;
            }
            else{
                goal.at(p[i])++;
            }
        }
        for(int i=0;i<s.size();++i){
            if(cur.find(s[i])==cur.end()){
                cur[s[i]]=1;
            }
            else{
                cur.at(s[i])++;
            }
            if(i>=window){
                if(cur[s[i-window]]==1){
                    cur.erase(s[i-window]);
                }
                else{
                    cur[s[i-window]]--;
                }
            }
            if(cur==goal){
                ans.push_back(i-window+1);
            }
        }
        return ans;
    }
};
// @lc code=end

