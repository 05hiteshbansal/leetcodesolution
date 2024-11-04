class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success){
sort(potions.begin(),potions.end());

vector<int>ans(spells.size(),-1);
int n=potions.size();
for(int i=0;i<spells.size();i++){
    long long int no=success/spells[i];
    int idx1=lower_bound(potions.begin(),potions.end(),no)-potions.begin();
    int idx2=upper_bound(potions.begin(),potions.end(),no)-potions.begin();
    if(idx1==n){
        ans[i]=0;
    }
    else{
        long long check=(long long)potions[idx1]*spells[i];
        if(check<success){
            ans[i]=n-idx2;
        }
        else{
            ans[i]=n-idx1;
        }
    }
}
return ans;
        
    }
};