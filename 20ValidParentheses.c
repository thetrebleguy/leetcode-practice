#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// UNFINISHED !

// lets make a stack
typedef struct Node{
    char value;
    struct Node* next;
} Node;

Node* createNewNode(char data){
    Node* newNode = (Node*)malloc(sizeof(Node*));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
};

Node* appendNewNode(Node* head, Node* tail, char data){
    Node* newNode = createNewNode(data);
    if (head == NULL) return newNode;

    tail->next = newNode;
    tail = tail->next;
    free(newNode);
    return tail;
};

Node* deleteTail(Node* head){
    if (head == NULL) return NULL;
    if (head->next == NULL){
        free(head);
        return NULL;
    }
    
    Node* current = head;
    while (current->next->next != NULL) current = current->next;
    
    free(current->next);
    current->next = NULL;
    
    return head;
}

void printNodes(Node* head){
    Node* current = head;
    while (current != NULL){
        printf("%c ", current->value);
        current = current->next;
    };
    printf("\n");
}

bool isValid(char* s){
    int lengthOfString = strlen(s);
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < lengthOfString; i++){
        if (i == 0){
            if ((s[i] == '(' || s[i] == '{' || s[i] == '[')){
                head = appendNewNode(head, tail, s[i]);
                tail = head;
            }
        } else if (s[i] == '(' || s[i] == '{' || s[i] == '['){ 
            // if the next ones are open brackets, then append
            tail = appendNewNode(head, tail, s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
            // check if the tail is the same
            if (tail->value == '(' && s[i] == ')'){
                printf("test\n");
                head = deleteTail(head);
            } else if (tail->value == '{' && s[i] == '}'){
                head = deleteTail(head);
            } else if (tail->value == '[' && s[i] == ']'){
                head = deleteTail(head);
            } else {
                return false;
            };
        };

        printNodes(head);
    };
};

int main(){
    char string[10001];
    scanf("%s", string); getchar();

    bool result = isValid(string);
    printf(result ? "true\n" : "false\n");
}