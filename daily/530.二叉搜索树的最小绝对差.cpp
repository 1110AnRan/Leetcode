/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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

    void Inorder(TreeNode* root, vector<int>& v) {
        if(root == nullptr) {
            return;
        }

        Inorder(root->left, v);
        v.push_back(root->val);
        Inorder(root->right, v);


    
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        Inorder(root, v);
        int ans = 1e9;
        for(int i = 0; i < v.size() - 1; i++) {
            ans = min(ans, abs(v[i] - v[i + 1]));
        }
        return ans;
    }
};
// @lc code=end

