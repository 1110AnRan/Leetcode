/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;

            nums[index] *= -1;
            if(nums[index] > 0) {
                return abs(nums[i]);
            }
        }
        return -1;
    }
};
// @lc code=end

