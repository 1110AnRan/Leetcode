/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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

    void solve(TreeNode* root, int& ans, int& pre) {
        if(root == nullptr) {
            return;
        }
        solve(root->left, ans, pre);
        if(pre == -1) {
            pre = root->val;
        } else {
            ans = std::min(ans, root->val - pre);
            pre = root->val;
        }
        solve(root->right, ans, pre);
    }
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        solve(root, ans, pre);
        return ans;
    }
};
// @lc code=end

