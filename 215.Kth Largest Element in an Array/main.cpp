//
//  main.cpp
//  Kth Largest Element in an Array
//
//  Created by 刘昭 on 2019/11/24.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i : nums) {
            que.push(i);
            if ((int)que.size() > k) {
                que.pop();
            }
        }
        return que.top();
    }
    
    int findKthLargest1(vector<int>& nums, int k) {
        int ret = 0;
        int numSize = (int)nums.size();
        if (numSize == 0 || k > numSize) {
            return -1;
        }
        //寻找第kMIN小的数
        int kMin = numSize - k + 1;
        ret = helper(nums, kMin, 0, numSize - 1);
        return ret;
    }
    
    int helper(vector<int>& nums, int k, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        int par = partition(nums, left, right);
        int curRet = par - left + 1;
        if (k == curRet) {
            return nums[par];
        } else if (k < curRet) {
            return helper(nums, k, left, par - 1);
        } else {
            return helper(nums, k - curRet, par + 1, right);
        }
        return 0;
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int i = left, j = right - 1;
        int pivot = nums[right];
        while (i <= j) {
            while (i <= j && nums[j] >= pivot) {
                j--;
            }
            while (i <= j && nums[i] <= pivot) {
                i++;
            }
            if (i <= j) {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    Solution so = Solution();
    int ret = so.findKthLargest1(nums, k);
    cout << ret << endl;
    return 0;
}
