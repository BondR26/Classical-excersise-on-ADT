
#include "stack.h"
#include<iostream>

Stack::Stack() :letter{}, previous{ nullptr }, next{ nullptr }{}

void Stack::AddItem(Stack* stack, char s_let)
{
	stack->next = new Stack;
	stack->next->previous = stack;
	stack->next->letter = s_let;
	stack->next->next = nullptr;
}

void Stack::form_stack(char line[], Stack* stack)
{
	for (int i = 0; i < strlen(line); i++)
	{
		AddItem(stack, line[i]);
		stack = stack->next;
	}
}


Stack* Stack::show_stack_forward(Stack* stack)
{
	while (stack->next != 0)
	{
		std::cout << stack->letter;
		stack = stack->next;
	}

	return stack;
}

Stack* Stack::show_stack_backwards(Stack* stack)
{
	while (stack->previous != 0)
	{
		std::cout << stack->letter;
		stack = stack->previous;
	}
	return stack;
}

