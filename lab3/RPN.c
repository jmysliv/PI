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
    if(s->top == 0) return 0;
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


typedef enum entry_type {number, add, subtract, multiply, divide} entry_type;

entry_type parse(char* raw) {
    if (raw[0] == '+') return add;
    if (raw[0] == '-') return subtract;
    if (raw[0] == '*') return multiply;
    if (raw[0] == '/') return divide;
    return number;
}
int convert_to_int(char* entry, int max){
    int a=0;
    for(int i=0; i<max; i++){
        if(entry[i]=='\0') return a;
        a *= 10;
        a += entry[i] - '0';
    }
    return a;
}

void do_add(stack* s) {
    int a=pop(s);
    int b=pop(s);
    a=a+b;
    push(s, a);
}

void do_subtract(stack* s) {
    int a=pop(s);
    int b=pop(s);
    a=b-a;
    push(s, a);
}

void do_multiply(stack* s) {
    int a=pop(s);
    int b=pop(s);
    a=a*b;
    push(s, a);
}

void do_divide(stack* s) {
    int a=pop(s);
    int b=pop(s);
    a=b/a;
    push(s, a);
}


int read_and_calculate(int operands_count, int max_entry_size) {
    stack* operands = new_stack(operands_count);
    char* entry = malloc((max_entry_size+1)*sizeof(char));
    int counter=0;
    while(counter < operands_count || operands->top > 1) {
        for(int i=0; i<max_entry_size; i++) entry[i] = '\0';
        scanf("%s", entry);
        if(parse(entry) == number) {
            push(operands, convert_to_int(entry, max_entry_size));
            counter++;
        }
        else if(parse(entry) ==add) do_add(operands);
        else if(parse(entry) ==subtract) do_subtract(operands);
        else if(parse(entry) ==multiply) do_multiply(operands);
        else if(parse(entry) ==divide) do_divide(operands);

    }

    int result = pop(operands);
    delete_stack(operands);
    free(entry);
    return result;
}

int main() {
    int operands_count, max_entry_size;
    scanf("%d", &operands_count);
    scanf("%d", &max_entry_size);
    printf("%d\n", read_and_calculate(operands_count, max_entry_size));
}