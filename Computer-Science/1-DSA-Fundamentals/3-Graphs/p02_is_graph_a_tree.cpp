/*
Write a program to check whether a graph is a tree or not.
A graph is a tree if it has only 1 component, and if it has no cycles
A graph has a cycle if, while traversing, we reach a previously visited node (back edge)

Testing done on Graphs A and B
Graph A            

     0
    / \
   1   2
  /   / \
 3   4   5
        /
       6

Graph B

   0
  / \
 1   2 
  \ /
   3 --- 4

*/

#include <iostream>
#include <vector>

using namespace std;


// Perform Depth First Search and check for a cycle
bool check_cycle( vector<vector<int>> graph, int source, vector<bool> &found, int parent ) {

    // Visit the starting node
    found[source] = true;

    for ( int v : graph[source] ) {

        // If the current node has not been visited, perform DFS on it
        if ( !found[v] ) {

            if ( !check_cycle(graph, v, found, source) ) 
                return false; 
        }

        else if ( v != parent ) 
            // We found an edge leading to one of the previous nodes
            return false; 
    }

    return true;
}


// Returns true if there is one component
bool is_tree( vector<vector<int>> graph, int N ) {

     vector<bool> found(N);

    if ( !check_cycle(graph, 0, found, -1) ) {
        return false; // If a cycle is found, the graph is not a tree
    }

    // Check if the graph has exactly one component
    // If any nodes were left unvisited, this would be false
    for ( auto v : found ) {
        if ( !v ) 
            return false;
    }

    // passed all checks, therefore the graph is a tree
    return true;
}


int main() {

    
    // The graph is represented as an adjacency list

    int N1 = 7;
    vector<vector<int>> graph1 = { {1,2}, {3,0}, {0,4,5}, {1}, {2}, {2,6}, {5} };

    int N2 = 5;
    vector<vector<int>> graph2 = { {1,2}, {0,3}, {0,3}, {1,2,4}, {3} };

    if ( is_tree(graph1, N1) )
        cout << "Graph A is a Tree!\n";
    else
        cout << "Graph A is not a Tree\n";


    if ( is_tree(graph2, N2) )
        cout << "Graph B is a Tree!\n";
    else 
        cout << "Graph B is not a Tree\n";
    
    return 0;
}