//
//  main.cpp
//  Task Scheduler
//
//  Created by 刘昭 on 2019/11/15.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 贪心算法
        vector<int> a(26, 0);
        for (auto c : tasks) {
            a[c - 'A'] = a[c - 'A'] + 1;
        }
        sort(a.begin(), a.end());
        int sum = 0;
        while (true) {
            int nonZeroCount = 0;
            for (int i = 25; i >= 0; i--) {
                if (a[i] > 0) {
                    a[i] = a[i] - 1;
                    nonZeroCount++;
                }
                if (nonZeroCount >= n + 1) {
                    break;
                }
            }
            sum += n + 1;
            sort(a.begin(), a.end());
            if (a[25] == 0) {
                sum = sum - (n + 1) + nonZeroCount;
                break;
            }
        }
        return sum;
    }
    
    int leastInterval1(vector<char>& tasks, int n) {
        // 优先级队列
        unordered_map<char, int> umap;
        for (auto c : tasks) {
            umap[c]++;
        }
        priority_queue<int> pq;
        for (auto a : umap) {
            pq.push(a.second);
        }
        int sum = 0;
        while (!pq.empty()) {
            int cnt = 0;
            vector<int> finishedTasks;
            for (int i = 0; i < n + 1; i++) {
                if (!pq.empty()) {
                    int a = pq.top();
                    finishedTasks.push_back(a);
                    cnt++;
                    pq.pop();
                }
            }
            for (auto i : finishedTasks) {
                if (i - 1 > 0) {
                    pq.push(i - 1);
                }
            }
            sum += pq.empty() ? cnt : (n + 1);
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
//    ["A","A","A","A","A","A","B","C","D","E","F","G"]
    vector<char> task = {'A','A','A','B','B','B'};
//    task = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    int n = 2;
    Solution so = Solution();
    int res = so.leastInterval1(task, n);
    cout << res << endl;
    return 0;
}
