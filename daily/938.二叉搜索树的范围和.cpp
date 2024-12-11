/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    int sum = 0;

    void dfs(TreeNode* root, int low, int high) {
        if(root == nullptr) {
            return;
        }

        if(root->val >= low and root->val <= high) {
            sum += root->val;
            dfs(root->left, low, high);
            dfs(root->right, low, high);
        } else if(root->val < low) {
            dfs(root->right, low, high);
        } else if(root->val > high) {
            dfs(root->left, low, high);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return sum;
    }
};
// @lc code=end

