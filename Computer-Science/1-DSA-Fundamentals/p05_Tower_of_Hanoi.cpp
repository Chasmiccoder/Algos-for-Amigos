/*
Solution to the Tower of Hanoi Problem For 3 pegs

Task: Move all disks from the first peg to the third peg

How the puzzle is set up.
Each vector in the structure is a peg
Empty spaces are 'stored' as n+1. For example, if the game has 3 disks, 
then the empty spaces are stored as 4. While printing the game, they are printed as a blank


References:
https://en.wikipedia.org/wiki/Tower_of_Hanoi
*/

#include <iostream>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::vector;


struct towers {
    vector<int> pegA, pegB, pegC;
};


void printPuzzle( towers *puzzle, int iter, int n ) {

    if ( iter != -1 ) 
        cout << "Tower of Hanoi, after move: " << iter << " \n";
    else
        cout << "Final Solution to the Puzzle:\n";
    
    cout << "================================\n"; 

    for ( int i = n-1; i >= 0; i-- ) {

        if ( puzzle->pegA[i] == n+1 )
            cout << "  ";
        else
            cout << puzzle->pegA[i] << " ";
        
        if ( puzzle->pegB[i] == n+1 )
            cout << "  ";
        else
            cout << puzzle->pegB[i] << " ";
        
        if ( puzzle->pegC[i] == n+1 )
            cout << "  ";
        else
            cout << puzzle->pegC[i] << " ";
        
        cout << endl;
        
    }

    cout << "================================\n";
}


bool complete( towers *puzzle, int n ) {
    /* 
    Returns true if the puzzle is complete
    Else returns false
    */
    
    int disk = n;
    for( int i = 0; i < n; i++ ) {
        if ( puzzle->pegC[i] != disk ) {
            return false;
        }
        disk--;
    }
    return true;
}


int pop( vector<int>& stack, int *top, int n ) {
    if ( *top <= -1 ) {
        return -1;
    }
    
    int top_element = stack[ *top ];
    stack[ *top ] = n + 1; // replacing blank with n+1
    *top = *top - 1;

    return top_element;
}


bool push( vector<int>& stack, int *top, int element, int n ) {
    if ( *top >= n - 1 ) {
        return false;
    }

    *top = *top + 1;
    stack[ *top ] = element;
    
    return true;
}


bool move( vector<int>& first, vector<int>& second, int *top_1, int *top_2, int n ) {
    /*
    Takes two stacks and makes a legal move

    disk1 = Disk at the top of the first stack 
    disk2 = Disk at the top of the second stack
    If disk1 > disk2, then move disk2 from the second the first stack
    Else move disk1 from the first to the second stack
 
    */
    
    // If the first stack is empty, push the disk from the second into the first
    // This is to prevent disk1 and disk2 from getting garbage values
    if ( *top_1 == -1 ) {
        int disk = pop( second, top_2, n );
        push( first, top_1, disk, n );
        return true;
    }

    if ( *top_2 == -1 ) {
        int disk = pop( first, top_1, n );
        push( second, top_2, disk, n );
        return true;
    }

    int disk1 = first[ *top_1 ];
    int disk2 = second[ *top_2 ];

    if ( disk1 < disk2 ) {
        int disk = pop( first, top_1, n );
        push( second, top_2, disk, n );
    }
    
    if ( disk1 > disk2 ) {
        int disk = pop( second, top_2, n );
        push( first, top_1, disk, n );
    }

    return true;
}


void solve( int n ) {
    /*
    Solves the Puzzle
    n = Number of disks in the first peg

    Using the simple iterative solution:
    * make the legal move between pegs A and B (in either direction),
    * make the legal move between pegs A and C (in either direction),
    * make the legal move between pegs B and C (in either direction),
    * repeat until complete
    
    */
    
    towers *puzzle = new towers;
    
    int top_1, top_2, top_3;
    top_1 = top_2 = top_3 = -1;

    // Initialize the puzzle
    for ( int i = n; i >= 1; i-- ) {
        puzzle->pegA.push_back( i );
        puzzle->pegB.push_back( n+1 );
        puzzle->pegC.push_back( n+1 );
    }

    top_1 = n-1;

    cout << "Start of the puzzle:\n";
    printPuzzle( puzzle, 0, n );

    int iter = 1;

    while ( true ) {

        // For even number of disks
        if ( n%2 == 0 ) {
            move( puzzle->pegA, puzzle->pegB, &top_1, &top_2, n );
            if ( complete(puzzle,n) )
                break;
            printPuzzle( puzzle, iter++, n );

            move( puzzle->pegA, puzzle->pegC, &top_1, &top_3, n );
            if ( complete(puzzle,n) )
                break;
            printPuzzle( puzzle, iter++, n );
        }

        // For odd number of disks
        else {
            move( puzzle->pegA, puzzle->pegC, &top_1, &top_3, n );
            if ( complete(puzzle,n) )
                break;
            printPuzzle( puzzle, iter++, n );

            move( puzzle->pegA, puzzle->pegB, &top_1, &top_2, n );
            if ( complete(puzzle,n) )
                break;
            printPuzzle( puzzle, iter++, n );
        }

        move( puzzle->pegB, puzzle->pegC, &top_2, &top_3, n );
        
        if ( complete(puzzle,n) )
                break;
        
        printPuzzle( puzzle, iter++, n );
    }
    printPuzzle( puzzle, iter, n );

    cout << endl;
    printPuzzle( puzzle, -1, n );
}


int main() {
    cout << endl;
    cout << endl;

    cout << "Solution to the Tower of Hanoi Problem (3 Pegs):\n\n";

    int number_of_disks;
    cout << "Enter Number of Disks: ";
    cin >> number_of_disks;

    cout << "================================\n"; 

    solve( number_of_disks );

    return 0;
}