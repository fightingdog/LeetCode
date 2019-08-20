//
//  solution.hpp
//  001.two_sum
//
//  Created by liuzhao on 2019/8/20.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::map;

class Solution {
public:
    // map
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); ++i) {
            auto found = record.find(target - nums[i]);
            if (found != record.end()) {
                return {found->second, i};
            }
            record.emplace(nums[i], i);
            //            record.insert({nums[i], i});
        }
        return {-1, -1};
    }
    
    
    // 暴力遍历
    vector<int> twoSum1(vector<int> &nums, int target) {
        int i = 0, j = 0;
        for (i = 0; i < nums.size() - 1; ++i) {
            for (j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
    
    // map
    vector<int> twoSum2(vector<int> &nums, int target) {
        map<int, int> record;
        vector<int> result(2, -1);
        for (int i = 0; i < nums.size(); ++i) {
            if ((record.count(target - nums[i])) > 0) {
                result[0] = record[target - nums[i]];
                result[1] = i;
                break;
            }
            record[nums[i]] = i;
        }
        return result;
    }
};

#endif /* solution_hpp */
