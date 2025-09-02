/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

// @lc code=start
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int num_true = 0, num_false = 0;
        int ans = 0, right = -1, left = 0;
        for (char c : answerKey) {
            c == 'T' ? num_true++ : num_false++;
            right++;
            while (min(num_false, num_true) > k) {
            answerKey[left] == 'T' ? num_true-- : num_false--;
            left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
        }
};
// @lc code=end

