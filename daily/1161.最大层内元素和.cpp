/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int curmax = -1e9, ans = 1, cnt = 1;
        while(q.size()) {
            int cursize = q.size();
            int sum = 0;
            for(int i = 0; i < cursize; i++) {
                TreeNode* t = q.front();
                q.pop();
                if(t->left) {
                    q.push(t->left);
                }
                if(t->right) {
                    q.push(t->right);
                }
                sum += t->val;
            }
            if(sum > curmax) {
                curmax = sum;
                ans = cnt;
            }
            cnt++;
        }
        return ans;

    }

};
// @lc code=end

