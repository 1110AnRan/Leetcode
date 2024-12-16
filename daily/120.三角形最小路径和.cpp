/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[n - 1].size();
        vector<vector<int>> ans(n, vector<int>(m));
        ans[0][0] = triangle[0][0];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0) {
                    ans[i][j] = triangle[i][j] + ans[i - 1][j];
                } else if(j == i) {
                    ans[i][j] = triangle[i][j] + ans[i - 1][j - 1];
                } else {
                    ans[i][j] = triangle[i][j] + min(ans[i - 1][j - 1], ans[i - 1][j]);
                }
            }
        }
        return *min_element(ans[n - 1].begin(), ans[n - 1].end());
    }
};
// @lc code=end

