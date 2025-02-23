/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;
        for(int i = 0; i < s.size(); i++) {
            if(!mp1.count(s[i]) and !mp2.count(t[i])) {
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            } else if(mp1.count(s[i]) and mp2.count(t[i])) {
                if(mp1[s[i]] != t[i] or mp2[t[i]] != s[i]) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

