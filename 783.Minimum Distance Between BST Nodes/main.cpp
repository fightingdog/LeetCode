//
//  main.cpp
//  Minimum Distance Between BST Nodes
//
//  Created by 刘昭 on 2019/11/17.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>

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
    int minDiffInBST(TreeNode* root) {
        vector<int> inorderRet = inOrderTraverse(root);
        int ret = 100;
        for (int i = 1; i < inorderRet.size(); i++) {
            int diff = inorderRet[i] - inorderRet[i-1];
            ret = min(ret, diff);
        }
        return ret;
    }
    
    vector<int> inOrderTraverse(TreeNode *root) {
        if (root == NULL) {
            vector<int> ret;
            return ret;
        }
        vector<int> retLeft;
        vector<int> retRight;
        if (root->left) {
            retLeft = inOrderTraverse(root->left);
        }
        if (root->right) {
            retRight = inOrderTraverse(root->right);
        }
        vector<int> ret;
        for (auto a : retLeft) {
            ret.push_back(a);
        }
        ret.push_back(root->val);
        for (auto a : retRight) {
            ret.push_back(a);
        }
        return ret;
    }
};

class Solution1 {
public:
    // 使用一个变量储存上次访问的值
    int pre = -1000;
    int ret = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        inOrderTraverse(root);
        return ret;
    }
    
    void inOrderTraverse(TreeNode *root) {
        if (!root) {
            return;
        }
        inOrderTraverse(root->left);
        ret = min(ret, root->val - pre);
        pre = root->val;
        inOrderTraverse(root->right);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *n0_0 = new TreeNode(90);
    
    TreeNode *n1_0 = new TreeNode(69);
//    TreeNode *n1_1 = new TreeNode(6);
    
    TreeNode *n2_0 = new TreeNode(49);
    TreeNode *n2_1 = new TreeNode(89);
//    TreeNode *n2_2 = new TreeNode(5);
    
    TreeNode *n3_1 = new TreeNode(52);
    
    n0_0->left = n1_0;
//    n0_0->right = n1_1;
//    n1_0->left = n2_0;
    
    n1_0->left = n2_0;
    n1_0->right = n2_1;
//    n1_1->right = n2_2;
    n2_0->right = n3_1;
    
    Solution1 so = Solution1();
    int ret = so.minDiffInBST(n0_0);
    cout << ret << endl;
    
    return 0;
}
