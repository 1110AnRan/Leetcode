/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> ans(n, 1000000);
        ans[0] = cost[0];
        ans[1] = cost[1];
        for (int i = 2; i < n; i++) {
            ans[i] = min(ans[i - 1], ans[i - 2]) + cost[i];
        }
        return min(ans[n - 1], ans[n - 2]);
    }
};
// @lc code=end

