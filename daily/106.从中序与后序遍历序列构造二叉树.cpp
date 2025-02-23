/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
private:
    unordered_map<int, int> mp;
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
        if(pl > pr) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[pr]);
        int mid = mp[postorder[pr]];
        root->left = build(inorder, postorder, il, mid - 1, pl, pl + mid - il - 1);
        root->right = build(inorder, postorder, mid + 1, ir, pl + mid - il, pr - 1);
        return root;


    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int pi = inorder.size(), pp = postorder.size();
        return build(inorder, postorder, 0, pi - 1, 0, pp - 1);
    }
};
// @lc code=end

