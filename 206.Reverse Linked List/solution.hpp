//
//  solution.hpp
//  Reverse Linked List
//
//  Created by 刘昭 on 2019/11/12.
//  Copyright © 2019 刘昭. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

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
    ListNode* reverseList(ListNode* head) {
        // 头插法
        if (head == NULL) {
            return NULL;
        }
        ListNode *newHead = new ListNode(0);
        ListNode *curPos = head;
        ListNode *next;
        while (curPos != NULL) {
            next = curPos->next;
            curPos->next = newHead->next;
            newHead->next = curPos;
            curPos = next;
        }
        return newHead->next;
    }
    
    ListNode* reverseList1(ListNode* head) {
        // 直接翻转
        if (head == NULL) {
            return NULL;
        }
        ListNode *first = head;
        ListNode *target = first->next;
        while (target != NULL) {
            ListNode *temp = target;
            target = target->next;
            temp->next = head;
            first->next = target;
            head = temp;
        }
        return head;
    }
    
    ListNode* reverseList2(ListNode* head) {
        // 直接翻转
        if (head == NULL) {
            return NULL;
        }
        return reverse(head, head, head->next);
    }
    
    ListNode *reverse(ListNode *head, ListNode *first, ListNode *target) {
        if (target == nullptr) {
            return head;
        }
        first->next = target->next;
        ListNode *temp = target->next;
        target->next = head;
        return reverse(target, first, temp);
    }
};

#endif /* solution_hpp */
