class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=2;i<nums.size();i++){
            if(nums[i-2]==0){
            ans++;
                nums[i-2]^=1;
                nums[i-1]^=1;
                nums[i]^=1;
            }
        }

       return  (nums[n-1]==0 || nums[n-2]==0)?-1:ans;
    }
};