/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) {
            return {1};
        }
        vector<int> ret(rowIndex + 1);
        ret[0] = 1;
        ret[1] = 1;
        for(int i = 2; i <= rowIndex; i++) {
            for(int j = i; j >= 0; j--) {
                if(j == i || j == 0) {
                    ret[j] = 1;
                } else {
                    ret[j] = ret[j] + ret[j - 1];
                }
            }
        }
        return ret;
    }
};
// @lc code=end

