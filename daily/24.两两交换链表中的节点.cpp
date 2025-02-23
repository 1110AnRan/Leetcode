/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr or head->next == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* tmp = dummy;
        while(tmp->next != nullptr and tmp->next->next != nullptr) {
            ListNode* n1 = tmp->next;
            ListNode* n2 = tmp->next->next;
            n1->next = n2->next;
            n2->next = n1;
            tmp->next = n2;
            tmp = n1;
        }
        ListNode* newhead = dummy->next;
        delete dummy;
        dummy = nullptr;
        return newhead;
        

    }
};
// @lc code=end

