//
//  Solution.hpp
//  Middle of the Linked List
//
//  Created by liuzhao on 2019/11/13.
//  Copyright © 2019 liuzhao. All rights reserved.
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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *s = head, *f = head;
        while (f != NULL) {
            if (f->next == NULL) {
                return s;
            }
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
};

#endif /* Solution_hpp */
