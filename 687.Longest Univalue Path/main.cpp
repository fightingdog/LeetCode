//
//  main.cpp
//  Longest Univalue Path
//
//  Created by 刘昭 on 2019/11/17.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <algorithm>

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
    int ret = 0;
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return ret;
    }
    
    int helper(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        int arrowLeft = 0, arrowRight = 0;
        if (root->left != NULL && root->val == root->left->val) {
            arrowLeft = left + 1;
        }
        if (root->right != NULL && root->val == root->right->val) {
            arrowRight = right + 1;
        }
        ret = max(ret, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *n0_0 = new TreeNode(1);
    
    TreeNode *n1_0 = new TreeNode(4);
    TreeNode *n1_1 = new TreeNode(5);
    
    TreeNode *n2_0 = new TreeNode(4);
    TreeNode *n2_1 = new TreeNode(4);
    TreeNode *n2_2 = new TreeNode(5);
    
    n0_0->left = n1_0;
    n0_0->right = n1_1;
    n1_0->left = n2_0;
    n1_0->right = n2_1;
    n1_1->right = n2_2;
    
    Solution so = Solution();
    int ret = so.longestUnivaluePath(n0_0);
    cout << ret << endl;
    
    return 0;
}
