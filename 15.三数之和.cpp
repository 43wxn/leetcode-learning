// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    unordered_map<string, bool> set;
    for (int i = 0; i < nums.size(); ++i) {
      int target = -nums[i];
      for (int j = i + 1; j < nums.size(); ++j) {
        for (int k = j + 1; k < nums.size(); ++k) {
          if (nums[j] + nums[k] == target) {
            vector<int> temp = {nums[i], nums[j], nums[k]};
            sort(temp.begin(), temp.end());
            string s =
                to_string(temp[0]) + to_string(temp[1]) + to_string(temp[2]);
            if (set.find(s) == set.end()) {
              ans.push_back({nums[i], nums[j], nums[k]});
              set[s] = true;
            }
          }
        }
      }
    }
    return ans;
  }
};
// @lc code=end
