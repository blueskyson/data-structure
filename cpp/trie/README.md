# Trie

## Usage

|Method|Description|
|------|-----------|
|**trie()**| Initialize a trie object.|
|**void insert(string)**|Insert a word into trie.|
|**bool search(string)**|Search a word from trie. If target word exists then return `true`, otherwise return `false`.|
|**void remove(string)**|Remove a word from trie.|
|**void remove_start_with(string)**| Remove all words that start with the given string.|
|**vector\<string\> list_start_with(string)**|List all words that start with the given string.
|**vector\<string\> list_all()**|List all words in a trie.|
|**int max_depth()**|Find the length of the longest word.|
|**int word_number()**|Count how many words are in the trie.|


## Example

```
$ g++ example.cpp trie.cpp -o a
$ ./a
All words:
babara
banana
apt
application
apple

Max depth (the longest word length): 11
Word number: 5

Is "apple" exists? 1
Is "application" exists? 1
Is "apt" exists? 1
Is "app" exists? 0

Start with "app":
application
apple

Start with "ba":
babara
banana

Is "banana" exists? 1
Remove "banana"
Is "banana" exists? 0

Remove words starting with "app"
Is "apple" exists? 0
Is "application" exists? 0
Is "apt" exists? 1

All words:
babara
apt

Max depth (the longest word length): 6
Word number: 2
```