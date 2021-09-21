#include <bits/stdc++.h>

using namespace std;

struct Node {
	int info;
	Node* next;
};
typedef Node* Stack;

void initStack(Stack &stack){
	stack = NULL;
}
Stack CreateNode(int value){
	Stack stack = new Node();
	if(stack != NULL){
		stack->info = value;
		stack->next = NULL;
	}
	return stack;
}
void push(Stack &stack , Stack x){
	if(stack == NULL){
		stack = x;
		return;
	}
	x->next = stack;
	stack = x;
}
void pop(Stack &stack){
	if(stack->next == NULL){
		delete stack;
		stack = NULL;
		return;
	}
	Stack i = stack->next;
	delete stack;
	stack = i;
}
int main() {

}