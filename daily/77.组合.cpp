/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void dfs(int n, int k, int pre, int step, vector<int>& cur, vector<vector<int>>& ans) {
        if(step == k) {
            ans.push_back(cur);
            return;
        }

        for(int i = pre; i <= n; i++) {
            cur.push_back(i);
            dfs(n, k, i + 1, step + 1, cur, ans);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        vector<int> cur;
        dfs(n, k, 1, 0, cur, ans);
        return ans;
    }
};
// @lc code=end

