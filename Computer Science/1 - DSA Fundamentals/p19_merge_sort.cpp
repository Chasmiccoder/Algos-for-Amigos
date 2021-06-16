/*
Merge Sort:
===========

Merge sort involves divide and conquer and recursion. The array is first broken into subarrays with 1 element each
and then trivially sorted. Two nearby elements merge and get sorted as they merge, via recursive calls. This
happens in the merge() function. To reach the subarrays, we use the recursive calls from merge_sort()
Length of the binary tree is n, where n = number of array elements
Merge sort works using the bottom up approach of sorting

Merge Sort is a Stable Sorting Algorithm, which means that if there are repetitions in the initial array,
the final array will contain those repititions in the same order.

Example, 
      5,1,3,2,6,4,8,7
          /     \
   5,1,3,2       6,4,8,7
    /  \           /  \         
 5,1    3,2     6,4     8,7   
 / \    / \     /  \    / \                               
5   1  3   2   6   4   8   7
 \ /    \ /     \ /     \ /
 1,5    2,3     4,6     7,8
    \  /           \  /
   1,2,3,5       4,6,7,8 
          \     /
      1,2,3,4,5,6,7,8


Time Complexity = O(nlogn)
Space Complexity = O(n)       Due to the recursive stack calls

*/

#include <iostream>
#include <limits>

void merge_sort(float *arr, int lower_limit, int upper_limit );        // Performs merge sort
void merge(float *arr, int lower_limit, int middle, int upper_limit ); // Merges the left and right subarrays in ascending order
void printArray(float *arr, int n );

double INF = std::numeric_limits<double>::infinity();

void merge_sort(float *arr, int lower_limit, int upper_limit ) {
    if ( lower_limit < upper_limit ) {

        // Find the point at which the array should be split (into left and right subarrays)
        int middle_index = (lower_limit + upper_limit) / 2;

        merge_sort(arr, lower_limit, middle_index);
        merge_sort(arr, middle_index + 1, upper_limit);

        merge(arr, lower_limit, middle_index, upper_limit);
    }

    // If the upper limit becomes equal to, or exceeds the lower limit, we have sorted the sub array from lower_limit to upper_limit
    return;
}


void merge(float *arr, int lower_limit, int middle, int upper_limit ) {
    int n1 = middle - lower_limit + 1; // Number of elements in the left sub array
    int n2 = upper_limit - middle;     // Number of elements in the right subarray

    float *L = new float[n1];
    float *R = new float[n2];

    // Initialize the left and right subarrays
    for ( int i = 0; i < n1; i++ ) {
        L[i] = arr[ lower_limit + i ];
    }

    for ( int i = 0; i < n2; i++ ) {
        R[i] = arr[middle+i+1];
    }

    int i = 0, j = 0, k = lower_limit;

    // Compare elements of the left subarray with those in the right subarray, and add them
    // in ascending order until one of the arrays gets fully exhausted, after which we will just
    // need to merge the array left out
    while ( i < n1 && j < n2 ) {
        if ( L[i] <= R[j] ) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Add the leftover elements of the left sub array to the main array
    while ( i < n1 ) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Add the leftover elements of the right sub array to the main array
    while ( j < n2 ) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void printArray(float *arr, int n ) {
    for ( int i = 0; i < n; i++ ) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int n;

    std::cout << "Enter number of elements: " << std::endl;
    std::cin >> n;

    float *array = new float[n];

    std::cout << "Enter array elements:\n";
    for ( int i = 0; i < n; i++ ) {
        std::cin >> array[i]; 
    }

    std::cout << "\nArray before sorting:\n";
    printArray(array,n);

    merge_sort(array,0,n-1);

    std::cout << "\n\nArray after sorting:\n";
    printArray(array,n);
    
    delete[] array;

    return 0;
}