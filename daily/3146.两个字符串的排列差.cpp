/*
 * @lc app=leetcode.cn id=3146 lang=cpp
 *
 * [3146] 两个字符串的排列差
 */

// @lc code=start
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }
        int ans = 0;
        for(int i = 0; i < t.size(); i++) {
            ans += abs(mp[t[i]] - i);
        }
        return ans;
    }
};
// @lc code=end

