/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int cur = 100;
        int ans = 1;
        for(auto c : s) {
            int t = widths[c - 'a'];
            if(t <= cur) {
                cur -= t;
            } else {
                cur = 100 - t;
                ans++;
            }
        }
        return {ans, 100 - cur};
    }
};
// @lc code=end

