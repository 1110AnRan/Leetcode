/*
 * @lc app=leetcode.cn id=2138 lang=cpp
 *
 * [2138] 将字符串拆分为若干长度为 k 的组
 */

// @lc code=start
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i = 0; i < s.size(); i += k) {
            ans.push_back(s.substr(i, k));
        }
        auto &t = ans.back();
        if(t.size() < k) {
            t += string(k - t.size(), fill);
        }
        return ans;
    }
};
// @lc code=end

