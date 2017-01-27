#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <stdbool.h>

typedef int ValType;

typedef struct hashNode{
    int Key;
    ValType Val;
    struct hashNode *next;
} HashNode;

typedef struct{
    int Size;
    HashNode **Storage;
} HashMap;

/// \brief Linear probe hash map implement

#define PROBE_NEXT(X) \
( ((X)+1) % hashMap->Size )

/// create a pointer to HashMap structure including
/// the size of hash table, an array of HashNode which
/// contains the key and value.
HashMap *createHashMap(const int size);

void destroyHashMap(HashMap * hashMap);

/// Create a hash node and insert it into hash table.
/// Return true when successful to insert.
bool insertHashNode(HashMap *hashMap, int key, ValType val);

/// Search a specified key in hash table.
/// Return the value corresponding to it or NULL if the key is
/// not found.
ValType *getHashElement(const HashMap *hashMap, int key);


/// \brief The hash map with zigzag method implementation

/// Create a pointer to HashMap structure including
/// the size of hash table, an array of HashNode pointer
/// which point to a link list of HashNodes share the same
/// index of hash table.
HashMap *hash_create(const int size);

void hash_destroy(HashMap * hashMap);

/// Create a hash node and insert it into hash table.
/// Return true when successful to insert.
bool hash_insert(HashMap *hashMap, int key, ValType val);

/// Search a specified key in hash table.
/// Return the value corresponding to it or NULL if the key is
/// not found.
ValType *hash_get(const HashMap *hashMap, int key);

#endif // HASH_H_INCLUDED
