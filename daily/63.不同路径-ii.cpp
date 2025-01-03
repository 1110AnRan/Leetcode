/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector dp(n, vector<int>(m));
        for(int i = 0; i < m; i++) {
            if(obstacleGrid[0][i] == 1) {
                break;
            }
            dp[0][i] = 1;
        }

        for(int i = 0; i < n; i++) {
            if(obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(obstacleGrid[i][j] == 1) {
                    continue;
                }
                dp[i][j] = (obstacleGrid[i - 1][j] == 1 ? 0 : dp[i - 1][j]) + (obstacleGrid[i][j - 1] == 1 ? 0 : dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};
// @lc code=end

