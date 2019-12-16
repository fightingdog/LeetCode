//
//  main.cpp
//  Search Insert Position
//
//  Created by liuzhao on 2019/12/16.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        int l = 0, r = (int)nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 3, 5, 6};
    int target = 0;
    Solution so = Solution();
    int ret = so.searchInsert(nums, target);
    cout << ret << endl;
    return 0;
}
