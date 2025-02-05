/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int csize = q.size();
            ans.push_back(q.front()->val);
            for(int i = 0; i < csize; i++) {
                auto u = q.front();
                q.pop();
                if(u->right) {
                    q.push(u->right);
                }
                if(u->left) {
                    q.push(u->left);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

