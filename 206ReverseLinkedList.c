#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNewNode(int data){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode*));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}

// add a node from the end
struct ListNode* appendNode(struct ListNode* head, int data ){
    struct ListNode* newNode = createNewNode(data);

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

void printList(struct ListNode* head){
    struct ListNode* current = head;
    while (current != NULL){
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    
    // with a bit of help tho nice problem imo
    while (curr != NULL) {
        next = curr->next;    
        curr->next = prev;    
        prev = curr;          
        curr = next;          
    }
    
    return prev; 
}

int main(){
    struct ListNode* head = NULL;
    head = appendNode(head, 10);
    head = appendNode(head, 20);
    head = appendNode(head, 30);
    head = appendNode(head, 40);
    head = appendNode(head, 50);
    head = reverseList(head);
    printList(head);

    return 0;
}