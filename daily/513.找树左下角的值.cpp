/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
private:
    int ans = -1, deepth = -1;
public:
    void dfs1(TreeNode* c, int curDeepth) {
        while(c->left) {
            c = c->left;
            curDeepth++;
        }
        if(curDeepth > deepth) {
            ans = c->val;
            deepth = curDeepth;
        }
    }

    void dfs2(TreeNode* root, int cur) {
        if(!root) {
            return;
        }
        dfs1(root, cur);
        dfs2(root->left, cur + 1);
        dfs2(root->right, cur + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs2(root, 0);
        return ans;
    }
};
// @lc code=end

