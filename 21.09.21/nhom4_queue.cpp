#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};

struct Queue {
	Node* head;
	Node* tail;
};

void initQueue(Queue &queue) {
	queue.head = NULL;
	queue.tail = NULL;
}

Node* CreateNode(int value){
	Node* p = new Node();
	if(p!=NULL){
		p->data = value;
		p->next = NULL;
	}
	return p;
}

bool isempty(Queue queue){
	return queue.head==NULL;
}

void push(Queue &queue, int value){
	Node* a = CreateNode(value);
	if(!isempty(queue)){
		queue.tail->next = a;
		queue.tail = a;
	}
	else
		queue.tail = queue.head = a;

}

void pop(Queue &queue, int &value){
	if(isempty(queue))
		return;
	else{
		queue.head->data = value;
		Node* i = queue.head;
		queue.head = queue.head->next;
		delete i;
	}
}

int main() {

}

