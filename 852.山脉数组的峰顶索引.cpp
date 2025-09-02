/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    //O(logN)二分查找
        int left=0,right=arr.size()-1;
        while(1){
            int mid=left+(right-left)/2;
            if(arr[mid]<arr[mid+1]){
                left=mid+1;
            }
            else if(arr[mid]<arr[mid-1]){
                right=mid-1;
            }
            else{
                return mid;
            }
        }
        return 0;
    }
};
// @lc code=end

