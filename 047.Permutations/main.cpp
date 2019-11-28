//
//  main.cpp
//  Permutations
//
//  Created by liuzhao on 2019/11/28.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = (int)nums.size();
        vector<bool> used(n, false);
        vector<int> curRet(n, -1);
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        permuteUnique(0, n, used, curRet, nums, ret);
        return ret;
    }
    
    void permuteUnique(int index, int n, vector<bool>& used, vector<int>& curRet, vector<int>& nums, vector<vector<int>>& ret) {
        if (index == n) {
            ret.push_back(curRet);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                    continue;
                }
                used[i] = true;
                curRet[index] = nums[i];
                permuteUnique(index + 1, n, used, curRet, nums, ret);
                used[i] = false;
                curRet[index] = -1;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 1, 2};
    Solution so = Solution();
    vector<vector<int>> ret = so.permuteUnique(nums);
    for (vector<int> sol : ret) {
        for (int s : sol) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
