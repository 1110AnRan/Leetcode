/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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

    int ans = -1000;

    int dfs(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int leftans = max(dfs(root->left), 0);
        int rightans = max(dfs(root->right), 0);

        int cur = root->val + leftans + rightans;

        ans = max(ans, cur);

        return root->val + max(leftans, rightans);
    }

    int maxPathSum(TreeNode* root) {
        return max(dfs(root), ans);
    }
};
// @lc code=end

