//
//  main.cpp
//  Path Sum II
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
    vector<vector<int>> ret;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> curPath;
        helper1(root, sum, curPath);
        return ret;
    }
    
    void helper(TreeNode *root, int sum, vector<int>& curPath) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            curPath.push_back(root->val);
            ret.push_back(curPath);
            curPath.pop_back();
            return;
        }
        
        curPath.push_back(root->val);
        if (root->left) {
            helper(root->left, sum - root->val, curPath);
        }
        if (root->right) {
            helper(root->right, sum - root->val, curPath);
        }
        curPath.pop_back();
    }
    
    void helper1(TreeNode *root, int sum, vector<int>& curPath) {
        if (!root) {
            return;
        }
        curPath.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) {
            ret.push_back(curPath);
        }
        helper1(root->left, sum - root->val, curPath);
        helper1(root->right, sum - root->val, curPath);
        curPath.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    
    TreeNode *q1 = new TreeNode(1);
    TreeNode *q2 = new TreeNode(2);
    TreeNode *q3 = new TreeNode(3);
    
    p1->left = p2;
    p1->right = p3;
    
    q1->left = q2;
    q1->right = q3;
    
    int sum = 4;
    
    Solution so = Solution();
    vector<vector<int>> ret = so.pathSum(p1, sum);;
    for (vector<int> vec : ret) {
        for (int i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
