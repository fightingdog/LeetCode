//
//  main.cpp
//  Unique Binary Search Trees
//
//  Created by liuzhao on 2019/11/23.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include <queue>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int numTrees(int n) {
        // 卡特兰数
        vector<int> ret(n+1, 0);
        ret[0] = 1;
        ret[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                ret[i] += ret[j-1] * ret[i - j];
            }
        }
        return ret[n];
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(1);
    TreeNode *p3 = new TreeNode(3);
    
    TreeNode *q1 = new TreeNode(1);
    TreeNode *q2 = new TreeNode(2);
    TreeNode *q3 = new TreeNode(3);
    
    p1->left = p2;
    p1->right = p3;
    
    q1->left = q2;
    q1->right = q3;
    
    Solution so = Solution();
    
//    vector<int> ret = so.inorderTraversal(p1);
//    for (int i : ret) {
//        cout << i << " ";
//    }
//    cout << endl;
    
//    bool ret = so.isValidBST1(p1);
//    cout << ret << endl;
    
    int n = 3;
    int ret = so.numTrees(n);
    cout << ret << endl;
    
    return 0;
}
