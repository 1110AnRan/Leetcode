/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
/*struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};*/
class Solution {
public:

    int dfs(TreeNode* root, int op) {
        if(root == nullptr) {
            return 0;
        }

        if(op == 0 and root->left == nullptr and root->right == nullptr) {
            return root->val;
        }
        return dfs(root->left, 0) + dfs(root->right, 1);

    }

    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, -1);
    }
};
// @lc code=end

