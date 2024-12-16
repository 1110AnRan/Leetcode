/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if(head == nullptr) {
            return vector<ListNode*>(k, {});
        }
        int cnt = 0;
        ListNode* cur = head;
        while(cur) {
            cur = cur->next;
            cnt++;
        }
        int t1 = cnt / k;
        int t2 = cnt % k;
        vector<ListNode*> ans;
        while(head) {
            int curc = t1 + (t2 > 0 ? 1 : 0) - 1;
            t2--;
            ListNode* n = head;
            while(curc--) {
                n = n->next;
            }
            ListNode* next = nullptr;
            if(n) {
                next = n->next;
                n->next = nullptr;
            }
            ans.push_back(head);
            head = next;
        }
        int n = ans.size();
        for(int i = 1; i <= k - n; i++) {
            ans.push_back(nullptr);
        }
        return ans;
    }
};
// @lc code=end

