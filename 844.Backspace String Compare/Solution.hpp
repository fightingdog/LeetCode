//
//  Solution.hpp
//  Backspace String Compare
//
//  Created by 刘昭 on 2019/11/14.
//  Copyright © 2019 刘昭. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string S1 = removeBackspace(S);
        string T1 = removeBackspace(T);
        return S1 == T1;
    }
    
    string removeBackspace(string S) {
        stack<char> st;
        for (int i = 0; i < S.size(); i++) {
            char c = S[i];
            if (c == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }
        string res;
        while (!st.empty()) {
            char c = st.top();
            res += c;
            st.pop();
        }
        return res;
    }
};

#endif /* Solution_hpp */
