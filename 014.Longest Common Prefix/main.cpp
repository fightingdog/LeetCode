//
//  main.cpp
//  Longest Common Prefix
//
//  Created by liuzhao on 2019/11/26.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        char c;
        int cnt = 0;
        while (1) {
            if (strs[0].size() <= cnt) {
                break;
            } else {
                c = strs[0][cnt];
            }
            int i = 0;
            for (; i < strs.size(); i++) {
                string s = strs[i];
                if (s.size() <= cnt || s[cnt] != c) {
                    break;
                }
            }
            if (i < strs.size()) {
                break;
            }
            cnt++;
        }
        return strs[0].substr(0, cnt);
    }
};

int main(int argc, const char * argv[]) {
//    vector<string> strs = {"flower", "flow", "flight"};
    vector<string> strs = {"dog","racecar","car"};
    Solution so = Solution();
    string ret = so.longestCommonPrefix(strs);
    cout << ret << endl;
    return 0;
}
