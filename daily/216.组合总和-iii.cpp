/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:

    void dfs(vector<vector<int>>& ans, vector<int>& cur, int num, int cnt, int k, int n) {
        if(cnt == k) {
            if(std::accumulate(cur.begin(), cur.end(), 0) == n) {
                ans.push_back(cur);
            }
            return;
        }

        for(int i = num; i <= 9; i++) {
            cur.push_back(i);
            dfs(ans, cur, i + 1, cnt + 1, k, n);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, cur, 1, 0, k, n);
        return ans;
    }
};
// @lc code=end

