/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    unordered_map<int, int> map;
    int left = 0, ans = 0;
    for (int right = 0; right < fruits.size(); ++right) {
      if (map.size() == 2 && map.find(fruits[right]) == map.end()) {
        auto key = min_element(
            map.begin(), map.end(),
            [](const auto &a, const auto &b) { return a.second < b.second; });
        left = key->second + 1;
        map.erase(key->first);
        map[fruits[right]] = right;
      } else {
        map[fruits[right]] = right;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};
// @lc code=end

