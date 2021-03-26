/*
Write a program to print numbers from 1 to 100...
(Without using any numbers in your code)
*/

#include <iostream>

int main() {

    int a = 'a'/'a';
    std::string str = "..........";
    int limit = str.length();

    while ( a <= limit * limit ) {
        printf( "%d\n", a++ );
    }
}