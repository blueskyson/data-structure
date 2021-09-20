#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(25);
    bst.insert(15);
    bst.insert(13);

    cout << "There are " << bst.size() << " nodes." << endl;
    cout << "Print in order: ";
    bst.traversal();
    cout << "Is \'20\' in BST? " << bst.find(20) << endl;
    cout << endl;

    cout << "remove 20 from BST." << endl; 
    bst.remove(20);
    cout << "Now, there are " << bst.size() << " nodes." << endl;
    cout << "Print in order: ";    
    bst.traversal();
    cout << "Is \'20\' in BST? " << bst.find(20) << endl;
    return 0;
}