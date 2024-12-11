/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        string s;
        while(n) {
            s.push_back(n % 2 + '0');
            n /= 2;
        }
        vector<int> v1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                v1.push_back(i);
            }
        }
        int ret = 0;
        for(int i = 0; i < v1.size() - 1; i++) {
            ret = max(ret, v1[i + 1] - v1[i]);
        }
        return ret;
    }
};
// @lc code=end

