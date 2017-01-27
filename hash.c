/// \brief Linear probe hash map implementation
#include "hash.h"
#include <stdlib.h>

/// create a pointer to HashMap structure including
/// the size of hash table, an array of HashNode which
/// contains the key and value.
HashMap *createHashMap(const int size)
{
    if(size < 2)
        return NULL;

    HashMap *hashTable = (HashMap *)malloc(sizeof(HashMap));
    hashTable->Size = size;
    hashTable->Storage = calloc(hashTable->Size, sizeof(HashNode*));

    return hashTable;
}

void destroyHashMap(HashMap * hashMap)
{
    for(int i = 0; i < hashMap->Size; i++)
        if(hashMap->Storage[i])
            free(hashMap->Storage[i]);

    free(hashMap->Storage);
    free(hashMap);
}

/// Create a hash node and insert it into hash table.
/// Return true when successful to insert.
bool insertHashNode(HashMap *hashMap, int key, ValType val)
{
    int idx = abs(key) % hashMap->Size;

    while(NULL != hashMap->Storage[idx])
        idx = PROBE_NEXT(idx);

    HashNode *Node = (HashNode *)malloc(sizeof(HashNode));
    Node->Key = key;
    Node->Val = val;
    hashMap->Storage[idx] = Node;

    return true;
}

/// Search a specified key in hash table.
/// Return the value corresponding to it or NULL if the key is
/// not found.
ValType *getHashElement(const HashMap *hashMap, int key)
{
    //Project search key to index of hash table
    int index = abs(key) % hashMap->Size;

    HashNode *node;
    while(NULL != (node = hashMap->Storage[index])){
        if(node->Key == key)
            return &node->Val;
        else
            index = PROBE_NEXT(index);
    }

    //No matched key in hash table
    return NULL;
}

/// \brief The hash map with zigzag method implementation

/// Create a pointer to HashMap structure including
/// the size of hash table, an array of HashNode pointer
/// which point to a link list of HashNodes share the same
/// index of hash table.
HashMap *hash_create(const int size)
{
    if(size < 2)
        return NULL;

    HashMap *hashTable = (HashMap *)malloc(sizeof(HashMap));
    hashTable->Size = size;
    hashTable->Storage = calloc(hashTable->Size, sizeof(HashNode*));

    return hashTable;
}

void hash_destroy(HashMap * hashMap)
{
    HashNode *Node, *nextNode;
    for(int i = 0; i < hashMap->Size; i++){
        if((Node = hashMap->Storage[i]))
            //Free all nodes in this link list
            do{
                nextNode = Node->next;
                free(Node);
                Node = nextNode;
            } while(Node);
    }

    free(hashMap->Storage);
    free(hashMap);
}

/// Create a hash node and insert it into hash table.
/// Return true when successful to insert.
bool hash_insert(HashMap *hashMap, int key, ValType val)
{
    HashNode *insertPos;
    HashNode *Node = (HashNode *)malloc(sizeof(HashNode));
    Node->Key = key;
    Node->Val = val;
    Node->next = NULL;
    int idx = abs(key) % hashMap->Size;

    //No element node share this index
    if(NULL == hashMap->Storage[idx])
        hashMap->Storage[idx] = Node;
    else{
        insertPos = hashMap->Storage[idx];
        //Seek the last node
        while(insertPos->next)
            insertPos = insertPos->next;
        insertPos->next = Node;
    }

    return true;
}

/// Search a specified key in hash table.
/// Return the value corresponding to it or NULL if the key is
/// not found.
ValType *hash_get(const HashMap *hashMap, int key)
{
    //Project search key to index of hash table
    int index = abs(key) % hashMap->Size;

    HashNode *Node = hashMap->Storage[index];
    while(NULL != Node){
        if(Node->Key == key)
            return &Node->Val;
        else
            Node = Node->next;
    }

    //No matched key in hash table
    return NULL;
}
