//
//  Solution.hpp
//  Basic Calculator
//
//  Created by 刘昭 on 2019/11/14.
//  Copyright © 2019 刘昭. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st1;
        stack<char> st2;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ' ') {
                continue; // 忽略空格
            } else if (c == '(') {
                st2.push(c); // 左括号直接入栈
            } else if (c == '+' || c == '-') {
                st2.push(c); // 符号直接入栈
            } else if (c >= '0' && c <= '9') {
                int n = c - '0';
                // 拼接多位数字
                int j = i + 1;
                while (j < s.size()) {
                    if (s[j] >= '0' && s[j] <= '9') {
                        n = n * 10 + (s[j] - '0');
                    } else {
                        break;
                    }
                    j++;
                }
                i = j - 1;
                
                if (!st2.empty()) {
                    char c1 = st2.top();
                    if (c1 == '(') {
                        st1.push(n);
                    } else {
                        // 计算值
                        if (st1.empty()) {
                            st1.push(n);
                        } else {
                            int top = st1.top();
                            st1.pop();
                            char sig = st2.top();
                            if (sig == '+') {
                                int res = top + n;
                                st1.push(res);
                                st2.pop();
                            } else if (sig == '-') {
                                int res = top - n;
                                st1.push(res);
                                st2.pop();
                            }
                        }
                    }
                } else {
                    st1.push(n);
                }
            } else if (c == ')') {
                st2.pop();
                if (!st1.empty()) {
                    int num1 = st1.top();
                    st1.pop();
                    if (!st1.empty()) {
                        int num2 = st1.top();
                        st1.pop();
                        if (!st2.empty()) {
                            char sig = st2.top();
                            if (sig == '+') {
                                int res = num2 + num1;
                                st1.push(res);
                                st2.pop();
                            } else if (sig == '-') {
                                int res = num2 - num1;
                                st1.push(res);
                                st2.pop();
                            }
                        } else {
                            st1.push(num2);
                        }
                    } else {
                        st1.push(num1);
                    }
                }
            }
        }
        return st1.top();
    }
    
    int calculate1(string s) {
        stack<int> st1;
        stack<char> st2;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ' ') {
                continue;
            } else if (c == '(') {
                st2.push(c);
            } else if (c == '+' || c == '-' || c == ')') {
                while (!st2.empty() && (st2.top() == '+' || st2.top() == '-')) {
                    int a = st1.top();
                    st1.pop();
                    int b = st1.top();
                    st1.pop();
                    char op = st2.top();
                    st2.pop();
                    if (op == '+') {
                        st1.push(b + a);
                    } else if (op == '-') {
                        st1.push(b - a);
                    }
                }
                if (c == ')') {
                    if (!st2.empty() && st2.top() == '(') {
                        st2.pop();
                    }
                } else {
                    st2.push(c);
                }
            } else {
                int dig = c - '0';
                int j = i + 1;
                while (s[j] >= '0' && s[j] <= '9') {
                    dig = dig * 10 + (s[j] - '0');
                    j++;
                }
                i = j - 1;
                
                st1.push(dig);
            }
        }
        while (!st2.empty()) {
            int a = st1.top();
            st1.pop();
            int b = st1.top();
            st1.pop();
            char op = st2.top();
            st2.pop();
            if (op == '+') {
                st1.push(b + a);
            } else if (op == '-') {
                st1.push(b - a);
            }
        }
        return st1.top();
    }
};

#endif /* Solution_hpp */
