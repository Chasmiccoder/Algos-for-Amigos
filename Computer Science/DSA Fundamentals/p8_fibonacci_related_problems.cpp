#include <iostream>
#include <vector>
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
    // F331 = 668 996 615 388 005 031 531 000 081 241 745 415 306 766 517 246 774 551 964 595 292 186 469
    // answer for n = 331 is 9
    int a = 0;
    int b = 1;
    for ( int i = 0; i < n; i++ ) {
        int tmp = b%10;
        b = a%10;
        a = a%10+tmp%10;
    }
    return a%10;
}


int large_nth_fib_number_modulo_m( long long n, int m ) {
    // Instead of computing Fn, we can trace a pattern of Fi modulo m, which starts with the digits 0 and 1.
    // For example, for Fi modulo 3, the pattern is: 0 1 1 2 0 2 2 1  where Fi ranges from 0 to 7. Length of period = 8
    vector<long long> vi; // Period
    vi.push_back( 0 );
    vi.push_back( 1 );

    int len = 0; // Length of period

    int flag = 0;
    long long i = 2;

    while ( true ) {
        
        if ( vi[i-1] == 1 && vi[i-2] == 0 && flag == 1 ) {
            len = i-2;
            break;
        }
        flag = 1;
        vi.push_back( (vi[ i-1 ] + vi[ i-2 ]) % m );

        i++;
    }
    
    int index = n % len; 
    int answer = vi[ index ] % m;

    return answer;
}


int main() {
    int n,answer;

    // Finding the nth Fibonacci Number
    printf( "\nFinding the nth Fibonacci Number:\n" );
    printf( "Enter value of n: " );
    scanf( "%d", &n );

    answer = fib( n-1 );
    printf( "Fast Algorithm: %d\n", answer);

    answer = naive_nth_fibonacci_number( n );
    printf( "Naive Algorithm: %d\n\n", answer );

    
    // Finding the Last Digit of the nth Fibonacci Number
    printf( "Finding the last digit of the nth Fibonacci Number:\n" );
    printf( "Enter value of n: " );
    scanf( "%d", &n );

    answer = last_digit_of_nth_fib_number( n );
    printf( "Last digit of %dth Fibonacci Number: %d\n\n", n, answer );


    // Compute Fn modulo m, where Fn is the nth Fibonacci number. n <= 10^14, m <= 10^3
    long long num;
    int m;
    printf( "Compute Fn modulo m, where Fn is the nth Fibonacci number\n" );
    printf( "Enter values for n and m: " );
    scanf( "%lld %d", &num, &m );

    answer = large_nth_fib_number_modulo_m( num, m );
    printf( "%lldth Fibonacci Number %% %d is: %d\n\n", num, m, answer );


    //

    







    


    
    return 0;
}