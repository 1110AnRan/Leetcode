/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses);
        vector<int> d(numCourses);
        for(auto x : prerequisites) {
            int u = x[0];
            int v = x[1];
            edge[v].push_back(u);
            d[u]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++) {
            if(d[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        while(q.size()) {
            auto x = q.front();
            q.pop();
            for(auto y : edge[x]) {
                d[y]--;
                if(d[y] == 0) {
                    q.push(y);
                    ans.push_back(y);
                }
            }
        }
        if(ans.size() == numCourses) {
            return ans;
        }
        return {};
    }
};
// @lc code=end

