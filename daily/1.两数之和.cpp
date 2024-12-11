/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++)
        {
            auto it=m.find(target-nums[i]);
            if(it!=m.end())
            {
                return {it->second,i};
            }
            m[nums[i]]=i;
        }
        return {};
    }
};
// @lc code=end

