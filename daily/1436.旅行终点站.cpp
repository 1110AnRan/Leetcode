/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        int n = paths.size();
        for(int i = 0; i < n; i++) {
            mp[paths[i][0]]++;
        }
        for(int i = 0; i < n; i++) {
            if(!mp.count(paths[i][1])) {
                return paths[i][1];
            }
        }
        return "";
    }
};
// @lc code=end

