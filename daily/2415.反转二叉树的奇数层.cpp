/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int cur = 0;
        while(q.size()) {
            vector<TreeNode*> a;
            int c = q.size();
            for(int i = 0; i < c; i++) {
                auto t = q.front();
                q.pop();
                if(t->left) {
                    q.push(t->left);
                }
                if(t->right) {
                    q.push(t->right);
                }
                if(cur & 1) {
                    a.push_back(t);
                }
            }
            for(int i = 0; i < a.size() / 2; i++) {
                swap(a[i]->val, a[a.size() - i - 1]->val);
            }
            cur++;
        }
        return root;
    }
};
// @lc code=end

