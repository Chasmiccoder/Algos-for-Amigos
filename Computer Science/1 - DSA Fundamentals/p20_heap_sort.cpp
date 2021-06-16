/*
Heap Sort:
==========

Representing Binary Trees using Arrays -
Consider the following tree   5
                             / \
                            /   \
                           2     9
                          / \   / \
                         3   1 4   6
Using the convention,
if Root Node = i,
Left Node    = 2 * i + 1, 
Right Node   = 2 * i + 2
Where i is the array index (starting from 0)

The tree will be = [ 5, 2, 9, 3, 1, 4, 6 ]

A binary tree which can be represented in it's array format without spaces is a complete binary tree.
A Max Heap is a complete binary tree with the condition that the parent node always has an element
that is greater than or equal to its child nodes. (It is the other way around for Min Heaps)
The process of converting a binary tree into a heap efficiently is called heapify.

Max Heapifying the given example:
Start with the last element (nth node), and go backwards, while converting the node's subtree into a max heap
Note that leaf nodes are already max heaps. This happens in the max_heapify() function
                                                (Recursively Heapify until All Subtrees are Max Heaps)

     5                5                5                9                9
    / \     (9)      / \     (2)      / \     (5)      / \     (5)      / \
   /   \     =>     /   \     =>     /   \     =>     /   \     =>     /   \
  2     9          2     9          3     9          3     5          3     6
 / \   / \        / \   / \        / \   / \        / \   / \        / \   / \
3   1 4   6      3   1 4   6      2   1 4   6      2   1 4   6      2   1 4   5

Now, swap the root node [9] (which is the largest element in the list) with the last node [5], and then 
'cut' the leaf node. In the code, the first element is swapped with the last element, and the 'size' of
the array considered as the binary tree is reduced by 1. This happens in the heap_sort() function.
Re-heapify the binary tree, and eliminate the largest element in the tree after each recursive call. 


This way, the largest elements in the binary tree get eliminated and put at the end, which
results in an array sorted in ascending order.


*/

#include<iostream>

void build_max_heap( float *arr, int n );
void max_heapify( float *arr, int i, int n );
void heap_sort( float *arr, int n );


void heap_sort( float *arr, int n ) {
    // Convert the initial binary tree to a max heap
    build_max_heap( arr, n );

    for ( int i = n - 1; i > 0; i-- ) {
        // Deletion occurs at the root node 
        std::swap( arr[0], arr[i] );

        // Re-heapify the binary tree
        max_heapify( arr, 0, i );
    }
}


// Converts the binary tree to a max heap in the beginning
void build_max_heap( float *arr, int n ) {
    for ( int i = n/2 - 1; i >= 0; i-- ) {
        max_heapify( arr, i, n );
    }
}


// Max Heapify the binary tree
void max_heapify( float *arr, int i, int n ) {
    
    // indices of left and right children
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
    int largest = i; // index of root node

    // If a valid left child is greater than the root, mark it as the largest element
    if ( left_child < n && arr[left_child] > arr[largest] ) {
        largest = left_child;
    }
    
    // If a valid right child is greater than the root, mark it as the largest element
    if ( right_child < n && arr[right_child] > arr[largest] ) {
        largest = right_child;
    }

    // If the largest element is not the root (initial assumption), then we need to swap the new largest 
    // element with the old root, and re-heapify
    if ( largest != i ) {
        std::swap( arr[i], arr[largest] );
        max_heapify( arr, largest, n );
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

    heap_sort(array, n);

    std::cout << "\nArray after sorting:\n";
    printArray(array,n);

    delete[] array;

    return 0;
}