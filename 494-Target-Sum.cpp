class Solution {
public:

int fun(int idx ,int sum, int t,vector<int>& arr ,vector<vector<int>> &dp){
    if(idx==arr.size()){
        if(sum==t){
            return 1;
        }
        return 0;
    }

    if(dp[idx][sum+1001]!=-1){
        return dp[idx][sum+1001];
    }
    return dp[idx][sum+1001]=fun(idx+1,sum+arr[idx],t,arr,dp)+fun(idx+1,sum-arr[idx],t,arr,dp);
}


    int findTargetSumWays(vector<int>& nums, int t) {
        vector<vector<int>>dp(21,vector<int>(2005,-1));
        return fun(0,0,t,nums,dp);
    }
};