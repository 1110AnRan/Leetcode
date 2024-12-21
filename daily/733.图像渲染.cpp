/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        int n = image.size(), m = image[0].size();

        vector<int> dx{-1, 0, 0, 1}, dy{0, -1, 1, 0};
        auto dfs = [&](auto &&self, int x, int y) -> void {
            if(image[x][y] == color) {
                return;
            }

            image[x][y] = color;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 and nx < n and ny >=0 and ny < m and image[nx][ny] == start) {
                    self(self, nx, ny);
                }
            }

        };

        dfs(dfs, sr, sc);
        return image;
    }
};
// @lc code=end

