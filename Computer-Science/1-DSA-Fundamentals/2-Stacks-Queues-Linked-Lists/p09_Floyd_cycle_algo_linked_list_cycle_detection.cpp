/*

Write a program to check whether there is a cycle in a linked list or not
Done with Floyd's Tortoise and Hare Algorithm

Algorithm:
==========
Set the tortoise to the head element
Set the hare to the first node
while the hare is not at the end, or the last node, 
    If the hare has met the tortoise return true (cycle found) 
    move the tortoise by 1 node
    move the hare by 2 nodes
If we've reached the last node without a Hare-Tortoise collision, the
linked list has no cycle

*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert( Node* head_ptr, int element ) {

    Node* temp = new Node;
    temp->data = element;
    temp->next = NULL;

    Node* current;
    current = head_ptr;

    // Traverse to the last node of the list
    while ( current->next != NULL ) {
        current = current->next;
    }

    // Link the node created to the last element
    (*current).next = temp;
}

bool check_cycle( Node* head ) {
    if ( head == NULL || head->next == NULL ) {
        return false;
    }

    Node* tortoise = head;
    Node* hare = head->next;

    while ( hare != NULL && hare->next != NULL ) {

        // If the tortoise meets the hare, we have found a loop in the linked list
        if ( tortoise == hare ) {
            return true;
        }

        // Allow the tortoise to move by 1 step
        tortoise = tortoise->next;

        // Allow the hare to move by 2 steps
        hare = hare->next->next;
    }

    // Loop not found
    return false;
}

int main() {

    // List A
    Node head;
    head.data = 0;
    head.next = NULL;

    insert(&head, 2);
    insert(&head, 6);
    insert(&head, 3);

    Node *current = &head;
    current = current->next->next->next;
    current->next = &head;

    // List B
    Node head2;
    head2.data = 1;
    head2.next = NULL;

    insert(&head2, 7);
    insert(&head2, 9);
    insert(&head2, 0);
    insert(&head2, 4);

    // Check for a cycle in both List A and List B
    if ( check_cycle(&head) ) {
        cout << "List A contains a cycle!\n";
    }
    else {
        cout << "List A does not contain a cycle.\n";
    }

    if ( check_cycle(&head2) ) {
        cout << "List B contains a cycle!\n";
    }
    else {
        cout << "List B does not contain a cycle.\n";
    }
    
    return 0;
}