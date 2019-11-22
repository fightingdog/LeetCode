//
//  main.cpp
//  Symmetric Tree
//
//  Created by liuzhao on 2019/11/22.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <queue>

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
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    bool isMirror(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if (p == NULL || q == NULL) {
            return false;
        } else {
            if (p->val != q->val) {
                return false;
            } else {
                return isMirror(p->left, q->right) && isMirror(p->right, q->left);
            }
        }
    }
    
    bool isSymmetric1(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        queue<TreeNode *> que;
        que.push(root);
        que.push(root);
        while (!que.empty()) {
            TreeNode *p = que.front();
            que.pop();
            TreeNode *q = que.front();
            que.pop();
            if (p == NULL && q == NULL) {
                continue;
            } else if (p == NULL || q == NULL) {
                return false;
            } else {
                if (p->val != q->val) {
                    return false;
                } else {
                    que.push(p->left);
                    que.push(q->right);
                    que.push(p->right);
                    que.push(q->left);
                }
            }
        }
        return true;
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
    
    Solution so = Solution();
    bool ret = so.isSymmetric1(p1);
    cout << ret << endl;
    return 0;
}
