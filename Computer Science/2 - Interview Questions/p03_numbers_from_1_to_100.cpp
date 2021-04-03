/*
Write a program to print numbers from 1 to 100...
(Without using any numbers in your code)

Credits to:
Naveen AutomationLabs Youtube Channel
https://www.youtube.com/watch?v=_BXSdPNFnX8
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