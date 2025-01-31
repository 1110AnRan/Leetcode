/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* nxt = head->next;
        ListNode* newhead = nullptr;
        ListNode* tail = nullptr;
        int sum = 0;
        while(nxt != nullptr) {
            while(nxt->val != 0) {
                sum += nxt->val;
                nxt = nxt->next;
            }
            if(newhead == nullptr) {
                newhead = new ListNode(sum);
                tail = newhead;
            } else {
                ListNode* newnode = new ListNode(sum);
                tail->next = newnode;
                tail = tail->next;
            }
            sum = 0;
            nxt = nxt->next;
        }
        return newhead;
    }
};
// @lc code=end

