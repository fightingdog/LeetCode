//
//  main.cpp
//  Intersection of Two Arrays
//
//  Created by liuzhao on 2019/11/19.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> sMap;
        for (int i : nums1) {
            sMap[i]++;
        }
        vector<int> ret;
        for (int i : nums2) {
            if (sMap[i] > 0) {
                ret.push_back(i);
                sMap[i]--;
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution so = Solution();
    vector<int> ret = so.intersection(nums1, nums2);
    for (int i : ret) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
