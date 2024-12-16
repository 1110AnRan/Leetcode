/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        if(head == nullptr) {
            return;
        }
        if(head->next == nullptr) {
            return;
        }
        ListNode* fast = head, * slow = head;
        ListNode* pre = head;
        while(fast and fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = nullptr;
        pre = nullptr;
        ListNode* sn = slow->next;
        while(sn) {
            slow->next = pre;
            pre = slow;
            slow = sn;
            sn = slow->next;
        }
        slow->next = pre;
        int f = 0;
        ListNode* p = head, *r = slow;
        ListNode* pnext = p->next, *rnext = r->next;
        while(p and r) {
            if(f == 0) {
                p->next = r;
                p = pnext;
                if(p) {
                    pnext = p->next;
                }
                
                f = 1;
            } else {
                r->next = p;
                r = rnext;
                if(r) {
                    rnext = r->next;
                }
                f = 0;
            }
        }
    }
};
// @lc code=end

