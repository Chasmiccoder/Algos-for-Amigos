/*
Problems:
https://leetcode.com/problems/binary-tree-preorder-traversal/
https://leetcode.com/problems/binary-tree-inorder-traversal/
https://leetcode.com/problems/binary-tree-postorder-traversal/

Find the preorder, inorder and postorder traversals of a given binary tree
*/

#include <iostream>
#include <vector>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vi;
        preorder(root, vi);
        return vi;
    }
    
    void preorder(TreeNode* node, vector<int>& route) {
        if(node == NULL) {
            return;
        }
        
        route.push_back(node->val);
        preorder(node->left, route);
        preorder(node->right, route);
    }
    

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vi;
        inorder(root, vi);
        return vi;
    }

    void inorder(TreeNode* node, vector<int>& route) {
        if(node == NULL) {
            return;
        }
        
        inorder(node->left, route);
        route.push_back(node->val);
        inorder(node->right, route);
    }


    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vi;
        postorder(root, vi);
        return vi;
    }
    
    void postorder(TreeNode* node, vector<int>& route) {
        if(node == NULL) {
            return;
        }
        
        postorder(node->left, route);
        postorder(node->right, route);
        route.push_back(node->val);
    }
};

