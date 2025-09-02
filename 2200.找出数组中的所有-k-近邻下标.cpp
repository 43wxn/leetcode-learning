/*
 * @lc app=leetcode.cn id=2200 lang=cpp
 *
 * [2200] 找出数组中的所有 K 近邻下标
 */

// @lc code=start
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int window=k,index=INT_MIN;
        vector<int> ans;
        for(int i=-k;i<(int)nums.size();++i){
            if(nums[min(i+window,(int)nums.size()-1)]==key){
                index=min(i+2*window,(int)nums.size()-1);
            }
            cout<<i<<" "<<index<<endl;
            if(i<=index&&i>=0){
                ans.push_back(i);
                cout<<i<<endl;
            }
        }
        return ans;
    }
};
// @lc code=end

