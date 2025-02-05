/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        for(auto x : candies) {
            mx = max(mx, x);
        }
        vector<bool> ans(candies.size(), false);
        int n = candies.size();
        for(int i = 0; i < n; i++) {
            if(mx - candies[i] <= extraCandies) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
// @lc code=end

