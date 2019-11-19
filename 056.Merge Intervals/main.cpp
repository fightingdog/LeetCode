//
//  main.cpp
//  Merge Intervals
//
//  Created by liuzhao on 2019/11/19.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool lessVector(vector<int>& v1, vector<int>& v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        // 按第一个值排序
        sort(intervals.begin(), intervals.end(), lessVector);
        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size() - 1; i++) {
            vector<int> v1 = intervals[i];
            vector<int> v2 = intervals[i+1];
            if (v1[1] < v2[0]) {
                ret.push_back(v1);
            } else {
                intervals[i+1][0] = v1[0];
                intervals[i+1][1] = v1[1] > v2[1] ? v1[1] : v2[1];
            }
            if (i == intervals.size() - 2) {
                ret.push_back(intervals[i + 1]);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
//    vector<vector<int>> intervals = {
//        {1,3}, {2,6}, {8,10}, {15,18}
//    };
    vector<vector<int>> intervals = {
        {2,3},{4,5},{6,7},{8,9},{1,10}
    };
    Solution so = Solution();
    vector<vector<int>> ret = so.merge(intervals);
    for (vector<int> interval : ret) {
        for (int i : interval) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
