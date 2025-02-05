/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    const int inf = 100 * 100;
    const vector<pair<int, int>> d{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> path(n, vector<int>(m, inf));

        auto bfs = [&] (int x, int y) -> void {
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            queue<pair<int, int>> q;
            q.push({x, y});
            while(q.size()) {
                auto [u, v] = q.front();
                q.pop();
                if(vis[u][v]) {
                    continue;
                }
                vis[u][v] = true;
                for(int i = 0; i < 4; i++) {
                    int nx = u + d[i].first;
                    int ny = v + d[i].second;
                    if(nx >= 0 and nx < n and ny >= 0 and ny < m and grid[nx][ny] == 1) {
                        path[nx][ny] = min(path[nx][ny], path[u][v] + 1);
                        q.push({nx, ny});
                    }
                }
            }
        };

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    path[i][j] = 0;
                }
                if(grid[i][j] == 2) {
                    path[i][j] = 0;
                    bfs(i, j);
                }
            }
        }

        int ans = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 and path[i][j] == inf) {
                    return -1;
                }
                ans = max(ans, path[i][j]);
            }
        }
        return ans;

    }
};
// @lc code=end

