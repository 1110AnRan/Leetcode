/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses);
        vector<vector<int>> edge(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            in[prerequisites[i][0]]++;
            edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(in[i] == 0) {
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(q.size()) {
            auto u = q.front();
            ++cnt;
            q.pop();
            for(auto v : edge[u]) {
                in[v]--;
                if(in[v] == 0) {
                    q.push(v);
                }
            }
        }
        return cnt == numCourses;
    }
};
// @lc code=end

