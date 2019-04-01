#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int* elements;
    int top;
    int max_size;
} stack;



void push(stack* s, int n) {
    if(s->top==s->max_size) return;
    s->elements[s->top] = n;
    s->top++;
}

int pop(stack* s) {
    if(s->top==0) return 0;
    s->top--;
    return s->elements[s->top];
}

bool is_empty(stack* s) {
    if(s->top == 0) return true;
    else return false;
}

stack* new_stack(int size) {
    stack *s = malloc(sizeof(stack));
    s->max_size = size;
    s->elements = malloc(size* sizeof(int));
    s->top=0;
    return s;
}

void delete_stack(stack* s) {
    free(s->elements);
}

int main() {
    int size;
    scanf("%d", &size);
    stack* s = new_stack(size);
    int tmp;

    for(int i=0; i<size; i++){
        scanf("%d", &tmp);
        push(s, tmp);
    }
    for(int i=0; i<size; i++) {
        tmp = pop(s);
        printf("%d \n", tmp);
    }
    delete_stack(s);
}