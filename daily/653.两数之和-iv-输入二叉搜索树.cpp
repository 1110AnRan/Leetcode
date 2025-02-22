/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
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
    unordered_map<int, int> mp;

    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) {
            return false;
        }
        if(mp.count(k - root->val)) {
            return true;
        }
        mp[root->val] = 1;
        return findTarget(root->left, k) or findTarget(root->right, k);
    }
};
// @lc code=end

