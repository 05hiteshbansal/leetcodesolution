class Solution {
public:
    static bool comp(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] >= b[1];
        }
        return a[0] < b[0];
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<vector<int>> mp;
        multiset<int , greater<int>> ms;

        for (int i = 0; i < b.size(); i++) {
            int x1 = b[i][0];
            int x2 = b[i][1];
            int h = b[i][2];

            mp.push_back({x1, h});
            mp.push_back({x2, -h});
        }

        vector<vector<int>> ans;
        sort(mp.begin(), mp.end(),comp);

        int maxi = 0;

        for (int i = 0; i < mp.size(); i++) {
            cout << mp[i][1] << \ \;
        }
        cout << endl;


ms.insert({0,0});

        int idx=0;
        for (int i = 0; i < mp.size(); i++) {
            ms.insert(mp[i][1]);
            auto y = ms.begin();
            int temp = *y;
            if(mp[i][1]<0){
                int n=-mp[i][1];
                auto t = ms.find(n);
                ms.erase(t);
                temp=*(ms.begin());
            }

            //cout<<temp<<\ \;
            if(idx!=temp){
                ans.push_back({mp[i][0],temp});
                idx=temp;
            }
        }
        return ans;
    }
};