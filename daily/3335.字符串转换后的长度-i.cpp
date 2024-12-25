/*
 * @lc app=leetcode.cn id=3335 lang=cpp
 *
 * [3335] 字符串转换后的长度 I
 */

// @lc code=start
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int mod = 1e9 + 7;
        vector<long long> ans(26);
        for(int i = 0; i < s.size(); i++) {
            ans[s[i] - 'a']++;
        }
        for(int i = 0; i < t; i++) {
            vector<long long> next(26);
            for(int j = 1; j < 26; j++) {
                next[j] = ans[j - 1];
            }
            next[0] = ans[25] % mod;
            next[1] = ans[0] % mod + ans[25] % mod;
            for(int j = 0; j < 26; j++) {
                ans[j] = next[j] % mod;
            }
        }
        return accumulate(ans.begin(), ans.end(), 0LL) % mod;
    }
};
// @lc code=end

