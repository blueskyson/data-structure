# Binary Search Tree

## Usage

```
$ g++ demo.cpp -o demo
$ ./demo
There are 6 nodes.
Print in order: 5 10 13 15 20 25
Is '20' in BST? 1

remove 20 from BST.
Now, there are 5 nodes.
Print in order: 5 10 15 13 25
Is '20' in BST? 0
```

## Implementation of Insertion

Allocate a new node storing the key to be inserten

```
The following is the BST:

               10
               /\
              /  \
             5   20
                 /\
                /  \
               15  25

Suppose we want to insert key '13', the BST will become:

               10
               /\
              /  \
             5   20
                 /\
                /  \
               15  25
              /
             /
            13          
```

## Implementation of Deletion

```
The following is the BST:

               10
               /\
              /  \
             5   20
                 /\
                /  \
               15  25
               /\    \
              /  \    \
            13   16   30
                      /\
                     ... 
```

### Case 1:

delete node with nither leftchild nor rightchild, e.g. `5` has no branch. The BST becomes:

```
               10
                \
                 \
                 20
                 /\
                /  \
               15  25
               /\    \
              /  \    \
            13   16   30
                      /\
                     ... 
```

### Case 2:

delete node with only one child branch, e.g. `25` only has right branch `30`. The BST becomes:

```
               10
               /\
              /  \
             5   20
                 /\
                /  \
               15  30
               /\   /\
              /  \   ... 
            13   16   
```

## Case 3:

delete node with 2 child branches, e.g. `20` has 15 as left child and `30` as right child. The BST becomes:

```
               10
               /\
              /  \
             5   13
                 /\
                /  \
               15  25
                \    \
                 \    \
                 16   30
                      /\
                     ... 
```