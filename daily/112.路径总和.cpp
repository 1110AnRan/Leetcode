/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start


class Solution {
public:
    bool dfs(TreeNode* cur, int t) {
        if(cur == nullptr) {
            return false;
        }
        if(cur->left == nullptr && cur->right == nullptr
        && cur->val == t) {
            return true;
        }
        
        return dfs(cur->left, t - cur->val) || dfs(cur->right, t - cur->val);


    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};
// @lc code=end

