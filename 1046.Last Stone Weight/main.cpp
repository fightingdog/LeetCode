//
//  main.cpp
//  Last Stone Weight
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
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> que;
        for (int i : stones) {
            que.push(i);
        }
        while (!que.empty()) {
            int top1 = que.top();
            que.pop();
            if (que.empty()) {
                return top1;
            }
            int top2 = que.top();
            que.pop();
            int ret = abs(top1 - top2);
            que.push(ret);
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {4, 5, 8, 2};
    Solution so = Solution();
    int ret = so.lastStoneWeight(nums);
    cout << ret << endl;
    return 0;
}
