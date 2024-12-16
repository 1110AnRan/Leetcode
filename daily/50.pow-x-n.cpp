/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long long m = labs(n);
        while(m) {
            if(m & 1) { 
                res = res * x;
            }
            m >>= 1;
            x = x * x;
        }
        if(n < 0LL) {
            res = 1.0 / res;
        }
        return res;
    }
};
// @lc code=end

