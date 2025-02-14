/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto x : nums) {
            pq.push(x);
        }
        while(k > 1) {
            pq.pop();
            k--;
        } 
        return pq.top();
    }
};
// @lc code=end

