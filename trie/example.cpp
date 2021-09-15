#include <iostream>
#include "trie.h"
#include <string>
#include <vector>

using namespace std;

void test_search(trie t, string s) {
    cout << "Is \"" + s + "\" exists? "
        << t.search(s) << endl;
}

int main() {
    trie t;

    /* test insert and list_all */
    t.insert("apple");
    t.insert("application");
    t.insert("apt");
    t.insert("banana");
    t.insert("babara");
    cout << "All words:" << endl;
    for (string s : t.list_all()) {
        cout << s << endl;
    }
    cout << endl;

    /* test max_depth and word_number */
    cout << "Max depth (the longest word length): "
         << t.max_depth() << endl;
    cout << "Word number: "
         << t.word_number() << endl << endl;

    /* test search */
    test_search(t, "apple");
    test_search(t, "application");
    test_search(t, "apt");
    test_search(t, "app");
    cout << endl;

    /*test list_start_with */
    cout << "Start with \"app\":" << endl;
    for (string s : t.list_start_with("app")) {
        cout << s << endl;
    }
    cout << endl;
    cout << "Start with \"ba\":" << endl;
    for (string s : t.list_start_with("ba")) {
        cout << s << endl;
    }
    cout << endl;   

    /* test remove */
    test_search(t, "banana");
    cout << "Remove \"banana\"" << endl;
    t.remove("banana");
    test_search(t, "banana");
    cout << endl;

    /* test remove_start_with */
    cout << "Remove words starting with \"app\"" << endl;
    t.remove_start_with("app");
    test_search(t, "apple");
    test_search(t, "application");
    test_search(t, "apt");
    cout << endl;

    /* test max_depth and word_number again */
    cout << "All words:" << endl;
    for (string s : t.list_all()) {
        cout << s << endl;
    }
    cout << endl;
    cout << "Max depth (the longest word length): "
         << t.max_depth() << endl;
    cout << "Word number: "
         << t.word_number() << endl << endl;

    return 0;
}