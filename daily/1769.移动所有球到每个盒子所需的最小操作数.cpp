/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

// @lc code=start
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        int cntl = 0, cntr = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(boxes[i] == '1') {
                sum += i;
                if(i >= 1) {
                    cntr++;
                }
            }
        }
        ans[0] = sum;
        cntl = boxes[0] == '1';
        for(int i = 1; i < n; i++) {
            if(boxes[i] == '1') {
                cntr--;
                ans[i] = sum = sum - cntr - 1 + cntl;
            } else {
                ans[i] = sum = sum - cntr + cntl;
            }
            if(boxes[i] == '1') {
                cntl++;
            }
           
        }
        return ans;
    }
};
// @lc code=end

