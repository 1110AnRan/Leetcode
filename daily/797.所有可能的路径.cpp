/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int end = graph.size() - 1;

        vector<int> v;
        auto dfs = [&](auto &&self, int u) -> void {
            if(u == end) {
                v.push_back(u);
                ans.push_back(v);
                v.pop_back();
                return;
            }
            v.push_back(u);
            for(auto v : graph[u]) {
                self(self, v);
            }
            v.pop_back();
        };

        dfs(dfs, 0);
        return ans;
    }
};
// @lc code=end

