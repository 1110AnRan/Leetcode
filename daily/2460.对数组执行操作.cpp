/*
 * @lc app=leetcode.cn id=2460 lang=cpp
 *
 * [2460] 对数组执行操作
 */

// @lc code=start
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        vector<int> ret;
        for(auto x : nums) {
            if(x) {
                ret.push_back(x);
            }
        }
        int m = n - ret.size();
        for(int i = 0; i < m; i++) {
            ret.push_back(0);
        }
        return ret;
    }
};
// @lc code=end

