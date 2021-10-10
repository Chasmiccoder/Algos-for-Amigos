/*
Problem:
https://leetcode.com/problems/linked-list-cycle/

Given head, the head of a linked list, determine if the linked list has a cycle in it.
*/

#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Using Floyd's Tortoise and Hare Algorithm

        if(head == NULL || head->next == NULL) {
            return false;
        }
        
        ListNode* tortoise = head;
        ListNode* hare     = head->next;
        
        while(hare != NULL && hare->next != NULL ) {
            if(tortoise == hare) {
                return true;
            }
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        
        return false;
    }
};