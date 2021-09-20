#include "bst.h"
#include <stdio.h>

BST::BST() {
    root = nullptr;
    _size = 0;
}

void BST::recursive_destruct(node* n) {
    if (n == nullptr) {
        return;
    }
    recursive_destruct(n->left);
    recursive_destruct(n->right);
    delete n;
}

BST::~BST() {
    recursive_destruct(root);
}

BST::node* BST::new_node(int key) {
    node *tmp = new node;
    tmp->key = key;
    tmp->left = nullptr;
    tmp->right = nullptr;
    _size++;
    return tmp;
}

unsigned int BST::size() {
    return _size;
}

bool BST::find(int target) {
    node *cursor = root;
    while (cursor != nullptr) {
        if (cursor->key > target) {
            cursor = cursor->left;
        } else if (cursor->key < target) {
            cursor = cursor->right;
        } else {
            return true;
        }
    }
    return false;
}

BST::node* BST::recursive_insert(node* n, int key) {
    if (n == nullptr) {
        return new_node(key);
    }

    if (key < n->key) {
        n->left = recursive_insert(n->left, key);
    } else {
        n->right = recursive_insert(n->right, key);
    }

    return n;
}

void BST::insert(int key) {
    root = recursive_insert(root, key);
}

BST::node* BST::recursive_remove(node* n, int key) {
    if (n == nullptr) {
        return n;
    }

    if (key < n->key) {
        n->left = recursive_remove(n->left, key);
    } else if (key > n->key){
        n->right = recursive_remove(n->right, key);
    } else {
        _size--;
        if (n->left == nullptr && n->right == nullptr) {
            delete n;
            return nullptr;
        } else if (n->left == nullptr) {
            node* tmp = n->right;
            delete n;
            return tmp;
        } else if (n->right == nullptr) {
            node* tmp = n->left;
            delete n;
            return tmp;
        }
        
        node* right_min = n->right;
        while(right_min->left != nullptr) {
            right_min = right_min->left;
        }
        n->key = right_min->key;
        n->right = recursive_remove(n->right, n->key);
    }
    return n;
}

void BST::remove(int key) {
    root = recursive_remove(root, key);
    _size--;
}

void BST::traversal() {
    recursive_traverse(root);
    puts("");
}

void BST::recursive_traverse(node *n) {
    if (n == nullptr) {
        return;
    }
    recursive_traverse(n->left);
    printf("%d ", n->key);
    recursive_traverse(n->right);
}