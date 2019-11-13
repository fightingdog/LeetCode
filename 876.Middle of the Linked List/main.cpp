//
//  main.cpp
//  Middle of the Linked List
//
//  Created by liuzhao on 2019/11/13.
//  Copyright © 2019 liuzhao. All rights reserved.
//

#include <iostream>
#include "Solution.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(6);
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    
    Solution solution = Solution();
    ListNode *result = solution.middleNode(n1);
    std::cout << result->val << std::endl;
    return 0;
}
