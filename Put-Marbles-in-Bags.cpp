class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(0);
        vector<int>ans(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i+1]==nums[i] and nums[i]!=0){
                ans[count]=nums[i]*2;
                i++;
                count++;
            }
            else if(nums[i]!=0){
                ans[count]=nums[i];
                count++;
            }
        }

        return ans;
    }
};