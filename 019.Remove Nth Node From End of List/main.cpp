//
//  main.cpp
//  Remove Nth Node From End of List
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
//    ListNode *n3 = new ListNode(3);
//    ListNode *n4 = new ListNode(4);
//    ListNode *n5 = new ListNode(5);
    
    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;
    
    Solution solution = Solution();
    ListNode *result = solution.removeNthFromEnd1(n1, 2);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    
    return 0;
}
