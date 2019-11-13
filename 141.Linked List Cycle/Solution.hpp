//
//  Solution.hpp
//  Linked List Cycle
//
//  Created by 刘昭 on 2019/11/13.
//  Copyright © 2019 刘昭. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <set>

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

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *s = head;
        ListNode *f = head;
        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;
            if (s == f) {
                return true;
            }
        }
        return false;
    }
    
    bool hasCycle1(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        set<ListNode *> a;
        ListNode *s = head;
        while (s != NULL) {
            if (a.find(s) != a.end()) {
                return true;
            }
            a.insert(s);
            s = s->next;
        }
        return false;
    }
};

#endif /* Solution_hpp */
