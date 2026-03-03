#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 10000
// TIME LIMIT

struct ListNode{
    int value;
    struct ListNode* next;
};

struct addressCount{
    struct ListNode* current;
};

struct ListNode* createNewNode(int val){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode*));
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* appendNewNode(struct ListNode* head, int val){
    struct ListNode* newNode = createNewNode(val);

    if (head == NULL){
        return newNode;
    };

    struct ListNode* current = head;
    while (current->next != NULL){
        current = current->next;
    };

    current->next = newNode;
    return head;
};

struct ListNode* addCycle(struct ListNode* head, int pos){
    if (head == NULL) return NULL;
    if (pos == -1) return head;

    int currentPosition = 0;
    struct ListNode* link = head;
    struct ListNode* current = head;
    while (current->next != NULL){
        if (pos == currentPosition) link = current;
        currentPosition++;
        current = current->next;
    };

    current->next = link; // link the tail with the link node
    return head;
};

bool hasCycle(struct ListNode *head) {
    // make a hash table
    struct addressCount* hashArray[HASH_SIZE] = {NULL};

    struct ListNode *current = head;

    while (current != NULL){
        int index = ((unsigned long)current) % 10000; // assigning index with division

        if (hashArray[index] != NULL && hashArray[index]->current == current){
            return true; // basically found the cycle
        }

        // if it is empty then you can assign it there
        if (hashArray[index] == NULL) {
            hashArray[index] = malloc(sizeof(struct addressCount));
        }
        hashArray[index]->current = current;  
        current = current->next;
    };

    // for the cleanup
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hashArray[i] != NULL) {
            free(hashArray[i]);
        }
    }
    
    return false;
}

int main(){
    struct ListNode* head = NULL;
    head = appendNewNode(head, 3);
    head = appendNewNode(head, 2);
    head = appendNewNode(head, 0);
    head = appendNewNode(head, -4);
    head = addCycle(head, -1);

    printf(hasCycle(head) ? "true\n" : "false\n");

    return 0;
}