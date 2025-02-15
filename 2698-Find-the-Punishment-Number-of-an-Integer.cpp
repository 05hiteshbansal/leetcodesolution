class Solution {
public:


bool fun(int no,int target){
    if(target<0 || no<target){
        return 0;
    }
    if(no==target){
        return 1;
    }
    return fun(no/10,target-no%10) || fun(no/100,target-no%100) || fun(no/1000,target-no%1000);
}

    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(fun(i*i,i)){
                ans+=i*i;
            }
        }

        return ans;
    }
};