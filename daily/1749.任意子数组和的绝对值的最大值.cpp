/*
 * @lc app=leetcode.cn id=1749 lang=cpp
 *
 * [1749] 任意子数组和的绝对值的最大值
 */

// @lc code=start
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        partial_sum(nums.begin(), nums.end(), nums.begin());
        auto [a, b] = minmax_element(nums.begin(), nums.end());
        return max(*b, 0) - min(*a, 0);
    }
};
// @lc code=end

