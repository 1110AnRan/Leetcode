/*
 * @lc app=leetcode.cn id=2265 lang=cpp
 *
 * [2265] 统计值等于子树平均值的节点数
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
    pair<int, int> solve(TreeNode* root) {
        if(root == nullptr) {
            return {0, 0};
        }
        auto ls = solve(root->left);
        auto rs = solve(root->right);
        if((ls.first + rs.first + root->val) / (ls.second + rs.second + 1) == root->val) {
            ans++;
        }
        return {ls.first + rs.first + root->val, ls.second + rs.second + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
// @lc code=end

