#pragma once
class Stack
{
private:
	char letter;
	Stack* previous;
	Stack* next;
public:

	Stack();

	void AddItem(Stack* stack, char s_let);

	void form_stack(char line[], Stack* stack);

	Stack* show_stack_forward(Stack* stack);

	Stack* show_stack_backwards(Stack* stack);


};