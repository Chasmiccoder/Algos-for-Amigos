/* A very famous interview question that is used to determine competency in Programming

Print numbers from 1 to N, according to the following rules:
If a multiple of 3 is encountered, print "fizz"
If a multiple of 5 is encountered, print "buzz"
If a multiple of 15 is encountered, print "fizzbuzz"
Else, print the number.

Credits to:
Coding Blocks YouTube Channel, https://www.youtube.com/watch?v=UYMP-cMy_zg
*/
#include <stdio.h>


void naive_solution( int N ) {
    /* In the worst case scenario, Modulo operator is used thrice.
    Time Complexity of modulo operator is O(n^2), so this will get costly as n increases.
    Space Complexity = O(1)
    */

    for ( int i = 1; i <= N; i++ ) {
        if ( i%15 == 0 ) 
            printf( "fizzbuzz\n" );
        
        else if ( i%3 == 0 ) 
            printf( "fizz\n" );
        
        else if ( i%5 == 0 ) 
            printf( "buzz\n" );
        
        else 
            printf( "%d\n", i );
        
    }
}


void decent_solution( int N ) {
    /* In the worse case scenario, Modulo operator is used twice. (better than first approach)
    Space Complexity = O(1)
    */
    
    for ( int i = 1; i <= N; i++ ) {
        int flag = 0;

        if ( i%3 == 0 ) {
            printf( "fizz" );
            flag = 1;
        }
        if ( i%5 == 0 ) {
            printf( "buzz" );
            flag = 1;
        }
        if ( flag == 0 ) 
            printf( "%d", i );
        
        printf( "\n" );
    }
}


void epic_level_solution( int N ) {
    /* We can solve this problem without using Modulo operator.
    This solution is basically truly linear. Time complexity = O(n)
    Space Complexity = O(1) We are using more variables, but Space Complexity is still constant.
    */
    int ctr3 = 0;
    int ctr5 = 0;

    for ( int i = 1; i <= N; i++ ) {
        int flag = 0;
        ctr3++;
        ctr5++;

        if ( ctr3 == 3 ) {
            ctr3 = 0;
            flag = 1;
            printf( "fizz" );
        }

        if ( ctr5 == 5 ) {
            ctr5 = 0;
            flag = 1;
            printf( "buzz" );
        }

        if ( flag == 0 ) 
            printf( "%d", i );
        
        printf( "\n" );

    }
}
/* From a software point of view, this does not make a difference. While programming low level architecture
this does make a big difference though.
*/

int main() {

    int N;
    printf( "Enter value of N: " );
    scanf( "%d", &N );

    //naive_solution( N );
    //decent_solution( N );
    epic_level_solution( N );

    return 0;
}