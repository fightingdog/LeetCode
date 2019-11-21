//
//  main.cpp
//  3Sum
//
//  Created by liuzhao on 2019/11/21.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() <= 2) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size() - 2; i++) {
            int low = i + 1, high = (int)nums.size() - 1;
            int sum = -nums[i];
            while (low < high) {
                int curSum = nums[low] + nums[high];
                if (curSum == sum) {
                    ret.push_back({nums[i], nums[low], nums[high]});
                    while (low < high && nums[low] == nums[low + 1]) {
                        low++;
                    }
                    while (low < high && nums[high] == nums[high - 1]) {
                        high--;
                    }
                    low++;
                    high--;
                } else if (curSum < sum) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {0};
    Solution so = Solution();
    vector<vector<int>> ret = so.threeSum(nums);
    for (vector<int> vec : ret) {
        for (int i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
