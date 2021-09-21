#include <bits/stdc++.h>

using namespace std;

//hello from nhom 4

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

void pop(Stack &stack, int &x) {
	if(isEmpty(stack))
		return;
	Node* a = stack;
	x = a->info;
	stack = stack->next;
	free(a);
}

void DecToBin() {
	Stack stack;
	int x;
	initStack(stack);
	int n;
	cout << "Nhap so can chuyen: ";
	cin >> n;
	int soDu;
	while(n != 0) {
		soDu = n%2;
		n /= 2;
		push(stack,soDu);
	}
	while(isEmpty(stack) == 0) {
		int x;
		pop(stack,x);
		cout << x;
	}
}

int main() {
	DecToBin();
}