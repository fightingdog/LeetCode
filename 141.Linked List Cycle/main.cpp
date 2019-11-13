//
//  main.cpp
//  Linked List Cycle
//
//  Created by 刘昭 on 2019/11/13.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include "Solution.hpp"

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
//    node5->next = node2;
    
    Solution solution = Solution();
    bool hasCycle = solution.hasCycle1(node1);
    std::cout << hasCycle << std::endl;
    return 0;
}
