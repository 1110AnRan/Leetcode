/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] 链表最大孪生和
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
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = nullptr;
        while(fast and fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* nxt = slow->next;
        slow->next = nullptr;
        while(nxt) {
            ListNode* next = nxt->next;
            nxt->next = slow;
            slow = nxt;
            nxt = next;
        }
        int ans = 0;
        while(head) {
            ans = max(ans, head->val + slow->val);
            head = head->next;
            slow = slow->next;
        }
        return ans;
    }
};
// @lc code=end

