//
//  main.cpp
//  Partition to K Equal Sum Subsets
//
//  Created by 刘昭 on 2019/11/18.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (sum % k != 0) return false;
        vector<bool> visited(nums.size(), false);
        return helper(nums, k, sum / k, 0, 0, visited);
    }
    
    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited) {
        if (k == 1) return true;
        if (curSum > target) return false;
        if (curSum == target) return helper(nums, k - 1, target, 0, 0, visited);
        for (int i = start; i < nums.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            if (helper(nums, k, target, i + 1, curSum + nums[i], visited)) return true;
            visited[i] = false;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {4,5,3,2,5,5,5,1,5,5,5,5,3,5,5,2};
    int k = 13;
    Solution so = Solution();
    bool ret = so.canPartitionKSubsets(nums, k);
    cout << ret << endl;
    return 0;
}
