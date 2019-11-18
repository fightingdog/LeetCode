//
//  main.cpp
//  Range Sum of BST
//
//  Created by liuzhao on 2019/11/18.
//  Copyright © 2019 liuzhao. All rights reserved.
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
    int sum = 0;
    int rangeSumBST(TreeNode* root, int L, int R) {
        inOrderTraverse(root, L, R);
        return sum;
    }
    
    void inOrderTraverse(TreeNode *root, int L, int R) {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            inOrderTraverse(root->left, L, R);
        }
        if (root->val >= L && root->val <= R) {
            sum += root->val;
        }
        if (root->val > R) {
            return;
        }
        if (root->right) {
            inOrderTraverse(root->right, L, R);
        }
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *n0_0 = new TreeNode(10);
    
    TreeNode *n1_0 = new TreeNode(5);
    TreeNode *n1_1 = new TreeNode(15);
    
    TreeNode *n2_0 = new TreeNode(3);
    TreeNode *n2_1 = new TreeNode(7);
//    TreeNode *n2_2 = new TreeNode(5);
    TreeNode *n2_3 = new TreeNode(18);
    
//    TreeNode *n3_1 = new TreeNode(52);
    
    n0_0->left = n1_0;
    n0_0->right = n1_1;
    
    n1_0->left = n2_0;
    n1_0->right = n2_1;
    n1_1->right = n2_3;
//    n1_1->right = n2_2;
//    n2_0->right = n3_1;
    
    Solution so = Solution();
    int ret = so.rangeSumBST(n0_0, 7, 15);
    cout << ret << endl;
    
    return 0;
}
