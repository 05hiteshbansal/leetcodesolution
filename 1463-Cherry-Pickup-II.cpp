class Solution {
public:
    int fun(int row, int c1, int c2, vector<vector<int>>& arr,
            vector<vector<vector<int>>>&dp) {
        if (row >= arr.size()) {
            return 0;
        }
        if (dp[row][c1][c2] != -1) {
            return dp[row][c1][c2];
        }
        int sum = arr[row][c1];
        if (c1 != c2) {
            sum += arr[row][c2];
        }

        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int y1 = c1 + i;
                int y2 = c2 + j;
                if (y1 >= 0 and y2 >= 0 and y2 < arr[0].size() and
                    y1 < arr[0].size()) {
                    ans = max(ans, fun(row + 1, y1, y2, arr, dp));
                }
            }
        }
        return dp[row][c1][c2] = ans + sum;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));
        return fun(0, 0, m - 1, grid, dp);
    }
};