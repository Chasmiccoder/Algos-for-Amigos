/* Conduct a Balanced Bracket Check using a Stack 

Naming Convention -
'()' are parentheses
'[]' are brackets
'{}' are braces

Examples - 
" { hello [ world ( ) ] } "          Balanced string.
" { ] hello } "                      Unbalanced, too many closing brackets.
" { ( (  "                           Unbalanced, too many opening parentheses.
" { ( } world ) "                    Unbalanced, braces mismatched.

Algorithm Explanation -
Iterate throught the string using integer i
If the character at ith index is an opening bracket, push it to the stack
If it is a closing bracket, and its bracket type matches the one in the stack, pop it out (decrement top)
If at any time in the loop, the stack encounters underflow, there are too many closing brackets

At the end of iteration, if the stack is not empty, then the number of closing brackets 
was not enough to balance the opening ones.

*/

#include <stdio.h>
#include <string.h>

char opening_type( char a ) {
    if ( a == '}' )
        return '{';
    if ( a == ']' )
        return '[';
    if ( a == ')' ) 
        return '(';

    else return 1;
}


int check_balanced_bracket( char *string, int len ) {
    /* Function iterates through a string, and returns 0, if the parentheses, brackets, and braces
       are balanced.
       If there are too many opening brackets, it returns 1.
       If there are too many closing brackets or if there is bracket type mismatch, it returns 2. */

    char stack[ len ];
    int top = 0, i = 0;

    for ( i = 0; i < len; i++ ) {
        if ( string[i] == '{' || string[i] == '[' || string[i] == '(' ) {
            // If strcmp returns 0, the strings are equal    
            stack[ top ] = string[ i ];
            top++;   
        }

        else if ( string[i] == '}' || string[i] == ']' || string[i] == ')' ) {
            if ( stack[ top-1 ] == opening_type( string[i] ) )
                top--;
            else 
                return 2;   
        }

        // If at any time the stack encounters underflow, there are too many closing brackets
        if ( top < 0 )
            return 2;
    }
    
    if ( top == 0 )
        return 0;
    
    else
        return 1;
}

int main() {
    printf("\n");

    char string[1000];
    printf( "Enter string:\n" );
    gets( string );
    int length = strlen( string );

    printf( "\n" );

    int result = check_balanced_bracket( string, length );

    if ( result == 0 ) {
        printf( "Balanced Expression\n");
    }
    else if ( result == 1 ) {
        printf( "Unbalanced Expression\nToo many opening brackets\n" );
    }

    else {
        printf( "Unbalanced Expression\nToo many closing brackets\n" );
    }

    printf( "\n" );

    return 0;
}