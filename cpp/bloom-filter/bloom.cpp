#include "bloom.h"
#include <cstring>
#include <cmath>

static unsigned int djb2(const void *_str)
{
    const char *str = (const char *)_str;
    unsigned int hash = 5381;
    char c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

static unsigned int jenkins(const void *_str)
{
    const char *key = (const char *)_str;
    unsigned int hash = 0;
    while (*key) {
        hash += *key;
        hash += (hash << 10);
        hash ^= (hash >> 6);
        key++;
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

BloomFilter::BloomFilter(unsigned size) {
    _size = size;
    table = new unsigned char[size];
    memset(table, 0, size);
    _item_count = 0;
    _hash_count = 0;
    head = NULL;

    add_hash(djb2);
    add_hash(jenkins);

}

void BloomFilter::add_hash(hash_function f) {
    hash_node *h = new hash_node;
    h->func = f;
    h->next = NULL;
    _hash_count++;
    if (head == NULL) {
        head = h;
        return;
    }

    hash_node *last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = h;
}

void BloomFilter::add(void *data) {
    hash_node *h = head;
    _item_count++;
    while (h) {
        unsigned hash = h->func(data);
        hash %= _size;
        table[hash >> 3] |= 0x80 >> (hash & 7);
        h = h->next;
    }
}

bool BloomFilter::contains(void *data) {
    hash_node *h = head;
    while (h) {
        unsigned hash = h->func(data);
        hash %= _size;
        if (!(table[hash >> 3] & (0x80 >> (hash & 7)))) {
            return false;
        }
        h = h->next;
    }
    return true;
}

double BloomFilter::FPR() {
    double p = (-1.0 * _hash_count * _item_count) / _size;
    return pow(1 - exp(p), (double)_hash_count);
}

unsigned BloomFilter::item_count() {
    return _item_count;
}

unsigned BloomFilter::hash_count() {
    return _hash_count;
}

BloomFilter::~BloomFilter() {
    delete[] table;
}