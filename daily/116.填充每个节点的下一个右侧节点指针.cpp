/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) {
            return root;
        }

        queue<Node*> q;
        q.push(root);

        while(q.size()) {
            int siz = q.size();
            for(int i = 0; i < siz; i++) {
                auto u = q.front();
                q.pop();
                if(i == siz - 1) {
                    u->next = nullptr;
                } else {
                    u->next = q.front();
                }
                if(u->left) {
                    q.push(u->left);
                }
                if(u->right) {
                    q.push(u->right);
                }
                
            }
        }
        return root;
    }
};
// @lc code=end

