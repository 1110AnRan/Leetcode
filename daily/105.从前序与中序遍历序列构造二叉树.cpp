/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
        unordered_map<int, int> mp;
        TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
            if(il > ir) {
                return nullptr;
            }
    
            TreeNode* root = new TreeNode(preorder[pl]);
            int mid = mp[preorder[pl]];
            root->left = build(preorder, inorder, pl + 1, pl + mid - il, il, mid - 1);
            root->right= build(preorder, inorder, pl + mid - il + 1, pr, mid + 1, ir);
            return root;
        }
    
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            
            for(int i = 0; i < inorder.size(); i++) {
                mp[inorder[i]] = i;
            }
            int pn = preorder.size(), pm = inorder.size();
            return build(preorder, inorder, 0, pn - 1, 0, pm - 1);
        }
    };
// @lc code=end

