#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct Stack
{
	int data[STACK_SIZE];
	int top;
} Stack;

void push(Stack *stack, int value)
{
	if (stack->top == STACK_SIZE - 1)
{
	printf("Error: Stack Overflow\n");
	exit(EXIT_FAILURE);
    }

	stack->top++;
	stack->data[stack->top] = value;
}

void pall(Stack *stack)
{
	if (stack->top == -1)
{
	return;
/* Stack is empty, nothing to print */
    }

	int i;
	for (i = stack->top; i >= 0; i--)
{
	printf("%d\n", stack->data[i]);
	}
}

int main(void)
{
	Stack stack;
	stack.top = -1;

/* Example usage */
	push(&stack, 5);
	push(&stack, 10);
	push(&stack, 15);
	pall(&stack);

	return (0);
}
