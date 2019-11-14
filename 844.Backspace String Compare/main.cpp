//
//  main.cpp
//  Backspace String Compare
//
//  Created by 刘昭 on 2019/11/14.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include "Solution.hpp"

int main(int argc, const char * argv[]) {
//    "y#fo##f"
//    "y#f#o##f"
    string S = "y#fo##f";
    string T = "y#f#o##f";
    Solution so = Solution();
    bool res = so.backspaceCompare(S, T);
    cout << res << endl;
    return 0;
}
