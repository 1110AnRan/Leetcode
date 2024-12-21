/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<int> dx{-1, 0, 0, 1}, dy{0, -1, 1, 0};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int cnt = 0;
                    for(int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 0) {
                            cnt++;
                        }
                    }
                    ans += cnt;
                }
            }
        }
        return ans;
        
    }
};
// @lc code=end

