class Solution {
public:
    vector<int> v;
    int n;
    vector<vector<int>> dp;
    int f(int i, int j, vector<vector<int>> &grid){
        if(i == 0 && j == 0){
            return grid[0][0];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int up;
        if(i == j){
            up = 1e9;
        }
        else up = f(i-1, j, grid);
        
        int upleft;
        if(j == 0){
            upleft = 1e9;
        }
        else {
           upleft  = f(i-1, j-1, grid);
    }
        return dp[i][j] = min(up, upleft) + grid[i][j];
    }

    int minimumTotal(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n, vector<int> (n, -1));
        // f(i, j) -> minmimum cost to reach point (i, j) from (0, 0)
        for(int i = 0; i < n; i++){
            v.push_back(f(n-1, i, grid));
        }
        return *min_element(v.begin(), v.end());
    }
};
