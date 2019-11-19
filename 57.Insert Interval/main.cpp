//
//  main.cpp
//  Insert Interval
//
//  Created by liuzhao on 2019/11/19.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool lessVector(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        // 按第一个值排序
        sort(intervals.begin(), intervals.end(), lessVector);
        vector<vector<int>> ret{intervals[0]};
        for (int i = 0; i < intervals.size(); i++) {
            if (ret.back()[1] >= intervals[i][0]) {
                ret.back()[1] = max(intervals[i][1], ret.back()[1]);
            } else {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> intervals = {
        {1,2}, {3,5}, {6,7}, {8,10}, {12,16}
    };
    vector<int> newInterval = {4, 8};
//    vector<vector<int>> intervals = {
//        {1,3}, {6,9}
//    };
//    vector<int> newInterval = {2, 5};
//    vector<vector<int>> intervals = {
//        {1,5}
//    };
//    vector<int> newInterval = {2, 3};
    Solution so = Solution();
    vector<vector<int>> ret = so.insert(intervals, newInterval);
    for (vector<int> interval : ret) {
        for (int i : interval) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
