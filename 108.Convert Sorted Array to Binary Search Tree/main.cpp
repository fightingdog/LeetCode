//
//  main.cpp
//  Convert Sorted Array to Binary Search Tree
//
//  Created by liuzhao on 2019/11/23.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }
        return helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int mid = left + ((right - left) >> 1);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution so = Solution();
    TreeNode *root = so.sortedArrayToBST(nums);
    cout << root << endl;
    return 0;
}
