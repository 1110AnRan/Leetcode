/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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

    int dfs(TreeNode* root, int mx) {
        if(!root) {
            return 0;
        }
        int ans = 0;
        if(root->val >= mx) {
            ans++;
        }
        return ans + dfs(root->left, max(mx, root->val)) + dfs(root->right, max(mx, root->val));
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, -10001);
    }
};
// @lc code=end

