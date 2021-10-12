#include <bits/stdc++.h>

using namespace std;

typedef int data_type;

struct Node {
	data_type data;
	Node *left;
	Node *right;	
};
typedef Node* Tree;

void initTree(Tree &tree) {
	tree = NULL;
}

bool isEmpty(Tree &tree) {
	return tree == NULL;
}

Node* createNode(data_type data) {
	Node *n = new Node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void freeNode(Node* a) {
	delete(a);
}

void createTree(Tree &tree) {
	data_type value;
	cout << "Nhap gia tri can tao cho node\nNhap value < 0 de thoat: ";
	cin >> value;
	if(value < 0) 
		return;
	tree = createNode(value);
	cout << "\nNhap cay con ben trai cua " << value << ": \n";
	createTree(tree->left);
	cout << "\nNhap cay con ben phai cua " << value << ": \n";
	createTree(tree->right);
}

void search (Tree tree, data_type value, int &timthay) {
	if(tree == NULL)
		return;
	if(tree->data == value) {
		timthay = 1;
		return;
	}
	if(timthay == 1)
		return;
	search(tree->left,value, timthay);
	search(tree->right,value, timthay);	
}

void LMR(Tree tree) {
	if(tree == NULL)
		return;
	LMR(tree->left);
	cout << tree->data << " ";
	LMR(tree->right);
}

void MLR(Tree tree) {
	if(tree == NULL)
		return;
	cout << tree->data << " ";
	MLR(tree->left);
	MLR(tree->right);
}

void LRM(Tree tree) {
	if(tree == NULL)
		return;
	LRM(tree->left);
	LRM(tree->right);
	cout << tree->data << " ";
}

int chieuCao(Tree tree) {
	if(tree == NULL)
		return 0;
	return 1 + max(chieuCao(tree->left), chieuCao(tree->right));
}

int demNode(Tree tree) {
	if(tree == NULL)
		return 0;
	return 1 + demNode(tree->left) + demNode(tree->right);
}

bool isLeaf(Node* n) {
	return (n->left == NULL && n->right == NULL);
}

int demLa(Tree tree) {
	if(tree == NULL)	
		return 0;
	if(isLeaf(tree))
		return 1;
	return demLa(tree->left) + demLa(tree->right);
}

void inMenu() {
	cout << "\n-1. Thoat\n"
			 << "0. Duyet in-order\n"
			 << "1. Duyet pre-order\n"
			 << "2. Duyet post-order\n"
			 << "3. Search\n"
			 << "4. Chieu cao cua cay\n"
			 << "5. So node cua cay\n"
			 << "6. Dem node la cua cay\n";
}

int main() {
	Tree tree;
	initTree(tree);
	cout << "Tui em khong biet lam ham nhap cay co n phan tu\n";
	createTree(tree);
	int choice;
	do {
		inMenu();
		cout << "Chon chuc nang: ";
		cin >> choice;
		switch (choice) {
			case 0:
				cout << "Duyet in-order:\n";
				LMR(tree);
				break;
			case 1:
				cout << "Duyet pre-order:\n";
				MLR(tree);
				break;
			case 2:
				cout << "Duyet post-order:\n";
				LRM(tree);
				break;
			case 3: {
				data_type val;
				int timthay = 0;
				cout << "Nhap gia tri can tim kiem: ";
				cin >> val;
				search(tree,val,timthay);
				if(timthay == 1)
					cout << "Tim thay\n";
				else
					cout << "Khong tim thay\n";
				break;
			}
			case 4:
				cout << "Chieu cao cua cay: " << chieuCao(tree);
				break;
			case 5:
				cout << "So node cua cay " << demNode(tree);
				break;
			case 6:
				cout << "So node la cua cay " << demLa(tree);
				break;
			default:
				cout << "Thoat...\n";
				break;
		}
	} while (choice >= 0 && choice <= 6);
}