//
//  main.cpp
//  Search in Rotated Sorted Array II
//
//  Created by liuzhao on 2019/12/1.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target) {
                return true;
            }
            if (nums[low] == nums[mid]) {
                low++;
                continue;
            }
            if (nums[low] < nums[mid]) {
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
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {3, 1};
    int target = 1;
    Solution so = Solution();
    bool ret = so.search(nums, target);
    cout << ret << endl;
    return 0;
}
