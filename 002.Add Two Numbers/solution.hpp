//
//  solution.hpp
//  add_two_numbers
//
//  Created by liuzhao on 2019/8/21.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        int sum = 0, carry = 0;
        int val1 = 0, val2 = 0;
        while (l1 != NULL || l2 != NULL) {
            val1 = val2 = 0;
            if (l1 != NULL) {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                val2 = l2->val;
                l2 = l2->next;
            }
            sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            ListNode *node = new ListNode(sum);
            cur->next = node;
            cur = cur->next;
        }
        if (carry > 0) {
            ListNode *node = new ListNode(carry);
            cur->next = node;
            cur = cur->next;
        }
        return head->next;
    }
};

#endif /* solution_hpp */
