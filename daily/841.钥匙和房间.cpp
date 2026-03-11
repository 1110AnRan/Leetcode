/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        int cnt = 0;
        auto dfs = [&](auto&& self, int cur, int step) -> void {
            cnt++;
            vis[cur] = true;
            for (auto x : rooms[cur]) {
                if (!vis[x]) {
                    self(self, x, step + 1);
                }
            }
        };
        dfs(dfs, 0, 1);
        return cnt == n;
    }
};
// @lc code=end

