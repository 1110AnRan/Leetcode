/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        while(true) {
            if(p->val < ans->val and q->val < ans->val) {
                ans = ans->left;
            } else if(p->val > ans->val and q->val > ans->val) {
                ans = ans->right;
            } else {
                break;
            }
        }
        return ans;
    }
private:
};
// @lc code=end

