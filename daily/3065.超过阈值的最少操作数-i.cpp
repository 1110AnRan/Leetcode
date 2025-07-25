/*
 * @lc app=leetcode.cn id=3065 lang=cpp
 *
 * [3065] 超过阈值的最少操作数 I
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int x : nums) {
            if(x < k) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

