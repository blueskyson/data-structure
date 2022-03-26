typedef unsigned int (*hash_function)(const void *data);
struct hash_node {
    hash_function func;
    hash_node* next;
};

class BloomFilter {
public:
    BloomFilter(unsigned size);
    void add(void *data);
    bool contains(void *data);
    unsigned item_count();
    unsigned hash_count();
    double FPR();
    ~BloomFilter();
private:
    unsigned char *table;
    unsigned _size, _hash_count, _item_count;
    hash_node *head;
    void add_hash(hash_function f);
};