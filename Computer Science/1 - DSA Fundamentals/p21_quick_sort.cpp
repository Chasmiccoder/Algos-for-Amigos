/*
Quick Sort:
===========

Quick Sort (also called Partition Sort) is a Divide and Conquer sorting algorithm, that is 
similar to Merge Sort

A pivot point is chosen (taken as the last element of the array/subarray), and then placed in its
'sorted' postion. All this happens in partition()
This means that after this move, all elements before the sorted position will be lesser
than the pivot point, and all elements after the sorted position will be larger than the pivot point.
Then, this sorted index is returned to the quick_sort(), which is recursively called onto the subarrays
to the left and right hand sides of the sorted index. 

The array gets recursively divided and sorted, which signifies a top down approach towards sorting.
In merge sort, the array gets sorted using the bottom up approach of sorting subarrays and merging these
subarrays to generate the final array.

Ideally, we can choose the pivot to be any point in the sub array. In this code, we take it as the last element
Note that quick sort is not as good as merge sort for arrays with a large number of elements

Example, (i,j are iterators, p is the pivot)
  5  1  3  2  4
i j           p    A[j] > A[p]  -> Nothing  

                   Increment j
  5  1  3  2  4
i    j        p    A[j] < A[p]  -> Increment i, then swap A[i] and A[j]
                   
                   Increment j
  1  5  3  2  4
  i     j     p    A[j] < A[p]  -> Increment i, then swap A[i] and A[j]

                   Increment j
  1  3  5  2  4
     i     j  p    A[j] < A[p]  -> Increment i, then swap A[i] and A[j]

                   Increment j
  1  3  2  5  4
        i     jp   A[j] = A[p]

                   The for loop of partition() is over; swap A[i+1] and A[p]
  1  3  2  4  5   
                   The right subarray gets trivially solved
                   The left subarray will now go through quick sort 
  1  3  2  4  5
i j     p          A[j] < A[p]  -> Increment i, then swap A[i] and A[j]  

                   Increment j
  1  3  2  4  5
  i     jp         A[j] = A[p]

                   The for loop of partition() is over; swap A[i+1] and A[p]

  1  2  3  4  5
                   The right subarray and left subarray get trivially solved

Quick Sort is an Unstable Sorting Algorithm, which means that if there are repititions in the initial array,
the sorted array may not contain those repetitions in the same order.

Time Complexity = O(nlogn)
Worst Case Time Complexity = O(n^2)       When the array is in descending order
Space Complexity = O(n)                   In recursive stack calls


A beautiful visualization of what happens in partition(),
https://www.youtube.com/watch?v=MZaf_9IZCrc

*/

#include <iostream>

int partition( float *arr, int lower, int upper );
void quick_sort( float *arr, int lower, int upper );


int partition( float *arr, int lower_limit, int upper_limit ) {

    // Considering the last element as the pivot
    // index of the element which is supposed to be placed in its sorted position
    int pivot_index = upper_limit; 
    int i = lower_limit - 1;        // iterator to locate the sorted position of the pivot point

    for ( int j = lower_limit; j <= upper_limit; j++ ) {
        if ( arr[j] < arr[pivot_index] ) {
            i++;
            std::swap( arr[i], arr[j] );
        }
    }

    // Sorted index of pivot = i + 1
    std::swap( arr[i+1], arr[pivot_index] );
    return i+1;
}


void quick_sort( float *arr, int lower_limit, int upper_limit ) {
    if ( lower_limit < upper_limit ) {

        // Element at this index will be in its place
        int sorted_index = partition(arr,lower_limit,upper_limit);

        // Sort subarray to the left hand side of the sorted element
        quick_sort(arr,lower_limit,sorted_index-1);

        // Sort subarray to the right hand side of the sorted element
        quick_sort(arr,sorted_index+1,upper_limit);
    }
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

    quick_sort(array,0,n-1);

    std::cout << "\nArray after sorting:\n";
    printArray(array,n);

    delete[] array;

    return 0;
}