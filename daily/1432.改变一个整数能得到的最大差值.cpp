/*
 * @lc app=leetcode.cn id=1432 lang=cpp
 *
 * [1432] 改变一个整数能得到的最大差值
 */

// @lc code=start
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '9') {
                for(int j = i + 1; j < s.size(); j++) {
                    if(s[j] == s[i]) {
                        s[j] = '9';
                    }
                }
                s[i] = '9';
                break;
            }
        }
        int t1 = stoi(s);
        s = to_string(num);
        if(s[0] != '1') {
            for(int i = 1; i < s.size(); i++) {
                if(s[i] == s[0]) {
                    s[i] = '1';
                }
            }
            s[0] = '1';
        } else {
            for(int i = 1; i < s.size(); i++) {
                if(s[i] != '0' and s[i] != s[0]) {
                    for(int j = i + 1; j < s.size(); j++) {
                        if(s[j] == s[i]) {
                            s[j] = '0';
                        }
                    }
                    s[i] = '0';
                    break;
                }
            }
        }
        int t2 = stoi(s);
        return t1 - t2;
    }
};
// @lc code=end

