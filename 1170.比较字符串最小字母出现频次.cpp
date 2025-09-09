/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 *
 * [1170] 比较字符串最小字母出现频次
 */

// @lc code=start
    int count_characters(string s) {
        map<char, int> counter;
        for (char c: s) {
            counter[c]++;
        }
        return counter.begin()->second;
    }
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> words_cnt(words.size(),0),ans;
        for (string s: words) {
            words_cnt.push_back(count_characters(s));
        }
        sort(words_cnt.begin(), words_cnt.end());
        int n = words_cnt.size();
        for (string s : queries) {
            auto idx = upper_bound(words_cnt.begin(),words_cnt.end(),count_characters(s));
            ans.push_back(n - (idx-words_cnt.begin()));
        }
        return ans;
    }
};
// @lc code=end

