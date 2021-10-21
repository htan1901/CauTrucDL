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

void addNode(Tree &tree, data_type value) {
	if(tree == NULL) {
		tree = createNode(value);
		return;
	}
	if(tree->data == value) {
		cout << "Gia tri trung lap!!!\n";
		return;
	}
	if(tree->data > value)
		addNode(tree->left, value);
	else 
		addNode(tree->right, value);
}

bool isLeaf(Tree tree) {
	return (tree->left == NULL && tree->right == NULL);
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

Node* search(Tree tree, int value) {
	if(tree == NULL)
		return NULL;
	if(tree->data == value)
		return tree;
	if(tree->data < value)
		search(tree->right, value);
	search(tree->left, value);
}

bool hasOneChild(Tree tree) {
	return (tree->left == NULL && tree->right != NULL) || (tree->left != NULL && tree->right == NULL);
}

Node* pre_successor(Tree tree) {
	Node* n = tree->right;
	while (n->left->left != NULL) 
		n = n->left;	
	return n;	
}

void deleteSubTree(Tree &subTree) {
	Node* deleteNode;
	if(isLeaf(subTree)){
		deleteNode = subTree;
		subTree = NULL;
		free(deleteNode);
		return;
	}
	if(hasOneChild(subTree)) {
		if(subTree->left != NULL) 
			subTree = subTree->left;
		else 
			subTree = subTree->right;
		return;	
	}
	Node* pre = pre_successor(subTree);
	Node* successor = pre->left;
	if(successor->right != NULL) {
		subTree->data = successor->data;
		deleteNode = successor;
		pre->left = successor->right;
		free(deleteNode);
		return;
	}
	subTree->data = successor->data;
	deleteNode = successor;
	pre->left = NULL;
	free(deleteNode);
	return;
}

void deleteNode(Tree &tree, int value) {
	if(tree == NULL)
		return;
	if(tree->data > value)
		deleteNode(tree->left, value);
	if(tree->data < value)
		deleteNode(tree->right, value);
	if(tree->data == value)
		deleteSubTree(tree);
}

void clear(Tree &tree) {
	if(tree == NULL)
		return;
	clear(tree->left);
	clear(tree->right);
	Node* delNode;
	if(isLeaf(tree)) {
		delNode = tree;
		tree = NULL;
		free(delNode);
		return;
	}
}

int main() {
	Tree tree;
	initTree(tree);
	vector<int> a = {30, 7, 5, 14, 9, 27, 15, 25, 20};
	for(int i:a) 
		addNode(tree,i);
	cout << "\nDuyet theo: LMR\n";
	LMR(tree);
	// cout << "\nDuyet theo: MLR\n";
	// MLR(tree);
	// cout << "\nDuyet theo: LRM\n";
	// LRM(tree);
	cout << "\nXoa node co gia tri 50\n";
	deleteNode(tree,50);
	cout << "Sau khi xoa:\n";
	LMR(tree);
	cout << "\nXoa toan bo cay\n";
	clear(tree);
	LMR(tree);
}	

