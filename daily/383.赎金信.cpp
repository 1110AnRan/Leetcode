/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto c : magazine) {
            mp[c]++;
        }
        int cnt = 0;
        for(auto c : ransomNote) {
            if(!mp.count(c) or mp[c] <= 0) {
                return false;
            }
            mp[c]--;
            cnt++;
        }
        return cnt == ransomNote.size();

    }
};
// @lc code=end

