//
//  main.cpp
//  3Sum Closest
//
//  Created by liuzhao on 2019/12/10.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff = INT_MAX;
        int ret = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = (int)nums.size() - 1;
            int sum = target - nums[i];
            while (j < k) {
                int curSum = nums[j] + nums[k];
                if (curSum == sum) {
                    return target;
                } else if (curSum < sum) {
                    if (abs(curSum - sum) < minDiff) {
                        minDiff = abs(curSum - sum);
                        ret = curSum + nums[i];
                    }
                    j++;
                } else {
                    if (abs(curSum - sum) < minDiff) {
                        minDiff = abs(curSum - sum);
                        ret = curSum + nums[i];
                    }
                    k--;
                }
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    Solution so = Solution();
    int ret = so.threeSumClosest(nums, target);
    cout << ret << endl;
    return 0;
}
