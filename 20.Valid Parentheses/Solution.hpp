//
//  Solution.hpp
//  Valid Parentheses
//
//  Created by 刘昭 on 2019/11/13.
//  Copyright © 2019 刘昭. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <string>
#include <stack>
#include <map>

using namespace std;

// ()[]{}
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else if (c == ')') {
                if (stack.empty()) {
                    return false;
                }
                char r = stack.top();
                if (r == '(') {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (c == ']') {
                if (stack.empty()) {
                    return false;
                }
                char r = stack.top();
                if (r == '[') {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (c == '}') {
                if (stack.empty()) {
                    return false;
                }
                char r = stack.top();
                if (r == '{') {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        if (!stack.empty()) {
            return false;
        }
        return true;
    }
    
    bool isValid1(string s) {
        if (s.empty()) {
            return true;
        }
        map<char, char> sMap = {{')', '('},
                                {'}', '{'},
                                {']', '['}};
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                if (sMap[s[i]] != st.top()) {
                    st.push(s[i]);
                } else {
                    st.pop();
                }
            }
            if (st.size() > s.size() / 2) {
                return false;
            }
        }
        return st.empty();
    }
};


#endif /* Solution_hpp */
