/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    map<int, TreeNode*> fa;
    map<int, bool> vis;
    void dfs(TreeNode* root)
    {
        if(root->left != NULL)
        {
            fa[root->left->val] = root;
            dfs(root->left);
        }
        if(root->right != NULL)
        {
            fa[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);
        while(p != NULL)
        {
            vis[p->val] = true;
            p = fa[p->val];
        } 
        while(q != NULL)
        {
            if(vis[q->val]) return q;
            q = fa[q->val];
        }
        return NULL;
    }
};
// @lc code=end

