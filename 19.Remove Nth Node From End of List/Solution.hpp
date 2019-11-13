//
//  Solution.hpp
//  Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 直接寻找倒数第n个节点
        if (head == NULL || n <= 0) {
            return head;
        }
        int i = 1;
        ListNode *f = head, *s = head;
        ListNode *p = head;
        while (i <= n && f != NULL) {
            f = f->next;
            i++;
        }
        if (f == NULL) {
            // 删除头结点
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while (f != NULL) {
            p = s;
            f = f->next;
            s = s->next;
        }
        ListNode *temp = s;
        p->next = s->next;
        delete temp;
        return head;
    }
    
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        // 插入一个头结点
        if (head == NULL || n <= 0) {
            return head;
        }
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *p = dummyHead;
        ListNode *q = dummyHead;
        for (int i = 0; i < n + 1; i++) {
            q = q->next;
        }
        while (q) {
            q = q->next;
            p = p->next;
        }
        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};

#endif /* Solution_hpp */
