/*
 * @lc app=leetcode.cn id=2951 lang=cpp
 *
 * [2951] 找出峰值
 */

// @lc code=start
class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ans;
        for(int i = 1; i < mountain.size() - 1; i++) {
            if(mountain[i] > mountain[i - 1] and mountain[i] > mountain[i + 1]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

