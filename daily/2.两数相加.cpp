/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* cur = head;
        int c = 0;
        while(l1 && l2) {
            int t = l1->val + l2->val + c;
            ListNode* newnode = new ListNode(t % 10);
            if(head == nullptr) {
                head = newnode;
            } else {
                cur->next = newnode;
            }
            cur = newnode;
            c = t / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1) {
            while(l1) {
                int t = l1->val + c;
                ListNode* newnode = new ListNode(t % 10);
                cur->next = newnode;
                cur = newnode;
                c = t / 10;
                l1 = l1->next;
            }
        } else {
            while(l2) {
                int t = l2->val + c;
                ListNode* newnode = new ListNode(t % 10);
                cur->next = newnode;
                cur = newnode;
                c = t / 10;
                l2 = l2->next;
            }
        }
        if(c) {
            ListNode* newnode = new ListNode(c);
            cur->next = newnode;
            cur = newnode;
        }
        return head;
    }
};
// @lc code=end

