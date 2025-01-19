/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> mp;
    int solve(int id) {
        int sum = mp[id]->importance;
        for(auto x : mp[id]->subordinates) {
            sum += solve(x);
        }
        return sum;
    }

    int getImportance(vector<Employee*> employees, int id) {
        for(Employee* e : employees) {
            mp[e->id] = e;
        }
        return solve(id);

    }
};
// @lc code=end

