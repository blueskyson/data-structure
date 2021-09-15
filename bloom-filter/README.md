# Bloom Filter

## Usage

- **Bloomfilter(int k):** Construct a bloom filter with `k`-byte table.
- **void add(void\* item):** insert an item into the bloom filter.
- **bool contains(void\* item):** check if the item is in the bloom filter.
- **unsigned item_count():** return the amount of item the bloom filter contains.
- **unsigned hash_count():** return hash function amount. There are `djb2` and `jekins` in source code.
- **double FPR():** return false postive rate of current bloom filter. 

## Example

```
$ g++ example.cpp bloom.cpp -o a
$ ./example
Construct a bloom filter with 1024 bytes (8192 bits).
The bloom filter has 2 hash funtions: djb2, jenkins.

Test if string "hello" is in the bloom filter. (1 => true, 0 => false)
0

Add string "hello" to the bloom filter

Test if string "hello" is in the bloom filter again.
1

Add other 9 strings: a, b, c, d, aa, aaa, bbb, cc, ddd

Test if string "aaa" is in the bloom filter.
1

Test if string "xyz" is in the bloom filter.
0

False positive rate of the bloom filter: 0.000374103
```