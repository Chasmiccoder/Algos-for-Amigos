/*
Problem:
https://leetcode.com/problems/remove-linked-list-elements/submissions/

Given the head of a linked list and an integer val, 
remove all the nodes of the linked list that has Node.val == val, and return the new head.

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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* current = new ListNode();
        ListNode* previous = new ListNode();
        current = head;
        
        if(head == NULL) {
            return head;
        }
        
        while(current != NULL && current->val == val) {
            current = current->next;
            head = current;
        }
        
        while(current != NULL) {
            if(current->val == val) {
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