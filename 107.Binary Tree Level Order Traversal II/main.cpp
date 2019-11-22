//
//  main.cpp
//  Binary Tree Level Order Traversal II
//
//  Created by 刘昭 on 2019/11/22.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        queue<TreeNode *> que;
        vector<vector<int>> ret;
        que.push(root);
        while (!que.empty()) {
            vector<int> curLevel;
            vector<TreeNode *> curLevelNode;
            while (!que.empty()) {
                TreeNode *node = que.front();
                que.pop();
                curLevel.push_back(node->val);
                curLevelNode.push_back(node);
            }
            for (TreeNode *node : curLevelNode) {
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            ret.push_back(curLevel);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    vector<vector<int>> levelOrder1(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        queue<TreeNode *> que;
        vector<vector<int>> ret;
        que.push(root);
        while (!que.empty()) {
            vector<int> curLevel;
            vector<TreeNode *> curLevelNode;
            int curSize = (int)que.size();
            for (int i = 0; i < curSize; i++) {
                TreeNode *node = que.front();
                que.pop();
                curLevel.push_back(node->val);
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            ret.push_back(curLevel);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    // 递归解法
    vector<vector<int>> ret;
    vector<vector<int>> levelOrder2(TreeNode* root) {
        if (root == NULL) {
            return ret;
        }
        helper(root, 0);
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    void helper(TreeNode *node, int level) {
        if (level == (int)ret.size()) {
            vector<int> curLevel;
            ret.push_back(curLevel);
        }
        vector<int> &curLevel = ret[level];
        curLevel.push_back(node->val);
        if (node->left) {
            helper(node->left, level + 1);
        }
        if (node->right) {
            helper(node->right, level + 1);
        }
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
    vector<vector<int>> ret = so.levelOrder2(n0_0);
    for (vector<int> vec : ret) {
        for (int i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}
