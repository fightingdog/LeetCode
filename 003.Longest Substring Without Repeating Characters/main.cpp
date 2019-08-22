//
//  main.cpp
//  003.longest_substring_without_repeating_characters
//
//  Created by liuzhao on 2019/8/22.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include "solution.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution = Solution();
    string s = "abba";
    int result = solution.lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}
