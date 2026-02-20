/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    int reverseBits(int n) {
        string s;
        while(n) {
            if (n % 2) {
                s.push_back('1');
            } else {
                s.push_back('0');
            }
            n /= 2;
        }
        if (s.size() < 32) {
            s.append(string(32 - s.size(), '0'));
        }
        cout << s << endl;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += (s[i] == '1' ? (1 << (s.size() - i - 1)) : 0);
        }
        return ans;
    }
};
// @lc code=end

