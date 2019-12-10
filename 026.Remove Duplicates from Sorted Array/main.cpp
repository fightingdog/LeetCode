//
//  main.cpp
//  Remove Duplicates from Sorted Array
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
    int removeDuplicates(vector<int>& nums) {
        int ret = 0;
        int dupCount = 0;
        for (int i = 1; i < nums.size() - dupCount; i++) {
            int j = i;
            int originDupCount = dupCount;
            while (j < nums.size() - originDupCount && nums[j] == nums[j - 1]) {
                j++;
                dupCount++;
            }
            int k = i;
            // 迁移
            while (j < nums.size() - originDupCount) {
                nums[k++] = nums[j++];
            }
        }
        ret = (int)nums.size() - dupCount;
        return ret;
    }
    
    int removeDuplicates1(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main(int argc, const char * argv[]) {
//    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums = {1,1,2,2};
    Solution so = Solution();
    int ret = so.removeDuplicates1(nums);
    cout << ret << endl;
    for (int i = 0; i < ret; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
