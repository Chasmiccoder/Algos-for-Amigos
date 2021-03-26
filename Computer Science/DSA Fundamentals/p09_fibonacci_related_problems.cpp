/*
This program solves various problems related to the Fibonacci Series
1) Find the nth Fibonacci Number using an efficient algorithm
2) Find the last digit of the nth Fibonacci Number
3) Find the value of the nth Fibonacci Number modulo m (n <= 10^14)
4) Find the last digit of the sum of the first n Fibonacci Numbers (n <= 10^14)
5) Find the last digit of the partial sum of the Fibonacci Numbers from m to n 
6) Find the last digit of the sum of the squares of the first n Fibonacci Numbers


This code also introduces the concept of stress testing which has been applied to solve problem number 4

Pisano Period,
*/

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


void stress_testing_last_digit_of_sum_of_first_n_fibonacci_numbers() {
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


long long naive_get_fibonacci_partial_sum(long long from, long long to) {
    /*
    Finds the last digit of the partial sum of fibonacci numbers
    Simple, but slow solution
    */
    
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current%10;
        }

        long long new_current = next%10;
        next = next%10 + current%10;
        current = new_current%10;
    }

    return sum % 10;
}


vector<int> last_digit_of_nth_fibonacci_number_and_the_one_before( long long n ) {
    /*
    Finds the last digit of the (n-1)th fibonacci number, and the nth fibonacci number efficiently
    It makes use of the repeating pattern of the last digit of the ith fibonacci number
    */
    
    vector<int> pattern;

    pattern.push_back( 0 );
    pattern.push_back( 1 );

    bool passed_first_round = false;
    int i = 1;

    while ( true ) {
        if ( passed_first_round && pattern[i] == 1 && pattern[i-1] == 0 ) {
            pattern.pop_back();
            pattern.pop_back();
            break;
        }
        passed_first_round = true;
        pattern.push_back( (pattern[i]%10 + pattern[i-1]%10)%10 );
        i++;
    }

    int size = pattern.size();
    vector<int> vi;

    int index = n % size;

    vi.push_back( pattern[ index - 1 ] );
    vi.push_back( pattern[ index ] );
    
    return vi;
}


int last_digit_of_partial_sum_of_fibonacci_numbers( long long m, long long n ) {
    /*
    Finds the last digit of the partial sum of the Fibonacci Numbers from Fm to Fn
    There exists a pattern to the last digit of the fibonacci series starting from the mth Fibonacci number

    First we compute that pattern for the value of m
    To compute this value, we find the last digit of the (m-1)th and the mth Fibonacci number and then find the last digit 
    of the succeeding numbers until the (m-1)th and mth results get repeated.
    
    Then, we find the particular solution using n
    */

    // If m is zero, the problem is the same as finding the last digit of the sum of the first n fibonacci numbers
    if ( m == 0 ) {
        return last_digit_of_sum_of_first_n_fibonacci_numbers( n );
    }

    vector<int> vi;
    vector<int> vi_tmp;

    vi = last_digit_of_nth_fibonacci_number_and_the_one_before( m );

    if ( m == n ) {
        return vi[1] % 10;
    }
    
    bool passed_first_round = false;

    int i = 1;

    while ( true ) {
        if ( passed_first_round && vi[ i ] == vi[ 1 ] && vi[ i-1 ] == vi[ 0 ] ) {

            // Removing the last two digits, since they are already part of the pattern
            vi.pop_back( );
            vi.pop_back( );
            
            break;
        }
        passed_first_round = true;
        
        vi.push_back( (vi[i]%10 + vi[i-1]%10)%10 );
        i++;
    }
    
    // The first element actually corresponds to the (m-1)th Fibonacci Number. We want to put it at the end
    vi.push_back( vi[0] );
    vi.erase( vi.begin() );
    // After this stage, vi contains the pattern for m

    int length = vi.size( );

    // Finding the sum of the entire period for the pattern corresponding to the sum of the last digit of the Fibonacci Numbers starting from m
    long long sum = 0;
    for (auto x:vi )
        sum += x%10;
    sum = sum%10;

    // The number of complete periods in the interval [m,n] is given by (int) (n-m) / length
    int answer = (int) (n-m) / length;

    // Finding the total of the periods in the interval
    answer *= sum;

    // limit is till where we need to iterate to find the sum of the leftover period
    long long limit = (n-m) % length;
    for ( long long i = 0; i <= limit; i++ ) {
        answer += vi[i]%10;
    }

    return answer%10;
}


int main() {

    printf( "Fibonacci Related Problems!\n" );
    int n, answer;

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

    // Compute the last digit of the partial sum of the fibonacci numbers
    // Answer = ( Fm + F(m+1) + F(m+2) + ... + F(n) ) % 10
    printf( "Compute the last digit of the partial sum of the fibonacci numbers from m to n\n" );
    printf( "Enter values of m and n: " );
    long long M, N;
    scanf ("%lld %lld", &M, &N);

    answer = last_digit_of_partial_sum_of_fibonacci_numbers( M, N );
    printf( "Last digit of the sum of Fibonacci Numbers from %lld to %lld is: %d\n\n", M, N, answer );


    return 0;
}