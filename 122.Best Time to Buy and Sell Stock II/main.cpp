//
//  main.cpp
//  Best Time to Buy and Sell Stock II
//
//  Created by liuzhao on 2019/11/27.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
    
    int maxProfit1(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int maxProfit = 0;
        int i = 0;
        int totalCount = (int)prices.size();
        int valley = prices[0];
        int peak = prices[0];
        while (i < totalCount - 1) {
            while (i < totalCount - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            valley = prices[i];
            while (i < totalCount - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            peak = prices[i];
            maxProfit += peak - valley;
        }
        return maxProfit;
    }
};

int main(int argc, const char * argv[]) {
//    vector<int> prices = {7, 1, 5, 3, 6, 4};
//    vector<int> prices = {1,2,3,4,5};
//    vector<int> prices = {7,6,4,3,1};
    vector<int> prices = {1,4,2};
//    vector<int> prices = {2,1,4};
    Solution so = Solution();
    int ret = so.maxProfit1(prices);
    cout << ret << endl;
    return 0;
}
