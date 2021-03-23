#include <iostream>
using namespace std;


struct Node {
    string data;
    Node* link;
};


int length_linked_list( Node* head_ptr );
void insert( Node* head_ptr, string element, int position );
void delete_element( Node* head_ptr, int position );
void print_linked_list( Node* head_ptr );
void print_menu();
void print_instructions();


int length_linked_list( Node* head_ptr ) {
    /*
    Returns the length of the linked list
    */
    
    int len = 0;
    Node* current = new Node;
    current = head_ptr;

    while ( current->link ) {
        len++;
        current = current->link;
    }
    return len;
}


void insert( Node* head_ptr, string element, int position = -1 ) {
    /*
    Inserts an element at the specified position in the linked list
    If the position is -1, the element gets inserted at the end
    */
    
    // Check if the position is valid
    int length = length_linked_list( head_ptr );
    if ( position < -1 || position > length ) {
        printf( "Invalid Position!\n\n" );
        return;
    }
    

    // If position is -1 (default argument), insert at the end
    if ( position == -1 || position == length + 1 ) {

        /*
        We need to dynamically allocate memory for the pointer to a Node named temp, else once we get 
        out of the function, the value stored in head_ptr->link will turn to some garbage value, since temp will
        go out of scope.
        */
        Node* temp = new Node;
        (*temp).data = element;
        (*temp).link = NULL;

        Node* current;
        current = head_ptr;

        // Traverse to the last node of the list
        while ( (*current).link != NULL ) {
            current = (*current).link;
        }

        // Link the node created to the last element
        (*current).link = temp;
    }

    // To insert an element in the first position, update the head to point to the new node, and the new node to point to the first node
    else if ( position == 0 ) {
        
        
        Node* temp = new Node;
    
        temp->data = element;
        (*temp).link = (*head_ptr).link;
        (*head_ptr).link = temp;
    }

    else {
        Node* temp = new Node;
        Node* current = new Node;

        temp->data = element;

        current = head_ptr;

        // Traverse all the way to the i-1th node (we make i iterations, but start from the head, which means that end at the (i-1)th node)
        for ( int i = 0; i < position; i++ ) {
            current = current->link;
        }

        // Link the new node to the ith node. Now the ith node becomes the (i+1)th node
        temp->link = current->link;
        // Link the (i-1)th node to the new node. Now the new node becomes the ith node
        current->link = temp;
    }
}


void delete_element( Node* head_ptr, int position ) {

    // Check if the position is valid
    int length = length_linked_list( head_ptr );
    if ( position < -1 || position >= length ) {
        printf( "Invalid Position!\n\n" );
        return;
    }

    // If we want to delete the first element, update the head to point to the 2nd node (node number 1)
    if ( position == 0 ) {
        Node* current = new Node;
        current = head_ptr;
        current = current->link;
        head_ptr->link = current->link;
        head_ptr->data = "";
    }

    // If position is -1 (default argument), delete the last element
    else if ( position == -1 || position == length - 1 ) {
        Node* current = new Node;
        Node* previous = new Node;
        current = head_ptr;
        previous = head_ptr;

        // Traverse to the last node
        while ( current->link ) {
            previous = current;
            current = current->link;
        }
        // Update the (n-1)th node to point to a NULL value
        previous->link = NULL;
    }

    else {

        Node* current = new Node;
        Node* previous = new Node;
        current = head_ptr;
        previous = head_ptr;
        int i = 0;

        // Traverse to the ith element
        for ( int i = 0; i <= position; i++ ) {
            previous = current;
            current = current->link;
        }
        // The (i-1)th element will point to the (i+1)th element
        previous->link = current->link;
    }
}


void print_linked_list( Node* head_ptr ) {
    /* 
    Function to print the entire linked list
    */
    
    Node* current = new Node;
    current = head_ptr;
    
    printf( "\n" );
    printf( "Linked List:\n" );
    printf( "============\n" );
    cout << "-head_ptr-" << endl;
    int i = 0;
    
    while ( current->link ) {
        
        current = current->link;    
        cout << current->data << ", " << i << endl;
        i++;
    }
    
    cout << "-Tail-" << endl;
}


void print_menu() {
    printf( "Operations:\n" );
    printf( "===========\n");
    printf( "1 - Insert an element\n" );
    printf( "2 - Delete an element\n" );
    printf( "3 - Print Linked List\n" );
    printf( "4 - Print Length of Linked List\n" );
    printf( "0 - Terminate the program\n" );
    printf( "\n" );
}


void print_instructions() {
    printf( "\nInstructions:\n" );
    printf( "=============\n" );
    printf( "Inserting an element -\nThe list stores strings. The position of the first node is 0.\n" );
    printf( "To insert element at the end, enter the position as -1.\n\n" );
    printf( "Deleting an element -\n" );
}


int main() {

    printf( "\nLinked List Implementation!\n" );
    print_instructions();

    Node head;
    head.link = NULL;

    while ( true ) {
        printf( "\n" );
        print_menu();

        printf( "Enter Choice: " );
        int control;
        scanf( "%d", &control );

        if ( control == 1 ) {
            string element;
            int position;

            printf( "Enter element to be inserted: " );
            cin >> element;
            printf( "Enter position: " );
            scanf( "%d", &position );

            insert( &head, element, position );   
        }

        else if ( control == 2 ) {
            int position;
            printf("Enter Position of element to be deleted: " );
            scanf( "%d", &position );

            delete_element( &head, position );
        }

        else if ( control == 3 ) {
            print_linked_list( &head );
        }

        else if ( control == 4 ) {
            int length = length_linked_list( &head );
            printf( "Length of Linked List: %d\n", length );
        }

        else if ( control == 0 ) {
            break;
        }
    }

    printf( "Terminating the program!\n" );
    return 0;
}