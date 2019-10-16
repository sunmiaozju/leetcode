/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 *
 * https://leetcode.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (40.67%)
 * Likes:    401
 * Dislikes: 475
 * Total Accepted:    145.5K
 * Total Submissions: 353.5K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a stack using queues.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * 
 * 
 * Example:
 * 
 * 
 * MyStack stack = new MyStack();
 * 
 * stack.push(1);
 * stack.push(2);  
 * stack.top();   // returns 2
 * stack.pop();   // returns 2
 * stack.empty(); // returns false
 * 
 * Notes:
 * 
 * 
 * You must use only standard operations of a queue -- which means only push to
 * back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may
 * simulate a queue by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top
 * operations will be called on an empty stack).
 * 
 * 
 */

// @lc code=start

#include <iostream>
#include <queue>

using namespace std;

// class MyStack {
// public:
//     queue<int> q1, q2;
//     /** Initialize your data structure here. */
//     MyStack()
//     {
//     }

//     /** Push element x onto stack. */
//     void push(int x)
//     {
//         q1.push(x);
//     }

//     /** Removes the element on top of the stack and returns that element. */
//     int pop()
//     {
//         int num = q1.size() - 1;
//         for (size_t i = 0; i < num; i++) {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         int ans = q1.front();
//         q1 = q2;
//         q2 = queue<int>();
//         return ans;
//     }

//     /** Get the top element. */
//     int top()
//     {
//         int num = q1.size() - 1;
//         for (size_t i = 0; i < num; i++) {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         int ans = q1.front();
//         q2.push(q1.front());
//         q1 = q2;
//         q2 = queue<int>();
//         return ans;
//     }

//     /** Returns whether the stack is empty. */
//     bool empty()
//     {
//         return q1.empty();
//     }
// };

class MyStack {
public:
    queue<int> q1;
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q1.push(x);
        for (size_t i = 0; i < q1.size() - 1; i++) {
            q1.push(q1.front());
            q1.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    /** Get the top element. */
    int top()
    {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
