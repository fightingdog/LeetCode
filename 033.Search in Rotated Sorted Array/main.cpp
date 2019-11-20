//
//  main.cpp
//  Search in Rotated Sorted Array
//
//  Created by liuzhao on 2019/11/20.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[low] <= nums[mid]) {
                // 左边递增，右边旋转
                if (target < nums[mid] && target >= nums[low]) {
                    // 在左边
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // 左边旋转，右边递增
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
//    vector<int> nums = {4,5,6,7,0,1,2};
//    int target = 3;
    vector<int> nums = {3, 1};
    int target = 1;
    Solution so = Solution();
    int ret = so.search(nums, target);
    cout << ret << endl;
    return 0;
}
