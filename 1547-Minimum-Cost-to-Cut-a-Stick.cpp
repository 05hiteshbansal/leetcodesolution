class Solution {
public:

int fun(int left,int right,vector<int>& cuts , vector<vector<int>>& dp){
    if(right-left==1){
        return 0;
    }
    if(dp[left][right]!=-1){
        return dp[left][right];
    }
    int ans=INT_MAX;
    for(int k=left+1;k<right;k++){
        ans=min(ans,cuts[right]-cuts[left]+ fun(k,right,cuts,dp)+fun(left,k,cuts,dp));
    }

    return dp[left][right]= ans;
}

    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        vector<vector<int>>dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        int left=0;
        int right=cuts.size()-1;
        return fun(left,right,cuts,dp);
    }
};