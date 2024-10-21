class Solution {
public:

int fun(int mid ,vector<int>& c ){
    int count=0;
    for(int i=0;i<c.size();i++){
        if(c[i]>=mid){
            count++;
        }
    }

    return count>=mid;

}

    int hIndex(vector<int>& c) {
        int left=0;
        int right=c.size();
        while(right-left>=0){
            int mid=left+(right-left)/2;
            if(fun(mid,c)){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return right;
    }
};