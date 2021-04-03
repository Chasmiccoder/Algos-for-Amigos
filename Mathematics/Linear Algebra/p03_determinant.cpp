/*
This code helps find the determinant of any square matrix

Algorithm:
==========

(1) Find the determinant of the input matrix
To do this, find the minor of all the elements in the first row (and then add the cofactors to get the result)
Trivially solve 1x1 and 2x2 determinant, and use recursion to solve higher order determinants

(2) Find the minor of an element
To do this (for element Aij), create a matrix such that the elements are not from the ith row or the jth column
Then find the determinant of that matrix formed

This code uses the natural way of solving a determinant along the first row
It breaks the entire matrix down into fundamental 2x2 matrices and solves the determinant recursively!


Function minor_in_matrix_form() has been named this way because a minor is the determinant of 
the matrix formed after removing the rows and columns similar to that of the element whose minor is to be found
The function doesn't return a minor directly. It returns its matrix instead

*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


vector< vector<float> > minor_in_matrix_form( vector< vector<float> > matrix, int row, int column, int size );
float determinant( vector< vector<float> > matrix, int size );


void print_matrix( vector<vector<float>> vi ) {
    for ( int i = 0; i < vi.size(); i++ ) {
        for ( int j = 0; j < vi[i].size(); j++ ) {
            cout << vi[i][j] << " ";
        }
        cout << endl;
    }
}


vector< vector<float> > minor_in_matrix_form( vector< vector<float> > matrix, int row, int column, int size ) {
    /*
    Returns a matrix that corresponds to the minor of an element in a given row and column 
    */
    
    if ( size == 1 ) {
        return { {0} };
    }

    vector< vector<float> > minor_matrix;

    for ( int i = 0; i < size; i++ ) {
        vector<float> matrix_row;

        for ( int j = 0; j < size; j++ ) {

            if ( i != row && j != column ) {
                float element = matrix[i][j];
                matrix_row.push_back( element );
            }
        }

        if ( matrix_row.size() != 0 ) {
            minor_matrix.push_back( matrix_row );
        }
    }

    return minor_matrix;
}


float determinant( vector< vector<float> > matrix, int size ) {
    /*
    Returns the determinant of a square matrix with a specified size
    */

    // Trivially solve the determinant if it is 1x1 or 2x2
    if ( size == 1 ) {
        return matrix[0][0];
    }
    if ( size == 2 ) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    float result = 0;

    // Loop through the first row and find the sum of the cofactors
    for ( int i = 0; i < size; i++ ) {
        float element = matrix[0][i];

        // If a row element is zero, we don't need to calculate the minor, since it won't affect the result
        if ( element == 0 ) {
            continue;
        }

        vector< vector<float> > minor_matrix;
        minor_matrix = minor_in_matrix_form( matrix, 0, i, size );
    
        result += ((int)pow( -1, i ))  *  element  *  determinant( minor_matrix, size - 1 ); 
    }

    return result;
}


int main() {

    int size;

    printf( "\nDeterminant Calculator!\n\n" );
    printf( "Enter the size of the square matrix: " );
    scanf( "%d", &size );

    vector< vector<float> > matrix;

    // Taking input from the user:
    printf( "Enter the matrix:\n" );
    for ( int i = 0; i < size; i++ ) {
        vector<float> row;

        for ( int j = 0; j < size; j++ ) {
            float element;
            scanf( "%f", &element );
            row.push_back( element );
        }

        matrix.push_back( row );
    }


    float det = determinant( matrix, size );
    printf( "The determinant of the given matrix is: %.2f\n", det );

    return 0;
}