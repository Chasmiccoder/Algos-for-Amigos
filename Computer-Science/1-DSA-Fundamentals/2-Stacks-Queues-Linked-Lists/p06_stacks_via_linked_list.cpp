/*
Structure of the Stack: 
The head pointer of the linked list points to the top of the stack
This way, both push() and pop() can happen in constant time
The top of the stack is marked as the head
The top element can be accessed with top->next
*/

#include <iostream>
using namespace std;


struct Node {
    string data;
    Node* next;
};


void push( Node* top_ptr, string element ) {
    /*
    We only need to worry about inserting at the end for the stack implementation
    */
    
    Node* temp = new Node;
    temp->data = element; // can also be: (*temp).data = element;
    temp->next = NULL;

    // If the stack is empty, directly link the new element to the head
    if ( top_ptr->next == NULL ) {
        top_ptr->next = temp;
        return;
    }

    // Link the new node to the old top element
    temp->next = top_ptr->next;
    // Link the head pointer to the new node
    top_ptr->next = temp;
}


string pop( Node* top_ptr ) {
    /*
    Same as deletion of the first Node
    */

    if ( top_ptr->next == NULL ) {
        printf( "Underflow!\n" );
        return "";
    }

    Node* temp = new Node;
    temp = top_ptr->next;

    string element = temp->data;
    // If there is only element in the stack, top_ptr->next gets assigned to NULL
    top_ptr->next = temp->next;
    
    delete temp;
    return element;
}


string peek( Node* top_ptr ) {
    /*
    Returns the top element of the stack
    */
    
    if ( top_ptr->next == NULL ) {
        printf( "No element in Stack!\n" );
        return "";
    }

    Node* temp = new Node;
    temp = top_ptr->next;
    string element = temp->data;
    
    return element;
}


void print_menu() {
    printf( "\nStack Operations:\n" );
    printf( "1 - Push an element into the stack\n" );
    printf( "2 - Pop an element from the stack\n" );
    printf( "3 - Peek top element\n" );
    printf( "0 - Terminate the program\n" );
    printf( "\n" );
}


int main() {
    
    printf( "\nStack Implementation Using Linked List!\n" );

    // Initialization of the stack
    Node* top_ptr = new Node;
    top_ptr->next = NULL;

    while ( true ) {
        print_menu();

        printf( "Enter choice: " );
        int control;
        scanf( "%d", &control );

        if ( control == 0 ) {
            printf( "Thank you for using the program!\n" );
            break;
        }

        else if ( control == 1 ) {
            printf( "Enter element to be inserted: " );
            string element;
            cin >> element;
            push( top_ptr, element );
        }

        else if ( control == 2 ) {
            string element = pop( top_ptr );

            if ( element != "" ) {
                printf( "Popped Element: " );
                cout << element << endl;
            }
        }

        else if ( control == 3 ) {
            string element = peek( top_ptr );

            if ( element != "" ) {
                printf( "Top Element: " );
                cout << element << endl;
            }
        }
    } 

    return 0;
}