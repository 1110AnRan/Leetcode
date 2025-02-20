/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:

    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& t, vector<bool>& vis) {
        if(t.size() == nums.size()) {
            ans.push_back(t);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!vis[i]) {
                vis[i] = true;
                t.push_back(nums[i]);
                dfs(ans, nums, t, vis);
                t.pop_back();
                vis[i] = false;
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        vector<bool> vis(nums.size());
        dfs(ans, nums, t, vis);
        return ans;
    }
};
// @lc code=end

