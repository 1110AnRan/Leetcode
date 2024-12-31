/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
        string s1, s2;
        while(l1) {
            s1 += (l1->val + '0');
            l1 = l1->next;
        }
        while(l2) {
            s2 += (l2->val + '0');
            l2 = l2->next;
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        string s3;
        int c = 0;
        for(int i = 0; i < min(s1.size(), s2.size()); i++) {
            int t = (s1[i] - '0') + (s2[i] - '0') + c;
            c = t / 10;
            t = t % 10;
            s3 += (t + '0');
        }
        cout << s3;
        for(int i = min(s1.size(), s2.size()); i < max(s1.size(), s2.size()); i++) {
            int t = (i < s1.size() ? (s1[i] - '0') : 0) + (i < s2.size() ? (s2[i] - '0') : 0) + c;
            c = t / 10;
            t = t % 10;
            s3 += (t + '0');
        }
        if(c) {
            s3 += (c + '0');
        }
        reverse(s3.begin(), s3.end());
        ListNode* newhead = nullptr;
        ListNode* tail = newhead;
        for(int i = 0; i < s3.size(); i++) {
            ListNode* newnode = new ListNode(s3[i] - '0');
            if(newhead == nullptr) {
                newhead = newnode;
                tail = newhead;
            } else {
                tail->next = newnode;
                tail = tail->next;
            }
        }
        return newhead;
    }
};
// @lc code=end

