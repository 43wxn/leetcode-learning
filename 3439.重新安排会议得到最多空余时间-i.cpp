/*
 * @lc app=leetcode.cn id=3439 lang=cpp
 *
 * [3439] 重新安排会议得到最多空余时间 I
 */

// @lc code=start
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        int maxfree=0,ans=0,TotalTime=0;
        for(int i=0;i<k;++i){
            TotalTime+=endTime[i]-startTime[i];
        }
        if(k==n){
            maxfree=eventTime-TotalTime;
        }
        else{
            maxfree=startTime[k]-TotalTime;
        }
        ans=maxfree;
        for(int i=k;i<n;++i){
            TotalTime+=endTime[i]-startTime[i];
            TotalTime-=endTime[i-k]-startTime[i-k];
            if(i<n-1){
                maxfree=startTime[i+1]-endTime[i-k]-TotalTime;
            }
            else{
                maxfree=eventTime-endTime[i-k]-TotalTime;
            }
            ans=max(ans,maxfree);
        }
        return ans;
    }
};
// @lc code=end

