/*
 * @lc app=leetcode.cn id=3289 lang=cpp
 *
 * [3289] 数字小镇中的捣蛋鬼
 */

// @lc code=start
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto x : nums) {
            mp[x]++;
            if(mp[x] == 2) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
// @lc code=end

