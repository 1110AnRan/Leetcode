/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for(auto c : s) {
            t += c;
            t += "#";
        }
        int n = t.size();
        int mx = 0, l = 0;
        vector<int> p(n);
        for(int i = 0, c = 0, r = 0, len; i < n; i++) {
            len = r > i ? min(p[2 * c - i], r - i) : 1;
            while(i + len < n && i - len >= 0 && t[i + len] == t[i - len]) {
                len++;
            }
            if(i + len > r) {
                r = i + len;
                c = i;
            }
            if(len > mx) {
                mx = len - 1;
                l = (i + len - 1) / 2;
            }
            p[i] = len;
        }
        return s.substr(l - mx, mx);
        

    }
};
// @lc code=end

