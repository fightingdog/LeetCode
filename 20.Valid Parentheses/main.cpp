//
//  main.cpp
//  Valid Parentheses
//
//  Created by 刘昭 on 2019/11/13.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include "Solution.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    string s = "{{}}";
    Solution solution = Solution();
    bool res = solution.isValid1(s);
    cout << res << endl;
    return 0;
}
