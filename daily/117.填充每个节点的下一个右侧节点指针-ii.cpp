/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
        if (!root) {
            return nullptr;
        }
        queue<Node*> q;
        q.push(root);
        while (q.size()) {
            int curS = q.size();
            Node* last = q.front();
            q.pop();
            if (last->left) {
                q.push(last->left);
            }
            if (last->right) {
                q.push(last->right);
            }
            for (int i = 2; i <= curS; i++) {
                Node* now = q.front();
                q.pop();
                if (now->left) {
                    q.push(now->left);
                }
                if (now->right) {
                    q.push(now->right);
                }
                last->next = now;
                last = now;
            }
            last->next = nullptr;
        }
        return root;
    }
};
// @lc code=end

