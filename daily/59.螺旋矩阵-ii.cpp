/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int cur = 1;
        int l = 0, r = n - 1, u = 0, d = n - 1;
        for(int i = 0; i < (n + 1) / 2; i++) {
            for(int j = l; j <= r; j++) {
                ans[u][j] = cur++;
            }
            for(int j = u + 1; j <= d; j++) {
                ans[j][r] = cur++;
            }
            for(int j = r - 1; j >= l; j--) {
                ans[d][j] = cur++;
            }
            for(int j = d - 1; j >= u + 1; j--) {
                ans[j][l] = cur++;
            }
            l++;
            r--;
            u++;
            d--;
        }
        return ans;
    }
};
// @lc code=end

