class Solution {
public:
    int n;
    // vector<vector<int>> dp;
    int minimumTotal(vector<vector<int>>& grid) {
        n = grid.size();
        // dp.resize(n, vector<int>(n, -1));
        vector<int> prev(n, 0);

        for (int i = 0; i < n; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j <= i; j++) {
                if (i == 0 && j == 0) {
                    temp[0] = grid[i][j];
                }

                else {
                    int up;
                    if (i == j) {
                        up = 1e9;
                    } else {
                        up = prev[j];
                    }
                    int upleft;
                    if (j == 0) {
                        upleft = 1e9;
                    } else {
                        upleft = prev[j - 1];
                    }
                    temp[j] = min(up, upleft) + grid[i][j];
                }
            }
            prev = temp;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
