/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) {
            return nullptr;
        }
        int cnt = 0;
        ListNode* cur = head;
        ListNode* tail = nullptr;
        while(cur != nullptr) {
            cnt++;
            tail = cur;
            cur = cur->next;
        }
        k %= cnt;
        if(k == 0) {
            return head;
        }
        cnt = cnt - k;
        ListNode* newhead = head;
        ListNode* pre = nullptr;
        while(cnt--) {
            pre = newhead;
            newhead = newhead->next;
        }
        pre->next = nullptr;
        tail->next = head;
        return newhead;
    }
};
// @lc code=end

