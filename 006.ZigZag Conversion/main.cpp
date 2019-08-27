//
//  main.cpp
//  006.zigzag_conversion
//
//  Created by liuzhao on 2019/8/27.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include "solution.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "PAYPALISHIRING";
    Solution solution;
    for (int i = 0; i < 5; i++) {
        string ret1 = solution.convert(s, i);
        cout << ret1 << endl;
    }
    
    return 0;
}
