#include <bits/stdc++.h>

using namespace std;

struct SinhVien {
	char MaSo[10];
	char HoTen[30];
	float DiemTB;
};

void nhapSV(SinhVien &sv) {
	printf("Nhap ma so");
	fflush(stdin);
	gets(sv.MaSo);
	printf("Nhap ten: ");
	fflush(stdin);
	gets(sv.HoTen);
	printf("Nhap DTB");
	scanf("%f", &sv.DiemTB);
}

void XuatSV(SinhVien sv){
	printf("Ma So: %-10d Ho Ten: %-30d DiemTB: %.2f",sv.MaSo,sv.HoTen,sv.DiemTB);
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
	list.head = NULL;
	list.tail = NULL;
}

Node * CreateNode(SinhVien value) {
	Node* a=new Node();
	if(a!=NULL)
	{
		a->info = value;
		a->next = NULL;
	}
	return a;
}

void xuatList(List list) {
	Node *i = list.head;
	while(i != NULL) {
		XuatSV(i->info);
	}
}

void xuatListDTB(List list) {
	Node* i =list.head;
	while (i!=NULL)
		if(i->info.DiemTB > 5.0)	
			XuatSV(i->info);
}

Node* searchSV(List list, char* ten) {
	Node*i =list.head;
    while (i!=NULL)
    {
      if(i->info.HoTen == ten)
          return i;
      i=i->next;
    }
    return NULL;
}

void swapData(Node *a, Node *b) {
	Node *temp = new Node;
	temp->info = a->info;
	a->info = b->info;
	b->info = temp->info;
}

void sort(List &list) {
	for(Node *i = list.head; i != NULL; i = i->next)
		for (Node *j = 0; j != NULL; j=j->next) 
			if(i->info.DiemTB > j->info.DiemTB)
				swapData(i,j);
}

int main() {

}