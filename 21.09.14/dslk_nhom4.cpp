/*
*
*	@author: Nhom 4
*
*/
#include <bits/stdc++.h>

using namespace std;
struct Node {
	int data;
	Node *next;
};

struct List {
	Node *head;
	Node *tail;
};

void initList(List &list) {
	list.head = NULL;
	list.tail = NULL;
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

void pushFront(List &list, Node *node) {
	if(isEmpty(list)) {
		list.head = node; 
		list.tail = node;
		return;
	}
	node->next = list.head;
	list.head = node;
	return;
}

void pushBack(List &list, Node *node) {
	if(isEmpty(list)) {
		list.tail = node;
		return;
	}
	list.tail->next = node;
	list.tail = node;
	return;
}

void traverse(List list) {
	Node *node = list.head;
	while(node != NULL) {
		cout << node->data << ((node->next == NULL)? "" : " -> ");
		node = node->next;
	}
	cout << "\n";
}

void deleteFront(List &list) {
	Node *temp = list.head; 
	list.head = list.head->next; 
	free(temp); 
}

void deleteBack(List &list) {
	Node *pre = list.head; // gán cho pre bằng head để lặp
	while(pre->next != list.tail) // lặp tới phần tử áp cuối
		pre = pre->next;
	pre->next = list.tail->next; // cho pre trỏ tới NULL
	delete(list.tail); // xóa tail
	list.tail = pre; // cập nhật lại tail
	return;
}

void deleteNode(List &list, int value) {
	Node *node = list.head; // khởi tạo biến node để duyệt tới trước phần tử cần xóa
	while(node->next != NULL && node->next->data != value) 
		node = node->next;
	if(node != NULL) { // nếu node khác NULL thì xóa node
		Node *delNode = node->next;
		node->next = node->next->next;
		free(delNode);
	}
}

void insertNode(List &list, int newValue, int value) {
	Node *node = list.head;
	while(node != NULL && node->data != value) 
		node = node->next;
	if(node != NULL) {
		Node *newNode = createNode(newValue);
		newNode->next = node->next;
		node->next = newNode;
	}
}

void swapData(Node *first, Node *second) {
	Node *temp = new Node;
	temp->data = first->data;
	first->data = second->data;
	second->data = temp->data;
	free(temp);
}

void sort(List &list) {
	for(Node *i = list.head; i != NULL; i = i->next)
		for(Node *j = i->next; j != NULL; j = j->next)
			if(i->data > j->data)
				swapData(i,j);
}

void selectionSort(List &list) {
	Node *min;
	for(Node *i = list.head; i != NULL; i = i->next) {
		min = i;
		for(Node *j = i->next; j != NULL; j = j->next) {
			if(j->data < min->data)
				min = j;
		}
		if(i != min)
			swapData(i,min);
	}
}

Node* searchNode(List list, int value) {
	Node* node = list.head;
	while(node != NULL) {
		if(node->data == value)
			return node;
		node = node->next;
	}
	return NULL;
}

void xuatChucNang() {
	cout << "Chon chuc nang: \n"
			 << "1. Them 1 node vao danh sach\n"
			 << "2. Xuat danh sach\n"
			 << "3. Xoa cuoi danh sach \n"
			 << "4. Xoa 1 node sau 1 node co data bang value \n"
			 << "5. Them 1 node sau 1 node co data bang value \n"
			 << "6. Sap xep lai danh sach \n"
			 << "7. Tim value \n"
			 << "0. Thoat\n"
			 << "Chon: ";
}

void baitap1() {
	List list;
	initList(list);
	int n;
	int num;
	int value;
	while (n != 0) {
		do {
			xuatChucNang();
			cin >> n;
			if(n<0 || n>7)
				cout << "Nhap sai!!\n";
		} while (n<0 || n>7);

		switch (n) {
			case 1: 	
				cout << "\nNhap so can them: ";
				cin >> num;
				pushBack(list,createNode(num));
				break;
			case 2:
				traverse(list);
				break;
			case 3:
				deleteFront(list);
				cout << "\nDanh sach sau khi xoa: \n";
				traverse(list);
				break;
			case 4:
				cout << "\nNhap so can xoa: ";
				cin >> value;
				deleteNode(list,value);
				cout << "\nDanh sach sau khi xoa: \n";
				traverse(list);
				break;
			case 5:
				cout << "\nNhap value: ";
				cin >> num;
				cout << "\nNhap new value: "; 
				cin >> value; //new value
				insertNode(list,value,num);
				cout << "\nDanh sach sau khi them: \n";
				traverse(list);
				break;
			case 6:
				cout << "\nDanh sach sau khi sap xep: \n";
				selectionSort(list);
				traverse(list);
				break;
			case 7:
				cout << "Nhap value can tim: ";
				cin >> value;
				cout << (searchNode(list,value) == NULL? "Khong tim thay\n": "Tim thay\n");
				break;
		}
	}
}

int main() {
	baitap1();
}