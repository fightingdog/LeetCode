//
//  main.cpp
//  Find First and Last Position of Element in Sorted Array
//
//  Created by liuzhao on 2019/11/20.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // min
        int low = 0, high = (int)nums.size() - 1;
        int mid;
        int min = -1, max = -1;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (nums[mid] == target) {
                if (mid > 0 && nums[mid-1] == target) {
                    high = mid - 1;
                } else {
                    min = mid;
                    break;
                }
            } else if (nums[mid] < target) {
                low = low + 1;
            } else {
                high = high - 1;
            }
        }
        
        // max
        low = min;
        high = (int)nums.size() - 1;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (nums[mid] == target) {
                if (mid < nums.size() - 1 && nums[mid+1] == target) {
                    low = mid + 1;
                } else {
                    max = mid;
                    break;
                }
            } else if (nums[mid] < target) {
                low = low + 1;
            } else {
                high = high - 1;
            }
        }
        vector<int> ret = {min, max};
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {5, 7,7,8,8,10};
    int target = 8;
    Solution so = Solution();
    vector<int> ret = so.searchRange(nums, target);
    for (int i : ret) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
