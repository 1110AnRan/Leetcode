/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 *
 * [1382] 将二叉搜索树变平衡
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

    vector<int> sor;

    void inorder(TreeNode* root) {
        if(!root) {
            return;
        }
        inorder(root->left);
        sor.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* build(int l, int r) {
        if(l == r) {
            TreeNode* cur = new TreeNode(sor[l]);
            return cur;
        }

        if(l > r) {
            return nullptr;
        }

        int mid = (l + r) >> 1;
        TreeNode* root = new TreeNode(sor[mid]);
        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);
        return root;

    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, sor.size() - 1);
    }
};
// @lc code=end

