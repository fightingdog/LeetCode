//
//  Solution.hpp
//  Implement Queue using Stacks
//
//  Created by 刘昭 on 2019/11/14.
//  Copyright © 2019 刘昭. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s1.empty() && s2.empty()) {
            return -1;
        }
        if (!s2.empty()) {
            int res = s2.top();
            s2.pop();
            return res;
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            int res = s2.top();
            s2.pop();
            return res;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if (s1.empty() && s2.empty()) {
            return -1;
        }
        if (!s2.empty()) {
            int res = s2.top();
            return res;
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

#endif /* Solution_hpp */
