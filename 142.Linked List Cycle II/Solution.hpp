//
//  Solution.hpp
//  Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode *s = head, *f = head;
        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;
            if (s == f) {
                break;
            }
        }
        if (f == NULL || f->next == NULL) {
            return NULL;
        } else {
            ListNode *t = head;
            while (s != t) {
                s = s->next;
                t = t->next;
            }
            return s;
        }
    }
};

#endif /* Solution_hpp */
