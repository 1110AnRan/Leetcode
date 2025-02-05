/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        this->root = root;

        queue<TreeNode*> t;
        t.push(root);
        while(t.size()) {
            auto u = t.front();
            t.pop();
            if(u->left) {
                t.push(u->left);
            }
            if(u->right) {
                t.push(u->right);
            }

            if(u->left == nullptr or u->right == nullptr) {
                q.push(u);
            }
        }
    }
    
    int insert(int val) {
        auto u = q.front();
        int ret = u->val;
        TreeNode* child = new TreeNode(val);
        if(u->left == nullptr) {
            u->left = child;
        } else {
            u->right = child;
            q.pop();
        }
        q.push(child);
        return ret;
    }
    
    TreeNode* get_root() {
        return root;
    }
private:
    TreeNode* root;
    queue<TreeNode*> q;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

