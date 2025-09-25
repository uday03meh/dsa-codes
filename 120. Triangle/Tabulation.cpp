class Solution {
public:
    vector<int> v;
    int n;
    vector<vector<int>> dp;
    int minimumTotal(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                }

                else {
                    int up;
                    if (i == j) {
                        up = 1e9;
                    } else {
                        up = dp[i - 1][j];
                    }
                    int upleft;
                    if (j == 0) {
                        upleft = 1e9;
                    } else {
                        upleft = dp[i - 1][j - 1];
                    }
                    dp[i][j] = min(up, upleft) + grid[i][j];
                }
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
