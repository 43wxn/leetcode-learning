/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, right = 0, left = 0, cur=0;
        unordered_set<int> st;
        while (right < nums.size()) {
            if (st.count(nums[right])) {
                cur += nums[right];
                st.insert(nums[right]);
                right += 1;
            }
            else {
                cur -= nums[left];
                st.erase(nums[right]);
                left += 1;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
// @lc code=end

