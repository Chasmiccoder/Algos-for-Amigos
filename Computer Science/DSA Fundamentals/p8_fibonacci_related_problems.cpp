#include <iostream>
#include <vector>
using namespace std;


int naive_nth_fibonacci_number( int n ) {
    /*
    Naive algorithm O(2^n) to find the nth Fibonacci Number
    */
    
    if ( n <= 1 )
        return n;
    return naive_nth_fibonacci_number( n-1 ) + naive_nth_fibonacci_number( n-2 );
}


int fib( int n ) {
    /*
    Efficient algorithm O(n) to find the nth Fibonacci Number 
    */

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
    /*
    To compute the last digit of the nth Fibonacci Number efficiently
    F331 = 668 996 615 388 005 031 531 000 081 241 745 415 306 766 517 246 774 551 964 595 292 186 469
    answer for n = 331 is 9
    */

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
    /*
    To compute Fn modulo m, where Fn is a large fibonacci number
    Instead of computing Fn, we can trace a pattern of Fi modulo m, which starts with the digits 0 and 1.
    For example, for Fi modulo 3, the pattern is: 0 1 1 2 0 2 2 1  where Fi ranges from 0 to 7. Length of period = 8
    */

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

int last_digit_of_sum_of_first_n_fibonacci_numbers_small_n( long long n ) {
    /*
    To compute the last digit of the sum of first n Fibonacci Numbers
    This function works... but breaks once n gets too large. Takes too much time
    */

    long long a = 0;
    long long b = 1;
    long long sum = 0;
    for ( long long i = 0; i < n; i++ ) {

        long long tmp = b%10;
        b = a%10;
        a = a%10 + tmp%10;
        sum+= a%10;
        
    }
    return (int)sum%10;
}

int last_digit_of_sum_of_first_n_fibonacci_numbers( long long n ) {
    /* 
    To compute the last digit of the sum of the first n Fibonacci Numbers efficiently

    Uses the naive approach with function named last_digit_of_sum_of_first_n_fibonacci_numbers_small_n ( )
    to get the repeating pattern, after which it exploits the pattern to find the last digit of the
    sum of first n Fibonacci Numbers

    From the insight gained, we need to compute the last digit of the sum of fibonacci numbers only till about 100
    */
    vector<int> vi;
    vi.push_back( 0 );
    vi.push_back( 1 );
    int len;
    
    for ( int i = 2; i < 100; i++ ) {
        vi.push_back( last_digit_of_sum_of_first_n_fibonacci_numbers_small_n(i) );
        if ( vi[i] == 1 && vi[i-1] == 0 ) {
            //len = i-2;
            len = i - 1;
            break;
        }
    }

    long long index = n%len;
    int result = vi[ index ];
    return result;
}

int naive_approach_last_digit_of_sum_of_first_n_fibonacci_numbers( long long n ) {
    /*
    To directly compute the last digit of the sum of first n Fibonacci Numbers
    This approach is highly inefficient
    */

    long long sum = 1;
    long long a = 1;
    long long b = 0;

    for ( long long i = 2; i <= n; i++ ) {
        long long tmp = b;
        b = a;
        a = a + tmp;
        sum += a%10;
    }

    return sum%10;
}

void stress_testing_last_digit_of_sum_of_first_n_fibonacci_numbers( ) {
    /*
    Stress Testing is done to check for the correctness of an efficient algorithm against a naive but correct solution
    This function performs stress testing for the problem: 
    Compute the last digit of the sum of first n Fibonacci Numbers

    Untested Efficient Algorithm: last_digit_of_sum_of_first_n_fibonacci_numbers( )
    Naive but correct Algorithm: naive_approach_last_digit_of_sum_of_first_n_fibonacci_numbers( )
    */

    int testcases = 80;
    bool passed = true;
    printf( "Conducting Stress Test\n" );

    for ( int i = 5; i < testcases+5; i++ ) {
        int first = naive_approach_last_digit_of_sum_of_first_n_fibonacci_numbers( i );
        //int second = last_digit_of_fib_sum( i );
        int second = last_digit_of_sum_of_first_n_fibonacci_numbers( i );

        if ( first != second ) {
            passed = false;
            printf( "\nN: %d\n", i );
            printf( "Naive Result: %d\n", first );
            printf( "Algo: %d\n", second );
        }
    }

    if ( passed ) {
        printf( "Algorithm Passed Stress Test!\n" );
    }
}


int main() {
    printf( "Fibonacci Related Problems!\n" );
    int n,answer;

    // Finding the nth Fibonacci Number
    printf( "\nFinding the nth Fibonacci Number:\n" );
    printf( "Enter value of n: " );
    scanf( "%d", &n );

    answer = fib( n-1 );
    printf( "Fast Algorithm: %d\n", answer);

    answer = naive_nth_fibonacci_number( n );
    printf( "Naive Algorithm: %d\n\n", answer ); // Really slow for any n > 40
    // For n = 13, answer is 233

    
    // Finding the Last Digit of the nth Fibonacci Number
    printf( "Finding the last digit of the nth Fibonacci Number:\n" );
    printf( "Enter value of n: " );
    scanf( "%d", &n );

    answer = last_digit_of_nth_fib_number( n );
    printf( "Last digit of %dth Fibonacci Number: %d\n\n", n, answer );
    // For n = 331, answer is 9


    // Compute Fn modulo m, where Fn is the nth Fibonacci number. n <= 10^14, m <= 10^3
    long long num;
    int m;
    printf( "Compute Fn modulo m, where Fn is the nth Fibonacci number\n" );
    printf( "Enter values for n and m: " );
    scanf( "%lld %d", &num, &m );

    answer = large_nth_fib_number_modulo_m( num, m );
    printf( "%lldth Fibonacci Number %% %d is: %d\n\n", num, m, answer );
    // For num = 2816213588, and m = 239, answer is 151


    // Compute the last digit of the sum of the first n Fibonacci Numbers. n <= 10^14
    printf( "Compute the last digit of the sum of the first n Fibonacci Numbers\n" );
    printf( "Enter the value for n: " ); 
    scanf( "%lld", &num );

    stress_testing_last_digit_of_sum_of_first_n_fibonacci_numbers( );

    answer = last_digit_of_sum_of_first_n_fibonacci_numbers( num );
    printf( "Last digit of first %lld Fibonacci Numbers is: %d\n\n", num, answer );
    // For num = 100, answer is 5


    return 0;
}