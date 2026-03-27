#include <stdio.h>
#include <stdlib.h>

// ermmmrmrmrmrmrm

typedef struct MinStack {
    int val;
    struct MinStack *next;    
} MinStack;

MinStack* minStackCreate() {
    MinStack* newStack = (MinStack*)malloc(sizeof(MinStack));
    return newStack;
}

void minStackPush(MinStack* obj, int val) {
    if (obj == NULL) {
        // if there is no top, then make it one
        obj->val = val; 
        obj->next = NULL;
    } else {
        MinStack* newStack = minStackCreate();
        newStack->next = obj;
        obj = newStack;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->next == NULL) return;
    else {
        MinStack* current = obj;
        obj = current->next;
        free(current);
    }
}

int minStackTop(MinStack* obj) {
    if (obj == NULL) {
        printf("There is no stack!\n");
        return 0;
    } else {
        printf("The value of the top stack is: %d\n", obj->val);
        return obj->val;
    }
}

int minStackGetMin(MinStack* obj) {
    if (obj == NULL){
        printf("There is no stack!\n");
        return 0;
    } else {
        MinStack* current = obj;
        int minimumValue = current->val;

        while (current->next != NULL){
            current = current->next;
            if (minimumValue > current->val) minimumValue = current->val;
        };

        return minimumValue;
    }
}

void minStackFree(MinStack* obj) {
    if (obj->next == NULL) return;
    else {
        MinStack* current = obj;

        while (current != NULL){
            obj = current->next;
            free(current);
        }
    }
}

int main(){
    MinStack* obj = minStackCreate();
    minStackPush(obj, 10);
    
    return 0;
}