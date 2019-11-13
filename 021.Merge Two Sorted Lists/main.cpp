//
//  main.cpp
//  Merge Two Sorted Lists
//
//  Created by 刘昭 on 2019/11/13.
//  Copyright © 2019 刘昭. All rights reserved.
//

#include <iostream>
#include "Solution.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(4);
    ListNode *n4 = new ListNode(1);
    ListNode *n5 = new ListNode(3);
    ListNode *n6 = new ListNode(4);
    
    n1->next = n2;
    n2->next = n3;
    
    n4->next = n5;
    n5->next = n6;
    
    ListNode *h1 = n1;
    ListNode *h2 = n4;
    
    Solution solution = Solution();
    ListNode *result = solution.mergeTwoLists(h1, h2);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    
    return 0;
}
