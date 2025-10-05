class Solution {
public:
    vector<pair<int, int>> ngb = {{0, -1}, {-1, 0}, {0, +1}, {+1, 0}};
    
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, 
             queue<pair<int, int>>& q) {
        int n = heights.size();
        int m = heights[0].size();
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int nr = r + ngb[k].first;
                int nc = c + ngb[k].second;
                
                // Check bounds, not visited, and can flow TO current cell
                // (i.e., neighbor height >= current height, going uphill)
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                    !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        queue<pair<int, int>> pq, aq;
        
        // Add Pacific borders (top row and left column)
        for (int i = 0; i < n; i++) {
            pacific[i][0] = true;
            pq.push({i, 0});
        }
        for (int j = 0; j < m; j++) {
            pacific[0][j] = true;
            pq.push({0, j});
        }
        
        // Add Atlantic borders (bottom row and right column)
        for (int i = 0; i < n; i++) {
            atlantic[i][m-1] = true;
            aq.push({i, m-1});
        }
        for (int j = 0; j < m; j++) {
            atlantic[n-1][j] = true;
            aq.push({n-1, j});
        }
        
        // BFS from both oceans
        bfs(heights, pacific, pq);
        bfs(heights, atlantic, aq);
        
        // Find intersection
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};
