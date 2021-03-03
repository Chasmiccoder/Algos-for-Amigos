#include <iostream>
#include <cstdlib>

using namespace std;

// Fast and Accurate
long long solve( int arr[], int len ) {
    /*
    Finds the largest, and second largest integers and returns the product
    */
    int i = 0;
    int largest_index = -1;
    int second_largest_index = -1;

    for ( i = 0; i < len; i++ ) {
        if ( largest_index == -1 || arr[ largest_index ] < arr[ i ] ) {
            largest_index = i;
        }
    }

    for ( i = 0; i < len; i++ ) {
        if ( largest_index == i )
            continue;
        if ( second_largest_index == -1 || arr[ second_largest_index ] < arr[ i ]  ) {
            second_largest_index = i;
        }
    }
    
    long long result = (long long) arr[ largest_index ] * arr[ second_largest_index ];
    return result;
}


// Basically Brute Force
long long solve_correct_but_slow( int arr[], int len ) {
    /*
    Goes through all possible pairs of integers, finds their product and returns the maximum value
    */
    long long result = 0, tmp = 0;
    
    for ( int i = 0; i < len; i++ ) {
        for ( int j = 0; j < len; j++ ) {
            tmp = (long long) arr[i] * arr[j];
            if ( result < tmp && i!=j )
                result = tmp;
        }
    }

    return result;
}


void stress_test( ) {
    /* 
    Compares the two algorithms in solve( ) and solve_correct_but_slow( ) methods for a randomly generated dataset
    If the results don't match, it prints the dataset and generated answers, for easy debugging
    */
    int param1 = 10;
    int param2 = 100000;

    int len = rand()%param1 + 2; // Random integer between 2 and (param1 + 1)
    int arr[ len ];
    
    for ( int i = 0; i < len; i++ ) {
        arr[ i ] = rand() % param2;
    }
    long long res1 = solve( arr, len );
    long long res2 = solve_correct_but_slow( arr, len );

    if ( res1 != res2 ) {
        printf( "Array: " );
        for ( int i = 0; i < len; i++ ) {
            printf( "%d ", arr[i] );
        }
        printf( "\nAlgo Answer: %lld\nCorrect Answer: %lld\n\n", res1, res2 );
    }

}


int main() {

    // Main Code
    int len, i = 0;
    scanf( "%d", &len ); // Length of array

    int arr[ len ];
    for ( i = 0; i < len; i++ ) {
        scanf( "%d", &arr[ i ] ); // Array Elements
    }

    long long answer = solve( arr, len );
    printf( "%lld\n", answer );
    
    /*
    // Stress Test:
    int testcases = 10000;
    for ( int i = 0; i < testcases; i++ ) {
        stress_test( );
    }
    */
    
    return 0;
}