class Solution {
public:

int dp[302][302];
int fun(int left,int right,vector<int>& nums){

    if(right-left==1){
        return 0;
    }

    if(dp[left][right]!=-1){
        return dp[left][right];
    }
    int ans=INT_MIN;
    for(int i=left+1;i<right;i++){
        ans=max(ans,nums[i]*nums[left]*nums[right] + fun(left,i,nums)+fun(i,right,nums));
    }

    return dp[left][right] =ans;
}


    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int left=0;
        int right=nums.size()-1;
        for (int i = 0; i < 302; i++) {
        memset(dp[i], -1, sizeof(dp[i])); 
    }
        return fun(left,right,nums);

    }
};