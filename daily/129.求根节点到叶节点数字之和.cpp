/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sum = 0;
    void solve(TreeNode* root, int val) {
        if(!root->left and !root->right) {
            sum += val;
            return;
        }
        if(root->left) {
            solve(root->left, val * 10 + root->left->val);
        }
        if(root->right) {
            solve(root->right, val * 10 + root->right->val);
        }
    }

    int sumNumbers(TreeNode* root) {
        solve(root, root->val);
        return sum;
    }
};
// @lc code=end

