//
//  main.cpp
//  Sort Array By Parity II
//
//  Created by liuzhao on 2019/11/19.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int j = 1;
        for (int i = 0; i < A.size(); i = i + 2) {
            if (A[i] % 2 == 1) {
                while (A[j] % 2 == 1) {
                    j = j + 2;
                }
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        return A;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> num = {4, 2, 5, 7};
    Solution so = Solution();
    vector<int> ret = so.sortArrayByParityII(num);
    for (int i : ret) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
