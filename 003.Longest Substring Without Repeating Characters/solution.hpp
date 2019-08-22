//
//  solution.hpp
//  003.longest_substring_without_repeating_characters
//
//  Created by liuzhao on 2019/8/22.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int i = 0, j = 0;
        map<char, int> tempMap;
        while(j < s.length()) {
            auto found = tempMap.find(s[j]);
            if (found != tempMap.end()) {
                i = max(tempMap[s[j]] + 1, i);
            }
            result = max(result, j - i + 1);
            tempMap[s[j]] = j;
            j++;
        }
        return result;
    }
};

#endif /* solution_hpp */
