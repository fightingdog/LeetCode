//
//  main.cpp
//  Maximum Depth of Binary Tree
//
//  Created by liuzhao on 2019/11/22.
//  Copyright © 2019 liuzhao. All rights reserved.
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
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
    int ret = so.maxDepth(p1);
    cout << ret << endl;
    return 0;
}
