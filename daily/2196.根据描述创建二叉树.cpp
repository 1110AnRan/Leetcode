/*
 * @lc app=leetcode.cn id=2196 lang=cpp
 *
 * [2196] 根据描述创建二叉树
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> mp1;
        for(int i = 0; i < descriptions.size(); i++) {
            int p = descriptions[i][0], c = descriptions[i][1], o = descriptions[i][2];
            if(!mp1.count(p)) {
                mp1[p] = true;
            }
            mp1[c] = false;

            if(!mp.count(p)) {
                mp[p] = new TreeNode(p);
            }
            if(!mp.count(c)) {
                mp[c] = new TreeNode(c);
            }
            if(o == 1) {
                mp[p]->left = mp[c];
            } else {
                mp[p]->right = mp[c];
            }
        }

        int root = -1;
        for(auto [x, y] : mp1) {
            if(y) {
                root = x;
                break;
            }
        }
        return mp[root];
    }

};
// @lc code=end

