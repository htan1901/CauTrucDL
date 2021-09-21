#include <bits/stdc++.h>

using namespace std;

struct Node {
	int info;
	Node* next;
};
typedef Node* Stack;

Node* createNode(int value) {
	Node* p = new Node;
	p->info = value;
	p->next = NULL;
	return p;
}

bool isEmpty(Stack stack) {
	return stack == NULL;
}

void initStack(Stack &stack){
	stack = NULL;
}

void push(Stack &stack, int x) {
	Node *a = createNode(x);
	if(isEmpty(stack)) {
		stack = a;
		return;
	}
	a->next = stack;
	stack = a;
	return;
}

void pop(Stack &stack) {
	if(isEmpty(stack))
		return;
	Node* a = stack;
	stack = stack->next;
	free(a);
}

int main() {

}