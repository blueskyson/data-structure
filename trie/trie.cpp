#include "trie.h"

using std::string;
using std::unordered_map;
using std::vector;

trie::node::node() {
    depth = 0;
    is_word = false;
    child = unordered_map<char, node*>();
}

trie::node::node(int depth): depth(depth) {
    is_word = false;
    child = unordered_map<char, node*>();
}

trie::node::~node() {
    for (std::pair<char, node*> pair : child) {
        delete pair.second;
    }
}

trie::trie() {
    root = new node();
}

void trie::insert(string word) {
    node* n = root;
    for (char c : word) {
        if (n->child.find(c) == n->child.end()) {
            n->child[c] = new node(n->depth + 1);
        }
        n = n->child[c];
    }
    n->is_word = true;
}

bool trie::search(string word) {
    node* n = root;
    for (char c : word) {
        if (n->child.find(c) == n->child.end()) {
            return false;
        }
        n = n->child[c];
    }
    return n->is_word;
}

void trie::remove(string word) {
    node* n = root;
    for (char c : word) {
        if (n->child.find(c) == n->child.end()) {
            return;
        }
        n = n->child[c];
    }
    n->is_word = false;
}

void trie::remove_start_with(string word) {
    node* n = root;
    for (char c : word) {
        if (n->child.find(c) == n->child.end()) {
            return;
        }
        n = n->child[c];
    }
    for (std::pair<char, node*> pair : n->child) {
        delete pair.second;
    }
    n->child = unordered_map<char, node*>();
    n->is_word = false;
}

void trie::push_word_recursive(node* n, std::string word, std::vector<std::string>* list) {
    if (n->is_word) {
        list->push_back(word);
    }
    for (std::pair<char, node*> pair : n->child) {
        push_word_recursive(pair.second, word + pair.first, list);
    }
}

vector<string> trie::list_start_with(string word) {
    node* n = root;
    vector<string> list;
    for (char c : word) {
        if (n->child.find(c) == n->child.end()) {
            return list;
        }
        n = n->child[c];
    }

    push_word_recursive(n, word, &list);
    return list;
}

vector<string> trie::list_all() {
    vector<string> list;
    push_word_recursive(root, "", &list);
    return list;
}

void trie::max_depth_recursive(node* n, int* max) {
    if (n->is_word && n->depth > *max) {
        *max = n->depth;
    }
    for (std::pair<char, node*> pair : n->child) {
        max_depth_recursive(pair.second, max);
    } 
}

int trie::max_depth() {
    int max = 0;
    max_depth_recursive(root, &max);
    return max;
}

void trie::word_num_recursve(node* n, int* num) {
    if (n->is_word) {
        *num = *num + 1;
    }
    for (std::pair<char, node*> pair : n->child) {
        word_num_recursve(pair.second, num);
    } 
}

int trie::word_number() {
    int num = 0;
    word_num_recursve(root, &num);
    return num;
}