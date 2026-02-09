// UNFINISHED
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNewNode(int data){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = NULL;
    struct ListNode* curr1 = list1;
    struct ListNode* curr2 = list2;
    int reachedEnd1 = 0, reachedEnd2 = 0;

    // check first
    if (curr1 == NULL) reachedEnd1 = 1;
    if (curr2 == NULL) reachedEnd2 = 1;

    while (reachedEnd1 == 0 || reachedEnd2 == 0){
        if (!reachedEnd1 && !reachedEnd2){
            // just check normally
            if (curr1->val <= curr2->val){
                head = appendNode(head, curr1->val);
                curr1 = curr1->next;
                if (curr1 == NULL) reachedEnd1 = 1;
            } else {
                head = appendNode(head, curr2->val);
                curr2 = curr2->next;
                if (curr2 == NULL) reachedEnd2 = 1;
            };
        } else if (reachedEnd1 && !reachedEnd2){
            while (!reachedEnd2){
                head = appendNode(head, curr2->val);
                curr2 = curr2->next;
                if (curr2 == NULL) reachedEnd2 = 1;
            }
        } else if (!reachedEnd1 && reachedEnd2){
            while (!reachedEnd1){
                head = appendNode(head, curr1->val);
                curr1 = curr1->next;
                if (curr1 == NULL) reachedEnd1 = 1;
            }
        }
    };

    struct ListNode* current = head;
    while (current != NULL){
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
    
    return head;
};

int main(){
    struct ListNode* head1 = NULL;
    struct ListNode* head2 = NULL;
    struct ListNode* head = NULL;
    head1 = appendNode(head1, 1);
    head1 = appendNode(head1, 2);
    head1 = appendNode(head1, 4);
    head2 = appendNode(head2, 1);
    head2 = appendNode(head2, 3);
    head2 = appendNode(head2, 4);
    head = mergeTwoLists(head1, head2); // merge the list here

    return 0;
};