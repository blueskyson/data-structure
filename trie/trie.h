#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

class trie {
public:
    class node {
    public:
        node();
        node(int);
        ~node();
        int depth;
        bool is_word;
        std::unordered_map<char, node*> child;
    };

    trie();
    void insert(std::string);
    bool search(std::string);
    void remove(std::string);
    void remove_start_with(std::string);
    std::vector<std::string> list_start_with(std::string);
    std::vector<std::string> list_all();
    int max_depth();
    int word_number();

private:
    void push_word_recursive(node*, std::string, std::vector<std::string>*);
    void max_depth_recursive(node*, int*);
    void word_num_recursve(node*, int*);
    node* root;
};