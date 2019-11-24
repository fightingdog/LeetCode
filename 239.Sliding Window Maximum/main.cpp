//
//  main.cpp
//  Sliding Window Maximum
//
//  Created by 刘昭 on 2019/11/24.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    void cleanDeque(vector<int>& nums, deque<int>& que, int i, int k) {
        if (!que.empty() && que.front() == i - k) {
            que.pop_front();
        }
        while (!que.empty() && nums[que.back()] < nums[i]) {
            que.pop_back();
        }
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int numSize = (int)nums.size();
        if (k * numSize == 0) {
            return {};
        }
        if (k == 1) {
            return nums;
        }
        vector<int> ret;
        deque<int> que;
        int maxIndex = 0;
        for (int i = 0; i < k; i++) {
            cleanDeque(nums, que, i, k);
            que.push_back(i);
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        ret.push_back(nums[maxIndex]);
        for (int i = k; i < numSize; i++) {
            cleanDeque(nums, que, i, k);
            que.push_back(i);
            ret.push_back(nums[que.front()]);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
//    vector<int> nums = {1,3,1,2,0,5};
    int k = 3;
    Solution so = Solution();
    vector<int> ret = so.maxSlidingWindow(nums, k);
    for (int i : ret) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
