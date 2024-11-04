class Solution {
public:

long long int dp[1001]={0};
long long int MOD=1e9+7;
    int numTilings(int n) {
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(n==3){
            return 5;
        }
        if(dp[n]!=0){
            return dp[n];
        }
        return dp[n]= (2*numTilings(n-1)%MOD+numTilings(n-3)%MOD)%MOD;
    }
};