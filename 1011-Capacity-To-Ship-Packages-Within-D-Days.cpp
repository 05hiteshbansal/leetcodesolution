class Solution {
public:
    bool fun(long long int mid, vector<int>& w, int d) {
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < w.size(); i++) {
            if (w[i] > mid) {
                return false;
            }
            if (sum + w[i] > mid) {
                ans++;
                sum = w[i];
            } else {
                sum += w[i];
            }
        }
        if (sum > mid) {
            ans += 1;
        }

        ans++;
        // sum = w[i];
        // cout<<ans<<endl;
        return ans <= d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        long long int left = 0;
        long long int right = 1e9 + 7;
        while (right - left >= 0) {
            long long int mid = left + (right - left) / 2;
            if (fun(mid, weights, days)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};