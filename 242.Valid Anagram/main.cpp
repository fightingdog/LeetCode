//
//  main.cpp
//  Valid Anagram
//
//  Created by liuzhao on 2019/11/19.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
    
    bool isAnagram1(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<char, int> sMap;
        map<char, int> tMap;
        for (char c : s) {
            sMap[c]++;
        }
        for (char c : t) {
            tMap[c]++;
        }
        
        return sMap == tMap;
    }
};

int main(int argc, const char * argv[]) {
    string s1 = "anagram";
    string s2 = "nagaram";
    Solution so = Solution();
    bool ret = so.isAnagram1(s1, s2);
    cout << ret << endl;
    return 0;
}
