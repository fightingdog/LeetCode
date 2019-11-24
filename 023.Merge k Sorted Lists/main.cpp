//
//  main.cpp
//  Merge k Sorted Lists
//
//  Created by 刘昭 on 2019/11/24.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> que;
        for (ListNode *node : lists) {
            if (node) {
                que.push(node);
            }
        }
        if (que.empty()) {
            return NULL;
        }
        ListNode *head = que.top();
        que.pop();
        if (head->next) {
            que.push(head->next);
        }
        ListNode *tail = head;
        while (!que.empty()) {
            tail->next = que.top();
            que.pop();
            tail = tail->next;
            if (tail->next) {
                que.push(tail->next);
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    vector<ListNode *> lists;
    Solution so = Solution();
    ListNode *ret = so.mergeKLists(lists);
    cout << ret << endl;
    return 0;
}
