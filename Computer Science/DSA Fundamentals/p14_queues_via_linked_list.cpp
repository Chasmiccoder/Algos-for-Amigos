/*

Structure of the Queue:
=======================
The front of the queue is the first element of the linked list
The front pointer is the head pointer
The rear of the queue is the last element of the linked list, given by the rear pointer

*/

#include <iostream>
using namespace std;


struct Node{
    string data;
    Node* next;
};


void enqueue( Node* front, Node* rear, string element ) {
    /*
    Function to enqueue an element at the rear of the Queue
    Separately saves the last element enqueued into the rear pointer
    */

    // If the Queue is empty
    if ( front->next == NULL ) {
        Node* temp = new Node;
        temp->data = element;
        temp->next = NULL;
        
        front->next = temp;
        
        // Need to specifically assign rear pointer
        rear->data = element;
        rear->next = NULL;
        
        return;
    }

    Node* current = new Node;
    current = front->next;
    while ( current->next != NULL ) {
        current = current->next;
    }

    Node* temp = new Node;
    temp->data = element;
    temp->next = NULL;

    current->next = temp;

    rear->data = element;
    rear->next = NULL;

}


string dequeue( Node* front, Node* rear ) {
    /*
    Function to Dequeue the first element in the Queue
    */

    // If there is no element in the Queue
    if ( front->next == NULL ) {
        printf( "Underflow!\n" );
        return "";
    }

    Node* temp = new Node;
    temp = front->next;

    // If there is only one element in the Queue, front->next gets assigned to NULL
    front->next = temp->next;
    string element = temp->data;
    delete temp;
    return element;

}


void print_front_and_rear( Node* front, Node* rear ) {
    /*
    Prints the front and rear elements in the Queue
    */

    if ( front->next == NULL ) {
        printf( "Queue is empty\n" );
        return;
    }

    Node* temp = new Node;
    temp = front->next;
    string front_element = temp->data;

    printf( "Front Element: " );
    cout << front_element << endl;

    // If the Queue has more than 1 element, print the rear
    if ( temp->next != NULL ) {
        string rear_element = rear->data;
        printf( "Rear Element: " );
        cout << rear_element << endl;
    }
}


void print_menu() {
    printf( "\nOperations:\n" );
    printf( "1 - Enqueue an element\n" );
    printf( "2 - Dequeue the front element\n" );
    printf( "3 - Print the Front and Rear Elements\n" );
    printf( "0 - Terminate the Program\n" );
    printf( "\n" );
}


int main() {

    printf( "\nQueue Implementation with Linked List!\n" );

    // Initialization of the Queue
    Node front;
    Node rear;

    front.next = NULL;

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
            string element;
            printf( "Enter element to be enqueued: " );
            cin >> element;
            enqueue( &front, &rear, element );
        }

        else if ( control == 2 ) {
            string element = dequeue( &front, &rear );
            if ( element != "" ) {
                printf( "Dequeued Element: " );
                cout << element << endl;
            }
        }

        else if ( control == 3 ) {
            print_front_and_rear ( &front, &rear );
        }
    }

    return 0;
}