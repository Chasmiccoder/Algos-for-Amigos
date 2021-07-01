/*
N-Bonacci Numbers
=================

The N-Bonacci Series is a generalization of the Fibonacci Series.
The next term of the Fibonacci Series is given by the sum of the last two numbers
It goes like this,
0 1 1 2 3 5 8 13 21 34 ...
This series has great importance in mathematics. It grows at an exponential rate, and is closely tied
to the Golden Ratio

We can take this a step further and generate an N-Bonacci Series, where we will consider the sum
of the last n numbers to generate the next one. The series starts with N - 1 Zeroes followed by a 1.
For N = 4,
0 0 0 1 1 2 4 8 15 29 56 ...

For N = 5,
0 0 0 0 1 1 2 4 8 16 31 61 ...

In this Blog, we will attempt to find the m-th N-bonacci Number, first the iterative way, and then
the recursive way.

*/

#include <iostream>
#include <vector>
#include <cstring>


// mth Fibonacci Number Iterative
int fib_iterative( int m ) {
    /*
    Logic
    0 1 1 2 3 4
    ^ ^
    | Previous
    Before Previous
    We only need to store the last 2 elements of the series
    Add previous and before previous to get the next number
    Replace before previous with previous,
    Replace previous with the computed result (so that we can use this in the next iteration)
    */

    if ( m < 0 ) {
        std::cout << "Cannot compute fibonacci number at negative index!\n";
        exit(-1);
    }

    if ( m == 0 || m == 1 ) {
        return m;
    }

    // Series starts with 0, 1
    // 0th Element is 0. 1st element is 1
    int before_previous = 0;
    int previous = 1;

    int result;

    for ( int i = 2; i <= m; i++ ) {
        result = before_previous + previous;
        
        before_previous = previous;
        previous = result;
    }

    return result;
}


// mth Fibonacci Number Recursive
int fib( int m ) {
    if ( m < 0 ) {
        std::cout << "Cannot compute fibonacci number at negative index!\n";
        exit(-1);
    }

    // The 0th Fibonacci Number is 0, and the 1st Fibonacci Number is 1
    if ( m == 0 || m == 1 ) {
        return m;
    }

    /*
    Recursively compute the value (using the mathematical formula) until we get a 'direct' answer
    Basically, find the sum of the last 2 Fibonacci Numbers. If one, or both of the them are not
    trivial solutions (m = 0,1), then compute them (via a recursive call) before coming back here.
    */
    else {
        return fib( m - 1 ) + fib( m - 2 );
    }
}


// mth Fibonacci Number with Dynamic Programming
int fib_dp( int m, int *memo ) {
    if ( m < 0 ) {
        std::cout << "Cannot compute fibonacci number at negative index!\n";
        exit(-1);
    }

    if ( m == 0 ) {
        return 0;
    }

    // If the mth Fibonacci number has already been found, retrieve it from the memo
    if ( memo[m] != 0 ) {
        return memo[m];
    }

    else {
        int tmp = fib_dp( m - 1, memo ) + fib_dp( m - 2, memo );
        memo[m] = tmp; // Store the calculated result in memo for future use
        return tmp;
    }
}


// mth N-bonacci Number
int N_bonacci_iterative( int N, int m ) {

    int previous[N];
    
    // Set the first N-1 elements as 0, and the (N-1)th as 1
    std::memset(previous, 0, sizeof(previous));
    previous[N-1] = 1;
    
    // If m is smaller than N, the answer is either 0 or 1
    if ( m < N ) {
        return previous[m];
    }

    int result = 0;

    for ( int i = N; i <= m; i++ ) {

        // Compute the result by finding the sum of the last N elements in the series
        result = 0;
        for ( int j = 0; j < N; j++ ) {
            result += previous[j];
        }

        // Shift all elements towards the left
        for( int k = 0; k < N - 1; k++ ) {
            previous[k] = previous[k+1];
        }

        // Store the current intermediate result, so that we can use it in the next iteration
        previous[N - 1] = result;
    }

    return result;
}


// mth N-bonacci Number
int N_bonacci_iterative_optimized( int N, int m ) {
    /*
    We can store all the results in the array previous itself so that 
    we won't have to replenish it (by moving elements one step back)
    This cuts down the time complexity from O(n^2) to O(n)

    Also, we do not need to 're-calculate' the sum of the past N numbers to get the next one.
    For example, for N = 2, m = 8
    0 1 1 2 3 5 8 13 21
    The answer should be 21 = 8 + 13
    But, the previous result was computed like this, 13 = 8 + 5
    So, if we subtract 5 from the previous result (13), we will get 8. Now we just need to add
    the last number.
    Compute 21, from the previous result 21 = 13 - 5 + 13

    Another exmample, for N = 5, m = 11
    0 0 0 0 1 1 2 4 8 16 31 61
    The answer should be 61 = 2 + 4 + 8 + 16 + 31
    Previous result 31 = 1 + 2 + 4 + 8 + 16 
    Computing 61, from the previous result 61 = 31 - 1 + 31 = 2(31) - 1

    */ 

    if ( m < N - 1 ) {
        return 0;
    }
    else if ( m == N - 1 ) {
        return 1;
    }

    int previous[m+1];

    // Setting the initial series, 0 0 0 0 ... 0 1  where we have N - 1 zeroes
    for (int i = 0; i < N - 1; i++ ) {
        previous[i] = 0;
    }

    // Intial Elements:
    previous[N-1] = 1;
    previous[N] = 1;
    
    for ( int i = N; i < m; i++ ) {
        previous[ i+1 ] = 2 * previous[ i ] - previous[ i - N ];
    }

    return previous[m];
}


