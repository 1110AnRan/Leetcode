/*
 * @lc app=leetcode.cn id=1361 lang=cpp
 *
 * [1361] 验证二叉树
 */

// @lc code=start
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> d(n);
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                ++d[leftChild[i]];
            }
            if(rightChild[i] != -1) {
                ++d[rightChild[i]];
            }
        }
        int root = -1;
        for(int i = 0; i < n; i++) {
            if(d[i] == 0) {
                root = i;
                break;
            }
        }
        if(root == -1) {
            return false;
        }

        multiset<int> st;
        queue<int> q;
        q.push(root);
        st.insert(root);
        while(q.size()) {
            int u = q.front();
            q.pop();
            if(leftChild[u] != -1) {
                if(st.count(leftChild[u])) {
                    return false;
                }
                q.push(leftChild[u]);
                st.insert(leftChild[u]);
            }
            if(rightChild[u] != -1) {
                if(st.count(rightChild[u])) {
                    return false;
                }
                q.push(rightChild[u]);
                st.insert(rightChild[u]);
            }
        }
        return st.size() == n;
    }
};
// @lc code=end

