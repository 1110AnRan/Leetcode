/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> min;
    priority_queue<int, vector<int>, greater<int>> max;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(min.empty() || num <= min.top()) {
            min.push(num);
            if(max.size() + 1 < min.size()) {
                max.push(min.top());
                min.pop();
            }
        } else {
            max.push(num);
            if(max.size() > min.size()) {
                min.push(max.top());
                max.pop();
            }
        }
    }
    
    double findMedian() {
        if(min.size() > max.size()) {
            return min.top();
        }
        return (min.top() + max.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

