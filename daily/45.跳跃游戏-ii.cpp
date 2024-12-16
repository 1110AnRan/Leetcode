/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int max = 0, n = nums.size(), end = 0, ans = 0;
        for(int i = 0; i < n - 1; i++) {
            if(max >= i) {
                max = std::max(max, i + nums[i]);
                if(i == end) {
                    end = max;
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

