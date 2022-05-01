/*
Program to Multiply 2 matrices using the naive O(n^3) approach
*/

#include <iostream>
#include <vector>

using namespace std;


vector< vector<float> > multiply_matrices( vector<vector<float>> matrix1, int rows1, int columns1, vector<vector<float>> matrix2, int rows2, int columns2 ) {
    if ( columns1 != rows2 ) {
        printf( "The Two Matrices cannot be multiplied!\n" );
        return {{0}};
    }

    vector< vector<float> > product;
    
    for ( int i = 0; i < rows1; i++ ) {
        vector<float> row;

        for ( int j = 0; j < columns2; j++ ) {
            float product_element = 0;

            for ( int k = 0; k < columns1; k++ ) {
            
                float element1 = matrix1[i][k];
                float element2 = matrix2[k][j];

                product_element += element1 * element2;
            }
            row.push_back( product_element );
        }
        product.push_back( row );
    }

    return product;
}


vector<vector<float>> input_matrix( int rows, int columns ) {
    vector<vector<float>> matrix;

    printf( "Enter the matrix:\n" );
    for ( int i = 0; i < rows; i++ ) {
        vector<float> row;
        
        for ( int j = 0; j < columns; j++ ) {
            float element;
            scanf("%f", &element );
            row.push_back( element );
        }

        matrix.push_back( row );
    }

    return matrix;
}


int main() {
    printf( "\n" );

    vector<vector<float>> matrix1;
    vector<vector<float>> matrix2;
    int rows1, columns1, rows2, columns2;

    printf( "Enter the number of rows and columns of first matrix: " );
    scanf( "%d %d", &rows1, &columns1 );
    matrix1 = input_matrix( rows1, columns1 );
    
    printf( "\n" );

    printf( "Enter the number of rows and columns of second matrix: " );
    scanf( "%d %d", &rows2, &columns2 );
    matrix2 = input_matrix( rows2, columns2 );

    vector<vector<float>> result = multiply_matrices( matrix1, rows1, columns1, matrix2, rows2, columns2 );


    vector<vector<float>> dummy = {{0}};
    if ( result != dummy ) {

        printf( "\nProduct of the two matrices:\n" );
        for ( auto row : result ) {
            for ( auto element : row ) {
                cout << element << " ";
            }
            cout << endl;
        }
    }

    return 0;
}