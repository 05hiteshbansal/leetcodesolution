class Solution {
public:
    //int ans = 0;
    int fun(int i, string &s , vector<int> &dp) {
        if (i >= s.size()) {
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans = 0;
        if (i != s.size() - 1) {
            string temp = \\;
            temp = s.substr(i, 2);
            if (temp <= \26\ and temp != \00\ and temp[0] != '0') {
                cout << temp;
                ans += fun(i + 2, s,dp);
            }
        }
        if (s[i] != '0') {
            ans += fun(i + 1, s,dp);
        }

        return dp[i]= ans;
    }

    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return fun(0, s,dp);
        //return ans;
    }
};