//
//  main.cpp
//  Divide Two Integers
//
//  Created by liuzhao on 2019/11/20.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return ans * sign;
    }
};

int main(int argc, const char * argv[]) {
    int dividend = 10;
    int divisor = 3;
    Solution so = Solution();
    int ret = so.divide(dividend, divisor);
    cout << ret << endl;
    return 0;
}
