//
//  main.cpp
//  Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        // 中序遍历，查看是否递增
        stack<TreeNode *> st;
        long curVal = LONG_MIN;
        TreeNode *currNode = root;
        while (currNode || !st.empty()) {
            while (currNode) {
                st.push(currNode);
                currNode = currNode->left;
            }
            currNode = st.top();
            st.pop();
            if (currNode->val <= curVal) {
                return false;
            }
            curVal = currNode->val;
            currNode = currNode->right;
        }
        return true;
    }
    
    bool isValidBST1(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
    
    bool helper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) {
            return true;
        }
        if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
            return false;
        }
        return helper(root->left, minNode, root) && helper(root->right, root, maxNode);
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
    
    bool ret = so.isValidBST1(p1);
    cout << ret << endl;
    
    return 0;
}

