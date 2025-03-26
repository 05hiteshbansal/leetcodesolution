class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]-i]++;
        }
    
    long long int ans=0;
    for(auto i : mp){
        int o=i.second;
        ans+=(long long )o*(o-1)/2;
    }

    return (long long )((n*(n-1)/2)-ans);
    }
};