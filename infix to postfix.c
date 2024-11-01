//infix to postfix :
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100 // Maximum size for the stack

char stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to return the precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '^') {
        return 3;
    }
    return 0;
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix expression to postfix
void infixToPostfix(char *infix) {
    char postfix[MAX];
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        // If the character is an operand, add it to the output
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            push(c);
        }
        // If the character is ')', pop and output from the stack until '(' is encountered
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Pop the '('
        }
        // If an operator is encountered
        else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    // Pop all the operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
