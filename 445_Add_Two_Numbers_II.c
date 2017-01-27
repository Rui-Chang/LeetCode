
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

/// Need 2 times to traverse both nodes in two lists
/// and 2 times  to traverse the elements of sum after add.
/// TimeComplx O(max{length(l1), length(l2)})

struct ListNode {
    int val;
    struct ListNode *next;
 };

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct ListNode* addTwoNumbersII(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;

    //outlist point to the header node of output list
    struct ListNode *outlist = (struct ListNode *)malloc(sizeof(struct ListNode));
    outlist->next = NULL;
    //Point to the rear node in outlist
    struct ListNode *rear = outlist;
    //Apply space with malloc()
    struct ListNode *work;

    //Point to the longer list within the two
    struct ListNode *longerlist;
    //The number of nodes in longer list
    int len = 0;
    //The difference of length between two lists
    int dist = 0;

    //compute the length of each list
    while(p1){
        len++;
        p1 = p1->next;
    }
    while(p2){
        dist++;
        p2 = p2->next;
    }

    // Make sure the digit to be add are aligned.
    // If the length of two lists is different, skip the higher digit
    // in the longer list.
    p1 = l1;
    p2 = l2;
    if(len >= dist){
        longerlist = l1;
        dist = len - dist;
        for(int i = dist; i > 0; i--)
            p1 = p1->next;
    }
    else{
        longerlist = l2;
        swap(&len, &dist);
        dist = len - dist;
        for(int i = dist; i > 0; i--)
            p2 = p2->next;
    }

    // Temporary array to hold the sum of two list
    // convenient to fix the carry.
    int *NumArray = (int *)malloc(len * sizeof(int));
    //First initialize the higher digits in longer list
    work = longerlist;
    int i;
    for(i = 0; i < dist; i++){
        NumArray[i] = work->val;
        work = work->next;
    }
    //Add the correspondent digit in two lists.
    while(p1){
        //compute digit sum for each node
        NumArray[i++] = p1->val + p2->val;
        p1 = p1->next;
        p2 = p2->next;
    }
    //Adjust the carry bit from bottom on
    int carry = 0;
    for(i = len-1; i >= 0; i--){
        if(carry)
            ++NumArray[i];
        //Take carry bit to front digit.
        carry = 0;
        if(NumArray[i] > 9){
            carry = 1;
            NumArray[i] -= 10;
        }
    }

    // Transfer the sum to output link list.
    //Need one more node holding the excessive carry bit
    if(carry){
        work = (struct ListNode *)malloc(sizeof(struct ListNode));
        work->val = 1;
        rear->next = work;
        rear = work;
    }
    for(i = 0; i < len; i++){
        work = (struct ListNode *)malloc(sizeof(struct ListNode));
        work->val = NumArray[i];
        //insert it into the rear of output list
        rear->next = work;
        rear = work;
    }
    rear->next = NULL;

    free(NumArray);
    return outlist->next;

}
