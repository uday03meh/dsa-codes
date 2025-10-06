#define pii pair<int, pair<int, int>>
class Solution {
public:
        vector<pair<int, int>> ngb = {{0, -1}, {-1, 0}, {0, +1}, {+1, 0}};

    int swimInWater(vector<vector<int>>& grid) {

        
        int n = grid.size();
        int m = grid[0].size();
        // O (n*m) SC
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // {height, {x, y}}
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        // min heap
        int t = 0; // time
        
        pq.push({grid[0][0], {0, 0} });
        visited[0][0] = true;
        while (!pq.empty()) {
            int height = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second; 
            pq.pop();
            t = max(t, height);
            if(x == n-1 && y == m-1){
                return t;
            }
            for (int k = 0; k < 4; k++) {
                int nr = x + ngb[k].first;
                int nc = y + ngb[k].second;
                
                // valid cell
                // unvisited
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({grid[nr][nc], {nr, nc}});
                }
            }
        }
    return t;
    }
};
