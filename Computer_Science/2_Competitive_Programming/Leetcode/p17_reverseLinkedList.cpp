/*
https://leetcode.com/problems/reverse-linked-list

Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* previous = new ListNode();
        ListNode* current  = new ListNode();
        ListNode* nextNode = new ListNode();
        
        previous = NULL;
        current  = head;
        
        while(current != NULL) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        
        return previous;    
        
    }
};