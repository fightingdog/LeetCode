//
//  main.cpp
//  Longest Increasing Subsequence
//
//  Created by liuzhao on 2019/11/29.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxLength = 0;
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return (int)nums.size();
        }
        vector<int> ret;
        subsetOfNums(0, ret, (int)nums.size(), nums);
        return maxLength;
    }
    
    void subsetOfNums(int index, vector<int>& curRet, int n, vector<int>& nums) {
//        printVector(curRet);
        
        if (isAsend(curRet) && curRet.size() > maxLength) {
            maxLength = (int)curRet.size();
        }
        
        if (index == n) {
            return;
        }
        
        for (int i = index; i < n; i++) {
            curRet.push_back(nums[i]);
            subsetOfNums(i + 1, curRet, n, nums);
            curRet.pop_back();
        }
//        subsetOfNums(index + 1, curRet, n, nums); // 不选用这个
//
//        curRet.push_back(nums[index]);
//        subsetOfNums(index + 1, curRet, n, nums);
//        curRet.pop_back();
    }
    
    void printVector(vector<int>& nums) {
        for (int i : nums) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    bool isAsend(vector<int>& nums) {
        // 判断是否递增
        int i = 0;
        while (nums.size() > 0 && i < nums.size() - 1) {
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
            i++;
        }
        return true;
    }
    
    int lengthOfLIS1(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return (int)nums.size();
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int maxAns = 1;
        for (int i = 1; i < nums.size(); i++) {
            int maxVal = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    maxVal = max(maxVal, dp[j]);
                }
            }
            dp[i] = maxVal + 1;
            maxAns = max(maxAns, dp[i]);
        }
        return maxAns;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
//    nums = {-2, -1};
    nums = {4,10,4,3,8,9};
    Solution so = Solution();
    int ret = so.lengthOfLIS1(nums);
    cout << ret << endl;
    return 0;
}
