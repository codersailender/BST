//
//  main.cpp
//  BST
//
//  Just a BST practice
//

#include <iostream>

using namespace std;

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    Node() {
        key = 0;
        left = NULL;
        right = NULL;
    }
};

struct Node* root = NULL;

void printBST(struct Node* node) {
    if (node==NULL) {
        return;
    }
    
    printBST(node->left);
    cout << node->key << " ";
    printBST(node->right);
}

void deleteBST(struct Node* node) {
    if (node == NULL) {
        return;
    }
    deleteBST(node->left);
    deleteBST(node->right);
    delete node;
}

struct Node* getNode(int key) {
    struct Node* node =  new Node();
    node->key = key;
    return node;
}

Node* getNextMinValue(Node* node) {
    if (node->right != NULL) {
        return getNextMinValue(node->right);
    } else {
        return node;
    }
}

Node* deleteNode(Node* node, int key) {
    if (node == NULL) {
        return node;
    }
    
    if (node->key > key) {
        node -> left = deleteNode(node->left, key);
    } else if (node -> key < key) {
        node -> right = deleteNode(node->right, key);
    } else {
        if (node->left == NULL) {
            Node* temp  = node->right;
            delete node;
            return temp;
        } else if (node->right == NULL) {
            Node* temp = node -> left;
            delete node;
            return temp;
        }
        
        Node* minNode = getNextMinValue(node->left);
        node->key = minNode->key;
        node->left = deleteNode(node->left, minNode->key);
    }
    
    return node;
}

Node* insertNode(Node* node, int key) {
    if (node == NULL) {
        node =  getNode(key);
    } else {
        if (node->key < key) {
            node->right = insertNode(node->right, key);
        } else {
            node->left = insertNode(node->left, key);
        }
    }
    
    return node;
}

int main(int argc, const char * argv[]) {
    int n=10;
    int list[10] = {34, 23, 56, 88, 23, 998, 77, 34, 12233, 5609};
    for (int i=0; i<n; i++) {
        root = insertNode(root, list[i]);
    }
    
    cout<<endl<<endl;
    printBST(root);
    
    root = deleteNode(root, 77);
    cout<<endl<<endl;
    printBST(root);
    
    root = deleteNode(root, 10);
    cout<<endl<<endl;
    printBST(root);
    
    root = deleteNode(root, 34);
    cout<<endl<<endl;
    printBST(root);
    
    deleteBST(root);
    root = NULL;
    return 0;
}

