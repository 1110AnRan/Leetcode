/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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
    vector<vector<string>> ret;
    int n, m;
    int getheight(TreeNode* root) {
        int h = 0;
        if(root->left) {
            h = max(h, getheight(root->left) + 1);
        }
        if(root->right) {
            h = max(h, getheight(root->right) + 1);
        }
        return h;
    }

    void getans(TreeNode* root, int r, int c) {
        ret[r][c] = to_string(root->val);
        if(root->left) {
            getans(root->left, r + 1, c - (1 << (n - r - 2)));
        }
        if(root->right) {
            getans(root->right, r + 1, c + (1 << (n - r - 2)));
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        n = getheight(root) + 1;
        m = (1 << (n)) - 1;
        ret.assign(n, vector<string>(m));
        getans(root, 0, (m - 1) / 2);
        return ret;
    }
};
// @lc code=end

