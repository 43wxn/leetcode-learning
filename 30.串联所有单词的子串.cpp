/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
   vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    if (words.empty() || s.empty()) return ans;

    int word_len = words[0].size();
    int total_len = word_len * words.size();
    if (s.size() < total_len) return ans;

    unordered_map<string, int> word_count;
    for (const auto& word : words) {
        word_count[word]++;
    }

    for (int i = 0; i < word_len; ++i) {
        int left = i;
        unordered_map<string, int> current_count;

        for (int right = i; right + word_len <= s.size(); right += word_len) {
            string word = s.substr(right, word_len);
            if (word_count.find(word) != word_count.end()) {
                current_count[word]++;
                while (current_count[word] > word_count[word]) {
                    string left_word = s.substr(left, word_len);
                    current_count[left_word]--;
                    left += word_len;
                }
                if (right + word_len - left == total_len) {
                    ans.push_back(left);
                }
            } else {
                current_count.clear();
                left = right + word_len;
            }
        }
    }
    return ans;
    }
};
// @lc code=end

