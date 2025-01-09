/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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
    vector<int> preorder(Node* root) {
        vector<int> ans;

        auto dfs = [&](auto &&self, Node* r) {
            if(r == nullptr) {
                return;
            }
            ans.push_back(r->val);
            for(auto v : r->children) {
                self(self, v);
            }
        };

        dfs(dfs, root);
        return ans;
    }
};
// @lc code=end

