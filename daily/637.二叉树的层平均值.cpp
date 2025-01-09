/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int curs = q.size();
            long long sum = 0;
            for(int i = 0; i < curs; i++) {
                auto f = q.front();
                q.pop();
                if(f->left) {
                    q.push(f->left);
                }
                if(f->right) {
                    q.push(f->right);
                }
                sum += f->val;
            }
            ans.push_back(1.0 * sum / curs);
        }
        return ans;
    }
};
// @lc code=end

