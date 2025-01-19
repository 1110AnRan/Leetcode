/*
 * @lc app=leetcode.cn id=1600 lang=cpp
 *
 * [1600] 王位继承顺序
 */

// @lc code=start
class ThroneInheritance {
public:

    unordered_map<string, vector<string>> mp;
    unordered_map<string, bool> isdea;
    string fir;
    ThroneInheritance(string kingName) {
        mp[kingName].push_back(kingName);
        isdea.insert({ kingName, false });
        fir = kingName;
    }

    void birth(string parentName, string childName) {
        mp[parentName].push_back(childName);
        isdea.insert({ childName, false });
    }

    void death(string name) {
        isdea[name] = true;
    }

    void dfs(vector<string>& ans, string x) {
        if (isdea.count(x) and isdea[x] == false) {
            ans.push_back(x);
        }
        for (auto y : mp[x]) {
            if (y == x) {
                continue;
            }
            dfs(ans, y);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(ans, fir);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
// @lc code=end

