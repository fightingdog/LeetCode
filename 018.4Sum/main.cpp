//
//  main.cpp
//  3Sum
//
//  Created by liuzhao on 2019/11/21.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() <= 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int low = j + 1, high = (int)nums.size() - 1;
                int sum = target - nums[i] - nums[j];
                while (low < high) {
                    int curSum = nums[low] + nums[high];
                    if (curSum == sum) {
                        ret.push_back({nums[i], nums[j], nums[low], nums[high]});
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
                while (j + 1 < nums.size() - 2 && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            while (i + 1 < nums.size() - 3 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
//    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution so = Solution();
    vector<vector<int>> ret = so.fourSum(nums, target);
    for (vector<int> vec : ret) {
        for (int i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
