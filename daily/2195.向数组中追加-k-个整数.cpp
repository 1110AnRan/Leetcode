/*
 * @lc app=leetcode.cn id=2195 lang=cpp
 *
 * [2195] 向数组中追加 K 个整数
 */

// @lc code=start
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        if(nums[0] > 1) {
            ans += 1LL * min(nums[0] - 1, k) * (1 + min(nums[0] - 1, k)) / 2;
            k -= min(nums[0] - 1, k);
        }
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i + 1] - nums[i] > 1 and k >= (nums[i + 1] - nums[i] - 1)) {
                ans += 1LL * (nums[i + 1] - nums[i] - 1) * (nums[i] + 1 + nums[i + 1] - 1) / 2;
                k -= nums[i + 1] - nums[i] - 1;
                
            } else if(nums[i + 1] - nums[i] > 1 and k <= nums[i + 1] - nums[i] - 1 and k > 0){
                ans += 1LL * k * (nums[i] + 1 + nums[i] + k) / 2;
                k = 0;
                break;
            }
        }
        if(k) {
            ans += 1LL * k * (nums.back() + 1 + nums.back() + k) / 2;
        }
        return ans;
    }
};
// @lc code=end

