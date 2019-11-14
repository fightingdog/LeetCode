//
//  main.cpp
//  Next Greater Element I
//
//  Created by liuzhao on 2019/11/14.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 单调栈的应用
        stack<int> st;
        map<int, int> sMap;
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                sMap[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while (!st.empty()) {
            sMap[st.top()] = -1;
            st.pop();
        }
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            res.push_back(sMap[nums1[i]]);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution so = Solution();
    vector<int> res = so.nextGreaterElement(nums1, nums2);
    for (auto r : res) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}
