/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    int carry = 0;
    struct ListNode *outlist = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *rear = outlist;
    struct ListNode *alloc;

    // When there are two operands to add
    while(p1 && p2){
        //Compute sum and carry bit
        alloc = (struct ListNode *)malloc(sizeof(struct ListNode));
        alloc->val = (p1->val + p2->val + carry) % 10;
        carry = (p1->val + p2->val + carry) / 10;

        //Insert at the rear
        rear->next = alloc;
        rear = alloc;
        p1 = p1->next;
        p2 = p2->next;
    }

    // Sum the remaining higher digits and carry
    if(p2)
        p1 = p2;
    while(p1){
        alloc = (struct ListNode *)malloc(sizeof(struct ListNode));
        alloc->val = (p1->val + carry) % 10;
        carry = (p1->val + carry) / 10;

        //Insert at the rear
        rear->next = alloc;
        rear = alloc;
        p1 = p1->next;
    }

    //One more node to hold the most significant carry
    if(carry){
        alloc = (struct ListNode *)malloc(sizeof(struct ListNode));
        alloc->val = carry;

        //Insert at the rear
        rear->next = alloc;
        rear = alloc;
    }

    rear->next = NULL;
    alloc = outlist;
    outlist = outlist->next;
    free(alloc);

    return outlist;
}
