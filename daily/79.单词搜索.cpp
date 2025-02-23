/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        const vector<int> dx{-1, 0, 0, 1}, dy{0, -1, 1, 0};
        bool found = false;
        auto dfs = [&](auto &&self, int x, int y, int cur) -> void {
            if(cur == word.size() - 1 || found) {
                found = true;
                return;
            }
            

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 and nx < n and ny >= 0 and ny < m and board[nx][ny] == word[cur + 1] and !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    self(self, nx, ny, cur + 1);
                    vis[nx][ny] = false;
                }
            }

        };

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    vis[i][j] = true;
                    dfs(dfs, i, j, 0);
                    if(found) {
                        return found;
                    }
                    vis[i][j] = false;
                }
            }
        }

        return false;
    }
};
// @lc code=end

