class Solution {
public:

vector<int> fun(vector<int>& l){
    vector<int>ans;
    vector<int>f(l.size(),0);
    for(int i=0;i<l.size();i++){
        int idx=lower_bound(ans.begin(),ans.end(),l[i])-ans.begin();

        if(idx==ans.size()){
            ans.push_back(l[i]);
        }
        else{
            ans[idx]=l[i];
        }

        f[i]=ans.size();
    }
return f;
}


    int minimumMountainRemovals(vector<int>& nums) {
        int idx=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[idx]<nums[i]){
                idx=i;
            }
        }
        // for(int i=0;i<=idx;i++){
        //     l.push_back(nums[i]);
        // }
        // for(int i=n-1;i>=idx;i--){
        //     r.push_back(nums[i]);
        // }


vector<int>l=fun(nums);
reverse(nums.begin(),nums.end());
vector<int>r=fun(nums);
        

for(int i=0;i<l.size();i++){
    cout<<l[i]<<" ";
}

cout<<endl;

reverse(r.begin(),r.end());

for(int i=0;i<r.size();i++){
    cout<<r[i]<<" ";
}

int minRemovals = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (l[i] > 1 && r[i] > 1) {
                minRemovals =
                    min(minRemovals, n - l[i] - r[i] + 1);
            }
        }

        return minRemovals;

    
    }
};