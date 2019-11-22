//
//  main.cpp
//  Same Tree
//
//  Created by liuzhao on 2019/11/22.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include <deque>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if (p != NULL && q != NULL) {
            if (p->val == q->val) {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    
    bool isSameTree1(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (!check(p, q)) {
            return false;
        }
        deque<TreeNode *> deq;
        deq.push_back(p);
        deq.push_front(q);
        while (!deq.empty()) {
            TreeNode *f = deq.front();
            TreeNode *b = deq.back();
            if (!check(f, b)) {
                return false;
            }
            deq.pop_front();
            deq.pop_back();
            if (f) {
                deq.push_front(f->left);
                deq.push_front(f->right);
                deq.push_back(b->left);
                deq.push_back(b->right);
            }
        }
        return true;
    }
    
    bool check(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if (p == NULL || q == NULL) {
            return false;
        } else {
            if (p->val == q->val) {
                return true;
            } else {
                return false;
            }
        }
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
    bool ret = so.isSameTree1(p1, q1);
    cout << ret << endl;
    
    return 0;
}
