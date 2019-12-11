//
//  main.cpp
//  Remove Element
//
//  Created by liuzhao on 2019/12/11.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        for (; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution so = Solution();
    int ret = so.removeElement(nums, val);
    cout << ret << endl;
    for (int i = 0; i < ret; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
