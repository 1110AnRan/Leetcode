/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target) {
            return letters[0];
        }
        int l = 0, r = letters.size() - 1;
        int ans = r;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(letters[mid] > target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return letters[ans];
    }
};
// @lc code=end

