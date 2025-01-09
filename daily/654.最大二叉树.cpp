/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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

    TreeNode* build(int l, int r, const vector<int>& nums) {
        if(l > r) {
            return nullptr;
        }

        int idx = l;
        for(int i = l; i <= r; i++) {
            if(nums[i] > nums[idx]) {
                idx = i;
            }
        }
        TreeNode* node = new TreeNode(nums[idx]);
        node->left = build(l, idx - 1, nums);
        node->right = build(idx + 1, r, nums);
        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(0, nums.size() - 1, nums);
    }
};
// @lc code=end

