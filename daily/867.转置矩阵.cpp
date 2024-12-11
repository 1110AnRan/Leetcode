/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ret[j][i] = matrix[i][j];
            }
        }
        return ret;
    }
};
// @lc code=end

