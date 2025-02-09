/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    stack<int> s1, s2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty()) {
            s2.push(val);
        } else {
            if(val < s2.top()) {
                s2.push(val);
            } else {
                s2.push(s2.top());
            }
        }
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

