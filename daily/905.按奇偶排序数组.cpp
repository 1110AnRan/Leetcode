/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> v1, v2;
        for(auto x : nums) {
            if(x & 1) {
                v1.push_back(x);
            } else {
                v2.push_back(x);
            }
        }
        vector<int> ret(v2);
        ret.insert(ret.end(), v1.begin(), v1.end());
        return ret;
    }
};
// @lc code=end

