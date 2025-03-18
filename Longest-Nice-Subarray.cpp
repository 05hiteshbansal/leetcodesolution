class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=0;
        int temp=0;
        int sub=0;
        while(i<n){
            while((nums[i]&temp)!=0){
                temp^=nums[j];
                j++;
                sub--;
                //cout<<nums[j]<<" ";
            }
                temp|=nums[i];
                i++;
                sub++;
                ans=max(ans,sub);
        }

        return ans;

    }
};