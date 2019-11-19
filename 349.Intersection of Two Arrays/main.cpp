//
//  main.cpp
//  Intersection of Two Arrays
//
//  Created by liuzhao on 2019/11/19.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;
        vector<int> ret;
        for (int i : nums1) {
            set1.insert(i);
        }
        for (int i : nums2) {
            set2.insert(i);
        }
        unordered_set<int> temp;
        if (set1.size() > set2.size()) {
            temp = set1;
            set1 = set2;
            set2 = temp;
        }
        for (int i : set1) {
            if (set2.find(i) != set2.end()) {
                ret.push_back(i);
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
