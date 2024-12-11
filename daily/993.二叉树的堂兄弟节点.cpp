/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
class Solution {
public:
    unordered_map<int, int> mp, mp1;

    void dfs(TreeNode* root, int dep, TreeNode* f) {
        if(root == nullptr) {
            return;
        }

        mp[root->val] = dep;
        if(f != nullptr) {
            mp1[root->val] = f->val;
        }
        dfs(root->left, dep + 1, root);
        dfs(root->right, dep + 1, root);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, 0, nullptr);
        if(mp[x] == mp[y] and mp1[x] != mp1[y]) {
            return true;
        }
        return false;
    }
};
// @lc code=end

