class Solution {
public:
    int final(int i, int j, int idx, vector<pair<int, int>> &f ,  vector<vector<vector<int>>>&dp) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (idx >= f.size()) {
            return 0;
        }
        if(dp[i][j][idx]!=-1){
            return dp[i][j][idx];
        }
        int include1=0;
        int include2=0;
        int notinclude=0;
        if(i-f[idx].first>=0 and j-f[idx].second>=0){
             include1= final(i-f[idx].first,j-f[idx].second, idx + 1, f,dp)+1;
             include2 = final(i, j, idx + 1, f,dp);
        }
        else{
        notinclude = final(i, j, idx + 1, f,dp);
        }
        return dp[i][j][idx]=  max({include1,include2,notinclude});
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(strs.size()+1,-1)));
        vector<pair<int, int>> f;
        for (int i = 0; i < strs.size(); i++) {
            int one = 0;
            int zero = 0;
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0') {
                    zero++;
                } else {
                    one++;
                }
            }
            f.push_back({one, zero});
        }
        return final(n, m, 0, f,dp);
    }
};