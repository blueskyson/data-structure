#include <stdio.h>

class BST
{
public:
    class node
    {
    public:
        int key;
        node *left, *right;
        node(int);
    };
    BST();
    ~BST();
    unsigned int size();
    bool find(int);
    void insert(int);
    void remove(int);
    void _remove(int);
    void traversal();
private:
    void traversal_recur(node*);
    void destruct_recur(node*);
    node* root;
    unsigned int _size;
};

BST::BST()
{
    root = nullptr;
    _size = 0;
}

BST::~BST()
{
    destruct_recur(root);
}

void BST::destruct_recur(node* n) {
    if (n == nullptr) {
        return;
    }
    destruct_recur(n->left);
    destruct_recur(n->right);
    delete n;
}

BST::node::node(int k)
{
    key = k;
    left = nullptr;
    right = nullptr;
}

unsigned int BST::size()
{
    return _size;
}

bool BST::find(int target)
{
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

void BST::insert(int target)
{
    if (root == nullptr) {
        root = new node(target);
        _size = 1;
        return;
    }

    node *cursor = root;
    while (1) {
        if (cursor->key > target) {
            if (cursor->left == nullptr) {
                cursor->left = new node(target);
                _size++;
                break;
            } else {
                cursor = cursor->left;
            }
        } else if (cursor->key < target) {
            if (cursor->right == nullptr) {
                cursor->right = new node(target);
                _size++;
                break;
            } else {
                cursor = cursor->right;
            }
        } else {
            /* key already exists */
            return;
        }
    }
    return;
}

void BST::remove(int target)
{
    if (root == nullptr) {
        return;
    }

    if (root->key == target) {
        node* del = root;
        if (_size == 1) {
            root = nullptr;
        } else if (root->left == nullptr) {
            root = root->right;
        } else if (root->right == nullptr) {
            root = root->left;
        } else {
            node *cursor = root->right;
            node *prev = root;
            while (cursor->left != nullptr) {
                prev = cursor;
                cursor = cursor->left;
            }
            root->key = cursor->key;
            if (prev == root) {
                root->right = nullptr;
            } else {
                prev->left = nullptr;
            }
            del = cursor;
        }
        delete del;
        _size--;
        return;
    }

    node *cursor = root, *prev;
    int LEFT = 0, RIGHT = 1, branch;
    while (1) {
        if (cursor->key > target) {
            if (cursor->left == nullptr) {
                /* no such key */
                return;
            } else {
                prev = cursor;
                cursor = cursor->left;
                branch = LEFT;
            }
        } else if (cursor->key < target) {
            if (cursor->right == nullptr) {
                /* no such key */
                return;
            } else {
                prev = cursor;
                cursor = cursor->right;
                branch = RIGHT;
            }            
        } else {
            /* target key is found */
            break;
        }
    }

    node *del = cursor;
    if (branch == LEFT) {
        if (cursor->left == nullptr) {
            prev->left = cursor->right;
        } else if (cursor->right == nullptr) {
            prev->right = cursor->left;
        } else {
            prev = cursor;
            node *tmp = cursor->right;
            while (tmp->right != nullptr) {
                prev = tmp;
                tmp = tmp->right;
            }
            cursor->key = tmp->key;
            prev->right = nullptr;
            del = tmp;
        }
    } else if (branch == RIGHT) {
        if (cursor->right == nullptr) {
            prev->right = cursor->left;
        } else if (cursor->left == nullptr) {
            prev->right = cursor->right;
        } else {
            prev = cursor;
            node *tmp = cursor->left;
            while (tmp->left != nullptr) {
                prev = tmp;
                tmp = tmp->left;
            }
            cursor->key = tmp->key;
            prev->left = nullptr;
            del = tmp;
        }
    }
    delete del;
    _size--;
}

void BST::traversal()
{
    traversal_recur(root);
    puts("");
}

void BST::traversal_recur(node *n)
{
    if (n == nullptr) {
        return;
    }
    traversal_recur(n->left);
    printf("%d ", n->key);
    traversal_recur(n->right);
}