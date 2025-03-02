class Solution {
public:
vector<vector<vector<int>>>dp;
int fun(int b,int l,string &s , int k ){
    if(b>l){
        return 0;
    }
    if(b==l){
        return 1;
    }
    if(dp[b][l][k]!=-1){
        return dp[b][l][k];
    }

    int ans=-1;
    if(s[b]==s[l]){
        ans=fun(b+1,l-1,s,k)+2;
    }
    else if(s[b]!=s[l] and k!=0){
        char c1=s[l];
        char c2=s[b];
        c1=min(s[l],s[b]);
        c2=max(s[l],s[b]);
        int count=min(abs(c2-c1),abs(('z'-c2)+(c1-'a')+1));
        if(count<=k){
            //cout<<count<<" "<<b<<" "<<l<<endl;
            ans=fun(b+1,l-1,s,k-count)+2;
        }
    }
    return dp[b][l][k]= max({ans,fun(b+1,l,s,k),fun(b,l-1,s,k)});
}

    int longestPalindromicSubsequence(string s, int k) {
       int n=s.size();
        dp.resize(n,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
       return fun(0,n-1,s,k); 

    }
};