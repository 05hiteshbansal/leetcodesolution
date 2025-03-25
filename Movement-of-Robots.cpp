class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int MOD = 1000000007;
        int n=nums.size();
        vector<long long int>nums1(n);

        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                nums1[i]=(long long int )nums[i]-d;
            }
            else{
                nums1[i]=(long long int)nums[i]+d;
                
            }
        }

long long ans = 0;
        long long pref = 0;
        sort(nums1.begin(),nums1.end());
        for(long long i = 0; i < nums1.size(); i++){
            ans += i * (long long int) nums1[i] - pref;
            ans %= MOD;
            pref += nums1[i];
        }
return ans;

    }
};