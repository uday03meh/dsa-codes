class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, vector<int> &v){
        if(j - i  <= 1){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }    
        int ans = INT_MAX;
        // o(n)
        for(int k = i+1; k < j; k++){
            // considering all points as our thid vertex of triangle
            ans = min(ans, v[i]*v[j]*v[k] + f(i, k, v) + f(k , j, v));
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& v) {
        dp.resize(51, vector<int> (51, -1));
        return f(0, v.size()-1, v);
    }
};
