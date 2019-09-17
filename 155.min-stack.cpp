/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (38.60%)
 * Likes:    2082
 * Dislikes: 225
 * Total Accepted:    345.1K
 * Total Submissions: 891.8K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 * 
 * 
 */

#include <climits>
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    /** initialize your data structure here. */
    stack<int> ss;
    stack<int> ss_min;

public:
    MinStack()
    {
    }

    void push(int x)
    {
        ss.push(x);
        if (ss_min.empty() || x <= getMin()) {
            ss_min.push(x);
        }
    }

    void pop()
    {
        if (!ss_min.empty() && ss.top() == getMin()) {
            ss_min.pop();
        }
        ss.pop();
    }

    int top()
    {
        return ss.top();
    }

    int getMin()
    {
        return ss_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
