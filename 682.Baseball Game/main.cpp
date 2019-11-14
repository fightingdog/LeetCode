//
//  main.cpp
//  Baseball Game
//
//  Created by liuzhao on 2019/11/14.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for (int i = 0; i < ops.size(); i++) {
            string s = ops[i];
            if (s == "C") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (s == "+") {
                if (!st.empty()) {
                    int n1 = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int n2 = st.top();
                        st.push(n1);
                        st.push(n1 + n2);
                    } else {
                        st.push(n1);
                    }
                }
            } else if (s == "D") {
                if (!st.empty()) {
                    int n1 = st.top();
                    st.push(n1 * 2);
                }
            } else {
                st.push(stoi(s));
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    Solution so = Solution();
    int res = so.calPoints(ops);
    cout << res << endl;
    return 0;
}
