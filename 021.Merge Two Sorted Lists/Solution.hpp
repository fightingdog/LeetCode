//
//  Solution.hpp
//  Merge Two Sorted Lists
//
//  Created by 刘昭 on 2019/11/13.
//  Copyright © 2019 刘昭. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>

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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode *head = new ListNode(-1);
        ListNode *s = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                s->next = l1;
                l1 = l1->next;
            } else {
                s->next = l2;
                l2 = l2->next;
            }
            s = s->next;
        }
        if (l1 == NULL) {
            while (l2 != NULL) {
                s->next = l2;
                l2 = l2->next;
                s = s->next;
            }
        } else {
            while (l1 != NULL) {
                s->next = l1;
                l1 = l1->next;
                s = s->next;
            }
        }
        return head->next;
    }
};

#endif /* Solution_hpp */
