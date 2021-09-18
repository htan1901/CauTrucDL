#include <bits/stdc++.h>

using namespace std;

struct SinhVien {
	char MaSo[10];
	char HoTen[30];
	float DiemTB;
};
void Xuat1SinhVien(SinhVien *sv){
	printf("Ma So: %-10d Ho Ten: %-30d DiemTB: %.2f",sv->MaSo,sv->HoTen,sv->DiemTB);
}
struct Node {
	SinhVien info;
	Node* next;
};

struct List {
	Node* head;
	Node* tail;
};

void initList(List &list) {

}
Node * CreateNode(SinhVien value)
{
	Node* a=new Node();
	if(a!=NULL)
	{
		a->info = value;
		a->next = NULL;
	}
	return a;
}
void xuatList(List list) {

}

void xuatListDTB(List list) {
	Node* i =list.head;
	while (i!=NULL)
	{
		if(i->info.DiemTB > 5)
		{
			
		}
	}
	
}

Node* searchSV(List list, char* ten) {

}

void swapData(Node *a, Node *b) {

}

void sort(List &list) {

}

int main() {
	
}



