//
//  main.cpp
//  005.longest_pralindromic_substring
//
//  Created by 刘昭 on 2019/8/26.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <vector>
#include "solution.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here.""..
    vector<string> testArray;
    testArray.push_back("cbbd");
    testArray.push_back("babad");
    for (auto s : testArray) {
        string r = Solution().longestPalindrome(s);
        cout << r << endl;
    }
    
    return 0;
}
