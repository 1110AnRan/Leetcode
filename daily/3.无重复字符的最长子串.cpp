/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.size();
        int l = -1, ans = 0;
        for(int i = 0; i < n; i++) {
            if(i != 0) {
                st.erase(s[i - 1]);
            }

            while(l + 1 < n and !st.count(s[l + 1])) {
                st.insert(s[l + 1]);
                ++l;
            }

            ans = max(ans, l - i + 1);
        }
        return ans;
    }
    
};
// @lc code=end

