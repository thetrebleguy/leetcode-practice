#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASH_SIZE 10000
// TIME LIMIT

struct ListNode{
    int value;
    struct ListNode* next;
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
    if (head == NULL) return false;
    // using the floyd's tortoise and hare
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) return true;
    };

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