//
//  main.cpp
//  Path Sum
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            return true;
        }
        bool leftRet = false, rightRet = false;
        if (root->left) {
            leftRet = hasPathSum(root->left, sum - root->val);
        }
        if (root->right) {
            rightRet = hasPathSum(root->right, sum - root->val);
        }
        return leftRet || rightRet;
    }
    
    bool hasPathSum1(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        sum -= root->val;
        if (root->left == NULL && root->right == NULL) {
            return sum == 0;
        }
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
    
    bool hasPathSum2(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        stack<pair<TreeNode *, int>> st;
        st.push(make_pair(root, sum));
        while (!st.empty()) {
            pair<TreeNode *, int> p = st.top();
            st.pop();
            TreeNode *node = p.first;
            int curSum = p.second;
            if (node->left == NULL && node->right == NULL && curSum == node->val) {
                return true;
            }
            if (node->right) {
                st.push(make_pair(node->right, curSum - node->val));
            }
            if (node->left) {
                st.push(make_pair(node->left, curSum - node->val));
            }
        }
        return false;
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
    bool ret = so.hasPathSum2(p1, sum);;
    cout << ret << endl;
    return 0;
}
