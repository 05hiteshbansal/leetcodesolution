class Solution {
public:

int fun(vector<int>& n, int k){
    if(k<0){
        return 0;
    }
     int oddcount=0;
        int i=0;
        int ans=0;
        for(int j=0;j<n.size();j++){
            if(n[j]%2==1){
                oddcount++;
            }
            while(oddcount>k){
                if(n[i]%2==1){
                    oddcount--;
                }
                i++;
            }
            ans+=j-i+1;
        }

        return ans;
}

    int numberOfSubarrays(vector<int>& n, int k) {
        return fun(n,k)-fun(n,k-1);
    }
};