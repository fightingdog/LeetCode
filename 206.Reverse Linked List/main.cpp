//
//  main.cpp
//  Reverse Linked List
//
//  Created by 刘昭 on 2019/11/12.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include "solution.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
    Solution solution = Solution();
    ListNode *result = solution.reverseList2(node1);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    
    return 0;
}
