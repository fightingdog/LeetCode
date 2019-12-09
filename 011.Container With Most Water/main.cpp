//
//  main.cpp
//  Container With Most Water
//
//  Created by liuzhao on 2019/12/9.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = (int)height.size() - 1;
        int maxArea = 0;
        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            maxArea = max(maxArea, area);
            height[i] < height[j] ? i++ : j--;
        }
        return maxArea;
    }
};

int main(int argc, const char * argv[]) {
    Solution so = Solution();
//    vector<int> height = {1,8,6,2,5,4,8,3,7};
    vector<int> height = {1,2,4,3};
    height = {1,3,2,5,25,24,5};
    int ret = so.maxArea(height);
    cout << ret << endl;
    return 0;
}
