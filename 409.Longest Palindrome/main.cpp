//
//  main.cpp
//  Longest Palindrome
//
//  Created by liuzhao on 2019/11/26.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> sMap;
        for (char c : s) {
            sMap[c]++;
        }
        int ret = 0;
        bool hasSingle = false;
        for (pair<char, int> p : sMap) {
            if (p.second % 2 == 0) {
                ret += p.second;
            } else {
                hasSingle = true;
                ret += (p.second / 2) * 2;
            }
        }
        if (hasSingle) {
            ret++;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    string s = "ccc";
    Solution so = Solution();
    int ret = so.longestPalindrome(s);
    cout << ret << endl;
    return 0;
}
