/*
This program helps print a matrix in an organized format
Will be used extensively in future codes
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void pretty_print_matrix( vector< vector<float> > matrix, int rows, int columns, string matrix_name ) {
    
    // Keeps track of the length of the largest number
    int max_len = 0;

    for ( int i = 0; i < rows; i++ ) {
        for ( int j = 0; j < columns; j++ ) {

            float element = matrix[i][j];
            string s_element = to_string( element );

            if ( s_element.length() > max_len ) {
                max_len = s_element.length();
            }
        }
    }

    cout << "Matrix '" << matrix_name << "':" << endl;

    printf( "--\n" );
    for ( int i = 0; i < rows; i++ ) {
        printf( "| " );
        for ( int j = 0; j < columns; j++ ) {
            float element = matrix[i][j];
            
            string s_element = to_string( element );
            int length = s_element.length();

            s_element = s_element.substr( 0, length-4 ); // For practical reasons we want accuracy up to 2 decimals
            cout << s_element;
            while ( length < max_len ) {
                printf( " " );
                length++;
            }
            
            printf( "   " );
        }
        printf( " |\n" );
    }

    
}


int main() {

    vector< vector<float> > matrix;
    int rows, columns;
    string name;
    printf( "Enter number of rows and columns: " );
    scanf( "%d %d", &rows, &columns );

    printf( "Enter the name of the matrix: " );
    cin >> name;

    printf( "Enter the matrix:\n" );
    for ( int i = 0; i < rows; i++ ) {
        vector<float> row_vector;

        for ( int j = 0; j < columns; j++ ) {
            float element;
            scanf( "%f", &element );
            row_vector.push_back( element );
        }

        matrix.push_back( row_vector );
    }

    pretty_print_matrix( matrix, rows, columns, name );


    return 0;
}