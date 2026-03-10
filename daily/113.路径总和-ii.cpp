/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void dfs(vector<vector<int>>& ans, vector<int>& cur, TreeNode* node, int sum, int targetSum) {
        if (!node) {
            return;
        }
        cur.push_back(node->val);
        dfs(ans, cur, node->left, sum + node->val, targetSum);
        dfs(ans, cur, node->right, sum + node->val, targetSum);
        if (node->left == nullptr && node->right == nullptr && node->val + sum == targetSum) {
            ans.push_back(cur);
        }
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, cur, root, 0, targetSum);
        return ans;
    }
};
// @lc code=end

