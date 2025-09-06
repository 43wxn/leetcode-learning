/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start
class Solution {
public:
    int find_first_index(vector<int>& nums, long long target) {
        int left = -1, right = nums.size();
        while (left+1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end(), [](int a, int b)
             { return a > b; });
        vector<int> pairs;
        for (int x : spells) {
            long long target = success % x ? success / x + 1 : success / x; //因为是向下取整 当非整除时加1
            int index = find_first_index(potions, target);
            pairs.push_back(index);
        }
        return pairs;
    }
};
// @lc code=end

