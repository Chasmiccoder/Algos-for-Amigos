/*
Problem:
https://leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a sorted list. 
The list should be made by splicing together the nodes of the first two lists.
*/

#include <iostream>


using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* current = new ListNode();
        head = current;
        
        ListNode* firstList = l1;
        ListNode* secondList = l2;
        
        while(firstList != NULL && secondList != NULL) {
            
            if(firstList->val < secondList->val) {
                current->next = new ListNode(firstList->val);
                current = current->next;
                firstList = firstList->next;
            }
            else {                
                current->next = new ListNode(secondList->val);
                current = current->next;
                secondList = secondList->next;
            }
        }
        
        while(firstList != NULL) {
            current->next = new ListNode(firstList->val);
            current = current->next;
            firstList = firstList->next;
        }
        
        while(secondList != NULL) {
            current->next = new ListNode(secondList->val);
            current = current->next;
            secondList = secondList->next;
        }
        
        return head->next;
    }
};