/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < m; i++) {
            int t = matrix[0][i];
            int j = 1, k = i + 1;
            while(j < n and k < m) {
                if(matrix[j][k] != t) {
                    return false;
                }
                j++;
                k++;
            }
        }
        for(int i = 1; i < n; i++) {
            int t = matrix[i][0];
            int j = i + 1, k = 1;
            while(j < n and k < m) {
                if(matrix[j][k] != t) {
                    return false;
                }
                j++;
                k++;
            }
        }
        return true;
    }
};
// @lc code=end

