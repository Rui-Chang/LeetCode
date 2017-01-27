/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "hash.h"
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    HashMap *HashTable = createHashMap(2 * numsSize);
    int Rest;
    int *RestIndex;
    int *RetPair = (int *)calloc(2, sizeof(int));

    for(int i = 0; i < numsSize; i++){
        Rest = target - nums[i];
        //The rest number found in hash table
        if((RestIndex = getHashElement(HashTable, Rest))){
            RetPair[0] = *RestIndex;
            RetPair[1] = i;
            destroyHashMap(HashTable);
            return RetPair;
        }
        else{
            //If a pair [i, j]satisfying target = nums[i]+nums[j]
            //exist, when testing j, i must be found in hash table.
            //Moreover, if insert all element to hash table firstly,
            //then search the rest number. If we meet the case
            //that nums[i] == nums[j], when we search the rest of
            //nums[i] in hash table, it will return index i because
            //i inserted to hash table before j. (The key is not unique)
            insertHashNode(HashTable, nums[i], i);
        }
    }

    return RetPair;
}
