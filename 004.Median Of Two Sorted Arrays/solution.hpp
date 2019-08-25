//
//  solution.hpp
//  004.median_of_two_sorted_arrays
//
//  Created by liuzhao on 2019/8/24.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t m = nums1.size();
        size_t n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j - 1] > nums1[i]) {
                iMin = i + 1;
            } else if (i > iMin && nums1[i - 1] > nums2[j]) {
                iMax = i - 1;
            } else {
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = nums2[j - 1];
                } else if (j == 0) {
                    maxLeft = nums1[i - 1];
                } else {
                    maxLeft = max(nums1[i-1], nums2[j-1]);
                }
                
                if ((m + n) % 2 == 1) {
                    return maxLeft;
                }
                
                int minRight = 0;
                if (i == m) {
                    minRight = nums2[j];
                } else if (j == n) {
                    minRight = nums1[i];
                } else {
                    minRight = min(nums2[j], nums1[i]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0;
    }
};

#endif /* solution_hpp */
