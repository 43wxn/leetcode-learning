/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 *
 * [2586] 统计范围内的元音字符串数
 */

// @lc code=start
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            string word=words[i];
            if(word.size()>=2){
                if(word[0]=='a'|| word[0]=='e'|| word[0]=='i'|| word[0]=='o'|| word[0]=='u'){
                    if(word[word.size()-1]=='a'|| word[word.size()-1]=='e'|| 
                       word[word.size()-1]=='i'|| word[word.size()-1]=='o'|| 
                       word[word.size()-1]=='u'){
                        count++;
                    }
                }
            }
            else if(word.size()==1){
                if(word[0]=='a'|| word[0]=='e'|| word[0]=='i'|| 
                   word[0]=='o'|| word[0]=='u'){
                    count++;
                }
            } else {
                // 如果字符串长度小于1，直接跳过
                continue;
            }
        }
        return count;
    }
};
// @lc code=end

