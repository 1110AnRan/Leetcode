/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
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

    int ans = 0;
    void dfs(TreeNode* gr, TreeNode* p, TreeNode* c) {
        if(c == nullptr) {
            return;
        }
        if(gr->val % 2 == 0) {
            ans += c->val;
        }
        dfs(p, c, c->left);
        dfs(p, c, c->right);
    }

    int sumEvenGrandparent(TreeNode* root) {
        if(root->left) {
            dfs(root, root->left, root->left->left);
            dfs(root, root->left, root->left->right);
        }
        if(root->right) {
            dfs(root, root->right, root->right->left);
            dfs(root, root->right, root->right->right);
        }
        return ans;
    }
};
// @lc code=end