// mth N-bonacci Number with recursion
int N_bonacci( int N, int m ) {

    // If m is lesser than or equal to N - 1, the solution is trivial
    if ( m < N - 1 ) {
        return 0;
    }

    else if ( m == N - 1 ) {
        return 1;
    }

    else {
        /*
        Create a temporary variable, and store the sum of the previous N
        elements, by making N recursive calls. If it finds a trivial solution,
        it returns that (the above base cases). Otherwise, it searches for it,
        through more recursive calls
        */
        int tmp = 0;
        for ( int i = 1; i <= N; i++ ) {
            tmp += N_bonacci( N, m - i );
        }
        return tmp;
    }
}


// mth N-bonacci Number with Dynamic Programming
int N_bonacci_dp( int N, int m, int *memo ) {

    if ( m <= N - 1 ) {
        return memo[m];
    }

    // If the result has been computed already, retrieve it.
    if ( memo[m] != 0 ) {
        return memo[m];
    }

    else {
        int tmp = 0;
        for ( int i = 1; i <= N; i++ ) {
            tmp += N_bonacci_dp( N, m - i, memo );
        }
        memo[m] = tmp;  // memoization
        return tmp;
    }
}


// Driver Code
int main() {
    std::cout << "N-bonacci Numbers!\n";
    std::cout << "==================\n\n";
    
    int m,N;

    std::vector<int> results;
    
    std::cout << "mth Fibonacci Number (iterative):\n";
    
    std::cout << "Enter the value for m: ";
    std::cin >> m;

    results.push_back( fib_iterative(m) );
    std::cout << "The mth Fibonacci Number is: " << results[0] << "\n\n";


    std::cout << "mth Fibonacci Number (recursive):\n";
    
    std::cout << "Enter the value for m: ";
    std::cin >> m;

    results.push_back( fib(m) );
    std::cout << "The mth Fibonacci Number is: " << results[1] << "\n\n";

    std::cout << "mth Fibonacci Number (recursive, DP):\n";

    std::cout << "Enter the value for m: ";
    std::cin >> m;

    int memo_1[ m + 1 ];  
    std::memset( memo_1, 0, sizeof(memo_1) );
    memo_1[1] = 1;

    results.push_back( fib_dp( m, memo_1 ) );
    std::cout << "The mth Fibonacci Number is: " << results[2] << "\n\n";


    std::cout << "mth N-bonacci Number (iterative):\n";

    std::cout << "Enter the value for N: ";
    std::cin >> N;

    std::cout << "Enter the value for m: ";
    std::cin >> m;

    results.push_back( N_bonacci_iterative( N, m ) );
    std::cout << "The mth N-bonacci Number is: " << results[3] << "\n\n";


    std::cout << "mth N-bonacci Number (iterative, optimized):\n";

    std::cout << "Enter the value for N: ";
    std::cin >> N;

    std::cout << "Enter the value for m: ";
    std::cin >> m;
    results.push_back( N_bonacci_iterative_optimized( N, m ) );
    
    std::cout << "The mth N-bonacci Number is: " << results[4] << "\n\n";


    std::cout << "mth N-bonacci Number (recursive):\n";

    std::cout << "Enter the value for N: ";
    std::cin >> N;

    std::cout << "Enter the value for m: ";
    std::cin >> m;

    results.push_back( N_bonacci( N, m ) );
    std::cout << "The mth N-bonacci Number is: " << results[5] << "\n\n";


    // To do: N-bonacci Recursive + DP
    std::cout << "mth N-bonacci Number (recursive, DP):\n";

    std::cout << "Enter the value for N: ";
    std::cin >> N;

    std::cout << "Enter the value for m: ";
    std::cin >> m;

    // int *memo = new int[m+1];
    int memo[ m + 1 ];
    std::memset( memo, 0, sizeof(memo) );
    memo[N-1] = 1;

    results.push_back( N_bonacci_dp( N, m, memo ) );
    std::cout << "The mth N-bonacci Number is: " << results[6] << "\n\n";

    std::cout << "================================\n";
    std::cout << "Thank you for using the program!\n";
    std::cout << "\n\n";
    return 0;
}