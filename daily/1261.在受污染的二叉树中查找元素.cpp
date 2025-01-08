/*
 * @lc app=leetcode.cn id=1261 lang=cpp
 *
 * [1261] 在受污染的二叉树中查找元素
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
class FindElements {
public:
    unordered_map<int, int> mp;
    FindElements(TreeNode* root) {
        root->val = 0;
        mp[0] = 1;
        solve(root);
    }
    
    void solve(TreeNode* root) {
        if(root->left) {
            root->left->val = root->val * 2 + 1;
            mp[root->val * 2 + 1] = 1;
            solve(root->left);
        }
        if(root->right) {
            root->right->val = root->val * 2 + 2;
            mp[root->val * 2 + 2] = 1;
            solve(root->right);
        }
    }

    bool find(int target) {
        if(mp.count(target)) {
            return true;
        }
        return false;
    }
};
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

