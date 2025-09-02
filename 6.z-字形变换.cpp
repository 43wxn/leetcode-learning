/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows ==1 || numRows >=s.size()||s.size()==1){
            return s;
        }     
        vector<string> rows(numRows);
        int flag=1,index=0;
        for(int i=0;i<s.size();i++){
            rows[index]+=s[i];
            if(index==numRows-1){
                flag=-1;
            }else if(index==0){
                flag=1;
            }
            index+=flag;
        }
        return accumulate(rows.begin(),rows.end(),string(""));
    }
};
// @lc code=end

