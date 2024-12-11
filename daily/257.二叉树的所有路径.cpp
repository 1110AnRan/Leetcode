/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include<bits/stdc++.h>
using namespace std;
class TreeNode;
class Solution {
public:

    void dfs(TreeNode* root, vector<string>& v, string s) {
        if(root->left == nullptr && root->right == nullptr) {
            s += to_string(root->val);
            v.push_back(s);
            return;
        }

        s += to_string(root->val) + "->";
        if(root->left) {
            dfs(root->left, v, s);
        }
        if(root->right) {
            dfs(root->right, v, s);
        }
        
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        dfs(root, v, "");
        return v;
    }
};
// @lc code=end

