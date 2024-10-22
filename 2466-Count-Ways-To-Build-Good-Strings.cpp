class Solution {
public:
long long int MOD=1e9+7;
long long int fun(int l,int s, int z, int o,vector<long long int>& dp){
    if(l>=s){
        return 0;
    }
    if(dp[l]!=-1){
        return dp[l];
    }
    long long int i1=0;
    long long int i0=0;
    if(l+o<=s){
    i1=fun(l+o,s,z,o,dp)+1;
    }
    if(l+z<=s){
     i0=fun(l+z,s,z,o,dp)+1;
    }
    
return dp[l]= (i1+i0)%MOD;
}

    int countGoodStrings(int low, int high, int z, int o) {
vector<long long int>dp1(high,-1);
vector<long long int>dp2(high,-1);
        return (fun(0,high,z,o,dp1)- fun(0,low-1,z,o,dp2) +MOD)% MOD;
    }
};