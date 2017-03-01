//
//  main.cpp
//  LeetCode
//
//  Created by QuNing on 27/2/17.
//  Copyright © 2017年 QuNing. All rights reserved.
//

#include <iostream>
#include "Solution.h"


int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    
    Solution run;
    
//    std::cout << run.trailingZeroes(28) << std::endl;
//    run.rotate(nums, 3);
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    ListNode* l6 = new ListNode(6);
    ListNode* l7 = new ListNode(7);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    run.reorderList(l1);
    return 0;
}
