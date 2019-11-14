//
//  main.cpp
//  Min Stack
//
//  Created by 刘昭 on 2019/11/14.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include "Solution.hpp"

using namespace std;

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/

int main(int argc, const char * argv[]) {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;

    return 0;
}
