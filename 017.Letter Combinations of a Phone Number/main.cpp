//
//  main.cpp
//  Letter Combinations of a Phone Number
//
//  Created by liuzhao on 2019/11/28.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

static map<char, string> sMap = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return {};
        }
        vector<string> ret;
        int n = (int)digits.length();
        string s(n, ' ');
        letterCombinations(0, n, s, digits, ret);
        return ret;
    }
    
    void letterCombinations(int index, int n, string& curStr, string& digits, vector<string>& ret) {
        if (index == n) {
            ret.push_back(curStr);
        }
        string mapString = sMap[digits[index]];
        for (int i = 0; i < mapString.length(); i++) {
            char c = mapString[i];
            curStr[index] = c;
            letterCombinations(index + 1, n, curStr, digits, ret);
            curStr[index] = ' ';
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution so = Solution();
    string s = "23";
    vector<string> ret = so.letterCombinations(s);
    for (string str : ret) {
        cout << str << "  ";
    }
    cout << endl;
    return 0;
}
