//
//  solution.hpp
//  005.longest_pralindromic_substring
//
//  Created by 刘昭 on 2019/8/26.
//  Copyright © 2019 刘昭. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
    void longestPalindrome(const string &s, int b, int e, int &start, int &end) {
        int len = s.size();
        while(b >= 0 && e < len && s[b] == s[e]) {
            b--;
            e++;
        }
        ++b;
        --e;
        if (e - b + 1 > end - start + 1) {
            end = e;
            start = b;
        }
    }
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0) {
            return s;
        }
        int start = 0, end = 0;
        for (int i = 0; i < len - 1; i++) {
            longestPalindrome(s, i, i, start, end);
            longestPalindrome(s, i, i+1, start, end);
        }
        return s.substr(start, end - start + 1);
    }
};

#endif /* solution_hpp */
