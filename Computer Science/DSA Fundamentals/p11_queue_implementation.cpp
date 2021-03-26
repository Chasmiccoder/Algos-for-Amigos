#include <iostream>
using namespace std;


void enqueue( string* Q, string element, int* front, int* rear, int size ) {
    /* 
    Adds an element at the rear of the queue
    If the queue is full, it prints out Overflow
    */
    
    if ( *rear == size - 1 ) {
        printf( "Overflow\n" );
        return;
    }

    if ( *front = -1 ) {
        *front = 0;
    }

    *rear = *rear + 1;
    Q[ *rear ] = element;
}


string dequeue( string* Q, int* front, int* rear ) {
    /*
    Removes the element at the front of the queue
    If the queue is empty (front and rear are already -1), it prints out Underflow
    If at any point the front and rear pointers become the same, and are not equal to -1,
    the front and rear can be set back to -1
    */
    
    if ( *front == -1 && *rear == -1 ) {
        printf( "Underflow\n" );
        return "";
    }
    if ( *front == *rear ) {
        string element = Q[ *front ];
        *front = -1;
        *rear = -1;
        return element;
    }
    
    string element = Q[ *front ];
    *front = *front + 1;
    return element;
}


void print_front_and_rear( string* Q, int* front, int* rear ) {
    if ( *front == -1 || *rear == -1 ) {
        printf( "\nFront: %d\nRear: %d\n\n", *front, *rear );
        return;
    }
    printf( "\nFront Element: " );
    cout << Q[ *front ] << endl;

    printf( "Front Pointer: %d\n\n", *front );

    printf( "Rear Element: " );
    cout << Q[ *rear ] << endl;

    printf( "Rear Pointer: %d\n\n", *rear );
}


void print_menu() {
    printf( "\nOperations:\n" );
    printf( "1 - Enqueue\n" );
    printf( "2 - Dequeue\n" );
    printf( "3 - Display front and rear\n" );
    printf( "0 - Terminate the program\n" );
    printf( "\n" );
}


int main() {

    int size = 10;
    string Q[ size ];
    int rear = -1;
    int front = -1;

    while ( true ) {
        print_menu();

        int control;
        printf( "Enter Choice: " );
        scanf( "%d", &control );

        if ( control == 0 ) {
            printf( "Terminating the program!\n" );
            break;
        }

        else if ( control == 1 ) {
            string element;
            printf( "Enter element to be enqueued: " );
            cin >> element;
            enqueue( Q, element, &front, &rear, size );
        }

        else if ( control == 2 ) {
            string element = dequeue( Q, &front, &rear );
            if ( element != "" ) {
                printf( "Dequeued Element: " );
                cout << element << endl;
            }
        }

        else if ( control == 3 ) {
            print_front_and_rear( Q, &front, &rear );
        }
    }

    return 0;
}
