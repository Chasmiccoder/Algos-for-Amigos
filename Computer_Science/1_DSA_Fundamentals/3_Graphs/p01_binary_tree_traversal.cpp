#include <iostream>
#include <vector>


struct node {
    char data;
    node *left, *right;

    // Assign values to nodes during instantiation
    node( char element ) {
        data = element;
        left = NULL;
        right = NULL;
    }
};


void pre_order( node *parent, std::vector<char>& target ) {
    if ( parent == NULL ) {
        return;
    }

    target.push_back( parent->data );

    pre_order( parent->left, target );

    pre_order( parent->right, target );

}


void in_order( node *parent, std::vector<char>& target ) {
    if ( parent == NULL ) {
        return;
    }

    in_order( parent->left, target );

    target.push_back( parent->data );

    in_order( parent->right, target );
}


void post_order( node *parent, std::vector<char>& target ) {
    if ( parent == NULL ) {
        return ;
    }

    post_order( parent->left, target );

    post_order( parent->right, target );

    target.push_back( parent->data );
}


// Generates binary tree with linked list concept, from its array representation
node* generate_binary_tree(char *arr, node* root, int i, int n ) {
    if ( i < n ) {
        node *temp = new node( arr[i] );

        root = temp;

        root->left = generate_binary_tree(arr, root->left, 2*i + 1, n );

        root->right = generate_binary_tree(arr, root->right, 2 * i + 2, n );
    }

    return root;
}


void printVector( const std::vector<char> vi ) {
    for( auto x : vi ) {
        
        if ( x != '0' )
            std::cout << x << " ";
    }
    std::cout << "\n";
}


int main () {

    std::cout << "\n\nFind the Preorder, Inorder and Postorder Traversals of a Binary Tree:\n";
    std::cout << "=====================================================================\n";
    std::cout << "(Enter 0 For Empty Node)\n\n";

    int n;

    std::cout << "Enter number of nodes in the Binary Tree: ";
    std::cin >> n;

    char *binary_tree = new char[n];

    std::cout << "\nEnter the elements:\n";

    for ( int i = 0; i < n; i++ ) {
        std::cin >> binary_tree[i];
    }

    std::cout << "\n";

    node *root;
    root = generate_binary_tree( binary_tree, root, 0, n );

    std::vector<char> preOrder;
    std::vector<char> inOrder;
    std::vector<char> postOrder;

    pre_order( root, preOrder );
    in_order( root, inOrder );
    post_order( root, postOrder );

    std::cout << "Pre Order Sequence:\n";
    printVector( preOrder );

    std::cout << "In Order Sequence:\n";
    printVector( inOrder );

    std::cout << "Post Order Sequence:\n";
    printVector( postOrder );

    std::cout << "\n";
    
    return 0;
}