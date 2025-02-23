/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, string> mp;

    void dfs(string digits, vector<string>& ans, string cur, int step) {
        if(step == digits.size()) {
            ans.push_back(cur);
            return;
        }

        for(int i = 0; i < mp[digits[step]].size(); i++) {
            cur.push_back(mp[digits[step]][i]);
            dfs(digits, ans, cur, step + 1);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> ans;
        if(digits.size() == 0) {
            return vector<string>{};
        }
        dfs(digits, ans, "", 0);
        return ans;
    }
};
// @lc code=end

