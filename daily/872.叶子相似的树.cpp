/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    void solve(vector<int>& v, TreeNode* root) {
        if(!root->left and !root->right) {
            v.push_back(root->val);
        } else {
            if(root->left) {
                solve(v, root->left);
            }
            if(root->right) {
                solve(v, root->right);
            }
        }
        
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        if(root1) {
            solve(v1, root1);
        }

        if(root2) {
            solve(v2, root2);
        }
        return v1 == v2;

    }
};
// @lc code=end

