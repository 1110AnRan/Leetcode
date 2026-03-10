/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    bool check(TreeNode* root, TreeNode* subRoot) {
        if ((!root && subRoot) || (root && !subRoot)) {
            return false;
        }
        if (!root && !subRoot) {
            return true;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool leftCheck, rightCheck;
        if (root->left) {
            leftCheck = isSubtree(root->left, subRoot);
        }
        if (root->right) {
            rightCheck = isSubtree(root->right, subRoot);
        }
        return check(root, subRoot) || leftCheck || rightCheck;
    }
};
// @lc code=end

