//
//  main.cpp
//  N-Queens
//
//  Created by liuzhao on 2019/11/28.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<int> curRet(n, -1);
        solveNQueues(0, curRet, n, ret);
        return ret;
    }
    
    void solveNQueues(int row, vector<int>& curRet, int n, vector<vector<string>>& ret) {
        if (row == n) {
            // curRet加入到ret中去
            vector<string> stringRet = convetToString(curRet);
            ret.push_back(stringRet);
        }
        for (int i = 0; i < n; i++) {
            if (isOK(row, i, curRet, n)) {
                curRet[row] = i;
                solveNQueues(row + 1, curRet, n, ret);
                curRet[row] = -1;
            }
        }
    }
    
    bool isOK(int row, int pos, vector<int>& curRet, int n) {
        // 检查竖向列
        for (int i = 0; i < row; i++) {
            if (curRet[i] == pos) {
                return false;
            }
        }
        // 检查左斜 & 右斜
        for (int i = row - 1; i >= 0; i--) {
            if (curRet[i] == pos - (row - i) || curRet[i] == pos + (row - i)) {
                return false;
            }
        }
        return true;
    }
    
    vector<string> convetToString(vector<int>& curRet) {
        vector<string> ret;
        for (int i = 0; i < curRet.size(); i++) {
            string s(curRet.size(), '.');
            s[curRet[i]] = 'Q';
            ret.push_back(s);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    int n = 4;
    Solution so = Solution();
    vector<vector<string>> ret = so.solveNQueens(n);
    for (vector<string> sol : ret) {
        for (string s : sol) {
            cout << s << ",";
        }
        cout << endl;
    }
    return 0;
}
