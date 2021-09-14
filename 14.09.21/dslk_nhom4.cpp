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

bool isEmpty(List list) {
	return list.head == NULL;
}

Node* createNode(int value) {
	Node* p = new Node;
	p->data = value;
	p->next = NULL;
	return p;
}

void insertFront(List &list, Node *node) {
	if(isEmpty(list)) {
		list.head = node;
		list.tail = node;
		return;
	}
	node->next = list.head;
	list.head = node;
	return;
}

void insertTail(List &list, Node *node) {
	if(isEmpty(list)) {
		list.head = node;
		list.tail = node;
		return;
	}
	list.tail->next = node;
	list.tail = node;
	return;
}