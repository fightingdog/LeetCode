//
//  main.cpp
//  001.two_sum
//
//  Created by liuzhao on 2019/8/20.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include "solution.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution = Solution();
    vector<int> result = solution.twoSum(nums, target);
    for (auto i = result.begin(); i != result.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    
    vector<int> result1 = solution.twoSum1(nums, target);
    for (auto i = result1.begin(); i != result1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    
    vector<int> result2 = solution.twoSum2(nums, target);
    for (auto i = result2.begin(); i != result2.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
    
    return 0;
}
