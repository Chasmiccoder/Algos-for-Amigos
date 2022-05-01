/*
{ Work in progree }

Working with undirected graph
Using linked list to implement edges in graph
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node** initialize_graph(int size) {
    struct Node **graph = (struct Node**)malloc((size+1) * sizeof(struct Node*));

    for (int i = 0; i < size; i++ ) {
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        node->data = i;
        node->next = NULL;
        graph[i] = node;
    }

    return graph;
}


void insertEdge(int u, int v, struct Node** graph, int repeat) {

    // Add node v to the linked list of node u
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));

    node->data = v; // 1
    node->next = NULL;

    // For traversal through linked list of node u
    // struct Node *current = &graph[u];
    
    // struct Node *current = graph[u]->next;
    struct Node *current = graph[u]; // 2

    if ( current->next == NULL ) {
        current->next = node;

        if ( repeat == 1 ) {
            insertEdge(v,u,graph,0);
        }
        return;
    }

    else {

        while ( current->next != NULL ) {
            current = current->next;
        }
        current->next = node;

        // Add node u to the linked list of node v (remove this for directed graphs)
        if ( repeat == 1 ) {
            insertEdge(v,u,graph,0);
        }
    }
}


void deleteEdge(int u, int v, struct Node **graph, int repeat) {

    // Delete node v from node u's linked list
    // struct Node *current = &graph[u];
    struct Node *current = graph[u];

    if ( current->next == NULL ) {
        return;
    }

    // If the first friend of u happens to be v
    if ( current->next->data == v ) {
        current = current->next;
        graph[u]->next = current->next; // Check for the case in which there is only 1 edge, and that edge needs to be deleted
        free(current);
    }

    else {
        // Keep track of the previous node
        // struct Node *previous = &graph[u];
        struct Node *previous = graph[u];
        int i = 0;

        current = current->next;

        while( current->data != v ) {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        free(current);
    }

    if ( repeat == 1 ) {
        deleteEdge(v,u,graph,0);
    }
}


void printGraph(struct Node **graph, int size) {
    /*
    Helper function
    */

    printf("Graph:\n");
    printf("======\n");

    // no need to print dummy node (0th node)
    for( int i = 1; i < size; i++ ) {
        

        struct Node *current = graph[i];
        printf("Friends of Vertex: %d\n", current->data);

        // printf("lkslf\n");
        // printf("%d", current->data);
        int j = 0;

        if ( current->next == NULL ) {
            printf("\n");
            continue;
        }
        else {
            current = current->next;
            while( current->next != NULL ) {
                printf("%d ", current->data);
                current = current->next;
            }
            printf("%d\n", current->data);
        }
    }
    printf("======\n\n");
}


//untested
void deleteNode(int vertex, struct Node **graph, int size) {

    for ( int i = 0; i < size; i++ ) {

        struct Node *node = graph[i];
        
        if ( graph[i]->data == vertex ) {
            graph[i]->data = 0;
            graph[i]->next = NULL;
        }

        else {
            deleteEdge(graph[i]->data,vertex,graph,0);
        }
    }
}


int main() {

    printf("Graph Implementation from scratch:\n");
    return 0;
}