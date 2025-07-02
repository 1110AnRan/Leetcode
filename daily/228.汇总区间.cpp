/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        for(int l = 0, r = 0; l <= r and l < n;) {
            while(r + 1 < n and nums[r + 1] == nums[r] + 1) {
                r++;
            }
            if(nums[l] == nums[r]) {
                ans.push_back(to_string(nums[l]));
            } else {
                ans.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
            }
            
            r++;
            l = r;
        }
        return ans;
    }
};
// @lc code=end

