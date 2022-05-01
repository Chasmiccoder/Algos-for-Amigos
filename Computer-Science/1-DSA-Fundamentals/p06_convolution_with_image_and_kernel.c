/*
Problem Definition:
===================
Implement Image Convolution with C
The first element of the image overlaps with the centre of the kernal in the beginning
Convolution is done by taking the sum of the products of all overlapping kernel and image elements

For example, if
kernel = [ [ 1, 2, 1],
           [ 0, 0, 0],
           [-1,-2,-1]]
And if 
image = [ [1,2,3],
          [4,5,6],
          [7,8,9]]

To get the first element of the convoluted_image, consider the overlapping region (submatrices of kernel and image)
sub matrix of kernel = [[ 0, 0],     sub matrix of image = [[1,2],
                        [-2,-1]]                            [4,5]]

After manipulating the first image, we should get   0 * (1) + 0 * (2) + (-2) * (4) + (-1) * 5 = -13
After applying convolution on the entire image, the final image is,
convoluted_image = [[-13,-20,-17],
                    [-18,-24,-18],
                    [13,20,17]]


Input File Format:
==================
The Input is given in the file "input_convolution.txt"
First line contains integers x,y,z where,
x = Number of rows in the kernel
y = Number of columns in the kernel
z = Number of elements in the kernel
The next x lines contain triplets of integers which specify the row number, column number,
and the element itself corresponding to the kernel.

The next line contains integers a,b,c where,
a = Number of rows in the image
b = Number of columns in the image
c = Number of elements in the image
The next a lines contain triplets of integers which specify the row number, column number,
and the element itself corresponding to the image.

The Final Output is in a file "output_convolution.txt"

Note: Code works under the assumption that the input file has the appropriate data in its specified format

Solved in collaboration with Mohit Manoj :)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Matrix {
    int rows;
    int columns;
    int **e; // elements the form of an array
};


void perform_convolution(struct Matrix *image, struct Matrix *kernel, struct Matrix *target) {

    int row_limit = (int)(kernel->rows)/2;
    int column_limit = (int)(kernel->columns)/2;
    
    for ( int row = 0; row < image->rows; row++ ) {
        for ( int column = 0; column < image->columns; column++ ) {
            
            int element = 0;
        
            for ( int i = 0; i < kernel->rows; i++ ) {
                for ( int j = 0; j < kernel->columns; j++ ) {
                    
                    /*
                    To understand these coordinates, picture the image as a grid, which lies behind
                    the kernel. We are moving the kernel using an intuitive sliding window algorithm
                    row_index and column_index are used to locate the corresponding grid coordinates
                    to which the kernel element is to be multiplied with.
                    */ 
                    int row_index = row + i - row_limit;
                    int column_index = column + j - column_limit;
                    
                    // Multiply the kernel element with the image element only if it is within the appropriate bounds
                    if ( row_index >= 0 && column_index >= 0 && row_index < image->rows && column_index < image->columns ) {

                        element += image->e[row_index][column_index] * kernel->e[i][j];
                    }
                  
                }
            }
            target->e[row][column] = element;
        }
    }
}

// To take input
struct node {
    int data;
    struct node *next;
};

void insert(struct node *head, int element){
    struct node *current = head;
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = element;
    tmp->next = NULL;

    while ( current->next != NULL ) {
        current = current->next;
    }

    current->next = tmp;
}

// Dynamically allocates a 2D Matrix with its specified number of rows and columns
void matrixDeclaration( struct Matrix *matrix, int rows, int columns ) {

    matrix->e = (int**) malloc(matrix->rows * sizeof(int));
    for ( int i = 0; i < matrix->rows; i++ ) {

        matrix->e[i] = (int*)malloc(matrix->columns * sizeof(int));
    }
}


// Prints a linked list (for debugging purposes)
void printList( struct node *head ) {

    printf( "\nLinked List:\n" );
    struct node *current = head;
    
    if ( current->next == NULL ) {
        printf("Empty List!\n");
        return;
    }
    current = current->next;

    while( current->next != NULL ) {
        printf( "%d ", current->data );
        current = current->next;
    }

    printf("\n");
}


// Prints a 2D Array (for debugging purposes)
void printMatrix( int **arr, int rows, int columns ) {

    printf( "Matrix:\n" );
    for ( int i = 0; i < rows; i++ ) {
        for ( int j = 0; j < columns; j++ ) {
            printf( "%d ", arr[i][j] );
        }
        printf("\n");
    }
}


int main() {
    FILE *file;
    file = fopen("input_convolution.txt", "r");

    if ( file == NULL ) {
        printf( "Could not open the file!\n" );
        exit(-1);
    }

    /*
    Taking file input
    */
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;

    // Stores file data
    int file_int = 0;

    while ( fscanf( file, "%d", &file_int ) != EOF ) {
        insert( head, file_int );
    }
    
    // Insert the last element as well
    insert( head, file_int );

    fclose(file);


    /*
    Program Parameters
    Now we will traverse the Linked List and assign values to the Program Parameters
    */
    struct node *current = head;
    current = current->next;

    int kernel_details[3]; // Number of Rows, Number of Columns, Number of Elements
    struct Matrix *kernel = (struct Matrix*)malloc(sizeof(struct Matrix));
    
    // First row contains the Kernel Details
    kernel->rows = current->data;
    current = current->next;
    kernel->columns = current->data;
    current = current->next;
    current = current->next; // We don't want to store the size of the kernel
    
    // Declaration of kernel
    matrixDeclaration( kernel, kernel->rows, kernel->columns );
    
    // Initialization of kernel
    for ( int i = 0; i < kernel->rows; i++ ) {
        for ( int j = 0; j < kernel->columns; j++ ) {
            // Skipping 2 elements since they mention the row and columns (which we already have)
            current = current->next;
            current = current->next;

            kernel->e[i][j] = current->data;
            current = current->next;
        }
    }

    struct Matrix *image = (struct Matrix*)malloc(sizeof(struct Matrix));

    // The row contains the Image Details
    image->rows = current->data;
    current = current->next;
    image->columns = current->data;
    current = current->next;
    current = current->next; // We don't want to store the size of the image

    // Declaration of the image
    matrixDeclaration(image, image->rows, image->columns);

    // Initialization of the image
    for ( int i = 0; i < image->rows; i++ ) {
        for ( int j = 0; j < image->columns; j++ ) {
            // Skipping 2 elements since they mention the row and columns (which we already have)
            current = current->next;
            current = current->next;

            image->e[i][j] = current->data;
            current = current->next;
        }
    }

    struct Matrix *result = (struct Matrix*)malloc(sizeof(struct Matrix));
    result->rows = image->rows;
    result->columns = image->columns;  // Dimensions of the result are the same as the image

    // Declaration of result
    matrixDeclaration(result, result->rows, result->columns);
    
    perform_convolution( image, kernel, result );

    // Put this result in the file, and check
    FILE *output_file;
    output_file = fopen("output_convolution.txt","w");
    
    for( int i = 0; i < result->rows; i++ ) {
        for ( int j = 0; j < result->columns; j++ ) {

            fprintf(output_file, "%d ", result->e[i][j] );
        }
        fprintf( output_file, "\n" );
    }

    fclose(output_file);

    // Free the heap memory. (not really needed, since the program is going to be terminated anyway)
    free(image);
    free(kernel);
    free(result);
    struct node *tmp = head;
    struct node *prev = head;
    while ( tmp->next != NULL ) {
        prev = tmp;
        tmp = tmp->next;
        free(prev);
    }
    free(tmp);

    printf("Image Convolution Done Successfully!\n");
    
    return 0;
}