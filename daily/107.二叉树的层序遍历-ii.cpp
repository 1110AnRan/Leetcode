/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr) {
            return vector<vector<int>>{};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(q.size()) {
            vector<int> v;
            int cursize = q.size();
            for(int i = 0; i < cursize; i++) {
                auto n = q.front();
                q.pop();
                if(n->left != nullptr) {
                    q.push(n->left);
                }
                if(n->right != nullptr) {
                    q.push(n->right);
                }
                v.push_back(n->val);
            }
            ans.push_back(v);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

