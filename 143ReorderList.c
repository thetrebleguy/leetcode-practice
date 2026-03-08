#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int value;
    struct ListNode *next;
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

void printList(struct ListNode* head){
    struct ListNode* current = head;
    while (current != NULL){
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
};

void reorderList(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* current1;
    struct ListNode* current2;

    int lengthOfLinkedList = 1;
    
    while (current->next != NULL){
        current = current->next;
        lengthOfLinkedList++;
    };

    // if odd, then lengthOfLinkedList / 2
    // if even, then lengthOfLinkedList / 2 - 1
    int maxIndex;
    if (lengthOfLinkedList % 2 == 0) maxIndex = lengthOfLinkedList / 2 - 1;
    else maxIndex = lengthOfLinkedList / 2;

    for (int index = 0; index < maxIndex; index++){
        current = head; // reset the position of the current
        int currentIndex = 0; // keeps track of the position of current

        while (currentIndex < lengthOfLinkedList){
            if (currentIndex == index * 2){
                current1 = current;
            } else if (currentIndex == (lengthOfLinkedList - 2)){
                current2 = current;
            };
            current = current->next;
            currentIndex++;
        };

        // after current 1 and 2 has been found, we
        // swap those
        printf("found to swap: %d %d\n", current1->value, current2->value);
        current2->next->next = current1->next;
        current1->next = current2->next;
        current2->next = NULL;
        printList(head);
    };
};

int main(){
    struct ListNode* head = NULL;
    head = appendNewNode(head, 10);
    head = appendNewNode(head, 20);
    head = appendNewNode(head, 30);
    head = appendNewNode(head, 40);
    head = appendNewNode(head, 50);
    head = appendNewNode(head, 60); 

    printList(head);

    reorderList(head);
    return 0;
}