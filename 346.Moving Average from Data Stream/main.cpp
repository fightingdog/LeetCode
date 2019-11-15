//
//  main.cpp
//  Moving Average from Data Stream
//
//  Created by 刘昭 on 2019/11/15.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): len(size), sum(0) {
        
    }
    
    double next(int val) {
        sum += val;
        que.push(val);
        if (que.size() > len) {
            int front = que.front();
            sum -= front;
            que.pop();
        }
        return sum / que.size();
    }
    
private:
    int len;
    double sum;
    queue<int> que;
};

int main(int argc, const char * argv[]) {
    MovingAverage m = MovingAverage(3);
//    m.next(1) = 1
//    m.next(10) = (1 + 10) / 2
//    m.next(3) = (1 + 10 + 3) / 3
//    m.next(5) = (10 + 3 + 5) / 3
    cout << m.next(1) << endl;
    cout << m.next(10) << endl;
    cout << m.next(3) << endl;
    cout << m.next(5) << endl;
    return 0;
}
