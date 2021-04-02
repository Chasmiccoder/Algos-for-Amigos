#include <iostream>
using namespace std;


void push( string* stack, string element, int* top, int length ) {
    /*
    Push a string element to the stack
    Nothing gets pushed if the stack is full
    */
    
    if ( *top == length -1  ) {
        printf( "Stack Overflow\n" );
        return;
    }
    
    *top = *top + 1;
    stack[ *top ] = element;
}


string pop( string* stack, int* top ) {
    /*
    Returns the top element of the stack
    Nothing gets popped if the stack is empty
    Top gets decremented by 1
    */
    
    if ( *top == -1 ) {
        printf( "Underflow\n" );
        return "";
    }

    string element = stack[ *top ];
    *top = *top - 1;
    return element;
}


string peek( string* stack, int* top ) {
    /*
    Returns the element at the top of the stack
    */
    
    if ( *top == -1 ) {
        printf( "Underflow\n" );
        return "";
    }
    return stack[ *top ];
}

void print_menu() {
    printf( "\nStack Operations:\n" );
    printf( "1 - Push Element\n" );
    printf( "2 - Pop Element\n" );
    printf( "3 - Peek Element\n" );
    printf( "4 - Print top value\n" );
    printf( "0 - Terminate Program\n" );
    printf( "\n" );
}


int main() {
    
    const int size = 10;
    string stack[ size ];
    int top = -1;

    while ( true ) {
        print_menu();
        int control;
        printf( "Enter choice: " );
        scanf( "%d", &control );

        if ( control == 0 ) {
            printf( "Terminating the program!\n" );
            break;
        }

        else if ( control == 1 ) {
            printf( "Enter element to be inserted: " );
            string element;
            cin >> element;
            push( stack, element, &top, size );
        }

        else if ( control == 2 ) {
            string element = pop( stack, &top );
            
            if ( element != "" ) {
                printf( "Popped Element: " );
                cout << element << endl;
            }
        }

        else if ( control == 3 ) {
            string element = peek( stack, &top );
            if ( element != "" ) {
                printf( "Top Element: " );
                cout << element << endl;
            }
            
        }

        else if ( control == 4 ) {
            printf( "Top Value: %d\n", top );
        }
    }

    return 0;
}