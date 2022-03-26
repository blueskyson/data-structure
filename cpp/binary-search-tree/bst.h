class BST {
public:
    struct node {
        int key;
        node *left, *right;
    };
    BST();
    ~BST();
    unsigned int size();
    bool find(int);
    void insert(int);
    void remove(int);
    void traversal();

private:
    node* new_node(int);
    node* recursive_insert(node*, int);
    node* recursive_remove(node*, int);
    void recursive_traverse(node*);
    void recursive_destruct(node*);
    node* root;
    unsigned int _size;
};