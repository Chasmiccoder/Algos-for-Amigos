/*
Time Complexity = O(n^2)
Space Complexity = O(1)
*/

#include <iostream>

void insertion_sort( int *arr, int n ) {

    for ( int i = 1; i < n; i++ ) {
        int key = arr[i];
        int j = i - 1;

        while ( j >= 0 && arr[j] > key ) {
            arr[ j + 1 ] = arr[j];
            j--;
        }

        arr[j+1] = key;

    }
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    int *arr = new int[n];

    std::cout << "Enter array elements:\n";
    for ( int i = 0; i < n; i++ ) {
        std::cin >> arr[i];
    }

    insertion_sort( arr, n );

    std::cout << "Array after sorting:\n";
    for ( int i = 0; i < n; i++ ) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    delete[] arr;

    return 0;
}