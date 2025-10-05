// this will give MLE
class Solution {
public:
    vector<pair<int, int>> ngb = {{0, -1}, {-1, 0}, {0, +1}, {+1, 0}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> ans;
                
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // apply bfs
                        vector<vector<int>> visited(n, vector<int>(m, 0));

                bool pacific = 0, atlantic = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    visited[r][c] = 1;
                    
                    q.pop();
                    // traverse neighbours
                    if(pacific == 1 && atlantic == 1){
                        break;
                    }
                    for (int k = 0; k < 4; k++) {
                        int ngb_row = r + ngb[k].first;
                        int ngb_col = c + ngb[k].second;
                        if (ngb_row < 0 || ngb_col < 0) {
                            pacific = 1;
                        }
                        if (ngb_row >= n || ngb_col >= m) {
                            atlantic = 1;
                        }

                        if (ngb_row >= 0 && ngb_row < n && ngb_col >= 0 &&
                            ngb_col < m && !visited[ngb_row][ngb_col] 
                            && (heights[ngb_row][ngb_col] <= heights[r][c])
                            )
                            // valid unvisited cell
                            {
                            visited[ngb_row][ngb_col] = 1;
                                q.push({ngb_row, ngb_col});
                        }
                    }
                }
                if(pacific && atlantic){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
