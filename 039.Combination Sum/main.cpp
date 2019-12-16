//
//  main.cpp
//  Combination Sum
//
//  Created by liuzhao on 2019/12/16.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> curRet;
        helper(0, target, candidates, curRet, ret);
        return ret;
    }
    
    void helper(int s, int target, vector<int>& candiates, vector<int>& curRet, vector<vector<int>>& ret) {
        if (target == 0) {
            ret.push_back(curRet);
            return;
        } else if (target < 0) {
            return;
        }
        for (int i = s; i < candiates.size(); i++) {
            int newTarget = target - candiates[i];
            curRet.push_back(candiates[i]);
            helper(i, newTarget, candiates, curRet, ret);
            curRet.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;
    Solution so = Solution();
    vector<vector<int>> ret = so.combinationSum(nums, target);
    for (vector<int> solu : ret) {
        for (int i : solu) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
