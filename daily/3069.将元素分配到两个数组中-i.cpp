/*
 * @lc app=leetcode.cn id=3069 lang=cpp
 *
 * [3069] 将元素分配到两个数组中 I
 */

// @lc code=start
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1, a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            if(a1.back() > a2.back()) {
                a1.push_back(nums[i]);
            } else {
                a2.push_back(nums[i]);
            }
        }
        a1.insert(a1.end(), a2.begin(), a2.end());
        return a1;
    }
};
// @lc code=end

