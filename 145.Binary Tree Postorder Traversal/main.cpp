//
//  main.cpp
//  Binary Tree Preorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        // 根据前序遍历修改得来
        // 前序遍历：根左右，后序遍历：左右根
        // 根左右 (调换左右顺序)-> 根右左 （反转）-> 左右根
        vector<int> ret;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while (curr || !st.empty()) {
            while (curr) {
                ret.push_back(curr->val);
                st.push(curr);
                curr = curr->right;
            }
            curr = st.top();;
            st.pop();
            curr = curr->left;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    vector<int> postorderTraversal1(TreeNode* root) {
        // 添加一个标志位
        vector<int> ret;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        TreeNode *pre = NULL;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            // 若右结点已经访问过或者没有右结点，则输出该结点值
            if (!curr->right || pre == curr->right) {
                ret.push_back(curr->val);
                st.pop();
                pre = curr;
                curr = NULL;
            } else {
                curr = curr->right;
                pre = NULL;
            }
        }
        return ret;
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
    
//    vector<int> ret = so.inorderTraversal(p1);
//    for (int i : ret) {
//        cout << i << " ";
//    }
//    cout << endl;
    
    //    bool ret = so.isValidBST1(p1);
    //    cout << ret << endl;
    
//    int n = 3;
//    int ret = so.numTrees(n);
//    cout << ret << endl;
    
//    int n = 3;
//    vector<TreeNode *> ret = so.generateTrees(n);
//    for (TreeNode* node : ret) {
//        cout << node << endl;
//    }
    
    vector<int> ret = so.postorderTraversal(p1);
    for (int i : ret) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}

