#include <iostream>
using namespace std;

int naive_nth_fibonacci_number( int n ) {
    if ( n <= 1 )
        return n;
    return naive_nth_fibonacci_number( n-1 ) + naive_nth_fibonacci_number( n-2 );
}

int fib( int n ) {
    int a = 1;
    int b = 0;
    for ( int i = 0; i < n; i++ ) {
        int tmp = b;
        b = a;
        a = a+tmp;
    }
    return a;
}

int last_digit_of_nth_fib_number( int n ) {
    int a = 0;
    int b = 1;
    for ( int i = 0; i < n; i++ ) {
        int tmp = b%10;
        b = a%10;
        a = a%10+tmp%10;
    }
    return a%10;
}

int main() {
    int n,answer,answer2;

    // Finding the nth Fibonacci Number
    printf( "\nFinding the nth Fibonacci Number:\n" );
    printf( "Enter value of n: " );
    scanf( "%d", &n );

    answer2 = fib( n-1 );
    printf( "Fast Algorithm: %d\n", answer2);

    answer = naive_nth_fibonacci_number( n );
    printf( "Naive Algorithm: %d\n\n", answer );

    
    // Finding the Last Digit of the nth Fibonacci Number
    printf( "Finding the last digit of the nth Fibonacci Number:\n" );
    printf( "Enter value of n: " );
    scanf( "%d", &n );

    answer = last_digit_of_nth_fib_number( n );
    printf( "Last digit of %dth Fibonacci Number: %d\n", n, answer );
    // F331 = 668 996 615 388 005 031 531 000 081 241 745 415 306 766 517 246 774 551 964 595 292 186 469
    // answer for n = 331 is 9

    




    


    
    return 0;
}