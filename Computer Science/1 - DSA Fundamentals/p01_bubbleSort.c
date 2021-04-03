/*
Program to sort an array into ascending or descending order using Bubble Sort
*/
#include <stdio.h>

void bubble_sort( int *arr, int n, int reverse ) {
    /*Takes the pointer to the first value of the array, and the number of array elements as arguments
      and then sorts the array in ascending order using bubble sort.
      If reverse is 1 (true), then it sorts in descending order */
    
    
    int i = 0, j = 0;
    int temp = 0;

    for ( i = 0; i < n - 1; i++ ) {
        for ( j = 0; j < n - i - 1; j++ ) {
            if ( reverse == 0 && arr[j] > arr[j+1] || reverse == 1 && arr[j] < arr[j+1] ) {
                // If ascending and if the previous element is greater than the next, then swap, or
                // if descending and if the previous element is lesser than the next, then swap.

                temp = arr[ j ];
                arr[ j ] = arr[ j+1 ];
                arr[ j+1 ] = temp;
            }
        }
    }
}

int main() {
    printf("\n");

    int len;
    printf( "Enter length of array: " );
    scanf( "%d", &len );
    int array[ len ];

    int i = 0;
    printf( "Enter array elements: " );
    for ( i = 0; i < len; i++ ) {
        scanf( "%d", &array[i] );
    }

    bubble_sort( array, len, 0 );    // Ascending Order
    //bubble_sort( array, len, 1 );  // Descending Order


    printf( "Array after sorting: " );
    for ( i = 0; i < len; i++ ) {
        printf( "%d ",  array[i] );
    }

    return 0;
}