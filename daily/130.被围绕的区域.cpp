/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};

        auto valid = [&](int x, int y) -> bool {
            return x >= 0 and x < n and y >= 0 and y < m
                and board[x][y] == 'O' and !vis[x][y];
        };

        auto bfs = [&](int x, int y) -> void {
            queue<pair<int,int>> q;
            q.push({x, y});
            while(q.size()) {
                auto [nx, ny] = q.front();
                q.pop();
                if(vis[nx][ny]) {
                    continue;
                }
                vis[nx][ny] = true;
                for(int i = 0; i < 4; i++) {
                    int tx = nx + dx[i];
                    int ty = ny + dy[i];
                    if(valid(tx, ty)) {
                        q.push({tx, ty});
                    }
                }
            }
        };

        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O' and !vis[0][i]) {
                bfs(0, i);
            }
        }

        for(int i = 1; i < n; i++) {
            if(board[i][m - 1] == 'O' and !vis[i][m - 1]) {
                bfs(i, m - 1);
            }
        }

        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O' and !vis[i][0]) {
                bfs(i, 0);
            }
        }

        for(int i = 1; i < m; i++) {
            if(board[n - 1][i] == 'O' and !vis[n - 1][i]) {
                bfs(n - 1, i);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j]) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }

    }
};
// @lc code=end

