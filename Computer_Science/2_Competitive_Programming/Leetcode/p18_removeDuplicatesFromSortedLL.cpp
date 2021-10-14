/*
Problem:
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* current = new ListNode();
        current = head->next;
        ListNode* previous = new ListNode();
        previous = head;
        
        while(current != NULL) {
            if(previous->val == current->val) {
                previous->next = current->next;
                current = current->next;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
        
        return head;   
    }
};