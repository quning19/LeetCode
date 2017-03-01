//
//  Solution.cpp
//  LeetCode
//
//  Created by QuNing on 27/2/17.
//  Copyright © 2017年 QuNing. All rights reserved.
//

#include <stdio.h>
#include "Solution.h"

int Solution::trailingZeroes(int n) {
    int totalZeroes = 0;
    while (n > 0)
    {
        n = n / 5;
        totalZeroes += n;
    }
    return totalZeroes;
}

vector<int> Solution::countSmaller(vector<int>& nums){
    vector<int> result;
    for (int i = 0; i < nums.capacity(); i++)
    {
        result.push_back(0);
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[i])
                result[j] ++;
        }
    }
    return result;
}

ListNode* Solution::oddEvenList(ListNode* head){
    ListNode* currentNode = head;
    ListNode* oddEndNode = head;
    int index = 1;
    while (currentNode != nullptr && currentNode->next != nullptr)
    {
        if (index % 2 == 0)
        {
            ListNode* cache = currentNode->next;
            currentNode->next = currentNode->next->next;
            cache->next = oddEndNode->next;
            oddEndNode->next = cache;
            oddEndNode = cache;
        }
        else
            currentNode = currentNode->next;
        index++;
    }
    
    return head;
}

int Solution::uniquePaths(int m, int n){
    if (m == 1 or n == 1)
        return 1;
    return uniquePaths(m-1, n) + uniquePaths(m, n-1);
}

void Solution::rotate(vector<int>& nums, int k)
{
    k = k % nums.size();
    rollback(nums, 0, nums.size());
    rollback(nums, 0, k);
    rollback(nums, k, nums.size() - k);
}

void Solution::rollback(vector<int>& nums, int start, int cnt)
{
    for (int i = 0; i<cnt/2;i++)
    {
        int num = nums[start + i];
        nums[start + i] = nums[start + cnt - i - 1];
        nums[start + cnt - i - 1] = num;
    }
}

vector<vector<int>> Solution::combine(int n, int k){
    vector<vector<int>> res1;
    vector<vector<int>> res2;
    if (n > k)
        res1 = combine(n-1, k);
    if (k > 1)
        res2 = combine(n-1, k -1);
    else
        res2 = vector<vector<int>>(1);
    for (int i = 0; i<res2.size(); i++)
    {
        vector<int> arr = res2[i];
        arr.push_back(n);
        res1.push_back(arr);
    }
    
    return res1;
}


vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> result;
    vector<int> usedNums;
    combinationSum(result, usedNums, candidates, target, candidates.size());
    
    return result;
}
void Solution::combinationSum(vector<vector<int>>& result, vector<int> usedNums, vector<int>& candidates, int target, int maxIndex){
    if (target < 0)
        return;
    if (target == 0)
    {
        result.push_back(usedNums);
        return;
    }
    for (int i = 0;i < maxIndex; i++)
    {
        usedNums.push_back(candidates[i]);
        combinationSum(result, usedNums, candidates, target - candidates[i], i + 1);
        usedNums.pop_back();
    }
}

void Solution::reorderList(ListNode* head){
    // find middle node
    if (head == NULL)
        return;
    ListNode* middleNode = head;
    ListNode* node = head;
    while(node != NULL && node->next != NULL)
    {
        middleNode = middleNode->next;
        node = node->next->next;
    }
    //revert last half
    node = middleNode->next ;
    while(node != NULL && node->next != NULL)
    {
        ListNode* temp;
        temp = node->next;
        node->next = temp->next;
        temp->next = middleNode->next;
        middleNode->next = temp;
    }
    //merge together
    node = head;
    while (middleNode != NULL && middleNode->next != NULL)
    {
        ListNode* temp;
        temp = middleNode->next;
        middleNode->next = temp->next;
        temp->next = node->next;
        node->next = temp;
        node = temp->next;
    }
}


TreeNode* Solution::invertTree(TreeNode* root) {
    return root;
}












