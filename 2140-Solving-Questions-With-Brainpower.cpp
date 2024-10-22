class Solution {
public:

long long int fun(int idx,vector<vector<int>>& q, vector<long long int>& dp){
    if(idx>=q.size()){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    long long int include=fun(idx+q[idx][1]+1,q,dp)+q[idx][0];
    long long int notinclude=fun(idx+1,q,dp);

    return dp[idx]= max(include,notinclude);
}

    long long mostPoints(vector<vector<int>>& q) {
        vector<long long int>dp(q.size(),-1);
        return fun(0,q,dp);
    }
};