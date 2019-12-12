//
//  main.cpp
//  Next Permutation
//
//  Created by liuzhao on 2019/12/12.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        // 先从后向前找相邻顺序对[i, i-1]，找到以后，从后向前找第一个比i-1位置大的数字，找到后和i-1交换，反转i-1后面的数字
        bool found = false;
        int i = 0;
        for (i = (int)nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                found = true;
                break;
            }
        }
        if (found) {
            int j = 0;
            for (j = (int)nums.size() - 1; j >= 0; j--) {
                if (nums[j] > nums[i - 1]) {
                    break;
                }
            }
            swap(nums[i - 1], nums[j]);
            // 反转i
            reverse(nums.begin() + i, nums.end());
        } else {
            reverse(nums.begin(), nums.end());
        }
    }
};

void printVector(vector<int>& nums) {
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 2, 3, 4};
//    nums = {1, 3, 4, 2};
    printVector(nums);
    Solution so = Solution();
    for (int i = 0; i < 24; i++) {
        so.nextPermutation(nums);
        printVector(nums);
    }
    return 0;
}
