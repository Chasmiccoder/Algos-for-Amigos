#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> decimal_to_binary( int n ) {

    int size = ceil ( log2(n) );
    vector<int> binary;

    int i = 0;
    while ( n > 0 ) {
        binary.push_back( n % 2 );
        n = n / 2;
        i++;
    }
    reverse( binary.begin(), binary.end() );
    return binary;
}


int main () {
    
    int num;
    printf( "Enter number in decimal: " );
    scanf( "%d", &num );

    vector<int> binary_number = decimal_to_binary( num );
    int size = binary_number.size();

    printf( "Number in Binary:\n" );
    for ( int i = 0; i < size; i++ ) 
        printf( "%d", binary_number[i] );
    printf( "\n" );

    return 0;
}