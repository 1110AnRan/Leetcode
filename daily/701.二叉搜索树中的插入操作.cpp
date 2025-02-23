/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) {
            return new TreeNode(val);
        }
        TreeNode* retNode = root;
        TreeNode* parent = nullptr;
        int op = -1;
        while(root) {
            if(root->val > val) {
                op = 1;
                parent = root;
                root = root->left;
            } else {
                op = 2;
                parent = root;
                root = root->right;
            }
        }
        TreeNode* newNode = new TreeNode(val);
        if(op == 1) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
        return retNode;
    }
};
// @lc code=end

