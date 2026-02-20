/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l <= r) {
            // cout << l << " " << r << endl;
            if (s[l] >= 'A' && s[l] <= 'Z') {
                s[l] = s[l] - 'A' + 'a';
            }
            if (s[r] >= 'A' && s[r] <= 'Z') {
                s[r] = s[r] - 'A' + 'a';
            }
            if (!isalpha(s[l]) && !isdigit(s[l])) {
                l++;
                continue;
            }
            if (!isalpha(s[r]) && !isdigit(s[r])) {
                r--;
                continue;
            }
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
// @lc code=end

