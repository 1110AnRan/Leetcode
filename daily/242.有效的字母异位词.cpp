/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        int sum = 0;
        for(auto c : s) {
            mp[c]++;
            sum++;
        }
        for(auto c : t) {
            if(!mp.count(c) or mp[c] <= 0) {
                return false;
            }
            mp[c]--;
            sum--;
        }
        return sum == 0;
    }
};
// @lc code=end

