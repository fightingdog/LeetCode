//
//  main.cpp
//  Ugly Number II
//
//  Created by 刘昭 on 2019/11/24.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums = {1};
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        while (nums.size() < n) {
            int next2 = nums[i2] * 2;
            int next3 = nums[i3] * 3;
            int next5 = nums[i5] * 5;
            
            int val = min(next2, min(next3, next5));
            if (val == next2) {
                i2++;
            }
            if (val == next3) {
                i3++;
            }
            if (val == next5) {
                i5++;
            }
            nums.push_back(val);
        }
        return nums[n-1];
    }
};

int main(int argc, const char * argv[]) {
    int n = 10;
    Solution so = Solution();
    int ret = so.nthUglyNumber(n);
    cout << ret << endl;
    return 0;
}
