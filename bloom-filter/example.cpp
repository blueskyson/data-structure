#include "bloom.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Construct a bloom filter with 1024 bytes (8192 bits).\n"
         << "The bloom filter has 2 hash funtions: djb2, jenkins.\n"
         << endl;
    BloomFilter bloom(1024);

    cout << "Test if string \"hello\" is in the bloom filter. (1 => true, 0 => false)\n";
    cout << bloom.contains((void*)"hello") << "\n"
         << endl;

    cout << "Add string \"hello\" to the bloom filter\n" << endl;
    bloom.add((void*)"hello");

    cout << "Test if string \"hello\" is in the bloom filter again.\n";
    cout << bloom.contains((void*)"hello") << "\n" << endl;

    cout << "Add other 9 strings: a, b, c, d, aa, aaa, bbb, cc, ddd\n"
         << endl;
    bloom.add((void*)"a");
    bloom.add((void*)"b");
    bloom.add((void*)"c");
    bloom.add((void*)"d");
    bloom.add((void*)"aa");
    bloom.add((void*)"aaa");
    bloom.add((void*)"bbb");
    bloom.add((void*)"cc");
    bloom.add((void*)"ddd");

    cout << "Test if string \"aaa\" is in the bloom filter.\n";
    cout << bloom.contains((void*)"aaa") << "\n" << endl;  

    cout << "Test if string \"xyz\" is in the bloom filter.\n";
    cout << bloom.contains((void*)"xyz") << "\n" << endl;

    cout << "False positive rate of the bloom filter: " << bloom.FPR() << endl;
    cout << "The bloom filter contins " << bloom.item_count() << " items.\n";
    return 0;
}