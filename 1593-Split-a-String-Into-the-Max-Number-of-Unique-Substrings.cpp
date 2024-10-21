class Solution {
public:
int fun(int i, string s , set<string>&st ){
    if(i==s.size()){
         return 0;
    }
    int ans=0;
    for(int j=i+1;j<=s.size();j++){
        string temp=s.substr(i,j-i);
        if(st.find(temp)==st.end()){
            st.insert(temp);
            ans=max(ans,fun(j,s,st)+1);
            st.erase(temp);
        }
    }


    return ans;
}

    int maxUniqueSplit(string s) {
        set<string>st;
        return fun(0,s,st);
        //return ans;
    }
};