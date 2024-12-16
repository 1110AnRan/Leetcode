/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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


    bool found = true;
    void dfs(TreeNode* root, long long left, long long right) {
        if(root == nullptr) {
            return;
        }

        if(root->val <= left || root->val >= right) {
            found = false;
            return;
        }

        dfs(root->left, left, root->val);
        dfs(root->right, root->val, right);
    }

    bool isValidBST(TreeNode* root) {
        dfs(root, LONG_MIN, LONG_MAX);
        return found;
    }
};
// @lc code=end

