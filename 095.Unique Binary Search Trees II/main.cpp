//
//  main.cpp
//  Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        vector<TreeNode *> ans = dfs(1, n);
        return ans;
    }
    
    vector<TreeNode*> dfs(int x, int y) {
        vector<TreeNode *> ans;
        if (x > y) {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = x; i <= y; i++) {
            vector<TreeNode *> left = dfs(x, i - 1);
            vector<TreeNode *> right = dfs(i + 1, y);;
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *root = new TreeNode(i);;
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
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
//    p1->right = p3;
    
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
    
//    int n = 3;
//    int ret = so.numTrees(n);
//    cout << ret << endl;
    
    int n = 3;
    vector<TreeNode *> ret = so.generateTrees(n);
    for (TreeNode* node : ret) {
        cout << node << endl;
    }
    
    return 0;
}
