//
//  main.cpp
//  N-th Tribonacci Number
//
//  Created by liuzhao on 2019/11/18.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }
        int ret = 0;
        int temp1 = 0, temp2 = 1, temp3 = 1;
        for (int i = 3; i <= n; i++) {
            ret = temp1 + temp2 + temp3;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = ret;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution so = Solution();
    int ret = so.tribonacci(25);
    cout << ret << endl;
    return 0;
}
