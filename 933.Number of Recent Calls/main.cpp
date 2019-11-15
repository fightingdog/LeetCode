//
//  main.cpp
//  Number of Recent Calls
//
//  Created by 刘昭 on 2019/11/15.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        que.push(t);
        while (que.front() < t - 3000) {
            que.pop();
        }
        return (int)que.size();
    }
private:
    queue<int> que;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
