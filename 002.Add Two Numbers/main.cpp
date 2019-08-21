//
//  main.cpp
//  add_two_numbers
//
//  Created by liuzhao on 2019/8/21.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include "solution.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ListNode *l1 = new ListNode(2);
    ListNode *cur = l1;
    ListNode *temp = new ListNode(4);
    cur->next = temp;
    cur = cur->next;
    temp = new ListNode(3);
    cur->next = temp;
    cur = cur->next;
    
    ListNode *l2 = new ListNode(5);
    cur = l2;
    temp = new ListNode(6);
    cur->next = temp;
    cur = cur->next;
    temp = new ListNode(4);
    cur->next = temp;
    cur = cur->next;
    
    Solution solution = Solution();
    ListNode *result = solution.addTwoNumbers(l1, l2);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    
    return 0;
}
