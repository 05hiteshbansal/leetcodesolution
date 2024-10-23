class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        map<char, int> mp; 
        int j = 0;          
        
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;

            while (mp[s[i]] >= k) {
                ans += (s.size() - i);  
                mp[s[j]]--;  
                j++;
            }
            cout<<ans<<endl;
        }
        
        return ans;
    }
};