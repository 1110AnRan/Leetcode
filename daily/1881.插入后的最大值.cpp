/*
 * @lc app=leetcode.cn id=1881 lang=cpp
 *
 * [1881] 插入后的最大值
 */

// @lc code=start
class Solution {
public:
    string maxValue(string n, int x) {
        if(n[0] != '-') {
            for(int i = 0; i < n.size(); i++) {
                if(n[i] - '0' < x) {
                    n.insert(n.begin() + i, x + '0');
                    return n;
                }
            }
            n += (x + '0');
            return n;
        } else {
            for(int i = 1; i < n.size(); i++) {
                if(n[i] - '0' > x) {
                    n.insert(n.begin() + i, x + '0');
                    return n;
                }
            }
            n += (x + '0');
            return n;
        }
    }
};
// @lc code=end

