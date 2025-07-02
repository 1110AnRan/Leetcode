/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void f(Node* root, int& ans, int depth) {
        if(!root) {
            return;
        }

        ans = max(ans, depth);
        for(auto v : root->children) {
            f(v, ans, depth + 1);
        }

    }

    int maxDepth(Node* root) {
        int ans = 0;
        f(root, ans, 1);
        return ans;
    }
};
// @lc code=end

