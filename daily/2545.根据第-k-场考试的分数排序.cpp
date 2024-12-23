/*
 * @lc app=leetcode.cn id=2545 lang=cpp
 *
 * [2545] 根据第 K 场考试的分数排序
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&](const vector<int>& v1, const vector<int>& v2) {
            return v1[k] > v2[k];
        });
        return score;
    }
};
// @lc code=end

