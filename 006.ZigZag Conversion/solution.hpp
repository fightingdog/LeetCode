//
//  solution.hpp
//  006.zigzag_conversion
//
//  Created by liuzhao on 2019/8/27.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || numRows == 0 || numRows == 1) {
            return s;
        }
        vector<string> rows(min(numRows, (int)s.size()));
        int curRow = 0;
        bool bDown = false;
        
        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                bDown = !bDown;
            }
            curRow += bDown ? 1 : -1;
        }
        
        string ret;
        for (string row : rows) {
            ret += row;
        }
        return ret;
    }
};

#endif /* solution_hpp */
