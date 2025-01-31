/*
 * @lc app=leetcode.cn id=2956 lang=cpp
 *
 * [2956] 找到两个数组中的公共元素
 */

// @lc code=start
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        for(auto x : nums1) {
            mp1[x] = 1;
        }
        for(auto x : nums2) {
            mp2[x] = 1;
        }
        int ans1 =  0, ans2 = 0;
        for(auto x : nums1) {
            if(mp2[x]) {
                ans1++;
            }
        }
        for(auto x : nums2) {
            if(mp1[x]) {
                ans2++;
            }
        }
        return {ans1, ans2};
    }
};
// @lc code=end

