/*
 * @lc app=leetcode.cn id=1993 lang=cpp
 *
 * [1993] 树上的操作
 */

// @lc code=start
class LockingTree {
public:
    int n;
    vector<vector<int>> sons;
    vector<int> locks, parent;
    LockingTree(vector<int>& parent) {
        this->n = parent.size();
        this->parent = parent;
        sons.assign(n, {});
        locks.assign(n, -1);
        for(int i = 1; i < n; i++) {
            sons[parent[i]].push_back(i);
        }
    }
    bool lock(int num, int user) {
        if(locks[num] == -1) {
            locks[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(locks[num] == user) {
            locks[num] = -1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        bool res = locks[num] == -1 and !check1(num) and check2(num);
        if(res) {
            locks[num] = user;
        }
        return res;
    }

    bool check1(int num) {
        int cur = parent[num];
        while(cur != -1) {
            if(locks[cur] != -1) {
                return true;
            }
            cur = parent[cur];
        }
        return false;
    }

    bool check2(int num) {
        bool res = locks[num] != -1;
        locks[num] = -1;
        for(int c : sons[num]) {
            res |= check2(c);
        }
        return res;

    }

};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
// @lc code=end

