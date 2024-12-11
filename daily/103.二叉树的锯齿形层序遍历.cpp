/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) {
            return vector<vector<int>>{};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int cursize = q.size();
            vector<int> v;
            for(int i = 0; i < cursize; i++) {
                auto u = q.front();
                if(u->left != nullptr) {
                    q.push(u->left);
                }
                if(u->right != nullptr) {
                    q.push(u->right);
                }
                q.pop();
                v.push_back(u->val);
            }
            ans.push_back(v);
        }
        for(int i = 1; i < ans.size(); i += 2) {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
// @lc code=end

