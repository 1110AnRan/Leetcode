/*
 * @lc app=leetcode.cn id=2965 lang=cpp
 *
 * [2965] 找出缺失和重复的数字
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnt(n * n + 1, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cnt[grid[i][j]]++;
            }
        }
        vector<int> ret;
        for(int i = 1; i <= n * n; i++) {
            if(cnt[i] == 2) {
                ret.push_back(i);
            }
        }
        for(int i = 1; i <= n * n; i++) {
            if(cnt[i] == 0) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
// @lc code=end

