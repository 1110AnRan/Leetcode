/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode* root) {
        queue< pair<TreeNode*, unsigned long long> > q;
        q.push({root, 1});
        unsigned long long ans = 0;
        while (q.size()) {
            int curSize = q.size();
            unsigned long long m = numeric_limits<unsigned long long>::min(), n = numeric_limits<unsigned long long>::max();
            for (int i = 0; i < curSize; i++) {
                pair<TreeNode*, unsigned long long> p = q.front();
                q.pop();
                m = max(m, p.second);
                n = min(n, p.second);
                if (p.first->left) {
                    q.push({p.first->left, p.second * 2});
                }
                if (p.first->right) {
                    q.push({p.first->right, p.second * 2 + 1});
                }
            }
            ans = max(ans, m - n + 1);
        }
        return ans;
    }
};
// @lc code=end

