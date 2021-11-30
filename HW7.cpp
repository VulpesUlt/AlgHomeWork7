#include<iostream>

//Task 1
class Stack
{
public:
	char data;
	Stack* head;
	Stack* prev;
	int length;

	void push(char dt)
	{
		if (length == 0)
		{
			data = dt;
			length++;
		}
		else
		{
			Stack* newStack = new Stack;
			newStack->data = dt;
			newStack->head = newStack;
			newStack->prev = head;
			newStack->length = ++length;
			head = newStack;
		}
	}

	char pop()
	{
		if (length == 0)
		{
			return '\n';
		}
		else if(length == 1)
		{
			char tmp = data;
			data = 0;
			length = 0;
			return tmp;
		}
		else
		{
			length--;
			char tmp;
			tmp = head->data;
			Stack* ptr = head;
			head = head->prev;
			delete ptr;
			return tmp;
		}
	}

	Stack* init()
	{
		Stack* newStack = new Stack;
		newStack->head = newStack;
		newStack->length = 0;
		newStack->prev = NULL;
		return newStack;
	}

	void print()
	{
		if (length == 0)
			printf("Stack is empty");
		else
		{
			Stack* curr = head;
			do
			{
				printf(" %c", curr->data);
				curr = curr->prev;
			} while (curr->prev != NULL);
			printf(" %c", curr->data);
			printf("\n\n");
		}
	}

	Stack* copy()
	{
		Stack* copy = NULL;
		copy = copy->init();
		if (length == 0)
			return copy;
		else
		{
			Stack* curr = head;
			char* buf = new char[length];
			
			int idx = 0;
			do
			{
				buf[idx++] = curr->data;
				curr = curr->prev;
			} while (curr->prev != NULL);
			buf[idx] = curr->data;
			
			for (int i = length - 1; i > -1; i--)
				copy->push(buf[i]);
			
			delete[] buf;
			return copy;
		}
	}

	bool sorted()
	{
		bool sorted = true;

		Stack* curr = head;
		char* buf = new char[length];

		int idx = 0;
		do
		{
			buf[idx++] = curr->data;
			curr = curr->prev;
		} while (curr->prev != NULL);
		buf[idx] = curr->data;

		for (int i = length - 2; i > -1; i--)
			if (buf[i] > buf[i + 1])
			{
				delete[] buf;
				return false;
			}
		delete[] buf;
		return true;
	}
};

// Task 2


int main()
{
	//Task 1
	Stack* open = NULL; 
	open = open->init();

	printf("Enter your expression: ");
	char curr = 'a';
	bool correct = true;
	while (true)
	{
		scanf_s("%c", &curr);
		if (curr == '\n')
		{
			if (open->pop() != '1')
				correct = false;
			break;
		}
		else if (curr == '(' || curr == '[' || curr == '{')
			open->push(curr);
		else if (curr == ')' || curr == ']' || curr == '}')
		{
			char last = open->pop();
			if (last == '\n')
				correct = false;
			if (last == '(' && curr != ')')
				correct = false;
			else if (last == '[' && curr != ']')
				correct = false;
			else if (last == '{' && curr != '}')
				correct = false;
			
		}
	}

	if (correct)
		printf("Expression is correct\n");
	else
		printf("Expression isn't correct\n");

	//Task 2
	Stack* origin = NULL;
	origin = origin->init();

	printf("Enter your word: ");
	while (true)
	{
		scanf_s("%c", &curr);
		if (curr == '\n')
			break;
		origin->push(curr);
	}
	origin->print();
	
	
	Stack* copy = NULL;
	copy = origin->copy();
	
	copy->print();

	//Task 3

	Stack* alphabet = NULL;
	alphabet = alphabet->init();

	curr = 'a';
	for (int i = 0; i < 15; i++)
		alphabet->push(curr++);
	
	if (alphabet->sorted())
		printf("TRUE\n");
	else
		printf("FALSE\n");

	alphabet = alphabet->init();
	
	for (int i = 14; i > -1; i--)
		alphabet->push(curr--);

	if (alphabet->sorted())
		printf("TRUE\n");
	else
		printf("FALSE\n");

	return 0;
}