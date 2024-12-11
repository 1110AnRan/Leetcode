/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int ans = 0, n = grid.size(), m = grid[0].size();
        vector vis(n, vector<bool>(m, false));
        vector<int> dx{-1, 0, 0, 1}, dy{0, 1, -1, 0};

        auto check = [&](int x, int y) -> bool {
            return x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == '1' and !vis[x][y];
        };

        auto bfs = [&](int x, int y) -> void {
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
                    int nx = u + dx[i];
                    int ny = v + dy[i];
                    if(check(nx, ny)) {
                        q.push({nx, ny});
                    }
                }
            }
        };

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' and !vis[i][j]) {
                    bfs(i, j);
                    ans++;
                }
            }
        }        
        return ans;
    }
};
// @lc code=end

