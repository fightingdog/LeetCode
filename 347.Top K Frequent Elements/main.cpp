//
//  main.cpp
//  Top K Frequent Elements
//
//  Created by 刘昭 on 2019/11/24.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> MyPair;

class Solution {
public:
    struct compare {
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> sMap;
        for (int i : nums) {
            sMap[i]++;
        }
        vector<int> ret;
        priority_queue<MyPair, vector<MyPair>, compare> que;
        for (auto a : sMap) {
            que.push(a);
            if (que.size() > k) {
                que.pop();
            }
        }
        while (!que.empty()) {
            ret.push_back(que.top().first);
            que.pop();
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution so = Solution();
    vector<int> ret = so.topKFrequent(nums, k);
    for (auto i : ret) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
