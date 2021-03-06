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

int main() {
    int n;
    printf( "\nEnter value of n: " );
    scanf( "%d", &n );

    int answer2 = fib( n-1 );
    printf( "Fast Algorithm: %d\n", answer2);

    int answer = naive_nth_fibonacci_number( n );
    printf( "Naive Algorithm: %d\n", answer );

    
    return 0;
}