//
//  Solution.h
//  LeetCode
//
//  Created by QuNing on 27/2/17.
//  Copyright © 2017年 QuNing. All rights reserved.
//

#ifndef Solution_h
#define Solution_h

#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int trailingZeroes(int n);
    vector<int> countSmaller(vector<int>& nums);
    ListNode* oddEvenList(ListNode* head);
    //62. Unique Paths
    int uniquePaths(int m, int n);
    //189. Rotate Array
    void rotate(vector<int>& nums, int k);
    void rollback(vector<int>& nums, int start, int end);
    //77. Combinations
    vector<vector<int>> combine(int n, int k);
    
    //39. Combination Sum
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    void combinationSum(vector<vector<int>>& result, vector<int> usedNums, vector<int>& candidates, int target, int maxIndex);
    
    //143. Reorder List
    void reorderList(ListNode* head);
    //226. Invert Binary Tree
    TreeNode* invertTree(TreeNode* root);
};
#endif /* Solution_h */
