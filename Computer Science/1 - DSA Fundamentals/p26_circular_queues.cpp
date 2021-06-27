#include <iostream>

struct CircularQueue {
    int front, rear;
    int size;
    int *arr;
};

void init(CircularQueue& Q, int size) {
    Q.front = -1;
    Q.rear  = -1;
    Q.size  = size;
    Q.arr   = new int[size];
}

void enqueue(CircularQueue& Q, int element) {
    if( ( Q.front == 0 && Q.rear == Q.size - 1 ) || (Q.rear == (Q.front - 1 ) % (Q.size - 1) ) ) {
        std::cout << "The Queue is full!\nNothing changed\n";
        return;
    }

    // When the first element gets added (right after initialization)
    else if ( Q.front == - 1 ) {
        Q.front = 0;
        Q.rear = 0;
        Q.arr[Q.rear] = element;
    }

    else if ( Q.rear == Q.size - 1 && Q.front != 0 ) {
        Q.rear = 0;
        Q.arr[Q.rear] = element;
    }

    else {
        Q.rear++;
        std::cout << "SECOND: " << Q.front << "\n";
        Q.arr[Q.rear] = element;

    }
}

int dequeue(CircularQueue& Q) {

    // Queue has no elements
    if ( Q.front == -1 ) {
        std::cout << "Queue is Empty!\nReturning Zero\n";
        return 0;    
    }

    int element = Q.arr[Q.front];
    // Q.arr[Q.front] = -1;
    if ( Q.front == Q.rear ) {
        Q.front = -1;
        Q.rear = -1;
    }

    else if ( Q.front == Q.size - 1 ) {
        Q.front = 0;
    }

    else {
        Q.front++;
    }

    return element;
}


int main() {

    std::cout << "\nImplementation of Circular Queues:\n";

    CircularQueue Q;
    int n;

    std::cout << "Enter size of Queue:\n";
    std::cin >> n;
    
    init(Q, n);

    while ( true ) {
        std::cout << "\nCircular Queue Operations\n";
        std::cout << "1 - Enqueue\n";
        std::cout << "2 - Dequeue\n";
        std::cout << "3 - Print Front and Rear Elements\n";
        std::cout << "4 - End Program\n";

        int choice;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cout << "\n";

        if ( choice == 1 ) {
            int element;
            std::cout << "Enter element: ";
            std::cin >> element;

            enqueue(Q, element);
            std::cout << "\nElement Enqueued successfully\n\n";
        }

        else if ( choice == 2 ) {
            int element = dequeue(Q);
            std::cout << "Dequeued Element: " << element << "\n\n";
        }

        else if ( choice == 3 ) {
            std::cout << "Front: " << Q.arr[Q.front] << "\n";
            std::cout << "Rear : " << Q.arr[Q.rear]  << "\n\n";
        }

        else if ( choice == 4 ) {
            std::cout << "\nThank you for using the program!\n\n";
            break;
        }

        else {
            std::cout << "Invalid Input!\n";
        }

    }


    return 0;
}


