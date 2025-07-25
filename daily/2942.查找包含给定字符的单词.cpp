/*
 * @lc app=leetcode.cn id=2942 lang=cpp
 *
 * [2942] 查找包含给定字符的单词
 */

// @lc code=start
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i = 0; i < words.size(); i++) {
            if(words[i].find(x) != -1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

