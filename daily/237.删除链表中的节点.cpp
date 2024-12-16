/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* cur = node;
        ListNode* next = cur->next;
        while(next->next) {
            cur->val = next->val;
            cur = next;
            next = cur->next;
        }
        cur->val = next->val;
        cur->next = nullptr;
    }
};
// @lc code=end

