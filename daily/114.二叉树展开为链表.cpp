/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur != nullptr) {
            if(cur->left != nullptr) {
                TreeNode* cl = cur->left;
                TreeNode* cr = cl;
                while(cr->right) {
                    cr = cr->right;
                }
                cr->right = cur->right;
                cur->left = nullptr;
                cur->right = cl;
            }
            cur = cur->right;
        }
    }
};
// @lc code=end

