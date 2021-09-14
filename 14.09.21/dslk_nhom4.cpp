#include <bits/stdc++.h>

struct Node {
	int data;
	Node *next;
};

struct List {
	Node *head;
	Node *tail;
};

void initList(List *list) {
	list->head = NULL;
	list->tail = NULL;
}

Node* createNode(int value) {
	Node* p = new Node;
	p->data = value;
	p->next = NULL;
	return p;
}