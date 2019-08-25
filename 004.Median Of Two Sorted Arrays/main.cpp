//
//  main.cpp
//  004.median_of_two_sorted_arrays
//
//  Created by liuzhao on 2019/8/24.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>
#include "solution.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums1 = { 1, 2 };
    vector<int> nums2 = { -1, 3 };
    Solution solution = Solution();
    double result = solution.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}
