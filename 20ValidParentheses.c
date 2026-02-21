#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// FINISHED!
// 123ms runtime and 8.6mb lol

// lets make a stack
typedef struct Node{
    char value;
    struct Node* next;
} Node;

Node* createNewNode(char data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
};

Node* appendNewNode(Node* head, char data){
    Node* newNode = createNewNode(data);
    
    if (head == NULL) return newNode;
    Node* current = head;
    while (current->next != NULL) current = current->next;

    current->next = newNode;
    return head;
};

Node* deleteTail(Node* head){
    if (head == NULL) return NULL;
    if (head->next == NULL){
        return NULL;
    }
    
    Node* current = head;
    while (current->next->next != NULL) current = current->next;
    
    free(current->next);
    current->next = NULL;
    
    return head;
}

Node* checkTail(Node* head, char data){
    Node* current = head;
    while (current->next != NULL) current = current->next;

    if (current->value == '(' && data == ')'){
        head = deleteTail(head);
    } else if (current->value == '{' && data == '}'){
        head = deleteTail(head);
    } else if (current->value == '[' && data == ']'){
        head = deleteTail(head);
    } else {
        head->value = 'f';
    };

    return head;
}

void printNodes(Node* head){
    if (head == NULL) return;

    Node* current = head;
    while (current != NULL){
        printf("%c ", current->value);
        current = current->next;
    };
    printf("\n");
    return;
}

bool isValid(char* s){
    int lengthOfString = strlen(s);
    Node* head = NULL;

    for (int i = 0; i < lengthOfString; i++){
        if (i == 0){
            if ((s[i] == '(' || s[i] == '{' || s[i] == '[')){
                head = appendNewNode(head, s[i]);
            } else {
                return false;
            }
        } else if (s[i] == '(' || s[i] == '{' || s[i] == '['){ 
            // if the next ones are open brackets, then append
            head = appendNewNode(head, s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
            // check if the tail is the same
            head = checkTail(head, s[i]);
            if (head != NULL && head->value == 'f') return false;
        };
        
        printNodes(head);
    };

    if (head != NULL) return false;
    return true;
};

int main(){
    char string[10001];
    scanf("%s", string); getchar();

    bool result = isValid(string);
    printf(result ? "true\n" : "false\n");
}