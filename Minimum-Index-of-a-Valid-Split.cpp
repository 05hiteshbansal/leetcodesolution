class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
        }

        for(int i=0;i<n;i++){
            m1[nums[i]]--;
            m2[nums[i]]++;

            int f1=m1[nums[i]];
            int f2=m2[nums[i]];
            int l1=(i+1);
            int l2=(n-i-1);

            if(f2*2>l1 and f1*2>l2){
                return i;
            }
            
        }

        return -1;
    }
};